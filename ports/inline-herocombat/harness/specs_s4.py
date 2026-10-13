"""specs_s4.py - inline session batch 4 (Haiku, 2026-10-09 evening): 0x45efc0, 0x4418f0, 0x47c4e0, 0x4ccbe0."""
import math
from pilot import S, F, f32


def _fl(c, edge=0.35):
    r = c.rng.random()
    if r < edge:
        return f32(c.rng.choice([0.0, -0.0, 1.0, -1.0, 0.5, math.nan, math.inf]))
    return c.fv()


def _ptr3(c, vals=None):
    a = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.wf32(a + 4 * i, _fl(c) if vals is None else vals[i])
    return a


# 0x45efc0 stdcall: (float* out, const float* a, const float* b, float t)
def _lerp(c):
    out = c.emu.alloc(16, 4)
    return [out, _ptr3(c), _ptr3(c), F(_fl(c, 0.1))]


S(0x45efc0, 'lerp3 (guessed) stdcall', 'stdcall', None, ret=None, gen=_lerp,
  note='batch4; name guessed from body')


# 0x4418f0 thiscall: (this, const u32* v). Pairs with zeros/NaN in the 40% range so both flag paths run.
def _set(c):
    e = c.emu
    o = e.alloc(0x50, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x50)))
    v = e.alloc(8, 4)
    e.wf32(v, _fl(c)); e.wf32(v + 4, _fl(c))
    return [o, v]


S(0x4418f0, 'setRange2 (class unknown) thiscall', 'thiscall', None, ret=None, gen=_set,
  note='batch4; flag 0x200 set unless both floats are +-0')


# 0x47c4e0 thiscall: (this, const u32* a, const u32* b)
def _copy(c):
    e = c.emu
    o = e.alloc(0x800, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    a = e.alloc(12, 4); b = e.alloc(12, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(12)))
    e.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(12)))
    return [o, a, b]


S(0x47c4e0, 'copyTwoVec3 (class unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='batch4; copies two 12-byte blocks, sets byte +0x726')


# 0x4ccbe0 thiscall: (this, int n, int m). n and m drawn from negative, zero, small and large values.
def _ctor(c):
    e = c.emu
    o = e.alloc(0x20, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    pick = lambda: c.rng.choice([-5, -1, 0, 1, 2, 3, 7, 100, c.rng.randint(-2**31, 2**31 - 1)])
    return [o, pick() & 0xffffffff, pick() & 0xffffffff]


S(0x4ccbe0, 'initTable (class unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='batch4; constructor writes vtable 0x695734')
