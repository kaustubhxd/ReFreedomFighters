from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    engine = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    sys = rnd(c, 0x120)
    e.w32(0x70039c, sys)
    e.w32(sys + 0x9b, engine)
    first = r.choice([0, 0, 1, 2])
    accepted = r.getrandbits(32)
    vtable = {
        0x3f0: pystub(c, 0, this=True, ret=first),
        0x514: pystub(c, 0, this=True, ret=accepted),
        0x45c: pystub(c, 3, this=True, pop=12, ret=r.getrandbits(32)),
    }
    # Embed slots in the self object's vtable.
    self = obj(c, 0x40, vtable)
    return [self, r.getrandbits(32)]

S(0x473240, 'GUESS dispatch engine lookup when target is not ready', 'thiscall', None, ret=None, gen=gen, note='batch62114')
