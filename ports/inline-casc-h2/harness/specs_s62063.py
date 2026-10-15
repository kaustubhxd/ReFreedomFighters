from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    returns = [r.getrandbits(32) for _ in range(4)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0,
             ret=lambda emu, k: returns[min(k, 3)],
             side=lambda emu, k: emu.calllog.append(('parse', emu.reg('ecx'), k)))
    code = r.choice([0xff, 0x0b, 0x4b, 0x8b, 0x00, 0x10, 0x3f])
    data = rnd(c, 8)
    e.w8(data, code)
    parser = rnd(c, 0x20)
    e.w32(parser, data)
    self = rnd(c, 0x60)
    return [self, parser]


S(0x548ef0, 'GUESS parse record fields and conditionally parse a tag', 'thiscall', None,
  ret='eax', gen=gen, note='batch62063')
