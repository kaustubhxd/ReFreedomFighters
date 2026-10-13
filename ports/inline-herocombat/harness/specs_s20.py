"""specs_s20.py - inline session batch 20 (Haiku, overnight): 0x4856f0, 0x4464a0, 0x467ea0."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4856f0 fastcall: pointer to three floats. About a third of the cases are all zero, the rest mix zeros and values.
def _zero3(c):
    r = c.rng
    v = c.emu.alloc(12, 4)
    for i in range(3):
        if r.random() < 0.33:
            c.emu.wf32(v + 4 * i, 0.0)
        else:
            c.emu.wf32(v + 4 * i, c.fv())
    return [v]


S(0x4856f0, 'isAllZero3 (unknown) fastcall', 'fastcall', None, ret='al', gen=_zero3,
  note='batch20; ordered compare with 0.0 on each of three floats (NaN fails)')


# 0x4464a0 thiscall: count at this+0x2c, u32 array at this+0x24, value as the stack argument. The array entries are written
# first and the count after, since the count slot is also arr[2].
def _take(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    n = r.randint(0, 6)
    for i in range(n):
        c.emu.w32(obj + 0x24 + 4 * i, r.randint(1, 6))
    c.emu.w32(obj + 0x2c, n)
    value = r.randint(1, 7)
    return [obj, value]


S(0x4464a0, 'takeValue (unknown) thiscall', 'thiscall', None, ret='al', gen=_take,
  note='batch20; removes by moving the last element into the slot; count slot aliases arr[2]')


# 0x467ea0 thiscall, no stack args. Object pointer at this+0x6c, global pointer at 0x70039c with a float at +0x48.
def _step(c):
    r = c.rng
    obj = _rnd(c, 0x200)
    c.emu.wbytes(obj + 0x70, bytes([r.choice([0, 1])]))
    c.emu.w32(obj + 0x6c, _rnd(c, 0x240))
    c.emu.wf32(obj + 0x1c6, c.fv())
    g = _rnd(c, 0x60)
    c.emu.wf32(g + 0x48, c.fv())
    c.emu.w32(0x70039c, g)
    return [obj]


S(0x467ea0, 'stepFloat (unknown) thiscall', 'thiscall', None, ret=None, gen=_step,
  note='batch20; copies four dwords when this+0x70 is 0; subtracts a scaled global float; clamps below 0')
