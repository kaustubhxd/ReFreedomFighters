"""specs_f16b011.py - fresh slice 16 batch 11 (see src/f16b011.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval


def _handler(c, seq, ret=0):
    h = codeaddr(c)
    phook(c, seq, h, 0, ret=ret)
    c.emu.w32(0x7003b0, h)


def _500(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    _handler(c, seq, r.getrandbits(32))
    e = rnd(c, 0x10)
    c.emu.w8(e + 4, r.choice([0, 1, 2, 0xff]))
    phook(c, seq, 0x5003d0, 1, ret=e, this=True, pop=True)
    o = obj(c, 0x20, {0x4c: stub(c, seq, 0, ret=rnd(c, 0x10))})
    fac = obj(c, 0x20, {0x18: stub(c, seq, 1, ret=o if r.random() < 0.85 else 0)})
    return [fac, r.getrandbits(32), r.getrandbits(32)]


def _494(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    s = obj(c, 0x20, {0x40: stub(c, seq, 3)})
    db = obj(c, 0x190, {0x134: stub(c, seq, 0, ret=s), 0xb0: stub(c, seq, 0, ret=r.getrandbits(32)),
                        0xa8: stub(c, seq, 0), 0xa0: stub(c, seq, 1), 0x18c: stub(c, seq, 1)})
    sysobj(c, db=db)
    return [rnd(c, 0x10)]


def _5a3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _handler(c, seq)
    phook(c, seq, 0x5a3dc0, 0, this=True)
    phook(c, seq, 0x4690b0, 2)
    return [rnd(c, 0x140), r.choice([0, 1, 4, 5, 2, 3, 7, r.getrandbits(32)])]


def _65c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    t = obj(c, 0x40, {0x30: stub(c, seq, 2, pop=False)})
    o = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=t)})
    c.emu.w32(0x700390, o)
    buf = rnd(c, 0x40)
    me = rnd(c, 0x430)
    c.emu.w32(me + 0x408, rnd(c, 0x10))
    cur = buf + 8 * r.randint(0, 6)
    c.emu.w32(me + 0x41c, cur)
    c.emu.w32(me + 0x420, cur + r.choice([0, 4, 7, 8, 9, 16]) if r.random() < 0.9 else r.getrandbits(32))
    return [me, r.getrandbits(32)]


def _61a(c):
    r = c.rng
    clear_hooks(c)
    n = r.randint(1, 12)
    for i in range(n):
        c.emu.wbytes(0x812840 + 8 * i, bytes(r.getrandbits(8) for _ in range(8)))
        c.emu.wbytes(0x812940 + 8 * i, bytes(r.getrandbits(8) for _ in range(8)))
    src = rnd(c, 0x24 * n)
    dst = rnd(c, 0x24 * n) if r.random() < 0.85 else src
    return [dst, src, n]


S(0x500880, 'VisibleEventTranslator_t::handleEventTranslation', 'stdcall', None, ret='eax', gen=_500, note='f16b011; null-handler int3 not run')
S(0x494540, 'ZEngineDataBase::ScratchedDisk', 'thiscall', None, ret=None, gen=_494, note='f16b011')
S(0x5a3e40, 'CMPGameController::~CMPGameController', 'thiscall', None, ret='eax', gen=_5a3, note='f16b011; null-handler int3 not run; SEH not reproduced')
S(0x65ca80, 'ZShadowListBuild::NewSetBegin', 'thiscall', None, ret='al', gen=_65c, note='f16b011')
S(0x61a900, 'ZRObjectInstanceStripGC::UpdateLight', 'stdcall', None, ret=None, gen=_61a, note='f16b011; MMX ported as integer code; n >= 1')
