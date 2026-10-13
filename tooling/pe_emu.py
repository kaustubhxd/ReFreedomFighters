"""pe_emu.py - run single functions of the PC Freedom Fighters exe in Unicorn (x86-32).

Nothing here is game-specific except the default exe path. See README.md in this folder.

    emu = PEEmu()                      # maps Freedom.Exe.orig, checks its sha256
    obj = emu.alloc(0x100)             # fake heap
    emu.wf32(obj + 0xb0, 5000.0)
    r = emu.call(0x46b4c0, this=obj, args=[weapon, F(1234.0)], float_ret=True)
    r.st0, r.eax, r.writes

Rules the harness enforces (each one stops the run with a clear message):
  * a call into an import (IAT slot) that has no Python stub,
  * a fetch, read or write of unmapped memory (the null page is unmapped),
  * a call through a fake vtable slot that has no stub,
  * int3 / any interrupt (MSVC asserts end in int3 when the assert hook pointer is null),
  * more than `max_insns` instructions.
"""
import hashlib
import os
import struct

import pefile
from unicorn import (Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED,
                     UC_HOOK_MEM_WRITE, UC_HOOK_INTR, UC_PROT_ALL, UC_MEM_WRITE_UNMAPPED,
                     UC_MEM_READ_UNMAPPED, UC_MEM_FETCH_UNMAPPED)
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDX,
                               UC_X86_REG_ESI, UC_X86_REG_EDI, UC_X86_REG_EBP, UC_X86_REG_ESP,
                               UC_X86_REG_EIP, UC_X86_REG_FPSW, UC_X86_REG_XMM0, UC_X86_REG_XMM1,
                               UC_X86_REG_XMM2)

DEFAULT_ROOT = os.environ.get('FF_RE_ROOT') or '/mnt/user-data/uploads/freedom-fighters-re'
DEFAULT_EXE = os.path.join(DEFAULT_ROOT, 'bin', 'Freedom.Exe.orig')

REGS = {'eax': UC_X86_REG_EAX, 'ebx': UC_X86_REG_EBX, 'ecx': UC_X86_REG_ECX, 'edx': UC_X86_REG_EDX,
        'esi': UC_X86_REG_ESI, 'edi': UC_X86_REG_EDI, 'ebp': UC_X86_REG_EBP, 'esp': UC_X86_REG_ESP,
        'xmm0': UC_X86_REG_XMM0, 'xmm1': UC_X86_REG_XMM1, 'xmm2': UC_X86_REG_XMM2}

STACK_TOP = 0x0ff00000
STACK_SIZE = 0x00100000
HEAP_BASE = 0x20000000
HEAP_SIZE = 0x01000000
STUB_BASE = 0x7e000000      # import stubs, fake vtable slots, trampolines; never real code
STUB_SIZE = 0x00100000
SCRATCH = STUB_BASE + STUB_SIZE - 0x100   # float return slot etc. (inside the stub page range)


class F(float):
    """A float32 argument (pushed as 4 bytes). Plain ints are pushed as u32."""


class D(float):
    """A float64 argument (pushed as 8 bytes)."""


def f32(x):
    """Round a Python float to float32 (keeps NaN / inf)."""
    return struct.unpack('<f', struct.pack('<f', x))[0]


def f32_bits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


class EmuStop(Exception):
    """The run stopped for a reason the caller did not ask for (unmapped access, missing stub...)."""


class Result:
    def __init__(self):
        self.eax = None
        self.st0 = None          # float (from fstp qword) when float_ret=True
        self.fpu_balanced = None
        self.writes = []         # (eip, addr, size, value) for writes to the heap
        self.stopped_at = None   # address of a stop_at hook that ended the run
        self.captured = {}       # whatever stop/hooks put here
        self.insns = 0

    def __repr__(self):
        return 'Result(eax=%r, st0=%r, stopped_at=%r, captured=%r)' % (
            None if self.eax is None else hex(self.eax), self.st0,
            None if self.stopped_at is None else hex(self.stopped_at), self.captured)


class PEEmu:
    def __init__(self, exe=DEFAULT_EXE, check_hash=True):
        self.exe = exe
        if check_hash:
            self.sha256 = self._check_hash(exe)
        self.pe = pefile.PE(exe, fast_load=False)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.size = (self.pe.OPTIONAL_HEADER.SizeOfImage + 0xfff) & ~0xfff
        self.image = self._build_image()
        self.mu = Uc(UC_ARCH_X86, UC_MODE_32)
        self.mu.mem_map(self.base, self.size, UC_PROT_ALL)
        self.mu.mem_write(self.base, bytes(self.image))
        self.mu.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE, UC_PROT_ALL)
        self.mu.mem_map(HEAP_BASE, HEAP_SIZE, UC_PROT_ALL)
        self.mu.mem_map(STUB_BASE, STUB_SIZE, UC_PROT_ALL)
        # Trial copy only (decomp-pilot/trial-level1): a fake TEB at 0, so fs:[0] reads work.
        # FS base is 0 in this flat model, so fs:[x] is address x. Exception list = -1, stack limits, self.
        # Page 0 is now mapped, so a NULL dereference no longer faults in this trial copy.
        self.mu.mem_map(0, 0x1000, UC_PROT_ALL)
        self.mu.mem_write(0, struct.pack('<IIII', 0xffffffff, STACK_TOP, STACK_TOP - STACK_SIZE, 0))
        self.mu.mem_write(0x18, struct.pack('<I', 0))
        self._stub_next = STUB_BASE + 0x1000
        self.stubs = {}          # addr -> (name, handler or None)
        self.hooks = {}          # real-code addr -> handler(emu, result) for callee stubs
        self.imports = {}        # 'DLL!name' -> stub addr
        self._map_imports()
        # fixed trampolines
        self.RET_ADDR = self._new_stub('<return>', None)
        self.RET_FLOAT = self._alloc_stub_code(
            b'\xdd\x1d' + struct.pack('<I', SCRATCH) + b'\xe9' + b'\0' * 4)  # fstp qword [SCRATCH]; jmp RET_ADDR
        rel = self.RET_ADDR - (self.RET_FLOAT + 11)
        self.mu.mem_write(self.RET_FLOAT + 7, struct.pack('<i', rel))
        self._fld_tramps = {}
        self._install_math_stubs()
        self._install_cpu_feature_stub()
        self._stub_mark = self._stub_next   # stubs above this are per-run (fake vtables, stub_fn)
        self._image_dirty = False
        self._heap_next = HEAP_BASE
        self._cur = None
        self.mu.hook_add(UC_HOOK_CODE, self._on_stub_code, begin=STUB_BASE, end=STUB_BASE + STUB_SIZE - 1)
        self.mu.hook_add(UC_HOOK_MEM_UNMAPPED, self._on_unmapped)
        self.mu.hook_add(UC_HOOK_INTR, self._on_intr)
        self.mu.hook_add(UC_HOOK_MEM_WRITE, self._on_heap_write, begin=HEAP_BASE, end=HEAP_BASE + HEAP_SIZE - 1)
        self.mu.hook_add(UC_HOOK_MEM_WRITE, self._on_image_write, begin=self.base, end=self.base + self.size - 1)
        self._code_hooks = {}

    # ------------------------------------------------------------------ loading
    @staticmethod
    def _check_hash(exe):
        h = hashlib.sha256(open(exe, 'rb').read()).hexdigest()
        side = exe + '.sha256'
        if os.path.exists(side):
            want = open(side).read().split()[0].lower()
            if want != h:
                raise SystemExit('sha256 mismatch for %s: %s, expected %s' % (exe, h, want))
        return h

    def _build_image(self):
        img = bytearray(self.size)
        data = self.pe.__data__
        hdr = self.pe.OPTIONAL_HEADER.SizeOfHeaders
        img[:hdr] = data[:hdr]
        for s in self.pe.sections:
            raw = data[s.PointerToRawData:s.PointerToRawData + min(s.SizeOfRawData, s.Misc_VirtualSize or s.SizeOfRawData)]
            img[s.VirtualAddress:s.VirtualAddress + len(raw)] = raw
        return img

    def _map_imports(self):
        for entry in getattr(self.pe, 'DIRECTORY_ENTRY_IMPORT', []):
            dll = entry.dll.decode('latin-1')
            for imp in entry.imports:
                name = imp.name.decode('latin-1') if imp.name else 'ord%d' % imp.ordinal
                full = '%s!%s' % (dll, name)
                a = self._new_stub('import ' + full, None)
                self.imports[full] = a
                struct.pack_into('<I', self.image, imp.address - self.base, a)
                self.mu.mem_write(imp.address, struct.pack('<I', a))

    def stub_import(self, name, handler):
        """Give an import a Python implementation. name: 'func' or 'DLL!func'."""
        hits = [k for k in self.imports if k == name or k.split('!', 1)[1] == name]
        if not hits:
            raise KeyError('no import named %r' % name)
        for k in hits:
            a = self.imports[k]
            self.stubs[a] = (self.stubs[a][0], handler)

    def _install_math_stubs(self):
        """Pure CRT math with the SSE2 convention (double in xmm0 -> double in xmm0), so that
        sqrt/sin/... in game code do not stop the run. Python's libm is not bit-identical to the
        MSVC CRT for sin/cos/etc.; sqrt is exact either way."""
        import math as _m
        fns = {'sqrt': _m.sqrt, 'sin': _m.sin, 'cos': _m.cos, 'tan': _m.tan, 'atan': _m.atan,
               'asin': _m.asin, 'acos': _m.acos, 'exp': _m.exp, 'log': _m.log, 'log10': _m.log10}
        for nm, fn in fns.items():
            def h(e, r, fn=fn):
                x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
                try:
                    y = fn(x)
                except (ValueError, OverflowError):
                    y = float('nan')
                e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', y))[0])
                e.ret()
            try:
                self.stub_import('_libm_sse2_%s_precise' % nm, h)
            except KeyError:
                pass

    # Processor features a 2020s x86-64 Windows host reports as present (PF_* numbers from winnt.h).
    # Anything not listed answers 0 (including PF_FLOATING_POINT_PRECISION_ERRATA = 0, the FDIV bug).
    CPU_FEATURES_PRESENT = frozenset([3, 6, 7, 8, 10, 13, 17, 18, 21, 23])

    def _install_cpu_feature_stub(self):
        """KERNEL32!IsProcessorFeaturePresent(feature) -> BOOL, stdcall(4). The CRT start-up/fast-fail
        code calls it; without a stub such a run stops. Deterministic; override with stub_import()."""
        def h(e, r):
            e.ret(eax=1 if e.arg32(0) in self.CPU_FEATURES_PRESENT else 0, argbytes=4)
        try:
            self.stub_import('IsProcessorFeaturePresent', h)
        except KeyError:
            pass

    def _new_stub(self, name, handler):
        a = self._stub_next
        self._stub_next += 0x10
        self.mu.mem_write(a, b'\xc3')
        self.stubs[a] = (name, handler)
        return a

    def _alloc_stub_code(self, code):
        a = self._stub_next
        self._stub_next += (len(code) + 0xf) & ~0xf
        self.mu.mem_write(a, code)
        return a

    def _fld_tramp(self, argbytes):
        """Trampoline 'fld dword [SCRATCH+8]; ret argbytes' used by float-returning stubs."""
        t = self._fld_tramps.get(argbytes)
        if t is None:
            code = b'\xd9\x05' + struct.pack('<I', SCRATCH + 8)
            code += (b'\xc2' + struct.pack('<H', argbytes)) if argbytes else b'\xc3'
            t = self._alloc_stub_code(code)
            self._fld_tramps[argbytes] = t
        return t

    # ------------------------------------------------------------------ memory helpers
    def reset_stubs(self):
        """Forget per-run stubs (fake vtable slots, stub_fn, trampolines) made since load."""
        for a in [a for a in self.stubs if a >= self._stub_mark]:
            del self.stubs[a]
        self._fld_tramps = {}
        self._stub_next = self._stub_mark
        # 2026-10-11 (docs/38): drop Unicorn's translated code for the stub area so a stub rewritten for this case
        # is not run from a stale translation (false, order-dependent mismatches seen in the VM with unicorn 2.1.4).
        try:
            self.mu.ctl_remove_cache(STUB_BASE, STUB_BASE + STUB_SIZE)
        except Exception:
            pass

    def reset(self):
        """Fresh state for the next case: empty heap, per-run stubs gone, globals restored."""
        self.reset_heap()
        self.reset_stubs()
        self.reset_image()

    def reset_heap(self):
        used = self._heap_next - HEAP_BASE
        if used:
            self.mu.mem_write(HEAP_BASE, b'\0' * used)
        self._heap_next = HEAP_BASE

    def reset_image(self):
        """Restore the exe image (globals) if a run wrote to it."""
        if self._image_dirty:
            self.mu.mem_write(self.base, bytes(self.image))
            self._image_dirty = False

    def alloc(self, size, align=16, fill=0):
        a = (self._heap_next + align - 1) & ~(align - 1)
        if a + size > HEAP_BASE + HEAP_SIZE:
            raise MemoryError('fake heap full')
        self._heap_next = a + size
        self.mu.mem_write(a, bytes([fill]) * size)
        return a

    # Host writes do not fire the image write hook, so a spec writing a global (e.g. 0x70039c) marks the image dirty
    # here; otherwise the value would leak into later cases and functions (shared-harness fix, 2026-10-11).
    def _host_write(self, a, data):
        if self.base <= a < self.base + len(self.image):
            self._image_dirty = True
        self.mu.mem_write(a, data)
    def w8(self, a, v): self._host_write(a, struct.pack('<B', v & 0xff))
    def w16(self, a, v): self._host_write(a, struct.pack('<H', v & 0xffff))
    def w32(self, a, v): self._host_write(a, struct.pack('<I', v & 0xffffffff))
    def wf32(self, a, v): self._host_write(a, struct.pack('<f', v))
    def wbytes(self, a, b): self._host_write(a, bytes(b))
    def r8(self, a): return self.mu.mem_read(a, 1)[0]
    def r32(self, a): return struct.unpack('<I', self.mu.mem_read(a, 4))[0]
    def rf32(self, a): return struct.unpack('<f', self.mu.mem_read(a, 4))[0]
    def rbytes(self, a, n): return bytes(self.mu.mem_read(a, n))

    def cstr(self, s):
        b = s.encode('latin-1') + b'\0'
        a = self.alloc(len(b), 4)
        self.wbytes(a, b)
        return a

    def reg(self, name): return self.mu.reg_read(REGS[name])

    def xmm_f32(self, name):
        return struct.unpack('<f', struct.pack('<I', self.mu.reg_read(REGS[name]) & 0xffffffff))[0]

    def arg32(self, i):
        """i-th stack argument (0-based) when stopped on the first instruction of a callee."""
        return self.r32(self.reg('esp') + 4 + 4 * i)

    def argf(self, i):
        return struct.unpack('<f', struct.pack('<I', self.arg32(i)))[0]

    # ------------------------------------------------------------------ fake objects
    def fake_vtable(self, name, nslots, slots=None):
        """A vtable of nslots entries. slots: {byte_offset: handler | real address}.
        Every other slot is a stub that stops with 'unstubbed virtual call'."""
        vt = self.alloc(4 * nslots, 4)
        slots = slots or {}
        for i in range(nslots):
            off = 4 * i
            h = slots.get(off)
            if isinstance(h, int):
                tgt = h
            else:
                tgt = self._new_stub('%s vtable slot +0x%x' % (name, off), h)
            self.w32(vt + off, tgt)
        return vt

    def fake_object(self, name, size, vtable=None, nslots=0, slots=None):
        """Allocate an object; vtable = a real vtable address, or build a fake one (nslots/slots)."""
        o = self.alloc(size)
        if vtable is None and (nslots or slots):
            vtable = self.fake_vtable(name, max(nslots, (max(slots) // 4 + 1) if slots else 0), slots)
        if vtable is not None:
            self.w32(o, vtable)
        return o

    def stub_fn(self, name, handler):
        """A free function address that runs a Python handler (for function pointers in data)."""
        return self._new_stub(name, handler)

    # ------------------------------------------------------------------ returning from stubs
    def ret(self, eax=None, argbytes=0, st0=None):
        """Finish a stubbed call: set EAX and/or push ST0, pop the return address and argbytes."""
        if eax is not None:
            self.mu.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        if st0 is not None:
            self.mu.mem_write(SCRATCH + 8, struct.pack('<f', st0))
            self.mu.reg_write(UC_X86_REG_EIP, self._fld_tramp(argbytes))
            return
        esp = self.reg('esp')
        ra = self.r32(esp)
        self.mu.reg_write(UC_X86_REG_ESP, esp + 4 + argbytes)
        self.mu.reg_write(UC_X86_REG_EIP, ra)

    def stop(self, reason, ok=True):
        """End the run from a hook. ok=True: a planned stop (results are valid)."""
        self._cur_stop = (reason, ok)
        self.mu.emu_stop()

    # ------------------------------------------------------------------ hooks
    def hook(self, addr, handler):
        """Replace the real function at addr with handler(emu, result). Persistent until unhook."""
        self.hooks[addr] = handler
        if addr not in self._code_hooks:
            self._code_hooks[addr] = self.mu.hook_add(UC_HOOK_CODE, self._on_real_code, begin=addr, end=addr)

    def unhook(self, addr):
        self.hooks.pop(addr, None)
        h = self._code_hooks.pop(addr, None)
        if h is not None:
            self.mu.hook_del(h)

    def _on_real_code(self, mu, addr, size, _):
        h = self.hooks.get(addr)
        if h is not None and self._cur is not None:
            h(self, self._cur)

    def _on_stub_code(self, mu, addr, size, _):
        if self._cur is None:
            return
        if addr == self.RET_ADDR:
            self._cur_stop = ('returned', True)
            mu.emu_stop()
            return
        st = self.stubs.get(addr)
        if st is None:
            return  # trampoline code
        name, handler = st
        if handler is None:
            ra = self.r32(self.reg('esp'))
            self.stop('call to %s with no stub (return address 0x%x)' % (name, ra), ok=False)
            return
        handler(self, self._cur)

    def _on_unmapped(self, mu, access, addr, size, value, _):
        kind = {UC_MEM_WRITE_UNMAPPED: 'write', UC_MEM_READ_UNMAPPED: 'read',
                UC_MEM_FETCH_UNMAPPED: 'fetch'}.get(access, 'access %d' % access)
        eip = mu.reg_read(UC_X86_REG_EIP)
        self._cur_stop = ('unmapped %s at 0x%x (eip 0x%x)' % (kind, addr, eip), False)
        return False

    def _on_intr(self, mu, intno, _):
        eip = mu.reg_read(UC_X86_REG_EIP)
        self._cur_stop = ('interrupt %d near eip 0x%x (int3 = MSVC assert with no handler)' % (intno, eip), False)
        mu.emu_stop()

    def _on_heap_write(self, mu, access, addr, size, value, _):
        if self._cur is not None and self.track_writes:
            self._cur.writes.append((mu.reg_read(UC_X86_REG_EIP), addr, size, value & ((1 << (8 * size)) - 1)))

    def _on_image_write(self, mu, access, addr, size, value, _):
        self._image_dirty = True

    track_writes = True

    # ------------------------------------------------------------------ running
    def call(self, addr, args=(), this=None, float_ret=False, stop_at=None, regs=None, max_insns=200000):
        """Call a function. args are pushed right to left: int -> u32, F -> float32, D -> float64.
        this -> ECX (__thiscall). stop_at: {addr: handler(emu, result) or None}; reaching it ends the
        run as a planned stop (handler can read registers into result.captured first)."""
        esp = STACK_TOP - 0x100
        blob = b''
        for a in args:
            if isinstance(a, D):
                blob += struct.pack('<d', a)
            elif isinstance(a, F):
                blob += struct.pack('<f', a)
            else:
                blob += struct.pack('<I', int(a) & 0xffffffff)
        esp -= len(blob)
        self.mu.mem_write(esp, blob)
        esp -= 4
        self.mu.mem_write(esp, struct.pack('<I', self.RET_FLOAT if float_ret else self.RET_ADDR))
        return self._run(addr, esp, this, regs, stop_at, max_insns, float_ret)

    def run_slice(self, start, until, regs=None, stack_words=(), max_insns=100000):
        """Run straight-line code start..until (exclusive) with the given registers, e.g. a piece of a
        constructor. stack_words are pushed first (for code that expects pushed slots)."""
        esp = STACK_TOP - 0x100
        for w in reversed(list(stack_words)):
            esp -= 4
            self.w32(esp, w)
        return self._run(start, esp, None, regs, {until: None}, max_insns, False)

    def _run(self, addr, esp, this, regs, stop_at, max_insns, float_ret):
        r = Result()
        self._cur = r
        self._cur_stop = None
        mu = self.mu
        for k in ('eax', 'ebx', 'edx', 'esi', 'edi'):
            mu.reg_write(REGS[k], 0)
        mu.reg_write(UC_X86_REG_ESP, esp)
        mu.reg_write(UC_X86_REG_EBP, STACK_TOP - 0x80)
        mu.reg_write(UC_X86_REG_ECX, this or 0)
        mu.reg_write(UC_X86_REG_FPSW, 0)
        if regs:
            for k, v in regs.items():
                mu.reg_write(REGS[k], v)
        stop_hooks = []
        for sa, h in (stop_at or {}).items():
            def mk(sa=sa, h=h):
                def _f(m, a, s, _):
                    if self._cur_stop is None:
                        if h:
                            h(self, r)
                        r.stopped_at = sa
                        self._cur_stop = ('stop_at 0x%x' % sa, True)
                        m.emu_stop()
                return _f
            stop_hooks.append(mu.hook_add(UC_HOOK_CODE, mk(), begin=sa, end=sa))
        try:
            mu.emu_start(addr, 0xffffffff, count=max_insns)
        except UcError as e:
            if self._cur_stop is None:
                self._cur_stop = ('unicorn error %s at eip 0x%x' % (e, mu.reg_read(UC_X86_REG_EIP)), False)
        finally:
            for h in stop_hooks:
                mu.hook_del(h)
            self._cur = None
        reason, ok = self._cur_stop or ('instruction limit %d reached at eip 0x%x' % (max_insns, mu.reg_read(UC_X86_REG_EIP)), False)
        if not ok:
            raise EmuStop(reason)
        r.eax = mu.reg_read(UC_X86_REG_EAX)
        if float_ret and reason == 'returned':
            r.st0 = struct.unpack('<d', mu.mem_read(SCRATCH, 8))[0]
            r.fpu_balanced = ((mu.reg_read(UC_X86_REG_FPSW) >> 11) & 7) == 0
        return r
