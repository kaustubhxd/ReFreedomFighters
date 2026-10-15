"""specs_s5810.py - unclaimed-57, batch 110: 0x5da160 (GUESS name unnamed_5da160). Thiscall, two stack arguments (a16 whose low word is compared, b; ret 8),
returns 0. Hooked callees: 0x5da470 (batch 99: returns an object e, null in about one case in five) and 0x5da670 (batch 48: a logging stub with ECX and two
arguments, writing nothing). The engine's pointer p at +0x190f is an object with fake slots +0xb8 (one arg, logged) and +0xac (two args: the object and a
float, logged as its bit pattern). e has fake slots +0x254 and +0x250 (no args, logged). The state at this+0x4c is 0, 1 or 2 at random; the word is one of
this+0x50, +0x52, +0x54 in about four cases in five, otherwise random."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5160(c):
    e = c.emu
    e_obj = _rnd(c, 0x80)
    null_e = c.rng.random() < 0.2

    def h5a470(em, r):
        em.calllog.append(('5a470', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0 if null_e else e_obj, argbytes=0)

    def h5a670(em, r):
        p = em.arg32(1)
        if self_obj <= p < self_obj + 0x200:
            what = ('self', p - self_obj)
        else:
            what = ('buf', em.rbytes(p, 16))  # a stack buffer: log its contents, never its address
        em.calllog.append(('5a670', 0, 'S' if em.reg('ecx') == self_obj else 'other', (em.arg32(0), what)))
        em.ret(eax=0, argbytes=8)

    def hb8(em, r):
        em.calllog.append(('b8', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hac(em, r):
        em.calllog.append(('ac', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h254(em, r):
        em.calllog.append(('254', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def h250(em, r):
        em.calllog.append(('250', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x5da470, h5a470)
    e.hook(0x5da670, h5a670)
    vt_e = e.fake_vtable('d5160_e', 200, {0x254: h254, 0x250: h250})
    vt_p = e.fake_vtable('d5160_p', 200, {0xb8: hb8, 0xac: hac})
    e.w32(e_obj, vt_e)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x190f, p)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    w50 = c.rng.getrandbits(16)
    w52 = c.rng.getrandbits(16)
    w54 = c.rng.getrandbits(16)
    e.wbytes(self_obj + 0x50, bytes([w50 & 0xff, w50 >> 8]))
    e.wbytes(self_obj + 0x52, bytes([w52 & 0xff, w52 >> 8]))
    e.wbytes(self_obj + 0x54, bytes([w54 & 0xff, w54 >> 8]))
    e.w32(self_obj + 0x4c, c.rng.choice([0, 1, 2]))
    x = c.rng.random()
    if x < 0.3:
        low = w50
    elif x < 0.6:
        low = w52
    elif x < 0.8:
        low = w54
    else:
        low = c.rng.getrandbits(16)
    a16 = (c.rng.getrandbits(16) << 16) | low
    b = c.rng.getrandbits(32)
    return [self_obj, a16, b]


S(0x5da160, 'unnamed_5da160 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_d5160,
  note='unclaimed-57 batch 110; 0x5da470 (batch 99) and 0x5da670 (batch 48) hooked; p slots +0xb8 and +0xac, e slots +0x254 and +0x250 fake')
