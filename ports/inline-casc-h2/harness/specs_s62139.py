from pilot import S
from recruits_util import clear_hooks

def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    self = e.alloc(0x640, 4)
    e.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x640)))
    for off in range(0x5f8, 0x628, 4):
        child = e.alloc(0x60, 4)
        e.wbytes(child, bytes(r.getrandbits(8) for _ in range(0x60)))
        target = e.alloc(4, 4)
        e.w32(child + 0x3a, target)
        e.w32(self + off, child)
    return [self]

S(0x5a58a0, 'GUESS clear_twelve_embedded_states', 'thiscall', None, ret=None, gen=gen, note='batch62139')
