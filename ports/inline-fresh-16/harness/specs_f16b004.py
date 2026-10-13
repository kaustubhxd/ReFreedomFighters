"""specs_f16b004.py - fresh slice 16 batch 4 (see src/f16b004.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval


def _4f1(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x45fd20, 1, this=True, pop=True)
    g = rnd(c, 0x40)
    v = rnd(c, 0x10)
    for i in range(3):
        b = fval(c)
        c.emu.w32(g + 0x24 + 4 * i, b)
        c.emu.w32(v + 4 * i, b if r.random() < 0.7 else fval(c))
    me = rnd(c, 0xa0)
    c.emu.w32(me + 8, g)
    return [me, v]


def _63a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x63b3c0, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)
    phook(c, seq, 0x63b110, 0, ret=r.getrandbits(32), this=True)
    n = r.randint(0, 5)
    es = [rnd(c, 0x10) for _ in range(n)]
    for i, e in enumerate(es):
        c.emu.w16(e + 2, 0xffff if r.random() < 0.7 else r.getrandbits(16))
        if i + 1 < n:
            c.emu.w32(e + 8, es[i + 1])
        else:
            c.emu.w32(e + 8, r.choice([es[0], 0, es[0]]) if n else 0)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, es[0] if n else 0)
    return [me]


def _637(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    me = obj(c, 0x40, {0x74: stub(c, seq, 1), 0x78: stub(c, seq, 1), 0x5c: stub(c, seq, 1)})
    def dim():
        return r.choice([0, 1, 2, 3, 256, 1 << r.randint(0, 31), r.getrandbits(32), r.randint(0, 5000)])
    return [me, dim(), dim(), r.choice([0, 1, 0x100, r.getrandbits(32)])]


def _54f(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    co = obj(c, 0x40, {0x10: stub(c, seq, 7, ret=r.choice([0, 1, 0x80000000, 0x8007000e, r.getrandbits(32)]))})
    me = rnd(c, 0x90)
    c.emu.w32(me + 4, co if r.random() < 0.85 else 0)
    return [me]


def _5f3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    n = r.randint(0, 40)
    s = c.emu.alloc(n + 1, 1)
    c.emu.wbytes(s, bytes(r.randint(1, 255) for _ in range(n)) + b'\0')
    buf = rnd(c, 64)
    me = rnd(c, 0x10)
    c.emu.w32(me + 8, buf + r.randint(0, 8))
    c.emu.w32(me + 0xc, buf + r.randint(0, 64))
    return [me, s]


def _566(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x562440, 0, this=True)
    s = obj(c, 0x80, {0x60: stub(c, seq, 3)})
    db = obj(c, 0x140, {0x138: stub(c, seq, 0, ret=s), 0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, obj(c, 0x20, {0xbc: stub(c, seq, 1)}))
    return [me]


def _63b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    phook(c, seq, 0x63b510, 1, ret=r.choice([0xffffffff, r.getrandbits(32), r.randint(0, 0x1000)]), this=True, pop=True)
    return [rnd(c, 0x70), r.choice([r.randint(0, 0x100), r.getrandbits(32)])]


S(0x4f1240, 'ZWINOBJ::SetPos', 'thiscall', None, ret=None, gen=_4f1, note='f16b004; ZGEOM::SetPos hooked')
S(0x63ae80, 'ZDrawArray<ZPrimDrawEntry>::Add', 'thiscall', None, ret='eax', gen=_63a, note='f16b004; grow and take hooked')
S(0x637dc0, 'FUN_637dc0 (size + mip count)', 'thiscall', None, ret=None, gen=_637, note='f16b004')
S(0x54f200, 'FUN_54f200 (COM create + error report)', 'thiscall', None, ret=None, gen=_54f, note='f16b004')
S(0x5f31c0, 'SerialInfo_t::savecharptr', 'thiscall', None, ret=None, gen=_5f3, note='f16b004; null-handler int3 not run')
S(0x5667c0, 'CBriefing::Init', 'thiscall', None, ret=None, gen=_566, note='f16b004')
S(0x63b600, 'ZDrawBase::Alloc', 'thiscall', None, ret='eax', gen=_63b, note='f16b004')
