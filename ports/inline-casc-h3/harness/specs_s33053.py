"""specs_s33053.py - h3 () batch 33053."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g574250(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562d90, 1, this=True, ret=lambda em, k: _w(c))
    s300 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    child = obj(c, 0x40, {0x300: s300})
    s84 = pystub(c, 0, this=True, ret=lambda em, k: child)
    me = obj(c, 0x40, {0x84: s84})
    return [me, r.choice([0x105, 0x105, 0x104, 0, _w(c)])]


def _g597640(c):
    clear_hooks(c)
    e = c.emu
    me = _zeroed(c, 0x1d40, 0x40)
    o1 = rnd(c, 0x20)
    o2 = rnd(c, 0x20)
    e.w32(me + 0x1d0b, o1)
    hook_rec(c, 0x593f40, 1, this=True, side=lambda em, k: e.w32(me + 0x1d0b, o2))
    hook_rec(c, 0x594040, 2, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x596d70, 2, this=True)
    return [me]


def _g5a1c20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467060, 3, this=True, ret=lambda em, k: _w(c))
    s = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x980, {0x684: s})
    arr = rnd(c, 0x400)
    e.w32(me + 0x936, arr)
    return [me, r.choice([0, 1, 5, 0xff, 0x100, 0x1ff, _w(c)])]


def _g5f0420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5f0380, 0, this=True)
    so = sysobj(c)
    s = pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    e.w32(so + 0x1907, obj(c, 0x40, {0x2c: s}))
    return [rnd(c, 0x40)]


def _g46d040(c):
    clear_hooks(c)
    hook_rec(c, 0x46cee0, 1, this=True)
    hook_rec(c, 0x4e0fd0, 1, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True)
    return [rnd(c, 0x100), rnd(c, 0x40)]


def _g46eff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x471680, 0, this=True)
    me = rnd(c, 0x80)
    c1 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0x44, c2))
    c2s = pystub(c, 1, this=True)
    ch1 = obj(c, 0x340, {0xbc: c1, 0x300: c2s})
    c2 = obj(c, 0x340, {0xbc: c1, 0x300: c2s})
    e.w32(me + 0x44, ch1)
    e.wbytes(me + 0x51, bytes([r.choice([0, 1, 0xff])]))
    return [me]


def _g470640(c):
    clear_hooks(c)
    hook_rec(c, 0x4705a0, 1, this=True)
    s = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    a = obj(c, 0x80, {0x6c: s})
    return [rnd(c, 0x100), a]


def _g48aad0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        if r.random() < 0.8:
            em.w32(em.arg32(1), _w(c))
    s = pystub(c, 2, this=True, nullflag=(1,), side=side, ret=lambda em, k: _w(c))
    me = rnd(c, 0x20)
    e.w32(me, obj(c, 0x100, {0x88: s}))
    return [me]


S(0x574250, 'GUESS special id vcall else tail', 'thiscall', None, ret='eax', gen=_g574250, note='batch33053')
S(0x597640, 'GUESS init sequence with child reread', 'thiscall', None, ret=None, gen=_g597640, note='batch33053')
S(0x5a1c20, 'GUESS vcall 684 then 467060 with indexed elem', 'thiscall', None, ret='eax', gen=_g5a1c20, note='batch33053')
S(0x5f0420, 'GUESS sys vcall 2c then tail', 'thiscall', None, ret=None, gen=_g5f0420, note='batch33053')
S(0x46d040, 'GUESS three calls with arg as this', 'thiscall', None, ret=None, gen=_g46d040, note='batch33053')
S(0x46eff0, 'GUESS child vcalls then tail if flag', 'thiscall', None, ret=None, gen=_g46eff0, note='batch33053')
S(0x470640, 'GUESS call then arg vcall 6c return 1', 'thiscall', None, ret='al', gen=_g470640, note='batch33053')
S(0x48aad0, 'GUESS vcall 88 with out local', 'thiscall', None, ret='eax', gen=_g48aad0, note='batch33053')
