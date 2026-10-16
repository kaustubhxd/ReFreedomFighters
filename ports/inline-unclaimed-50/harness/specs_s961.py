"""specs_s961.py - area 50 batch 961: 0x508560 (thiscall, one arg, ret 4, void). Has stack cookie (not reproduced, tagged).
Stand-ins (logged): 0x5003d0 (thiscall, one index arg, returns a pointer), and this's object at +0x18 with virtual
methods at [0x57c], [0x620], [0x578] (thiscall, various args, ret 4 assumed)."""
import struct
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    # Allocate a block with random dword (will be tested)
    dval = r.randint(0, 3)  # Sometimes 0, sometimes non-zero
    blk = rnd(c, 0x10)
    e.w32(blk, dval)

    def h5003(e, rr):
        e.calllog.append(('5003d0', e.arg32(0), e.reg('ecx') != 0))
        e.ret(eax=blk, argbytes=4)

    only_hooks(c, {0x5003d0: h5003})

    def hvtm57c(e, rr):
        e.calllog.append(('obj.18[57c]', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    def hvtm620(e, rr):
        e.calllog.append(('obj.18[620]', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    def hvtm578(e, rr):
        e.calllog.append(('obj.18[578]', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    obj_18 = vt_object(c, 0x700, {0x57c: hvtm57c, 0x620: hvtm620, 0x578: hvtm578}, nslots=0x1000, name='obj_18')
    self = rnd(c, 0x40)
    e.w32(self + 0x18, obj_18)
    a = rnd(c, 0x40)
    e.w32(a + 4, rnd(c, 0x20))
    return [self, a]


S(0x508560, 'accessor test then conditional virtual calls (no name in map; 5003d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch961 (claimed)')
