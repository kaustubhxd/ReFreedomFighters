"""specs_s612.py - damage batch 612: CHitpointControl::Notify / FrameUpdate."""
from pilot import S
from wkit import rnd, stub, obj, fedge


def _gen(c):
    r = c.rng
    emu = c.emu
    g = obj(c, 0x40, {0x12c: stub(c, 3, skip=(2,), copy=(2, [(0, 'd'), (4, 'd')]))})
    h = obj(c, 0x80, {0x68: stub(c, 2)})
    emu.w32(h + 0x44, g)
    emu.w32(h + 0x50, r.choice((0, r.getrandbits(32))))
    emu.wf32(h + 0x57, r.choice((0.0, 0.016, 1.0, -0.5, fedge(c))))
    rm = obj(c, 0x80, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    eng = rnd(c, 0x200)
    emu.w32(eng + 0x9b, rm)
    emu.wf32(eng + 0x48, r.choice((0.016, 0.033, 0.0, 1.0, fedge(c))))
    emu.w32(0x70039c, eng)
    return [h]


S(0x5849d0, 'CHitpointControl::Notify', 'thiscall', ret=None, gen=_gen)
S(0x5843d0, 'CHitpointControl::FrameUpdate', 'thiscall', ret=None, gen=_gen)
