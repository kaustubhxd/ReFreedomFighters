"""specs_s213114.py - batch 213114: bounded record list with a bounding box accumulated over parts, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g5bef80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, -2.0, 3.0, r.uniform(-5, 5)]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x940)
    cnt = r.choice([0, 1, 2, 5, 28, 29, 0x1d, 0x1e, 0x1e, 0x1f, 0x20, 0x7f])
    if cnt == 0x7f:
        cnt = 3
    e.w32(this + 0x90c, cnt)
    # parts: a0->[0x18] object with slots 0x14 (count byte) and 0x30 (index -> id)
    ncnt = r.choice([0, 1, 2, 3, 4, 5, 127, 0x80, 0xff, 0x81, r.getrandbits(8)])
    if ncnt == 127:
        ncnt = r.choice([2, 3, 6])   # keep the part loop short
    def s14(emu, k):
        return (r.getrandbits(32) & ~0xff) | ncnt
    def s30(emu, k):
        return r.randrange(0, 4)
    Oq = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=s14), 0x30: pystub(c, 1, this=True, ret=s30)}, nslots=0x20)
    a0 = rnd(c, 0x40)
    e.w32(a0 + 0x18, Oq)
    # table slot 0x58 -> X objects with slot 0x84

    def s84(emu, k):
        # values chosen near each other so the min/max compare branches are all exercised
        v = [r.choice([0.0, 0.0, -0.0, -0.0, 1.0, -1.0, 2.0, -2.0, 0.5, fv()]) for _ in range(3)]
        emu.wbytes(emu.arg32(0), struct.pack('<fff', *[f32(x) for x in v]))
    X = [obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=s84)}, nslots=0x60) for _ in range(2)]
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lambda emu, k: r.choice(X))}, nslots=0x60)
    eng = obj(c, 0x100, {}, nslots=4)
    e.w32(eng + 0x9b, T)
    e.w32(eng + 0x40, r.choice([0, 1000, r.getrandbits(31), 0xffffff00]))
    e.w32(0x70039c, eng)
    # log manager
    def h2c(emu, rr):
        emu.calllog.append(('log', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))
        emu.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('log2c', h2c)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=M)}, nslots=0x20)
    e.w32(0x700390, Lg)

    def s1940(emu, k):
        lg(emu, 'a1940', emu.reg('ecx'), 12)
        lg(emu, 'b1940', emu.reg('edx'), 12)
        if r.random() < 0.6:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x441940, 0, pop=0, this=True, side=s1940)

    def sd00(emu, k):
        lg(emu, 'cd00', emu.reg('ecx'), 12)
    hook_rec(c, 0x4e0d00, 1, pop=4, this=True, side=sd00)

    def s220(emu, k):
        lg(emu, 'rec220', emu.arg32(0), 0x3a)
    hook_rec(c, 0x5be220, 1, pop=4, this=True, side=s220)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    args = [this, a0, r.getrandbits(32), F(fv()), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return args


S(0x5bef80, 'record_bounds_add', 'thiscall', None, ret=None, gen=g5bef80)
