"""specs_s5805.py - unclaimed-57, batch 105: 0x5da540 (GUESS name unnamed_5da540). Thiscall, no stack args, plain ret. The callee 0x5da470 (batch 99)
is a hooked stub that returns a per-case object e (null in about one case in five, which returns at once). The engine's pointer p at +0x190f is
always set (its slot +0xb8 is called unconditionally), and has a byte at +0x81 that is 0 or 1; p has a fake slot +0xb8 (one arg, logged). The engine
sub-object has fake slots +0x58 (one arg, logged; returns u, null in about one case in five) and +0x134 (returns x). e has fake slots +0x27c
(one arg, logged), +0x280 (one float argument, logged as its bit pattern). x has fake slot +0x90 (two args: a flag byte is written through the
second). The gate at this+0x62 is zero in about two cases in five."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5540(c):
    e_ = c.emu
    e_obj = _rnd(c, 0x80)
    u_obj = _rnd(c, 0x40)
    x_obj = _rnd(c, 0x40)
    p_obj = _rnd(c, 0x40)
    null_e = c.rng.random() < 0.2
    p81 = c.rng.choice([0, 1])
    null_u = c.rng.random() < 0.2
    flag = c.rng.choice([0, 1])

    def h5a470(em, r):
        em.calllog.append(('5a470', 0, 'S' if em.reg('ecx') == self_obj else 'other', ()))
        em.ret(eax=0 if null_e else e_obj, argbytes=0)

    def hb8(em, r):
        em.calllog.append(('b8', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=0 if null_u else u_obj, argbytes=4)

    def h134(em, r):
        em.calllog.append(('134', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h27c(em, r):
        em.calllog.append(('27c', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h280(em, r):
        em.calllog.append(('280', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h90(em, r):
        em.calllog.append(('90', 0, None, (em.arg32(0),)))
        em.wbytes(em.arg32(1), bytes([flag]))
        em.ret(eax=0, argbytes=8)

    e_.hook(0x5da470, h5a470)
    vt_e = e_.fake_vtable('d5540_e', 200, {0x27c: h27c, 0x280: h280})  # 0x280 is slot 160: the table needs more than 160 entries
    vt_p = e_.fake_vtable('d5540_p', 160, {0xb8: hb8})
    vt_sub = e_.fake_vtable('d5540_sub', 160, {0x58: h58, 0x134: h134})
    vt_x = e_.fake_vtable('d5540_x', 160, {0x90: h90})
    e_.w32(e_obj, vt_e)
    e_.w32(p_obj, vt_p)
    e_.w32(x_obj, vt_x)
    sub = _rnd(c, 0x40)
    e_.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e_.w32(eng + 0x9b, sub)
    e_.w32(eng + 0x190f, p_obj)  # p is always set: the original calls its slot +0xb8 unconditionally
    e_.wbytes(p_obj + 0x81, bytes([p81]))
    e_.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e_.w32(self_obj + 0x5a, c.rng.getrandbits(32))
    e_.w32(self_obj + 0x62, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32))
    return [self_obj]


S(0x5da540, 'unnamed_5da540 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5540,
  note='unclaimed-57 batch 105; callee 0x5da470 hooked (batch 99; returns e or null); p, sub, e, x, u fake slots; float argument logged')
