"""specs_f0113.py - fresh-01 batch 13 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _engine(c, n=0x1b00):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
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


def _load(c):
    def mk(name):
        def s(e, r):
            p = e.arg32(0)
            stk = p >= e.reg('esp') - 0x1000 and p < e.reg('esp') + 0x1000
            e.calllog.append((name, e.reg('ecx'), 'stack' if stk else p))
            e.w32(p, (len(e.calllog) * 0x1111 + 0x51000000) & 0xffffffff)   # write through the pointer (unaligned +0x79 too)
            e.ret(argbytes=4)
        return s
    ld = rnd(c, 0x10)
    c.emu.w32(ld, c.emu.fake_vtable('load', 0x20, {0x48: mk('i'), 0x50: mk('f'), 0x68: mk('b')}))
    return [rnd(c, 0x90), ld]


def _native(c):
    eng = _engine(c)
    arr4, arr8 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    e0, e1, e8 = rnd(c, 8), rnd(c, 8), rnd(c, 8)
    c.emu.w8(e0 + 4, c.rng.choice([0, 1, 0, 1, 2, 0xff]))
    c.emu.w32(e1, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))

    def el(e):
        if e.reg('ecx') == arr8:
            return e8
        return e0 if e.arg32(0) == 0 else e1
    hk(c, 0x5003d0, 'elem', 1, eax=el)
    hk(c, 0x5002f0, 'set', 1, eax=0x2f0)
    hk(c, 0x5979c0, 'count5', 0, eax=lambda e: (e.reg('ecx') * 7) & 0xffff)
    k = c.rng.random()
    o = 0
    if k > 0.15:
        o = rnd(c, 0x860)
        if k < 0.3:
            c.emu.w32(o + 0x852, 0)
    r = obj(c, 0x20, 'render', 0x40, {0x58: lambda e, a: (o, None)}, {0x58: 1})
    c.emu.w32(eng + 0x9b, r)
    _logmgr(c, 3)
    _handler(c)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, arr4)
    c.emu.w32(p + 8, arr8)
    if o and c.emu.r32(o + 0x852):
        c.emu.w32(o + 0x852, rnd(c, 0x1fb4))
    return [rnd(c, 0x10), p]


def _geomenter(c):
    eng = _engine(c, 0x40)
    self_ = rnd(c, 0x300)
    ent = rnd(c, 0x40)
    ent2 = rnd(c, 0x40)
    c.emu.w16(ent + 6, c.rng.choice([0xffff, c.rng.randint(0, 0x20)]))
    g = rnd(c, 0x40)
    c.emu.w32(g + 0x3c, c.rng.choice([0, 0x40000000, 0x40000, c.rng.getrandbits(32) & ~0x40040000, c.rng.getrandbits(32)]))
    c.emu.w32(ent + 0x38, g)
    c.emu.w32(ent2 + 0x38, g)
    swap = c.rng.random() < 0.3

    def mk(name, sw):
        def s(e, r):
            p = e.arg32(0)
            e.calllog.append((name, e.reg('ecx'), e.r32(p)))
            if sw:
                e.w32(p, ent2)
            e.ret(argbytes=4)
        return s
    for off, nm in ((0x1f0, 'all'), (0x1b4, 'moving'), (0x1dc, 'bit1'), (0x1c8, 'b3f')):
        c.emu.w32(self_ + off, c.emu.fake_vtable(nm, 0x10, {8: mk(nm, swap and off == 0x1f0)}))
    mv = 0x300 | c.rng.choice([0, 1])
    hk(c, 0x4db9e0, 'IsMoving', 0, eax=mv)
    return [self_, ent]


def _texanim(c):
    eng = _engine(c)
    prim = rnd(c, 0x70)
    c.emu.w16(prim + 2, c.rng.choice([0, 0, 0, 1]))
    texs = {}
    ids = [c.rng.getrandbits(16), c.rng.getrandbits(32), c.rng.getrandbits(32)]
    c.emu.w16(prim + 4, ids[0])
    c.emu.w32(prim + 0x60, ids[1])
    c.emu.w32(prim + 0x68, ids[2])
    for i in ids:
        k = c.rng.random()
        if k < 0.2:
            texs[i] = 0
            continue
        t = rnd(c, 0x40)
        if k < 0.35:
            c.emu.w32(t + 0x3c, 0)
        else:
            d = rnd(c, 4)
            c.emu.w32(d, c.rng.choice([0, 1, 5, 0x80000000, c.rng.getrandbits(32)]))
            c.emu.w32(t + 0x3c, d)
        texs[i] = t

    def look(e, a):
        return (texs.get(a[0], 0), None)
    mgr = obj(c, 0x10, 'texmgr', 0x10, {4: look}, {4: 2})
    h = rnd(c, 0x20)
    c.emu.w32(h + 0x14, mgr)
    c.emu.w32(eng + 0x1aa3, h)
    self_ = obj(c, 0x10, 'prims', 0x10, {0xc: lambda e, a: (prim, None)}, {0xc: 1})
    return [self_, c.rng.getrandbits(32), rnd(c, 4)]


S(0x4bc090, 'ZSoundRandomVolume::Load', 'thiscall', None, ret='al', gen=_load)
S(0x555290, 'script native 0x555290', 'thiscall', None, ret=None, gen=_native)
S(0x63e850, 'ZDrawBase::GeomEnter', 'thiscall', None, ret=None, gen=_geomenter)
S(0x657490, 'ZPrimControlGC::GetPrimTextureAnimData', 'thiscall', None, ret='al', gen=_texanim)
