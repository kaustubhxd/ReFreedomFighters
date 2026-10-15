"""specs_s33082.py - h3 (Sonnet) batch 33082: tier H float/SSE functions."""
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


def _g521a40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = pystub(c, 3, this=True)
    vt = e.alloc(0x10, 4)
    e.w32(vt, st)
    me = rnd(c, 0x26a0)
    e.w32(me + 0x2695, vt)
    p = rnd(c, 0x40)
    e.w32(me + 0x5c, p)
    e.w32(p + 0x24, r.choice([_b(50.0), _b(50.00001), _b(49.99999), 0x7fc00000, _fb(c, 0, 100), _b(0.0), _b(1e9)]))
    return [me, rnd(c, 0x10)]


def _g460aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4604f0, 2, this=True)
    me = rnd(c, 0x20)
    e.w32(me + 0x10, r.choice([0, 1, 2, 3, 5, 10, 100, r.getrandbits(6), 0xffffffff]))
    e.w32(me + 0xc, rnd(c, 0x40))
    return [me, _w(c), _fl(c, -0.5, 1.5)]


def _g51ea70(c):
    clear_hooks(c)
    pa, pb = rnd(c, 8), rnd(c, 8)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: pa if k % 2 == 1 else pb)
    s = pystub(c, 2, this=True)
    q = obj(c, 0x10, {0x3a0: s})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, q)
    arg = rnd(c, 0x10)
    return [me, arg]


def _g656060(c):
    clear_hooks(c)
    e = c.emu
    cc = rnd(c, 0x10)
    for i in range(4):
        e.w32(cc + 4 * i, _fb(c, -1.2, 1.2))
    return [rnd(c, 8), cc]


def _g4bf640(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s88 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, _w(c)]))
    s90 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('b', em.rbytes(em.reg('ecx') + 0x1ba, 1))))
    me = obj(c, 0x300, {0x88: s88, 0x90: s90})
    so = sysobj(c)
    f = r.choice([_fb(c, -5000, 5000), _b(0.0), _b(1000.0)])
    e.w32(me + 0x1c7, f)
    e.wbytes(me + 0x1ba, bytes([r.choice([0, 1, 0xff])]))
    fv = struct.unpack('<f', struct.pack('<I', f))[0]
    x = fv * 1024.0
    k = 0 if x != x or abs(x) >= 2147483648.0 else int(x)
    if r.random() < 0.8:
        t = k + 0x400 + r.choice([-1, 0, 1, 2, -2, 50, -50])
    else:
        t = _w(c)
    e.w32(so + 0x40, t & 0xffffffff)
    return [me]


def _g593ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x80)
    e.w32(p + 0x70, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _fb(c)]))
    s = pystub(c, 1, this=True, ret=lambda em, k: p if flag else 0, deref=None)
    flag = r.random() < 0.75
    sysobj(c, table_slots={0x60: s})
    hook_rec(c, 0x467230, 1, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0xf70), _w(c)]


def _g5e9300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    me = rnd(c, 0x460)
    f = r.choice([_fb(c, -1000, 1000), 0, 0x80000000, 0x7fc00000, _b(2.0e6)])
    e.w32(me + 0x44c, f)
    e.w32(me + 0x48, r.choice([0, 1, 5, 20, 100, 127]))
    e.w32(so + 0x40, r.choice([_w(c), r.getrandbits(14), 0, 0xffffff00]))
    return [me, _w(c)]


def _g51eb80(c):
    clear_hooks(c)
    pa, pb = rnd(c, 8), rnd(c, 8)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: pa if k % 2 == 1 else pb)
    s = pystub(c, 3, this=True)
    q = rnd(c, 0x3d0)
    vt = c.emu.alloc(0x10, 4)
    c.emu.w32(vt, s)
    c.emu.w32(q + 0x3c8, vt)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, q)
    return [me, rnd(c, 0x10)]


S(0x521a40, 'GUESS set direction vector then slot 0 on sub-object', 'thiscall', None, ret=None, gen=_g521a40, note='batch33082')
S(0x460aa0, 'GUESS pick keyframe by t then 0x4604f0', 'thiscall', None, ret=None, gen=_g460aa0, note='batch33082')
S(0x51ea70, 'GUESS fetch two floats and call slot 0x3a0', 'thiscall', None, ret=None, gen=_g51ea70, note='batch33082')
S(0x656060, 'GUESS pack colour floats into an int', 'stdcall', None, ret=None, gen=_g656060, note='batch33082')
S(0x4bf640, 'GUESS timed refresh with slots 0x88/0x90', 'thiscall', None, ret=None, gen=_g4bf640, note='batch33082')
S(0x593ff0, 'GUESS look up object and maybe recreate', 'thiscall', None, ret='eax', gen=_g593ff0, note='batch33082')
S(0x5e9300, 'GUESS append (id, age) record', 'thiscall', None, ret=None, gen=_g5e9300, note='batch33082')
S(0x51eb80, 'GUESS two floats: slot 0 on sub-object and store', 'thiscall', None, ret=None, gen=_g51eb80, note='batch33082')
