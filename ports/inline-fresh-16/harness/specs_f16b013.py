"""specs_f16b013.py - fresh slice 16 batch 13 (see src/f16b013.cpp). The MYSTR callees are hooked: the constructors write a
tag into the local, c_str reads it back, the destructor records it, so the same local is shown to flow through every call."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _491(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    tag = r.getrandbits(32)
    rec = c.emu.alloc(4, 4)
    phook(c, seq, 0x48c4b0, 2, this=True, pop=True, act=lambda e, a: e.w32(a[0], tag))
    phook(c, seq, 0x4cc1d0, 0, this=True, ret=lambda e: e.r32(e.reg('ecx')) ^ 0x5a5a5a5a)
    phook(c, seq, 0x4cbec0, 0, this=True, act=lambda e, a: e.w32(rec, e.r32(e.reg('ecx'))))
    o = obj(c, 0x40, {0x30: stub(c, seq, 2, ret=r.getrandbits(32))})
    c.emu.w32(0x700394, o)
    return [rnd(c, 0x40)]


def _42f(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(8, 4)
    phook(c, seq, 0x4cbe80, 1, this=True, pop=True, act=lambda e, a: e.w32(e.reg('ecx'), a[0] ^ 0x13572468))
    phook(c, seq, 0x4cc1e0, 2, this=True, pop=True, act=lambda e, a: e.w32(rec, e.r32(a[1])))
    phook(c, seq, 0x4cbec0, 0, this=True, act=lambda e, a: e.w32(rec + 4, e.r32(e.reg('ecx'))))
    return [rnd(c, 0x130), rnd(c, 0x10)]


def _5fa(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x5fa7e0, 0, this=True)
    phook(c, seq, 0x5faad0, 0, this=True)
    phook(c, seq, 0x6014a0, 1, this=True, pop=True, ret=rnd(c, 0x10))
    return [rnd(c, 0x180)]


S(0x491340, 'ZEngineDataBase::GetTreesSize', 'thiscall', None, ret='eax', gen=_491, note='f16b013; MYSTR calls hooked; SEH/cookie not reproduced')
S(0x42fa00, 'ZSysInterface::SaveGamePath', 'thiscall', None, ret='eax', gen=_42f, note='f16b013; MYSTR calls hooked; SEH/cookie not reproduced')
S(0x5fa740, 'FUN_5fa740 (constructor)', 'thiscall', None, ret='eax', gen=_5fa, note='f16b013; SEH not reproduced')
