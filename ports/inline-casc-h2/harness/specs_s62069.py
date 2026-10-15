from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x4614d0, 3, this=True, pop=12,
             side=lambda emu, k: emu.calllog.append(('helper', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))
    nxt = rnd(c, 0x20)
    first = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=nxt)})
    fallback = r.getrandbits(32)
    action_result = rnd(c, 0x20)
    action = obj(c, 0x240, {0x228: pystub(c, 5, this=True, pop=20, ret=action_result,
              side=lambda emu, k: emu.calllog.append(('action', emu.reg('ecx'), *(emu.arg32(i) for i in range(5)))))}, nslots=0x229 // 4)
    self = obj(c, 0x30, {0xc: pystub(c, 0, this=True, ret=fallback)}, nslots=0x10 // 4)
    e.w32(self + 0xc, first)
    e.w32(self + 8, action)
    e.w32(self + 0x10, r.choice([0, r.getrandbits(32)]))
    return [self]


S(0x486480, 'GUESS resolve resource and submit positioned action', 'thiscall', None,
  ret='al', gen=gen, note='batch62069')
