"""specs_s527.py - weapons batch 527: CreateLnkAction (ids 0-16) and ZLnkAction ctor H (0x485ca0)."""
from pilot import S
from wkit import rnd, stub, obj, patch_jmp


def _cla(c):
    r = c.rng
    # __builtin_new: cdecl, returns a fresh object (or 0) of the requested size
    buf = c.emu.alloc(0x100, 16)
    patch_jmp(c, 0x41e290, stub(c, 1, cdecl=True, ret=buf if r.random() < 0.95 else 0))
    # the constructors run as exe code (the ext_ bindings), so no stubs here
    s = rnd(c, 0x400)
    return [s, r.choice(list(range(0, 17)) + [r.getrandbits(32)])]


def _ctor(c):
    r = c.rng
    o = rnd(c, 0x40)
    return [o] + [r.getrandbits(32) for _ in range(9)]


S(0x4733d0, 'ZLNKWHANDS::CreateLnkAction', 'thiscall', None, ret='eax', gen=_cla)
S(0x485ca0, 'ZLnkAction ctor H (9 args)', 'thiscall', None, ret='eax', gen=_ctor)
