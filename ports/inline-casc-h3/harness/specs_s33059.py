"""specs_s33059.py - h3 (Sonnet) batch 33059."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g5f55e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    arr = rnd(c, 0x60)
    s = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.reg('ecx'), em.r32(me + 8))))
    for i in range(n):
        e.w32(arr + 8 * i, obj(c, 0x40, {0x28: s}))
        e.wbytes(arr + 8 * i + 4, bytes([r.choice([4, 4, 0, 1, 3, 5])]))
    me = rnd(c, 0x40)
    e.w32(me, arr)
    e.w32(me + 8, n)
    return [me]


def _g64f860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    sa = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]))
    sb = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]))
    vt2 = e.alloc(0x80, 4)
    e.w32(vt2 + 0x28, sb)
    o = obj(c, 0x80, {0x28: sa})
    s4c2 = pystub(c, 1, this=True, side=lambda em, k: e.w32(o, vt2), ret=lambda em, k: _w(c))
    me = rnd(c, 0xa0)
    e.w32(me + 0x8c, o)
    sysobj(c, table_slots={0x4c: s4c2})
    return [me, _w(c)]


def _g463940(c):
    clear_hooks(c)
    e = c.emu
    me = rnd(c, 0x100)
    s330a = pystub(c, 0, this=True)
    s330b = pystub(c, 0, this=True)
    vt2 = e.alloc(0x400, 4)
    e.w32(vt2 + 0x330, s330b)
    s2f8 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me, vt2))
    vt1 = e.alloc(0x400, 4)
    e.w32(vt1 + 0x2f8, s2f8)
    e.w32(vt1 + 0x330, s330a)
    e.w32(me, vt1)
    return [me]


def _g4870c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x200, 4)
    e.w32(vt2 + 0x128, sb)
    o1 = obj(c, 0x200, {0x128: sa})
    o2 = obj(c, 0x200, {0x128: sb})
    s114 = pystub(c, 6, this=True, side=lambda em, k: e.w32(me + 8, o2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    me = rnd(c, 0x40)
    e.w32(me + 8, o1)
    return [me]


def _g4dce70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    tab = e.r32(so + 0x9b)
    e.w32(tab + 8, obj(c, 0x80, {0x58: s58}))
    me = rnd(c, 0x80)
    return [me, r.choice([0, 1, _w(c)])]


def _g52b080(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    o1 = rnd(c, 0x40)
    o2 = rnd(c, 0x40)
    e.wbytes(o1 + 0x10, bytes([r.choice([0, 1, 0x80])]))
    e.wbytes(o2 + 0x10, bytes([1]))
    ret = r.choice([_w(c), 0x1000, 5])
    e.w32(o2, r.choice([0, 100, 0x1000 - 5, _w(c)]))
    e.w32(o2 + 4, r.choice([0, 4, 5, 6, 0x1000, _w(c)]))
    e.w32(o1, e.r32(o2))
    e.w32(o1 + 4, e.r32(o2 + 4))
    s = pystub(c, 2, this=True, side=lambda em, k: e.w32(me + 0x44, o2), ret=lambda em, k: ret)
    sysobj(c, slots={0x1c8: s})
    e.w32(me + 0x44, r.choice([o1, o1, o1, 0]))
    e.wbytes(me + 0x48, bytes([r.choice([0, 1, 9])]))
    return [me]


def _g5b6b30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sx = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x20), 0]))
    inner = obj(c, 0x40, {0x2c: sx})
    sr = pystub(c, 1, this=True, ret=lambda em, k: r.choice([None, 0]) if False else None)
    rr = _zeroed_obj(c, inner, r)
    sc = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rr, rr, 0]))
    ctr = obj(c, 0x40, {0x2c: sc})
    me = rnd(c, 0x80)
    e.w32(me + 0x48, ctr)
    return [me, _w(c), _w(c)]


def _zeroed_obj(c, inner, r):
    e = c.emu
    a = e.alloc(0xa0, 4)
    e.wbytes(a, bytes(r.getrandbits(8) for _ in range(0xa0)))
    e.w32(a + 4, inner)
    return a


def _g5f2fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    buf = rnd(c, 0x40)
    p = buf + 4 * r.randrange(0, 6)
    me = rnd(c, 0x20)
    e.w32(me + 8, p)
    e.w32(me + 0xc, p + r.choice([0, 1, 2, 3, 4, 0x10, -1 & 0xffffffff]))
    return [me, rnd(c, 0x10)]


S(0x5f55e0, 'GUESS pop typed records and release', 'thiscall', None, ret=None, gen=_g5f55e0, note='batch33059')
S(0x64f860, 'GUESS table lookup then child vcall 28 bool', 'thiscall', None, ret='al', gen=_g64f860, note='batch33059')
S(0x463940, 'GUESS reset via vcalls and field shuffle', 'thiscall', None, ret='eax', gen=_g463940, note='batch33059')
S(0x4870c0, 'GUESS table lookup 114 then child vcall 128', 'thiscall', None, ret='eax', gen=_g4870c0, note='batch33059')
S(0x4dce70, 'GUESS store word from table object lookup', 'thiscall', None, ret=None, gen=_g4dce70, note='batch33059')
S(0x52b080, 'GUESS time clamp via sysobj 1c8', 'thiscall', None, ret=None, gen=_g52b080, note='batch33059')
S(0x5b6b30, 'GUESS nested lookup mark', 'thiscall', None, ret=None, gen=_g5b6b30, note='batch33059')
S(0x5f2fc0, 'GUESS read word from stream with bound assert', 'thiscall', None, ret=None, gen=_g5f2fc0, note='batch33059')
