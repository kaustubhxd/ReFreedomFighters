"""specs_s5811.py - unclaimed-57, batch 111: 0x5d52d0 (GUESS name unnamed_5d52d0). Thiscall, two stack arguments (a16, v; ret 8), returns 0. The word
compared is this+0x48 in about four cases in ten, this+0x4a in about three in ten, otherwise random. v is zero in about three cases in ten.
The object at this+0x44 has fake slots +0xbc and +0x250 (one arg each, logged). The engine dword at +0x40 is random, and the float constants are
the exe's data. The engine value equals this+0x4c in about one case in seven only through the random draw, which the heap comparison checks."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d52d0(c):
    e = c.emu

    def hbc(em, r):
        em.calllog.append(('bc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h250(em, r):
        em.calllog.append(('250', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('d52d0_o', 200, {0xbc: hbc, 0x250: h250})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x40, c.rng.getrandbits(32))
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    e.w32(self_obj + 0x44, obj)
    w48 = c.rng.getrandbits(16)
    w4a = c.rng.getrandbits(16)
    e.wbytes(self_obj + 0x48, bytes([w48 & 0xff, w48 >> 8]))
    e.wbytes(self_obj + 0x4a, bytes([w4a & 0xff, w4a >> 8]))
    x = c.rng.random()
    if x < 0.4:
        low = w48
    elif x < 0.7:
        low = w4a
    else:
        low = c.rng.getrandbits(16)
    a16 = (c.rng.getrandbits(16) << 16) | low
    v = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    return [self_obj, a16, v]


S(0x5d52d0, 'unnamed_5d52d0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_d52d0,
  note='unclaimed-57 batch 111; object slots +0xbc and +0x250 logged; engine dword at +0x40 random; float constants from the exe')
