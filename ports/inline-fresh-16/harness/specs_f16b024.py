"""specs_f16b024.py - fresh slice 16 batch 24 (see src/f16b024.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, reporter


def _4d1(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    phook(c, seq, 0x4d1cf0, 1, this=True, pop=True, ret=r.getrandbits(32) if r.random() < 0.8 else 0)
    phook(c, seq, 0x634273, 2)
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x20) if r.random() < 0.85 else 0)
    phook(c, seq, 0x4d14a0, 4, this=True, pop=True)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x14, r.choice([0, r.getrandbits(32)]))
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _geomflags(c, n):
    r = c.rng
    if r.random() < 0.12:
        c.emu.w32(n + 0x54, 0)
        return
    k = rnd(c, 0x40)
    c.emu.w32(k + 0x23, r.getrandbits(32) | (0x100000 if r.random() < 0.85 else 0))
    seq = Seq(c)
    ch = obj(c, 0x400, {0x1e0: stub(c, seq, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)])),
                        0x310: stub(c, seq, 0, ret=r.choice([0, 5, 10, 25, 49, 50, 51, 0xffffffff, r.getrandbits(32)])),
                        0x2dc: stub(c, seq, 0)})
    c.emu.w32(ch + 0xc, k)
    c.emu.w32(n + 0x54, ch)


def _577(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x562440, 0, this=True)
    phook(c, seq, 0x563510, 1, this=True, pop=True)
    sbuf = rnd(c, 8)
    ca = codeaddr(c)
    phook(c, seq, ca, 2, this=True, pop=True, ret=r.choice([0, 1, 0x100]), act=lambda e, a: e.w32(a[1], sbuf))

    def atoi(e, _):
        e.ret(eax=(e.r32(e.arg32(0)) % 9) - 2 & 0xffffffff)
    c.emu.stub_import('atoi', atoi)
    s = sysobj(c)
    c.emu.w32(s, c.emu.r32(obj(c, 0x10, {0x5c: ca})))
    g = rnd(c, 0x60)
    nxt = 0
    for _ in range(r.randrange(0, 6)):
        n = rnd(c, 0x70)
        _geomflags(c, n)
        c.emu.w32(n + 0x60, nxt)
        nxt = n
    c.emu.w32(g + 0x50, nxt)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, obj(c, 0x100, {0xbc: stub(c, seq, 1)}))
    c.emu.w32(me + 0x54, obj(c, 0x300, {0x25c: stub(c, seq, 2, ret=g)}))
    return [me]


def _492(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x41e290, 1, ret=lambda e: rnd(c, 0x10))
    pen = obj(c, 0x80, {0x48: stub(c, seq, 1, ret=r.getrandbits(32))})
    c.emu.w32(0x70038c, pen)
    lst = rnd(c, 0x20)
    c.emu.w32(lst + 0x1c, obj(c, 0x20, {8: stub(c, seq, 2), 0xc: stub(c, seq, 2)}))
    sysobj(c, extra={0x1aa3: lst})
    me = obj(c, 0xc00, {0x200: stub(c, seq, 0, ret=r.choice([0xffffffff, 0, 4, 0x20])),
                        0x208: stub(c, seq, 0, ret=r.choice([0xffffffff, 0, 4, 0x20])),
                        0x204: stub(c, seq, 2), 0x20c: stub(c, seq, 2)})
    return [me]


S(0x4d1e40, 'FUN_4d1e40 (replace entry)', 'thiscall', None, ret=None, gen=_4d1, note='f16b024; SEH not reproduced')
S(0x577480, 'ZCutSequenceMenu::Init', 'thiscall', None, ret=None, gen=_577, note='f16b024; atoi stubbed')
S(0x4929c0, 'FUN_4929c0 (dump two buffers)', 'thiscall', None, ret=None, gen=_492, note='f16b024')
