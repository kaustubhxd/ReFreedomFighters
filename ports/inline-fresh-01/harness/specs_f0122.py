"""specs_f0122.py - fresh-01 batch 22 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _pi(c):
    parser = rnd(c, 0x250)
    enc = rnd(c, 0x50)
    c.emu.w32(enc + 0x44, c.rng.choice([1, 2]))
    mode = c.rng.random()
    c.emu.w32(parser + 0x40, 0 if mode < 0.2 else 1)
    c.emu.w32(parser + 0x50, c.rng.choice([0, 1]))
    if mode >= 0.2:
        def pih(e, r):
            e.calllog.append(('PI', e.arg32(0), e.arg32(1), e.arg32(2)))
            e.ret()
        c.emu.w32(parser + 0x40, c.emu.stub_fn('pi handler', pih))

    def nl(e, r):
        e.calllog.append(('nameLength', e.arg32(0), e.arg32(1)))
        e.ret(eax=7)

    def sk(e, r):
        e.calllog.append(('skipS', e.arg32(0), e.arg32(1)))
        e.ret(eax=(e.arg32(1) + 3) & 0xffffffff)
    c.emu.w32(enc + 0x20, c.emu.stub_fn('nameLength', nl))
    c.emu.w32(enc + 0x24, c.emu.stub_fn('skipS', sk))
    pool = parser + 0x22c
    bufs = [rnd(c, 0x40) for _ in range(2)]
    c.emu.w32(pool + 8, 0)
    c.emu.w32(pool + 0xc, 0)
    c.emu.w32(pool + 0x10, c.rng.getrandbits(32))
    plan = [(c.rng.choice([1, 1, 1, 0]), c.rng.choice([0, 0, 1]), c.rng.choice([1, 1, 0])) for _ in range(2)]
    nulls = [c.rng.random() < 0.08 for _ in range(2)]

    def app(e, r):
        k = sum(1 for x in e.calllog if x[0] == 'poolAppend')
        p = e.arg32(0)
        e.calllog.append(('poolAppend', p, e.arg32(1), e.arg32(2), e.arg32(3), e.r32(p + 0xc), e.r32(p + 0x10)))
        ok, full, _ = plan[k]
        b = bufs[k]
        e.w32(p + 0x10, 0 if nulls[k] else b)
        e.w32(p + 0xc, b + 8)
        e.w32(p + 8, b + 8 if full else b + 0x20)
        e.ret(eax=ok)

    def grow(e, r):
        k = sum(1 for x in e.calllog if x[0] == 'poolAppend') - 1
        p = e.arg32(0)
        e.calllog.append(('poolGrow', p))
        e.w32(p + 8, e.r32(p + 8) + 0x10)
        e.ret(eax=plan[k][2])
    c.emu.hook(0x620180, app)
    c.emu.hook(0x6206e0, grow)
    hk(c, 0x620cb0, 'reportDefault', 4, regs=(), pop=False)
    hk(c, 0x6200d0, 'normalizeLines', 1, regs=(), pop=False)
    hk(c, 0x6204a0, 'poolClear', 1, regs=(), pop=False)
    c.emu.w32(parser + 4, c.rng.getrandbits(32))
    st = rnd(c, 0x40)
    return [parser, enc, st, st + 0x30]


def _key(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    ids = [0x1111, 0x2222, 0x3333]
    f = c.rng.choice(ids)
    b = obj(c, 0x10, 'b', 0xc0, {0x2f0: lambda e, a: (f, None)})
    a = obj(c, 0x10, 'a', 0xc0, {0x2c4: lambda e, x: (b, None)})
    busy = c.rng.random() < 0.15
    self_ = rnd(c, 0x1d0)
    c.emu.w32(self_, c.emu.logging_vtable('koth', 0x40, {0xd8: lambda e, x: (0x400 | int(busy), None),
                                                          0x84: lambda e, x: (a, None)}, {}))
    c.emu.w32(self_ + 0x180, ids[0])
    c.emu.w32(self_ + 0x184, c.rng.getrandbits(32))
    c.emu.w8(self_ + 0x1b5, c.rng.choice([0, 1]))
    r = obj(c, 0x20, 'render', 0x40, {0x58: lambda e, x: (ids[1], None)}, {0x58: 1})
    c.emu.w32(eng + 0x9b, r)
    hk(c, 0x563d20, 'step down', 3)
    hk(c, 0x563d40, 'step up', 3)
    hk(c, 0x56d750, 'UpdateAmountButton', 0)
    hk(c, 0x56d840, 'UpdateMapButton', 0)
    hk(c, 0x562d90, 'base OnKeyPress', 1, eax=0x5a5a5a01)
    return [self_, c.rng.choice([0x102, 0x103, 0x101, 0x0d])]


def _icons(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = rnd(c, 0xae8)
    c.emu.w32(eng + 0x9b, r)
    c.emu.w32(r + 0xae4, obj(c, 0x10, 'loc', 4, {0: lambda e, a: ((a[0] ^ a[1] ^ 0x10000000), None)}, {0: 2}))
    self_ = rnd(c, 0x300)
    for k in range(5):
        rec = self_ + 0x240 + 0x24 * k
        z = 0 if c.rng.random() < 0.15 else rnd(c, 8)
        if z:
            c.emu.w32(z + 4, 0 if c.rng.random() < 0.3 else rnd(c, 8))
        c.emu.w32(rec, z)

        def s84(e, _, k=k):
            p = e.arg32(0)
            e.calllog.append(('GetPos', e.reg('ecx'), bytes(e.rbytes(p, 12)).hex()))
            e.w32(p + 4, 0x3f800000 + k)
            e.ret(argbytes=4)
        mk = 0 if c.rng.random() < 0.15 else rnd(c, 0x10)
        if mk:
            c.emu.w32(mk, c.emu.fake_vtable('marker', 0x30, {0x84: s84}))
        c.emu.w32(rec + 4, mk)
    for k in range(5):
        c.emu.w32(self_ + 0x190 + 4 * k, obj(c, 0x10, 'btn%d' % k, 0xc0, {}, {0x284: 1, 0xbc: 1, 0x260: 1}))
    c.emu.w32(self_ + 0x1fe, c.rng.choice([0, 1, 3, 5, 0xffffffff]))
    c.emu.w32(self_ + 0x94, rnd(c, 0x520))
    hk(c, 0x5b1000, 'LevelCompleted', 1, eax=lambda e: 0x700 | (e.arg32(0) & 1))

    def icon(e, _):
        p = e.arg32(1)
        e.calllog.append(('SetupIcon', e.reg('ecx'), e.arg32(0), bytes(e.rbytes(p, 12)).hex(), e.arg32(2) & 0xff,
                          e.arg32(3), e.arg32(4)))
        e.ret(argbytes=20)
    c.emu.hook(0x574af0, icon)
    return [self_]


S(0x620d50, 'expat reportProcessingInstruction', 'cdecl', None, ret='eax', gen=_pi)
S(0x56cfd0, 'CMultiplayerKOTH::OnKeyPress', 'thiscall', None, ret='al', gen=_key)
S(0x575bd0, 'ZZoneMap::SetupIcons', 'thiscall', None, ret=None, gen=_icons)
