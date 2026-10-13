"""specs_m1424.py - batch 1424: ZFFCareTaker_C05A::FrameUpdate (loudspeaker line).
GetResource runs as a stub that writes a resource record; GetText is hooked to return a fixed string."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402


def g_fu(c):
    text = cstr(c, 'Loudspeaker line')
    # mgr: vtable slots 0x114 (register message), 0x138 (registry), 0x58 (handle -> object), 0x134 unused here.
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 5)])})
    hero = rnd(c, 0x900)
    c.emu.w32(hero + 0x852, rnd(c, 16))
    mgr = rnd(c, 0xb00)
    mvt = obj(c, 0x140, {0x114: stub(c, 5, this=True, ret=0x71), 0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, ret=hero)})
    c.emu.w32(mgr, c.emu.r32(mvt))
    # ResourceCollection at [mgr+0xae4]: its vtable slot 0 = GetResource(name, res) (cdecl-free, thiscall, 2 args)
    rcvt = obj(c, 0x10, {})
    rc = obj(c, 0x20, {})
    c.emu.w32(rc, rcvt)
    c.emu.w32(mgr + 0xae4, rc)
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x40, c.rng.getrandbits(24))
    c.emu.w32(0x70039c, sysi)
    res_rec = rnd(c, 0x40)
    hook_stub(c, 0x49df60, 2, this=True, skip=(0, 1), rets=[res_rec, 0, res_rec, res_rec])   # GetResource (called directly)
    hook_stub(c, 0x49e0d0, 0, this=True, rets=[text, text])   # GetText(Resource*)
    hook_stub(c, 0x59a5b0, 3, this=True)
    ct = rnd(c, 0x80)
    c.emu.w8(ct + 0x5e, c.rng.choice([0, 1, 1]))
    c.emu.w32(ct + 0x5f, c.rng.getrandbits(20))
    c.emu.w32(ct + 0x6f, c.rng.getrandbits(32))
    c.emu.w32(ct + 0x44, obj(c, 0x20, {0x12c: stub(c, 2, this=True)}))
    return [ct]


S(0x5bce80, 'ZFFCareTaker_C05A::FrameUpdate', 'thiscall', ret=None, gen=g_fu)
