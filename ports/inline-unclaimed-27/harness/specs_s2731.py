"""specs_s2731.py - unclaimed-27 batch 33: FUN_589840 (GUESS, thiscall, one argument, ret 4, returns this). Callees HOOKED (stubs,
NOT verified): 0x54f870 (stdcall, two args) and 0x634273 (cdecl, two args, the caller cleans). Each records its arguments and counts
its calls. The object is 0x800 random bytes; the block at +0x4a0 has begin and end chosen so that (end - begin) >> 2 is 0 in about a
third of cases. The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f9840(c):
    rec = c.emu.alloc(0x20, 4)   # +0 0x54f870 calls, +4 begin, +8 size; +0xc 0x634273 calls, +0x10 its pointer, +0x14 its size

    def h54(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.arg32(0))
        e.w32(rec + 8, e.arg32(1))
        e.ret(argbytes=8)

    def h63(e, r, rec=rec):
        e.w32(rec + 0xc, (e.r32(rec + 0xc) + 1) & 0xffffffff)
        e.w32(rec + 0x10, e.arg32(0))
        e.w32(rec + 0x14, e.arg32(1))
        e.ret(argbytes=0)

    c.emu.hook(0x54f870, h54)
    c.emu.hook(0x634273, h63)
    o = _rnd(c, 0x800)
    blk = c.emu.alloc(0x400, 16)
    k = c.rng.choice([0, 0, 1, 2, -1, -3, 5])
    end = (blk + (k << 2)) & 0xffffffff
    if c.rng.random() < 0.15:
        end = c.rng.getrandbits(32)
    c.emu.w32(o + 0x4a0, blk)
    c.emu.w32(o + 0x4a8, end)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x589840, 'FUN_589840 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f9840, reg_values=True,
  note='unclaimed-27 batch 33; 0x54f870 and 0x634273 are hooks (stubs); SEH frame not reproduced')
