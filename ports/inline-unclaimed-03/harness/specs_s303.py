"""specs_s303.py - unclaimed-03 batch 3 (docs/20-unclaimed-03.md): CMoveAlongPath::CalcAcceleration (0x522f20) and
CMoveAlongPath::OffsetSplineVal (0x523940). Both take a float (or two) on the stack, thiscall, and return a float on
the x87 stack (ret='st0'). Each object is 0x800 random bytes. Boundary values are forced in some cases: CalcAcceleration
gets a1 equal to its threshold 0x679540 in one case of four; OffsetSplineVal gets divisor 1.0 and offset 0.0 in one
case of three, so its result follows the argument and crosses 0 and 1."""
from pilot import S, F
import struct


def _f32_bits(u):
    return struct.unpack('<f', struct.pack('<I', u))[0]


def _obj(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return a


def _calc(c):
    o = _obj(c)
    a1 = c.fv(-100.0, 100.0)
    a2 = c.fv(-100.0, 100.0)
    if c.rng.random() < 0.25:
        a1 = _f32_bits(0x39000000)     # the threshold at 0x679540, compared with '>'
    return [o, F(a1), F(a2)]


def _offset(c):
    o = _obj(c)
    a = c.fv(-10.0, 10.0)
    if c.rng.random() < 1 / 3:
        c.emu.wf32(o + 0x53, 1.0)      # divisor 1.0
        c.emu.wf32(o + 0x4, 0.0)       # offset 0.0, so the result is minss(1.0, a)
    return [o, F(a)]


S(0x522f20, 'CMoveAlongPath::CalcAcceleration (unknown) thiscall', 'thiscall', None, ret='st0', gen=_calc,
  note='unclaimed-03 batch 3; a1 > 0x679540 gives (d*d)/a1*0x67a6ac, else 0x7e967699')
S(0x523940, 'CMoveAlongPath::OffsetSplineVal (unknown) thiscall', 'thiscall', None, ret='st0', gen=_offset,
  note='unclaimed-03 batch 3; t=a/+0x53+ +4; t<0 gives 0, else minss(1.0, t)')
