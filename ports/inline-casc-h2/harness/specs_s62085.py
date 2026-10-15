from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x513190, 0, this=True, pop=0,
        side=lambda emu, k: emu.calllog.append(('init', emu.reg('ecx'))))
    vals = [r.getrandbits(32) for _ in range(3)]
    n = [0]
    def lookup(emu, k):
        i = n[0]; n[0] += 1
        emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))
    resource = obj(c, 0x70, {0x60: pystub(c, 2, this=True, pop=8, ret=lambda emu, k: vals[k], side=lookup)})
    engine = rnd(c, 0x1b00)
    e.w32(engine + 0x1a9f, r.choice([0, 0, resource]))
    e.w32(0x70039c, engine)
    self = rnd(c, 0x2708)
    for off in (0x12f, 0x26ee, 0x26f2, 0x26f6, 0x26fa, 0x26fe):
        e.w32(self + off, r.getrandbits(32))
    return [self]


S(0x520d90, 'GUESS reset and resolve three resource labels', 'thiscall', None,
  ret=None, gen=gen, note='batch62085')
