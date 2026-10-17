"""specs_s5763.py - unclaimed-57, batch 63: 0x5d89f0 (GUESS name unnamed_5d89f0). Thiscall, no stack args, no return value. The
engine (global 0x70039c) has a sub-object at +0x9b (fake vtable: slot +0x58 with one argument returns object a, or null in about
one case in four, so the skip path runs too) and a holder at +0x1aa3 whose +0x18 is object b. Object a has fake slots +0x254 (one
argument, returns r1) and +0x274 (returns r2); object b has slot +0x108 (three arguments, returns the value stored at this+0x34).
Every slot logs its arguments and the ECX value's presence, never a pointer, since pointers vary between runs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d89(c):
    e = c.emu
    null_a = c.rng.random() < 0.25
    obj_a = _rnd(c, 0x40)
    obj_b = _rnd(c, 0x40)
    r254 = c.rng.getrandbits(32)
    r274 = c.rng.getrandbits(32)
    r108 = c.rng.getrandbits(32)

    def h58(em, r):
        em.calllog.append(('58', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0 if null_a else obj_a, argbytes=4)

    def h254(em, r):
        em.calllog.append(('254', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=r254, argbytes=4)

    def h274(em, r):
        em.calllog.append(('274', 0, em.reg('ecx'), ()))
        em.ret(eax=r274, argbytes=0)

    def h108(em, r):
        em.calllog.append(('108', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=r108, argbytes=12)

    vt_sub = e.fake_vtable('d89f0_sub', 160, {0x58: h58})
    vt_a = e.fake_vtable('d89f0_a', 160, {0x254: h254, 0x274: h274})
    vt_b = e.fake_vtable('d89f0_b', 160, {0x108: h108})
    e.w32(obj_a, vt_a)
    e.w32(obj_b, vt_b)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    holder = _rnd(c, 0x40)
    e.w32(holder + 0x18, obj_b)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(eng + 0x1aa3, holder)
    e.w32(0x70039c, eng)
    obj = _rnd(c, 0x200)
    e.w32(obj + 0x28, c.rng.getrandbits(32))
    return [obj]


S(0x5d89f0, 'unnamed_5d89f0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d89,
  note='unclaimed-57 batch 63; engine sub +0x9b slot +0x58 (null or object a), a slots +0x254/+0x274, b slot +0x108; logged')
