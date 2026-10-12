"""specs_s262.py - area 22, batch262 (src/batch262.cpp): ZItemTemplateWeapon getters, ZMoveOnSpline::SendTargetForVehicle,
ZFFHintBox::Load, ZMoveOnSpline::ClassFrameUpdate, ZMoveOnSplineIf::collectOpaqueInfo and opaqueCall. Hooked by address
(logged, not the real bodies): 0x523280 (GUESS stub; disputed in docs/39), 0x5121e0 (recorder; verified in
inline-unclaimed-81), 0x50a410 and 0x504560 (GUESS stubs). 0x4690b0 (ret) runs as exe code. The opaqueCall handler table
(count [0x701660], entries from 0x701668) is replaced per case by logged stubs."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _z(em, a):
    return (0, None)


def _g_self(c):
    return [_rnd(c, 0x100)]


def _g_514350(c):
    e = c.emu
    self_ = _rnd(c, 0x220)

    def send(em, r):
        to, cmd, data = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('send.12c', 0x12c, em.reg('ecx'), (to, cmd, em.r32(data), em.r32(data + 4))))
        em.ret(eax=0, argbytes=12)
    e.w32(self_, _pyvt(c, {0x12c: send}))
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x4c: (lambda em, a, v=_r(c): (v, None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [self_, _r(c), _r(c)]


def _g_5b7710(c):
    e = c.emu
    self_ = _rnd(c, 0x60)
    vals = [_r(c), c.rng.choice([_r(c), 0])]

    def rd(name):
        def h(em, r):
            dst = em.arg32(0)
            em.calllog.append((name, 0, None, (dst,)))
            em.w32(dst, vals.pop(0) if vals else 0x1234)
            em.ret(eax=1, argbytes=4)
        return h
    l = _rnd(c, 0x10)
    e.w32(l, _pyvt(c, {0x48: rd('l.48'), 0x40: rd('l.40')}))
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, v=_r(c): (v, None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [self_, l]


def _g_512450(c):
    e = c.emu
    _hk(c, 0x523280, 'MoveAlongPath::FrameUpdate', 0)
    _hk(c, 0x5121e0, 'AnimUpdate', 0)
    self_ = _rnd(c, 0x140)
    e.w32(self_, _multi_vt(c, {0x354: (_z, 0), 0x2f4: (_z, 0), 0x34c: (_z, 0), 0x320: (_z, 0)}))
    p = _rnd(c, 0x60)
    e.w32(p + 0x4b, c.rng.choice([0, 0, 1, _r(c)]))
    e.w32(self_ + 0x5c, p)
    e.wbytes(self_ + 0x133, bytes([c.rng.choice([0, 1, 0x80])]))
    c.emu.mu.ctl_flush_tb()
    return [self_]


def _g_51a790(c):
    e = c.emu
    _hk(c, 0x50a410, 'ZGeomIf::collectOpaqueInfo', 1)
    self_ = _rnd(c, 0x40)
    e.w32(self_, _multi_vt(c, {0x38: (lambda em, a, v=_r(c): (v, None), 0)}))
    buf = _rnd(c, 0x10)
    e.w32(buf, _multi_vt(c, {0: (_z, 1)}))
    c.emu.mu.ctl_flush_tb()
    return [self_, buf]


def _g_51a7d0(c):
    e = c.emu
    _hk(c, 0x504560, 'ZGeomIf::opaqueCall', 1)
    n = c.rng.choice([0, 1, 3, 8])
    e.w32(0x701660, n)
    for i in range(n):
        e.w32(0x701668 + 4 * i, e.stub_fn('h%d' % i, lambda em, r, i=i: (
            em.calllog.append(('handler', i, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4))))
    p = _rnd(c, 0x20)
    e.wbytes(p + 0x10, (c.rng.choice([0, 1, 2, 5, 7, 8, 9, 0xffff, c.rng.getrandbits(16)])).to_bytes(2, 'little'))
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x40), p]


S(0x46ed10, 'ZItemTemplateWeapon::GetPitchChange', 'thiscall', None, ret='eax', gen=_g_self, note='batch262; word +0xd3')
S(0x46efd0, 'ZItemTemplateWeapon::GetWeaponType', 'thiscall', None, ret='eax', gen=_g_self, note='batch262; word +0x9c')
S(0x46ecd0, 'ZItemTemplateWeapon::GetMuzzleVelocity', 'thiscall', None, ret='st0', gen=_g_self,
  note='batch262; float +0xa8 in st0')
S(0x514350, 'ZMoveOnSpline::SendTargetForVehicle', 'thiscall', None, ret=None, gen=_g_514350,
  note='batch262; void; SendCommand slot 0x12c with a stack pair (logged by value)')
S(0x5b7710, 'ZFFHintBox::Load', 'thiscall', None, ret='al', gen=_g_5b7710, note='batch262; returns 1')
S(0x512450, 'ZMoveOnSpline::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_g_512450,
  note='batch262; void; 0x523280 GUESS stub, 0x5121e0 recorder')
S(0x51a790, 'ZMoveOnSplineIf::collectOpaqueInfo', 'thiscall', None, ret=None, gen=_g_51a790,
  note='batch262; void; 0x50a410 GUESS stub')
S(0x51a7d0, 'ZMoveOnSplineIf::opaqueCall', 'thiscall', None, ret=None, gen=_g_51a7d0,
  note='batch262; void; handler table replaced per case; 0x504560 GUESS stub')
