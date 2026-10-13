"""specs_m1425.py - batch 1425: ZFFCareTaker_C05A::Command (TatarinDead)."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402


def listobj(c, items):
    """An object with a +0x18 list: slot 0x4c(&it) starts, slot 0x5c(&it) gives the next item and sets it."""
    state = {'k': 0}

    def start(e, r):
        it = e.r32(e.reg('esp') + 4)
        e.w32(it, 1 if items else 0)
        state['k'] = 0
        e.ret(eax=0, argbytes=4)

    def nxt(e, r):
        it = e.r32(e.reg('esp') + 4)
        k = state['k']
        state['k'] = k + 1
        e.w32(it, 1 if k + 1 < len(items) else 0)
        e.ret(eax=items[k] if k < len(items) else 0, argbytes=4)
    o = obj(c, 0x40, {0x4c: 0, 0x5c: 0})   # vtable large enough for slot 0x5c
    vt = c.emu.r32(o)
    c.emu.w32(vt + 0x4c, c.emu.stub_fn('list start', start))
    c.emu.w32(vt + 0x5c, c.emu.stub_fn('list next', nxt))
    return o


def g_cmd(c):
    hero = obj(c, 0x900, {})
    c.emu.w32(hero + 0x852, rnd(c, 16))
    tat = obj(c, 0x90, {0x84: stub(c, 1, this=True, skip=(0,), outs=[(0, 0x41000000, 4, 0), (0, 0x41400000, 4, 4), (0, 0x41800000, 4, 8)])})
    a_list = obj(c, 0x20, {0xc: stub(c, 0, this=True), 4: stub(c, 1, this=True)})
    b_list = listobj(c, [c.rng.getrandbits(32) for _ in range(c.rng.choice([0, 1, 3]))])
    a = obj(c, 0x40, {0x18: 0})
    b = obj(c, 0x40, {0x18: 0})
    c.emu.w32(a + 0x18, a_list)
    c.emu.w32(b + 0x18, b_list)
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 0x11)])})
    rc = obj(c, 0x20, {0: stub(c, 2, this=True, skip=(0, 1), ret=cstr(c, 'Tatarin dead'))})
    mgr = rnd(c, 0xb00)
    mvt = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg),
                         0x58: stub(c, 1, this=True, rets=[hero, a, b, tat] * 2)})
    c.emu.w32(mgr, c.emu.r32(mvt))
    c.emu.w32(mgr + 0xae4, rc)
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x40, c.rng.getrandbits(24))
    c.emu.w32(0x70039c, sysi)
    gd = rnd(c, 0x2c40)
    c.emu.w32(gd + 0x2c2d, rnd(c, 16))
    c.emu.w32(0x7003b8, gd)
    logger(c, nargs=2)
    hook_stub(c, 0x596940, 4, this=True, skip=(1,), copy=(1, 12))
    hook_stub(c, 0x589c20, 1, this=True, ret=rnd(c, 16))
    hook_stub(c, 0x59a580, 3, this=True)
    ct = rnd(c, 0x80)
    c.emu.w8(ct + 0x5c, c.rng.choice([0, 0, 1]))
    c.emu.w16(ct + 0x54, 0x101)
    c.emu.w16(ct + 0x58, 0x102)
    c.emu.w32(ct + 0x48, c.rng.choice([0x21, 0x21]))
    c.emu.w32(ct + 0x4c, 0x22)
    c.emu.w32(ct + 0x63, 0x23)
    c.emu.w32(ct + 0x6b, 0x24)
    c.emu.w32(ct + 0x44, obj(c, 0x30, {0x12c: stub(c, 3, this=True)}))
    msg = c.rng.choice([0x101, 0x101, 0x102]) | (c.rng.getrandbits(16) << 16)
    return [ct, msg, 0]


S(0x5bcc10, 'ZFFCareTaker_C05A::Command', 'thiscall', ret='eax', gen=g_cmd)
