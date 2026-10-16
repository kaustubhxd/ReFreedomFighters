"""specs_s66085.py - cascade s4 batch 66085: 0x466b70 (float fraction from two object fields and a global tick count)."""
import struct
from pilot import S
from recruits_util import clear_hooks, rnd


def _fl(x):
    return struct.pack('<f', x)


def _g466b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nan = float('nan')
    scale = r.choice([1.0, 100.0, 1000.0])
    e.wbytes(0x678620, _fl(scale))
    mul = r.choice([0.5, 1.0, 0.001])
    e.wbytes(0x6785e4, _fl(mul))
    e._image_dirty = True
    t = r.choice([0, 1, 5, 100, 1000, 100000, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)])
    g = e.alloc(0x80, 8)
    e.w32(g + 0x40, t)
    e.w32(0x70039c, g)
    a = r.choice([0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 10.0, -10.0, 1000.0, -1e30, 1e30, nan, float('inf'), -float('inf'), r.uniform(-50, 50)])
    xs = [float(int(t if t < 0x80000000 else t - 0x100000000) - int(abs(a) * scale)) * mul] if abs(a) < 1e9 else [0.0]
    b = r.choice([0.0, -0.0, nan, 1.0, -1.0, 2.0, 0.25, 100.0, -100.0, r.uniform(-200, 200), xs[0], xs[0] + 1, xs[0] - 1])
    o = e.alloc(0x60, 8)
    e.wbytes(o + 0x35, _fl(a))
    e.wbytes(o + 0x31, _fl(b))
    return [o]


S(0x466b70, 'GUESS fraction from two float fields and a global tick', 'thiscall', None, ret='st0', gen=_g466b70, note='batch66085')
