"""specs_s33062.py - h3 () batch 33062."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _gdisp(base):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 0, this=True, side=lambda em, k: em.calllog.append(('b', 0)))
        hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
        hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
        return [rnd(c, 0x40), r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]
    return g


def _g4b4160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    so = sysobj(c)
    s14 = pystub(c, 1, this=True)
    e.w32(so + 0x1907, r.choice([obj(c, 0x40, {0x14: s14}), 0]))
    me = rnd(c, 0xa0)
    e.w32(me + 0x90, r.choice([_w(c), 0]))
    e.w32(me + 0x94, r.choice([_w(c), 0]))
    return [me]


def _g5613a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 2, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))
    me = rnd(c, 0xe0)
    e.w32(me + 0xd8, r.choice([0, 1, 5, 7, 8, 9, 0x7fffffff, 0xffffffff & -1]))
    return [me, _w(c), _w(c)]


def _g5b9830(c):
    clear_hooks(c)
    r = c.rng
    s88 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('s', 88)))
    s8c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x100, {0x88: s88, 0x8c: s8c})
    se4 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    sysobj(c, slots={0xe4: se4})
    return [me]


def _g5e1510(c):
    clear_hooks(c)
    r = c.rng

    def lg(i):
        return lambda em, k: em.calllog.append(('c', i, em.reg('ecx')))
    hook_rec(c, 0x480fd0, 0, this=True, side=lg(0))
    hook_rec(c, 0x4878d0, 0, this=True, side=lg(1))
    hook_rec(c, 0x634273, 2, pop=0, side=lg(2))
    return [rnd(c, 0x5a0), r.choice([0, 1, 2, 3, _w(c)])]


S(0x465720, 'GUESS dtor flags dispatch 465720', 'thiscall', None, ret='eax', gen=_gdisp(0x465660), note='batch33062')
S(0x481180, 'GUESS dtor flags dispatch 481180', 'thiscall', None, ret='eax', gen=_gdisp(0x480ff0), note='batch33062')
S(0x4faca0, 'GUESS dtor flags dispatch 4faca0', 'thiscall', None, ret='eax', gen=_gdisp(0x4ee4e0), note='batch33062')
S(0x52a6c0, 'GUESS dtor flags dispatch 52a6c0', 'thiscall', None, ret='eax', gen=_gdisp(0x52a600), note='batch33062')
S(0x4b4160, 'GUESS release sysobj hook and two members', 'thiscall', None, ret=None, gen=_g4b4160, note='batch33062')
S(0x5613a0, 'GUESS push pair or log full', 'thiscall', None, ret='eax', gen=_g5613a0, note='batch33062')
S(0x5b9830, 'GUESS key checks vcalls', 'thiscall', None, ret='eax', gen=_g5b9830, note='batch33062')
S(0x5e1510, 'GUESS dtor with four members', 'thiscall', None, ret='eax', gen=_g5e1510, note='batch33062')
