from pilot import S
from recruits_util import obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    tail = pystub(c, 0, this=True, pop=0, ret=c.rng.getrandbits(32))
    self = obj(c, 0x80, {0x0c: tail})
    returned_id = c.rng.choice([0, 0, c.rng.getrandbits(32)])
    lazy = pystub(c, 1, this=True, pop=4, ret=returned_id)
    sub = obj(c, 0x880, {0x100: lazy})
    c.emu.w32(sub + 0x852, c.rng.getrandbits(32))
    c.emu.w32(sub + 0x856, c.rng.getrandbits(32))
    c.emu.w32(sub + 0x85a, c.rng.choice([0, 0, c.rng.getrandbits(32)]))
    c.emu.w32(self + 0x5f, sub)
    hook_rec(c, 0x591ae0, 0, this=True, pop=0, ret=c.rng.getrandbits(32))
    return [self]

S(0x5b3e10, 'GUESS initialize subobject and dispatch', 'thiscall', None, ret='eax', gen=gen, note='batch62008')
