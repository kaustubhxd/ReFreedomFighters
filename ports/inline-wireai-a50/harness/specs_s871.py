"""specs_s871.py - area 50, batch 871: 0x4dda90 (GUESS name), stdcall (two float stack args, ret 8), result in ST0.
Pure math; the CRT atan comes from the import slot 0x676318 (the harness's math stubs). The inputs cover zero, negative and
NaN values; the float arguments are wrapped in F(...)."""
import struct
from pilot import S, F


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    r = c.rng
    pool = [0.0, -0.0, 1.0, -1.0, 0.5, -3.25, 1e-3, 7.0]
    x = r.choice(pool + [_f32(r.uniform(-10, 10))]) if r.random() < 0.8 else float('nan')
    y = r.choice(pool + [_f32(r.uniform(-10, 10))]) if r.random() < 0.8 else float('nan')
    return [F(_f32(x)) if x == x else F(0.0), F(_f32(y)) if y == y else F(0.0)]


S(0x4dda90, 'Angle4dda90 (GUESS name)', 'stdcall', None, ret='st0', gen=_gen, note='area50 batch871')
