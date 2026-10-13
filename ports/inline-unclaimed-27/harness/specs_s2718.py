"""specs_s2718.py - unclaimed-27 batch 18 (gap band): FUN_588920 (void, no args; global 0x7003b8 object's vtable slot 0 is a
recording stub, NOT verified) and FUN_589810 (thiscall, one argument, returns this). The callees 0x589600 (thiscall) and 0x634273
(CRT free, cdecl) are HOOKED by address (stubs, NOT verified): each counts its calls and records its arguments."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    rec = c.emu.alloc(0x20, 4)   # +0 0x589600 calls, +4 0x634273 calls, +8 last free pointer, +0xc last free size

    def h589600(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.ret(argbytes=0)

    def h634273(e, r, rec=rec):
        e.w32(rec + 4, (e.r32(rec + 4) + 1) & 0xffffffff)
        e.w32(rec + 8, e.arg32(0))
        e.w32(rec + 0xc, e.arg32(1))
        e.ret(argbytes=0)

    c.emu.hook(0x589600, h589600)
    c.emu.hook(0x634273, h634273)
    return rec


def _f588920(c):
    _hooks(c)
    vt = c.emu.alloc(0x40, 4)
    rec = c.emu.alloc(0x10, 4)
    code = b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little') + b'\xc2\x04\x00'   # records its one argument (the flag 1); ret 4
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(vt, st)
    obj = _rnd(c, 0x100)
    c.emu.w32(obj, vt)
    g = obj if c.rng.random() < 0.7 else 0
    c.emu.w32(0x7003b8, g)
    c.emu.mu.ctl_flush_tb()
    return []


def _f589810(c):
    _hooks(c)
    o = _rnd(c, 0x100)
    return [o, c.rng.getrandbits(32)]


S(0x588920, 'FUN_588920 (GUESS) cdecl-void', 'cdecl', None, ret=None, gen=_f588920,
  note='gap band batch 18; global 0x7003b8 object slot 0 is a stub; 0x589600 0x634273 are hooks (unused here)')
S(0x589810, 'FUN_589810 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f589810,
  note='gap band batch 18; 0x589600 and 0x634273 are hooks (stubs)')
