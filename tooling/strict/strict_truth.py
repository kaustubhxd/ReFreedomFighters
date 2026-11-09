"""strict_truth.py - what the ORIGINAL exe says about each callee and call site (never what a port or a spec declares).

    T = truth()
    T.callee(0x634273)  -> {'pop': bytes the callee pops (`ret N`; 0 for a plain ret), 'reads': {'ecx','edx'} read before written
                            on some path, 'writes': {'ecx','edx'} written somewhere (the real callee does not preserve them),
                            'thunk': target or None, 'mixed': rets disagree, 'known': False when nothing could be decoded}
    T.callsite(ra)      -> {'kind': 'direct'|'mem'|'reg'|'none', 'target': addr|None, 'pushes': dwords pushed since the previous
                            call / jump target / function entry, 'cleanup': bytes the caller removes right after the call,
                            'ecx_set', 'edx_set': the register is written in that chain, 'certain': the chain ended at a previous
                            call or at the function entry (not at a jump target), 'func': entry of the containing function}

Everything is derived from the pristine bytes of the original executable (path from tooling/pe_emu.py, i.e. FF_RE_ROOT) with capstone; nothing is executed.
"""
import bisect
import json
import os
import struct

import capstone
from capstone import x86_const as X
import pefile

import sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))   # tooling/
from pe_emu import DEFAULT_ROOT, DEFAULT_EXE   # noqa: E402  (the exe path is resolved in one place: FF_RE_ROOT)

ROOT = DEFAULT_ROOT
EXE = DEFAULT_EXE
FUNCS = os.environ.get('FF_FUNCTIONS') or os.path.join(ROOT, 'out', 'functions.jsonl')   # the function list of the user's own analysis (entry + ranges per line)

_PARENT = {}
for _p, _names in {'ecx': ('ecx', 'cx', 'cl', 'ch'), 'edx': ('edx', 'dx', 'dl', 'dh'),
                   'eax': ('eax', 'ax', 'al', 'ah'), 'ebx': ('ebx', 'bx', 'bl', 'bh'), 'esi': ('esi', 'si'),
                   'edi': ('edi', 'di'), 'ebp': ('ebp', 'bp'), 'esp': ('esp', 'sp')}.items():
    for _n in _names:
        _PARENT[_n] = _p
def is_ret(i):
    return i.mnemonic == 'ret' or i.mnemonic.endswith(' ret') or i.mnemonic == 'retf'


SAVED = ('ebx', 'esi', 'edi', 'ebp')
CD = ('ecx', 'edx')


class Truth:
    def __init__(self, exe=EXE, funcs=FUNCS):
        pe = pefile.PE(exe, fast_load=True)
        self.base = pe.OPTIONAL_HEADER.ImageBase
        self.size = (pe.OPTIONAL_HEADER.SizeOfImage + 0xfff) & ~0xfff
        img = bytearray(self.size)
        data = pe.__data__
        for s in pe.sections:
            raw = data[s.PointerToRawData:s.PointerToRawData + min(s.SizeOfRawData, s.Misc_VirtualSize or s.SizeOfRawData)]
            img[s.VirtualAddress:s.VirtualAddress + len(raw)] = raw
        self.image = bytes(img)
        self.cs = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.cs.detail = True
        self.franges = {}
        rs = []
        if not os.path.exists(funcs):
            # Without function ranges the call sites cannot be attributed to their functions and the strict checks would silently
            # weaken (ports would be reported exact that are not), so refuse instead.
            raise SystemExit('strict mode needs the function list of the original executable: %s not found (it is the same out/functions.jsonl '
                             'that decoders/tools uses: one JSON object per line with "entry", "ranges" and "external"). '
                             'Set FF_RE_ROOT or FF_FUNCTIONS.' % funcs)
        with open(funcs) as fh:
            for l in fh:
                f = json.loads(l)
                if f.get('external'):
                    continue
                e = f['entry']
                self.franges[e] = [tuple(r) for r in f['ranges']]
                for a, b in f['ranges']:
                    rs.append((a, b, e))
        rs.sort()
        self.range_starts = rs
        self._rs_keys = [r[0] for r in rs]
        self._fc = {}
        self._callee = {}
        self._site = {}

    # ---------------------------------------------------------------- raw bytes / functions
    def read(self, addr, n):
        o = addr - self.base
        if o < 0 or o >= self.size:
            return b''
        return self.image[o:o + n]

    def func_of(self, addr):
        i = bisect.bisect_right(self._rs_keys, addr) - 1
        for j in range(i, max(i - 8, -1), -1):
            a, b, e = self.range_starts[j]
            if a <= addr < b:
                return e
        return None

    def _dis(self, a, b):
        return list(self.cs.disasm(self.read(a, b - a), a))

    @staticmethod
    def imm_target(i):
        if i.operands and i.operands[0].type == X.X86_OP_IMM:
            return i.operands[0].imm & 0xffffffff
        return None

    def regs(self, i):
        """(read, write) parent register sets of an instruction (explicit and implicit operands)."""
        try:
            rd, wr = i.regs_access()
        except Exception:
            return set(), set()
        nm = self.cs.reg_name
        return ({_PARENT.get(nm(r)) for r in rd} - {None}, {_PARENT.get(nm(r)) for r in wr} - {None})

    def func(self, entry):
        """(insns by address, {addr: index}, labels) of the function at entry (all of its ranges)."""
        r = self._fc.get(entry)
        if r is not None:
            return r
        ranges = self.franges.get(entry)
        if ranges is None:      # not in the function list: linear scan to the first ret / int3
            ins = []
            for i in self.cs.disasm(self.read(entry, 0x600), entry):
                ins.append(i)
                if is_ret(i) or i.mnemonic == 'int3':
                    break
            ranges = [(entry, ins[-1].address + ins[-1].size)] if ins else [(entry, entry)]
        ins = []
        for a, b in sorted(ranges):
            ins.extend(self._dis(a, b))
        ins.sort(key=lambda i: i.address)
        byaddr = {i.address: k for k, i in enumerate(ins)}
        labels = set()
        for i in ins:
            if i.mnemonic.startswith('j') or i.mnemonic.startswith('loop'):
                t = self.imm_target(i)
                if t is not None:
                    labels.add(t)
        if ins:
            lo, hi = min(a for a, _ in ranges), max(b for _, b in ranges)
            for i in ins:      # jump table: dwords at the table that point back into the function are labels
                if i.mnemonic == 'jmp' and i.operands and i.operands[0].type == X.X86_OP_MEM and i.operands[0].mem.index != 0 and i.operands[0].mem.disp:
                    tbl = i.operands[0].mem.disp & 0xffffffff
                    for k in range(256):
                        d = self.read(tbl + 4 * k, 4)
                        if len(d) < 4:
                            break
                        v = struct.unpack('<I', d)[0]
                        if lo <= v < hi:
                            labels.add(v)
                        else:
                            break
        r = (ins, byaddr, labels)
        self._fc[entry] = r
        return r

    # ---------------------------------------------------------------- callee truth
    def callee(self, addr, depth=0):
        if addr in self._callee:
            return self._callee[addr]
        res = {'pop': 0, 'reads': set(), 'writes': set(), 'thunk': None, 'mixed': False, 'known': True, 'rets': [], 'pushed': set()}
        self._callee[addr] = res          # recursion guard (filled in place)
        ins, byaddr, labels = self.func(addr)
        if not ins or addr not in byaddr:
            res['known'] = False
            return res
        first = ins[byaddr[addr]]
        if first.mnemonic == 'jmp' and self.imm_target(first) is not None and depth < 4:   # thunk: the target is the real callee
            res['thunk'] = self.imm_target(first)
            r2 = self.callee(res['thunk'], depth + 1)
            for k in ('pop', 'mixed', 'known', 'rets'):
                res[k] = r2[k]
            res['reads'], res['writes'], res['pushed'] = set(r2['reads']), set(r2['writes']), set(r2.get('pushed', ()))
            return res
        rets = {(i.operands[0].imm if i.operands else 0) for i in ins if is_ret(i)}
        res['rets'] = sorted(rets)
        if rets:
            res['pop'] = max(rets)
            res['mixed'] = len(rets) > 1
        else:       # no ret in the body: a tail jump out of the function carries the callee's pop; otherwise the pop is UNKNOWN (import thunk, indirect jmp, truncated range)
            res['known'] = False
            for i in ins:
                t = self.imm_target(i) if i.mnemonic == 'jmp' else None
                if t is not None and t not in byaddr and depth < 3:
                    c2 = self.callee(t, depth + 1)
                    res['pop'] = c2['pop']
                    res['rets'] = list(c2['rets'])
                    res['known'] = c2['known']
                    break
        seen = set()
        work = [(byaddr[addr], frozenset())]
        reads, writes_any, steps, pushed = set(), set(), 0, set()
        while work and steps < 30000:
            idx, wr = work.pop()
            while 0 <= idx < len(ins):
                key = (idx, wr)
                if key in seen:
                    break
                seen.add(key)
                steps += 1
                i = ins[idx]
                m = i.mnemonic
                rd, w = self.regs(i)
                if (m == 'or' and i.op_str.endswith(', -1')) or (m == 'and' and i.op_str.endswith(', 0')):
                    rd = set()                 # `or edx, -1` / `and ecx, 0` are pure writes
                if m in ('xor', 'sub', 'sbb') and len(i.operands) == 2 and i.operands[0].type == X.X86_OP_REG \
                        and i.operands[1].type == X.X86_OP_REG and i.operands[0].reg == i.operands[1].reg:
                    rd = set()
                if m == 'push' and i.operands and i.operands[0].type == X.X86_OP_REG:
                    for r in CD:
                        if r in rd and r not in wr:
                            pushed.add(r)
                    rd = rd - set(CD)          # `push ecx` is MSVC's 4-byte stack reserve far more often than an argument
                if m == 'call':
                    t = self.imm_target(i)
                    if t in (0x6336b0, 0x633c90, 0x633ca6):
                        # The original probe saves/restores ECX and never
                        # touches EDX (0x6336b0..0x6336db). Both aligned
                        # variants save/restore ECX and tail-jump to it.
                        w = w | {'eax'}
                    else:
                        if t is not None and depth < 3:
                            c2 = self.callee(t, depth + 1)
                            for r in CD:
                                if r in c2['reads'] and r not in wr:
                                    reads.add(r)
                        w = w | {'ecx', 'edx', 'eax'}
                for r in CD:
                    if r in rd and r not in wr:
                        reads.add(r)
                writes_any |= (w & set(CD))
                wr = wr | (w & set(CD))
                if is_ret(i):
                    break
                if m == 'jmp':
                    t = self.imm_target(i)
                    if t is not None and t in byaddr:
                        idx = byaddr[t]
                        continue
                    if t is not None and depth < 3:     # tail jump out of the function
                        c2 = self.callee(t, depth + 1)
                        for r in CD:
                            if r in c2['reads'] and r not in wr:
                                reads.add(r)
                        writes_any |= c2['writes']
                    break
                if m.startswith('j') or m.startswith('loop'):
                    t = self.imm_target(i)
                    if t is not None and t in byaddr:
                        work.append((byaddr[t], wr))
                idx += 1
        res['reads'], res['writes'], res['pushed'] = reads, writes_any, pushed
        return res

    # ---------------------------------------------------------------- call-site truth
    def prologue_end(self, fe):
        """Index of the first instruction after the function prologue: the longest prefix of saved-register pushes, frame setup,
        register copies and argument loads (none of which are outgoing arguments), or everything up to the SEH `mov fs:[0], reg`."""
        ins = self.func(fe)[0]
        seh = -1
        for k, i in enumerate(ins[:40]):
            if i.mnemonic == 'mov' and i.op_str.startswith('dword ptr fs:[0], '):
                seh = k             # the first one is the install of the SEH frame (later ones restore the previous frame)
                break
        k = 0
        while k < len(ins):
            i = ins[k]
            m, o = i.mnemonic, i.op_str
            ok = False
            if m == 'push' and (o in SAVED or o in CD):
                # A callee-saved register pushed after this function has
                # assigned it is an outgoing value, not its entry save.
                ok = not (o in SAVED and self._written_before(fe, k, o))
            elif m == 'mov' and o == 'ebp, esp':
                ok = True
            elif m == 'sub' and o.startswith('esp, ') and i.operands[1].type == X.X86_OP_IMM:
                ok = True
            elif m == 'mov' and len(i.operands) == 2 and i.operands[0].type == X.X86_OP_REG and (
                    i.operands[1].type == X.X86_OP_REG or (i.operands[1].type == X.X86_OP_MEM and i.operands[1].mem.base in (X.X86_REG_EBP, X.X86_REG_ESP))):
                ok = True
            elif m in ('xor', 'and') and len(i.operands) == 2 and i.operands[0].type == X.X86_OP_REG and i.operands[1].type == X.X86_OP_REG:
                ok = True
            elif m == 'and' and o.startswith('esp, '):
                ok = True
            if not ok:
                break
            k += 1
        return max(k, seh + 1)

    def _written_before(self, fe, k, reg):
        ins = self.func(fe)[0]
        for i in ins[:k]:
            if i.mnemonic == 'push':
                continue
            if reg in self.regs(i)[1]:
                return True
        return False

    def site_at(self, fe, ci, depth=0):
        """Analysis of the call instruction ins[ci] of function fe (see the module doc); memoized."""
        key = (fe, ci)
        if key in self._site:
            return self._site[key]
        ins, byaddr, labels = self.func(fe)
        c = ins[ci]
        out = {'kind': 'none', 'target': None, 'pushes': 0, 'cleanup': 0, 'ecx_set': False, 'edx_set': False, 'certain': False,
               'capture': False, 'clean': False, 'func': fe, 'barrier': None}
        self._site[key] = out
        op = c.operands[0] if c.operands else None
        if op is None:
            return out
        if op.type == X.X86_OP_IMM:
            out['kind'], out['target'] = 'direct', op.imm & 0xffffffff
        elif op.type == X.X86_OP_MEM:
            out['kind'] = 'mem'
            out['vt_ecx'] = op.mem.base == X.X86_REG_ECX      # call [ecx+N]: ECX holds the vtable pointer here, `this` is elsewhere
            if op.mem.base == 0 and op.mem.index == 0:
                out['target'] = op.mem.disp & 0xffffffff      # call [IAT slot]
        else:
            out['kind'] = 'reg'
        clean, j = 0, ci + 1
        while j < len(ins):
            n = ins[j]
            if n.mnemonic == 'add' and n.op_str.startswith('esp, ') and n.operands[1].type == X.X86_OP_IMM:
                clean += n.operands[1].imm
                break
            if n.mnemonic == 'pop' and n.op_str in ('ecx', 'edx'):      # MSVC's `pop ecx` 4-byte cleanup
                clean += 4
                j += 1
                continue
            break
        out['cleanup'] = clean
        lead_end = self.prologue_end(fe)
        pushes = skip = 0
        ecx_set = edx_set = certain = capture = False
        k = ci - 1
        barrier = None
        while k >= 0:
            i = ins[k]
            m = i.mnemonic
            if m == 'call':
                certain = True
                barrier = k
                break
            if k < lead_end:
                certain = True
                break
            rd, w = self.regs(i)
            if capture:
                pass            # only register writes still matter
            elif m == 'push':
                if i.op_str in SAVED + CD and not self._written_before(fe, k, i.op_str):
                    pass            # a callee-saved register saved on entry, not an outgoing argument
                elif skip:
                    skip -= 1
                else:
                    pushes += 1
            elif m == 'pop':
                skip += 1
            elif m == 'add' and i.op_str.startswith('esp, ') and i.operands[1].type == X.X86_OP_IMM:
                skip += i.operands[1].imm // 4
            elif m == 'sub' and i.op_str.startswith('esp, ') and i.operands[1].type == X.X86_OP_IMM:
                n = i.operands[1].imm // 4
                if skip:
                    skip = max(0, skip - n)
                else:
                    pushes += n
            elif (m == 'mov' and i.op_str.endswith(', esp') and i.operands[0].type == X.X86_OP_REG) or \
                    (m == 'lea' and len(i.operands) == 2 and i.operands[1].type == X.X86_OP_MEM and i.operands[1].mem.base == X.X86_REG_ESP):
                capture = True      # the address of the stack area is taken: the words below this point are locals / by-value temporaries
            if 'ecx' in w:
                ecx_set = True
            if 'edx' in w:
                edx_set = True
            if i.address in labels:
                certain = False
                break
            k -= 1
        if k < 0:
            certain = True
        if out.get('vt_ecx'):
            ecx_set = False
        out.update(pushes=pushes, ecx_set=ecx_set, edx_set=edx_set, certain=certain, capture=capture, barrier=barrier)
        # clean: the pop of this site equals its own pushes (nothing pending from before the barrier / no locals area)
        cl = certain and not capture and clean == 0
        if cl and barrier is not None:
            b = self.site_at(fe, barrier, depth + 1) if depth < 3 else None
            if b is None:
                cl = False
            elif b['kind'] == 'direct':
                ce = self.callee(b['target'])
                cl = ce['known'] and (ce['pop'] // 4 == b['pushes'] if ce['pop'] > 0 else (b['cleanup'] // 4 == b['pushes'] and b['pushes'] >= 0 and not b['capture'] and b['certain']))
            else:
                cl = b['clean']
        out['clean'] = cl
        return out

    def callsite(self, ra):
        """Site analysis for the call that returns to ra, or the 'none' record."""
        if ra in self._site:
            return self._site[ra]
        none = {'kind': 'none', 'target': None, 'pushes': 0, 'cleanup': 0, 'ecx_set': False, 'edx_set': False, 'certain': False,
                'capture': False, 'clean': False, 'func': None, 'barrier': None}
        fe = self.func_of(ra - 1)
        r = none
        if fe is not None:
            ins, byaddr, labels = self.func(fe)
            for k in (2, 3, 5, 6, 7):
                j = byaddr.get(ra - k)
                if j is not None and ins[j].mnemonic == 'call' and ins[j].address + ins[j].size == ra:
                    r = self.site_at(fe, j)
                    break
        self._site[ra] = r
        return r


_T = None


def truth():
    global _T
    if _T is None:
        _T = Truth()
    return _T


if __name__ == '__main__':
    import sys
    t = truth()
    for a in sys.argv[1:]:
        a = int(a, 16)
        print('0x%x callee' % a, t.callee(a))
