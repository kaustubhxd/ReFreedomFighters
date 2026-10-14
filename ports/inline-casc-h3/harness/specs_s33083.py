"""specs_s33083.py - h3 () batch 33083: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fl(c, lo=-10.0, hi=10.0):
    return F(c.fv(lo, hi, 0.25))


def _fb(c, lo=-10.0, hi=10.0):
    return _b(c.fv(lo, hi, 0.25))


def _setlog(c, argn, tag):
    e = c.emu
    r = c.rng
    slog = pystub(c, argn, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


_ZS = [0, 0x80000000, 0x7fc00000, _b(1.0), _b(2.0), 0x00000001]


def _g527270(c):
    clear_hooks(c)
    r = c.rng
    _setlog(c, 2, 'l')
    a = r.choice(_ZS + [_fb(c), 0, 0, 0])
    return [rnd(c, 0x30), a, _w(c), _w(c)]


def _g5d5ea0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x80), rnd(c, 0x10)]


def _g46b5d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0xd0)
    s = r.choice([0.0, 1.0, -2.0, c.fv(-5, 5, 0.1)])
    en = r.choice([s, s + 1.0, s + 4.0, s - 1.0, c.fv(-5, 5, 0.1)])
    t = r.choice([s, en, (s + en) / 2, s - 1, en + 1, c.fv(-8, 8, 0.1), c.fv(-8, 8, 0.1), float('nan')])
    e.w32(me + 0xb0, _b(s) if s == s else 0x7fc00000)
    e.w32(me + 0xb4, _b(en) if en == en else 0x7fc00000)
    e.w32(me + 0xbc, r.choice([_fb(c), _b(-3.5), 0x80000000, 0x7fc00000, _b(1.0)]))
    return [me, _w(c), F(t) if t == t else F(float('nan'))]


def _g4b41b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x80)
    e.w32(p + 0x70, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _b(-1.0), _fb(c)]))
    flag = r.random() < 0.8
    s = pystub(c, 1, this=True, ret=lambda em, k: p if flag else 0)
    sysobj(c, table_slots={0x60: s})
    sa0 = pystub(c, 0, this=True)
    s68 = pystub(c, 2, this=True)
    me = obj(c, 0x200, {0xa0: sa0, 0x68: s68})
    e.wbytes(me + 0x181, bytes([r.choice([0, 1, 0xff])]))
    e.w32(me + 0x64, r.choice([0, 1, _w(c)]))
    e.w32(me + 0x6c, r.choice([0, 1, _w(c)]))
    return [me]


def _g4f7520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sb8 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sac = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x40, {0xb8: sb8, 0xac: sac})
    so = sysobj(c)
    e.w32(so + 0x190f, o)
    me = rnd(c, 0xb0)
    e.wbytes(me + 0xa7, bytes([r.choice([0, 1, 0xff])]))
    a = r.choice([0, 1, 0xffffffff, 0x80000000, 0x7fffffff, 0x1000001, 0xfffffff0, _w(c), _w(c), r.getrandbits(16)])
    return [me, a]


def _two_ptr(c):
    pa, pb = rnd(c, 8), rnd(c, 8)
    r = c.rng
    e = c.emu
    e.w32(pb, r.choice([0, 1, _w(c), 0x80000000]))
    e.w32(pa, r.choice([0, 1, _w(c), 0x80000000]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: pa if k % 2 == 1 else pb)


def _g51aaa0(c):
    clear_hooks(c)
    _two_ptr(c)
    s = pystub(c, 2, this=True)
    q = obj(c, 0x10, {0x364: s})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, q)
    return [me, rnd(c, 0x10)]


def _g51ec70(c):
    clear_hooks(c)
    _two_ptr(c)
    s = pystub(c, 3, this=True)
    q = rnd(c, 0x2a0)
    vt = c.emu.alloc(0x10, 4)
    c.emu.w32(vt, s)
    c.emu.w32(q + 0x29a, vt)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, q)
    return [me, rnd(c, 0x10)]


def _g5f4110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3, 'l')
    _hook(c)
    me = rnd(c, 0x10)
    e.wbytes(me + 4, bytes([r.choice([2, 2, 2, 0, 1, 3, 0xff])]))
    e.w32(me, _fb(c))
    d = rnd(c, 4)
    e.w32(d, r.choice([_fb(c), 0, 0x80000000, 0x7fc00000, _b(1.0)]))
    return [me, d]


S(0x527270, 'GUESS set three floats, log when first is zero', 'thiscall', None, ret=None, gen=_g527270, note='batch33083')
S(0x5d5ea0, 'GUESS read stream: 3 floats, 3 dwords', 'thiscall', None, ret=None, gen=_g5d5ea0, note='batch33083')
S(0x46b5d0, 'GUESS linear fade weight times scale', 'thiscall', None, ret='st0', gen=_g46b5d0, note='batch33083')
S(0x4b41b0, 'GUESS maybe slot 0xa0 then slot 0x68(0x10,0)', 'thiscall', None, ret=None, gen=_g4b41b0, note='batch33083')
S(0x4f7520, 'GUESS store u32 and push as float to engine object', 'thiscall', None, ret=None, gen=_g4f7520, note='batch33083')
S(0x51aaa0, 'GUESS float and bool to slot 0x364', 'thiscall', None, ret=None, gen=_g51aaa0, note='batch33083')
S(0x51ec70, 'GUESS two floats to slot 0 of sub-object', 'thiscall', None, ret=None, gen=_g51ec70, note='batch33083')
S(0x5f4110, 'GUESS divide in place or log + assert', 'thiscall', None, ret=None, gen=_g5f4110, note='batch33083')
