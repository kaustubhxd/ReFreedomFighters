"""specs_s8.py - inline session batch 8 (Haiku, overnight): 0x4e4990, 0x4e6b80, 0x61fce0, 0x644fb0."""
from pilot import S, F, f32


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4e4990 stdcall: (v). Edge values and random 32-bit values.
S(0x4e4990, 'spanBits (unknown) stdcall', 'stdcall', None, ret='eax',
  gen=lambda c: [c.rng.choice([-2**31, -1, 0, 1, 2, 3, 4, 255, 256, 2**30, 2**31 - 1, c.rng.getrandbits(32)]) & 0xffffffff],
  note='batch8; v <= 1 signed returns 15')


# 0x4e6b80 thiscall: (this, out). Table of 40 u16 values; limit 0..24; index 0..24 so both branches run.
def _step(c):
    e, r = c.emu, c.rng
    o = _rnd(c, 0x20)
    table = _rnd(c, 80, 2)
    limit = r.randint(0, 24)
    e.w32(o + 0, r.getrandbits(32))
    e.w32(o + 4, table)
    e.w32(o + 8, limit)
    e.w32(o + 0xc, r.randint(0, 9))
    e.w32(o + 0x10, r.randint(0, 24))
    out = _rnd(c, 4)
    return [o, out]


S(0x4e6b80, 'readU16Step (unknown) thiscall', 'thiscall', None, ret='eax', gen=_step,
  note='batch8; index == limit returns 0 and writes -1')


# 0x61fce0 stdcall: (s). NUL-terminated byte string, no interior NUL, length 0..40.
def _str(c):
    n = c.rng.randint(0, 40)
    a = c.emu.alloc(n + 1, 4)
    c.emu.wbytes(a, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\x00')
    return [a]


S(0x61fce0, 'strHash33 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_str,
  note='batch8; djb2-style multiply by 33')


# 0x644fb0 thiscall: (this, mode, value). Mode drawn from 0..4 and -1; value a float.
def _mode(c):
    o = _rnd(c, 0x20)
    mode = c.rng.choice([0, 1, 2, 3, 4, -1, 1, 2, 3])
    return [o, mode & 0xffffffff, F(c.fv())]


S(0x644fb0, 'setSlotByMode (unknown) thiscall', 'thiscall', None, ret=None, gen=_mode,
  note='batch8; mode 2 writes the exe global 0x6ec3cc')
