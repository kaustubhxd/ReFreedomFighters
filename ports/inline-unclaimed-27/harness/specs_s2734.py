"""specs_s2734.py - unclaimed-27 batch 36: FUN_5888a0 (GUESS, cdecl-void, no arguments). Hooks (NOT verified): 0x41e290 (cdecl, one
argument; returns a chosen pointer or 0, records its argument) and 0x588a00 (thiscall; returns a chosen value, records its this).
The global 0x7003b8 starts at a random value. The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f88a0(c):
    rec = c.emu.alloc(0x20, 4)   # +0 0x41e290 calls, +4 its argument, +8 0x588a00 calls, +0xc its this
    blk = _rnd(c, 0x100) if c.rng.random() < 0.7 else 0
    val = c.rng.getrandbits(32)

    def h41(e, r, blk=blk, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.arg32(0))
        e.ret(eax=blk, argbytes=0)

    def h58(e, r, val=val, rec=rec):
        e.w32(rec + 8, (e.r32(rec + 8) + 1) & 0xffffffff)
        e.w32(rec + 0xc, e.reg('ecx'))
        e.ret(eax=val, argbytes=0)

    c.emu.hook(0x41e290, h41)
    c.emu.hook(0x588a00, h58)
    c.emu.w32(0x7003b8, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return []


S(0x5888a0, 'FUN_5888a0 (GUESS) cdecl-void', 'cdecl', None, ret=None, gen=_f88a0, reg_values=True,
  note='unclaimed-27 batch 36; 0x41e290 and 0x588a00 are hooks (stubs); SEH frame not reproduced')
