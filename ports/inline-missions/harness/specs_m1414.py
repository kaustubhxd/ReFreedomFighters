"""specs_m1414.py - batch 1414: ZFFCareTaker_C01A constructor and destructors."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def world(c):
    mgr = obj(c, 0x140, {0x114: stub(c, 4, this=True, rets=[11, 12, 13, 14, 15, 16, 17]), 0x34: stub(c, 1, this=True)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi, c.emu.r32(obj(c, 0x1b0, {0x1a4: stub(c, 1, this=True), 0x1a8: stub(c, 1, this=True)})))
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)


def g_ctor(c):
    world(c)
    hook_stub(c, 0x469870, 0, this=True)
    mem = rnd(c, 0x108) if c.rng.random() < 0.9 else 0
    rec = c.emu.alloc(8, 4)

    def new(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.ret(eax=mem, argbytes=0)   # cdecl
    c.emu.hook(0x41e290, new)
    hook_stub(c, 0x4d8330, 3, this=True, ret=mem)
    return [rnd(c, 0xd0)]


def g_body(c):
    world(c)
    ct = rnd(c, 0xd0)
    c.emu.w32(ct + 0x80, obj(c, 8, {0: stub(c, 1, this=True)}) if c.rng.random() < 0.8 else 0)
    return [ct]


def g_dtor(c):
    a = g_body(c)
    fr = stub(c, 0, pop=0)
    c.emu.w32(0x7003b0, fr if c.rng.random() < 0.9 else 0)
    rec = c.emu.alloc(8, 4)

    def sdel(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(e.reg('esp') + 8))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, sdel)
    return a + [c.rng.choice([0, 1, 5, 4, 3])]


S(0x5b9880, 'ZFFCareTaker_C01A::ZFFCareTaker_C01A', 'thiscall', ret='eax', gen=g_ctor)
S(0x5b9a60, 'ZFFCareTaker_C01A::~ZFFCareTaker_C01A body', 'thiscall', ret=None, gen=g_body)
S(0x5b9af0, 'ZFFCareTaker_C01A deleting dtor', 'thiscall', ret='eax', gen=g_dtor)


def g_beam(c):
    from mkit import logger, cstr
    world(c)
    logger(c, nargs=4)
    mgr = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    room = obj(c, 0x1e0, {0x1d8: stub(c, 2, this=True, skip=(0,), ret=0)})
    c.emu.w32(c.emu.r32(mgr) + 0x58, stub(c, 1, this=True, ret=room))
    actor = obj(c, 0x680, {0x370: stub(c, 2, this=True, skip=(0, 1), copy=(0, 36, None)),
                           0x5dc: stub(c, 2, this=True, skip=(0, 1), copy=(0, 12, None)),
                           0x660: stub(c, 0, this=True, ret=c.rng.getrandbits(32)),
                           0x1d8: stub(c, 2, this=True, skip=(0,), ret=0)})
    vals = [c.rng.getrandbits(32) for _ in range(12)]
    geom = obj(c, 0x90, {0x80: stub(c, 2, this=True, skip=(0, 1),
                                    outs=[(0, vals[i], 4, 4 * i) for i in range(9)] + [(1, vals[9 + i], 4, 4 * i) for i in range(3)])})
    hook_stub(c, 0x4cc1d0, 0, this=False, rets=[cstr(c, 'Room_A'), cstr(c, 'Jones')])
    hook_stub(c, 0x4cbec0, 0)
    return [rnd(c, 0xd0), actor, geom]


S(0x5b9c00, 'ZFFCareTaker_C01A::BeamActor', 'thiscall', ret=None, gen=g_beam)
