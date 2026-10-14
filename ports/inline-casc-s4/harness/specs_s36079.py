"""specs_s36079.py - cascade s4 batch 36079: 0x5fd170 (release every entry of a pointer array)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, stub_memmove


def _g5fd170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)
    hook_rec(c, 0x5f3b00, 0, this=True)
    hook_rec(c, 0x5fb660, 0, this=True)
    hook_rec(c, 0x5fd2a0, 1, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    lg = obj(c, 0x40, {0x24: pystub(c, 1, this=True)})
    e.w32(0x724270, lg)
    n = r.choice([0, 1, 1, 2, 3, 4, 6])
    pool = [0, rnd(c, 8), rnd(c, 8), rnd(c, 8)]
    arr = e.alloc(4 * 8 + 8, 4)
    vals = [r.choice(pool) for _ in range(n)]
    for i, v in enumerate(vals):
        e.w32(arr + 4 * i, v)
    b = rnd(c, 0x30)
    e.w32(b + 0x18, arr)
    e.w32(b + 0x20, n)
    e.w32(b + 4, rnd(c, 8))
    return [b]


S(0x5fd170, 'GUESS release every entry of a pointer array', 'thiscall', None, ret=None, gen=_g5fd170, note='batch36079')
