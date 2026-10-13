"""specs_m1416.py - batch 1416: ZFFCareTaker_C02A Init2, Save, Load, byte-array save helpers."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def arr(c, base):
    n = c.rng.choice([0, 1, 5, 10])
    c.emu.w32(base, n)


def g_save_arr(c):
    sg = obj(c, 0x80, {0x3c: stub(c, 1, this=True), 0x60: stub(c, 1, this=True)})
    a = rnd(c, 0x40)
    arr(c, a)
    return [sg, a]


def g_load_arr(c):
    n = c.rng.choice([0, 1, 4, -1])
    lg = obj(c, 0x80, {0x48: stub(c, 1, this=True, skip=(0,), outs=[(0, n)]),
                       0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(8), 1)])})
    a = rnd(c, 0x40)
    arr(c, a)
    return [lg, a]


def g_save(c):
    sg = obj(c, 0x80, {0x3c: stub(c, 1, this=True), 0x60: stub(c, 1, this=True)})
    ct = rnd(c, 0x390)
    arr(c, ct + 0x2b8)
    return [ct, sg]


def g_load(c):
    lg = obj(c, 0x80, {0x48: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.choice([0, 2]))]),
                       0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(8), 1)])})
    ct = rnd(c, 0x390)
    arr(c, ct + 0x2b8)
    return [ct, lg]


def g_init2(c):
    ct = rnd(c, 0x390)
    for off in (0x70, 0x74, 0x80):
        c.emu.w32(ct + off, c.rng.choice([0, 7]))
    n = c.rng.choice([0, 1, 3])
    objs = []
    for _ in range(n):
        vals = [fb(c.rng.uniform(-100, 100)) for _ in range(12)]
        objs.append(obj(c, 0x90, {0x80: stub(c, 2, this=True, skip=(0, 1),
                                            outs=[(0, vals[i], 4, 4 * i) for i in range(9)] + [(1, vals[9 + i], 4, 4 * i) for i in range(3)]),
                                  0x28: stub(c, 0, this=True), 0x2c: stub(c, 0, this=True),
                                  0x7c: stub(c, 2, this=True, skip=(0, 1), copy=(1, 12, None)),
                                  0x370: stub(c, 2, this=True, skip=(0, 1), copy=(0, 36, None)),
                                  0x5dc: stub(c, 2, this=True, skip=(0, 1), copy=(0, 12, None))}))
    state = {'k': 0}

    def nxt(e, r):
        k = state['k']
        state['k'] = k + 1
        it = e.r32(e.reg('esp') + 4)
        e.w32(it, 1 if k < n else 0)
        e.ret(eax=100 + k, argbytes=4)
    lvt = c.emu.alloc(0x60, 4)
    c.emu.w32(lvt + 0x4c, stub(c, 1, this=True, skip=(0,), outs=[(0, 1)]))
    c.emu.w32(lvt + 0x5c, c.emu.stub_fn('list next', nxt))
    c.emu.w32(ct + 0x1e8, lvt)
    other = obj(c, 0x380, {0x28: stub(c, 0, this=True), 0x2c: stub(c, 0, this=True),
                           0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(0, 0x3f800000), (1, 0x40000000, 4, 4)]),
                           0x7c: stub(c, 2, this=True, skip=(0, 1), copy=(1, 12, None)),
                           0x370: stub(c, 2, this=True, skip=(0, 1)), 0x5dc: stub(c, 2, this=True, skip=(0, 1))})
    # the hero first; then the list objects (C02B path) and the actor/switch objects. With the flag unset the list
    # is not walked, so the later lookups land on list objects: they get every slot too.
    seq = [rnd(c, 0x10)] + objs + [other] * 8
    reg = obj(c, 0x70, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 5)]), 0x60: stub(c, 2, this=True)})
    mgr = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x58: stub(c, 1, this=True, rets=seq[:16]),
                         0x4c: stub(c, 2, this=True, ret=0x77)})
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    gd = rnd(c, 0x2c40)
    c.emu.w32(0x7003b8, gd)
    hook_stub(c, 0x59b310, 1, this=True, ret=c.rng.choice([0, 1]))
    lid = obj(c, 0x90, {0x84: stub(c, 1, this=True, skip=(0,), outs=[(0, fb(3.0)), (0, fb(-2.0), 4, 8)])})
    hook_stub(c, 0x59b3c0, 0, this=True, ret=lid)
    return [ct]


S(0x5ba850, 'C02A save byte array', 'fastcall', ret='eax', gen=g_save_arr)
S(0x5ba800, 'C02A load byte array', 'fastcall', ret='eax', gen=g_load_arr)
S(0x5bbb60, 'ZFFCareTaker_C02A::Save', 'thiscall', ret='al', gen=g_save)
S(0x5bb8c0, 'ZFFCareTaker_C02A::Load', 'thiscall', ret='al', gen=g_load)
S(0x5bb520, 'ZFFCareTaker_C02A::Init2', 'thiscall', ret=None, gen=g_init2)
