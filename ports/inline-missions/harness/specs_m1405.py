"""specs_m1405.py - batch 1405: ZFFLevelController::MakeSceneName (+ CopyEventDataBlock).
striwcmp runs as exe code with the Python CRT string imports (mkit.crt_strings)."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, crt_strings  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402

PATHS = ['C:\\FF\\Scenes\\C02A\\FF-C02A_MAIN', 'C:FF-Startup', 'D:\\_Test\\HeroPlayground\\x', 'C:\\FF-DEMO\\C02A',
         'X:\\c05b_main', 'C:\\c0', 'C:\\c0a', 'C:\\FF_MP\\KOTH_02', 'C:\\ff_mp\\koth_03\\a', 'C:\\FF_MP\\x',
         'C:\\levels\\C09R', 'C:\\levels\\c09r_x', 'C:\\C07A', 'C:\\C09A', '', 'ab', 'C:\\DemoEndScreen',
         'C:\\Scenes\\c03c', 'C:\\C0', 'C:\\xC0z', 'C:\\C1A\\C08e', 'C:\\FF-demo\\c07a']


def g_scene(c):
    lc, p = lctrl(c)
    c.emu.w8(lc + 0x1041, c.rng.choice([0, 1]))
    crt_strings(c)
    n = c.rng.choice([0, 1, 1, 2, 3])
    nodes = []
    for _ in range(n):
        nd = c.emu.alloc(80, 4)
        c.emu.wbytes(nd + 4, (c.rng.choice(PATHS) + '\0').encode('latin-1'))
        nodes.append(nd)
    lvt = c.emu.alloc(0x80, 4)
    c.emu.w32(lvt + 0x54, stub(c, 1, this=True, skip=(0,)))
    c.emu.w32(lvt + 0x74, stub(c, 1, this=True, skip=(0,), rets=nodes + [0] * (16 - len(nodes))))
    mgr = rnd(c, 0x40)
    c.emu.w32(mgr + 0x1c, lvt)
    gv = obj(c, 0x10, {0x68: stub(c, 3, this=True)})
    mvt = c.emu.alloc(0x140, 4)
    c.emu.w32(mvt + 0x134, stub(c, 0, this=True, ret=gv))
    c.emu.w32(mgr, mvt)
    sysi = rnd(c, 0x1c00)
    svt = c.emu.alloc(0x80, 4)
    ini = cstr(c, c.rng.choice(PATHS + ['1', '0']))
    c.emu.w32(svt + 0x5c, stub(c, 2, this=True, skip=(1,), outs=[(1, ini)], rets=[c.rng.choice([0, 1, 0x100])]))
    c.emu.w32(sysi, svt)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(0x6762d8, stub(c, 1, pop=0, rets=[c.rng.choice([0, 1, 7]), c.rng.getrandbits(32)]))
    return [lc]


def g_copy(c):
    return g_scene(c) + [rnd(c, 16)]


S(0x59c0d0, 'ZFFLevelController::MakeSceneName', 'thiscall', ret=None, gen=g_scene)
S(0x59b090, 'ZFFLevelController::CopyEventDataBlock', 'thiscall', ret=None, gen=g_copy)
