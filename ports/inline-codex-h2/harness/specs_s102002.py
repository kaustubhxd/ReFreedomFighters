from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng

    final = pystub(c, 5, ret=r.getrandbits(32), pop=20, this=True)
    worker = obj(c, 0x400, {0x314: final})
    owner = obj(c, 0x40, {})
    e.w32(owner + 0x14, worker)

    get_result = r.getrandbits(32)
    method34 = pystub(c, 0, ret=get_result, pop=0, this=True)
    branch_type = r.choice([3, 3, 4, 4, 2, 5])
    vt_head = rnd(c, 0x80)
    e.w32(vt_head + 0x34, method34)
    vt = obj(c, 0x40, {0: vt_head})
    table = obj(c, 0x40, {})
    e.w32(table, e.r32(vt))
    e.w32(table + 0x40, 0) # leave type storage separate from the vtable pointer
    e.w8(table + 4, branch_type)

    items = [obj(c, 0x40, {}) for _ in range(3)]
    for ptr in items:
        for off in (0, 4, 8, 12):
            e.wf32(ptr + off, c.fv(-5, 5, edge=0.01))
    # The last lookup (index zero) selects the branch object.
    returned = [items[2], items[1], items[0], table]
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: returned[k], pop=4,
             this=True)

    slot2c = pystub(c, 3, ret=r.getrandbits(32), pop=0, this=True)
    log_result = obj(c, 0x40, {0x2c: slot2c})
    slot20 = pystub(c, 2, ret=log_result, pop=0, this=True)
    e.w32(0x700390, obj(c, 0x40, {0x20: slot20}))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))

    array = rnd(c, 0x20)
    e.wf32(array, c.fv(-3, 3, edge=0.01))
    e.w32(array + 4, rnd(c, 0x40))
    return [owner, array]


S(0x5199e0, 'GUESS_query_four_slots_and_dispatch_transform', 'thiscall', None,
  ret=None, gen=gen, note='batch102002')
