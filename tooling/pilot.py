#!/usr/bin/env python3
"""pilot.py - differential verifier for the decompilation pilot.

For every function registered in src/ (PCREG(addr, fn)) and described in harness/specs*.py, run
the ORIGINAL machine code of Freedom.Exe.orig and the DECOMPILED C++ (compiled for i386 by
build.sh and loaded into the same Unicorn instance at 0x31000000) on the same inputs, and compare:

  * return value (EAX, EAX:EDX, ST0 as all 80 bits, or XMM0), callee-pop (ESP after return),
  * callee-saved registers (EBX ESI EDI EBP) and the x87 stack depth,
  * every byte of the fake heap (all argument buffers and objects),
  * every byte of the exe's .data section (globals),
  * the log of calls into Python stubs (fake vtables, engine calls), in order, with arguments,
  * faults: if the original faults (e.g. NULL read), the C++ must fault on the same address.

    python3 -I harness/pilot.py                 # build + verify everything
    python3 -I harness/pilot.py 0x4de1d0 -n 2000 # one function, more cases
    python3 -I harness/pilot.py --no-build --json results/run.json
"""
import argparse
import hashlib
import json
import math
import os
import random
import struct
import subprocess
import sys
import time

HERE = os.environ.get('PILOT_SPECS') or os.path.dirname(os.path.abspath(__file__))   # spec folder (specs_*.py)
ROOT = os.path.dirname(HERE)
EXE_VERIFY = os.environ.get('PILOT_EXE_VERIFY') or os.path.dirname(os.path.abspath(__file__))  # shared-harness: trial pe_emu (fake TEB) sits next to this file
sys.path.insert(0, EXE_VERIFY)
sys.path.insert(0, HERE)
import pe_emu  # noqa: E402
from pe_emu import PEEmu, EmuStop, F, D, f32, HEAP_BASE, SCRATCH  # noqa: E402,F401
from unicorn.x86_const import (UC_X86_REG_FPCW, UC_X86_REG_FPSW, UC_X86_REG_FPTAG,  # noqa: E402
                               UC_X86_REG_MXCSR, UC_X86_REG_ESP, UC_X86_REG_EBX, UC_X86_REG_ESI,
                               UC_X86_REG_EDI, UC_X86_REG_EBP, UC_X86_REG_EDX, UC_X86_REG_XMM0,
                               UC_X86_REG_EIP)
from unicorn import UC_PROT_ALL  # noqa: E402

BLOB_BASE = 0x31000000
BUILD = os.environ.get('PILOT_BUILD') or os.path.join(ROOT, 'build')
DATA_LO, DATA_HI = 0x6e4000, 0x6e4000 + 0x13024c
# x87 control word. 0x027F is the Windows default (53-bit precision, round to nearest, all
# exceptions masked). The game's x87 code is only float returns and a few leftovers; see the
# README for the 0x007F (24-bit, Direct3D default) cross-check.
FPCW = int(os.environ.get('PILOT_FPCW', '0x27f'), 16)
MXCSR = 0x1f80
SENTINELS = {'ebx': 0x0b0b0b0b, 'esi': 0x5151515, 'edi': 0x0d0d0d0d}


# ============================================================================ emulator
class Pilot(PEEmu):
    def __init__(self, build=BUILD):
        super().__init__()
        self.reg_values = False   # set per run from the spec (reg_values=True)
        blob = open(os.path.join(build, 'pilot.bin'), 'rb').read()
        size = (len(blob) + 0x10000 + 0xfffff) & ~0xfffff
        self.mu.mem_map(BLOB_BASE, size, UC_PROT_ALL)
        self.mu.mem_write(BLOB_BASE, blob)
        self.blob = blob
        self.blob_size = size
        self.decomp = {}     # pc addr -> address of the C++ function in the blob
        self.symbols = {}
        for line in open(os.path.join(build, 'pilot.syms')):
            p = line.split()
            if len(p) == 3:
                self.symbols[p[2]] = int(p[0], 16)
                if p[2].startswith('pc_'):
                    ptr = int(p[0], 16)
                    self.decomp[int(p[2][3:], 16)] = struct.unpack_from('<I', blob, ptr - BLOB_BASE)[0]
        # trampoline: fstp tbyte [SCRATCH]; jmp RET_ADDR   (keeps all 80 bits of ST0)
        code = b'\xdb\x3d' + struct.pack('<I', SCRATCH) + b'\xe9' + b'\0' * 4
        self.RET_ST0 = self._alloc_stub_code(code)
        self.mu.mem_write(self.RET_ST0 + 7, struct.pack('<i', self.RET_ADDR - (self.RET_ST0 + 11)))
        self._stub_mark = self._stub_next
        self.calllog = []

    def reset(self):
        super().reset()
        self.mu.mem_write(BLOB_BASE, self.blob)   # the C++ may have statics
        self.calllog = []

    # a fake vtable whose slots log (slot, args) and return what `impl` says
    def logging_vtable(self, name, nslots, impl=None, argwords=None):
        """impl: {byte_off: fn(emu, args)->(eax|None, st0|None)}; argwords: {byte_off: n stack words}."""
        impl = impl or {}
        argwords = argwords or {}
        slots = {}
        for i in range(nslots):
            off = 4 * i

            def h(e, r, off=off):
                n = argwords.get(off, 0)
                args = [e.arg32(k) for k in range(n)]
                e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
                f = impl.get(off)
                eax, st0 = (f(e, args) if f else (0, None))
                e.ret(eax=eax, argbytes=4 * n, st0=st0)
            slots[off] = h
        return self.fake_vtable(name, nslots, slots)

    def run(self, addr, abi, args, ret, max_insns=2000000):
        """Call addr. abi: 'fastcall' | 'thiscall' | 'cdecl' | 'stdcall' | ('regs', [reg per arg or 's'])."""
        mu = self.mu
        regs = dict(SENTINELS)
        stack = []
        if abi == 'fastcall':
            ints = [a for a in args if not isinstance(a, (F, D))]
            # MSVC fastcall: the first two 32-bit non-float args go in ECX, EDX (in order)
            used = 0
            for a in args:
                if not isinstance(a, (F, D)) and used < 2:
                    regs[('ecx', 'edx')[used]] = int(a) & 0xffffffff
                    used += 1
                else:
                    stack.append(a)
            del ints
        elif abi == 'thiscall':
            regs['ecx'] = int(args[0]) & 0xffffffff
            stack = list(args[1:])
        elif abi in ('cdecl', 'stdcall'):
            stack = list(args)
        elif isinstance(abi, tuple) and abi[0] == 'regs':
            for a, where in zip(args, abi[1]):
                if where == 's':
                    stack.append(a)
                else:
                    regs[where] = int(a) & 0xffffffff
        else:
            raise ValueError(abi)
        esp = pe_emu.STACK_TOP - 0x200
        # Fill 64 KB below the arguments with 0xcc, so a read of an uninitialised local differs from zero (as the
        # Decompilation thread's harness does).
        mu.mem_write(esp - 0x10000, b'\xcc' * 0x10000)
        blob = b''
        for a in stack:
            if isinstance(a, D):
                blob += struct.pack('<d', a)
            elif isinstance(a, F):
                blob += struct.pack('<f', a)
            else:
                blob += struct.pack('<I', int(a) & 0xffffffff)
        esp -= len(blob)
        mu.mem_write(esp, blob)
        esp -= 4
        mu.mem_write(esp, struct.pack('<I', self.RET_ST0 if ret == 'st0' else self.RET_ADDR))
        mu.reg_write(UC_X86_REG_FPCW, FPCW)
        mu.reg_write(UC_X86_REG_MXCSR, MXCSR)
        mu.reg_write(UC_X86_REG_FPSW, 0)
        mu.reg_write(UC_X86_REG_FPTAG, 0xffff)
        mu.reg_write(UC_X86_REG_XMM0, 0)
        esp0 = esp
        r = self._run(addr, esp, regs.pop('ecx', 0), regs, None, max_insns, False)
        out = {'eax': r.eax}
        if ret == 'st0':
            out['st0'] = bytes(mu.mem_read(SCRATCH, 10)).hex()
        if ret == 'eax:edx':
            out['edx'] = mu.reg_read(UC_X86_REG_EDX)
        if ret == 'xmm0':
            out['xmm0'] = mu.reg_read(UC_X86_REG_XMM0) & 0xffffffff
        if ret == 'al':
            out['eax'] = r.eax & 0xff   # bool return: only AL is defined
        if ret in (None, 'none', 'void', 'st0', 'xmm0'):
            out.pop('eax')   # EAX is scratch for void and float returns: not part of the contract
        out['pop'] = mu.reg_read(UC_X86_REG_ESP) - esp0 - 4
        bad = [k for k, v in SENTINELS.items() if self.reg(k) != v]
        if mu.reg_read(UC_X86_REG_EBP) != pe_emu.STACK_TOP - 0x80:
            bad.append('ebp')
        out['clobbered'] = bad
        if self.reg_values:
            # Values, not only names: a callee-saved register that differs from its sentinel must also hold the
            # same value on both sides (see HOWTO, register values). Only when a spec asks, so other runs are unchanged.
            out['reg_values'] = {k: self.reg(k) for k in SENTINELS}
            out['reg_values']['ebp'] = mu.reg_read(UC_X86_REG_EBP)
        sw = mu.reg_read(UC_X86_REG_FPSW)
        out['x87_top'] = (sw >> 11) & 7
        out['mxcsr'] = mu.reg_read(UC_X86_REG_MXCSR) & ~0x3f  # control bits only (flags are sticky)
        return out


# ============================================================================ input generators
EDGE_F = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 2.0, math.nan, math.inf, -math.inf,
          1e-40, -1e-40, 1.1754944e-38, 3.4028235e38, -3.4028235e38, 1e-7, 0.999999, 1e7]


class Ctx:
    def __init__(self, emu, rng, case):
        self.emu = emu
        self.rng = rng
        self.case = case
        self.args = []
        self.vars = {}

    def fv(self, lo=-10.0, hi=10.0, edge=0.12):
        r = self.rng.random()
        if r < edge:
            return f32(self.rng.choice(EDGE_F))
        if r < edge + 0.03:
            return struct.unpack('<f', struct.pack('<I', self.rng.getrandbits(32)))[0]
        if r < edge + 0.25:
            return f32(self.rng.uniform(lo * 100, hi * 100))
        if r < edge + 0.35:
            return f32(float(self.rng.randint(-3, 3)))
        return f32(self.rng.uniform(lo, hi))

    def fbuf(self, n, gen=None, pad=8):
        """n floats (plus a few pad floats after, so overruns show up as heap differences)."""
        a = self.emu.alloc(4 * (n + pad), 4)
        for i in range(n + pad):
            self.emu.wf32(a + 4 * i, gen(self) if gen else self.fv())
        return a

    def bytes_(self, n, align=4):
        a = self.emu.alloc(n, align)
        self.emu.wbytes(a, bytes(self.rng.getrandbits(8) for _ in range(n)))
        return a


def fl(lo=-10.0, hi=10.0, edge=0.12):
    return lambda c: F(c.fv(lo, hi, edge))


def fbuf(n, gen=None):
    return lambda c: c.fbuf(n, gen)


def same(i):
    return lambda c: c.args[i]


def oneof(*gens, w=None):
    return lambda c: c.rng.choices(gens, weights=w)[0](c)


def null_or(g, p=0.2):
    return lambda c: 0 if c.rng.random() < p else g(c)


def u32(lo=0, hi=0xffffffff):
    return lambda c: c.rng.randint(lo, hi)


def const(v):
    return lambda c: v


class Spec:
    def __init__(self, addr, name, abi, args, ret=None, setup=None, n=None, note='', abi_mine=None,
                 status_override=None, tries=1, gen=None, nan_heap=False, heap_mask=None, max_insns=2000000, stack_arg_bytes=4, reg_values=False):
        self.nan_heap = nan_heap                 # True only where a heap word is a float the spec marks as such
        self.heap_mask = heap_mask               # fn(ctx) -> [(abs_addr, nbytes)]: heap words not compared (see HOWTO)
        self.addr, self.name, self.abi, self.args, self.ret = addr, name, abi, args, ret
        self.setup, self.n, self.note, self.abi_mine = setup, n, note, abi_mine or abi
        self.status_override = status_override   # (status, why) for functions not run (unverifiable)
        self.tries = tries                       # build/verify cycles it took to pass (worklog)
        self.gen = gen                           # optional fn(ctx) -> args (replaces args)
        self.max_insns = max_insns               # instruction budget per call (default 2,000,000)
        self.stack_arg_bytes = stack_arg_bytes   # bytes compared behind a stack-pointer call-log arg (see norm_stack)
        self.reg_values = reg_values             # compare callee-saved register VALUES, not only which ones were clobbered


SPECS = []


def S(*a, **k):
    s = Spec(*a, **k)
    SPECS.append(s)
    return s


# ============================================================================ comparison
def one_run(emu, spec, addr, abi, seed, case):
    emu.reset()
    rng = random.Random((seed << 32) ^ (spec.addr << 8) ^ case)
    c = Ctx(emu, rng, case)
    emu.reg_values = spec.reg_values
    if spec.setup:
        spec.setup(c)
    if spec.gen:
        c.args = spec.gen(c)
    else:
        for g in spec.args:
            c.args.append(g(c))
    for a in c.args:
        if isinstance(a, float) and not isinstance(a, (F, D)):
            # A bare float is truncated to an integer by run(), so the spec would test the wrong values.
            raise ValueError('%s: bare float argument %r; wrap it as F(x) (single) or D(x) (double)' % (spec.name, a))
    data0 = emu.rbytes(DATA_LO, DATA_HI - DATA_LO)
    try:
        out = emu.run(addr, abi, c.args, spec.ret, max_insns=spec.max_insns)
    except EmuStop as e:
        msg = str(e)
        # keep only the kind of fault and its address (EIP differs between the two codes)
        if msg.startswith('instruction limit'):
            out = {'fault': 'instruction limit'}       # both sides looping forever = same behaviour
        else:
            out = {'fault': msg.split(' (eip')[0] if msg.startswith('unmapped') else msg.split(' near')[0]}
    used = emu._heap_next - HEAP_BASE
    if out.get('fault') == 'instruction limit':
        out['calls'] = []
        out['heap'] = b''
        out['data'] = []
        return c, out
    out['heap'] = emu.rbytes(HEAP_BASE, used)
    data1 = emu.rbytes(DATA_LO, DATA_HI - DATA_LO)
    out['data'] = data_writes(data0, data1)
    out['calls'] = [norm_entry(emu, spec, e) for e in emu.calllog]
    return c, out


def norm_entry(emu, spec, e):
    """Each call-log entry, with its stack-pointer values replaced (see norm_stack). Entries of any length are
    accepted: stubs log 3-tuples and 4-tuples, and only tuples inside the entry are changed."""
    nb = getattr(spec, 'stack_arg_bytes', 4)
    def one(x):
        if isinstance(x, tuple):
            return tuple(one(y) for y in x)
        return norm_stack(emu, x, nb)
    return tuple(one(x) for x in e)


def norm_stack(emu, v, nb=4):
    """A call-log value that points into the stack is replaced by the first nb bytes it points to (default 4, the
    size of an out-flag or pointer; S(..., stack_arg_bytes=N) changes it per spec). Each side has its own frame,
    so the address differs even when the callee gets the same data. The bytes are read after the callee returns,
    so a value it wrote is included. Limits: a stack pointer stored inside those bytes still differs (use heap_mask
    for that word), and a struct larger than nb is only partly compared (set stack_arg_bytes for it)."""
    if not isinstance(v, int) or not (pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP):
        return v
    n = min(nb, pe_emu.STACK_TOP - v)
    return ('stk', emu.rbytes(v, n).hex())


def data_writes(data0, data1):
    """The .data bytes the code changed, as runs (address, new bytes). Compared as values, not only addresses:
    a wrong constant written into a global must fail (rule added 2026-10-11, see HOWTO)."""
    runs, n = [], len(data0)
    # Skip unchanged 4 KB blocks with one bytes compare; only the blocks that differ are scanned byte by byte.
    # (The byte loop alone cost ~100 ms per case on the 1.2 MB .data section.)
    for c in range(0, n, 4096):
        if data0[c:c + 4096] == data1[c:c + 4096]:
            continue
        i, end = c, min(c + 4096, n)
        while i < end:
            if data0[i] == data1[i]:
                i += 1
                continue
            j = i
            while j < end and data0[j] != data1[j]:
                j += 1
            runs.append((DATA_LO + i, bytes(data1[i:j])))
            i = j
    # A run that crosses a block edge is split in two above; merge touching runs so the output is unchanged.
    merged = []
    for a, b in runs:
        if merged and merged[-1][0] + len(merged[-1][1]) == a:
            merged[-1] = (merged[-1][0], merged[-1][1] + b)
        else:
            merged.append((a, b))
    return [(hex(a), b.hex()) for a, b in merged]


def diff(a, b):
    keys = sorted(set(a) | set(b))
    out = []
    for k in keys:
        if a.get(k) != b.get(k):
            if k == 'heap':
                ha, hb = a.get(k) or b'', b.get(k) or b''
                i = next((i for i in range(min(len(ha), len(hb))) if ha[i] != hb[i]), min(len(ha), len(hb)))
                off = i & ~3
                out.append('heap@0x%x orig=%s mine=%s' % (HEAP_BASE + off, ha[off:off + 4].hex(), hb[off:off + 4].hex()))
            else:
                out.append('%s orig=%r mine=%r' % (k, a.get(k), b.get(k)))
    return out


def _nan32(w):
    return (w & 0x7f800000) == 0x7f800000 and (w & 0x7fffff) != 0


def nan_only(a, b, nan_heap=False):
    """True when a and b differ only in the sign/payload of NaN floats (heap words, ST0, XMM0).

    Recompiled C++ cannot be forced to use the same operand order as the original SSE code, and
    the x86 rule "the first NaN operand wins; a generated NaN is negative" depends on that order.
    The game never inspects a NaN payload, so such cases are counted (nan_payload_cases) but not
    failed. Any other difference (also: NaN on one side only) is still a mismatch."""
    for k in set(a) | set(b):
        va, vb = a.get(k), b.get(k)
        if va == vb:
            continue
        if k == 'heap' and va is not None and vb is not None and len(va) == len(vb):
            if not nan_heap:
                return False        # raw bits: a stored integer must not pass as a NaN (2026-10-11)
            for i in range(0, len(va) - 3, 4):
                if va[i:i + 4] != vb[i:i + 4]:
                    x, y = struct.unpack_from('<I', va, i)[0], struct.unpack_from('<I', vb, i)[0]
                    if not (_nan32(x) and _nan32(y)):
                        return False
            if len(va) & 3 and va[-(len(va) & 3):] != vb[-(len(va) & 3):]:
                return False
        elif k == 'st0' and isinstance(va, str) and isinstance(vb, str):
            ba, bb = bytes.fromhex(va), bytes.fromhex(vb)
            ma, ea = struct.unpack('<Q', ba[:8])[0], struct.unpack('<H', ba[8:10])[0]
            mb, eb = struct.unpack('<Q', bb[:8])[0], struct.unpack('<H', bb[8:10])[0]
            if not ((ea & 0x7fff) == 0x7fff and (eb & 0x7fff) == 0x7fff and (ma << 1) & 0xffffffffffffffff and (mb << 1) & 0xffffffffffffffff):
                return False
        elif k == 'xmm0' and isinstance(va, int) and isinstance(vb, int):
            if not (_nan32(va) and _nan32(vb)):
                return False
        else:
            return False
    return True


def fmt_args(c):
    out = []
    for a in c.args:
        if isinstance(a, F):
            out.append('F(%r)' % float(a))
        else:
            out.append(hex(a) if isinstance(a, int) else repr(a))
    return out


def verify(emu, spec, n, seed):
    if spec.status_override:
        return {'status': spec.status_override[0], 'why': spec.status_override[1], 'cases': 0}
    mine = emu.decomp.get(spec.addr)
    if mine is None:
        return {'status': 'not-built', 'why': 'no PCREG(%x) in src/' % spec.addr, 'cases': 0}
    for h in list(emu.hooks):
        emu.unhook(h)        # hooks persist on the emulator: an earlier spec's hook must not reach this one
    n = spec.n or n
    faults = 0
    nanc = 0
    for case in range(n):
        c, o = one_run(emu, spec, spec.addr, spec.abi, seed, case)
        _, m = one_run(emu, spec, mine, spec.abi_mine, seed, case)
        if 'fault' in o:
            faults += 1
        if spec.heap_mask:
            # Words the spec names (for example a pointer to the port's own stack frame) are blanked on both sides.
            # They are NOT verified by this spec (see HOWTO, heap_mask).
            for _r in (o, m):
                h = bytearray(_r.get('heap', b''))
                for a, nb in spec.heap_mask(c):
                    i = a - HEAP_BASE
                    if 0 <= i < len(h):
                        h[i:i + nb] = b'\0' * min(nb, len(h) - i)
                _r['heap'] = bytes(h)
        d = diff(o, m)
        if d and nan_only(o, m, spec.nan_heap):
            nanc += 1
            d = []
        if d:
            return {'status': 'mismatch', 'cases': case + 1, 'why': '; '.join(d)[:600],
                    'args': fmt_args(c)}
    if faults == n:
        # Both sides fault on every input: the comparison says nothing about the logic (added 2026-10-09).
        return {'status': 'not-exercisable', 'cases': n, 'faulting_cases': faults,
                'why': 'original and port fault on every input; parity only'}
    return {'status': 'exact', 'cases': n, 'faulting_cases': faults, 'nan_payload_cases': nanc}


def build():
    r = subprocess.run(['sh', os.path.join(os.path.dirname(os.path.abspath(__file__)), 'build.sh'), ROOT], capture_output=True, text=True)
    sys.stdout.write(r.stdout)
    if r.returncode:
        sys.stderr.write(r.stderr)
        raise SystemExit('build failed')
    if r.stderr.strip():
        sys.stderr.write(r.stderr)


def load_specs():
    import glob
    import importlib
    sys.modules.setdefault('pilot', sys.modules[__name__])   # specs do `from pilot import S` (run as __main__)
    for f in sorted(glob.glob(os.path.join(HERE, 'specs_*.py'))):
        importlib.import_module(os.path.basename(f)[:-3])


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument('only', nargs='*', help='PC addresses (hex) or name substrings')
    ap.add_argument('-n', type=int, default=300)
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('--no-build', action='store_true')
    ap.add_argument('--json')
    ap.add_argument('-q', action='store_true')
    a = ap.parse_args(argv)
    if not a.no_build:
        build()
    load_specs()
    emu = Pilot()
    sel = SPECS
    if a.only:
        def want(s):
            for o in a.only:
                try:
                    if int(o, 16) == s.addr:
                        return True
                except ValueError:
                    pass
                if o in s.name:
                    return True
            return False
        sel = [s for s in SPECS if want(s)]
    results = []
    t0 = time.time()
    counts = {}
    for s in sel:
        t = time.time()
        r = verify(emu, s, a.n, a.seed)
        r.update({'addr': '0x%x' % s.addr, 'name': s.name, 'note': s.note, 'tries': s.tries,
                  'secs': round(time.time() - t, 2)})
        if r.get('nan_payload_cases'):
            r['note'] = (r['note'] + ' ' if r['note'] else '') + '[%d cases differ only in NaN sign/payload]' % r['nan_payload_cases']
        results.append(r)
        counts[r['status']] = counts.get(r['status'], 0) + 1
        if not a.q or r['status'] != 'exact':
            print('%-10s %-9s %-42s %5s  %s' % (r['addr'], r['status'], s.name[:42], r['cases'],
                                                 r.get('why', '') + ('  args=' + ' '.join(r['args']) if 'args' in r else '')))
    print('== %s  (%d functions, %.1fs, seed %d, n %d, FPCW 0x%x)' % (
        ', '.join('%s %d' % kv for kv in sorted(counts.items())), len(sel), time.time() - t0, a.seed, a.n, FPCW))
    unspecced = sorted(set(emu.decomp) - {s.addr for s in SPECS})
    if unspecced and not a.only:
        print('registered in src/ but no spec:', ' '.join('0x%x' % x for x in unspecced))
    if a.json:
        json.dump(results, open(a.json, 'w'), indent=1)
    return 1 if any(r['status'] == 'mismatch' for r in results) else 0


if __name__ == '__main__':
    sys.exit(main())
