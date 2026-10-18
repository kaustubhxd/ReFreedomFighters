"""specs_s213014.py - batch 213014: typed value stream readers (real verified helpers 0x4e5f90/0x4e6400/0x4e6420), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _stream(r):
    """Record = tag byte (low 6 bits type, bit 6 = "valid, keep reading") + payload. The reader takes the first record
    unconditionally and goes on while the NEXT tag byte has bit 6 set. Type 6 does not advance the cursor, so it may only be
    the first record with bit 6 clear (a set bit would loop forever)."""
    n = r.randint(1, 6)
    out = bytearray()
    for k in range(n):
        t = r.randint(1, 11)
        if k > 0:
            while t == 6:
                t = r.randint(1, 11)
        flag = 0x40 if k > 0 else r.choice([0, 0x40]) if t != 6 else 0
        hi = r.choice([0, 0x80]) if r.random() < 0.2 else 0
        rec = bytearray([t | flag | hi])
        if t == 1:
            rec += struct.pack('<d', r.choice([r.uniform(-1e5, 1e5), 0.0, 1e39, r.uniform(-3, 3)]))
        elif t == 2:
            rec += struct.pack('<f', r.uniform(-1e5, 1e5)) if r.random() < 0.7 else bytes(r.getrandbits(8) for _ in range(4))
        elif t in (3, 8, 10, 11):
            rec += bytes(r.getrandbits(8) for _ in range(4))
        elif t in (4, 5):
            rec += bytes(r.randint(1, 255) for _ in range(r.randint(0, 6))) + b'\0'
        elif t in (7, 9):
            ln = r.randint(5, 12)
            rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
        out += rec
        if k == 0 and flag == 0 and t != 6 and n > 1:
            break          # first record without the flag: the reader stops after it
    out.append(r.choice([0x00, 0x3f, 0x80, 0xbf, 0xff, r.getrandbits(8) & 0xbf]))   # terminator: bit 6 clear (or 0xff)
    return bytes(out)


def _setup(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = _stream(r)
    import os
    if os.environ.get('DBG'):
        print('STREAM', data.hex())
    buf = rnd(c, len(data) + 16)
    e.wbytes(buf, data)
    this = rnd(c, 0x10)
    e.w32(this, buf)
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    return this, rnd(c, 0x80)


def g4e6180(c):
    this, out = _setup(c)
    return [this, out]


S(0x4e6180, 'read_floats', 'thiscall', None, ret='eax', gen=g4e6180)
S(0x4e6250, 'read_doubles', 'thiscall', None, ret='eax', gen=g4e6180)
