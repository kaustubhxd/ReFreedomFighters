from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, stub_seq


def gen(c):
    clear_hooks(c)
    r = c.rng
    # Exercise all four combinations of the two AL-controlled helper calls.
    first, second = r.choice([(0, 0), (0, 1), (1, 0), (1, 1)])
    table = obj(c, 0x40, {0x2c: stub_seq(c, 2, [first, second])})
    system = sysobj(c)
    c.emu.w32(system + 0x1907, table)
    hook_rec(c, 0x5f04a0, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('first-helper', emu.reg('ecx'))))
    hook_rec(c, 0x5f0540, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('second-helper', emu.reg('ecx'))))
    self = rnd(c, 0x20)
    a, b = r.getrandbits(32), r.getrandbits(32)
    c.emu.w32(self + 0x0c, a)
    c.emu.w32(self + 0x10, b)
    return [self]


S(0x5f05e0, 'GUESS dispatch two conditionally selected helpers', 'thiscall', None,
  ret=None, gen=gen, note='batch62041')
