"""specs_m1409.py - batch 1409: ZFFLevelController::Command."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402
from specs_m1408 import lid, fbits  # noqa: E402

IDS = [11, 12, 13, 14, 15, 16]


def g_cmd(c):
    lc, p = lctrl(c)
    logger(c)
    k = c.rng.randrange(0, 7)
    msg = (IDS[k] if k < 6 else c.rng.choice([0, 17, 0x1000b])) | (c.rng.getrandbits(16) << 16)
    data = rnd(c, 16)
    if k == 1:   # GETMISSIONVAR block
        c.emu.w32(data + 4, c.rng.choice(p + [0]))
        if c.rng.random() < 0.1:
            data = 0   # the original then writes 0 to address 0
    elif k == 2:
        data = c.rng.choice(p) if c.rng.random() < 0.9 else 0
    elif k == 5:
        data = c.rng.getrandbits(32)
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 0x77)])})
    hero_g = rnd(c, 16)
    c.emu.w32(hero_g, c.emu.r32(obj(c, 8, {})))
    hero = obj(c, 16, {0x20: stub(c, 0, this=True, ret=hero_g)})
    mgr = obj(c, 0x140, {0x114: stub(c, 4, this=True, rets=IDS + [0x5555] * 10),
                         0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, rets=[lid(c, c.rng.randrange(0, 9)),
                                                          hero if c.rng.random() < 0.8 else 0])})
    sysi = obj(c, 0x100, {0: 0})
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    mat = [fbits(c) for _ in range(12)]

    def matpos(e, r):
        esp = e.reg('esp')
        for i in range(9):
            e.w32(e.r32(esp + 4) + 4 * i, mat[i])
        for i in range(3):
            e.w32(e.r32(esp + 8) + 4 * i, mat[9 + i])
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x4db2c0, matpos)
    rec = c.emu.alloc(64, 4)

    def setinfo(e, r):
        esp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.r32(esp + 4))
        e.w32(rec + 8, e.r32(esp + 8))
        e.wbytes(rec + 12, e.rbytes(e.r32(esp + 12), 12))
        e.wbytes(rec + 24, e.rbytes(e.r32(esp + 16), 36))
        e.ret(eax=0, argbytes=16)
    c.emu.hook(0x5b1760, setinfo)
    return [lc, msg, data]


S(0x59ae60, 'ZFFLevelController::Command', 'thiscall', ret='eax', gen=g_cmd)
