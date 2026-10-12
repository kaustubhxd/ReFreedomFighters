"""specs_s261.py - area 22, batch261 (src/batch261.cpp): ZFFHeroMovementCloseCombat::CalcNewSpeed. this->vt[0x50] is a
Python slot that logs dir and pos and writes fwd and goal (random vectors, sometimes unit and parallel or opposite to dir so
the dot product reaches 1 or -1). PSVECSubtract, DeltaTime, vscalar and vcross run as original code (inline-batch45); acos
goes through pe_emu's _libm_sse2_acos_precise stub (Python acos, the same on both sides)."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _vec(c, scale=2.0):
    return [c.rng.uniform(-scale, scale) for _ in range(3)]


def _g_5e18d0(c):
    e = c.emu
    k = c.rng.random()
    if k < 0.2:
        d = [1.0, 0.0, 0.0]
        fwd = c.rng.choice([[1.0, 0.0, 0.0], [-1.0, 0.0, 0.0], [1.0000001, 0.0, 0.0], [-1.0000001, 0.0, 0.0]])
    else:
        d = _vec(c, 1.0)
        fwd = _vec(c, 1.0)
    goal = _vec(c, 5.0)

    def vt50(em, r):
        a0, a1, f, g = (em.arg32(i) for i in range(4))
        em.calllog.append(('vt50', 0x50, None, (em.rbytes(a0, 12), em.rbytes(a1, 12))))
        for i in range(3):
            em.w32(f + 4 * i, _fb(fwd[i]))
            em.w32(g + 4 * i, _fb(goal[i]))
        em.ret(eax=0, argbytes=16)
    self_ = _rnd(c, 0x40)
    e.w32(self_, _pyvt(c, {0x50: vt50}))
    e.w32(self_ + 0x18, _fb(c.rng.choice([0.0, 0.0, 1 / 30, c.rng.uniform(0.001, 0.1)])))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x48, _fb(c.rng.choice([1 / 30, 1 / 60, c.rng.uniform(0.001, 0.1)])))
    e.w32(rm + 0x54, _fb(c.rng.choice([1.0, 0.5, 2.0, c.rng.uniform(0.1, 3.0)])))
    e.w32(0x70039c, rm)
    dp = _rnd(c, 12)
    for i in range(3):
        e.w32(dp + 4 * i, _fb(d[i]))
    pos = _rnd(c, 12)
    for i, v in enumerate(_vec(c, 5.0)):
        e.w32(pos + 4 * i, _fb(v))
    return [self_, dp, pos, _rnd(c, 12), _rnd(c, 12)]


S(0x5e18d0, 'ZFFHeroMovementCloseCombat::CalcNewSpeed', 'thiscall', None, ret=None, gen=_g_5e18d0, nan_heap=True,
  note='batch261; void; acos through the exe thunk; x87 division done as double math (exact for float inputs)')
