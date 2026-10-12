"""specs_s242.py - area 22, batch242 (src/batch242.cpp): 0x519dd0, 0x55b2d0, 0x519790. 0x5003d0, 0x5002f0 and 0x5133d0
are per-call recorders (ecx and their one stack word each, ret 4), so the index, the stored value and the float argument
are compared. The value sources return full 32-bit randoms so the byte truncations are tested."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _seq_rec


def _args(c):
    a = _rnd(c, 0x40)
    c.emu.w32(a + 4, _rnd(c, 0x40))
    c.emu.w32(a + 8, _rnd(c, 0x40))
    return a


def _g_519dd0(c):
    self_ = _rnd(c, 0x40)
    v = c.rng.getrandbits(32)
    o = _rnd(c, 0x40)
    c.emu.w32(o, _multi_vt(c, {0x334: (lambda em, args, v=v: (v, None), 0)}))
    c.emu.w32(self_ + 0x14, o)
    _seq_rec(c, 0x5003d0, 1, [_rnd(c, 0x40)])
    _seq_rec(c, 0x5002f0, 1, [c.rng.getrandbits(32)])
    return [self_, _args(c)]


def _g_55b2d0(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, _rnd(c, 0x400))
    _seq_rec(c, 0x5003d0, 1, [_rnd(c, 0x40)])
    _seq_rec(c, 0x5002f0, 1, [c.rng.getrandbits(32)])
    return [self_, _args(c)]


def _g_519790(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x14, _rnd(c, 0x40))
    fbuf = _rnd(c, 0x10)   # random bits: NaNs and denormals included, movss copies them unchanged
    _seq_rec(c, 0x5003d0, 1, [fbuf, _rnd(c, 0x40)])
    _seq_rec(c, 0x5133d0, 1, [c.rng.getrandbits(32)])
    _seq_rec(c, 0x5002f0, 1, [c.rng.getrandbits(32)])
    return [self_, _args(c)]


S(0x519dd0, 'slot334Ret (GUESS)', 'thiscall', None, ret=None, gen=_g_519dd0,
  note='batch242; vtable 0x334 on this+0x14, then 0x5003d0(0) and 0x5002f0(value)')
S(0x55b2d0, 'byte3e9Ret (GUESS)', 'thiscall', None, ret=None, gen=_g_55b2d0,
  note='batch242; byte at this+0x1c->+0x3e9, then 0x5003d0(0) and 0x5002f0(value)')
S(0x519790, 'floatArgRet (GUESS)', 'thiscall', None, ret=None, gen=_g_519790,
  note='batch242; float from element 0 of a+4, 0x5133d0(f), then 0x5002f0((u8)r)')
