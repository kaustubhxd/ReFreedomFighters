from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    state = r.choice([0, 1, 2, 1, 0xff])
    value = r.choice([-100000, -100, -1, 0, 1, 37, 100, 100000])
    divisor = r.choice([-17, -3, -1, 1, 2, 7, 19])
    if state == 1 and value == -2147483648 and divisor == -1:
        value = 0
    self = rnd(c, 0x10)
    e.w32(self, value & 0xffffffff)
    e.w8(self + 4, state)
    nested = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0, ret=r.getrandbits(32))})
    global_obj = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=nested)})
    e.w32(0x700390, global_obj)
    def assert_hook(emu, res):
        emu.calllog.append(('assert',))
        emu.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', assert_hook))
    divisor_ptr = rnd(c, 4)
    e.w32(divisor_ptr, divisor & 0xffffffff)
    return [self, divisor_ptr]


S(0x5f40b0, 'GUESS divide or assert unexpected state', 'thiscall', None,
  ret='eax', gen=gen, note='batch62095')
