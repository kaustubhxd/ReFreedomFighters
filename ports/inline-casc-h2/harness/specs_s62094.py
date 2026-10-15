from pilot import S
from recruits_util import clear_hooks, obj, pystub, sysobj


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    found = r.randrange(2)
    lookup = obj(c, 0x20, {0x130: pystub(c, 2, this=True, pop=8,
        ret=r.getrandbits(32))})
    def set_found(emu, k):
        emu.w8(emu.arg32(4), found)
    query_ret = r.getrandbits(32)
    query = pystub(c, 5, this=True, pop=20, ret=query_ret,
                   stackmark=(4,), side=set_found)
    table_slots = {
        0x58: pystub(c, 0, this=True, ret=lookup),
        0x114: query,
    }
    sysobj(c, table_slots=table_slots)
    return []


S(0x5f0c70, 'GUESS query global table and return found byte', 'cdecl', None,
  ret='al', gen=gen, note='batch62094')
