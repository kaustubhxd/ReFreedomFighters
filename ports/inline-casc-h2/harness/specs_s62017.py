from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g437ad0(c):
    clear_hooks(c)
    r = c.rng
    self = obj(c, 0x20, {4: pystub(c, 2, this=True, pop=8)}, nslots=2)
    arr = rnd(c, 16)
    stop = r.randrange(5)
    for i in range(4):
        value = r.getrandbits(32)
        if value == 0xffffffff:
            value = 0xfffffffe
        if i == stop:
            value = 0xffffffff
        c.emu.w32(arr + i * 4, value)
    return [self, arr, r.getrandbits(32)]


S(0x437ad0, 'GUESS dispatch item values until sentinel', 'thiscall', None, ret=None, gen=g437ad0, note='batch62017')
