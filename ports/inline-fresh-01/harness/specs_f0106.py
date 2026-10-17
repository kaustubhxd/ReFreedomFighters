"""specs_f0106.py - fresh-01 batch 6 (docs/20-fresh-01.md)."""
import os
from pilot import S
from helpers01 import rnd, hk, obj


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _engine(c, n=0x200):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _pool(c):
    o = rnd(c, 0xd700)
    got = c.rng.random() < 0.85
    c.emu.w32(o + 0x1ea, c.emu.logging_vtable('pool', 4, {8: lambda e, a: ((a[0] ^ 0x8000) if got else 0, None),
                                                           4: lambda e, a: (a[0] + 0x40, None)}, {8: 2, 4: 1}))
    c.emu.w32(o + 0xd628, c.rng.randint(1, 0x400))
    _handler(c)
    return [o, c.rng.getrandbits(32)]


FAULTS = os.environ.get('FRESH01_FAULTS') == '1'   # dev check of the null-write branch (not part of strict runs)


def _slot(c):
    o = rnd(c, 0x80)
    base = rnd(c, 0x10)
    first = 0x21000000
    c.emu.w32(base + 4, first)
    c.emu.w32(o + 0x14, base)
    cnt = c.rng.randint(0, 8) * 112 + c.rng.randint(0, 111)
    c.emu.w32(o + 0x28, cnt)
    tab = rnd(c, 0x100)
    c.emu.w32(o + 0x5d, tab + 0x40)
    k = c.rng.randint(cnt // 112 - 8, cnt // 112 + 8)
    ent = rnd(c, 0x40)
    flags = c.emu.r32(ent + 0x3c) & ~0x8000000
    if FAULTS and c.rng.random() < 0.3:
        flags |= 0x8000000
    c.emu.w32(ent + 0x3c, flags)
    # the entry's address only enters through (entry - first); move `first` so the difference is k*112 + r
    c.emu.w32(base + 4, (ent - (k * 112 + c.rng.randint(-111, 111))) & 0xffffffff)
    if c.rng.random() < 0.15:
        # counts at 2^31 and up: the count is divided unsigned (0x1249249 for 0x7ffffff0..0x8000005f) while the entry
        # difference is divided signed
        c.emu.w32(o + 0x28, 0x80000000 + c.rng.randint(0, 0x5f))
        c.emu.w32(base + 4, (ent - (0x7ffffff0 + c.rng.randint(0, 15))) & 0xffffffff)
    return [o, ent, c.rng.getrandbits(32)]


def _str(c, n):
    return bytes(c.rng.choice(b'abcAB/._\\') for _ in range(n))


def _fl(c):
    txt = _str(c, c.rng.randint(0, 12))
    st = _str(c, c.rng.randint(0, 4))
    t = rnd(c, len(txt) + 8)
    c.emu.wbytes(t, txt)
    s = rnd(c, len(st) + 8)
    c.emu.wbytes(s, st)
    out = rnd(c, 8)
    last = t + c.rng.randint(0, len(txt))
    return [out, s, last, t, s + len(st), c.rng.getrandbits(32)]


def _sfl(c):
    txt = _str(c, c.rng.randint(0, 12))
    t = rnd(c, len(txt) + 8)
    c.emu.wbytes(t, txt)
    o = rnd(c, 8)
    c.emu.w32(o, t)
    c.emu.w32(o + 4, t + len(txt))
    st = _str(c, c.rng.randint(0, 4)) + b'\0'
    s = rnd(c, len(st) + 4)
    c.emu.wbytes(s, st)
    return [o, s, c.rng.choice([0, 1, 3, 0xffffffff, c.rng.randint(0, 20)])]


def _all(c):
    o = rnd(c, 0x80)
    for cnt, base, n, slot in ((0xc, 4, 2, 0x2c), (0x1c, 0x10, 3, 0x2c), (0x60, 0x20, 16, 0x54)):
        k = c.rng.randint(0, n)
        c.emu.w32(o + cnt, k)
        for i in range(k):
            c.emu.w32(o + base + 4 * i, obj(c, 0x10, 'o%x' % base, 0x18, {}))
    return [o]


def _fact(ctor):
    def g(c):
        eng = _engine(c)
        r = rnd(c, 0x20)
        c.emu.w32(eng + 0x9b, r)
        sel = c.rng.random() < 0.8
        p = rnd(c, 0x100)
        c.emu.w32(r + 8, obj(c, 0x10, 'alloc', 0x20, {0x44: lambda e, a: (p if sel else 0, None)}, {0x44: 1}))
        hk(c, ctor, 'ctor', 0)
        return [c.rng.getrandbits(32)]
    return g


def _sorted(c):
    n = c.rng.choice([0, 1, 2, 5, 16, 0x40000000, 0x40000001, 0xffffffff])
    src = rnd(c, 0x80)
    buf = rnd(c, 0x80)
    hk(c, 0x41e290, 'new', 1, eax=buf, regs=(), pop=False)

    def mc(e, r):
        d, s_, k = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, k))
        if k <= 0x40:
            e.wbytes(d, e.rbytes(s_, k))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)

    def qs(e, r):
        e.calllog.append(('qsort', tuple(e.arg32(k) for k in range(4))))
        e.ret()
    c.emu.stub_import('qsort', qs)
    return [rnd(c, 0x20), src, n]


def _ut(c):
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0x20)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x603500, 'OpaqueUserType_t', 1, eax=lambda e: e.reg('ecx') + 1)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _center(c):
    eng = _engine(c)
    for off in (0x6f, 0x73):
        c.emu.w32(eng + off, c.rng.choice([0, 1, -1, 3, -3, 640, 481, -0x80000000, 0x7fffffff, c.rng.getrandbits(32)]) & 0xffffffff)

    def s70(e, r):
        e.calllog.append(('SetCenter', e.reg('ecx'), e.rbytes(e.arg32(0), 12).hex()))
        e.ret(argbytes=4)
    cam = rnd(c, 0x20)
    c.emu.w32(cam, c.emu.fake_vtable('cam', 0x20, {0x70: s70}))
    o = obj(c, 0x80, 'center', 0x20, {})
    c.emu.w32(o + 0x44, cam)
    return [o]


S(0x4d0950, 'id pool 0x4d0950', 'thiscall', None, ret='eax', gen=_pool)
S(0x499810, 'set slot 0x499810', 'thiscall', None, ret=None, gen=_slot)
S(0x5f1050, 'find_last_of 0x5f1050', ('regs', ['ecx', 'edx', 's', 's', 's', 's']), None, ret='eax', gen=_fl)
S(0x5fba50, 'string find_last_of 0x5fba50', 'thiscall', None, ret='eax', gen=_sfl)
S(0x429b50, 'call all 0x429b50', 'thiscall', None, ret=None, gen=_all)
S(0x4a63d0, 'factory 0x4a63d0', 'thiscall', None, ret='eax', gen=_fact(0x4a6270))
S(0x4b2950, 'factory 0x4b2950 (CCutSequenceCharacterSound)', 'thiscall', None, ret='eax', gen=_fact(0x4b1ca0))
S(0x4d3f10, 'sorted array ctor 0x4d3f10', 'thiscall', None, ret='eax', gen=_sorted)
S(0x5f30d0, 'OpaqueUserTypeFactory_t::produceOpaqueObject', 'thiscall', None, ret='eax', gen=_ut)
S(0x5bf550, 'ZCenter::Init', 'thiscall', None, ret=None, gen=_center)
