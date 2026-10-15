from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    raw = r.choice([-0x80000000, -0x2711, -0x2710, -1, 0, 1, 0x2710, 0x2711, 0x7fffffff])
    slot_result = r.choice([-7, -1, 0, 1, r.getrandbits(31)])
    hook_rec(c, 0x54f2b0, 0, this=True, pop=0, ret=r.getrandbits(32),
             side=lambda emu, k: emu.calllog.append(('negative-result', emu.reg('ecx'))))
    callback = pystub(c, 2, this=True, pop=8, ret=slot_result,
                      side=lambda emu, k: emu.calllog.append(('callback', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    objptr = obj(c, 0x20, {0x40: callback}, nslots=0x41 // 4)
    self = rnd(c, 0x6400)
    e.w32(self + 0x63ec, objptr)
    arg = rnd(c, 0x80)
    e.w32(arg + 0x70, raw)
    return [self, arg]


S(0x54c750, 'GUESS clamp signed input and dispatch callback', 'thiscall', None,
  ret='eax', gen=gen, note='batch62053')
