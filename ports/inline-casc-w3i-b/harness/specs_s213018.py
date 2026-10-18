"""specs_s213018.py - batch 213018: typed-record cursor seek and a 3x3x3 grid walk, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _records(r):
    out = bytearray()
    for _ in range(r.randint(0, 8)):
        t = r.choice([r.randint(1, 12)] * 6 + [0, 13, 20, 63])
        hi = r.choice([0, 0x40, 0x80, 0xc0]) if r.random() < 0.3 else 0
        b = (t | hi) & 0xff
        if b == 0xff:
            b = 0x3f
        rec = bytearray([b])
        if t == 1:
            rec += bytes(r.getrandbits(8) for _ in range(8))
        elif t in (2, 3, 8, 10, 11):
            rec += bytes(r.getrandbits(8) for _ in range(4))
        elif t in (4, 5):
            rec += bytes(r.randint(1, 254) for _ in range(r.randint(0, 6))) + b'\0'
        elif t in (7, 9, 12):
            ln = r.randint(4, 12)
            rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
        out += rec
    out.append(0xff)
    return bytes(out)


def g4e0e90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = _records(r)
    buf = rnd(c, len(data) + 16)
    e.wbytes(buf, data)
    this = rnd(c, 0x20)
    e.w32(this + 8, buf)
    want = r.randint(0, 14) if r.random() < 0.9 else r.getrandbits(32)
    return [this, want]


def g457680(c):
    clear_hooks(c)
    r = c.rng
    k = r.random()
    if k < 0.5:
        code = 0
        n = r.randint(0, 12)
        for i in range(n):
            code |= r.choice([0, 1, 2, 3, 4, 5, 0, 3, 6, 7]) << (3 * i)
        code &= 0xffffffff
    else:
        code = r.getrandbits(32)
    return [code]


S(0x4e0e90, 'seek_tag', 'thiscall', None, ret=None, gen=g4e0e90)
S(0x457680, 'grid_walk_mask', 'stdcall', None, ret='eax', gen=g457680)
