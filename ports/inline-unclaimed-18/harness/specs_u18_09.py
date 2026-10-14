"""specs_u18_09.py - area 18, group 9 (unclaimed-18 thread)."""
from pilot import S
from ckit import obj, rnd, cstr, rvt


def _rflf(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x12000)
    sub_vt = rvt(e, 'loadlist', {0x90: (1, lambda e, t, a: (0, None, (bytes(e.rbytes(a[0], 24)).split(b'\0')[0],)))}, nslots=0x94 // 4)
    e.w32(o + 0x1218c, sub_vt)   # embedded sub-object: its first dword is its vtable
    name = cstr(e, r.choice([b'save1.dat', b'', b'slot_7']))
    return [o, name]


S(0x59c510, 'ZFFSaveDeviceInterface::RemoveFileFromLoadList', 'thiscall', None, ret=None, gen=_rflf,
  note='u18; the target slot is a logging fake')


def _b2(c):
    return [rnd(c, 0x40), rnd(c, 0x40)]


S(0x65f200, 'unnamed flag setter (GUESS)', 'thiscall', None, ret=None, gen=_b2, note='u18')
