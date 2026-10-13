"""specs_f16b022.py - fresh slice 16 batch 22 (see src/f16b022.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, fval
import struct


def _4c3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = obj(c, 0x100, {0xbc: stub(c, seq, 1), 0x3c: stub(c, seq, 1), 0x84: stub(c, seq, 1)})
    me = obj(c, 0xb0, {0x64: stub(c, seq, 1)})
    c.emu.w32(me + 0x44, h)
    for o in (0x48, 0x49, 0x78):
        c.emu.w8(me + o, r.choice([0, 1, 0x80]))
    k = r.random()
    if k < 0.2:
        c.emu.w32(me + 0x7a, fval(c))
    else:
        c.emu.w32(me + 0x7a, struct.unpack('<I', struct.pack('<f', r.uniform(-3e6, 3e6) if k < 0.3 else r.uniform(-100, 100)))[0])
    sysobj(c)
    return [me]


def _447(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x45c3a0, 3, this=True, pop=True, ret=r.getrandbits(32))
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x20) if r.random() < 0.8 else 0)
    phook(c, seq, 0x4ccbe0, 2, this=True, pop=True, ret=r.getrandbits(32))
    db = rnd(c, 0xc00)
    c.emu.w8(db + 0xbad, r.choice([0, 1, 0x80]))
    sysobj(c, db=db)
    return [rnd(c, 0x30), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _4d8(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x4cc1d0, 0, this=True, ret=lambda e: e.reg('ecx') ^ 0x5a5a5a5a)
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x20))  # a null result crashes the exe (tab 0), not generated
    tab = obj(c, 0x20, {4: stub(c, seq, 1)})
    phook(c, seq, 0x4ccbe0, 2, this=True, pop=True, ret=tab)
    found = rnd(c, 8)
    c.emu.w32(found + 4, tab)
    r2 = rnd(c, 8)
    t = obj(c, 0x100, {0x84: stub(c, seq, 1, ret=found if r.random() < 0.5 else 0), 0x88: stub(c, seq, 1, ret=r2)})
    me = rnd(c, 8)
    c.emu.w32(me + 4, t)
    cmd = obj(c, 0x20, {4: stub(c, seq, 0, ret=rnd(c, 8))})
    return [me, cmd]


def _50c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    t = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: stub(c, seq, 2, ret=t)}))
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    e = rnd(c, 8)
    x = rnd(c, 8)
    c.emu.w8(x + 4, r.choice([0, 1, 2, 0xff]))

    def get(em, a):
        return e if em.reg('ecx') == pa else x
    pa, pb = r.getrandbits(32), r.getrandbits(32)
    while pb == pa:
        pb = r.getrandbits(32)
    phook(c, seq, 0x5003d0, 1, this=True, pop=True, act=get)
    phook(c, seq, 0x5002f0, 1, this=True, pop=True)
    o = obj(c, 0x600, {0x504: stub(c, seq, 0, ret=r.getrandbits(32))}) if r.random() < 0.8 else 0
    db = obj(c, 0x80, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    me = obj(c, 0x80, {0x4c: stub(c, seq, 1, ret=o)})
    params = rnd(c, 0x10)
    c.emu.w32(params + 4, pa)
    c.emu.w32(params + 8, pb)
    return [me, params]


S(0x4c3e80, 'FUN_4c3e80 (reset timer state)', 'thiscall', None, ret=None, gen=_4c3, note='f16b022')
S(0x4474c0, 'FUN_4474c0 (ctor vtable 0x67f0c0)', 'thiscall', None, ret='eax', gen=_447, note='f16b022; SEH not reproduced')
S(0x4d8600, 'CConsoleCommandList::Add', 'thiscall', None, ret=None, gen=_4d8, note='f16b022; SEH not reproduced')
S(0x50c540, 'FUN_50c540 (script native: geom ref to param)', 'thiscall', None, ret=None, gen=_50c, note='f16b022')
