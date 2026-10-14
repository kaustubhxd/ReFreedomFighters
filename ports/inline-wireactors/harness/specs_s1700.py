"""specs_s1700.py - wire-actors thread: vangle 0x4e0030 (fastcall, result in ST0)."""
from pilot import S


def _v(c, scale=1000.0):
    v = c.emu.alloc(0x20, 4)
    for i in range(3):
        c.emu.wf32(v + 4 * i, c.rng.uniform(-scale, scale))
    return v


def _set(c, v, vals):
    for i, x in enumerate(vals):
        c.emu.wf32(v + 4 * i, x)


def _gen(c):
    r = c.rng
    a = _v(c)
    b = _v(c, r.choice([1.0, 100.0, 1000.0]))
    k = r.random()
    if k < 0.1:      # parallel (c near 1: the clamp)
        f = r.choice([0.5, 2.0, 7.25])
        _set(c, b, [c.emu.rf32(a + 4 * i) * f for i in range(3)])
    elif k < 0.2:    # opposite
        _set(c, b, [-c.emu.rf32(a + 4 * i) for i in range(3)])
    elif k < 0.25:   # zero vector (0 / 0)
        _set(c, b, [0.0, 0.0, 0.0])
    elif k < 0.3:
        _set(c, a, [0.0, 0.0, 0.0])
    elif k < 0.4:    # axis aligned
        _set(c, a, [1.0, 0.0, 0.0]); _set(c, b, [r.choice([1.0, 0.0, -1.0]), r.choice([0.0, 1.0]), 0.0])
    return [a, b]


S(0x4e0030, 'vangle', 'fastcall', None, ret='st0', gen=_gen, note='wire-actors; angle between two vectors, ST0')
