from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    recv = pystub(c, 2, this=True, pop=8, ret=c.rng.getrandbits(32))
    other = obj(c, 4, {0x20: recv})
    self = obj(c, 0x80, {})
    n = c.rng.choice([0, 0, 1, 4, 20, 63])
    name = rnd(c, n + 1)
    if n:
        c.emu.wbytes(name, bytes(c.rng.choice(b'abcdef0123456789') for _ in range(n)))
    c.emu.w8(name + n, 0)
    c.emu.w32(self + 0x61, name)
    return [self, other]

S(0x4689e0, 'GUESS send name to receiver', 'thiscall', None, ret=None, gen=gen, note='batch62003')
