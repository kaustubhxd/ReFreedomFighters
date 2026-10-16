"""specs_s0611.py - fresh-06 batch 11 (docs/20-fresh-06.md)."""
import math
import struct
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def fbits(c):
    v = c.rng.choice([0.0, -0.0, 1.0, 0.5, -2.5, 100.0, 1e-30, 1e30, math.inf, -math.inf, math.nan,
                      c.rng.uniform(-1e3, 1e3)])
    b = struct.unpack('<I', struct.pack('<f', v))[0]
    if c.rng.random() < 0.1:
        b = 0x7f800000 | c.rng.getrandbits(23) | (c.rng.getrandbits(1) << 31)   # NaN payloads
    return b


def _szinit(c):
    hk(c, 0x562440, 0, ecx=True)
    m = rnd(c, 0x1048)
    k = c.rng.randrange(4)
    if k == 0:
        s = c.emu.rbytes(0x6a6e5c, 32).split(b'\0')[0] + b'\0'
    elif k == 1:
        s = c.emu.rbytes(0x6a8558, 32).split(b'\0')[0] + b'\0'
    elif k == 2:
        s = c.emu.rbytes(0x6a6e5c, 32).split(b'\0')[0][:-1] + b'Q\0'
    else:
        s = bytes(c.rng.randrange(1, 256) for _ in range(c.rng.randrange(0, 6))) + b'\0'
    c.emu.wbytes(m + 0x48, s)
    c.emu.wbytes(m + 0x1040, bytes([c.rng.choice([0, 0, 1])]))
    o = obj(c, 0x10, vt(c, 'o', {0x60: (3, 0)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x138: (0, o), 0x4c: (1, c.rng.getrandbits(32))}))})
    this = rnd(c, 0xa0)
    c.emu.w32(this + 0x94, m)
    return [this]


def _gate(c):
    hk(c, 0x4dc630, 2, ecx=True)
    lst = c.rng.choice([0, obj(c, 0x10, vt(c, 'gl', {0: (1, 0), 0x3c: (1, 0), 0x14: (0, c.rng.choice([0, 0, 1, 5]))}))])
    rooms = [rnd(c, 0xb0) for _ in range(c.rng.randrange(1, 4))]
    for i, r in enumerate(rooms):
        nxt = rooms[i + 1] if i + 1 < len(rooms) else 0
        c.emu.w32(r, vt(c, 'room%d' % i, {0x20: (0, nxt), 0x1e0: (1, c.rng.choice([0, 1, 1, 0x100, 0xffffff01]))}))
        c.emu.w32(r + 0xa4, c.rng.choice([0, 0, 0, 1]))
    this = rooms[0]
    c.emu.w32(this + 0xa4, lst)
    kids = [rnd(c, 0x70) for _ in range(c.rng.randrange(0, 4))]
    for i, k in enumerate(kids):
        c.emu.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
        if c.rng.random() < 0.8:
            p = rnd(c, 0x10)
            t = rnd(c, 0x30)
            c.emu.w32(t + 0x23, c.rng.choice([0x100000, 0x1000f0, 0, c.rng.getrandbits(32)]))
            c.emu.w32(p + 0xc, t)
            c.emu.w32(k + 0x54, p)
        else:
            c.emu.w32(k + 0x54, 0)
        c.emu.w32(k + 0x3c, c.rng.choice([0, 0x400000, c.rng.getrandbits(32) & ~0x400000]))
    c.emu.w32(this + 0x50, kids[0] if kids else 0)
    return [this, c.rng.getrandbits(32)]


def _rdtor(c):
    hk(c, 0x64f380, 0, ecx=True)
    c.emu.w32(0x70039c, obj(c, 0x200, vt(c, 'eng', {0x1a8: (1, 0)})))
    this = rnd(c, 0x1200)
    for i, off in enumerate((0x11df, 0x11db, 0x11e3, 0x1143)):
        c.emu.w32(this + off, c.rng.choice([0, obj(c, 0x10, vt(c, 'o%d' % i, {0: (1, 0)}))]))
    return [this]


def _mk(c):
    hk(c, 0x45c4f0, 2, pop=0, ret=c.rng.choice([0, rnd(c, 0xb0), rnd(c, 0xb0)]))
    hk(c, 0x4ee240, 3, ecx=True)
    return [rnd(c, 0x10), rnd(c, 0x10), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _span(c):
    x0 = c.rng.randrange(0, 8)
    x1 = x0 + c.rng.randrange(1, 24)
    y0 = c.rng.randrange(0, 64)
    y1 = c.rng.randrange(0, 64)
    buf = rnd(c, 4 * (x1 + 1))
    for i in range(x1 + 1):
        c.emu.w32(buf + 4 * i, fbits(c))
    return [x0, x1, y0, y1, buf]


S(0x576260, 'ZSubZoneMap::Init thiscall', 'thiscall', None, gen=_szinit)
S(0x444fe0, 'ZROOM::RemoveGate thiscall', 'thiscall', None, gen=_gate)
S(0x658020, 'ZRender::~ZRender thiscall', 'thiscall', None, gen=_rdtor)
S(0x4ee0e0, 'placement factory 0x698118 (GUESS) fastcall', 'fastcall', None, ret='eax', gen=_mk)
S(0x40c320, 'span scale by table (GUESS) cdecl', 'cdecl', None, gen=_span)
