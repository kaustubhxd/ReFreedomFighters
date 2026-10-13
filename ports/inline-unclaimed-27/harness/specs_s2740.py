"""specs_s2740.py - unclaimed-27 batch 42 (slice 6): 0x64c4a0 (stdcall, one argument), 0x64ede0 (thiscall, one stack argument), 0x4cb0e0
(thiscall, no arguments). Hooks (NOT verified): 0x6352f0 (stdcall, one argument; writes a chosen dword to *arg, records the value at
its pointer, not the pointer); 0x4cb030 (thiscall, one argument; records ecx and the value at its pointer)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f0(c):
    return [c.rng.getrandbits(32)]


def _f1(c):
    o = _rnd(c, 0x40)
    out = _rnd(c, 0x10)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0xc, 0)
    c.emu.mu.ctl_flush_tb()
    return [o, out]


def _f2(c):
    rec = c.emu.alloc(0x20, 4)   # +0 0x6352f0 calls, +4 the value at its pointer on entry, +8 0x4cb030 calls, +0xc ecx, +0x10 the value at its pointer
    chosen = c.rng.getrandbits(32)

    def h6(e, r, rec=rec, chosen=chosen):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        p = e.arg32(0)
        e.w32(rec + 4, e.r32(p))
        e.w32(p, chosen)
        e.ret(argbytes=4)

    def h4c(e, r, rec=rec):
        e.w32(rec + 8, (e.r32(rec + 8) + 1) & 0xffffffff)
        e.w32(rec + 0xc, e.reg('ecx'))
        p = e.arg32(0)
        e.w32(rec + 0x10, e.r32(p))
        e.ret(argbytes=4)

    c.emu.hook(0x6352f0, h6)
    c.emu.hook(0x4cb030, h4c)
    o = _rnd(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x64c4a0, 'GUESS page base (stdcall)', 'stdcall', None, ret='eax', gen=_f0, reg_values=True,
  note='slice 6 batch 42')
S(0x64ede0, 'GUESS range out (thiscall)', 'thiscall', None, ret=None, gen=_f1, reg_values=True,
  note='slice 6 batch 42')
S(0x4cb0e0, 'GUESS call pair (thiscall)', 'thiscall', None, ret=None, gen=_f2, reg_values=True,
  note='slice 6 batch 42; 0x6352f0 and 0x4cb030 are hooks (stubs)')
