"""specs_m1427.py - batch 1427: ZObjectives Init2, OnKeyPress, OnWindowClose. ZBaseMap / CBaseWindow / MapIconClear are
hooked (they belong to other areas); the window objects are fake objects with slot 0xbc."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def win(c):
    return obj(c, 0x40, {0xbc: stub(c, 1, this=True, skip=(0,))})


def g_init2(c):
    self_ = rnd(c, 0x100)
    c.emu.w32(self_ + 0x44, obj(c, 0x30, {0x4c: stub(c, 2, this=True, ret=0x66)}))
    reg = obj(c, 0x90, {0x60: stub(c, 2, this=True)})
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x4c: stub(c, 2, this=True, ret=0x66),
                         0x58: stub(c, 1, this=True, ret=0)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x562440, 0, this=True)
    return [self_]


def g_key(c):
    self_ = rnd(c, 0x100)
    o = obj(c, 0x30, {0x84: stub(c, 0, this=True, ret=0)})
    c.emu.w32(o, c.emu.r32(o))
    inner = obj(c, 0x30, {0x300: stub(c, 0, this=True)})
    c.emu.w32(self_, c.emu.r32(obj(c, 0x30, {0x84: stub(c, 0, this=True, ret=inner)})))
    hook_stub(c, 0x574250, 1, this=True, ret=c.rng.choice([0, 1]))
    key = c.rng.choice([0x102, 0x103, 0x41, 0x20, 0x104])
    return [self_, key]


def g_close(c):
    self_ = rnd(c, 0x300)
    c.emu.w32(self_ + 0xf8, rnd(c, 16))
    for off in (0x1e4, 0x1d4, 0x1d8, 0x1cc, 0x1d0):
        c.emu.w32(self_ + off, win(c))
    hook_stub(c, 0x574280, 2, this=True)
    hook_stub(c, 0x5aa6e0, 0, this=True)
    return [self_, c.rng.getrandbits(32), c.rng.choice([0, 1])]


S(0x577d00, 'ZObjectives::Init2', 'thiscall', ret=None, gen=g_init2)
S(0x577e20, 'ZObjectives::OnKeyPress', 'thiscall', ret='al', gen=g_key)
S(0x577e60, 'ZObjectives::OnWindowClose', 'thiscall', ret='al', gen=g_close)
