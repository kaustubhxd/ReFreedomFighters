"""specs_s244.py - parked row 0x47f680 (batch244): fastcall(a, b), returns al (bool). Cases: equal copies, one differing
component, NaN components, signed zeros (equal)."""
import math
import struct
from pilot import S, F
import serial_stubs as ss


def _f(x):
    return struct.pack('<f', x)


def _gen(c):
    a = c.emu.alloc(16, 4)
    b = c.emu.alloc(16, 4)
    vals = [c.rng.uniform(-10, 10) for _ in range(3)]
    mode = c.rng.choice(['same', 'diff0', 'diff1', 'diff2', 'nan', 'zero'])
    if mode == 'zero':
        vals = [0.0, -0.0, 1.0]
    av = [struct.unpack('<f', _f(v))[0] for v in vals]
    bv = list(av)
    if mode == 'diff0':
        bv[0] = av[0] + 1.0
    elif mode == 'diff1':
        bv[1] = av[1] * 2.0 + 0.5
    elif mode == 'diff2':
        bv[2] = -av[2] if av[2] != 0 else 1.0
    elif mode == 'nan':
        bv[c.rng.randrange(3)] = math.nan
    if mode == 'zero':
        bv = [0.0, 0.0, 1.0]
    c.emu.wbytes(a, b''.join(_f(v) for v in av))
    c.emu.wbytes(b, b''.join(_f(v) for v in bv))
    _ = ss
    return [a, b]


S(0x47f680, 'vec3Equal (GUESS)', 'fastcall', None, ret='al', gen=_gen,
  note='batch244; parked row (ret al); three float compares with NaN not equal')
