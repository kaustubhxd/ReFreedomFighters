from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x1700)
    e.w32(self + 4, r.getrandbits(32))
    sys = obj(c, 0x40, {0x20: pystub(c, 2, this=True, pop=8)})
    e.w32(0x700390, sys)
    message = obj(c, 0x40, {0x2c: pystub(c, 3, this=True, pop=0)})
    sysfn = e.r32(e.r32(sys) + 0x20)
    # Engine callback's returned message object is shared across its original/port executions.
    # Install the recorder's result directly as the engine slot result.
    e.w32(e.r32(sys) + 0x20, pystub(c, 2, this=True, pop=8, ret=message))
    val = r.choice([0, 0, 1, r.getrandbits(32) | 1])
    def store_out(emu, k):
        emu.w32(emu.arg32(0), val)
    hook_rec(c, 0x517630, 1, this=True, pop=4)
    hook_rec(c, 0x4e12e0, 2, this=True, pop=8, side=store_out)
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0)
    return [self, rnd(c, 0x20)]

S(0x51f710, 'GUESS configure_resource_then_optional_log', 'thiscall', None, ret=None, gen=gen, note='batch62126')
