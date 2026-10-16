"""specs_s5795.py - unclaimed-57, batch 95: 0x5d5b40 (GUESS name unnamed_5d5b40). Thiscall, four stack arguments (a, b, c, d; ret 0x10); c and d
are not read. Hooked callees: 0x64fc60 (count helper, ECX = the list object: returns the first count n, then a second count m, per case),
the list object's slot +4 (two args, logged), the object at this+0x25 (slot +0x2c, logged), this's own vtable slots +0x110 and +0x12c (two
args, logged), the engine sub-object's slots +0x138 (returns x) and +0x114 (four args, logged, random dword), and x's slot +0x88 (two args:
writes a per-case dword through the second, which is the local the original reads back). The threshold this+0x32 is chosen so that m < it
about half the time."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5b40(c):
    e = c.emu
    n_v = c.rng.randrange(0, 41)
    m_v = c.rng.randrange(0, 61)
    cnt = [0]
    bv = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    rvw = c.rng.getrandbits(32)

    def h64fc(em, r):
        cnt[0] += 1
        em.ret(eax=n_v if cnt[0] == 1 else m_v, argbytes=0)
    e.hook(0x64fc60, h64fc)

    def hl4(em, r):
        em.calllog.append(('l4', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def hp2c(em, r):
        em.calllog.append(('p2c', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def h110(em, r):
        em.calllog.append(('110', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h12c(em, r):
        em.calllog.append(('12c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h114(em, r):
        em.calllog.append(('114', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4))))
        em.ret(eax=rvw, argbytes=20)

    def h88(em, r):
        em.calllog.append(('88', 0, None, (em.arg32(0),)))
        em.w32(em.arg32(1), bv)
        em.ret(eax=0, argbytes=8)

    vt_self = e.fake_vtable('d5b40_self', 160, {0x110: h110, 0x12c: h12c})
    vt_l = e.fake_vtable('d5b40_l', 160, {0x4: hl4})
    vt_p = e.fake_vtable('d5b40_p', 160, {0x2c: hp2c})
    vt_sub = e.fake_vtable('d5b40_sub', 160, {0x138: h138, 0x114: h114})
    vt_x = e.fake_vtable('d5b40_x', 160, {0x88: h88})
    x_obj = _rnd(c, 0x40)
    e.w32(x_obj, vt_x)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    lst = _rnd(c, 0x40)
    e.w32(lst, vt_l)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    self_obj = _rnd(c, 0x200)
    e.w32(self_obj, vt_self)
    e.wbytes(self_obj + 0x31, bytes([1 if c.rng.random() < 0.8 else 0]))
    e.w32(self_obj + 0x2d, c.rng.randrange(0, 4))
    e.w32(self_obj + 0x25, 0 if c.rng.random() < 0.3 else p)
    e.w32(self_obj + 0x19, 0 if c.rng.random() < 0.2 else lst)
    e.w32(self_obj + 0x32, c.rng.randrange(0, 51))
    args = [c.rng.getrandbits(32) for _ in range(4)]
    return [self_obj] + args


S(0x5d5b40, 'unnamed_5d5b40 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5b40,
  note='unclaimed-57 batch 95; 0x64fc60 hooked (two counts); list slot +4, this slots +0x110 and +0x12c, sub slots +0x138 and +0x114, x slot +0x88 fake')
