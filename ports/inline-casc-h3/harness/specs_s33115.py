"""specs_s33115.py - h3 () batch 33115: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _vb(x):
    return 0x7fc00000 if x != x else _b(x)


def _g578aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x579bd0, 0x579b20, 0x579a60):
        hook_rec(c, a, 1, this=True, side=lambda em, k: em.calllog.append(('s194', em.r32(em.reg('ecx') + 0x194))))
    hook_rec(c, 0x579d20, 0, this=True, side=lambda em, k: em.calllog.append(('s194b', em.r32(em.reg('ecx') + 0x194))))
    me = rnd(c, 0x1c0)
    vals = [-1.0, -1.0, 0.0, 0.5, 1.0, 2.0, -2.0, float('nan'), 0.99, -0.5, c.fv(-5, 5, 0.1)]
    for off in (0x1a8, 0x1ac, 0x1b0):
        e.w32(me + off, _vb(r.choice(vals)))
    return [me]


def _g516520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x524810, 1, this=True)
    hook_rec(c, 0x524460, 1, this=True)
    stubs = {off: pystub(c, n, this=True) for off, n in ((0x68, 1), (0x4c, 1), (0x60, 1), (0x10, 2))}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0x80), s]


def _g477670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x461250, 5, this=True, ret=lambda em, k: _w(c))
    s628 = pystub(c, 3, this=True)
    s588 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, _w(c)]))
    s62c = pystub(c, 1, this=True)
    me = obj(c, 0x740, {0x628: s628, 0x588: s588, 0x62c: s62c})
    e.wbytes(me + 0x726, bytes([r.choice([0, 1, 1, 0xff])]))
    e.w32(me + 0x64c, r.choice([10, 10, 0, 9, _w(c)]))
    a = rnd(c, 0x90)
    e.w32(a + 0x7c, r.choice([0x40, 0, 0x40, 0xffffffff, 0x3f, _w(c)]))
    for off in (0x70, 0x74, 0x78):
        e.w32(a + off, _vb(r.choice([0.0, 0.01, 0.0110, 0.0111, 0.5, -0.5, 1.0, c.fv(-1, 1, 0.05)])))
    return [me, a if r.random() < 0.9 else 0, r.choice([0, 4, 1, 5, _w(c)]), _w(c), _w(c), _w(c)]


S(0x578aa0, 'GUESS flush three pending triggers', 'thiscall', None, ret=None, gen=_g578aa0, note='batch33115')
S(0x516520, 'GUESS write six fields and sub-objects to stream', 'thiscall', None, ret='al', gen=_g516520, note='batch33115')
S(0x477670, 'GUESS maybe reset state then forward to 0x461250', 'thiscall', None, ret='eax', gen=_g477670, nan_heap=True, note='batch33115')
