"""specs_s2737.py - unclaimed-27 batch 39: FUN_589600 (GUESS, thiscall, no arguments, void). Hooks (NOT verified): 0x63418c (stdcall, four
args, ret 0x10; records them), 0x54f870 (stdcall, two args, ret 8; records them, counts calls). The object is 0xe00 random bytes; the
two ranges (begin at +0xb55 with end at +0xb5d, and begin at +0x4a0 with end at +0x4a8) are chosen so the counts are 0 in about a third
of cases. The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f9600(c):
    rec = c.emu.alloc(0x40, 4)   # +0 0x63418c calls, +4..+0x10 its args; +0x14 0x54f870 calls, +0x18/+0x1c its args
    def h63(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        for i in range(4):
            e.w32(rec + 4 + 4 * i, e.arg32(i))
        e.ret(argbytes=16)

    def h54(e, r, rec=rec):
        e.w32(rec + 0x14, (e.r32(rec + 0x14) + 1) & 0xffffffff)
        e.w32(rec + 0x18, e.arg32(0))
        e.w32(rec + 0x1c, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x63418c, h63)
    c.emu.hook(0x54f870, h54)
    o = _rnd(c, 0xe00)
    blk1 = c.emu.alloc(0x2000, 64)
    k1 = c.rng.choice([0, 0, 1, 2, -1])
    end1 = (blk1 + (k1 << 6)) & 0xffffffff
    blk2 = c.emu.alloc(0x400, 16)
    k2 = c.rng.choice([0, 0, 1, 3, -2, 5])
    end2 = (blk2 + (k2 << 2)) & 0xffffffff
    c.emu.w32(o + 0xb55, blk1)
    c.emu.w32(o + 0xb5d, end1)
    c.emu.w32(o + 0x4a0, blk2)
    c.emu.w32(o + 0x4a8, end2)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x589600, 'FUN_589600 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f9600, reg_values=True,
  note='unclaimed-27 batch 39; 0x63418c and 0x54f870 are hooks; SEH frame not reproduced')
