"""specs_s11.py - inline session batch 11 (Haiku, overnight): 0x62f5a0, 0x4caf50, 0x4dd060, 0x522e80."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x62f5a0 cdecl: (this, value). Position 0..12 so two bytes always fit in the 16-byte buffer.
def _wbe(c):
    r = c.rng
    o = _rnd(c, 0x20)
    buf = _rnd(c, 16)
    c.emu.w32(o + 8, buf)
    c.emu.w32(o + 0x14, r.randint(0, 12))
    return [o, r.getrandbits(32)]


S(0x62f5a0, 'writeU16BE (unknown) cdecl', 'cdecl', None, ret=None, gen=_wbe,
  note='batch11; writes high byte then low byte, advances the position by 2')


# 0x4caf50 thiscall: (this, src). Both objects 0x100 bytes so offsets 0x68..0x8c are inside them.
S(0x4caf50, 'copyTail10 (unknown) thiscall', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x100), _rnd(c, 0x100)], note='batch11; ten dwords copied')


# 0x4dd060 thiscall: (this, src). Source dwords drawn so both sides of the 2^-13 clamp occur, plus NaN and 0.
_POOL = [0x39000000, 0x38000000, 0x3f800000, 0xbf800000, 0x40000000, 0, 0x80000000, 0x7fc00000, 0x39000001]


def _clamp(c):
    o = _rnd(c, 0x80)
    src = _rnd(c, 16)
    for i in range(3):
        c.emu.w32(src + 4 * i, c.rng.choice(_POOL) if c.rng.random() < 0.8 else c.rng.getrandbits(32))
    return [o, src]


S(0x4dd060, 'clampFloor3 (unknown) thiscall', 'thiscall', None, ret=None, gen=_clamp,
  note='batch11; clamps to 0x39000000 when below the constant at 0x679540')


# 0x522e80 thiscall: (this). Returns this.
S(0x522e80, 'initVec (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x80)], note='batch11; vtable word 0x6a0750, 1.0f in several float slots')
