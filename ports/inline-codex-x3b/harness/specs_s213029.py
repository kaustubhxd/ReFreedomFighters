"""specs_s213029.py - batch 213029: stack-local out values through slots; typed int record reader, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g486cc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def out_flag(emu, k):
        emu.wbytes(emu.arg32(0), bytes([r.choice([0, 1, 1, 0xff, r.getrandbits(8)])]))

    def out_kind(emu, k):
        emu.w32(emu.arg32(0), r.choice([0, 1, 2, 3, 4, 5, 6, 7, r.getrandbits(32)]))
    a = obj(c, 0x20, {0x50: pystub(c, 1, ret=r.getrandbits(32), this=True),
                      0x68: pystub(c, 1, ret=r.getrandbits(32), this=True, nullflag=(0,), side=out_flag),
                      0x40: pystub(c, 1, ret=r.getrandbits(32), this=True, nullflag=(0,), side=out_kind)}, nslots=0x1c)
    this = rnd(c, 0x40)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [this, a]


def _stream(r, k):
    out = bytearray()
    for _ in range(k):
        t = r.choice([3, 3, 3, 8, 10, 11, 1, 2, 4, 5, 6, 7, 9, 12, 0])
        hi = r.choice([0, 0x40, 0x80, 0x20, 0x10]) if r.random() < 0.3 else 0
        rec = bytearray([t | hi])
        if hi & 0x30:
            t = 0     # effective tag changes: 0x23, 0x2a ... are unknown tags with no payload (advance 1)
            if (rec[0] & 0x3f) <= 11:
                rec[0] = (rec[0] & 0xc0) | 0x30 | (rec[0] & 0xf)
        if t == 1:
            rec += bytes(r.getrandbits(8) for _ in range(8))
        elif t in (2, 3, 8, 10, 11):
            rec += bytes(r.getrandbits(8) for _ in range(4))
        elif t in (4, 5):
            rec += bytes(r.randint(1, 255) for _ in range(r.randint(0, 6))) + b'\0'
        elif t in (7, 9, 12):
            ln = r.randint(4, 10)
            rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
        out += rec
    return bytes(out) + b'\xff' * 40


def g4e11e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randint(1, 6)
    data = _stream(r, r.choice([n, n, n + 1, max(1, n - 1)]))
    buf = rnd(c, len(data) + 8)
    e.wbytes(buf, data)
    this = rnd(c, 0x20)
    e.w32(this + 8, buf)
    out = rnd(c, 0x40)
    L = obj(c, 0x20, {0x24: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0xc)
    e.w32(0x700390, L)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [this, out, n]


S(0x486cc0, 'copy_field_by_kind', 'thiscall', None, ret='eax', gen=g486cc0)
S(0x4e11e0, 'read_int_records', 'thiscall', None, ret='eax', gen=g4e11e0)
