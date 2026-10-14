"""specs_s33067.py - h3 () batch 33067."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4a90b0(c):
    clear_hooks(c)
    r = c.rng
    s1e0 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))
    s21c = pystub(c, 1, this=True, deref={0: 3})
    return [obj(c, 0x300, {0x1e0: s1e0, 0x21c: s21c})]


def _g4c5620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4c5770, 1, this=True)

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(1), _w(c))
    s88 = pystub(c, 2, this=True, nullflag=(1,), side=side)
    p = obj(c, 0x200, {0x88: s88})
    s138 = pystub(c, 0, this=True, ret=lambda em, k: p)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x138: s138, 0x58: s58})
    return [rnd(c, 0x80)]


def _g4daa20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sb4 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    ch = obj(c, 0x100, {0xb4: sb4})
    me = rnd(c, 0x80)
    e.w32(me + 0x54, r.choice([ch, ch, 0]))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.w32(me + 0x54, ch)
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [me, r.choice([0, 1, 0x100, 0xff, 0x101, _w(c)])]


def _g4f86c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4ccf60, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x4cbec0, 0, this=True, side=lambda em, k: em.calllog.append(('o', 2)))
    hook_rec(c, 0x43ea20, 0, this=True, side=lambda em, k: em.calllog.append(('o', 3)))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    return [rnd(c, 0x130), r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g526ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s30 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('s', 0x30, em.r32(me + 4))))
    s28 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('s', 0x28)))
    s24 = pystub(c, 0, this=True, side=lambda em, k: (em.calllog.append(('s', 0x24)), e.w32(me + 4, _w(c))))
    me = obj(c, 0x80, {0x30: s30, 0x28: s28, 0x24: s24})
    e.w32(me + 0x19, r.choice([2, 2, 0, 1, 3]))
    e.wbytes(me + 0x18, bytes([r.choice([0, 1, 0x80])]))
    return [me, rnd(c, 8)]


def _g549150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', k)))
    a = obj(c, 0x80, {0x3c: s})
    me = rnd(c, 0x80)
    e.w32(me + 4, r.choice([0, 4, 0x44, 0x40, _w(c)]))
    return [me, a]


def _g5769c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x200, 4)
    e.w32(vt2 + 0x12c, sb)
    c1 = obj(c, 0x200, {0x12c: sa})
    c2 = obj(c, 0x200, {0x12c: sb})
    s114 = pystub(c, 5, this=True, side=lambda em, k: e.w32(me + 0x44, c2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    s2f8 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    rr = obj(c, 0x300, {0x2f8: s2f8})
    s84 = pystub(c, 0, this=True, ret=lambda em, k: rr)
    me = obj(c, 0x220, {0x84: s84})
    e.w32(me + 0x44, c1)
    e.w32(me + 0x215, _w(c))
    return [me]


def _g5e90f0(c):
    clear_hooks(c)
    r = c.rng
    s5c = pystub(c, 3, this=True)

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(1), _w(c))
    s88 = pystub(c, 2, this=True, deref={1: 1}, side=side)
    p = obj(c, 0x200, {0x88: s88, 0x5c: s5c})
    s138 = pystub(c, 0, this=True, ret=lambda em, k: p)
    sysobj(c, table_slots={0x138: s138})
    return [rnd(c, 0x40)]


S(0x4a90b0, 'GUESS query then vcall 21c with float vec', 'stdcall', None, ret=None, gen=_g4a90b0, note='batch33067')
S(0x4c5620, 'GUESS table out local then store and call', 'thiscall', None, ret=None, gen=_g4c5620, note='batch33067')
S(0x4daa20, 'GUESS flag selects tail vcall b4', 'thiscall', None, ret='eax', gen=_g4daa20, note='batch33067')
S(0x4f86c0, 'GUESS dtor flags dispatch 1df', 'thiscall', None, ret='eax', gen=_g4f86c0, note='batch33067')
S(0x526ff0, 'GUESS state query with vcall chain', 'thiscall', None, ret='al', gen=_g526ff0, note='batch33067')
S(0x549150, 'GUESS pass four fields to arg vcall 3c', 'thiscall', None, ret='al', gen=_g549150, note='batch33067')
S(0x5769c0, 'GUESS table lookup then vcall 12c and 2f8', 'thiscall', None, ret='eax', gen=_g5769c0, note='batch33067')
S(0x5e90f0, 'GUESS table out local then vcall 5c', 'thiscall', None, ret=None, gen=_g5e90f0, note='batch33067')
