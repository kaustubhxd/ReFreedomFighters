"""specs_f0107.py - fresh-01 batch 7 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _engine(c, n=0x200):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _render(c, impl=None, argw=None):
    eng = _engine(c)
    r = obj(c, 0x20, 'render', 0x60, impl or {}, argw or {})
    c.emu.w32(eng + 0x9b, r)
    return r


def _fact(ctor):
    def g(c):
        r = _render(c)
        sel = c.rng.random() < 0.8
        p = rnd(c, 0x100)
        c.emu.w32(r + 8, obj(c, 0x10, 'alloc', 0x20, {0x44: lambda e, a: (p if sel else 0, None)}, {0x44: 1}))
        hk(c, ctor, 'ctor', 0)
        return [c.rng.getrandbits(32)]
    return g


def _copy(c):
    hk(c, 0x442c00, 'ZTreeGroup::CopyData', 1, eax=0x44c0)
    c.emu.w32(0x70038c, obj(c, 0x20, 'rm', 0x40, {}, {0xbc: 1}))
    k = c.rng.random() < 0.6
    src = obj(c, 0x100, 'src', 0x80, {0x1e0: lambda e, a: (0x1e000 | int(k), None)}, {0x1e0: 1})
    return [rnd(c, 0x100), src]


def _hash(c):
    o = rnd(c, 0x3410)
    nb = c.rng.randint(1, 5)
    c.emu.w32(o + 0x3408, nb)
    for b in range(nb):
        prev = 0
        for _ in range(c.rng.choice([0, 0, 1, 2, 3])):
            e = rnd(c, 0x10)
            c.emu.w32(e + 8, prev)
            prev = e
        c.emu.w32(o + 4 * b, prev)
    mode = c.rng.choice([0, 1, 2])
    sink = rnd(c, 0x10)
    st = obj(c, 0x20, 'stream', 0x10, {0x18: lambda e, a: (mode, None), 4: lambda e, a: (sink, None)}, {4: 1})
    return [o, st]


def _remove(c):
    o = rnd(c, 0x100)
    c.emu.w32(o + 0xc8, c.emu.logging_vtable('a', 0x30, {}, {0x88: 1}))
    k = c.rng.random()
    r = rnd(c, 0x10)
    c.emu.w32(r + 4, 0 if k < 0.4 else rnd(c, 0x80))
    c.emu.w32(o + 0xac, c.emu.logging_vtable('m', 0x30, {0x84: lambda e, a: ((r if k < 0.8 else 0), None)}, {0x84: 1, 0x90: 1}))
    eng = _engine(c)
    c.emu.w32(eng, c.emu.logging_vtable('eng', 0x30, {}, {0x64: 1}))
    hk(c, 0x4cbec0, '~MYSTR', 0)
    hk(c, 0x634273, 'delete', 2, regs=(), pop=False)
    return [o, c.rng.getrandbits(32)]


def _rmcam(c):
    _render(c, {0x4c: lambda e, a: (a[0] ^ 0x4c4c, None)}, {0x4c: 1})
    k = c.rng.random()
    lst = obj(c, 0x20, 'list', 0x20, {0x28: lambda e, a: (int(k < 0.7), None)}, {0x28: 1, 0x3c: 1})
    v = obj(c, 0x20, 'v', 0x10, {}, {0xc: 1})
    o = obj(c, 0x100, 'renderer', 0x30, {0xa4: lambda e, a: ((v if k < 0.5 else 0), None)}, {0xa4: 1})
    c.emu.w32(o + 0x8c, lst)
    return [o, c.rng.getrandbits(32)]


def _block(c):
    n = c.rng.choice([1, 2, 3, 8, 16])
    b = rnd(c, 0x10 + 0x20 * n + 0x20)
    k = c.rng.random() < 0.85
    o = obj(c, 0x20, 'arr', 0x10, {0x30: lambda e, a: ((b if k else 0), None), 0x28: lambda e, a: (n, None)})
    if c.rng.random() < 0.6:
        cb = rnd(c, 0x20)
        t = rnd(c, 0x20) if c.rng.random() < 0.5 else cb
        c.emu.w32(cb + 0xc, t)
        c.emu.w32(o + 8, cb)
    else:
        c.emu.w32(o + 8, 0)
    return [o]


def _ctor(c):
    hk(c, 0x43de40, 'ZSTDOBJ ctor', 3)
    hk(c, 0x4dcdf0, 'SetPrim', 1)
    return [rnd(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _dup(c):
    r = rnd(c, 0x100)
    hk(c, 0x440220, 'ZGROUP::DuplicateToResource', 5, eax=r)
    return [rnd(c, 0x100)] + [c.rng.getrandbits(32) for _ in range(5)]


def _s5a(c):
    k = c.rng.random()
    t = c.rng.choice([2, 3, 4, 9, 10, -5, -0x80000000, c.rng.getrandbits(32)]) & 0xffffffff
    ty = rnd(c, 8)
    c.emu.w32(ty + 4, t)
    g = obj(c, 0x60, 'g', 0x80, {0x1e0: lambda e, a: (int((a[0] == 0x2007f9 and k < 0.4) or (a[0] == 0x2003e8 and k < 0.7)), None)},
            {0x1e0: 1})
    c.emu.w32(g + 0x54, ty)
    _render(c, {0x58: lambda e, a: ((g if k < 0.9 else 0), None)}, {0x58: 1})
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x56dc50, 'window factory 0x56dc50', 'thiscall', None, ret='eax', gen=_fact(0x561020))
S(0x4b2bd0, 'factory 0x4b2bd0', 'thiscall', None, ret='eax', gen=_fact(0x469870))
S(0x4f1c90, 'factory 0x4f1c90', 'thiscall', None, ret='eax', gen=_fact(0x469870))
S(0x5b7990, 'factory 0x5b7990', 'thiscall', None, ret='eax', gen=_fact(0x469870))
S(0x5db890, 'factory 0x5db890', 'thiscall', None, ret='eax', gen=_fact(0x469870))
S(0x444310, 'ZROOM::CopyData', 'thiscall', None, ret='eax', gen=_copy)
S(0x63ead0, 'hash table serialize 0x63ead0', 'thiscall', None, ret=None, gen=_hash)
S(0x432c50, 'remove entry 0x432c50', 'thiscall', None, ret=None, gen=_remove)
S(0x650b90, 'ZRender::RemoveCamera', 'thiscall', None, ret=None, gen=_rmcam)
S(0x648d50, 'ZArrayBlock new block 0x648d50', 'thiscall', None, ret='al', gen=_block)
S(0x45ad90, 'ZSTDOBJ subclass ctor 0x45ad90', 'thiscall', None, ret='eax', gen=_ctor)
S(0x4f9e90, 'ZScrollbar::DuplicateToResource', 'thiscall', None, ret='eax', gen=_dup)
S(0x5a4610, 'slot lookup 0x5a4610', 'thiscall', None, ret='eax', gen=_s5a)
