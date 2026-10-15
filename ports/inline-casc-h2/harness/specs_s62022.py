from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g51cfb0(c):
    clear_hooks(c)
    r = c.rng
    accepted = r.choice([0, 1])
    slot = pystub(c, 1, this=True, pop=4, ret=accepted)
    self = obj(c, 0x5b0, {0x310: slot}, nslots=0x310 // 4 + 1)
    c.emu.w32(self + 0x3fd, r.getrandbits(32))
    hook_rec(c, 0x514480, 1, this=True, pop=4)
    return [self, r.choice([0, 0, 1, 2, 0xffffffff, r.getrandbits(32)])]


S(0x51cfb0, 'GUESS validate and store selected value', 'thiscall', None, ret=None, gen=g51cfb0, note='batch62022')
