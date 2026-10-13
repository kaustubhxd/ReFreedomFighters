"""specs_m1415.py - batch 1415: ZFFCareTaker_C02A ctor, Init, Load2, CopyEventDataBlock."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def world(c):
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    mgr = obj(c, 0x140, {0x114: stub(c, 4, this=True, rets=list(range(20, 36))), 0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, ret=c.rng.getrandbits(32))})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)


def g_ctor(c):
    world(c)
    hook_stub(c, 0x469870, 0, this=True)
    hook_stub(c, 0x4ccba0, 0, this=True)
    return [rnd(c, 0x390)]


def g_init(c):
    ct = rnd(c, 0x390)
    c.emu.w32(ct + 0x2b8, c.rng.choice([0, 3, 0x40]))
    return [ct]


def g_ct(c):
    world(c)
    return [rnd(c, 0x390)]


def g_copy(c):
    hook_stub(c, 0x4e5e60, 0, this=True, rets=[c.rng.getrandbits(32) for _ in range(16)])
    hook_stub(c, 0x4e6330, 1, this=True)
    return [rnd(c, 0x390), rnd(c, 8)]


S(0x5ba890, 'ZFFCareTaker_C02A::ZFFCareTaker_C02A', 'thiscall', ret='eax', gen=g_ctor)
S(0x5bb7a0, 'ZFFCareTaker_C02A::Init', 'thiscall', ret=None, gen=g_init)
S(0x5bb870, 'ZFFCareTaker_C02A::Load2', 'thiscall', ret=None, gen=g_ct)
S(0x5bb0a0, 'ZFFCareTaker_C02A::CopyEventDataBlock', 'thiscall', ret=None, gen=g_copy)
