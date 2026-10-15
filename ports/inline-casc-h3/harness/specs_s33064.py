"""specs_s33064.py - h3 (Sonnet) batch 33064."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g462a20(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x463030, 2, this=True, ret=lambda em, k: _w(c))
    s114 = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    s128 = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x140, {0x128: s128})
    return [me, _w(c), _w(c), _w(c), rnd(c, 0x20)]


def _g474730(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x466eb0, 2, this=True)
    sa = pystub(c, 2, this=True, side=lambda em, k: em.calllog.append(('v', k)), ret=lambda em, k: _w(c))
    a = obj(c, 0x40, {0x18: sa})
    return [rnd(c, 0x80), a, _w(c)]


def _g4b05d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x44b610, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x44b740, 1, pop=0, side=lambda em, k: em.calllog.append(('o', 2)))
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x20), 0]))
    sysobj(c, table_slots={0x60: s60})
    me = rnd(c, 0x100)
    v = r.getrandbits(16)
    e.wbytes(me + 0xdc, v.to_bytes(2, 'little'))
    a = r.choice([v, v, v | (r.getrandbits(16) << 16), _w(c)])
    return [me, a, _w(c)]


def _g4f6860(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e6330, 1, this=True, side=lambda em, k: em.calllog.append(('o', 0)))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]), side=lambda em, k: em.calllog.append(('e', k)))
    return [rnd(c, 0x100), _w(c), rnd(c, 0x20)]


def _g52b4a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45f3c0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    hook_rec(c, 0x52b430, 1, this=True)
    s48 = pystub(c, 1, this=True)
    a = obj(c, 0x80, {0x48: s48})
    me = rnd(c, 0x100)
    return [me, a]


def _g57f660(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x563110, 2, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x57f750, 0, this=True, side=lambda em, k: em.calllog.append(('o', 2)))
    s34c = pystub(c, 5, this=True)
    p = obj(c, 0x400, {0x34c: s34c})
    s84 = pystub(c, 0, this=True, ret=lambda em, k: p)
    me = obj(c, 0x100, {0x84: s84})
    return [me, _w(c), _w(c)]


def _g5b9730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s128 = pystub(c, 3, this=True, deref={1: 2})
    ch = obj(c, 0x200, {0x128: s128})
    s84 = pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, _w(c), _w(c)]))
    me = obj(c, 0x80, {0x84: s84})
    pp = rnd(c, 0x40)
    e.w32(me + 0x54, pp)
    e.w32(me + 0x44, ch)
    return [me]


def _g5f3160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    buf = rnd(c, 0x40)
    p = buf + 4 * r.randrange(0, 8)
    me = rnd(c, 0x20)
    e.w32(me + 8, p)
    e.w32(me + 0xc, p + r.choice([0, 1, 3, 4, 5, 8, 0x40, 0xffffffff]) & 0xffffffff)
    return [me, r.choice([0, 1, 0x1ff, 0xff, _w(c)])]


S(0x462a20, 'GUESS lookup then table lookup and vcall 128', 'thiscall', None, ret='al', gen=_g462a20, note='batch33064')
S(0x474730, 'GUESS call then two arg vcalls 18', 'thiscall', None, ret='al', gen=_g474730, note='batch33064')
S(0x4b05d0, 'GUESS match id then release', 'thiscall', None, ret='eax', gen=_g4b05d0, note='batch33064')
S(0x4f6860, 'GUESS init fields from queries on b', 'thiscall', None, ret=None, gen=_g4f6860, note='batch33064')
S(0x52b4a0, 'GUESS check then arg vcall 48', 'thiscall', None, ret='al', gen=_g52b4a0, note='batch33064')
S(0x57f660, 'GUESS calls then vcall 34c with stack zero', 'thiscall', None, ret='al', gen=_g57f660, note='batch33064')
S(0x5b9730, 'GUESS update child with stack pair', 'thiscall', None, ret=None, gen=_g5b9730, note='batch33064')
S(0x5f3160, 'GUESS write byte as dword with bound assert', 'thiscall', None, ret=None, gen=_g5f3160, note='batch33064')
