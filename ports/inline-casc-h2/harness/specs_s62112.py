from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    ret = r.getrandbits(32)
    log_obj = obj(c, 0x30, {0x2c: pystub(c, 3, pop=0)})
    logger = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=log_obj)})
    e.w32(0x700390, logger)
    e.w32(0x7003b0, pystub(c, 0, ret=ret, pop=0))
    self = rnd(c, 0x20)
    mode = r.choice([0, 1, 2, 3, 255])
    e.w8(self + 4, mode)
    e.w32(self, r.getrandbits(32))
    value = rnd(c, 4)
    e.w32(value, r.getrandbits(32))
    return [self, value]

S(0x5f3d40, 'GUESS assign_add_or_assert_on_invalid_mode', 'thiscall', None, ret=None, gen=gen, note='batch62112')
