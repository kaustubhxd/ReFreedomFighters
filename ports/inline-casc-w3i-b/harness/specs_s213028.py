"""specs_s213028.py - batch 213028: typed stream to ints (real 0x4e5f10/0x4e6420/0x4e6400) and a flag/kind field select, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _stream(r):
    """Records: tag byte (bit 6 = keep reading, set on every record after the first), terminator with bit 6 clear.
    Type 6 does not advance the cursor and may only be the first record (flag clear)."""
    n = r.randint(1, 6)
    out = bytearray()
    for k in range(n):
        t = r.randint(1, 11)
        if k > 0:
            while t == 6:
                t = r.randint(1, 11)
        flag = 0x40 if k > 0 else (r.choice([0, 0x40]) if t != 6 else 0)
        hi = r.choice([0, 0x80]) if r.random() < 0.2 else 0
        rec = bytearray([t | flag | hi])
        if t == 1:
            rec += struct.pack('<d', r.choice([r.uniform(-1e5, 1e5), 0.0, 1e39, -1e39, r.uniform(-3, 3), 2147483648.0, -2147483649.0]))
        elif t == 2:
            rec += struct.pack('<f', r.choice([r.uniform(-1e5, 1e5), 3e9, -3e9, 0.5])) if r.random() < 0.8 else bytes(r.getrandbits(8) for _ in range(4))
        elif t in (3, 8, 10, 11):
            rec += bytes(r.getrandbits(8) for _ in range(4))
        elif t in (4, 5):
            rec += bytes(r.randint(1, 255) for _ in range(r.randint(0, 6))) + b'\0'
        elif t in (7, 9):
            ln = r.randint(5, 12)
            rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
        out += rec
        if k == 0 and flag == 0 and t != 6 and n > 1:
            break
    out.append(r.choice([0x00, 0x3f, 0x80, 0xbf, 0xff, r.getrandbits(8) & 0xbf]))
    return bytes(out)


def g4e6050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = _stream(r)
    buf = rnd(c, len(data) + 16)
    e.wbytes(buf, data)
    this = rnd(c, 0x10)
    e.w32(this, buf)
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    return [this, rnd(c, 0x80)]


def _kobj(c, k):
    return obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)


def g591880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ke = _kobj(c, r.randint(0, 12) if r.random() < 0.9 else r.getrandbits(32))
    o = obj(c, 0x20, {0x350: pystub(c, 0, ret=ke, this=True)}, nslots=0xd5)
    oo = o if r.random() < 0.93 else 0
    slots = {0x50c: pystub(c, 0, ret=oo, this=True),
             0x508: pystub(c, 0, ret=r.choice([0, 1, r.getrandbits(32)]), this=True),
             0x49c: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)}
    this = obj(c, 0x780, slots, nslots=0x144)
    flags = r.choice([0, 0x40000, 0x2000000, 0x2040000, r.getrandbits(32), 0, 0])
    e.wbytes(this + 0x417, struct.pack('<I', flags))
    hook_rec(c, 0x473e50, 0, ret=r.getrandbits(32), this=True)
    return [this]


S(0x4e6050, 'read_ints', 'thiscall', None, ret='eax', gen=g4e6050)
S(0x591880, 'field_by_flags_kind', 'thiscall', None, ret='eax', gen=g591880)
