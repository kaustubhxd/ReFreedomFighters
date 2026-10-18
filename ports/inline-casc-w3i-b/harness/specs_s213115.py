"""specs_s213115.py - batch 213115: view/aim accumulator with mode switch, helper object chain and clamps, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g4a8a60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, -0.0, 0.5, -0.5, 0.25, 0.75, -0.75, 1.0, -1.0, 2.0, r.uniform(-1, 1), r.uniform(-3, 3)]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x130)
    e.w32(this + 0x4a, 0 if r.random() < 0.1 else r.getrandbits(32) | 1)
    e.w32(this + 0x56, 0 if r.random() < 0.1 else r.getrandbits(32) | 1)
    e.w32(this + 0x75, r.choice([0, 1, 2, 3, 0xffffffff, 1, 2, 0]))
    for off in (0x7d, 0x81, 0x85, 0x8b, 0x8f, 0x93):
        e.wbytes(this + off, struct.pack('<f', fv()))
    e.w32(this + 0xbf, r.getrandbits(32))
    e.wbytes(this + 0xc7, struct.pack('<H', r.getrandbits(16)))
    # chain: P (4a8d20 result) -> slot 0x128 fills id; table slot 0x58(id) -> X; X slots
    Z = obj(c, 0x20, {0x2d0: pystub(c, 0, this=True, ret=lambda emu, k: r.getrandbits(32))}, nslots=0x400)
    Y = obj(c, 0x20, {0x2e8: pystub(c, 0, this=True, ret=lambda emu, k: Z if r.random() < 0.7 else 0)}, nslots=0x400)
    X = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (0 if r.random() < 0.3 else 1)),
                      0x504: pystub(c, 0, this=True, ret=lambda emu, k: Y if r.random() < 0.7 else 0)}, nslots=0x400)

    def s128(emu, k):
        emu.w32(emu.arg32(1), r.choice([0, 0, r.getrandbits(32) | 1]))
    P = obj(c, 0x20, {0x128: pystub(c, 3, this=True, nullflag=(1,), side=s128)}, nslots=0x60)
    hook_rec(c, 0x4a8d20, 0, pop=0, this=True, ret=lambda emu, k: P if r.random() < 0.8 else 0)
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lambda emu, k: X if r.random() < 0.85 else 0)}, nslots=0x60)
    hook_rec(c, 0x4a9330, 1, pop=4, this=True)
    hook_rec(c, 0x4a93b0, 0, pop=0, this=True)
    # engine: slot 0xbc -> Q (slots 0xa8 x87, 0xb8 al), floats at +0x9e7..
    Q = obj(c, 0x20, {0xa8: pystub(c, 0, this=True, st0=lambda emu, k: f32(r.choice([0.0, 1.0, 0.5, -1.0, r.uniform(-5, 5), NAN]))),
                      0xb8: pystub(c, 0, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (0 if r.random() < 0.4 else r.choice([1, 2, 0x80])))}, nslots=0x60)
    eng = obj(c, 0xa00, {0xbc: pystub(c, 0, this=True, ret=Q)}, nslots=0x60)
    e.w32(eng + 0x9b, T)
    for off in (0x9e7, 0x9eb, 0x9ef):
        e.wbytes(eng + off, struct.pack('<f', fv()))
    e.w32(0x70039c, eng)

    def s3e920(emu, k):
        lg(emu, 'b3e920', emu.reg('edx'), 12)
        lg(emu, 'c3e920', emu.arg32(0), 12)
        m = r.random()
        if m < 0.25:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 0.0, -0.0, 0.0))
        elif m < 0.3:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', NAN, 0.0, 0.0))
        elif m < 0.4:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 0.0, 0.0, fv()))
        elif m < 0.5:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 0.0, fv(), 0.0))
        else:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x43e920, 1, pop=4, this='mark', side=s3e920)

    def sd00(emu, k):
        lg(emu, 'cd00', emu.reg('ecx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x4e0d00, 1, pop=4, this='mark', side=sd00)

    def s1940(emu, k):
        lg(emu, 'a1940', emu.reg('ecx'), 12)
        lg(emu, 'b1940', emu.reg('edx'), 12)
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x441940, 0, pop=0, this=True, side=s1940)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x4a8a60, 'view_accumulate', 'thiscall', None, ret=None, gen=g4a8a60)
