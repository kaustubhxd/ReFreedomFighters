"""Tier H cascade spec for 0x4045a0: Vorbis seed_chase."""
from pilot import S

def gen4045a0(c):
    n = c.rng.choice([0, 1, 2, 3, 8, 20, 40])
    lp = c.rng.randint(1, 8)
    sg = lambda c: c.rng.choice([-9999.0, c.fv(-100, 100), c.rng.uniform(-100, 0), float(c.rng.randint(-3, 3)), float('nan')])
    return [c.fbuf(n, sg), lp, n]

S(0x4045a0, 'GUESS vorbis seed_chase', 'cdecl', None, gen=gen4045a0)
