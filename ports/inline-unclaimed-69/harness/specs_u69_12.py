"""specs_u69_12.py - area 69, group 12 (unclaimed-69 thread): ZCHAROBJ::ClassInit2."""
from pilot import S
from ckit import obj, rnd, rvt, cstr


def _ci2(c):
    r = c.rng
    e = c.emu
    e.hook(0x45d3a0, lambda e, res: (e.calllog.append(('ZGEOM::ClassInit2', e.reg('ecx'))), e.ret()))
    o = rnd(c, 0x200)
    txt = r.choice([0, cstr(e, b''), cstr(e, b'%Player'), cstr(e, b'Name_Text'), cstr(e, b'%')])
    e.w32(o + 0x9b, txt)
    e.w32(o, rvt(e, 'charobj', {0x284: (1, lambda e, t, a: (0, None, (bytes(e.rbytes(a[0], 16)).split(b'\0')[0] if a[0] else None,))),
                                0x288: (2, lambda e, t, a: (0, None, (a[0], bytes(e.rbytes(a[1], 16)).split(b'\0')[0] if a[1] else None)))},
                 nslots=0x28c // 4))
    return [o]


S(0x4ef090, 'ZCHAROBJ::ClassInit2', 'thiscall', None, ret=None, gen=_ci2, note='u69 group 12; ZGEOM::ClassInit2 is a GUESS stub')
