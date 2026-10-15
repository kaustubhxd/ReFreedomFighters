"""specs_s83000.py - u6 batch 83000: 0x4e2800 (rectangle intersection test with NaN checks)."""
from pilot import S, F

def g4e2800(c):
    r = c.rng
    e = c.emu

    # Generate random float parameters for the rectangles
    # Each rectangle has 4 floats (minx, miny, maxx, maxy)
    a1 = r.uniform(-10.0, 10.0)
    a2 = r.uniform(-10.0, 10.0)
    a3 = r.uniform(a1, a1 + 20.0)
    a4 = r.uniform(a2, a2 + 20.0)

    a5 = r.uniform(-10.0, 10.0)
    a6 = r.uniform(-10.0, 10.0)
    a7 = r.uniform(a5, a5 + 20.0)
    a8 = r.uniform(a6, a6 + 20.0)

    a9 = r.uniform(-10.0, 10.0)
    a10 = r.uniform(-10.0, 10.0)
    a11 = r.uniform(a9, a9 + 20.0)
    a12 = r.uniform(a10, a10 + 20.0)

    # Output buffer for the result
    out = c.emu.alloc(4, 4)

    return [out,
            F(a1), F(a2), F(a3), F(a4),
            F(a5), F(a6), F(a7), F(a8),
            F(a9), F(a10), F(a11), F(a12)]

S(0x4e2800, 'rectangle intersection test', 'thiscall', None, ret='al', gen=g4e2800, note='batch83000')
