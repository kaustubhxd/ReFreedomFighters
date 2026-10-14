"""specs_u18_06.py - area 18, group 6 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _load3(c):
    r = c.rng
    e = c.emu
    f = rnd(c, 0x40)
    e.w32(f, rvt(e, 'frame', {0x27c: (0, lambda e, t, a: (r.getrandbits(32), None, ()))}, nslots=0x280 // 4 + 1))
    return [f]


S(0x4f5850, 'ZFRAME::Load3', 'thiscall', None, ret='eax', gen=_load3, note='u18')


def _suint(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    sub = obj(e, 'serial', 0x40, {0x3c: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0],)))})
    e.w32(o + 0x15, sub)
    return [o, r.getrandbits(32)]


S(0x5f3310, 'SaveSerialInfo_t::saveuint32', 'thiscall', None, ret='eax', gen=_suint, note='u18')


def _cc(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o, rvt(e, 'font', {0x280: (1, lambda e, t, a: (r.choice([0, 1, 0x100, r.getrandbits(32)]), None, (a[0],)))},
                 nslots=0x284 // 4))
    return [o, r.getrandbits(32)]


S(0x4f6390, 'ZTTFONT::ContainsChar', 'thiscall', None, ret='al', gen=_cc, note='u18')


def _re(c):
    r = c.rng
    e = c.emu
    sysobj = rnd(c, 0x2000)
    e.w32(0x70039c, sysobj)
    target = obj(e, 'rootctl', 0x40, {0x14: (1, lambda e, t, a: (0, None, (bytes(e.rbytes(a[0], 16)).split(b'\0')[0],)))})
    e.w32(sysobj + 0x1907, target if r.random() < 0.8 else 0)
    return [rnd(c, 0x40)]


S(0x4c7310, 'CRootGroup::End', 'thiscall', None, ret=None, gen=_re, note='u18')
