"""specs_m1423.py - batch 1423: ZFFCareTaker_C05A constructor, CopyEventDataBlock, Save, Load."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def world(c):
    mgr = obj(c, 0x140, {0x114: stub(c, 4, this=True, rets=[0x20, 0x21, 0x22]), 0x138: stub(c, 0, this=True, ret=0)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)


def g_ctor(c):
    world(c)
    hook_stub(c, 0x469870, 0, this=True)
    return [rnd(c, 0x80)]


def g_copy(c):
    world(c)
    hook_stub(c, 0x4e5e60, 0, this=True, rets=[c.rng.getrandbits(32) for _ in range(8)])
    return [rnd(c, 0x80), rnd(c, 8)]


def g_save(c):
    world(c)
    sg = obj(c, 0x80, {0x60: stub(c, 1, this=True), 0x54: stub(c, 1, this=True)})
    ct = rnd(c, 0x80)
    return [ct, sg]


def g_load(c):
    world(c)
    lg = obj(c, 0x80, {0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(8), 1)]),
                       0x58: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))])})
    return [rnd(c, 0x80), lg]


S(0x5bcab0, 'ZFFCareTaker_C05A::ZFFCareTaker_C05A', 'thiscall', ret='eax', gen=g_ctor)
S(0x5bce20, 'ZFFCareTaker_C05A::CopyEventDataBlock', 'thiscall', ret=None, gen=g_copy)
S(0x5bd020, 'ZFFCareTaker_C05A::Save', 'thiscall', ret='al', gen=g_save)
S(0x5bcfd0, 'ZFFCareTaker_C05A::Load', 'thiscall', ret='al', gen=g_load)
