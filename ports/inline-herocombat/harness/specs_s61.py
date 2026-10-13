"""specs_s61.py - inline session batch 61: ZFFHeroMovementGuide TerminateControl, ClassInit2, GotControl and
GetActiveAnim (the ladder). GotControl runs CalculateLadder (batch 58), createmat and vaddscalar as exe code on the
batch 58 ladder-shape setup. The _CIfmod import slot is pointed at the batch 58 heap fprem loop. Other calls are heap
recorder stubs (the batch 53 kit)."""
import struct
from pilot import S
import specs_s58 as k58

_rnd, _stub, _obj, _fv = k58._rnd, k58._stub, k58._obj, k58._fv


def _fmod_slot(c):
    fm = c.emu.alloc(32, 16)
    c.emu.wbytes(fm, k58.FMOD)
    c.emu.w32(0x676358, fm)


def _sys(c):
    r = c.rng
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x40, r.getrandbits(32))
    c.emu.w32(0x70039c, sysobj)
    return sysobj


def _term(c):
    self = _rnd(c, 0x600)
    c.emu.w32(self + 4, _rnd(c, 0x500))
    return [self, c.rng.getrandbits(32)]


def _ci2(c):
    sysobj = _sys(c)
    rm = _rnd(c, 0xae0)
    c.emu.w32(rm + 0xadc, _obj(c, 0x10, {0x25c: _stub(c, 2, ret=c.rng.getrandbits(32))}))
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x600)]


def _got(c):
    r = c.rng
    _sys(c)
    old = k58._ladder(c)[0]   # the batch 58 ladder object (+4 hero, +0x550 shape, fmod slot set)
    self = _rnd(c, 0x600)
    c.emu.wbytes(self, bytes(c.emu.mu.mem_read(old, 0x580)))
    c.emu.w32(self + 0x36d, _obj(c, 0x10, {0x59c: _stub(c, 2)}))
    c.emu.w32(self + 0x579, r.choice((0, 0, 1, 6, r.getrandbits(32))))
    c.emu.mu.ctl_flush_tb()
    return [self]


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gaa(c):
    r = c.rng
    _fmod_slot(c)
    self = _rnd(c, 0x600)
    hero = _obj(c, 0x400, {0x3f8: _stub(c, 1)})
    c.emu.w32(self + 4, hero)
    c.emu.w32(self + 0x579, r.choice((6, 6, 6, 0, 1)))
    prev = r.choice((r.uniform(0, 1), 0.25, 0.75, 0.0, 1.0, -0.5, r.uniform(-1, 2)))
    c.emu.wbytes(self + 0x5e1, struct.pack('<f', prev))
    top = r.choice((r.uniform(-500, 1500), float(r.randint(-5, 15) * 100)))
    c.emu.wbytes(self + 0x564, struct.pack('<f', top))
    x = r.random()
    if x < 0.6:
        ph = prev + r.choice((r.uniform(-0.3, 0.3), 0.0, 0.25, -0.25, 0.5, -0.5))
        k = r.randint(0, 8)
        y = _f(top - ((k + 1 - ph) * 100.0 + 100.0))
    elif x < 0.8:
        y = _f(top - float(r.randint(0, 40)) * 25.0)   # whole quarter rungs: the phase lands on 0, 0.25, 0.5, 0.75
    else:
        y = r.uniform(-2000, 2000)
    pos = _fv(c, [r.uniform(-100, 100), y, r.uniform(-100, 100)])
    out = _rnd(c, 8)
    c.emu.mu.ctl_flush_tb()
    return [self, out, _fv(c, [1, 2, 3]), _fv(c, [4, 5, 6]), _fv(c, [7, 8, 9]), pos]


S(0x5e7210, 'ZFFHeroMovementGuide::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch61; ladder tree')
S(0x5e1ff0, 'ZFFHeroMovementGuide::ClassInit2', 'thiscall', None, gen=_ci2, note='batch61; ladder tree')
S(0x5e5100, 'ZFFHeroMovementGuide::GotControl', 'thiscall', None, gen=_got, note='batch61; ladder tree; CalculateLadder as exe code')
S(0x5e2d30, 'ZFFHeroMovementGuide::GetActiveAnim', 'thiscall', None, ret='st0', gen=_gaa, note='batch61; ladder tree')
