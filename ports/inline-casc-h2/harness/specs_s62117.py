from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    rnd(c, 0x1000)  # keep harness-owned stack locals away from the low heap block
    self = obj(c, 0x100, {0xd8: pystub(c, 0, this=True, ret=1)})
    descriptor = obj(c, 0x20, {0x88: pystub(c, 2, this=True, pop=8, nullflag=(1,))})
    have_handle = r.random() < 0.7
    handle_obj = obj(c, 0x20, {0x438: pystub(c, 0, this=True, ret=r.choice([0, 1, 2]))}) if have_handle else 0
    table = obj(c, 0x20, {
        0x138: pystub(c, 0, this=True, ret=descriptor),
        0x58: pystub(c, 1, this=True, pop=4, ret=handle_obj),
    })
    sysobj(c, table_slots={})
    # Replace the sysobj helper's own +0x9b table with our configured object.
    so = e.r32(0x70039c)
    e.w32(so + 0x9b, table)
    hook_rec(c, 0x562d90, 1, this=True, pop=4)
    return [self, r.choice([0x100, 0x105, 0x106, 0x200]) ]

S(0x56a840, 'GUESS resolve_engine_handle_and_run_fallback', 'thiscall', None, ret='al', gen=gen, note='batch62117')
