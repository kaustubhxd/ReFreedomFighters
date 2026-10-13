"""specs_m1428.py - batch 1428: ZObjectives::DrawUpdate. Slots are unnamed: stubs by slot number.
ZBaseMap::GetScreenPos and ZBaseMap::DrawUpdate are hooked (other areas)."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def vec_obj(c, slot70=True):
    v = [fb(c.rng.uniform(-300, 300)) for _ in range(3)]
    return obj(c, 0x40, {0x70: stub(c, 1, this=True, skip=(0,), outs=[(0, v[0], 4, 0), (0, v[1], 4, 4), (0, v[2], 4, 8)])})


def g_draw(c):
    self_ = rnd(c, 0x200)
    c.emu.w8(self_ + 0x88, c.rng.choice([0, 1, 1]))
    c.emu.w8(self_ + 0x1f1, c.rng.choice([0, 1, 1]))
    c.emu.w32(self_ + 0x1c4, c.rng.getrandbits(16))
    x = vec_obj(c)
    c.emu.w32(self_ + 0x180, obj(c, 0x40, {0x20: stub(c, 0, this=True, ret=x)}))
    c.emu.w32(self_ + 0x188, vec_obj(c))
    c.emu.w32(self_ + 0x1ec, obj(c, 0x40, {0x84: stub(c, 1, this=True, skip=(0,),
                                                     outs=[(0, fb(c.rng.uniform(-50, 50)), 4, 0)])}))
    # sys: slot 0xbc -> object whose slot 0xdc is the map-open test
    map_obj = obj(c, 0x40, {0xdc: stub(c, 0, this=True, ret=c.rng.choice([0, 1]))})
    mgr = rnd(c, 0x100)
    sysi = rnd(c, 0x100)
    sys_vt = obj(c, 0x100, {0xbc: stub(c, 0, this=True, ret=map_obj)})
    c.emu.w32(sysi, c.emu.r32(sys_vt))
    c.emu.w32(sysi + 0x6f, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x573c70, 2, this=True)
    hook_stub(c, 0x573930, 2, this=True)
    cam = rnd(c, 16)
    return [self_, cam, c.rng.choice([0, 1, 2, 3])]


S(0x577bb0, 'ZObjectives::DrawUpdate', 'thiscall', ret=None, gen=g_draw)
