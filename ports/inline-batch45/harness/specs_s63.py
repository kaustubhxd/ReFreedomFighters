"""specs_s63.py - inline session batch 63 (throw tree): ZFFActionThrow::Execute and Terminate, the hero's camera-helper
getter, and the x87 vector helpers PSVECAdd3, vnorm(dst, src) and vaddscalar. The hero's slot 0x100 is a recorder stub
returning a random helper; the OSD setter (batch 38) runs as exe code."""
import math
from pilot import S, F
import specs_s58 as k58

_rnd, _stub, _obj = k58._rnd, k58._stub, k58._obj


def _hero(c):
    r = c.rng
    helper = _rnd(c, 0xc00)
    hero = _obj(c, 0x900, {0x100: _stub(c, 1, ret=helper)})
    if r.random() < 0.5:
        c.emu.w32(hero + 0x85a, _rnd(c, 0xc00))
    else:
        c.emu.w32(hero + 0x85a, 0)
    c.emu.w32(hero + 0x852, _rnd(c, 0x2300))
    return hero


def _tick(c):
    r = c.rng
    g = _rnd(c, 0x80)
    c.emu.w32(g + 0x40, r.choice((0, 1, 1023, 1024, 0x7fffffff, 0x80000000, r.getrandbits(32), r.randint(0, 1 << 24))))
    c.emu.w32(0x70039c, g)


def _gch(c):
    h = _hero(c)
    c.emu.mu.ctl_flush_tb()
    return [h]


def _exe(c):
    self = _rnd(c, 0x40)
    c.emu.w32(self + 8, _hero(c))
    _tick(c)
    c.emu.mu.ctl_flush_tb()
    return [self]


def _f(c):
    r = c.rng
    return r.choice((0.0, -0.0, 1.0, -1.0, math.nan, math.inf, 1e-30, 3e38, r.uniform(-500, 500), r.uniform(-1, 1),
                     c.fv(), c.fv(), r.uniform(-1e6, 1e6), 16777217.0, 1.5e-45))


def _v(c, zero=0.15):
    a = c.emu.alloc(0x20, 4)
    vals = [0.0, 0.0, 0.0] if c.rng.random() < zero else [_f(c), _f(c), _f(c)]
    if c.rng.random() < 0.15:
        vals[c.rng.randint(0, 2)] = c.rng.choice((0.0, -0.0))
    for i, x in enumerate(vals):
        c.emu.wf32(a + 4 * i, x)
    return a


def _add3(c):
    c.emu.alloc(0x40, 16)   # pad, so a pointer 4 bytes below the first vector is mapped
    a, b = _v(c), _v(c)
    dst = c.rng.choice((_rnd(c, 0x20), _rnd(c, 0x20), a, b, a + 4, b + 4))   # in place and overlapping too
    return [dst, a, b]


def _vn(c):
    c.emu.alloc(0x40, 16)   # pad, so a pointer 4 bytes below the first vector is mapped
    src = _v(c, 0.25)
    dst = c.rng.choice((src, src + 4, src - 4, _rnd(c, 0x20), _rnd(c, 0x20)))
    return [dst, src]


def _vas(c):
    c.emu.alloc(0x40, 16)   # pad, so a pointer 4 bytes below the first vector is mapped
    d, v = _v(c), _v(c)
    v = c.rng.choice((v, v, v, d, d + 4, d - 4))   # v may alias dst
    return [d, v, F(_f(c))]


S(0x566fa0, 'ZFFHERO camera-helper getter', 'thiscall', None, ret='eax', gen=_gch, note='batch63; throw tree')
S(0x5e0500, 'ZFFActionThrow::Execute', 'thiscall', None, ret='al', gen=_exe, note='batch63; throw tree')
S(0x5e0600, 'ZFFActionThrow::Terminate', 'thiscall', None, ret=None, gen=_exe, note='batch63')
S(0x43e8e0, 'PSVECAdd3', 'fastcall', None, ret=None, gen=_add3, note='batch63; dst = a + b, one stack arg')
S(0x44e630, 'vnorm(dst, src)', 'fastcall', None, ret='st0', gen=_vn, note='batch63; length in ST0')
S(0x451890, 'vaddscalar', 'fastcall', None, ret=None, gen=_vas, note='batch63; dst += v * s, float stack arg')
