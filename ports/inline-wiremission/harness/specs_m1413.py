"""specs_m1413.py - batch 1413: ZFFCareTaker_C01A::FrameUpdate. Hero item/inventory/OSD calls and JumpToAct are
hooked; the distance helper 0x4e0870 (vector subtract + CRT sqrt) runs for real."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def g_fu(c):
    ct = rnd(c, 0xd0)
    c.emu.w32(ct + 0x48, fb(c.rng.choice([0.0, 0.0, 3.0, 5.7, -1.0, float('nan')])))
    for off in (0x60, 0x61, 0x64, 0x65, 0xb8, 0xbd):
        c.emu.w8(ct + off, c.rng.choice([0, 0, 1]))
    c.emu.w32(ct + 0x5c, c.rng.choice([0, 0, 5, 9, 10, 3]))
    hp = [fb(c.rng.uniform(-600, 600)) for _ in range(3)]
    for i in range(3):
        c.emu.w32(ct + 0xbe + 4 * i, fb(c.rng.uniform(-300, 300)))
    hero = rnd(c, 0xa00)
    c.emu.w32(hero, c.emu.r32(obj(c, 0x600, {0x84: stub(c, 1, this=True, skip=(0,), outs=[(0, hp[0], 4, 0), (0, hp[1], 4, 4), (0, hp[2], 4, 8)]),
                                            0x5d0: stub(c, 0, this=True, ret=c.rng.choice([0x10, 3]))})))
    c.emu.w32(hero + 0x852, rnd(c, 16))
    c.emu.w32(ct + 0x58, hero)
    sub = rnd(c, 0x100)
    jones = obj(c, 0x10, {0x50c: stub(c, 0, this=True, ret=sub if c.rng.random() < 0.7 else 0)})
    c.emu.w32(ct + 0x50, jones)
    c.emu.w32(ct + 0x44, obj(c, 16, {0x130: stub(c, 3, this=True)}))
    mgr = obj(c, 0x140, {0x114: stub(c, 4, this=True, ret=0x4321)})
    rv = c.rng.choice([0.0, 0.25, 0.999, 0.5])

    def rnd_h(e, r):
        e.ret(st0=rv, argbytes=8)
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi, c.emu.r32(obj(c, 0x1d0, {0x1c4: c.emu.stub_fn('sys rand', rnd_h)})))
    c.emu.w32(sysi + 0x9b, mgr)
    now = c.rng.getrandbits(20)
    c.emu.w32(sysi + 0x40, now)
    c.emu.w32(ct + 0xb4, (now - c.rng.choice([0, 1000, 9000, 20000])) & 0xffffffff)
    c.emu.w32(ct + 0xb9, (now + c.rng.choice([-5, 5, 0])) & 0xffffffff)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x5ba310, 1, this=True)
    hook_stub(c, 0x591b20, 0, this=True, rets=[c.rng.choice([4, 0xc, 0x10, 1])])
    hook_stub(c, 0x5af7c0, 3, this=True)
    hook_stub(c, 0x597fc0, 2, this=True)
    hook_stub(c, 0x597fb0, 0, this=True)
    return [ct]


S(0x5b9f20, 'ZFFCareTaker_C01A::FrameUpdate', 'thiscall', ret=None, gen=g_fu)
