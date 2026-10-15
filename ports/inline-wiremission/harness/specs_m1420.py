"""specs_m1420.py - batch 1420: ZFFCareTaker_C03B constructor, deleting destructor, Command."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def world(c, n114=4):
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 0x55)])})
    target = obj(c, 0x40, {0x128: stub(c, 1, this=True)})
    mgr = obj(c, 0x140, {0x114: stub(c, n114, this=True, rets=[0x31, 0x32, 0x33, 0x34]),
                         0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, ret=target if c.rng.random() < 0.8 else 0),
                         0x34: stub(c, 1, this=True)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)


def g_ctor(c):
    world(c)
    hook_stub(c, 0x469870, 0, this=True)
    return [rnd(c, 0x60)]


def g_cmd(c):
    world(c, n114=6)   # Command's register call pushes six words (see batch1420.cpp)
    ct = rnd(c, 0x60)
    c.emu.w16(ct + 0x48, 0x31)
    msg = c.rng.choice([0x31, 0x31, 0x32]) | (c.rng.getrandbits(16) << 16)
    return [ct, msg, rnd(c, 8)]


def g_dtor(c):
    world(c)
    c.emu.w32(0x7003b0, stub(c, 0, pop=0) if c.rng.random() < 0.9 else 0)
    rec = c.emu.alloc(8, 4)

    def sdel(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(e.reg('esp') + 8))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, sdel)
    return [rnd(c, 0x60), c.rng.choice([0, 1, 5, 4, 3])]


S(0x5bc1d0, 'ZFFCareTaker_C03B::ZFFCareTaker_C03B', 'thiscall', ret='eax', gen=g_ctor)
S(0x5bc2f0, 'ZFFCareTaker_C03B deleting dtor', 'thiscall', ret='eax', gen=g_dtor)
S(0x5bc3e0, 'ZFFCareTaker_C03B::Command', 'thiscall', ret='eax', gen=g_cmd)
