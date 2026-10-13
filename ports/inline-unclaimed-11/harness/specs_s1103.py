"""specs_s1103.py - unclaimed-11 batch 3 (docs/20-unclaimed-11.md): ZPlayer::AdjustMovePoolSpeed(const float *p, float *v,
float t) at 0x4812a0, ret 0xc, thiscall. The object is 0x800 random bytes with a count at +0x4f1 (0 to 4) and that many
element pointers at +0x4e1 (stride 4). Each element is a 0x80-byte random buffer whose position is at +8 (3 floats) and
whose float at +0x38 is the radius-like value. The three callees 0x43e920, 0x443ef0 and 0x4e0d00 are original code (ext),
so the port calls the exe's own helpers. Floats come from c.fv, so the edge values (zero, NaN, inf) are included."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fvec(c, lo=-10.0, hi=10.0):
    a = c.emu.alloc(16, 16)
    c.emu.wbytes(a, bytes(16))
    vals = [c.fv(lo, hi) for _ in range(3)]
    for k in range(3):
        c.emu.wf32(a + 4 * k, vals[k])
    return a, vals


def _adjust(c):
    # About a third of the cases set v.x = 0 and the element's x equal to p.x, so the horizontal test sees F3.x == 0
    # exactly (the x == 0 and z == 0 branch in the PC code needs both to be zero).
    o = _rnd(c, 0x800)
    n = c.rng.randint(0, 4)
    c.emu.w32(o + 0x4f1, n)
    p, pv = _fvec(c)
    v, vv = _fvec(c)
    zero_x = c.rng.random() < 0.35
    if zero_x:
        c.emu.wf32(v, 0.0)
    for i in range(n):
        e = _rnd(c, 0x80)
        for k in range(3):
            c.emu.wf32(e + 8 + 4 * k, c.fv(-10.0, 10.0))
        if zero_x and c.rng.random() < 0.8:
            c.emu.wf32(e + 8, pv[0])
        c.emu.wf32(e + 0x38, c.fv(-30.0, 30.0))
        c.emu.w32(o + 0x4e1 + 4 * i, e)
    t = F(c.fv(0.05, 4.0, edge=0.05))
    return [o, p, v, t]


S(0x4812a0, 'ZPlayer::AdjustMovePoolSpeed (unknown) thiscall', 'thiscall', None, ret=None, gen=_adjust,
  note='unclaimed-11 batch 3; callees 43e920/443ef0/4e0d00 original (ext)')
