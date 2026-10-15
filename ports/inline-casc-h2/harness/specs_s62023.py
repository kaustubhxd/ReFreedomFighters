from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g537e00(c):
    clear_hooks(c)
    r = c.rng
    first = rnd(c, 0x20) if r.random() < 0.75 else 0
    result = rnd(c, 0x20) if r.random() < 0.75 else 0
    slots = {
        0x40: pystub(c, 1, this=True, pop=4, ret=first),
        0x1dc: pystub(c, 1, this=True, pop=4, ret=result),
    }
    self = obj(c, 0x20, slots, nslots=0x1dd // 4 + 1)
    if result:
        c.emu.w8(result + 8, r.getrandbits(8))
    return [self, r.getrandbits(32)]


S(0x537e00, 'GUESS query object flags through nested slots', 'thiscall', None, ret='al', gen=g537e00, note='batch62023')
