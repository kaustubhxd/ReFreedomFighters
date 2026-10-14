"""specs_s33068.py - h3 () batch 33068."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _logsetup(c, slot):
    e = c.emu
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {slot: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _assert(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g654e50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    e.w32(0x6761f0, pystub(c, 0, side=lambda em, k: em.calllog.append(('imp', 0))))
    s230 = pystub(c, 3, this=True, side=lambda em, k: em.calllog.append(('v', 0x230)))
    sc8a = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0xc8, em.r32(me + 0x1153), em.rbytes(me + 0x1185, 1)[0])))
    sc8b = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0xc9)))
    vt2 = e.alloc(0x300, 4)
    e.w32(vt2 + 0xc8, sc8b)
    vt1 = e.alloc(0x300, 4)
    e.w32(vt1 + 0x230, s230)
    e.w32(vt1 + 0xc8, sc8a)
    me = _zeroed(c, 0x1200, 0x100)
    e.w32(me, vt1)
    e.w32(me + 0x137, r.choice([0, 1, _w(c)]))
    e.w32(me + 0x1153, _w(c))
    e.wbytes(me + 0x1184, bytes([r.choice([1, 0xff])]))
    e.wbytes(me + 0x1185, bytes([r.choice([1, 0xff])]))
    # the import swaps the vtable to prove it is read after the import
    e.w32(0x6761f0, pystub(c, 0, side=lambda em, k: (em.calllog.append(('imp', 0)), e.w32(me, vt2))))
    return [me, _w(c), _w(c), _w(c)]


def _g45c0e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    arr = rnd(c, 0x40)
    i = r.randrange(0, 8)
    for k in range(8):
        e.w32(arr + 4 * k, r.choice([0, _w(c)]))
    s40 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', em.r32(arr + 4 * i))))
    rr = obj(c, 0x80, {0x40: s40})
    s20 = pystub(c, 0, this=True, ret=lambda em, k: rr)
    so = sysobj(c)
    e.w32(so + 0x190f, obj(c, 0x80, {0x20: s20}))
    me = rnd(c, 0x80)
    e.w32(me + 0x40, arr)
    return [me, i]


def _g46caa0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f8c0, 1, this=True)
    s = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    a = obj(c, 0x100, {0x1e0: s})
    return [rnd(c, 0x100), a]


def _g4fa120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45f070, 1, this=True, side=lambda em, k: em.calllog.append(('t', em.r32(me + 0x6c))))
    s2f4 = pystub(c, 2, this=True)
    ch = obj(c, 0x300, {0x2f4: s2f4})
    pick = r.choice([ch, ch, 0])
    s2c4 = pystub(c, 0, this=True, ret=lambda em, k: pick)
    me = obj(c, 0x300, {0x2c4: s2c4})
    e.w32(me + 0x6c, _w(c))
    return [me, r.choice([0, 1, 0x100, 0xff, _w(c)])]


def _g5670a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5626c0, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x563510, 1, this=True, side=lambda em, k: em.calllog.append(('o', 2)))
    hook_rec(c, 0x563610, 1, this=True, side=lambda em, k: em.calllog.append(('o', 3)))
    hook_rec(c, 0x566f10, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5672c0, 1, this=True)
    s1 = _zeroed(c, 0x13400, 0x40)
    s2 = _zeroed(c, 0x13400, 0x40)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s4c = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0x94, s2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58, 0x4c: s4c})
    me = _zeroed(c, 0x1a0, 0x1a0)
    e.w32(me + 0x94, s1)
    return [me]


def _g5c94a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s1e0 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    child = rnd(c, 0x10)
    e.w32(child + 4, r.choice([0, 0, 1, _w(c)]))
    o = obj(c, 0x100, {0x1e0: s1e0})
    e.w32(o + 0x54, r.choice([child, child, 0]))
    s58 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([o, o, o, 0]))
    sysobj(c, table_slots={0x58: s58})
    return [_w(c)]


def _g602cd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logsetup(c, 0x2c)
    _assert(c)
    me = rnd(c, 0x20)
    e.wbytes(me + 4, bytes([r.choice([0, 2, 2, 1, 3, 0xff])]))
    return [me, rnd(c, 8)]


def _g652840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        buf = em.arg32(3)
        flags = r.choice([0, 1, 0x7f, 0x100, 0x7fffff00 | r.getrandbits(7)])
        for i in range(10):
            em.w32(buf + 4 * i, _w(c))
        em.w32(buf + 4, flags)
    e.w32(0x67603c, pystub(c, 1, ret=lambda em, k: _w(c)))
    e.w32(0x676030, pystub(c, 4, nullflag=(3,), side=side))
    return [_w(c)]


S(0x654e50, 'GUESS vcall 230 then clear bits and import', 'thiscall', None, ret=None, gen=_g654e50, note='batch33068')
S(0x45c0e0, 'GUESS release array entry via child vcall', 'thiscall', None, ret=None, gen=_g45c0e0, note='batch33068')
S(0x46caa0, 'GUESS call then conditional copy six dwords', 'thiscall', None, ret=None, gen=_g46caa0, note='batch33068')
S(0x4fa120, 'GUESS toggle with vcalls and flag', 'thiscall', None, ret=None, gen=_g4fa120, note='batch33068')
S(0x5670a0, 'GUESS init sequence with table lookups', 'thiscall', None, ret=None, gen=_g5670a0, note='batch33068')
S(0x5c94a0, 'GUESS check object kind and child state', 'stdcall', None, ret='al', gen=_g5c94a0, note='batch33068')
S(0x602cd0, 'GUESS set value in kind 0/2 else log', 'thiscall', None, ret='eax', gen=_g602cd0, note='batch33068')
S(0x652840, 'GUESS import query then throw on flag', 'stdcall', None, ret=None, gen=_g652840, note='batch33068')
