"""specs_s33069.py - h3 (Sonnet) batch 33069."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _assert(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g657860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r1 = rnd(c, 0x40)
    r2 = rnd(c, 0x100)
    s0c = pystub(c, 1, this=True, ret=lambda em, k: r1 if k == 0 else r2)
    s128 = pystub(c, 2, this=True, side=lambda em, k: em.calllog.append(('e', k)))
    me = obj(c, 0x200, {0xc: s0c, 0x128: s128})
    return [me, _w(c), rnd(c, 0x40), r.choice([0, 1, 2, 3, 5])]


def _g46cd60(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f8c0, 1, this=True)
    s = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    a = _zeroed(c, 0x100, 0x100)
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x1e0, s)
    c.emu.w32(a, vt)
    return [rnd(c, 0x100), a]


def _g4b07f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    s98 = pystub(c, 1, this=True)
    me = obj(c, 0x100, {0x98: s98})
    sa = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('a', 0x48)))
    sb = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('a', 0x40)))
    a = obj(c, 0x80, {0x48: sa, 0x40: sb})
    return [me, a]


def _g4d60e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = {}

    def iside(em, k):
        st['buf'] = em.arg32(0)
        em.calllog.append(('imp', k))
    e.w32(0x67642c, pystub(c, 3, pop=0, nullflag=(0,), side=iside))
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.r32(me + 0xd), em.rbytes(st['buf'] + 0x104, 1)[0])))
    s34 = pystub(c, 2, this=True, nullflag=(0,))
    me = _zeroed(c, 0x100, 0x100)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x34, s34)
    e.w32(me, vt)
    return [me]


def _g4f9c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s2dc = pystub(c, 1, this=True)
    p = obj(c, 0x300, {0x2dc: s2dc})
    s2c4 = pystub(c, 0, this=True, ret=lambda em, k: p)
    s310 = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    me = _zeroed(c, 0x320, 0x100)
    vt = e.alloc(0x400, 4)
    e.w32(vt + 0x2c4, s2c4)
    e.w32(vt + 0x310, s310)
    e.w32(me, vt)
    e.w32(me + 0x70, r.choice([0x20, 0x20, 0, 1, _w(c)]))
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58})
    return [me]


def _g575d00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = _zeroed(c, 0x300, 0x100)
    cnt = [0]
    vals = [r.choice([0, 1, _w(c)]) for _ in range(5)]

    def ret2f0(em, k):
        return vals[k % 5]
    s2f0 = pystub(c, 0, this=True, ret=ret2f0)
    pobj = obj(c, 0x300, {0x2f0: s2f0})
    s84 = pystub(c, 0, this=True, ret=lambda em, k: pobj)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x84, s84)
    e.w32(me, vt)
    for i in range(5):
        q = me + 0x240 + 0x24 * i
        e.w32(q - 0x1c, r.choice([vals[i], vals[i], _w(c)]))
        sbc = pystub(c, 1, this=True)
        e.w32(q, r.choice([obj(c, 0x100, {0xbc: sbc}), 0]))
    return [me]


def _g5fa220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    n = r.choice([0, 1, 2, 3, 5])
    arr = rnd(c, 0x40)
    v = rnd(c, 0x20)
    e.w32(v, arr)
    e.w32(v + 8, n)
    a = r.choice([e.r32(arr + 4 * k) for k in range(max(n, 1))] + [_w(c)])
    me = rnd(c, 0x20)
    e.w32(me + 4, v)
    return [me, a]


def _g452fa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43de70, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    s0 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', em.r32(me))))
    me = rnd(c, 0x80)
    e.w32(me + 0x52, r.choice([obj(c, 0x40, {0: s0}), 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


S(0x657860, 'GUESS lookup two levels then n vcalls 128', 'thiscall', None, ret=None, gen=_g657860, note='batch33069')
S(0x46cd60, 'GUESS call then two conditional copies', 'thiscall', None, ret=None, gen=_g46cd60, note='batch33069')
S(0x4b07f0, 'GUESS flag assert then vcalls', 'thiscall', None, ret='al', gen=_g4b07f0, note='batch33069')
S(0x4d60e0, 'GUESS copy string then free and vcall 34', 'thiscall', None, ret=None, gen=_g4d60e0, note='batch33069')
S(0x4f9c00, 'GUESS lookup then vcall 310 with junk args', 'thiscall', None, ret=None, gen=_g4f9c00, note='batch33069')
S(0x575d00, 'GUESS five entry notify by compare', 'thiscall', None, ret=None, gen=_g575d00, note='batch33069')
S(0x5fa220, 'GUESS find index or assert', 'thiscall', None, ret='eax', gen=_g5fa220, note='batch33069')
S(0x452fa0, 'GUESS dtor flags dispatch 62 with child', 'thiscall', None, ret='eax', gen=_g452fa0, note='batch33069')
