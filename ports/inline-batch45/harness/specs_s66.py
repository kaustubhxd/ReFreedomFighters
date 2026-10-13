"""specs_s66.py - inline session batch 66 (grenade flight): ZParamParticle constructor and ZProjectile GetMaterialDesc, SetTarget, SetPrecision, SetProjectileInfo and Command. The game's random number (0x70039c
slot 0x1c4) is a stub that logs both calls and returns per-call floats in ST0; mrotaxis, createmat, vmmul, mreset,
mcpy, vneg, PSVECSubtract, ZParamParticle::Init and ZProjectile::Reset run as exe code; geometry, parent and owner
calls are heap recorder stubs."""
import math
import struct
from pilot import S, F
import specs_s53 as k53
import specs_s60 as k60

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
XYZ = [(0, 'd'), (4, 'd'), (8, 'd')]
M9 = [(4 * i, 'd') for i in range(9)]


def _rndstub(c, vals):
    tab = c.emu.alloc(8, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<f', v) for v in vals))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(16, 4)
    P = lambda v: struct.pack('<I', v)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x01\xc1\xe0\x03\x05' + P(log)
    code += b'\x8b\x54\x24\x04\x89\x10\x8b\x54\x24\x08\x89\x50\x04'
    code += b'\xa1' + P(cnt) + b'\x83\xe0\x01\xd9\x04\x85' + P(tab)
    code += b'\xff\x05' + P(cnt) + b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _f(c):
    r = c.rng
    return r.choice((0.0, -0.0, 1.0, -1.0, r.uniform(-500, 500), r.uniform(-1, 1), r.uniform(-1, 1), c.fv(),
                     r.uniform(-3000, 3000), math.nan))


def _vec(c, vals):
    c.emu.alloc(0x10, 16)
    return _fv(c, vals)


def _sys(c):
    r = c.rng
    rm = _obj(c, 0x20, {0x58: _seq(c, 1, [0]), 0x160: _seq(c, 1, [r.choice((0, 0, 1, r.getrandbits(32))), r.getrandbits(32)])})
    rnd = _rndstub(c, [r.choice((r.random(), r.uniform(-1, 1), 0.0, 1.0, r.uniform(-50, 50))) for _ in range(2)])
    sysobj = _obj(c, 0xa0, {0x1c4: rnd})
    c.emu.w32(sysobj + 0x40, r.choice((r.randint(0, 1 << 22), r.getrandbits(32))))
    c.emu.w32(sysobj + 0x44, r.getrandbits(32))
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    return sysobj, rm


def _zv(c, k):
    """An offset that is zero in 40% of inputs, so a target on an axis gives a direction on that axis."""
    r = c.rng
    return [0.0] * 3 if r.random() < 0.4 else [r.uniform(-k, k) for _ in range(3)]


def _geom(c):
    r = c.rng
    par = _obj(c, 0x20, {0x8c: _stub(c, 1, skip=(0,), copy=(0, XYZ),
                                     adds=((0, _fv(c, _zv(c, 50)), 3),))})
    geom = _obj(c, 0x20, {0x84: _stub(c, 1, skip=(0,), copy=(0, XYZ),
                                      adds=((0, _fv(c, _zv(c, 3000)), 3),)),
                          0x20: _stub(c, 0, ret=par),
                          0x6c: _stub(c, 1, skip=(0,), copy=(0, M9))})
    m = _fv(c, [r.uniform(-1, 1) for _ in range(9)])
    c.emu.w32(geom + 8, m)
    return geom


def _proj(c):
    r = c.rng
    p = _obj(c, 0xa0, {0x3c: _stub(c, 0)})
    c.emu.w32(p + 0x44, _geom(c))
    c.emu.w32(p + 0x4c, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    c.emu.w32(p + 0x6d, _rnd(c, 0x40))
    c.emu.w32(p + 0x89, r.getrandbits(32))
    return p


def _target(c):
    r = c.rng
    k = r.random()
    if k < 0.15:
        return [0.0, 0.0, 0.0]
    if k < 0.25:
        v = [0.0, 0.0, 0.0]
        v[r.randint(0, 2)] = r.choice((_f(c), -0.0, math.nan))
        return v
    return [r.uniform(-3000, 3000) for _ in range(3)]


def _ctor(c):
    return [_rnd(c, 0x40)]


def _mm(c):
    r = c.rng
    a = _vec(c, [r.uniform(-2, 2) for _ in range(9)])
    b = _vec(c, [r.uniform(-2, 2) for _ in range(9)])
    return [a, r.choice((b, b, a))]


def _gmd(c):
    r = c.rng
    _sys(c)
    rm = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    owner = _obj(c, 0x20, {0x2c8: _seq(c, 1, [r.choice((0, 0, 7, r.getrandbits(32))), r.getrandbits(32)])})
    c.emu.w32(c.emu.r32(rm) + 0x58, _seq(c, 1, [owner]))
    p = _proj(c)
    c.emu.mu.ctl_flush_tb()
    return [p, r.choice((0, 1, r.getrandbits(32)))]


def _st(c):
    _sys(c)
    p = _proj(c)
    c.emu.mu.ctl_flush_tb()
    return [p, _vec(c, _target(c))]


def _sp(c):
    r = c.rng
    _sys(c)
    p = _proj(c)
    c.emu.mu.ctl_flush_tb()
    return [p, F(r.choice((0.0, 1.0, r.uniform(0, 30), r.uniform(-10, 10), _f(c))))]


def _info(c):
    r = c.rng
    info = c.emu.alloc(0x30, 4)
    c.emu.wbytes(info, bytes(r.getrandbits(8) for _ in range(0x30)))
    c.emu.wf32(info + 8, r.choice((r.uniform(0, 1000), 100.0, _f(c))))
    c.emu.wbytes(info + 0x10, bytes([r.choice((0, 1, r.randint(0, 255))), r.choice((0, 1, r.randint(0, 255)))]))
    for i, v in enumerate(_target(c)):
        c.emu.wf32(info + 0x12 + 4 * i, v)
    c.emu.wf32(info + 0x1e, r.choice((0.0, r.uniform(0, 30), _f(c))))
    return info


def _spi(c):
    _sys(c)
    p = _proj(c)
    info = _info(c)
    c.emu.mu.ctl_flush_tb()
    return [p, info]


def _cmd(c):
    r = c.rng
    _sys(c)
    p = _proj(c)
    cmd = r.getrandbits(16)
    c.emu.wbytes(p + 0x95, struct.pack('<H', cmd if r.random() < 0.6 else r.getrandbits(16)))
    info = _info(c)
    c.emu.mu.ctl_flush_tb()
    return [p, (r.getrandbits(16) << 16) | cmd, info]


S(0x4e7160, 'ZParamParticle::ZParamParticle', 'thiscall', None, ret='eax', gen=_ctor, note='batch66')
S(0x4ba180, 'ZProjectile::GetMaterialDesc', 'thiscall', None, ret='eax', gen=_gmd, note='batch66')
S(0x4ba620, 'ZProjectile::SetTarget', 'thiscall', None, ret=None, gen=_st, note='batch66; createmat and Init as exe code')
S(0x4ba470, 'ZProjectile::SetPrecision', 'thiscall', None, ret=None, gen=_sp, note='batch66; mrotaxis as exe code')
S(0x4ba570, 'ZProjectile::SetProjectileInfo', 'thiscall', None, ret=None, gen=_spi, note='batch66')
S(0x4b94f0, 'ZProjectile::Command', 'thiscall', None, ret='eax', gen=_cmd, note='batch66')
