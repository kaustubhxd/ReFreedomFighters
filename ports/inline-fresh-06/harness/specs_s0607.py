"""specs_s0607.py - fresh-06 batch 7 (docs/20-fresh-06.md)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _gfac(ctor):
    def g(c):
        hk(c, 0x45c4f0, 2, pop=0, ret=c.rng.choice([0, rnd(c, 0x10)]))
        hk(c, 0x45c4b0, 1, pop=0, ret=c.rng.choice([0, rnd(c, 0x10)]))
        hk(c, ctor, 3, ecx=True, ret=c.rng.getrandbits(32))
        return [rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10), c.rng.choice([0, rnd(c, 0x10)])]
    return g


def _detach(c):
    hk(c, 0x4db9a0, 1, ecx=True, ret=c.rng.choice([0, 1, 0x100]))
    hk(c, 0x4da720, 1, ecx=True)
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
    this = obj(c, 0x40, vt(c, 'tg', {0x2f4: (1, 0)}))
    c.emu.w32(this + 8, c.rng.choice([g, rnd(c, 0x10)]))
    return [this, g]


def _trees(c):
    s = bytes(c.rng.getrandbits(8) for _ in range(8))
    hk(c, 0x48c4b0, 2, ecx=True, fn=lambda e, a, s=s: e.wbytes(a[0], s))
    hk(c, 0x4cc1d0, 0, ecx=True, ret=rnd(c, 0x10))
    hk(c, 0x4cbec0, 0, ecx=True)
    c.emu.w32(0x700394, obj(c, 0x10, vt(c, 'fs', {0x60: (5, c.rng.getrandbits(32))})))
    return [rnd(c, 0x20), rnd(c, 0x20), c.rng.getrandbits(32)]


def _token(c):
    def assign(e, a):
        e.w32(e.reg('ecx') + 4, e.r32(e.reg('ecx')))

    def reserve(e, a):
        s = e.reg('ecx')
        b, en = e.r32(s), e.r32(s + 4)
        nb = e.alloc(a[0] + 8, 4)
        e.wbytes(nb, e.rbytes(b, en - b))
        e.w32(s, nb)
        e.w32(s + 4, nb + (en - b))
        e.w32(s + 8, nb + a[0])
    hk(c, 0x5f2d60, 2, ecx=True, fn=assign)
    hk(c, 0x431270, 1, ecx=True, fn=reserve)
    cap = c.rng.choice([1, 2, 4, 16])
    buf = rnd(c, cap + 4)
    s = rnd(c, 12)
    c.emu.w32(s, buf)
    c.emu.w32(s + 4, buf)
    c.emu.w32(s + 8, buf + cap)
    n = c.rng.randrange(0, 24)
    txt = bytes(c.rng.choice(b'abcXYZ09_ \t\r\n$') for _ in range(n))
    t = c.emu.alloc(n + 4, 4)
    c.emu.wbytes(t, txt)
    pp = rnd(c, 4)
    c.emu.w32(pp, t)
    return [rnd(c, 0x10), s, pp, t + n]


def _savedel(c):
    ids = rv(c, c.rng.randrange(0, 4))
    st = [0]

    def nxt(e, a):
        i = st[0]
        st[0] += 1
        e.w32(a[0], 1 if i < len(ids) else 0)
        return ids[i] if i < len(ids) else c.rng.getrandbits(1)

    def begin(e, a):
        e.w32(a[0], 0x77)

    def wr(e, a):
        e.calllog.append(('wr', e.rbytes(a[0], 4).hex()))
    lst = c.rng.choice([0, obj(c, 0x10, vt(c, 'l', {0x4c: (1, begin), 0x5c: (1, nxt)}))])
    rm = rnd(c, 0x20)
    c.emu.w32(rm + 0xc, lst)
    eng(c, {0x9b: rm})
    sg = obj(c, 0x10, vt(c, 'sg', {8: (1, 0), 0x10: (2, wr)}))
    return [rnd(c, 0x10), sg]


def _ctor(c):
    hk(c, 0x659330, 2, ecx=True)
    b = rnd(c, 0x20)
    x = rnd(c, 0x10)
    c.emu.w32(x + 8, rnd(c, 0x20))
    c.emu.w32(b + 0x10, x)
    y = rnd(c, 0x40)
    c.emu.w32(y + 0x38, rnd(c, 0x40))
    c.emu.w32(b + 0xc, y)
    return [rnd(c, 0x20), c.rng.getrandbits(32), b, rnd(c, 0xb9b0)]


for a, k in ((0x44b8e0, 0x44b310), (0x4454e0, 0x4451d0), (0x455660, 0x455330), (0x45b6a0, 0x45b240), (0x45b7e0, 0x45b3a0)):
    S(a, 'geom factory ctor 0x%x (GUESS) fastcall' % k, 'fastcall', None, ret='eax', gen=_gfac(k))
S(0x442e20, 'ZTreeGroup::DetachDynamicGeoms thiscall', 'thiscall', None, gen=_detach)
S(0x4912a0, 'ZEngineDataBase::GetTreesData thiscall', 'thiscall', None, gen=_trees, stack_arg_bytes=8)
S(0x42f6e0, 'ZSysInterface::ReadNormalToken thiscall', 'thiscall', None, gen=_token)
S(0x498e60, 'ZGeomBuffer::SaveDeletedEvents thiscall', 'thiscall', None, gen=_savedel)
S(0x616620, 'ctor vtables 0x6bdc58/0x6bdc8c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor)
