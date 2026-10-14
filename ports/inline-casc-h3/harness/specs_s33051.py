"""specs_s33051.py - h3 () batch 33051."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _pair(c, ret5003=None):
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rnd(c, 0x20))
    hook_rec(c, 0x5002f0, 1, this=True, ret=lambda em, k: _w(c))


def _g55ace0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x59ffc0, 0, this=True, ret=lambda em, k: _w(c))
    _pair(c)
    me = rnd(c, 0x100)
    e.w32(me + 0x1c, rnd(c, 0x40))
    a = rnd(c, 0x20)
    e.w32(a + 8, rnd(c, 0x20))
    return [me, a]


def _g5582e0(c):
    clear_hooks(c)
    e = c.emu
    r = c.rng
    hook_rec(c, 0x59dfd0, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x1ff, _w(c)]))
    _pair(c)
    me = rnd(c, 0x100)
    e.w32(me + 0x1c, rnd(c, 0x40))
    a = rnd(c, 0x20)
    e.w32(a + 8, rnd(c, 0x20))
    return [me, a]


def _g519610(c):
    clear_hooks(c)
    e = c.emu
    s358 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    child = obj(c, 0x40, {0x358: s358})
    _pair(c)
    me = rnd(c, 0x100)
    e.w32(me + 0x14, child)
    a = rnd(c, 0x20)
    e.w32(a + 8, rnd(c, 0x20))
    return [me, a]


def _g474410(c):
    clear_hooks(c)
    r = c.rng
    s300 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    r2 = obj(c, 0x40, {0x300: s300})
    s2e8 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([r2, r2, 0]))
    r1 = obj(c, 0x40, {0x2e8: s2e8})
    s10 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([r1, r1, 0]))
    return [obj(c, 0x40, {0x10: s10})]


def _g57c360(c):
    clear_hooks(c)
    hook_rec(c, 0x563110, 2, this=True)
    s = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x100, {0xf8: s}), _w(c), _w(c)]


def _gdbl(off):
    def g(c):
        clear_hooks(c)
        st = {}

        def ret(em, k):
            if k == 0:
                return rnd(c, 0xa0)
            return _w(c)
        s = pystub(c, 1, this=True, ret=ret)
        return [obj(c, 0x40, {0xc: s}), _w(c)]
    return g


def _g46b730(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4711f0, 2, this=True)
    s35c = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, _w(c)]))
    s374 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x400, {0x35c: s35c, 0x374: s374})]


S(0x55ace0, 'GUESS pair 5003d0/5002f0 with 59ffc0', 'thiscall', None, ret='eax', gen=_g55ace0, note='batch33051')
S(0x474410, 'GUESS vcall chain 10, 2e8, 300', 'thiscall', None, ret='eax', gen=_g474410, note='batch33051')
S(0x519610, 'GUESS pair 5003d0/5002f0 with vcall 358', 'thiscall', None, ret='eax', gen=_g519610, note='batch33051')
S(0x5582e0, 'GUESS pair 5003d0/5002f0 with 59dfd0', 'thiscall', None, ret='eax', gen=_g5582e0, note='batch33051')
S(0x57c360, 'GUESS call 563110 then vcall f8 return 0', 'thiscall', None, ret='al', gen=_g57c360, note='batch33051')
S(0x656f40, 'GUESS vcall c twice (+0x94)', 'thiscall', None, ret='eax', gen=_gdbl(0x94), note='batch33051')
S(0x656fa0, 'GUESS vcall c twice (+0x84)', 'thiscall', None, ret='eax', gen=_gdbl(0x84), note='batch33051')
S(0x46b730, 'GUESS conditional vcalls then 4711f0', 'thiscall', None, ret=None, gen=_g46b730, note='batch33051')
