"""specs_s2727.py - unclaimed-27 batch 27 (gap band): FUN_59a9b0 (GUESS, thiscall, one argument, ret 4). Its callees are HOOKED
(stubs, NOT verified): 0x4ffea0 (thiscall, three arguments) returns a freshly allocated block of 4*n+16 bytes and records its
arguments; 0x54f870 (stdcall, two arguments) records its arguments. The object's begin, cap end and end are chosen so that the
count is below n in about two thirds of cases."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f9b0(c):
    rec = c.emu.alloc(0x40, 4)   # +0 0x4ffea0 calls, +4..+0xc its args, +0x10 0x54f870 calls, +0x14, +0x18 its args

    def h4f(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        n = e.arg32(0)
        e.w32(rec + 4, e.reg('ecx'))
        e.w32(rec + 8, n)
        e.w32(rec + 0xc, e.arg32(1))
        e.w32(rec + 0x1c, e.arg32(2))
        blk = e.alloc(min(n, 0x1000) * 4 + 16, 16)
        e.ret(eax=blk, argbytes=12)

    def h54(e, r, rec=rec):
        e.w32(rec + 0x10, (e.r32(rec + 0x10) + 1) & 0xffffffff)
        e.w32(rec + 0x14, e.arg32(0))
        e.w32(rec + 0x18, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x4ffea0, h4f)
    c.emu.hook(0x54f870, h54)
    o = _rnd(c, 0x800)
    begin = c.emu.alloc(0x400, 16)
    cnt = c.rng.choice([0, 1, 2, 4, 6])
    c.emu.w32(o + 0, begin)
    c.emu.w32(o + 4, begin + 4 * (cnt + c.rng.randint(0, 3)))
    c.emu.w32(o + 8, begin + 4 * cnt)
    c.emu.mu.ctl_flush_tb()
    n = c.rng.choice([0, 1, 3, 5, 8, 12]) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [o, n & 0xffffffff]


S(0x59a9b0, 'FUN_59a9b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f9b0,
  note='gap band batch 27; 0x4ffea0 and 0x54f870 are hooks (stubs)')
