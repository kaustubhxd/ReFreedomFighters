from pilot import S
from recruits_util import rnd, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x20)
    maximum = r.choice([0, 1, 7, 20, 0x7fffffff])
    value = r.choice([-20, -1, 0, 1, 5, 30, 0x7fffffff])
    e.w32(self + 8, maximum)
    e.w32(self + 4, value & 0xffffffff)
    mode = r.choice([0, 1, 2, 3, 0xffffffff])
    delta = r.choice([-10, -1, 0, 2, 10, 0x7fffffff]) & 0xffffffff
    target = self + 4 if r.random() < 0.9 else self + 8
    assert_ret = r.getrandbits(32) | 1
    e.w32(0x7003b0, pystub(c, 0, ret=assert_ret, pop=0))
    return [self, target, delta, mode]

S(0x4d5370, 'GUESS adjust_bounded_counter_with_operation_mode', 'thiscall', None, ret='eax', gen=gen, note='batch62116')
