"""specs_s213088.py - batch 213088: actor motion state refresh with stack vectors, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g51c560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cap = struct.unpack('<f', bytes(e.rbytes(0x67cd44, 4)))[0]

    def fl():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 100.0, cap, cap + 1, -cap, NAN, r.uniform(-5, 5), r.uniform(-5, 5), r.uniform(0, cap)])

    def vec3():
        return struct.pack('<fff', fl(), fl(), fl())
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def c_side(emu, k):
        if r.random() < 0.7:
            emu.wbytes(emu.arg32(0), vec3())
    Y = obj(c, 0x20, {0x84: sl(1, nullflag=(0,), side=c_side)}, nslots=0x60)
    T = obj(c, 0x20, {0x58: sl(1, Y)}, nslots=0x60)
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    def slot7c(emu, k):
        emu.calllog.append(('d', bytes(emu.rbytes(emu.arg32(1), 12))))

    def slot88(emu, k):
        emu.calllog.append(('c', bytes(emu.rbytes(emu.arg32(0), 12))))
        if r.random() < 0.6:
            emu.wbytes(emu.arg32(0), vec3())
    this = obj(c, 0x420, {0x36c: sl(0), 0x88: sl(1, nullflag=(0,), side=slot88), 0x7c: sl(2, nullflag=(1,), side=slot7c)}, nslots=0x100)
    Z = rnd(c, 0x10)
    zv = obj(c, 0x20, {0x4: sl(2)}, nslots=0x10)
    e.w32(this + 0x34e, e.r32(zv))
    P = rnd(c, 0x20)
    e.wbytes(P + 8, vec3())
    e.w32(this + 0x5c, P)
    e.w32(this + 0x34a, r.choice([0, 0, 0x1234, r.getrandbits(32)]))
    e.wbytes(this + 0x276, vec3())
    e.wbytes(this + 0x60, vec3())

    def f523(emu, k):
        emu.wbytes(emu.arg32(0), vec3() if r.random() < 0.85 else struct.pack('<fff', 0.0, 0.0, 0.0))
    hook_rec(c, 0x523330, 1, this=True, side=f523)

    def f43e920(emu, k):
        emu.calllog.append(('sub', bytes(emu.rbytes(emu.reg('edx'), 12))))
        emu.wbytes(emu.reg('ecx'), vec3() if r.random() < 0.85 else struct.pack('<fff', 0.0, 0.0, 0.0))
    hook_rec(c, 0x43e920, 1, pop=4, side=f43e920)

    def f43e8e0(emu, k):
        emu.calllog.append(('sub2', bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x43e8e0, 1, pop=4, nullflag=(0,), side=f43e8e0)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x51c560, 'actor_motion_refresh', 'thiscall', None, ret=None, gen=g51c560)
