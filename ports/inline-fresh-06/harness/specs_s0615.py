"""specs_s0615.py - fresh-06 batch 15 (docs/20-fresh-06.md)."""
import struct
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def cstr(e, a):
    out = bytearray()
    while a and len(out) < 256:
        b = e.rbytes(a, 1)[0]
        if not b:
            break
        out.append(b)
        a += 1
    return bytes(out)


def stricmp_stub(c):
    """_stricmp (C locale): difference of the first differing lower-cased bytes."""
    def h(e, r):
        a, b = e.arg32(0), e.arg32(1)
        sa, sb = cstr(e, a), cstr(e, b)
        e.calllog.append(('stricmp', sa, sb))
        v = 0
        for i in range(max(len(sa), len(sb)) + 1):
            x = sa[i] if i < len(sa) else 0
            y = sb[i] if i < len(sb) else 0
            x = x + 32 if 65 <= x <= 90 else x
            y = y + 32 if 65 <= y <= 90 else y
            if x != y or not x:
                v = x - y
                break
        e.ret(eax=v & 0xffffffff)
    c.emu.stub_import('_stricmp', h)


def strz(c, s):
    a = rnd(c, len(s) + 4)
    c.emu.wbytes(a, s + b'\0')
    return a


NAMES = [b'abc', b'ABC', b'abd', b'', b'data\\x.big', b'DATA/X.BIG', b'q']


def _timer(c):
    p = rnd(c, 0x10)
    ins = rnd(c, 8)
    c.emu.w32(p + 4, ins)
    vals = []
    for i in range(4):
        v = rnd(c, 8)
        c.emu.w32(v, c.rng.choice([0, 0x3f800000, 0xbf800000, 0x80000000, 0x7fc00000, c.rng.getrandbits(32)]))
        vals.append(v)
    hk(c, 0x5003d0, 1, ecx=True, fn=lambda e, a: vals[a[0]] if a[0] < 4 else 0)
    stats = {t: rnd(c, 0x20) for t in range(3, 7)}
    hk(c, 0x5a46f0, 1, ecx=True, fn=lambda e, a: stats.get(a[0], 0))
    g = rnd(c, 0x2c30)
    c.emu.w32(g + 0x2c21, rnd(c, 0x60))
    c.emu.w32(0x7003b8, g)
    return [p]


def _big(c):
    stricmp_stub(c)

    def ctor(e, a):
        s = cstr(e, a[0])
        buf = c.emu.alloc(len(s) + 4)
        e.wbytes(buf, s + b'\0')
        e.w32(e.reg('ecx'), buf)
        e.w32(e.reg('ecx') + 4, len(s))
    hk(c, 0x4cbe80, 1, ecx=True, fn=ctor)
    hk(c, 0x4cc5f0, 0, fn=lambda e, a: e.r32(e.reg('ecx') + 4))
    hk(c, 0x4cc1d0, 0, fn=lambda e, a: e.r32(e.reg('ecx')))
    hk(c, 0x4cbec0, 0)
    ents = []
    for _ in range(c.rng.randrange(0, 4)):
        o = rnd(c, 0x14)
        c.emu.w32(o + 0xd, strz(c, c.rng.choice(NAMES)))
        en = rnd(c, 4)
        c.emu.w32(en, o)
        ents.append(en)
    st = [0]

    def begin(e, a):
        st[0] = 0
        e.w32(a[0], 0x77)

    def nxt(e, a):
        i = st[0]
        st[0] += 1
        return ents[i] if i < len(ents) else 0
    this = rnd(c, 0x10)
    c.emu.w32(this + 4, c.rng.choice([0, obj(c, 0x10, vt(c, 'l', {0x4c: (1, begin), 0x64: (1, nxt)}))]))
    return [this, strz(c, c.rng.choice(NAMES))]


def _sym(c):
    stricmp_stub(c)
    handler(c)
    n = c.rng.randrange(0, 5)
    arr = rnd(c, 4 * n + 4)
    for i in range(n):
        rec = rnd(c, 0x10)
        c.emu.w32(rec, c.rng.choice([0, 0, 1]))
        c.emu.w32(rec + 0xc, strz(c, c.rng.choice(NAMES)))
        pr = rnd(c, 4)
        c.emu.w32(pr, rec)
        c.emu.w32(arr + 4 * i, pr)
    this = rnd(c, 0x10)
    c.emu.w32(this + 4, arr)
    c.emu.w32(this + 0xc, n)
    return [this, strz(c, c.rng.choice(NAMES))]


def _hash(c):
    stricmp_stub(c)
    nb = c.rng.randrange(1, 5)
    bk = rnd(c, 4 * nb)
    for i in range(nb):
        chain = 0
        for _ in range(c.rng.randrange(0, 3)):
            nd = rnd(c, 10)
            c.emu.w32(nd, chain)
            c.emu.w32(nd + 4, strz(c, c.rng.choice(NAMES)))
            chain = nd
        c.emu.w32(bk + 4 * i, chain)
    this = rnd(c, 0x20)
    c.emu.w32(this + 3, bk)
    c.emu.w32(this + 7, bk + 4 * nb)
    hk(c, 0x6073b0, 1, ecx=True)
    hk(c, 0x606ea0, 2, ecx=True, ret=c.rng.randrange(nb))
    hk(c, 0x6014a0, 1, ecx=True, ret=rnd(c, 0x10))
    pair = rnd(c, 8)
    c.emu.w32(pair, strz(c, c.rng.choice(NAMES)))
    return [this, pair]


S(0x5600a0, 'CFFMPGameControl_if::SetTimer stdcall', 'stdcall', None, gen=_timer)
S(0x4346e0, 'ZSysFile::BigLoaded thiscall', 'thiscall', None, ret='al', gen=_big)
S(0x601720, 'CSdlDataExchange::getExportSymbolInt thiscall', 'thiscall', None, ret='eax', gen=_sym)
S(0x607260, 'hashtable<const char*,u16>::find_or_insert thiscall', 'thiscall', None, ret='eax', gen=_hash)
