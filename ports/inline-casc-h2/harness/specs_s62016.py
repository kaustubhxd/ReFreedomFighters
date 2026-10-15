from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub


def g655bc0(c):
    clear_hooks(c)
    r = c.rng
    records = obj(c, 0x30, {0x14: pystub(c, 1, this=True, pop=4, ret=r.getrandbits(32))})
    collection = obj(c, 0x30, {0x20: pystub(c, 0, this=True, ret=records)})
    system = sysobj(c)
    c.emu.w32(system + 0x190f, collection)
    return [r.choice([0, 1, 2, 3, 0x100, r.getrandbits(32)])]


S(0x655bc0, 'GUESS lookup engine record by scaled index', 'stdcall', None, ret='eax', gen=g655bc0, note='batch62016')
