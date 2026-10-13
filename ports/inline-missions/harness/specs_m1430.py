"""specs_m1430.py - batch 1430: ZObjectives::SetupIconObj. Per-icon object slots stubbed by number; ZBaseMap::SetupIcon hooked."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def g_icon(c):
    self_ = rnd(c, 0x240)
    n = c.rng.choice([0, 1, 3, 8])
    count = c.rng.choice([0, 1, 2, 5])
    c.emu.w32(self_ + 0x1fe, count)
    c.emu.w32(self_ + 0x202, c.rng.randrange(0, 4))
    c.emu.w32(self_ + 0x210, fb(c.rng.uniform(-100, 100)))
    c.emu.w32(self_ + 0x214, fb(c.rng.uniform(-100, 100)))
    c.emu.w32(self_ + 0x21c, fb(c.rng.uniform(-50, 50)))
    c.emu.w32(self_ + 0x220, c.rng.getrandbits(8))
    table = []
    for _ in range(8):
        o = obj(c, 0x140, {0x2a0: stub(c, 1, this=True), 0x284: stub(c, 1, this=True), 0xbc: stub(c, 1, this=True),
                           0x70: stub(c, 1, this=True), 0x260: stub(c, 1, this=True)})
        table.append(o)
    for i in range(8):
        c.emu.w32(self_ + 0x190 + 4 * i, table[i])
    hook_stub(c, 0x574af0, 5, this=True, skip=(1,))
    icon = c.rng.choice([0, 1, 2, 5, 9])
    flag = c.rng.choice([0, 1])
    name = cstr(c, c.rng.choice(['Icon_A', 'Icon_B', 'x']))
    return [self_, icon, flag, name]


S(0x578430, 'ZObjectives::SetupIconObj', 'thiscall', ret=None, gen=g_icon)
