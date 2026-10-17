"""specs_s506.py - unclaimed-05 batch 6 (claim 6): CExplodeMolotov::Init (0x584480), thiscall, void.
Object model (harness/engine_stubs.py): this+0x44 is a lookup object whose slot +0x25c returns a block O for both
lookups; O has logging slots +0x224 and +0x24 and a zeroed block at +8 (the exe helpers 0x4dbe30 and 0x4dc440 run on it).
The engine at the global 0x70039c has a pointer at +0x9b to EN; EN has a logging slot +0x4c (returns a value, the dword
stored at this+0x362) and a pointer at +0xadc to EX (slot +0x288). The assert log object at 0x700390 is set but never used
on the non-null path."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _molotov(c):
    self_ = zero_obj(c, 0x400)
    o = zero_obj(c, 0x400)
    o_vt = c.emu.logging_vtable('ZMolotovObj', 0x100, impl={}, argwords={0x224: 1, 0x24: 1})
    c.emu.w32(o, o_vt)
    c.emu.w32(o + 8, logged_obj(c, 'ZMolotovSub', 0x100))
    lk = logged_obj(c, 'ZMolotovLookup', 0x100, impl={0x25c: lambda e, a: (o, None)}, argwords={0x25c: 2})
    c.emu.w32(self_ + 0x44, lk)
    val = c.rng.getrandbits(32)
    en = c.emu.alloc(0x1000, 16)
    c.emu.wbytes(en, bytes(0x1000))
    en_vt = c.emu.logging_vtable('ZEngineObj', 0x100, impl={0x4c: lambda e, a: (val, None)}, argwords={0x4c: 1})
    c.emu.w32(en, en_vt)
    ex = logged_obj(c, 'ZEngineSub', 0x100, impl={}, argwords={0x288: 3})
    c.emu.w32(en + 0xadc, ex)
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    log = logged_obj(c, 'ZAssertLog', 0x40, impl={0x20: lambda e, a: (logged_obj(c, 'ZAssertMsg', 0x100), None)}, argwords={0x20: 2})
    set_global(c, 0x700390, log)
    return [self_]


S(0x584480, 'CExplodeMolotov::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_molotov,
  note='unclaimed-05 batch 6; lookups via +0x25c; engine seq; exe helpers 0x4dbe30/0x4dc440 on O+8; assert path not reached')
