"""specs_s960.py - area 50 batch 960: 0x515f00 (thiscall, no args, ret 0, void). Has stack cookie (not reproduced, tagged).
Stand-ins (logged): 0x515f60 (thiscall, one arg, helper function), and this's objects at +0xd6 and +0xda with virtual
method at [0] (thiscall, one u32 arg, ret 4 assumed)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def h515f60(e, rr):
        e.calllog.append(('515f60', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x515f60: h515f60})

    def hvtm0_d6(e, rr):
        e.calllog.append(('obj.d6[0]', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def hvtm0_da(e, rr):
        e.calllog.append(('obj.da[0]', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    obj_d6 = vt_object(c, 0x40, {0: hvtm0_d6}, nslots=0x100, name='obj_d6')
    obj_da = vt_object(c, 0x40, {0: hvtm0_da}, nslots=0x100, name='obj_da')
    self = rnd(c, 0x100)
    e.w32(self + 0xd6, obj_d6)
    e.w32(self + 0xda, obj_da)
    return [self]


S(0x515f00, 'destructor with helper and two virtual calls (no name in map; 515f60 stood in)', 'thiscall', None, gen=_gen, note='area50 batch960 (claimed)')
