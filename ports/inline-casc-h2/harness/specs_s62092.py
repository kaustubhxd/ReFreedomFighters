from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x70)
    flags = r.choice([0, 4, 0x40, 0x44, 8, 0x48])
    e.w32(self + 4, flags)
    initial = [r.getrandbits(32) for _ in range(4)]
    for off, value in zip((0x4c, 0x50, 0x54, 0x58), initial):
        e.w32(self + off, value)
    source = obj(c, 0x20, {})
    produced = [r.getrandbits(32) for _ in range(4)]
    calls = []
    def side(emu, k):
        out = emu.arg32(0)
        calls.append(out)
        emu.w32(out, produced[len(calls)-1])
    source = obj(c, 0x20, {0x40: pystub(c, 1, this=True, pop=4, side=side)})
    return [self, source]


S(0x549100, 'GUESS clear flag and load four fields', 'thiscall', None,
  ret='al', gen=gen, note='batch62092')
