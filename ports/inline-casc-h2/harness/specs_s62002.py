from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    gate = pystub(c, 2, this=True, pop=8, ret=c.rng.choice([0, 0, 1, 0x100]))
    forward = pystub(c, 2, this=True, pop=8, ret=c.rng.getrandbits(32))
    self = obj(c, 4, {0x22c: forward, 0x23c: gate})
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x461210, 'GUESS gate and dispatch two arguments', 'thiscall', None, ret='eax', gen=gen, note='batch62002')
