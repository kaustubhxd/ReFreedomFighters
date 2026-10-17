"""specs_f0110.py - fresh-01 batch 10 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _render(c, impl=None, argw=None):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = obj(c, 0x20, 'render', 0x60, impl or {}, argw or {})
    c.emu.w32(eng + 0x9b, r)
    return r


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _logmgr(c, n):
    def s2c(e, r):
        e.calllog.append(('log',) + tuple(e.arg32(k) for k in range(n)))
        e.ret(eax=0x10910000)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))


def _bones(c):
    n = c.rng.randint(0, 4)
    arr = rnd(c, 4 * n + 4)
    ids = {}
    for i in range(n):
        e = rnd(c, 0x20)
        c.emu.w32(arr + 4 * i, e)
        if c.rng.random() < 0.7:
            ids[c.emu.r32(e + 0x10)] = obj(c, 0x20, 'g', 0xb0, {}, {0x294: 2, 0x290: 4})
    _render(c, {0x58: lambda e, a: (ids.get(a[0], 0), None)}, {0x58: 1})
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x1c, n)
    c.emu.w32(o + 0x20, arr)
    return [o, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


def _fact(c):
    r = _render(c)
    sel = c.rng.random() < 0.8
    p = rnd(c, 0x200)
    c.emu.w32(r + 8, obj(c, 0x10, 'alloc', 0x20, {0x44: lambda e, a: (p if sel else 0, None)}, {0x44: 1}))
    hk(c, 0x469870, 'ctor', 0)
    hk(c, 0x4ccba0, 'REFTAB32', 0)
    return [c.rng.getrandbits(32)]


def _remove(c):
    n = c.rng.randint(1, 4)
    blocks = [rnd(c, 0x20) for _ in range(n)]
    for i, b in enumerate(blocks):
        c.emu.w32(b + 8, blocks[(i + 1) % n])
        c.emu.w32(b + 0xc, blocks[(i - 1) % n])
        c.emu.w8(b, c.rng.choice([1, 1, 2, 5]))
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, blocks[c.rng.randint(0, n - 1)])
    tb = blocks[c.rng.randint(0, n - 1)]
    entry = rnd(c, 0x10)
    c.emu.w32(o, c.emu.logging_vtable('arr', 0x10, {0x2c: lambda e, a: (tb, None)}, {0x2c: 1, 0x34: 1}))
    return [o, entry]


def _buf(c):
    k = c.rng.random()
    r = rnd(c, 0x20)
    cap = rnd(c, 0x10)
    c.emu.w32(r + 0x11, cap)
    n = c.rng.choice([0, 1, 100, -5, c.rng.getrandbits(32)]) & 0xffffffff
    c.emu.w32(cap + 8, c.rng.choice([n, (n + 1) & 0xffffffff, (n - 1) & 0xffffffff, c.rng.getrandbits(32)]))
    o = rnd(c, 0x200)
    c.emu.w32(o + 0x1cc, c.emu.logging_vtable('pool', 0x8, {0xc: lambda e, a: ((r if k < 0.5 else 0), None)}, {0xc: 2}))
    hk(c, 0x4cfbe0, 'fallback', 0, eax=lambda e: r if k < 0.75 else 0)
    _logmgr(c, 3)
    c.emu.w32(0x70038c, obj(c, 0x20, 'rm', 0x20, {}))
    _handler(c)
    return [o, n]


def _gf(c):
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0x40)
    hk(c, 0x45c4f0, 'alloc at', 2, eax=p, regs=(), pop=False)
    hk(c, 0x45c4b0, 'alloc', 1, eax=p, regs=(), pop=False)
    hk(c, 0x457030, 'ctor', 3, eax=lambda e: e.reg('ecx') + 1)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32),
            c.rng.choice([0, c.rng.getrandbits(32)])]


def _ring(c):
    o = rnd(c, 0x1100)
    idx = c.rng.randint(0, 19)
    c.emu.w32(o + 0x10d3, idx)
    if c.rng.random() < 0.4:
        c.emu.w32(o + 0xfb7 + 4 * idx, 0)
    s = bytes(c.rng.choice(b'abcXYZ ') for _ in range(c.rng.randint(0, 20))) + b'\0'
    sp = rnd(c, len(s) + 4)
    c.emu.wbytes(sp, s)
    buf = rnd(c, 0x20)
    hk(c, 0x41e290, 'new', 1, eax=buf, regs=(), pop=False)
    hk(c, 0x634273, 'delete', 2, regs=(), pop=False)
    return [o, sp]


def _wf(c):
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0xa0)
    hk(c, 0x45c4f0, 'alloc at', 2, eax=p, regs=(), pop=False)
    hk(c, 0x4f97f0, 'ctor', 3)
    return [c.rng.getrandbits(32) for _ in range(4)]


S(0x44e590, 'ZBoneParticle::SaveCleanup', 'thiscall', None, ret=None, gen=_bones)
S(0x4beb10, 'factory 0x4beb10', 'thiscall', None, ret='eax', gen=_fact)
S(0x63f610, 'ZDrawArray<ZArrayBlock>::Remove', 'thiscall', None, ret=None, gen=_remove)
S(0x4d0590, 'buffer lookup 0x4d0590', 'thiscall', None, ret='eax', gen=_buf)
S(0x457410, 'geom factory 0x457410', 'fastcall', None, ret='eax', gen=_gf)
S(0x4d4050, 'string ring 0x4d4050', 'thiscall', None, ret=None, gen=_ring)
S(0x4f4990, 'window factory 0x4f4990', 'fastcall', None, ret='eax', gen=_wf)
