"""specs_s525.py - weapons batch 525: ZLNKWHANDS::AddNearItem."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp


def _add(c):
    r = c.rng
    lst = obj(c, 0x40, {0x4: stub(c, 1)})
    buf = rnd(c, 0x20)
    patch_jmp(c, 0x41e290, stub(c, 1, cdecl=True, ret=buf if r.random() < 0.9 else 0))
    patch_jmp(c, 0x4ccbe0, stub(c, 2, rec_ecx=True, ret=lst))
    s = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)
    g = rnd(c, 0x40)
    gf = rnd(c, 0x40)
    c.emu.w32(g + 8, gf)
    if r.random() < 0.3:
        c.emu.w32(g + 4, 0)
    sysobj(c, {0x58: stub(c, 1, ret=g)})
    h = rnd(c, 0x400)
    c.emu.w32(h + 0x3b7, 0 if r.random() < 0.4 else lst)
    return [h, r.getrandbits(32)]


S(0x4720f0, 'ZLNKWHANDS::AddNearItem', 'thiscall', None, ret=None, gen=_add)
