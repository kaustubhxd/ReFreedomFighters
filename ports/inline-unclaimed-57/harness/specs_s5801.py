"""specs_s5801.py - unclaimed-57, batch 101: 0x5d6d40 (GUESS name unnamed_5d6d40). Thiscall, two stack arguments (a16 whose low word is compared,
arg2; ret 8), no return value. The object at this+0x44 has fake slots +0xbc (one argument, logged) and +0x250 (one argument, logged). The word
compared is this+0x50 in about four cases in ten, this+0x52 in about three in ten, otherwise random. arg2 is zero in about three cases in ten.
The engine (global 0x70039c) dword at +0x40 is random; the float constants are the exe's data. The field addresses are never the engine's, so
the original's address tests take the store path, as the port does."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d6d40(c):
    e = c.emu

    def hbc(em, r):
        em.calllog.append(('bc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h250(em, r):
        em.calllog.append(('250', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('d6d40_o', 160, {0xbc: hbc, 0x250: h250})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x40, c.rng.getrandbits(32))
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x44, obj)
    w50 = c.rng.getrandbits(16)
    w52 = c.rng.getrandbits(16)
    e.wbytes(self_obj + 0x50, bytes([w50 & 0xff, w50 >> 8]))
    e.wbytes(self_obj + 0x52, bytes([w52 & 0xff, w52 >> 8]))
    x = c.rng.random()
    if x < 0.4:
        low = w50
    elif x < 0.7:
        low = w52
    else:
        low = c.rng.getrandbits(16)
    a16 = (c.rng.getrandbits(16) << 16) | low
    arg2 = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    return [self_obj, a16, arg2]


S(0x5d6d40, 'unnamed_5d6d40 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d6d40,
  note='unclaimed-57 batch 101; object slots +0xbc and +0x250 logged; engine dword at +0x40 random; float constants from the exe')
