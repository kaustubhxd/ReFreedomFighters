"""specs_f16b016.py - fresh slice 16 batch 16 (see src/f16b016.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, reporter, fval


def _504(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x14) if r.random() < 0.85 else 0)
    phook(c, seq, 0x5044c0, 0, this=True)
    c.emu.w32(0x700e70, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [rnd(c, 0x10)]


def _552(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    e = rnd(c, 8)
    phook(c, seq, 0x5003d0, 1, ret=e, this=True, pop=True)
    phook(c, seq, 0x51ad70, 2, this=True, pop=True)
    o = obj(c, 0x20, {0x1e0: stub(c, seq, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    db = obj(c, 0x60, {0x58: stub(c, seq, 1, ret=o if r.random() < 0.85 else 0)})
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, fval(c))
    s = obj(c, 0x100, {0x1c0: stub(c, seq, 2, fld=fl)})
    c.emu.w32(s + 0x9b, db)
    c.emu.w32(0x70039c, s)
    p = rnd(c, 8)
    return [p]


def _442(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x441ad0, 2, ret=r.getrandbits(32), pop=True, act=None)
    rec = c.emu.alloc(8, 4)
    phook(c, seq, 0x441ad0, 2, ret=r.getrandbits(32), pop=True,
          act=lambda e, a: (e.w32(rec, e.reg('ecx')), e.w32(rec + 4, e.reg('edx'))) and None)
    phook(c, seq, 0x45c4b0, 1, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x441b90, 3, this=True, pop=True, ret=r.getrandbits(32))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]


def _4f2(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4f2610, 0, this=True)
    phook(c, seq, 0x4ef0e0, 0, this=True)
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, fval(c))
    inp = obj(c, 0x20, {0xa8: stub(c, seq, 0, fld=fl), 0xb0: stub(c, seq, 0, ret=r.getrandbits(32))})
    db = obj(c, 0x60, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    s = obj(c, 0x100, {0xbc: stub(c, seq, 0, ret=inp)})
    c.emu.w32(s + 0x9b, db)
    c.emu.w32(0x70039c, s)
    g = obj(c, 0x50, {0x27c: stub(c, seq, 1)})
    me = obj(c, 0x80, {0x110: stub(c, seq, 2), 0x314: stub(c, seq, 1), 0x30c: stub(c, seq, 1)})
    c.emu.w32(me + 0x6f, g)
    return [me]


S(0x5045c0, 'FUN_5045c0 (new 0x69c9c0 object)', 'thiscall', None, ret='eax', gen=_504, note='f16b016; SEH not reproduced')
S(0x552400, 'CFFTools_if::DrawSpline', 'stdcall', None, ret=None, gen=_552, note='f16b016; 0x51ad70 name is a GUESS')
S(0x442240, 'FUN_442240 (construct or create, tag 0x83)', 'fastcall', None, ret='eax', gen=_442, note='f16b016; SEH not reproduced')
S(0x4f2000, 'ZWINDOWS::ClassInit', 'thiscall', None, ret=None, gen=_4f2, note='f16b016')
