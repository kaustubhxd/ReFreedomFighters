from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x5f5620, 1, this=True, pop=4,
             side=lambda emu, k: emu.calllog.append(('dispatch', emu.reg('ecx'), emu.arg32(0))))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32)))
    count = r.choice([0, 1, 3, 8])
    arr = rnd(c, max(4, count * 4))
    vals = [r.getrandbits(32) for _ in range(count)]
    for i, value in enumerate(vals):
        e.w32(arr + i * 4, value)
    state = rnd(c, 0x110)
    e.w32(state + 0x104, count)
    e.w32(state + 0x108, arr)
    self = rnd(c, 0x100)
    e.w32(self + 0x96, state)
    choices = [0, 1, max(0, count - 1), count, count + 1, 0x10001, 0xffffffff]
    if count:
        choices.extend(0x10000 | i for i in range(count))
    index = r.choice(choices)
    return [self, index]


S(0x5f5680, 'GUESS dispatch indexed value or assert fallback', 'thiscall', None,
  ret='eax', gen=gen, note='batch62042')
