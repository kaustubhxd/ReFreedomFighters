"""specs_s213011.py - batch 213011: typed value reader returning a float on the x87 stack, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g4e5f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    tag = r.randint(1, 12) if r.random() < 0.9 else r.getrandbits(8)
    if r.random() < 0.3:
        tag |= r.choice([0x40, 0x80, 0xc0])
    d = bytes([tag])
    k = r.random()
    if k < 0.4:
        d += struct.pack('<d', r.choice([r.uniform(-1e6, 1e6), 0.0, 1e39, -1e39, 1e-50, r.uniform(-3, 3)]))
    elif k < 0.7:
        d += struct.pack('<f', r.uniform(-1e6, 1e6)) + bytes(r.getrandbits(8) for _ in range(4))
    else:
        d += bytes(r.getrandbits(8) for _ in range(8))
        if r.random() < 0.3:
            d = d[:4] + b'\xff\xff\xff\x7f'[:0] + d[4:]
    buf = rnd(c, 0x20)
    e.wbytes(buf, d.ljust(0x20, b'\0'))
    this = rnd(c, 0x10)
    e.w32(this, buf)
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    return [this]


S(0x4e5f90, 'typed_value_to_float', 'thiscall', None, ret='st0', gen=g4e5f90)
