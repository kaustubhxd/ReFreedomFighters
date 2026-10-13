"""specs_s2728.py - unclaimed-27 batch 28 (gap band, SEH-cookie family): FUN_5819a0, FUN_581a10, FUN_581a80 (GUESS, thiscall, no
arguments, returns eax). The global 0x70039c is a fresh object whose +0x9b is an engine object E; E+8 is a sub-object S whose vtable
slot +0x44 (no args) is a STUB returning a pointer P (about two thirds nonzero). The callees 0x581200, 0x5812c0 and 0x581410 are HOOKED
(stubs, NOT verified): each counts calls and records its this. The exe's SEH frame is not reproduced; the port sets esi to the exe's
cookie value (see the batch file). Each function gets its own S()."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _chain(c, hook_addr, rec):
    def h(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.reg('ecx'))
        e.ret(argbytes=0)

    c.emu.hook(hook_addr, h)
    p = _rnd(c, 0x100) if c.rng.random() < 0.67 else 0
    svt = c.emu.alloc(0x100, 4)
    code = b'\xb8' + (p & 0xffffffff).to_bytes(4, 'little') + b'\xc3'   # mov eax, p; ret
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(svt + 0x44, st)
    sub = _rnd(c, 0x100)
    c.emu.w32(sub, svt)
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 8, sub)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, eng)
    c.emu.w32(0x70039c, g)
    c.emu.mu.ctl_flush_tb()
    return _rnd(c, 0x100)


def _gen(hook_addr):
    def f(c):
        rec = c.emu.alloc(0x10, 4)
        return [_chain(c, hook_addr, rec)]
    return f


S(0x5819a0, 'FUN_5819a0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x581200), reg_values=True,
  note='SEH-cookie family batch 28; slot +0x44 stub; 0x581200 hook')
S(0x581a10, 'FUN_581a10 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x5812c0), reg_values=True,
  note='SEH-cookie family batch 28; slot +0x44 stub; 0x5812c0 hook')
S(0x581a80, 'FUN_581a80 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x581410), reg_values=True,
  note='SEH-cookie family batch 28; slot +0x44 stub; 0x581410 hook')
S(0x581af0, 'FUN_581af0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x581530), reg_values=True,
  note='SEH-cookie family batch 29; slot +0x44 stub; 0x581530 hook')
S(0x585780, 'FUN_585780 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x5853f0), reg_values=True,
  note='SEH-cookie family batch 29; slot +0x44 stub; 0x5853f0 hook')
S(0x598e40, 'FUN_598e40 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x598440), reg_values=True,
  note='SEH-cookie family batch 30; slot +0x44 stub; 0x598440 hook')
S(0x59ade0, 'FUN_59ade0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen(0x59aa30), reg_values=True,
  note='SEH-cookie family batch 30; slot +0x44 stub; 0x59aa30 hook')
