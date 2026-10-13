"""specs_f16b020.py - fresh slice 16 batch 20 (see src/f16b020.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, fval


def _497(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    crt(c)
    na, nb = r.randrange(0, 6), r.randrange(0, 6)
    h = rnd(c, 0x30 + 4 + 12 * na + 4 + 8 * nb)
    a = 0x30 if r.random() < 0.8 else 0
    b = (0x30 + 4 + 12 * na) if r.random() < 0.8 else 0
    c.emu.w32(h + 0x20, a)
    c.emu.w32(h + 0x24, b)
    c.emu.w32(h + 0x30, na)
    c.emu.w32(h + 0x30 + 4 + 12 * na, nb)
    phook(c, seq, 0x41e290, 1, ret=lambda e: rnd(c, 0x50))
    return [rnd(c, 0x50), h]


def _5b9(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    db = obj(c, 0x200, {0x114: stub(c, seq, 4, retfn=[(3, 0x13, r.getrandbits(32))], ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [rnd(c, 0x70)]


def _490(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    tag = r.getrandbits(32)
    rec = c.emu.alloc(4, 4)
    phook(c, seq, 0x48c4b0, 2, this=True, pop=True, act=lambda e, a: e.w32(a[0], tag))
    phook(c, seq, 0x4cc1d0, 0, this=True, ret=lambda e: e.r32(e.reg('ecx')) ^ 0x5a5a5a5a)
    phook(c, seq, 0x4cbec0, 0, this=True, act=lambda e, a: e.w32(rec, e.r32(e.reg('ecx'))))
    o = obj(c, 0x80, {0x60: stub(c, seq, 5, ret=r.getrandbits(32))})
    c.emu.w32(0x700394, o)
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, fval(c))
    me = obj(c, 0x100, {0x90: stub(c, seq, 3, fld=fl)})
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _49b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4e6b30, 0, this=True)
    left = r.randrange(0, 5)
    cnt = [0]

    def nxt(e, a):
        cnt[0] += 1
        e.w32(a[0], 1 if cnt[0] <= left else 0)
        return r.getrandbits(32)
    ca4, ca5 = codeaddr(c), codeaddr(c)
    phook(c, seq, ca4, 1, this=True, pop=True, act=lambda e, a: e.w32(a[0], 0x77) and None)
    phook(c, seq, ca5, 1, this=True, pop=True, act=nxt)
    lst = obj(c, 0x80, {0x4c: ca4, 0x5c: ca5}) if r.random() < 0.9 else 0

    def get(e, a):
        if r.random() < 0.3:
            return 0
        o = rnd(c, 0x10)
        e.w32(o + 8, rnd(c, 0x70))
        return o
    ca = codeaddr(c)
    phook(c, seq, ca, 1, this=True, pop=True, act=get)
    db = obj(c, 0x80, {0x58: ca})
    sysobj(c, db=db)
    return [rnd(c, 0x40), lst]


S(0x497880, 'ZGeomBuffer::InitResourceGeoms', 'thiscall', None, ret=None, gen=_497, note='f16b020; memcpy stubbed')
S(0x5b9380, 'CFriendlyControl::CFriendlyControl', 'thiscall', None, ret='eax', gen=_5b9, note='f16b020; SEH not reproduced')
S(0x490940, 'ZEngineDataBase::GetPrimsData', 'thiscall', None, ret=None, gen=_490, note='f16b020; SEH and cookie not reproduced')
S(0x49b5c0, 'FUN_49b5c0 (ctor, vtable 0x68ed14)', 'thiscall', None, ret='eax', gen=_49b, note='f16b020; SEH not reproduced')
