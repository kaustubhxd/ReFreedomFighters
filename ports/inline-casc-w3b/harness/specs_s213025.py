"""specs_s213025.py - batch 213025: parser step with two callbacks; typed record bool reader with log and assert hook, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g62d030(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    e = rnd(c, 0x60)
    seq = r.choice([[0, 0], [0, 1], [1, 0], [0, r.getrandbits(32)], [r.getrandbits(32), 0], [0, 0]])
    c.emu.w32(e + 0x1c, pystub(c, 4, ret=lambda emu, k: seq[min(k, 1)], pop=0))
    b = r.randint(0xd, 0x1b) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.12:
        b = 0x1c
    return [o, b, r.getrandbits(32), r.getrandbits(32), e]


def _rec(r):
    t = r.choice([3, 3, 3, 3, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 20])
    hi = r.choice([0, 0x40, 0x80]) if r.random() < 0.3 else 0
    rec = bytearray([(t | hi) & 0xff])
    if t == 1:
        rec += bytes(r.getrandbits(8) for _ in range(8))
    elif t == 3:
        rec += struct.pack('<I', r.choice([0, 1, r.getrandbits(32)]))
    elif t in (2, 8, 10, 11):
        rec += bytes(r.getrandbits(8) for _ in range(4))
    elif t in (4, 5):
        rec += bytes(r.randint(1, 255) for _ in range(r.randint(0, 5))) + b'\0'
    elif t in (7, 9, 12):
        ln = r.randint(4, 10)
        rec += struct.pack('<I', ln) + bytes(r.getrandbits(8) for _ in range(ln - 4))
    return bytes(rec)


def g4e14a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.randint(0, 6)
    data = b''.join(_rec(r) for _ in range(k)) + b'\xff' * 40
    buf = rnd(c, len(data) + 8)
    e.wbytes(buf, data)
    this = rnd(c, 0x20)
    e.w32(this + 8, buf)
    out = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 3, k, k, k + 1, 6, -1, -5, r.randint(1, 7)])
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [this, out, n & 0xffffffff]


S(0x62d030, 'parser_step_h', 'cdecl', None, ret='eax', gen=g62d030)
S(0x4e14a0, 'read_bool_records', 'thiscall', None, ret=None, gen=g4e14a0)
