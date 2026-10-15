"""specs_m1418.py - batch 1418: ZFFCareTaker_C02A FrameUpdate and destructors."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def reftab(c, n, ret_base=100):
    state = {'k': 0}

    def nxt(e, r):
        k = state['k']
        state['k'] = k + 1
        e.w32(e.r32(e.reg('esp') + 4), 1 if k < n else 0)
        e.ret(eax=ret_base + k, argbytes=4)
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x4c, stub(c, 1, this=True, skip=(0,), outs=[(0, 1)]))
    c.emu.w32(vt + 0x5c, c.emu.stub_fn('reftab next', nxt))
    return vt


def g_fu(c):
    ct = rnd(c, 0x390)
    for off in (0x294, 0x295, 0x2a2, 0x2a7, 0x373, 0x374, 0x375, 0x37a, 0x37f):
        c.emu.w8(ct + off, c.rng.choice([0, 1]))
    for off in (0x70, 0x74, 0x80):
        c.emu.w32(ct + off, c.rng.choice([0, 4]))
    now = c.rng.getrandbits(20) + 0x10000
    for off in (0x29e, 0x2a8, 0x376, 0x37b):
        c.emu.w32(ct + off, (now + c.rng.choice([-0x2000, -10, 0, 10])) & 0xffffffff)
    c.emu.w32(ct + 0x2a3, c.rng.choice([0x1f, 0x15]))
    c.emu.w32(ct + 0x29a, c.rng.choice([2, 1, 0, 0xffffffff]))
    c.emu.w32(ct + 0x84, reftab(c, c.rng.choice([0, 2])))
    c.emu.w32(ct + 0x2c6, reftab(c, c.rng.choice([0, 1, 3])))
    hero = rnd(c, 0x900)
    o = rnd(c, 0x2300)
    c.emu.w32(o + 0x1fae, c.rng.choice([0, 1, 2, 5]))
    c.emu.w32(hero + 0x852, o)
    c.emu.w32(ct + 0x64, hero)
    c.emu.w32(ct + 0x44, obj(c, 0x140, {0x12c: stub(c, 3, this=True)}))
    thing = obj(c, 0x440, {0x2c: stub(c, 0, this=True), 0x28: stub(c, 0, this=True),
                           0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(1, 0x3f800000, 4, 0), (1, 0x40400000, 4, 4), (1, 0xc0000000, 4, 8)]),
                           0x7c: stub(c, 2, this=True, skip=(0, 1), copy=(1, 12, None)),
                           0x438: stub(c, 0, this=True, rets=[1, 1, c.rng.choice([0, 1])])})
    mgr = obj(c, 0x140, {0x58: stub(c, 1, this=True, ret=thing), 0x114: stub(c, 4, this=True, ret=0x99),
                         0x4c: stub(c, 1, this=True, ret=0x1234)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x40, now)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x5bb960, 2, this=True)
    hook_stub(c, 0x597fc0, 2, this=True)
    hook_stub(c, 0x597fb0, 0, this=True)
    hook_stub(c, 0x591e50, 1, this=True, ret=c.rng.choice([0, 1]))
    return [ct]


def g_body(c):
    mgr = obj(c, 0x140, {0x34: stub(c, 1, this=True)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x4ccf60, 0, this=True)
    return [rnd(c, 0x390)]


def g_dtor(c):
    a = g_body(c)
    c.emu.w32(0x7003b0, stub(c, 0, pop=0) if c.rng.random() < 0.9 else 0)
    rec = c.emu.alloc(8, 4)

    def sdel(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(e.reg('esp') + 8))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, sdel)
    return a + [c.rng.choice([0, 1, 5, 4, 3])]


S(0x5bb160, 'ZFFCareTaker_C02A::FrameUpdate', 'thiscall', ret=None, gen=g_fu)
S(0x57fad0, 'ZFFCareTaker_C02A destructor body', 'thiscall', ret=None, gen=g_body)
S(0x5babb0, 'ZFFCareTaker_C02A deleting dtor', 'thiscall', ret='eax', gen=g_dtor)
