"""specs_u69_09.py - area 69, group 9 (unclaimed-69 thread): ZCHAROBJ::SetTextId."""
from pilot import S
from ckit import obj, rnd, rvt, cstr


def _sti(c):
    r = c.rng
    e = c.emu
    sysobj = rnd(c, 0x200)
    e.w32(0x70039c, sysobj)
    pool = [cstr(e, b'Resolved_A'), cstr(e, b'Resolved_B')]
    acts = obj(e, 'acts', 0x40, {0: (2, lambda e, t, a: (r.choice([a[1], 0, pool[r.randrange(2)]]), None,
                                                       (bytes(e.rbytes(a[0], 16)).split(b'\0')[0] if a[0] else None,)))}, nslots=4)
    eng = rnd(c, 0x1000)
    e.w32(eng + 0xae4, acts)
    e.w32(sysobj + 0x9b, eng)
    o = rnd(c, 0x200)
    e.w32(o, rvt(e, 'charobj', {0x284: (1, lambda e, t, a: (0, None, (bytes(e.rbytes(a[0], 16)).split(b'\0')[0] if a[0] else None,)))},
                 nslots=0x288 // 4))
    idp = cstr(e, r.choice([b'ID_A', b'ID_B', b'']))
    txt = r.choice([0, cstr(e, b''), cstr(e, r.choice([b'Hello', b'Text_2'])), cstr(e, b'x' * 20)])
    return [o, idp, txt]


S(0x4f14d0, 'ZCHAROBJ::SetTextId', 'thiscall', None, ret=None, gen=_sti, note='u69 core-ish; the actions object is a fake')
