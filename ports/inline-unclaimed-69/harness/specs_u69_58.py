"""specs_u69_58.py - area 69, group 58 (slice 8): 0x63ef00, a ring-buffer push. The object is 0x8300 bytes; the write and read pointers at
+0x268 and +0x26c point into the ring (+0x270 .. +0x8270), so the stores stay in memory. 0x63cc50 is a GUESS stub: it logs its args
(small values) and pops 8 (thiscall, two stack args, ret 8 assumed)."""
from pilot import S
from ckit import rnd


def _leave(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x8300)
    ring0 = o + 0x268 + 8
    k = r.random()
    if k < 0.15:
        # the write pointer wraps: the slot before the end is written, then the pointer goes back to the start
        w = ring0 + 4 * 0x1fff
        rd = ring0 + 4 * r.randrange(0, 0x2000)
    elif k < 0.3:
        # occupancy exactly 0x800 with the write pointer behind the read pointer: v = 0x2000 - ((r - w') >> 2) = 0x800
        a = r.randrange(0, 0x800)
        w = ring0 + 4 * a
        rd = ring0 + 4 * (a + 1 + 0x1800)
    else:
        w = ring0 + 4 * r.randrange(0, 0x2000)
        rd = ring0 + 4 * r.randrange(0, 0x2000)
    e.w32(o + 0x268, w)
    e.w32(o + 0x26c, rd)
    g = rnd(c, 0x100)
    e.w32(0x70039c, g)
    e.w32(g + 0x3c, r.choice([1, 2, 0x10, 0x800, 0x801, 0x2000, r.randrange(1, 0x2100)]))
    res = rnd(c, 0x10)
    e.hook(0x63cc50, lambda e, res_: (e.calllog.append(('t63cc50', e.arg32(0), e.arg32(1))), e.ret(argbytes=8)))
    return [o, res]


S(0x63ef00, 'leave63ef00 (ZDrawBase::Leave, thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_leave,
  note='u69 group 58; callee 0x63cc50 is a GUESS stub (other area, ret 8 assumed)')
