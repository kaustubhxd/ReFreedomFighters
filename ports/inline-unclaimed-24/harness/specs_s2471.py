"""specs_s2471.py - decomp area 24, batch 2471 (parked ZLIST rows, stack contract resolved).
0x44a5e0 ZLIST::RemoveGeom(ZGEOM*) and 0x449f70 ZLIST::AddGeom(ZGEOM*), thiscall, ret 4. The argument is pushed again for the
sys-table call (the table object at ([0x70039c]+0x9b)): slot 0x4c, a thiscall that pops it (recorder, one argument, returns a
random dword). The result is pushed for this's slot 0x224 (RemoveGeom) or 0x21c (AddGeom), a thiscall popping it (recorder)."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _gen(slot):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        so = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
        o = obj(c, 0x100, {slot: pystub(c, 1)})
        return [o, rnd(c, 0x40)]
    return gen


S(0x44a5e0, 'ZLIST::RemoveGeom', 'thiscall', None, ret=None, gen=_gen(0x224), note='batch2471')
S(0x449f70, 'ZLIST::AddGeom', 'thiscall', None, ret=None, gen=_gen(0x21c), note='batch2471')
