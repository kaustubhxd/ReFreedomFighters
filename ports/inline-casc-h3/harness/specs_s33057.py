"""specs_s33057.py - h3 () batch 33057."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g48f840(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x4cc1d0, 0, this=True, ret=lambda em, k: _w(c))
    s12a = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    s12b = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    o1 = obj(c, 0x140, {0x12c: s12a})
    o2 = obj(c, 0x140, {0x12c: s12b})
    s4 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0x104, o2), ret=lambda em, k: _w(c))
    me = obj(c, 0x140, {4: s4})
    e.w32(me + 0x104, o1)
    return [me, _w(c)]


def _g4afd90(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6352f0, 1, this=True, nullflag=(0,), side=lambda em, k: (em.w32(em.arg32(0), _w(c)) if r.random() < 0.7 else None))
    s84 = pystub(c, 1, this=True, deref={0: 1})
    me = obj(c, 0x100, {0x84: s84})
    return [me, _w(c)]


def _g4b8e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s84 = pystub(c, 0, this=True)
    s88 = pystub(c, 0, this=True)
    me = obj(c, 0x100, {0x84: s84, 0x88: s88})
    v = r.getrandbits(16)
    e.wbytes(me + 0x48, v.to_bytes(2, 'little'))
    e.wbytes(me + 0x4a, r.choice([v, v, r.getrandbits(16)]).to_bytes(2, 'little'))
    a = r.choice([v, v, v | (r.getrandbits(16) << 16), r.getrandbits(32)])
    return [me, a, _w(c)]


def _g5396d0(c):
    clear_hooks(c)
    e = c.emu
    me = _zeroed(c, 0x5400, 0x80)
    e.w32(me + 0x51ad, _w(c) | 1)
    e.wbytes(me + 0x5147, bytes([c.rng.randrange(1, 256), c.rng.randrange(1, 256)]))

    def logger(i):
        return lambda em, k: em.calllog.append(('s', i, em.r32(me + 0x51ad), em.rbytes(me + 0x5147, 2)[0], em.rbytes(me + 0x15, 1)[0]))
    sa = pystub(c, 0, this=True, side=logger(1))
    sb = pystub(c, 0, this=True, side=logger(2))
    sc = pystub(c, 1, this=True, side=logger(3))
    vta = e.alloc(0x40, 4)
    e.w32(vta + 0xc, sa)
    vtb = e.alloc(0x40, 4)
    e.w32(vtb + 0xc, sb)
    vtm = e.alloc(0x100, 4)
    e.w32(vtm + 0xf4, sc)
    e.w32(me, vtm)
    e.w32(me + 0x53b2, vta)
    e.w32(me + 0x5306, vtb)
    return [me]


def _g59a7a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x597640, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x597f70, 0, this=True, ret=lambda em, k: _w(c))
    me = rnd(c, 0x1e00)
    return [me, r.choice([0, 1, 0x100, 0xff, _w(c)])]


def _g5eb7a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [rnd(c, 0x40), r.choice([0, 1, 2, 0xffffffff, _w(c)])]


def _g656360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    s18 = pystub(c, 2, this=True)
    child = obj(c, 0x80, {0x18: s18})
    s20 = pystub(c, 0, this=True, ret=lambda em, k: child)
    e.w32(so + 0x190f, obj(c, 0x80, {0x20: s20}))
    return [_w(c), r.choice([0, 1, 2, 7, 0x20000000, 0x40000000, 0x55555555, _w(c)])]


def _g47fb30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    s0 = pystub(c, 1, this=True)
    child = obj(c, 0x40, {0: s0})
    me = rnd(c, 0x40)
    e.w32(me + 4, r.choice([child, child, 0]))
    return [me, r.choice([0, 1, 2, 3, _w(c)])]


S(0x48f840, 'GUESS vcall 4, 4cc1d0, child vtable 12c reread', 'thiscall', None, ret='eax', gen=_g48f840, note='batch33057')
S(0x4afd90, 'GUESS clear flag, out local, vcall 84', 'thiscall', None, ret='al', gen=_g4afd90, note='batch33057')
S(0x4b8e00, 'GUESS match ids vcall 84/88', 'thiscall', None, ret='eax', gen=_g4b8e00, note='batch33057')
S(0x5396d0, 'GUESS reset state and subobject vcalls', 'thiscall', None, ret=None, gen=_g5396d0, note='batch33057')
S(0x59a7a0, 'GUESS select 597640 / 597f70', 'thiscall', None, ret='eax', gen=_g59a7a0, note='batch33057')
S(0x5eb7a0, 'GUESS set mode 0/1 else assert', 'thiscall', None, ret='eax', gen=_g5eb7a0, note='batch33057')
S(0x656360, 'GUESS sysobj child vcall 18 with count*24', 'stdcall', None, ret=None, gen=_g656360, note='batch33057')
S(0x47fb30, 'GUESS scalar deleting dtor with child', 'thiscall', None, ret='eax', gen=_g47fb30, note='batch33057')
