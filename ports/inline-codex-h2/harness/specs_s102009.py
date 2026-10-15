from pilot import S
from recruits_util import obj, rnd, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    key = r.getrandbits(32)
    o1_result, o2_result = rnd(c, 0x20), rnd(c, 0x20)
    # The return values of slot 0x10 independently exercise both cleanup branches.
    v10a = pystub(c, 0, ret=(o1_result if r.randrange(2) else 0), pop=0, this=True)
    v8a = pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True)
    v10b = pystub(c, 0, ret=(o2_result if r.randrange(2) else 0), pop=0, this=True)
    v8b = pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True)
    o1 = obj(c, 0x80, {8: v8a, 0x10: v10a})
    o2 = obj(c, 0x80, {8: v8b, 0x10: v10b})
    for o in (o1, o2):
        e.w32(o + 0x35, 0)
        e.w32(o + 0x39, 0)
        e.w32(o + 0x41, 0)
    lookup_ret = rnd(c, 0x20)
    table_slot = pystub(c, 1, ret=lookup_ret, pop=4, this=True)
    sysobj(c, table_slots={0x4c: table_slot})
    owner = rnd(c, 0x20)
    e.w32(owner + 8, key)
    e.w32(owner + 0xc, o1)
    e.w32(owner + 0x10, o2)
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    return [owner]


S(0x4862b0, 'GUESS_initialize_and_resolve_two_lists', 'thiscall', None,
  ret='al', gen=gen, note='batch102009')
