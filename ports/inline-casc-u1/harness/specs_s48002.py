"""specs_s48002.py - tier H. 0x4700a0: this object (slots 0x2f4 / 0x2c8 / 0x94 / 0x350), optional owner p (slot 0x20) giving b, object table with slots 0x4c / 0x60 / 0x58 and a dword at +0xadc,
hooked 0x43ec00 (ret 0x18, records the 9+3 floats), hooked 0x4db3b0 (ecx), record o (+0x3c/+0x40/+0x60/+0x64), engine random slot 0x1c0 (st0), x with slot 0x33c, /GS check keeping eax."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _fv(r):
    k = r.random()
    if k < 0.1:
        return r.choice(EDGE_F)
    return r.uniform(-4, 4)


def _g4700a0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda e, k: e.reg("eax"))
    res_obj = rnd(c, 0x20)
    res = r.choice([res_obj, res_obj, r.getrandbits(32)])

    def fill(e, k):
        v34, v10 = e.arg32(0), e.arg32(1)
        for i in range(9):
            e.w32(v34 + 4 * i, r.getrandbits(32))
        for i in range(3):
            e.w32(v10 + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x43ec00, 6, this=True, pop=0x18, ret=res, deref={0: 9, 1: 3})
    # 4db3b0 result: equal to [mgr+0xadc] (filled below), zero, or random
    state = {}

    def r4db(e, k):
        m = state['mgr']
        return r.choice([0, e.r32(m + 0xadc), e.r32(m + 0xadc), r.getrandbits(32)])
    hook_rec(c, 0x4db3b0, 0, this=True, pop=0, ret=r4db)
    # objects
    b = obj(c, 0x20, {0x94: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x98 // 4)
    p = obj(c, 0x20, {0x20: pystub(c, 0, ret=b, this=True)}, nslots=0x24 // 4)
    xo = obj(c, 0x20, {0x33c: pystub(c, 0, ret=lambda e, k: r.choice([0, 1, -1, 5, -7, 100, 0x7fffffff, r.getrandbits(32)]), this=True)}, nslots=0x340 // 4)
    has_p = r.random() < 0.5
    me = obj(c, 0x40, {0x2f4: pystub(c, 0, ret=(p if has_p else 0), this=True),
                       0x2c8: pystub(c, 2, this=True, side=fill, stackmark=(0, 1)),
                       0x350: pystub(c, 0, ret=xo, this=True),
                       0x94: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x354 // 4)
    o = rnd(c, 0x80)
    has_o = r.random() < 0.85
    kobj = obj(c, 0x20, {}, nslots=4)
    has_k = r.random() < 0.85
    so = sysobj(c, rand=lambda e, k: _fv(r),
                table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True),
                             0x60: pystub(c, 1, ret=(o if has_o else 0), this=True),
                             0x58: pystub(c, 1, ret=(kobj if has_k else 0), this=True)}, table_size=0xb00)
    state['mgr'] = em.r32(so + 0x9b)
    em.w32(kobj + 8, rnd(c, 0x20))
    em.w32(o + 0x3c, r.getrandbits(32))
    em.w32(o + 0x40, r.getrandbits(32))
    import os
    if os.environ.get('DBG48'):
        print('DBG me=%x o=%x kobj=%x has_o=%s has_k=%s p=%x b=%x res=%x so=%x' % (me, o, kobj, has_o, has_k, p, b, res_obj, so))
    return [me, r.choice([0, 1, 7, r.getrandbits(32)])]


S(0x4700a0, 'GUESS spawn record through object table and retime', 'thiscall', None, ret='eax', gen=_g4700a0, nan_heap=True, note='batch48002')
