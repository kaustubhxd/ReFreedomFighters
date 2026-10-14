"""specs_s5789.py - unclaimed-57, batch 89: 0x5c3310 (GUESS name unnamed_5c3310). Thiscall, one stack argument obj (ret 4), returns al = 1.
obj has fake slots +0x60 (one byte value, zero-extended, logged) and +0x4c (one float, logged as its bit pattern, so NaN payloads are
checked too). The fields are random bytes in this, so the unaligned float reads at +0x115, +0x119, +0x11d and +0x121 are exercised."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c3310(c):
    e = c.emu

    def h60(em, r):
        em.calllog.append(('60', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h4c(em, r):
        em.calllog.append(('4c', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('c3310_o', 160, {0x60: h60, 0x4c: h4c})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    self_obj = _rnd(c, 0x200)
    return [self_obj, obj]


S(0x5c3310, 'unnamed_5c3310 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_c3310,
  note='unclaimed-57 batch 89; obj fake slots +0x60 (byte) and +0x4c (float bits) logged')
