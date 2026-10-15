"""specs_m1410.py - batch 1410: ZFFLevelController StartupMenu, ToggleDemoMode, the debug path update, FrameUpdate.
Calls into other areas (GiveHeroFFInventory, SetStats, HintMessage, DumpAI, StartupRebelBase, 0x58a680,
GetStartupParam) are hooked; the CRT float->int (0x633910) runs for real."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402


def world(c, lc):
    """sys (+0x9b manager, +0x1907 input manager), registry, globals, the +0x44 event sender, game data."""
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    gv = obj(c, 0x10, {0x90: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.choice([0, 1, 2]), 1)]),
                       0x68: stub(c, 3, this=True)})
    part = obj(c, 8, {0x14: stub(c, 0, this=True, ret=c.rng.choice([0, 1, 3]))})
    win = rnd(c, 0xd0)
    c.emu.w32(win, c.emu.r32(obj(c, 8, {0x300: stub(c, 0, this=True)})))
    c.emu.w32(win + 0xcb, c.emu.r32(part))
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x134: stub(c, 0, this=True, ret=gv),
                         0x58: stub(c, 1, this=True, ret=win if c.rng.random() < 0.8 else 0),
                         0x114: stub(c, 4, this=True, rets=[0x1234, 0x99999]), 0xb8: stub(c, 0, this=True)})
    grp = obj(c, 0x10, {0x14: stub(c, 1, this=True, ret=c.rng.getrandbits(32))})
    inp = obj(c, 0x80, {0xc: stub(c, 3, this=True), 0x60: stub(c, 1, this=True, ret=grp),
                        0x2c: stub(c, 2, this=True, ret=c.rng.choice([0, 1, 0x100]))})
    sysi = rnd(c, 0x1a00)
    c.emu.w32(sysi, c.emu.r32(obj(c, 8, {})))
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x1907, inp)
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(lc + 0x44, obj(c, 0x10, {0x12c: stub(c, 3, this=True, skip=(2,), derefs=[(2, 0)])}))
    gd = rnd(c, 0x2c40)
    c.emu.w32(gd + 0xd8d, c.rng.choice([0, 1, 3]))
    osd = rnd(c, 0x1d20)
    c.emu.w32(gd + 0x2c2d, osd if c.rng.random() < 0.85 else 0)
    c.emu.w32(0x7003b8, gd)
    hook_stub(c, 0x490fa0, 0, this=True, ret=c.rng.choice([0, 6, 7]))
    hook_stub(c, 0x58a680, 1, this=True)
    hook_stub(c, 0x5ae020, 0, this=True)
    hook_stub(c, 0x597fc0, 2, this=True)
    hook_stub(c, 0x59ce00, 0, this=True)
    hook_stub(c, 0x59b120, 1, this=True)
    rec = c.emu.alloc(48, 4)

    def setstats(e, r):
        esp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.wbytes(rec + 4, e.rbytes(esp + 4, 32))
        e.ret(eax=0, argbytes=32)
    c.emu.hook(0x5ab020, setstats)


def flt(c):
    v = c.rng.choice([-1.0, 0.0, 0.0, 3.7, 12.0, float('nan'), -0.0, 1e9])
    return struct.unpack('<I', struct.pack('<f', v))[0]


def g_lc(c):
    lc, p = lctrl(c, 0x13300)
    for off in (0x103b, 0x103c, 0x103e, 0x103f, 0x1041):
        c.emu.w8(lc + off, c.rng.choice([0, 0, 1]))
    c.emu.w32(lc + 0x1044, c.rng.choice([0, 3, 1]))
    c.emu.w32(lc + 0x132c7, c.rng.choice([0, 1]))
    c.emu.w32(lc + 0x105c, flt(c))
    c.emu.w32(lc + 0x1060, flt(c))
    if c.rng.random() < 0.3:
        c.emu.wbytes(lc + 0x48, b'C02R\0')
    world(c, lc)
    return [lc]


S(0x59cc60, 'ZFFLevelController::StartupMenu', 'thiscall', ret=None, gen=g_lc)
S(0x59ce70, 'ZFFLevelController::ToggleDemoMode', 'thiscall', ret=None, gen=g_lc)
S(0x59cbc0, 'ZFFLevelController::UpdatePathDebug (no map name)', 'thiscall', ret=None, gen=g_lc)
S(0x59b1c0, 'ZFFLevelController::FrameUpdate', 'thiscall', ret=None, gen=g_lc)
