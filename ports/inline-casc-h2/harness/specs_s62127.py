from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = obj(c, 0x20, {0x68: pystub(c, 3, this=True, pop=12)})
    table = obj(c, 0x200, {0x134: pystub(c, 0, this=True, ret=resource)})
    sys = rnd(c, 0x200)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    hook_rec(c, 0x562440, 0, this=True, pop=0)
    hook_rec(c, 0x563510, 1, this=True, pop=4)
    return [rnd(c, 0x40)]

S(0x57bf60, 'GUESS initialize_three_engine_resources', 'thiscall', None, ret=None, gen=gen, note='batch62127')
