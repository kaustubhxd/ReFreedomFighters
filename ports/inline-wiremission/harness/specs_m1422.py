"""specs_m1422.py - batch 1422: ZFFCareTaker_C04B::Command (bombs at the helipad and the train)."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def placed(c, with_item=False):
    base = c.rng.uniform(-1500, 1500)
    v = [fb(base + c.rng.uniform(-900, 900)) for _ in range(3)]
    item = obj(c, 0x90, {0x2f0: stub(c, 3, this=True), 0x210: stub(c, 1, this=True)})
    return obj(c, 0x90, {0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(1, v[0], 4, 0), (1, v[1], 4, 4), (1, v[2], 4, 8)]),
                         0x20: stub(c, 0, this=True, ret=item)})


def g_cmd(c):
    bomb = placed(c, with_item=True)
    heli = placed(c)
    train = placed(c)
    mgr = rnd(c, 0x140)
    entries = {0x58: stub(c, 1, this=True, rets=[bomb, heli, train])}
    c.emu.w32(mgr, c.emu.r32(obj(c, 0x140, {0x58: stub(c, 1, this=True, rets=[bomb, heli, train]),
                                            0x114: stub(c, 4, this=True, rets=[0x34, 0x65, 0x4e, 0x57, 0x66, 0x67, 0x34, 0x65]),   # cycles: the item id is 0x65 at most calls
                                            0x34: stub(c, 1, this=True)})))
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)
    ct = rnd(c, 0x60)
    c.emu.w32(ct + 0x44, obj(c, 0x30, {0x12c: stub(c, 3, this=True)}))
    c.emu.w32(ct + 0x4e, bomb)   # the bomb from the start event (a message that arrives first would not set it)
    c.emu.w32(ct + 0x52, rnd(c, 16))
    c.emu.w32(ct + 0x56, rnd(c, 16))
    c.emu.w8(ct + 0x4c, c.rng.choice([0, 1]))
    c.emu.w8(ct + 0x4d, c.rng.choice([0, 1]))
    data = rnd(c, 16)
    c.emu.w32(data + 4, c.rng.choice([0, 1]))
    msg = c.rng.choice([0x34, 0x34, 0x65, 0x66]) | (c.rng.getrandbits(16) << 16)
    return [ct, msg, data]


S(0x5bc6e0, 'ZFFCareTaker_C04B::Command', 'thiscall', ret='eax', gen=g_cmd)
