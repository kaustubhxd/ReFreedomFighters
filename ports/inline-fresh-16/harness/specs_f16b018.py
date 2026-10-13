"""specs_f16b018.py - fresh slice 16 batch 18 (see src/f16b018.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _57a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x562c20, 1, this=True, pop=True, ret=r.getrandbits(32))
    sbuf = rnd(c, 8)
    ok = r.choice([0, 1, 0x100, r.getrandbits(32)])
    ca = codeaddr(c)
    phook(c, seq, ca, 2, this=True, pop=True, ret=ok, act=lambda e, a: e.w32(a[1], sbuf))

    def atoi(e, _):
        e.ret(eax=r.choice([0, 1, 2, 5, 8, 9, -3 & 0xffffffff]) if False else (e.r32(e.arg32(0)) % 12) - 2 & 0xffffffff)
    c.emu.stub_import('atoi', atoi)
    db = obj(c, 0x200, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    s = sysobj(c, db=db)
    c.emu.w32(s, c.emu.r32(obj(c, 0x10, {0x5c: ca})))
    ca2 = codeaddr(c)
    phook(c, seq, ca2, 3, this=True, pop=True)
    h = obj(c, 0x200, {0x12c: ca2})
    me = obj(c, 0x200, {0xd0: stub(c, seq, 1)})
    c.emu.w32(me + 0x44, h)
    return [me, r.choice([0, 1, 2, 3, 5, 7, 8, 9, 0xffffffff, r.getrandbits(32)])]


def _43d(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x45c4f0, 2, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x45c4b0, 1, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x45c3a0, 3, this=True, pop=True, ret=r.getrandbits(32))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]


def _4f5(c):
    seq = Seq(c)
    clear_hooks(c)
    phook(c, seq, 0x4ef200, 1, this=True, pop=True)
    return [rnd(c, 0xa0), rnd(c, 0xa0)]


def _4cd(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    n = r.randrange(1, 4)
    e = rnd(c, 12)
    c.emu.w32(e + 8, r.choice([1, 1, 2, 0]))
    for k in (0, 4):
        c.emu.w32(e + k, rnd(c, 8) if r.random() < 0.6 else 0)
    p = rnd(c, 4 * n)
    c.emu.w32(p + 4 * (n - 1), e)
    cnt = [0]
    left = r.randrange(0, 5)

    def nxt(e_, a):
        rr = rnd(c, 4 * n)
        if r.random() < 0.5:
            e_.w32(rr + 4 * (n - 1), e)
        cnt[0] += 1
        e_.w32(a[0], 1 if cnt[0] <= left else 0)
        return rr
    cas = {}
    for sl, act in ((0x4c, lambda e_, a: (cnt.__setitem__(0, 0), e_.w32(a[0], 0x77)) and None), (0x5c, nxt), (0x44, None)):
        ca = codeaddr(c)
        phook(c, seq, ca, 1, this=True, pop=True, act=act)
        cas[sl] = ca
    cas[4] = stub(c, seq, 1)
    h = obj(c, 0x80, cas) if r.random() < 0.85 else 0
    me = obj(c, 0x80, {0x7c: stub(c, seq, 1)})
    c.emu.w32(me + 0x18, n)
    c.emu.w32(me + 0x1c, h)
    if not h:
        c.emu.w32(e + 8, 1)
    return [me, p]


S(0x57ae00, 'ZFFSetStartZone::OnCommand', 'thiscall', None, ret='al', gen=_57a, note='f16b018; atoi stubbed')
S(0x43dec0, 'FUN_43dec0 (construct ZGEOM, tag 0x18, vtable 0x67c3a4)', 'fastcall', None, ret='eax', gen=_43d, note='f16b018; SEH not reproduced')
S(0x4f5ac0, 'ZWinGfxHandler::CopyData', 'thiscall', None, ret=None, gen=_4f5, note='f16b018')
S(0x4cde80, 'STATICREFTAB::DelRefPtr', 'thiscall', None, ret=None, gen=_4cd, note='f16b018')
