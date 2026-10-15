"""specs_s66044.py - cascade s4 batch 66044: 0x4062e0 (free the members of a record and clear it)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4062e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d52, 1, pop=0)
    box = {'p': 0, 'alt': 0, 'swap': r.random() < 0.5}

    def side(em, k):
        if box['swap'] and k == 0:
            em.w32(box['p'] + 0x78, box['alt'])
    hook_rec(c, 0x410b90, 1, pop=0, side=side)
    if r.random() < 0.08:
        return [0]
    p = e.alloc(0x90, 8)
    box['p'] = p
    box['alt'] = e.alloc(0x100, 8)
    e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x90)))
    for off in (0, 4, 0x14, 0x30, 0x34, 0x38, 0x7c):
        e.w32(p + off, 0 if r.random() < 0.3 else e.alloc(0x10, 8))
    e.w32(p + 0x78, 0 if r.random() < 0.25 else e.alloc(0x100, 8))
    e.w32(p + 8, r.choice([0, 1, 3, 0xffffffff, 2, 5]))
    return [p]


S(0x4062e0, 'GUESS free the members of a record and clear it', 'cdecl', None, ret=None, gen=_g4062e0, note='batch66044')
