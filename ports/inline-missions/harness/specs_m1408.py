"""specs_m1408.py - batch 1408: ZFFLevelController::GetStartingSewerLid.
GetSewerInfo, GetMatPos and the lid-open call are hooked; the x87 vector subtract (0x43e960) and the CRT sqrt
(emulator import stub) run for real."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402


def fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-200, 200)))[0]


def lid(c, num):
    t = rnd(c, 16)
    c.emu.w32(t + 4, cstr(c, 'SewerLid%02d' % num))
    o = obj(c, 16, {0x20: stub(c, 0, this=True, ret=t)})
    return obj(c, 32, {0x20: stub(c, 0, this=True, ret=o),
                       0x84: stub(c, 1, this=True, skip=(0,), outs=[(0, fbits(c), 4, 0), (0, fbits(c), 4, 4),
                                                                   (0, fbits(c), 4, 8)])})


def g_lid(c):
    lc, p = lctrl(c)
    c.emu.w8(lc + 0x103f, c.rng.choice([0, 0, 0, 1]))
    c.emu.w32(lc + 0x1050, 0 if c.rng.random() < 0.85 else c.rng.getrandbits(32))
    n = c.rng.choice([0, 1, 2, 5])
    gd = rnd(c, 0xc6d + 9 * 6)
    c.emu.w32(gd + 0xc69, n)
    lids = [lid(c, c.rng.randrange(0, 8)) for _ in range(n)]
    for i in range(n):
        c.emu.w32(gd + 0xc6d + 9 * i + 4, i + 100)
    c.emu.w32(0x7003b8, gd)
    sid = c.rng.choice([-1, -1, -2, -3, 0, 3, 7])
    pos = [fbits(c) for _ in range(3)]

    def info(e, r):
        esp = e.reg('esp')
        e.w32(e.r32(esp + 8), sid & 0xffffffff)
        for k in range(3):
            e.w32(e.r32(esp + 12) + 4 * k, pos[k])
        e.ret(eax=0, argbytes=16)
    c.emu.hook(0x5b15d0, info)

    def matpos(e, r):
        esp = e.reg('esp')
        for k in range(3):
            e.w32(e.r32(esp + 8) + 4 * k, pos[(k + 1) % 3])
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x4db2c0, matpos)
    hook_stub(c, 0x5c3a90, 1, this=True)
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 0x55)])})
    hero_g = rnd(c, 16)
    c.emu.w32(hero_g, c.emu.r32(obj(c, 8, {0x74: stub(c, 2, this=True, skip=(0, 1))})))
    hero = obj(c, 16, {0x20: stub(c, 0, this=True, ret=hero_g)})
    sysi = obj(c, 0x100, {0: 0})
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, rets=[hero] + lids * 3 if lids else [hero])})
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(0x70038c, obj(c, 16, {0xcc: stub(c, 1, this=True, ret=rnd(c, 16))}))
    return [lc]


S(0x59b3c0, 'ZFFLevelController::GetStartingSewerLid', 'thiscall', ret='eax', gen=g_lid)
