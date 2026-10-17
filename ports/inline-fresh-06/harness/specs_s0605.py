"""specs_s0605.py - fresh-06 batch 5 (docs/20-fresh-06.md)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _dtor_del(c):
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    this = rnd(c, 0x100)
    c.emu.w32(this + 0x48, c.rng.choice([0, obj(c, 0x10, vt(c, 'o', {0: (1, 0)}))]))
    return [this]


def _dtor_free(c):
    hk(c, 0x634273, 2, pop=0)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x34: (1, 0)}))})
    return [rnd(c, 0x100)]


def _waves(c):
    hk(c, 0x634273, 2, pop=0)
    items = [rnd(c, 0x30) for _ in range(c.rng.randrange(0, 4))] + [0]
    this = rnd(c, 0x80)
    c.emu.w32(this + 0x70, c.rng.choice([0, 1]))
    c.emu.w32(this + 0x48, c.rng.choice([0, obj(c, 0x10, vt(c, 'l', {0x4c: (1, 0), 0x64: (1, seq(items)), 0: (1, 0)}))]))
    return [this]


def _fac(c):
    al = obj(c, 0x10, vt(c, 'al', {0x44: (1, c.rng.choice([0, rnd(c, 0x60)]))}))
    rm = rnd(c, 0x20)
    c.emu.w32(rm + 8, al)
    eng(c, {0x9b: rm})
    hk(c, 0x469870, 0, ecx=True)
    return [c.rng.getrandbits(32)]


def _listclear(c):
    hk(c, 0x634273, 2, pop=0)
    this = rnd(c, 0x60)
    nodes = [rnd(c, 0x18) for _ in range(c.rng.randrange(0, 5))]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 8, nodes[i - 1] if i else 0)
        c.emu.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) else 0)
        c.emu.w32(n + 0x10, this)
    c.emu.w32(this + 0x48, nodes[0] if nodes else 0)
    c.emu.w32(this + 0x4c, nodes[-1] if nodes else 0)
    c.emu.w32(this + 0x50, c.rng.choice(nodes + [0, c.rng.getrandbits(32)]))
    return [this]


def _pool(c):
    n = c.rng.choice([1, 2, 3, 5])
    b = c.rng.choice([0, rnd(c, 0x10 + n * 0x8c + 4)])
    this = obj(c, 0x20, vt(c, 's', {0x30: (0, b), 0x28: (0, n)}))
    h = c.rng.choice([0, 0, rnd(c, 0x20)])
    if h:
        t = c.rng.choice([h, rnd(c, 0x20)])
        c.emu.w32(h + 0xc, t)
    c.emu.w32(this + 8, h)
    return [this]


def _morton(c):
    def sz():
        return c.rng.choice([0, 1, 2, 3, 4, 7, 8, 9, 64, 100, 1000, 0x80000000, 0xffffffff, c.rng.getrandbits(32)])
    return [rnd(c, 0x40), sz(), sz(), sz()]


def _arena(c):
    base = c.emu.alloc(0xa000 + 0x100, 4)
    this = rnd(c, 0x1c00)
    c.emu.w32(this + 0x1b55, c.rng.choice([base, base, base, 0]))
    hk(c, 0x4ce1c0, 2, ecx=True, ret=c.rng.getrandbits(32))
    handler(c, ret=0)
    off = c.rng.choice([0, 0x10, 0x9ff0, 0x9ffe, 0xa000, 0x500])
    q = base + off
    sz = c.rng.choice([2, 4, 0x10, 0x20])
    c.emu.w32(q, sz)
    c.emu.wbytes(q + sz - 1, bytes([c.rng.choice([0x5a, 0x5a, 0x5b])]))
    return [this, q + 2]


def _demo(c):
    def o(name, slots):
        return obj(c, 0x10, vt(c, name, slots))
    cc = o('c', {0x31c: (2, 0)})
    b = o('b', {0x2dc: (0, 0), 0x28: (0, 0)})
    a = o('a', {0x25c: (2, seq([b, cc]))})
    root = o('root', {0x25c: (2, a)})
    m = rnd(c, 0x1100)
    c.emu.w32(m + 0x1044, c.rng.choice([3, 3, 2, 0x103]))
    this = rnd(c, 0x100)
    c.emu.w32(this + 0x94, m)
    c.emu.w32(this + 0x54, root)
    return [this]


def _camsave(c):
    sg = obj(c, 0x10, vt(c, 'sg', {0x3c: (1, 0), 0x60: (1, 0), 0x4c: (1, 0)}))
    nodes = [rnd(c, 0x18) for _ in range(c.rng.randrange(0, 5))]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) else 0)
    this = rnd(c, 0x60)
    c.emu.w32(this + 0x48, nodes[0] if nodes else 0)
    c.emu.w32(this + 0x50, c.rng.choice(nodes + [0]))
    return [this, sg]


def _popscene(c):
    hk(c, 0x5fd170, 0, ecx=True)
    rm = obj(c, 0xc00, vt(c, 'rm', {0x114: (4, c.rng.getrandbits(32))}))
    c.emu.wbytes(rm + 0xbc4, bytes([c.rng.choice([0, 0, 1])]))
    eng(c, {0x9b: rm})
    s = rnd(c, 0xb0)
    c.emu.w32(s + 0x9c, c.rng.choice([1, 1, 2, 0]))
    for off in (0xa0, 0xa4):
        c.emu.w32(s + off, c.rng.choice([0, obj(c, 0x20, vt(c, 'x%x' % off, {0x18: (0, 0)}))]))
    this = rnd(c, 0x20)
    c.emu.w32(this + 0xc, s)
    return [this]


def _ctor(c):
    hk(c, 0x469870, 0, ecx=True)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x114: (4, c.rng.getrandbits(32))}))})
    return [rnd(c, 0x60)]


def _rel3(c):
    this = rnd(c, 0x80)

    def o():
        return obj(c, 0x10, vt(c, 'e%d' % c.rng.getrandbits(4), {8: (0, 0), 0: (1, 0)}))
    for base, cnt_off, mx in ((4, 0xc, 2), (0x10, 0x1c, 3), (0x20, 0x60, 16)):
        n = c.rng.randrange(0, mx + 1)
        for i in range(n):
            c.emu.w32(this + base + 4 * i, o())
        c.emu.w32(this + cnt_off, n)
    return [this]


S(0x5dc060, 'dtor vtables 0x6b6ab8/0x686874 (GUESS) thiscall', 'thiscall', None, gen=_dtor_del)
S(0x4b9160, 'dtor vtables 0x692a30/0x686874 (GUESS) thiscall', 'thiscall', None, gen=_dtor_free)
S(0x4baf60, 'CWaves::End thiscall', 'thiscall', None, gen=_waves)
S(0x4cabe0, 'factory vtable 0x695020 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fac)
S(0x5d5120, 'factory vtable 0x6ab31c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fac)
S(0x4fc460, 'clear owned linked list (GUESS) thiscall', 'thiscall', None, gen=_listclear)
S(0x613ba0, 'pool alloc block 0x8c entries (GUESS) thiscall', 'thiscall', None, ret='al', gen=_pool)
S(0x638ea0, 'Morton bit masks (GUESS) thiscall', 'thiscall', None, gen=_morton)
S(0x42cc60, 'arena free (map: ZSysInterfaceGC::IsControllerConnected) thiscall', 'thiscall', None, ret='eax', gen=_arena)
S(0x57bee0, 'ZFFDemoMenu::Init2 thiscall', 'thiscall', None, gen=_demo)
S(0x4fd9a0, 'ZSortCameraList::Save(ZSaveGame*) thiscall', 'thiscall', None, ret='al', gen=_camsave)
S(0x5f2720, 'ZScriptDll::PopScene thiscall', 'thiscall', None, gen=_popscene)
S(0x5c37e0, 'ctor vtable 0x6b3de4 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor)
S(0x436260, 'release three object arrays (GUESS) thiscall', 'thiscall', None, gen=_rel3)
