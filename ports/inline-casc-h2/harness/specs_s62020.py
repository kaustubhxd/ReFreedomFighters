from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec, pystub


def g4b0a70(c):
    clear_hooks(c)
    r = c.rng
    values = [r.getrandbits(32), r.choice([0, 1, 2, 0xffffffff])]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: values[min(k, 1)])
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, pop=16, ret=r.getrandbits(32))}, table_size=0x200)
    return [rnd(c, 0x60), rnd(c, 0x20)]


S(0x4b0a70, 'GUESS parse values and report engine status', 'thiscall', None, ret=None, gen=g4b0a70, note='batch62020')
