"""specs_s67.py - inline session batch 67: ZProjectile::Explode. ShotImpact runs as exe code and stops at its first check
(the render manager's slot 0x58 resolves the hit handle to nothing); RegisterZMsg (slot 0x114) returns a random id;
SendCommand (geometry slot 0x128) logs the id, the sender and the message block; geometry calls are recorder stubs."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_fv = k60._fv
BLK = [(4 * i, 'd') for i in range(11)]


def _ex(c):
    r = c.rng
    rm = _obj(c, 0x120, {0x58: _stub(c, 1, ret=0), 0x114: _stub(c, 4, ret=r.getrandbits(32))})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    geom = _obj(c, 0x20, {0x128: _stub(c, 3, skip=(1,), copy=(1, BLK)), 0x28: _stub(c, 0)})
    coli = _rnd(c, 0x70)
    self = _rnd(c, 0xa0)
    c.emu.w32(self + 0x44, geom)
    c.emu.w32(self + 0x8d, coli)
    c.emu.wbytes(self + 0x50, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    vel = _fv(c, [r.uniform(-1500, 1500) for _ in range(3)])
    c.emu.mu.ctl_flush_tb()
    return [self, vel]


S(0x4b95d0, 'ZProjectile::Explode', 'thiscall', None, ret=None, gen=_ex, note='batch67; ShotImpact as exe code')
