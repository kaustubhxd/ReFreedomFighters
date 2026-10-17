"""specs_f0112.py - fresh-01 batch 12 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _engine(c, n=0x200):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _render(c, impl=None, argw=None):
    eng = _engine(c, 0x1b00)
    r = obj(c, 0x20, 'render', 0x60, impl or {}, argw or {})
    c.emu.w32(eng + 0x9b, r)
    return eng


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


def _dtor(c):
    _render(c, {}, {0x34: 1})
    hk(c, 0x4690b0, 'sized delete', 2, regs=(), pop=False)
    _handler(c)
    return [rnd(c, 0x60), c.rng.choice([0, 1, 4, 5, c.rng.getrandbits(32)])]


def _addchild(c):
    o = rnd(c, 0x80)
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0x77, obj(c, 0x10, 'tab', 4, {}, {4: 1}))
    else:
        c.emu.w32(o + 0x77, 0)
    tab = obj(c, 0x10, 'newtab', 4, {}, {4: 1})
    p = 0 if c.rng.random() < 0.1 else rnd(c, 0x20)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x4ccbe0, 'REFTAB', 2, eax=tab)
    hk(c, 0x442050, 'AddStatic', 1)
    hk(c, 0x441e40, 'AddDynamic', 1)
    a, b = c.rng.random() < 0.5, c.rng.random() < 0.5
    ch = obj(c, 0x20, 'child', 0xd0, {0x308: lambda e, x: (0x300 | int(a), None), 0x30c: lambda e, x: (0x300 | int(b), None)})
    if p == 0:
        c.emu.w32(o + 0x77, tab)   # a failed new leaves a null table the exe then calls through: keep the table set
    return [o, ch]


def _stats(c):
    o = rnd(c, 0x240)
    c.emu.w8(o + 0x1a3, c.rng.choice([0, 0, 0, 1]))
    n = c.rng.randint(0, 5)
    c.emu.w32(o + 0x22c, n)
    for i in range(n):
        c.emu.w32(o + 0x1cc + 4 * i, obj(c, 0x10, 'txt%d' % i, 0xb0, {}, {0x284: 1, 0xbc: 1}))

    def s70(e, r):
        e.calllog.append(('SetPos', e.reg('ecx'), e.rbytes(e.arg32(0), 12).hex()))
        e.ret(argbytes=4)
    vt = c.emu.fake_vtable('item', 0x20, {0x70: s70})
    for k in range(2):
        it = rnd(c, 0x10)
        c.emu.w32(it, vt)
        c.emu.w32(o + 0x1c0 + 4 * k, it)
    return [o]


def _native(c):
    eng = _engine(c, 0x1b00)
    k = c.rng.random()
    els = {}

    def el(e):
        a = e.reg('ecx')
        if a not in els:
            b = rnd(c, 8)
            els[a] = b
        return els[a]
    # elements are created up front so the heap layout does not depend on call order
    arr4, arr8 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    e4, e8 = rnd(c, 8), rnd(c, 8)
    c.emu.w8(e8 + 4, c.rng.choice([0, 1, 2, 0xff]))
    hk(c, 0x5003d0, 'elem', 1, eax=lambda e: e4 if e.reg('ecx') == arr4 else e8)
    hk(c, 0x506040, 'handle', 0, eax=lambda e: e.reg('ecx') ^ 0x600)
    hk(c, 0x5002f0, 'set', 1, eax=0x2f0)
    c.emu.w32(eng + 0x1a9f, obj(c, 0x20, 'sys', 0x20, {0x6c: lambda e, a: (a[0] + 7, None)}, {0x6c: 1}) if k < 0.7 else 0)
    _logmgr(c, 3)
    _handler(c)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, arr4)
    c.emu.w32(p + 8, arr8)
    return [rnd(c, 0x10), p]


def _helper(c):
    hk(c, 0x43de40, 'ZSTDOBJ ctor', 3)
    hk(c, 0x4dc630, 'SetControl', 2)
    return [rnd(c, 0x50), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _fact(c):
    eng = _render(c, {0x58: lambda e, a: (a[0] ^ 0x5858, None)}, {0x58: 1})
    p = 0 if c.rng.random() < 0.2 else rnd(c, 0x30)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x51a960, 'base ctor', 2)
    hk(c, 0x51b530, 'class setup', 0)
    c.emu.w32(0x701800, c.rng.choice([0, 1]))
    idv = c.rng.getrandbits(32)

    def s40(e, r):
        e.calllog.append(('GetId', e.reg('ecx')))
        e.w32(e.arg32(0), idv)
        e.ret(argbytes=4)
    src = rnd(c, 0x10)
    c.emu.w32(src, c.emu.fake_vtable('src', 0x20, {0x40: s40}))
    a = rnd(c, 0x20)
    c.emu.w32(a + 0x15, src)
    return [a, c.rng.getrandbits(32)]


S(0x57f1d0, 'window scalar deleting destructor 0x57f1d0', 'thiscall', None, ret='eax', gen=_dtor)
S(0x441d90, 'ZTreeGroup::AddChildTreeGroup', 'thiscall', None, ret=None, gen=_addchild)
S(0x570310, 'CSewerMenu::ClearStats', 'thiscall', None, ret=None, gen=_stats)
S(0x511090, 'script native 0x511090', 'thiscall', None, ret=None, gen=_native)
S(0x43e190, 'ZHELPER::ZHELPER', 'thiscall', None, ret='eax', gen=_helper)
S(0x51b6d0, 'factory 0x51b6d0', 'fastcall', None, ret='eax', gen=_fact)
