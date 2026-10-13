"""specs_f16b006.py - fresh slice 16 batch 6 (see src/f16b006.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval, powstub


def _5f3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x5f3eb0, 2, this=True, pop=True)
    phook(c, seq, 0x5fe610, 2, this=True, pop=True)
    n = r.randint(0, 5)
    arr = c.emu.alloc(4 * n + 4, 4)
    for i in range(n):
        c.emu.w32(arr + 4 * i, obj(c, 0x10, {0x3c: stub(c, seq, 1)}))
    me = rnd(c, 0xa0)
    c.emu.w32(me + 0x4c, arr)
    c.emu.w32(me + 0x54, n)
    return [me, rnd(c, 0x10)]


def _640(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    reporter(c, seq)
    me = rnd(c, 0x270)
    c.emu.w8(me + 4, r.choice([0, 1, 1, 1, 0x80]))
    base = 0x30000000
    a = base + 4 * r.randint(0, 0x1fff)
    b = base + 4 * r.randint(0, 0x1fff)
    if r.random() < 0.2:
        a, b = r.getrandbits(32), r.getrandbits(32)
    c.emu.w32(me + 0x26c, a)
    c.emu.w32(me + 0x268, b)
    return [me]


def _436(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x70)
    for base, cnt, mx in ((4, 0xc, 2), (0x10, 0x1c, 3), (0x20, 0x60, 16)):
        n = r.randint(0, mx)
        for i in range(n):
            c.emu.w32(me + base + 4 * i, obj(c, 0x10, {4: stub(c, seq, 1)}))
        c.emu.w32(me + cnt, n)
    return [me]


def _4b1(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x120, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    phook(c, seq, 0x4e5e60, 0, ret=r.getrandbits(32), this=True)
    return [rnd(c, 0x60), rnd(c, 0x10)]


def _5bf(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x5bf5c0, 0, this=True)
    a = obj(c, 0x50, {0x44: stub(c, seq, 1, ret=rnd(c, 0x40) if r.random() < 0.8 else 0)})
    db = rnd(c, 0x20)
    c.emu.w32(db + 8, a)
    sysobj(c, db=db)
    return [rnd(c, 0x20)]


def _608(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x64f910, 0, this=True)
    phook(c, seq, 0x60d610, 0, this=True)
    o = obj(c, 0x20, {0x138: stub(c, seq, 2), 8: stub(c, seq, 1)})
    me = rnd(c, 0x1400)
    c.emu.w32(me + 0x1377, o)
    c.emu.w8(me + 0x13ed, r.choice([0, 1]))
    c.emu.w32(me + 0x13e7, obj(c, 0x10, {0: stub(c, seq, 1)}) if r.random() < 0.7 else 0)
    c.emu.w32(0x724ad8, obj(c, 0x10, {8: stub(c, seq, 1)}) if r.random() < 0.7 else 0)
    c.emu.w32(0x724b38, obj(c, 0x10, {8: stub(c, seq, 1)}))
    c.emu.w32(0x724a54, r.getrandbits(32))
    return [me]


def _45b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    powstub(c)
    phook(c, seq, 0x45c180, 0, this=True)
    k = r.random()
    sysobj(c, dt=r.uniform(0, 0.1) if k < 0.7 else r.choice([0.0, -0.0, 1.0, 100.0, -5.0, float('inf'), float('nan')]))
    return [rnd(c, 0x6510)]


S(0x5f3e40, 'Process_t::collectOpaqueObjectInfo', 'thiscall', None, ret=None, gen=_5f3, note='f16b006')
S(0x640240, 'ZDrawBase::ShouldFlush', 'thiscall', None, ret='al', gen=_640, note='f16b006')
S(0x436080, 'ZSysInput::InitDevices', 'thiscall', None, ret=None, gen=_436, note='f16b006')
S(0x4b1500, 'CCutSequenceProxy::LoadInit', 'thiscall', None, ret=None, gen=_4b1, note='f16b006')
S(0x5bf780, 'FUN_5bf780 (create trigger-function evaluator)', 'thiscall', None, ret='eax', gen=_5bf, note='f16b006; SEH frame not reproduced')
S(0x608e80, 'FUN_608e80 (render shutdown)', 'thiscall', None, ret=None, gen=_608, note='f16b006')
S(0x45b880, 'ZBloodSplatters::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_45b, note='f16b006; pow stubbed (same stub both sides)')
