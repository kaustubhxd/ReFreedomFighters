"""specs_m1412.py - batch 1412: ZFFCareTaker_C01A Init, Init2, Save, Load."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def world(c):
    hero = rnd(c, 0xa00)
    c.emu.w32(hero, c.emu.r32(obj(c, 0x90, {0x84: stub(c, 1, this=True, outs=[(0, 0x3f800000, 4, 0), (0, 0x40000000, 4, 8)])})))
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x58: stub(c, 1, this=True, ret=hero)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x6352f0, 1, this=True, skip=(0,))
    hook_stub(c, 0x5ba590, 1, this=True, skip=(0,), copy=(0, 4))


def g_ct(c):
    world(c)
    return [rnd(c, 0xd0)]


def g_save(c):
    world(c)
    sg = obj(c, 0x80, {k: stub(c, 1, this=True) for k in (0x44, 0x60, 0x64, 0x54)})
    return [rnd(c, 0xd0), sg]


def g_load(c):
    world(c)
    lg = obj(c, 0x80, {0x48: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))]),
                       0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(8), 1)]),
                       0x40: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))] if c.rng.random() < 0.8 else ()),
                       0x58: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))])})
    return [rnd(c, 0xd0), lg]


S(0x5ba2e0, 'ZFFCareTaker_C01A::Init', 'thiscall', ret=None, gen=g_ct)
S(0x5ba220, 'ZFFCareTaker_C01A::Init2', 'thiscall', ret=None, gen=g_ct)
S(0x5ba790, 'ZFFCareTaker_C01A::Save', 'thiscall', ret='al', gen=g_save)
S(0x5ba4e0, 'ZFFCareTaker_C01A::Load', 'thiscall', ret='al', gen=g_load)


def g_cmd(c):
    from mkit import logger
    import struct
    logger(c)
    ct = rnd(c, 0xd0)
    for off, v in ((0x72, 0x101), (0x7c, 0x102), (0x7e, 0x103)):
        c.emu.w16(ct + off, v)
    hero = rnd(c, 0xa00)
    hp = c.rng.choice([100.0, 50.0, 100.0, float('nan')])
    c.emu.w32(hero + 0x7ff, struct.unpack('<I', struct.pack('<f', hp))[0])
    c.emu.w32(hero + 0x7fb, struct.unpack('<I', struct.pack('<f', 100.0))[0])
    c.emu.w32(hero + 0x852, rnd(c, 16))
    c.emu.w32(ct + 0x58, hero)
    c.emu.w8(ct + 0x63, c.rng.choice([0, 1]))
    g = obj(c, 16, {0x84: stub(c, 1, this=True, skip=(0,), outs=[(0, 0x41200000, 4, 0), (0, 0x3f800000, 4, 4), (0, 0, 4, 8)])})
    actor = obj(c, 16, {0x3a0: stub(c, 2, this=True, skip=(0, 1), ret=c.rng.getrandbits(32)), 0x390: stub(c, 1, this=True),
                        0x20: stub(c, 0, this=True, ret=g)})
    c.emu.w32(ct + 0x4c, actor)
    c.emu.w32(ct + 0x44, obj(c, 16, {0x130: stub(c, 3, this=True)}))
    rec = c.emu.alloc(16, 4)

    def adjust(e, r):
        esp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.r32(esp + 4))
        e.w32(rec + 8, e.r32(esp + 8))
        e.w32(rec + 12, e.r32(esp + 12))
        e.ret(st0=1.5, argbytes=12)
    c.emu.hook(0x58b9c0, adjust)
    hook_stub(c, 0x596940, 4, this=True, skip=(1,), copy=(1, 12))
    msg = c.rng.choice([0x101, 0x101, 0x101, 0x102, 0x103, 0x55]) | (c.rng.getrandbits(16) << 16)
    return [ct, msg, c.rng.choice([0, 3, 4, 5, 6, 7, 8, 9, 10])]


S(0x5b9d50, 'ZFFCareTaker_C01A::Command', 'thiscall', ret='eax', gen=g_cmd)


def g_read(c):
    world(c)
    c.emu.unhook(0x5ba590)   # world() hooks ReadInput for the Init/Load specs
    mgr = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    vt = c.emu.r32(mgr)
    c.emu.w32(vt + 0x58, stub(c, 1, this=True, rets=[c.rng.getrandbits(32) for _ in range(16)]))
    hook_stub(c, 0x4e5e60, 0, this=True, rets=[c.rng.getrandbits(32) for _ in range(16)])
    return [rnd(c, 0xd0), rnd(c, 8)]


def g_jump(c):
    import struct
    world(c)
    ct = rnd(c, 0xd0)
    hero = rnd(c, 0xa00)
    c.emu.w32(hero, c.emu.r32(obj(c, 0x380, {0x100: stub(c, 1, this=True, ret=rnd(c, 8)),
                                            0x370: stub(c, 2, this=True, skip=(0, 1))})))
    c.emu.w32(hero + 0x85a, c.rng.choice([0, 0x1234]))
    hp = c.rng.choice([100.0, 50.0])
    c.emu.w32(hero + 0x7ff, struct.unpack('<I', struct.pack('<f', hp))[0])
    c.emu.w32(hero + 0x7fb, struct.unpack('<I', struct.pack('<f', 100.0))[0])
    c.emu.w32(ct + 0x58, hero)
    start = obj(c, 16, {0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(0, 0x3f800000), (1, 0x40000000)])})
    pick = lambda: c.rng.choice([start, 0])  # noqa: E731
    for i in range(11):
        grp = obj(c, 0x260, {0x25c: stub(c, 2, this=True, rets=[pick(), pick(), pick()])}) if c.rng.random() < 0.85 else 0
        c.emu.w32(ct + 0x84 + 4 * i, grp)
    c.emu.w32(ct + 0x44, obj(c, 16, {0x130: stub(c, 3, this=True)}))
    rec = c.emu.alloc(16, 4)

    def adjust(e, r):
        esp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.r32(esp + 4))
        e.ret(st0=1.5, argbytes=12)
    c.emu.hook(0x58b9c0, adjust)
    hook_stub(c, 0x5d1440, 0, this=True)
    hook_stub(c, 0x5b9c00, 2, this=True)
    return [ct, c.rng.randrange(0, 11)]


S(0x5ba590, 'ZFFCareTaker_C01A::ReadInput', 'thiscall', ret=None, gen=g_read)
S(0x5ba310, 'ZFFCareTaker_C01A::JumpToAct', 'thiscall', ret=None, gen=g_jump)
