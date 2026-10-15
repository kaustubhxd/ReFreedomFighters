from pilot import S
from recruits_util import clear_hooks, hook_rec, reftab


def gen(c):
    clear_hooks(c)
    r = c.rng
    items = [r.getrandbits(32) or 1 for _ in range(r.choice([0, 1, 2, 5, 8]))]
    table = reftab(c, items)
    hook_rec(c, 0x634273, 2, pop=0)
    return [table]


S(0x4cdcc0, 'GUESS release all table entries and mark object', 'thiscall', None,
  ret=None, gen=gen, note='batch62107')
