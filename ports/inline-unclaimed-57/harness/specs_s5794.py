"""specs_s5794.py - unclaimed-57, batch 94: 0x5d9210 (GUESS name unnamed_5d9210). Thiscall, no stack args, plain ret. 0x5d92e0 (ported in
batch 84) is hooked as a logging stub: it logs its ECX tag and its argument, and writes nothing. The object at this+0x44 has a fake slot +0x254
(no args, logged). The engine (global 0x70039c) has a sub-object at +0x9b with fake slots +0x58 (one arg, logged; returns t or null) and
+0x134 (returns x); x has a fake slot +0x90 (two args: writes a flag byte through the second; the flag is 0 or 1 at random). The engine's
pointer at +0x190f is null in about one case in three, and otherwise an object whose byte +0x81 is 0 or 1. The float constants are the exe's data."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9210(c):
    e = c.emu
    o_obj = _rnd(c, 0x40)
    t_obj = _rnd(c, 0x40)
    x_obj = _rnd(c, 0x40)
    null_t = c.rng.random() < 0.4
    flag = c.rng.choice([0, 1])

    def h92e0(em, r):
        em.calllog.append(('92e0', 'S' if em.reg('ecx') == self_obj else 'other', (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x5d92e0, h92e0)

    def h254(em, r):
        em.calllog.append(('254', 0, 'O' if em.reg('ecx') == o_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=0 if null_t else t_obj, argbytes=4)

    def h134(em, r):
        em.calllog.append(('134', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h90(em, r):
        em.calllog.append(('90', 0, None, (em.arg32(0),)))
        em.wbytes(em.arg32(1), bytes([flag]))
        em.ret(eax=0, argbytes=8)

    vt_o = e.fake_vtable('d9210_o', 160, {0x254: h254})
    vt_sub = e.fake_vtable('d9210_sub', 160, {0x58: h58, 0x134: h134})
    vt_x = e.fake_vtable('d9210_x', 160, {0x90: h90})
    e.w32(o_obj, vt_o)
    e.w32(x_obj, vt_x)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    if c.rng.random() < 2 / 3:
        p = _rnd(c, 0x100)
        e.wbytes(p + 0x81, bytes([c.rng.choice([0, 1])]))
        e.w32(eng + 0x190f, p)
    else:
        e.w32(eng + 0x190f, 0)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x44, o_obj)
    e.w32(self_obj + 0x54, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d9210, 'unnamed_5d9210 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d9210,
  note='unclaimed-57 batch 94; 0x5d92e0 hooked (logs); object slot +0x254, engine sub slots +0x58 and +0x134, x slot +0x90 fake')
