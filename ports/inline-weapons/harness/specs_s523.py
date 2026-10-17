"""specs_s523.py - weapons batch 523: DropItem / PickupItem / PushButton / UseItem (script commands to the owner)."""
from pilot import S
from wkit import rnd, stub, obj, sysobj, patch_jmp


def _env(c):
    r = c.rng
    patch_jmp(c, 0x4d2280, stub(c, 0))
    patch_jmp(c, 0x4d2330, stub(c, 0))
    patch_jmp(c, 0x4ccba0, stub(c, 0))
    patch_jmp(c, 0x4ccf60, stub(c, 0))
    patch_jmp(c, 0x4cd540, stub(c, 1))
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    for g in (0x6ff9a0, 0x6ff9a4, 0x6ff9a8, 0x6ff9ac):
        c.emu.w32(g, r.getrandbits(32))
    return obj(c, 0x600, {0x168: stub(c, 2, skip=(1,))})


def _one(c):
    r = c.rng
    patch_jmp(c, 0x4d3ab0, stub(c, 2))
    return [_env(c), r.getrandbits(32)]


def _use(c):
    r = c.rng
    patch_jmp(c, 0x4d3ab0, stub(c, 2, skip=(1,)))   # one value is a pointer to the caller's REFTAB
    return [_env(c), 0 if r.random() < 0.3 else r.getrandbits(32), r.getrandbits(32)]


S(0x473a70, 'ZLNKWHANDS::DropItem', 'thiscall', None, ret=None, gen=_one)
S(0x474e00, 'ZLNKWHANDS::PickupItem', 'thiscall', None, ret=None, gen=_one)
S(0x474f60, 'ZLNKWHANDS::PushButton', 'thiscall', None, ret=None, gen=_one)
S(0x476100, 'ZLNKWHANDS::UseItem', 'thiscall', None, ret=None, gen=_use)
