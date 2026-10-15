"""specs_m1421.py - batch 1421: ZFFCareTaker_C04B Init, Init2, deleting dtor."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def world(c):
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 5)]), 0x60: stub(c, 2, this=True)})
    hero = c.emu.alloc(0x100, 4)
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x58: stub(c, 1, this=True, ret=hero),
                         0x4c: stub(c, 2, this=True, ret=0x66), 0x34: stub(c, 1, this=True)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)


def g_init(c):
    world(c)
    hook_stub(c, 0x4e5e60, 0, this=True, rets=[c.rng.getrandbits(32) for _ in range(8)])
    return [rnd(c, 0x60), rnd(c, 8), rnd(c, 8)]


def g_init2(c):
    world(c)
    return [rnd(c, 0x60)]


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


S(0x5bc620, 'ZFFCareTaker_C04B::Init', 'thiscall', ret=None, gen=g_init)
S(0x5bc680, 'ZFFCareTaker_C04B::Init2', 'thiscall', ret=None, gen=g_init2)
S(0x57fe70, 'ZFFCareTaker_C04B deleting dtor', 'thiscall', ret='eax', gen=g_dtor)
