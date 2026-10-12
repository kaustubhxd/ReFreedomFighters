"""specs_s608.py - damage batch 608: hit-anim choice (actor table lookup, Hero clip names)."""
from pilot import S
from wkit import rnd


def _coll(c):
    a = rnd(c, 8)
    c.emu.w8(a, c.rng.choice(list(range(10)) * 2 + [10, 0xff]))
    c.emu.w8(a + 1, c.rng.choice((0, 1, 0x80)))
    return a


def _actor(c):
    r = c.rng
    n = 4
    tab = rnd(c, 64 * n)
    for i in range(16 * n):
        if r.random() < 0.25:
            c.emu.w32(tab + 4 * i, 0)
    g = rnd(c, 0xc00)
    c.emu.w32(g + 0xb55, tab)
    c.emu.w32(0x7003b8, g)
    a = rnd(c, 0xa00)
    c.emu.w32(a + 0x932, r.randrange(n))
    return [a, _coll(c)]


S(0x59fd30, 'ZFFActor::GetHitAimHeaderFromCollision', 'thiscall', ret='eax', gen=_actor)
S(0x483980, 'ZPlayer::GetAnimNameFromCollision', 'thiscall', ret='eax',
  gen=lambda c: [rnd(c, 0x40), _coll(c), c.rng.getrandbits(32), c.rng.getrandbits(32)])
