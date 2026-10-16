from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x20)
    buffer = rnd(c, 0x100) if r.random() < 0.9 else 0
    e.w32(self + 4, buffer)
    input = rnd(c, 0x20)
    result = 0 if r.random() < 0.4 else rnd(c, 4)
    if result:
        e.w8(result, r.choice([0, 1]))
    hook_rec(c, 0x49e140, 2, pop=8, ret=result)
    msg = obj(c, 0x40, {0x30: pystub(c, 3, pop=0)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, pop=8, ret=msg)})
    e.w32(0x700390, logger)
    return [self, input]

S(0x49e070, 'GUESS validate resource path and report lookup failure', 'thiscall', None, ret='eax', gen=gen, note='batch62115')
