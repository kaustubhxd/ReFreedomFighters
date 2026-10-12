"""specs_s2463.py - decomp area 24, batch 2463 (gap band). Four save/load pairs with one shape: the base call (0x45f960 Save or
0x45f3c0 Load, recorders returning AL) is made with the argument; when AL is set, one slot of the save/load object gets
the dword at this+0x18 (slot 0x3c for Save, 0x40 for Load) and AL = 1; otherwise AL is the base result (0).
0x449600 ZLIGHT::Save, 0x449550 ZLIGHT::Load, 0x449630 ZSPOTLIGHT::Save, 0x449580 ZSPOTLIGHT::Load: thiscall, ret 4."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _gen(base, slot):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 1, this=True, ret=lambda emu, k: r.choice([0, r.getrandbits(32) | 1]))
        o = rnd(c, 0x100)
        sg = obj(c, 0x40, {slot: pystub(c, 1)})
        return [o, sg]
    return gen


S(0x449600, 'ZLIGHT::Save', 'thiscall', None, ret='al', gen=_gen(0x45f960, 0x3c), note='batch2463')
S(0x449550, 'ZLIGHT::Load', 'thiscall', None, ret='al', gen=_gen(0x45f3c0, 0x40), note='batch2463')
S(0x449630, 'ZSPOTLIGHT::Save', 'thiscall', None, ret='al', gen=_gen(0x45f960, 0x3c), note='batch2463')
S(0x449580, 'ZSPOTLIGHT::Load', 'thiscall', None, ret='al', gen=_gen(0x45f3c0, 0x40), note='batch2463')
