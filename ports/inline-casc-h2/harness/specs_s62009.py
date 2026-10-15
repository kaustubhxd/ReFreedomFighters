from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    query = pystub(c, 1, this=True, pop=4, ret=c.rng.getrandbits(32))
    item = obj(c, 4, {0x14: query})
    get_item = pystub(c, 0, this=True, pop=0, ret=item)
    collection = obj(c, 4, {0x20: get_item})
    sys = sysobj(c)
    c.emu.w32(sys + 0x190f, collection)
    return [c.rng.choice([0, 0, 1, 2, 0x20000000, c.rng.getrandbits(32)])]

S(0x655c00, 'GUESS query system collection by scaled index', 'stdcall', None, ret='eax', gen=gen, note='batch62009')
