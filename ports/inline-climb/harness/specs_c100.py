"""specs_c100.py - climb thread batch 100: 0x43e8e0, 0x451890, 0x45bfd0, 0x5e2580, 0x4878c0, 0x4946a0, 0x5e1350."""
import struct
from pilot import S, F


def _pf(v):
    try:
        return struct.pack('<f', v)
    except OverflowError:
        return struct.pack('<f', float('inf') if v > 0 else float('-inf'))


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fv3(c, n=3, pad=4):
    return c.fbuf(n, pad=pad)


def _add(c):
    r = c.rng
    a = _fv3(c)
    b = _fv3(c)
    k = r.random()
    out = a if k < 0.15 else b if k < 0.3 else _fv3(c)   # aliasing cases
    return [out, a, b]


S(0x43e8e0, 'PSVECAdd (guess)', 'fastcall', None, ret=None, gen=_add, note='c100; out = a + b, x87')


def _vas(c):
    r = c.rng
    v = _fv3(c)
    a = v if r.random() < 0.15 else _fv3(c)
    return [v, a, F(c.fv())]


S(0x451890, 'vaddscalar', 'fastcall', None, ret=None, gen=_vas, note='c100; v += a*s, x87 53-bit')


def _tri(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    # corners: random, sometimes collinear or repeated so the cross product is zero
    pts = [[c.fv() for _ in range(3)] for _ in range(3)]
    k = r.random()
    if k < 0.15:
        pts[2] = list(pts[0])
    elif k < 0.25:
        pts[1] = list(pts[0]); pts[2] = list(pts[0])
    elif k < 0.35:
        t = float(r.randint(-3, 3))
        pts[2] = [pts[0][i] + t * (pts[1][i] - pts[0][i]) for i in range(3)]
    elif k < 0.6:
        pts = [[float(r.randint(-4, 4)) for _ in range(3)] for _ in range(3)]
    for i, p in enumerate(pts):
        for j, v in enumerate(p):
            c.emu.mu.mem_write(obj + 0x48 + 12 * i + 4 * j, _pf(v))
    out = _fv3(c)
    return [obj, out]


S(0x45bfd0, 'triNormal (guess: COLI hit-triangle normal)', 'thiscall', None, ret=None, gen=_tri,
  note='c100; PSVECSubtract and vcross run as original code')


def _gaa(c):
    return [_rnd(c, 0x40)] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x5e2580, 'ZFFHeroMovementClimb::GetActiveAnim (folded stub)', 'thiscall', None, ret='st0', gen=_gaa,
  note='c100; returns 0.0, pops 0x14')


S(0x4878c0, 'base dtor part (vtable 0x68cf50)', 'thiscall', None, ret=None, gen=lambda c: [_rnd(c, 0x20)],
  note='c100')

S(0x4946a0, 'ZSoundBase::SetOwner', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x20), c.rng.getrandbits(32)], note='c100')


def _delete(e, r):
    e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=0)


def _dtor(c):
    e = c.emu
    e.hook(0x634273, _delete)
    obj = _rnd(c, 0x80)
    if c.rng.random() < 0.3:
        sub = 0
    else:
        vt = e.logging_vtable('sub', 2, argwords={0: 1})
        sub = e.fake_object('sub', 0x20, vtable=vt)
    e.w32(obj + 0x76, sub)
    return [obj, c.rng.getrandbits(32)]


S(0x5e1350, 'ZFFHeroMovementClimb::~ZFFHeroMovementClimb (scalar deleting)', 'thiscall', None, ret='eax', gen=_dtor,
  note='c100; operator delete is a logging hook; the +0x76 sub-object a logging vtable')
