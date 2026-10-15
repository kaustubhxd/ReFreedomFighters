from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g584680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    value = r.getrandbits(32)

    def set_out(emu, call_no):
        emu.w32(emu.arg32(0), value)

    hook_rec(c, 0x6352f0, 1, this=True, pop=4, deref={0: 1}, side=set_out)
    hook_rec(c, 0x584b40, 1, this=True, pop=4, deref={0: 1})
    self = rnd(c, 0x70)
    owner = obj(c, 0x20, {0x40: pystub(c, 1, this=True, pop=4, deref={0: 1})})
    e.w32(self + 4, r.getrandbits(32) | 0x40)
    e.w32(self + 0x5e, r.getrandbits(32))
    return [self, owner]


S(0x584680, 'GUESS decode record and notify owner', 'thiscall', None, ret='al', gen=g584680, note='batch62014')
