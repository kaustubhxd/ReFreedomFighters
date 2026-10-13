"""specs_m1419.py - batch 1419: ZFFCareTaker_C03A."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def positioned(c):
    v = [fb(c.rng.uniform(-900, 900)) for _ in range(3)]
    g = obj(c, 0x300, {0x2f0: stub(c, 3, this=True), 0x210: stub(c, 1, this=True)})
    return obj(c, 0x90, {0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(1, v[0], 4, 0), (1, v[1], 4, 4), (1, v[2], 4, 8)]),
                         0x20: stub(c, 0, this=True, rets=[g, c.rng.choice([g, 0])])})


def world(c):
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 5)]), 0x60: stub(c, 2, this=True)})
    mgr = obj(c, 0x140, {0x58: stub(c, 1, this=True, rets=[positioned(c), positioned(c)]),
                         0x114: stub(c, 4, this=True, rets=[0x31, 0x32, 0x33, 0x34, 0x35]),
                         0x138: stub(c, 0, this=True, ret=reg), 0x4c: stub(c, 2, this=True, ret=0x66),
                         0x34: stub(c, 1, this=True)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)


def g_cmd(c):
    world(c)
    ct = rnd(c, 0x61)
    c.emu.w32(ct + 0x44, obj(c, 0x140, {0x12c: stub(c, 3, this=True)}))
    msg = c.rng.choice([0x31, 0x32, 0x33, 0x40]) | (c.rng.getrandbits(16) << 16)
    return [ct, msg, rnd(c, 8)]


def g_copy(c):
    world(c)
    hook_stub(c, 0x4e5e60, 0, this=True, rets=[1, 2, 3])
    return [rnd(c, 0x61), rnd(c, 8)]


def g_ct(c):
    world(c)
    return [rnd(c, 0x61)]


def g_load(c):
    world(c)
    lg = obj(c, 0x80, {0x40: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))]),
                       0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, 1, 1)]),
                       0x50: stub(c, 1, this=True, skip=(0,), outs=[(0, fb(2.5))])})
    return [rnd(c, 0x61), lg]


def g_save(c):
    world(c)
    sg = obj(c, 0x80, {k: stub(c, 1, this=True) for k in (0x64, 0x60, 0x4c, 0x3c)})
    return [rnd(c, 0x61), sg]


def g_dtor(c):
    world(c)
    c.emu.w32(0x7003b0, stub(c, 0, pop=0) if c.rng.random() < 0.9 else 0)
    rec = c.emu.alloc(8, 4)

    def sdel(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(e.reg('esp') + 8))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, sdel)
    return [rnd(c, 0x61), c.rng.choice([0, 1, 5, 4, 3])]


S(0x5bbcb0, 'ZFFCareTaker_C03A::Command', 'thiscall', ret='eax', gen=g_cmd)
S(0x5bbfe0, 'ZFFCareTaker_C03A::CopyEventDataBlock', 'thiscall', ret=None, gen=g_copy)
S(0x5bc050, 'ZFFCareTaker_C03A::Init2', 'thiscall', ret=None, gen=g_ct)
S(0x5bc0a0, 'ZFFCareTaker_C03A::Load', 'thiscall', ret='al', gen=g_load)
S(0x5bc160, 'ZFFCareTaker_C03A::Save', 'thiscall', ret='al', gen=g_save)
S(0x5bc4e0, 'ZFFCareTaker_C03A/C03C deleting dtor', 'thiscall', ret='eax', gen=g_dtor)
