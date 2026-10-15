from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32)))
    self = rnd(c, 0x830)
    starts = [i * 100 for i in range(8)]
    widths = [r.randrange(1, 50) for _ in range(8)]
    for i, (start, width) in enumerate(zip(starts, widths)):
        e.w32(self + 0x800 + i * 4, start)
        e.w32(self + 0x804 + i * 4, start + width)
    pick = r.randrange(10)
    if pick < 8:
        i = pick
        value = r.randrange(starts[i] + (1 if i else 0), starts[i] + widths[i] + 1)
    elif pick == 8:
        value = -1
    else:
        value = 900
    return [self, value & 0xffffffff]


S(0x4a0e40, 'GUESS find value in one of eight intervals', 'thiscall', None,
  ret='eax', gen=gen, note='batch62076')
