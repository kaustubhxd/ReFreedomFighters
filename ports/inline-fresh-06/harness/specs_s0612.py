"""specs_s0612.py - fresh-06 batch 12 (docs/20-fresh-06.md)."""
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


def _mix(*bs):
    n = max(len(b) for b in bs)
    out = bytearray((i * 29 + 7) & 0xff for i in range(n))
    for b in bs:
        for i, x in enumerate(b):
            out[i] = (out[i] * 3 + x) & 0xff
    return bytes(out)


def _cube(c):
    # fastcall math helpers: write a mix of their inputs (by content, never by address) and log contents
    def sub(e, a):
        ecx, edx = e.reg('ecx'), e.reg('edx')
        x, y = e.rbytes(edx, 12), e.rbytes(a[0], 12)
        e.calllog.append(('sub', x, y))
        e.wbytes(ecx, _mix(x, y, b'S'))

    def vmt(e, a):
        ecx, edx = e.reg('ecx'), e.reg('edx')
        x, y = e.rbytes(ecx, 12), e.rbytes(edx, 36)
        e.calllog.append(('vmt', x, y))
        e.wbytes(ecx, _mix(x, y)[:12])

    def mmt(e, a):
        ecx, edx = e.reg('ecx'), e.reg('edx')
        x, y = e.rbytes(edx, 36), e.rbytes(a[0], 36)
        e.calllog.append(('mmt', x, y))
        e.wbytes(ecx, _mix(y, x))

    def mcp(e, a):
        ecx, edx = e.reg('ecx'), e.reg('edx')
        x = e.rbytes(edx, 36)
        e.calllog.append(('mcp', x))
        e.wbytes(ecx, x)
    hk(c, 0x43e920, 1, fn=sub)
    hk(c, 0x441a60, 0, fn=vmt)
    hk(c, 0x4de4b0, 1, fn=mmt)
    hk(c, 0x4de420, 0, fn=mcp)

    def log(name, mi, vi):
        def f(e, a):
            e.calllog.append((name, e.rbytes(a[mi], 36), e.rbytes(a[vi], 12)))
            return c.rng.getrandbits(32) if name == 'dc' else 0
        return f
    A, B = rnd(c, 0x30), rnd(c, 0x30)
    buf = obj(c, 0x10, vt(c, 'buf', {0x3c: (0, A), 0x40: (0, B)}))
    cam = obj(c, 0x10, vt(c, 'cam', {0x94: (2, log('cam', 0, 1))}))
    rdc = c.rng.getrandbits(32)

    def dc(e, a, rdc=rdc):
        e.calllog.append(('dc', e.rbytes(a[2], 36), e.rbytes(a[3], 12)))
        return rdc
    this = obj(c, 0x20, vt(c, 'cg', {0x80: (2, log('s80', 0, 1)), 0xdc: (4, dc)}))
    return [this, buf, cam]


def _zdef(c):
    hk(c, 0x634273, 2, pop=0)
    o = obj(c, 0x10, vt(c, 'o', {0x60: (3, 0)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x138: (0, o), 0x4c: (1, c.rng.getrandbits(32))}))})
    v = obj(c, 0x10, vt(c, 'v', {0x20: (0, c.rng.getrandbits(32))}))
    this = obj(c, 0x60, vt(c, 'zd', {0x58: (0, 0)}))
    c.emu.w32(this + 0x44, v)
    c.emu.wbytes(this + 0x48, bytes([c.rng.choice([0, 1, 0x80])]))
    s = c.rng.choice([0, 0, rnd(c, 8), rnd(c, 8)])
    if s:
        c.emu.wbytes(s, bytes([c.rng.choice([0, 0x41])]))
    c.emu.w32(this + 0x49, s)
    return [this]


def _iterlist(c, name, entries):
    st = [0]

    def begin(e, a):
        e.w32(a[0], 0x1234)
        st[0] = 0
        return 0

    def nxt(e, a):
        i = st[0]
        st[0] += 1
        return entries[i] if i < len(entries) else 0
    return obj(c, 0x10, vt(c, name, {0: (1, 0), 0x4c: (1, begin), 0x64: (1, nxt)}))


def _vnend(c):
    hk(c, 0x634273, 2, pop=0)
    ents = []
    for _ in range(c.rng.randrange(0, 4)):
        en = rnd(c, 8)
        c.emu.wbytes(en + 4, bytes([c.rng.choice([0, 1])]))
        ents.append(en)
    g = obj(c, 0x10, vt(c, 'g', {0x130: (3, 0)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, lambda e, a: c.rng.choice([0, g]))}))})
    this = rnd(c, 0x70)
    c.emu.w32(this + 0x54, c.rng.choice([0, _iterlist(c, 'l', ents)]))
    n = c.rng.randrange(0, 4)
    arr = c.rng.choice([0, rnd(c, 4 * n + 4)])
    if arr:
        for i in range(n):
            c.emu.w32(arr + 4 * i, c.rng.getrandbits(32))
    c.emu.w32(this + 0x68, arr)
    c.emu.w32(this + 0x64, n)
    c.emu.w32(this + 0x6c, c.rng.choice([0, c.rng.getrandbits(32)]))
    return [this]


def _slot(c):
    handler(c)
    hk(c, 0x4ce7b0, 0, ecx=True, ret=c.rng.choice([0xfff, 0x1fff, c.rng.getrandbits(12), c.rng.getrandbits(32)]))
    item = rnd(c, 0x48)
    c.emu.wbytes(item + 0x40, struct.pack('<H', c.rng.choice([0, 0, c.rng.getrandbits(16)])))
    for off in (0x18, 0x1c):
        c.emu.w32(item + off, c.rng.choice([0, 0x80000000, fbits(c)]))
    tab = rnd(c, 0x4000)
    pool = obj(c, 0x10, vt(c, 'pool', {8: (0, c.rng.choice([0, rnd(c, 0x20)]))}))
    this = obj(c, 0xb9a0, vt(c, 'r', {0xb0: (1, 0)}))
    c.emu.w32(this + 0x68, tab)
    c.emu.w32(this + 0x22c, pool)
    c.emu.w32(this + 0x170, c.rng.choice([0, 3, 15, 16]))
    return [this, item, c.rng.getrandbits(32)]


def _evsave(c):
    hk(c, 0x4ccba0, 0, ecx=True, fn=lambda e, a: e.wbytes(e.reg('ecx'), b'TAB32...'))
    hk(c, 0x4cd540, 1, ecx=True)
    hk(c, 0x4ccf60, 0, ecx=True, ret=c.rng.getrandbits(32))
    ents = [rnd(c, 8) for _ in range(c.rng.randrange(0, 4))]
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x4c: (1, lambda e, a: (a[0] * 2654435761) & 0xffffffff)}))})
    this = rnd(c, 0x10)
    c.emu.w32(this + 4, c.rng.choice([0, _iterlist(c, 'l', ents)]))
    sg = obj(c, 0x10, vt(c, 'sg', {0x6c: (1, 0)}))
    return [this, sg]


def _saveall(c):
    def se(e, a):   # SaveEvents may change the mask: drop the highest set bit of every mask byte
        n = e.r32(a[0] + 0xc)
        mp = e.r32(a[0] + 8)
        if n < 8:
            e.wbytes(mp, bytes((b & ~(1 << (b.bit_length() - 1))) if b else 0 for b in e.rbytes(mp, n)))
    hk(c, 0x498f00, 2, ecx=True, fn=se)
    root = rnd(c, 0x10)
    rm = rnd(c, 0xb00)
    c.emu.w32(rm + 0xadc, root)
    eng(c, {0x9b: rm})
    nb = c.rng.randrange(0, 3)
    geoms = rnd(c, 0x380 * max(nb, 1))
    for k in range(8 * nb):
        g = geoms + 0x70 * k
        c.emu.w32(g + 0x3c, c.rng.choice([0, 0x4000000, c.rng.getrandbits(32) & ~0x4000000]))
        chain = [rnd(c, 0x60) for _ in range(c.rng.randrange(0, 3))]
        for i, p in enumerate(chain):
            c.emu.w32(p + 0x50, chain[i + 1] if i + 1 < len(chain) else 0)
        c.emu.w32(g + 0x50, chain[0] if chain else 0)
    arr = rnd(c, 8)
    c.emu.w32(arr + 4, geoms)
    this = rnd(c, 0x20)
    c.emu.w32(this + 0x14, arr)
    mask = rnd(c, max(nb, 1))
    c.emu.wbytes(mask, bytes(c.rng.choice([0, 0xff, c.rng.getrandbits(8)]) for _ in range(max(nb, 1))))
    st = obj(c, 0x10, vt(c, 'st', {8: (1, 0), 0x10: (2, lambda e, a: e.calllog.append(('w', e.rbytes(a[0], 4))) or 0)}))
    vars = rnd(c, 0x10)
    c.emu.w32(vars, st)
    c.emu.w32(vars + 8, mask)
    c.emu.w32(vars + 0xc, nb)
    return [this, vars]


S(0x4599e0, 'ZCubeGridParticles::DrawBufferViewUpdate thiscall', 'thiscall', None, ret='eax', gen=_cube)
S(0x4ca820, 'ZSetZDefine::Init thiscall', 'thiscall', None, gen=_zdef)
S(0x4cb720, 'ZViewNotify::End thiscall', 'thiscall', None, gen=_vnend)
S(0x63f3e0, 'get/create draw slot (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_slot)
S(0x53b2a0, 'CEVENTCONTROLLER::Save thiscall', 'thiscall', None, ret='al', gen=_evsave)
S(0x498be0, 'ZGeomBuffer::SaveAllEvents thiscall', 'thiscall', None, gen=_saveall)
