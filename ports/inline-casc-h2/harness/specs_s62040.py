from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5a5950, 2, this=True, pop=8, ret=r.getrandbits(32), side=lambda emu,k: emu.calllog.append(('helper', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    return [rnd(c, 0x600), r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 2, 3, 4, 0x10002])]

S(0x5a56d0, 'GUESS dispatch typed callback or assert', 'thiscall', None, ret='eax', gen=gen, note='batch62040')
