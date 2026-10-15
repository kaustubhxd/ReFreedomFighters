from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec, pystub


def g5b95f0(c):
    clear_hooks(c)
    r = c.rng
    parsed = [r.getrandbits(32), r.getrandbits(32)]
    looked = [r.getrandbits(32), r.getrandbits(32)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: parsed[min(k, 1)])
    slot = pystub(c, 1, this=True, pop=4, ret=lambda emu, k: looked[min(k, 1)])
    sysobj(c, table_slots={0x58: slot})
    return [rnd(c, 0x60), r.getrandbits(32), rnd(c, 0x20)]


S(0x5b95f0, 'GUESS parse values and resolve engine entries', 'thiscall', None, ret=None, gen=g5b95f0, note='batch62024')
