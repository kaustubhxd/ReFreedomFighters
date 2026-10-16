from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    local_value = r.getrandbits(32)
    context = obj(c, 0x30, {0x198: pystub(c, 4, this=True, pop=0, nullflag=(1,),
                                           side=lambda emu, k: emu.w32(emu.arg32(1), local_value))})
    resource = obj(c, 0x20, {0x88: pystub(c, 2, this=True, pop=8, nullflag=(0, 1))})
    table = obj(c, 0x200, {0x134: pystub(c, 0, this=True, ret=resource)})
    sys = obj(c, 0x300, {0x190: pystub(c, 0, this=True, ret=context)})
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    self = rnd(c, 0x1a0)
    e.w32(self + 0x188, r.getrandbits(32))
    return [self]

S(0x566f10, 'GUESS resolve_engine_context_and_submit_locals', 'thiscall', None, ret=None, gen=gen, note='batch62131')
