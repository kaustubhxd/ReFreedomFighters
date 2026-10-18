"""specs_s213138.py - batch 213138: timed-effect record setup (flag word, rates, fmod import, per-entry add loop), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

FMOD = bytes.fromhex('d9c9d9f8dfe09e7af9ddd9c3')   # fxch; fprem loop; fstp st1; ret  (_CIfmod)


def g464760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    fm = e.alloc(32, 16)
    e.wbytes(fm, FMOD)
    e.mu.ctl_flush_tb() if hasattr(e.mu, 'ctl_flush_tb') else None
    e.w32(0x676358, fm)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def fv():
        return r.choice([0.0, 0.5, 1.0, 2.0, -1.0, r.uniform(-4, 4), r.uniform(0, 10)])
    eng = rnd(c, 0x100)
    w32u(eng + 0x40, r.choice([0, 1, 50, 1000, 100000, 0xffffff00, rb() & 0xffff]))
    e.w32(0x70039c, eng)
    nent = r.choice([0, 1, 2, 3])
    cnt = [0]

    def s2c(emu, k):
        return rb()
    Q = obj(c, 0x40, {0x24: pystub(c, 1, this=True, ret=nent),
                      0x2c: pystub(c, 2, this=True, ret=lambda emu, k: rb() & 0xffff),
                      0x3c: pystub(c, 1, this=True, ret=lambda emu, k: (rb() & ~0xff) | (rb() & 0xff))}, nslots=0x20)
    self_ = obj(c, 0x200, {0x268: pystub(c, 2, this=True),
                           0x2b4: pystub(c, 1, this=True, ret=lambda emu, k: r.choice([0xffffffff, 0, 1, 7])),
                           0x350: pystub(c, 4, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.6 else 0))}, nslots=0x180)
    w32u(self_ + 0x5c, Q)
    w32u(self_ + 0x122, rb())
    # template chain Z -> W -> V
    V = rnd(c, 0x80)
    w32u(V + 0x6c, r.choice([1, 5, 100, 1000, 0x10000]))
    W = rnd(c, 0x80)
    w32u(W + 0x14, rb() | 8 if r.random() < 0.7 else rb() & ~8)
    w32u(W + 0x70, V)
    w32u(W + 0xc, r.choice([1, 3, 7, 100, 1000, 0xfffffff0]))
    wf(W + 0x28, r.choice([0.5, 1.0, 2.0, -1.0, 0.25]))
    wf(W + 0x1c, r.choice([0.0, 1.0, 0.5, 2.0, -1.0]))
    Zo = rnd(c, 0x40)
    w32u(Zo + 0x14, 0 if r.random() < 0.2 else W)
    e.wbytes(Zo + 4, bytes([r.choice([0, 1, 1, 3])]))
    w32u(self_ + 0x1c, Zo)
    # timeline Y and record X
    Y = rnd(c, 0x90)
    w32u(Y + 0x7c, r.choice([0, 1, 2, 8, 0x10, 0x1a, 0xfffffffe, 0x80000001, 0x80000000 | 0x1a, rb()]))
    w32u(Y + 0x5c, r.choice([0, 1, 10, 100]))
    w32u(Y + 0x6c, r.choice([1, 2, 10, 100, 1000]))
    w32u(Y + 0x60, r.choice([0, 5, 100]))
    w32u(Y + 0x64, r.choice([0, 10, 100, 1000, 5]))
    X = rnd(c, 0x80)
    w32u(X + 0x70, Y)
    wf(X + 0x2c, r.choice([0.0, 0.0, 1.0, -0.0, 2.0]))
    wf(X + 0x30, fv())
    wf(X + 0x28, r.choice([0.5, 1.0, 2.0, 0.25, 3.0]))
    kc = struct.unpack('<f', bytes(e.rbytes(0x67af2c, 4)))[0]
    wf(X + 0x34, r.choice([kc, kc, 1.0, 0.5, fv()]))
    w32u(X + 0x44, r.choice([0, 0, 1, 5]))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [self_, X, r.choice([0, 1, 2, 3, 4, 8, 0x10, 0x12, 0x1f, rb() & 0xff, rb()])]


S(0x464760, 'timed_effect_setup', 'thiscall', None, ret='al', gen=g464760)
