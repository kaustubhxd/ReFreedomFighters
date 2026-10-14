"""specs_s33070.py - h3 () batch 33070."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g46a810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x46a4f0, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.r32(me))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    s0 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', em.r32(me))))
    me = rnd(c, 0xa0)
    e.w32(me + 0x94, r.choice([obj(c, 0x40, {0: s0}), 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g48fa70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x49d2c0, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.r32(me + 0xc8))))
    s0 = pystub(c, 1, this=True)
    me = _zeroed(c, 0xae0, 0x40)
    for i in range(0x20):
        e.w32(me + 0x48 + 4 * i, r.choice([0, obj(c, 0x40, {0: s0})]) if r.random() < 0.3 else 0)
    e.w32(me + 0xc8, r.choice([0, _w(c)]))
    e.w32(me + 0xad0, _w(c) | 1)
    e.w32(me + 0xad8, _w(c) | 1)
    return [me]


def _g4cbee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4cc630, 1, this=True, side=lambda em, k: em.calllog.append(('s', 1)))
    me = rnd(c, 0x40)
    e.w32(me, r.choice([me + 4, _w(c)]))
    a = rnd(c, 0x40)
    e.w32(a, _w(c))
    return [me, r.choice([a, a, 0, me])]


def _g537200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    sb = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x100, 4)
    e.w32(vt2 + 0x58, sb)
    so = sysobj(c, table_slots={0x58: sa})
    tab = e.r32(so + 0x9b)
    sb4 = pystub(c, 1, this=True, side=lambda em, k: e.w32(tab, vt2), ret=lambda em, k: _w(c))
    e.w32(so + 0x190f, r.choice([obj(c, 0x100, {0xb4: sb4}), 0]))
    me = _zeroed(c, 0x5200, 0x40)
    e.w32(me + 0x51ad, _w(c))
    return [me]


def _g566fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x566f10, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5672c0, 1, this=True, side=lambda em, k: em.calllog.append(('l', em.r32(me + 0x188))))
    s1 = _zeroed(c, 0x13400, 0x40)
    s2 = _zeroed(c, 0x13400, 0x40)
    e.wbytes(s1 + 0x103f, bytes([r.choice([0, 1, 0x80])]))
    s4c = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0x94, s2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    me = _zeroed(c, 0x1a0, 0x1a0)
    e.w32(me + 0x94, r.choice([s1, s1, s1]))
    return [me]


def _g5f0db0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x200, 4)
    e.w32(vt2 + 0x130, sb)
    rr = obj(c, 0x200, {0x130: sa})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: rr)
    s114 = pystub(c, 5, this=True, deref={4: 1}, side=lambda em, k: e.w32(rr, vt2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58, 0x114: s114})
    return [_w(c), _w(c)]


def _g61a6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = pystub(c, 6, this=True, side=lambda em, k: em.calllog.append(('e', k)))
    g = obj(c, 0x200, {0x11c: s})
    e.w32(0x724a00, g)
    n = r.choice([0, 1, 2, 3, 5])
    b = rnd(c, 0x20)
    arr = rnd(c, 0x60)
    e.w32(b, n)
    e.w32(b + 8, arr)
    return [_w(c), b]


def _g46d700(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s300 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]))
    o = obj(c, 0x400, {0x300: s300})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: o)
    sysobj(c, table_slots={0x58: s58})
    sbc = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    sb8 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    p = obj(c, 0x200, {0xbc: sbc, 0xb8: sb8})
    s2f8 = pystub(c, 1, this=True, ret=lambda em, k: p)
    me = obj(c, 0x340, {0x2f8: s2f8})
    e.w32(me + 0x60, r.choice([0, _w(c), _w(c)]))
    return [me, r.choice([0, 1, 0x100, 0x1ff, _w(c)])]


S(0x46a810, 'GUESS dtor flags dispatch 98 with child', 'thiscall', None, ret='eax', gen=_g46a810, note='batch33070')
S(0x48fa70, 'GUESS release 32 objects and block', 'thiscall', None, ret=None, gen=_g48fa70, note='batch33070')
S(0x4cbee0, 'GUESS string assign from other', 'thiscall', None, ret='eax', gen=_g4cbee0, note='batch33070')
S(0x537200, 'GUESS table lookup twice or fallback', 'thiscall', None, ret='eax', gen=_g537200, note='batch33070')
S(0x566fd0, 'GUESS init loops then store lookup', 'thiscall', None, ret=None, gen=_g566fd0, note='batch33070')
S(0x5f0db0, 'GUESS fastcall lookup then vcall 130', 'fastcall', None, ret=None, gen=_g5f0db0, note='batch33070')
S(0x61a6b0, 'GUESS fastcall loop of vcalls 11c', 'fastcall', None, ret=None, gen=_g61a6b0, note='batch33070')
S(0x46d700, 'GUESS lookup check then child vcall bc/b8', 'thiscall', None, ret='eax', gen=_g46d700, note='batch33070')
