"""specs_s2721.py - unclaimed-27 batch 21 (gap band): FUN_59a6e0 (GUESS, thiscall, ret 4). Its callees are HOOKED (stubs, NOT
verified): 0x4e5e60 (thiscall, no args) returns a chosen eax per case; 0x58a660 (thiscall, two args) records its this and both
arguments. The global at 0x7003b8 is a fresh 0x400-byte object. The object is 0x2400 bytes (the store is at +0x22db)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f6e0(c):
    rec = c.emu.alloc(0x40, 4)   # +0 0x58a660 calls, +4 its this, +8 arg0, +0xc arg1, +0x10 0x4e5e60 calls
    seq = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    idx = [0]

    def h4e(e, r, rec=rec, seq=seq, idx=idx):
        e.w32(rec + 0x10, (e.r32(rec + 0x10) + 1) & 0xffffffff)
        v = seq[idx[0] % 2]
        idx[0] += 1
        e.ret(eax=v, argbytes=0)

    def h58(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.reg('ecx'))
        e.w32(rec + 8, e.arg32(0))
        e.w32(rec + 0xc, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x4e5e60, h4e)
    c.emu.hook(0x58a660, h58)
    g = _rnd(c, 0x400)
    c.emu.w32(0x7003b8, g)
    o = _rnd(c, 0x2400)
    arg = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, arg]


S(0x59a6e0, 'FUN_59a6e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f6e0,
  note='gap band batch 21; 0x4e5e60 and 0x58a660 are hooks (stubs)')
