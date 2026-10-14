"""specs_s842.py - area 50, batch 842: ZItemTemplateWeapon::Save. ZGROUP::Save (0x441790) is hooked and logged; the save
stream's virtuals are logged with their arguments (pointers into the object are the same in both runs)."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x441790: logged_fn('ZGROUP::Save', 1)})
    s = vt_object(c, 0x40, {0x6c: vslot('s.int', 1), 0x70: vslot('s.ptr70', 1), 0x68: vslot('s.ptr68', 1),
                            0x4c: vslot('s.float', 1), 0x64: vslot('s.dword', 1)}, nslots=0x40, name='stream')
    self = rnd(c, 0x140)
    e.w32(self + 0x70, r.getrandbits(32))
    for off in (0x10b, 0x10f):
        e.wf32(self + off, c.fv(-100, 100))
    for off in (0x11b, 0x11f, 0x123, 0x127):
        e.w32(self + off, r.getrandbits(32))
    return [self, s]


S(0x470720, 'ZItemTemplateWeapon::Save', 'thiscall', None, ret='al', gen=_gen, note='area50 batch842')
