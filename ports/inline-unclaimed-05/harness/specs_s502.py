"""specs_s502.py - unclaimed-05 batch 2 (docs/20-unclaimed-05.md, claim 2): two hero/throw functions.
ZFFHeroMovementRaiseFlag::GetAnims (0x5e4740) runs the original base GetAnims (0x5e3e90) and then three virtual lookups
on this (slot +0x58), so the object gets a logging vtable whose slot +0x58 returns a value that depends only on the call
count (the same in the original and the port). ZFFActionThrow dtor (0x5df880) calls the CRT sized delete (0x634273) when
bit 0 of its argument is set; that call is hooked and logged, not run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _raise_setup(c):
    # the CRT delete is not used here, but the hook keeps the harness from running free() on the fake heap
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete', 0, 0, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))


def _raise(c):
    # zeroed object: the base GetAnims reads pointer fields from the object, and random ones fault in both runs
    o = c.emu.alloc(0x800, 16)
    c.emu.wbytes(o, bytes(0x800))
    # slot +0x58 hands back a valid zeroed block (the base GetAnims dereferences what it returns); +0x54 returns nothing
    blk = c.emu.alloc(0x400, 16)
    c.emu.wbytes(blk, bytes(0x400))
    vt = c.emu.logging_vtable('ZFFHeroMovementRaiseFlag', 0x70,
                              impl={0x58: lambda e, a: (blk, None)})
    c.emu.w32(o, vt)
    return [o]


def _throw(c):
    o = _rnd(c, 0x800)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        flags |= 1
    else:
        flags &= ~1 & 0xffffffff
    return [o, flags]


S(0x5e4740, 'ZFFHeroMovementRaiseFlag::GetAnims (unknown) thiscall', 'thiscall', None, ret=None, gen=_raise,
  setup=_raise_setup, note='unclaimed-05 batch 2; calls base GetAnims 0x5e3e90 (original) and three slot +0x58 lookups')
S(0x5df880, 'ZFFActionThrow::~ZFFActionThrow (unknown) thiscall', 'thiscall', None, ret='eax', gen=_throw,
  setup=_raise_setup, note='unclaimed-05 batch 2; vtable word 0x685294; delete (0x634273) hooked when bit 0 set')


# batch 3 (claim 3): ZMovementStand dtor. Its three sub-object dtors (0x480fd0) run original code on this object.
def _stand(c):
    o = c.emu.alloc(0x800, 16)
    c.emu.wbytes(o, bytes(0x800))
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        flags |= 1
    else:
        flags &= ~1 & 0xffffffff
    return [o, flags]


S(0x487a00, 'ZMovementStand::~ZMovementStand (unknown) thiscall', 'thiscall', None, ret='eax', gen=_stand,
  setup=_raise_setup, note='unclaimed-05 batch 3; vtable 0x68cfb4 then 0x68cf50; sub-dtors 0x480fd0; delete hooked')
