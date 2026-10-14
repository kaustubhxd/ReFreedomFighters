"""specs_s906.py - vehicles batch 906: ZHeli::UpdateCannonSound. AddSound3d runs as exe code; with the engine's
sound manager pointer (+0x1a9f) zero it returns 0 at once, otherwise its slot 0x11c stub returns 0 or a handle."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub


def g_cs(c):
    node = _rnd(c, 0x90)
    grp = obj(c, 0x80)
    gm = _rnd(c, 0x48)
    c.emu.w32(grp + 8, gm)
    s = _rnd(c, 0x2000)
    wd = obj(c, 0x40, {0x58: idstub(c, [0, grp, grp, grp]), 0x60: idstub(c, [c.rng.choice([0, node]), node, 0, node])})
    c.emu.w32(s + 0x9b, wd)
    c.emu.w32(s + 0x1a9f, 0)
    c.emu.w32(0x70039c, s)
    h = _rnd(c, 0x600)
    c.emu.w32(h + 0x469, c.rng.choice([0, 1]))
    for off in (0x409, 0x40d):
        c.emu.w32(h + off, c.rng.choice([0, 1, 2]))
    for off in (0x4a1, 0x49d):
        c.emu.w32(h + off, c.rng.choice([0, 0, 1, 2]))
    return [h]


S(0x51d6f0, 'ZHeli::UpdateCannonSound', 'thiscall', gen=g_cs)
