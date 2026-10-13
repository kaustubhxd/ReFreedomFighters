"""specs_m1411.py - batch 1411: ZFFLevelController::Init. Profile load/save and SetLevel are hooked; the ini
overrides run for real against an ini stub."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402


def g_init(c):
    lc, p = lctrl(c)
    for off in (0x103c, 0x103f):
        c.emu.w8(lc + off, c.rng.choice([0, 0, 1]))
    c.emu.w32(lc + 0x1064, c.emu.r32(obj(c, 8, {0: stub(c, 0, this=True), 4: stub(c, 1, this=True),
                                               0x48: stub(c, 0, this=True)})))
    reg = obj(c, 0x10, {0x60: stub(c, 2, this=True)})
    gv = obj(c, 0x10, {0x68: stub(c, 3, this=True), 0x5c: stub(c, 3, this=True)})
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x134: stub(c, 0, this=True, ret=gv),
                         0x4c: stub(c, 2, this=True, ret=c.rng.getrandbits(32))})
    sysi = rnd(c, 0x1a00)
    c.emu.w32(sysi, c.emu.r32(obj(c, 0x60, {0x5c: stub(c, 2, this=True, skip=(1,), outs=[(1, cstr(c, '3'))],
                                                       rets=[c.rng.choice([0, 1])])})))
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x190f, obj(c, 8, {0x1b4: stub(c, 1, this=True)}))
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(0x6762d8, stub(c, 1, pop=0, ret=3))
    c.emu.w32(0x7003a0, rnd(c, 0x80))
    hook_stub(c, 0x5ae270, 1, this=True, ret=c.rng.choice([0, 1, 0x100]))
    hook_stub(c, 0x5ae710, 1, this=True)
    hook_stub(c, 0x5ae860, 1, this=True)
    return [lc]


S(0x59bd00, 'ZFFLevelController::Init', 'thiscall', ret=None, gen=g_init)
