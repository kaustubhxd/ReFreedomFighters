"""specs_m1426.py - batch 1426: ZFFCareTaker_C08C Init and Command (bomb director)."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub, logger  # noqa: E402


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def positioned(c):
    base = c.rng.uniform(-900, 900)
    v = [fb(base + c.rng.uniform(-700, 700)) for _ in range(3)]
    item = obj(c, 0x90, {0x2f0: stub(c, 3, this=True), 0x210: stub(c, 1, this=True)})
    return obj(c, 0x90, {0x80: stub(c, 2, this=True, skip=(0, 1), outs=[(1, v[0], 4, 0), (1, v[1], 4, 4), (1, v[2], 4, 8)]),
                         0x20: stub(c, 0, this=True, ret=item)})


def list_obj(c, n):
    """Embedded REFTAB: slot 0x4c starts, slot 0x5c gives the next handle and sets the iterator."""
    state = {'k': 0}

    def start(e, r):
        e.w32(e.r32(e.reg('esp') + 4), 1 if n else 0)
        state['k'] = 0
        e.ret(eax=0, argbytes=4)

    def nxt(e, r):
        it = e.r32(e.reg('esp') + 4)
        k = state['k']
        state['k'] = k + 1
        e.w32(it, 1 if k + 1 < n else 0)
        e.ret(eax=0x100 + k, argbytes=4)
    return start, nxt


def g_init(c):
    ct = rnd(c, 0x80)
    c.emu.w32(ct + 0x44, obj(c, 0x30, {0x4c: 0}))   # sender object: vtable with 0x4c
    sender = c.emu.r32(ct + 0x44)
    reg = obj(c, 0x90, {0x60: stub(c, 2, this=True)})
    mgr = rnd(c, 0xb00)
    mvt = obj(c, 0x140, {0x138: stub(c, 0, this=True, ret=reg), 0x58: stub(c, 1, this=True, ret=0),
                         0x4c: stub(c, 2, this=True, ret=0x66)})
    c.emu.w32(mgr, c.emu.r32(mvt))
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    gp = c.emu.r32(c.emu.r32(ct + 0x44))
    c.emu.w32(gp + 0x4c, stub(c, 2, this=True, skip=(0,), ret=0x55))
    hook_stub(c, 0x4e6330, 1, this=True, skip=(0,), rets=[0])
    group = rnd(c, 16)
    db = rnd(c, 16)
    return [ct, group, db]


def g_cmd(c):
    n = c.rng.choice([0, 1, 2, 3])
    start, nxt = list_obj(c, n)
    items = c.rng.choice([[], [0x31], [0x31, 0x32], [0x31, 0x32, 0x33]])
    ct = rnd(c, 0x80)
    # the embedded list at +0x4c is an object whose vtable is 0x4c/0x5c
    vt = c.emu.alloc(0x80, 4)
    c.emu.w32(vt + 0x4c, c.emu.stub_fn('reftab start', start))
    c.emu.w32(vt + 0x5c, c.emu.stub_fn('reftab next', nxt))
    c.emu.w32(ct + 0x4c, vt)
    c.emu.w32(ct + 0x44, obj(c, 0x30, {0x12c: stub(c, 2, this=True)}))
    objs = [positioned(c) for _ in range(n + 1)]
    bomb = positioned(c)
    rets = []
    for k in range(n + 1):
        rets += [objs[k], bomb]
    mgr = rnd(c, 0xb00)
    mvt = obj(c, 0x140, {0x114: stub(c, 4, this=True, rets=[0x3a, 0x3b, 0x3c, 0x3d]),
                         0x58: stub(c, 1, this=True, rets=rets or [bomb]),
                         0x138: stub(c, 0, this=True, ret=0)})
    c.emu.w32(mgr, c.emu.r32(mvt))
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    c.emu.w32(ct + 0x48, positioned(c))
    logger(c, nargs=3)
    hook_stub(c, 0x4e6330, 1, this=True, skip=(0,))
    msg = c.rng.choice([0x3a, 0x3a, 0x3b]) | (c.rng.getrandbits(16) << 16)
    data = rnd(c, 16)
    c.emu.w32(data + 4, c.rng.choice([0x21, 0x22]))
    return [ct, msg, data]


S(0x5bd070, 'ZFFCareTaker_C08C::Init', 'thiscall', ret=None, gen=g_init)
S(0x5bd0d0, 'ZFFCareTaker_C08C::Command', 'thiscall', ret='eax', gen=g_cmd)
