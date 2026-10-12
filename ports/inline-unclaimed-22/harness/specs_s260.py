"""specs_s260.py - area 22, batch260 (src/batch260.cpp): ZFFHeroMovementBaseMove::GetActiveAnim. vnorm 0x44c840,
PSVECSubtract 0x43e920 and vmtmul 0x441a60 run as original code (verified in other folders); _CIfmod goes through the
fprem stub (helpers22._install_fmod), sqrt through pe_emu's _libm_sse2_sqrt_precise stub (exact). The vt[0x44] call logs
its two float words."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _install_fmod


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _floats(c, addr, n, lo, hi):
    for i in range(n):
        c.emu.w32(addr + 4 * i, _fb(c.rng.uniform(lo, hi)))


def _g_5e23d0(c):
    e = c.emu
    _install_fmod(c)
    self_ = _rnd(c, 0x380)
    e.w32(self_, _multi_vt(c, {0x44: (lambda em, a: (0, None), 2)}))
    e.w32(self_ + 0xc, _fb(c.rng.choice([c.rng.uniform(-1.5, 2.5), 0.0, 0.999, -0.25])))
    flags = _rnd(c, 0x420)
    e.wbytes(flags + 0x417, bytes([c.rng.choice([0, 1, 2, 3, 4, 0x80])]))
    e.w32(self_ + 0x36d, flags)
    ctl = 0
    if c.rng.random() < 0.9:
        hdr = _rnd(c, 0x70)
        e.w32(hdr + 0x60, c.rng.randrange(0, 50))
        e.w32(hdr + 0x64, c.rng.randrange(0, 200))
        e.w32(hdr + 0x6c, c.rng.randrange(-5, 60) & 0xffffffff)
        ctl = _rnd(c, 0x20)
        e.w32(ctl, hdr)
        scale = c.rng.choice([1.0, 1e-5, 0.0])
        _floats(c, ctl + 0xc, 3, -2.0 * scale, 2.0 * scale)
    e.w32(self_ + 0x21, ctl)
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x48, _fb(c.rng.choice([1 / 30, 1 / 60, 0.0, c.rng.uniform(0, 0.1)])))
    e.w32(0x70039c, rm)
    a = _rnd(c, 0x10)
    b = _rnd(c, 0x10)
    m = _rnd(c, 0x40)
    _floats(c, a, 3, -3, 3)
    _floats(c, b, 3, -3, 3)
    _floats(c, m, 12, -1.5, 1.5)
    out = _rnd(c, 4)
    return [self_, out, _rnd(c, 0x10), a, m, b]


S(0x5e23d0, 'ZFFHeroMovementBaseMove::GetActiveAnim', 'thiscall', None, ret='st0', gen=_g_5e23d0, nan_heap=True,
  note='batch260; SSE math with fmod/sqrt through the exe thunks; vnorm, PSVECSubtract, vmtmul as exe code')
