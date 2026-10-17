"""specs_s0608.py - fresh-06 batch 8 (docs/20-fresh-06.md)."""
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


def _attach(c):
    hk(c, 0x4db9a0, 1, ecx=True, ret=c.rng.choice([0, 1, 0x100]))
    hk(c, 0x4d9ce0, 0, ecx=True)
    g = rnd(c, 0x80)
    p = 0
    if c.rng.random() < 0.8:
        kids = [rnd(c, 0x70) for _ in range(c.rng.randrange(0, 4))]
        for i, k in enumerate(kids):
            c.emu.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
        p = obj(c, 0x60, vt(c, 'p', {0x310: (0, c.rng.choice([0, 1, 0x100])), 0x30c: (0, c.rng.choice([0, 1, 0x100]))}))
        c.emu.w32(p + 0x50, kids[0] if kids else 0)
        t = rnd(c, 0x30)
        c.emu.w32(t + 0x23, c.rng.choice([0x100000, 0x1000f0, 0x200000, c.rng.getrandbits(32)]))
        c.emu.w32(p + 0xc, t)
    c.emu.w32(g + 0x54, p)
    c.emu.w32(g + 0x3c, c.rng.choice([0x40000, 0x40400, 0, c.rng.getrandbits(32)]))
    this = obj(c, 0x40, vt(c, 'tg', {0x2f0: (1, 0)}))
    c.emu.w32(this + 8, c.rng.choice([g, rnd(c, 0x10)]))
    return [this, g]


def _readpix(c):
    loc = b''.join(struct.pack('<I', fbits(c)) for _ in range(3))

    def s8c(e, a, loc=loc):
        e.wbytes(a[0], loc)

    def s214(e, a):
        e.calllog.append(('pt', e.rbytes(a[0], 12).hex()))
        return 0x1234
    this = obj(c, 0x20, vt(c, 'pic', {0x8c: (1, s8c), 0x214: (2, s214)}))
    g = rnd(c, 0x50)
    c.emu.w32(g + 0x40, fbits(c))
    c.emu.w32(g + 0x44, fbits(c))
    c.emu.w32(this + 8, g)
    p = rnd(c, 12)
    return [this, p, rnd(c, 8)]


def _volume(c):
    sm = obj(c, 0x10, vt(c, 'sm', {0xac: (1, 0), 0xbc: (1, 0)}))
    e = obj(c, 0x2000, vt(c, 'eng', {0xbc: (0, sm)}))
    c.emu.w32(0x70039c, e)
    hk(c, 0x57f6b0, 0, ecx=True)
    hk(c, 0x57f750, 0, ecx=True, ret=c.rng.getrandbits(32))
    this = obj(c, 0x200, vt(c, 'self', {0x84: (0, obj(c, 0x10, vt(c, 'o', {0x314: (1, 0)})))}))
    c.emu.w32(this + 0x180, obj(c, 0x10, vt(c, 'sl', {0x36c: (2, 0)})))
    c.emu.w32(this + 0x188, fbits(c))
    return [this]


def _ctor_ae94(c):
    hk(c, 0x4f97f0, 3, ecx=True)
    hk(c, 0x4ccbe0, 2, ecx=True, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x100)] + rv(c, 3)


def _ctor_3fc8(c):
    hk(c, 0x469870, 0, ecx=True)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x114: (4, c.rng.getrandbits(32))}))})
    return [rnd(c, 0x100)]


def _tagged(c):
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x54: (1, seq(rv(c)))}))})
    nodes = [rnd(c, 0x10) for _ in range(c.rng.randrange(0, 4))]
    for i, n in enumerate(nodes):
        for k in range(3):
            c.emu.w32(n + 4 * k, c.rng.choice([0, 1, 7, 8, 0xfffffff9, c.rng.getrandbits(32)]))
        c.emu.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) else 0)
    return [nodes[0] if nodes else 0, c.rng.getrandbits(32)]


def _child(c):
    o = rnd(c, 0x58)
    c.emu.w32(o, 0)
    hk(c, 0x41e290, 1, pop=0, ret=o)  # null alloc faults in the exe too (no check before the vcall)
    hk(c, 0x54cb50, 0, ecx=True)
    # the derived ctor installs the real exe vtable 0x6a383c; stub its two slot targets
    hk(c, c.emu.r32(0x6a383c + 0x3c), 1, ecx=True, name='s3c')
    hk(c, c.emu.r32(0x6a383c + 0x10), 0, ecx=True, name='s10',
       ret=c.rng.choice([0, 1, 0x100, 0xffffff00]))
    return [rnd(c, 0xa280)]


def _ctor_3e3c(c):
    hk(c, 0x469870, 0, ecx=True)
    hk(c, 0x41e290, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x20)]))
    hk(c, 0x4ccbe0, 2, ecx=True, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x80)]


def _blit(c):
    w = c.rng.choice([0, 1, 3, 8, -1])
    h = c.rng.choice([0, 1, 2, 5, -2])
    tw = w if c.rng.random() < 0.8 else max(w, 0) + 2
    th = h if c.rng.random() < 0.8 else max(h, 0) + 1
    x0, y0 = c.rng.randrange(0, 3), c.rng.randrange(0, 3)
    pw, ph = max(tw, 1) + 4, max(th, 1) + 4
    t = rnd(c, 0x20)
    c.emu.w32(t + 4, tw & 0xffffffff)
    c.emu.w32(t + 8, th & 0xffffffff)
    c.emu.w32(t + 0x10, rnd(c, pw * (ph + 4) + 16))
    pal = rnd(c, 0x400)
    this = obj(c, 0x40, vt(c, 'tx', {0x38: (1, t)}))
    c.emu.w32(this + 0x2d, pal)
    stride = c.rng.choice([max(w, 0) * 4, max(w, 0) * 4 + 8])
    dst = rnd(c, stride * (max(h, 0) + 1) + max(w, 0) * 4 + 16)
    handler(c, ret=0)
    return [this, dst, x0, y0, w & 0xffffffff, h & 0xffffffff, stride, c.rng.getrandbits(32)]


def _remove(c):
    nb = c.rng.randrange(1, 4)
    blks = [rnd(c, 0x10 + 20 * 8) for _ in range(nb)]
    for i, b in enumerate(blks):
        c.emu.w32(b + 8, blks[(i + 1) % nb])
        c.emu.w32(b + 0xc, blks[(i - 1) % nb])
        c.emu.wbytes(b, bytes([c.rng.choice([1, 1, 2, 5])]))
    b = c.rng.choice(blks)
    e = b + 0x10 + 20 * c.rng.randrange(8)
    this = obj(c, 0x20, vt(c, 'da', {0x2c: (1, b), 0x34: (1, 0)}))
    c.emu.w32(this + 8, c.rng.choice(blks))
    return [this, e]


def _disc(c):
    n_lo, n_hi = c.rng.randrange(0, 3), c.rng.randrange(0, 2)
    n = n_lo + n_hi
    hk(c, 0x49c980, 2, ecx=True, ret=(n_hi << 16) | n_lo | (c.rng.choice([0, 0]) << 8))
    hk(c, 0x49cbb0, 3, ecx=True, ret=c.rng.choice([0, 1, 2, 3, 0x101]))
    hk(c, 0x49ccc0, 3, ecx=True)
    hk(c, 0x4e6bf0, 1, ecx=True)
    arr = rnd(c, 4 * max(n, 1) + 4)
    for i in range(n):
        c.emu.w32(arr + 4 * i, rnd(c, 0x70))
    this = rnd(c, 0x40)
    c.emu.w32(this + 0x39, arr)
    tab = rnd(c, 0x40)
    c.emu.w32(this + 0x1d, tab)
    g = rnd(c, 0x70)
    idv = c.rng.randrange(0, 8)
    c.emu.w32(g + 0x68, idv)
    ch = [rnd(c, 0x10) for _ in range(c.rng.randrange(0, 4))]
    for i, x in enumerate(ch):
        c.emu.w32(x + 0xc, ch[i + 1] if i + 1 < len(ch) else 0)
    c.emu.w32(tab + 4 * idv, ch[0] if ch else 0)
    return [this, g]


def _lens(c):
    hk(c, 0x4690b0, 2, pop=0)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    handler(c)
    return [rnd(c, 0x80), c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]


S(0x4422e0, 'ZTreeGroup::AttachDynamicGeoms thiscall', 'thiscall', None, gen=_attach)
S(0x45ab60, 'ZPICOBJ::ReadGlobalPixel thiscall', 'thiscall', None, ret='eax', gen=_readpix)
S(0x57f360, 'apply volume slider (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_volume)
S(0x4f7960, 'ctor vtable 0x69ae94 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor_ae94)
S(0x4c38e0, 'ctor vtable 0x693fc8 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor_3fc8)
S(0x49c420, 'resolve tagged pointers (GUESS) stdcall', 'stdcall', None, gen=_tagged)
S(0x54b420, 'create child vtable 0x6a383c (GUESS) thiscall', 'thiscall', None, ret='al', gen=_child)
S(0x4c32a0, 'ctor vtable 0x693e3c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor_3e3c)
S(0x638d60, 'blit 8-bit paletted rect (GUESS) thiscall', 'thiscall', None, gen=_blit)
S(0x64d9e0, 'ZDrawArray<ZPrimDrawEntry>::Remove thiscall', 'thiscall', None, gen=_remove)
S(0x49c560, 'CListUser::DisconnectFromAllMembers thiscall', 'thiscall', None, gen=_disc)
S(0x4be520, 'CLensFlare deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_lens)
