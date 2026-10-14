"""specs_s34029.py - cascade tier E, batch 34029: 0x4d6250. Capacity [this] includes values whose doubled 0x2a-byte size overflows 32 bits; hooked 0x41e290 returns a fresh block or 0 (a fifth),
0x634d22 / 0x41e2c0 are cdecl recorders, the logger object at 0x700390 is set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, ret=(0 if r.random() < 0.2 else rnd(c, 0x40)), pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x41e2c0, 1, pop=0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = rnd(c, 0x20)
    cap = r.choice([0, 1, 5, 0x30, 0x1000000, 0x1861862, 0x30c30c3, 0x3000000, 0x4000000, 0x80000000, r.getrandbits(32), r.randint(0, 100)])
    c.emu.w32(me, cap)
    return [me]


S(0x4d6250, 'GUESS grow array of 42-byte records by doubling', 'thiscall', None, ret=None, gen=_g, note='batch34029')
