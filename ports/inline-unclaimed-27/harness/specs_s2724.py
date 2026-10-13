"""specs_s2724.py - unclaimed-27 batch 24 (gap band): FUN_5896b0 (GUESS, thiscall, void). The callee 0x54f870 is HOOKED (stub, NOT
verified): it records its two arguments and counts calls. The object is 0x2000 bytes; its +0x4a0 block holds begin (+0) and end
(+8), chosen so that (end - begin) >> 2 is 0 in about a third of cases and otherwise a small signed count. SEH not modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f6b0(c):
    rec = c.emu.alloc(0x20, 4)   # +0 call count, +4 begin, +8 size

    def h(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.arg32(0))
        e.w32(rec + 8, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x54f870, h)
    o = _rnd(c, 0x2000)
    blk = c.emu.alloc(0x400, 16)
    k = c.rng.choice([0, 0, 1, 3, -1, -2, 6])
    end = (blk + (k << 2)) & 0xffffffff
    if c.rng.random() < 0.15:
        end = c.rng.getrandbits(32)
    c.emu.w32(o + 0x4a0, blk)
    c.emu.w32(o + 0x4a8, end)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5896b0, 'FUN_5896b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f6b0,
  note='gap band batch 24; 0x54f870 is a hook (stub); SEH frame not modelled')
