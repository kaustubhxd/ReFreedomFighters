from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    final = r.getrandbits(32)
    end_cb = pystub(c, 1, this=True, pop=4, ret=final)
    self = obj(c, 0x1a0, {0xd0: end_cb})
    values = [r.getrandbits(32) for _ in range(3)]
    targets = []
    for _ in range(3):
        cb = pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32))
        targets.append(obj(c, 0x20, {0x36c: cb}))
    for i, (value, target) in enumerate(zip(values, targets)):
        e.w32(self + 0x18c + 4*i, value)
        e.w32(self + 0x180 + 4*i, target)
    hook_rec(c, 0x572240, 2, this=True, pop=8, ret=0)
    return [self]


S(0x571c40, 'GUESS refresh three indexed child objects', 'thiscall', None,
  ret='eax', gen=gen, note='batch62093')
