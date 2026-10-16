"""specs_s213024.py - batch 213024: parser step with callback, typed record skipper with a visitor, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g62d360(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    e = rnd(c, 0x60)
    c.emu.w32(e + 0x1c, pystub(c, 4, ret=r.choice([0, 1, r.getrandbits(32)]), pop=0))
    b = r.randint(0xd, 0x2c) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.12:
        b = 0x1c
    return [o, b, r.getrandbits(32), r.getrandbits(32), e]


def g4e6330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = r.choice([9, 9, 9, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 0, 13, 63])
    hi = r.choice([0, 0x40, 0x80]) if r.random() < 0.3 else 0
    rec = bytearray([t | hi])
    if t == 9:
        k = r.randint(1, 6)
        rec += struct.pack('<I', 4 * k)
        for _ in range(k - 1):
            rec += struct.pack('<I', r.choice([0, 0, r.getrandbits(32)]))
        rec += bytes(r.getrandbits(8) for _ in range(5))
    elif t == 1:
        rec += bytes(r.getrandbits(8) for _ in range(8))
    elif t in (2, 3, 8, 10, 11):
        rec += bytes(r.getrandbits(8) for _ in range(4))
    elif t in (4, 5):
        rec += bytes(r.randint(1, 255) for _ in range(r.randint(0, 6))) + b'\0'
    elif t in (7, 12):
        ln = r.randint(4, 12)
        rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
    buf = rnd(c, len(rec) + 32)
    e.wbytes(buf, bytes(rec))
    this = rnd(c, 0x10)
    e.w32(this, buf)
    visitor = obj(c, 0x20, {4: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=4)
    return [this, visitor]


S(0x62d360, 'parser_step_g', 'cdecl', None, ret='eax', gen=g62d360)
S(0x4e6330, 'skip_record_visit', 'thiscall', None, ret=None, gen=g4e6330)
