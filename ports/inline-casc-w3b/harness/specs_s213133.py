"""specs_s213133.py - batch 213133: effect update (matrix from template, two state machines through a message printf and a distance test), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g521f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    rdf = lambda a: struct.unpack('<f', bytes(e.rbytes(a, 4)))[0]
    K1, K2 = rdf(0x67da04), rdf(0x6a0674)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def fv():
        return f32(r.choice([0.0, 1.0, -1.0, 0.5, r.uniform(-9, 9)]))

    def fill(emu, addr, nfl):
        emu.wbytes(addr, struct.pack('<%df' % nfl, *[fv() for _ in range(nfl)]))
    # engine / table
    Qo = rnd(c, 0x80)
    w32u(Qo + 0x3c, (rb() & ~0x1000) | (0x1000 if r.random() < 0.5 else 0))
    Ro = rnd(c, 0x20)
    e.w32(Ro + 8, Qo)
    T = obj(c, 0x40, {0x58: pystub(c, 1, this=True, ret=Ro)}, nslots=0x60)
    P = obj(c, 0x40, {0x184: pystub(c, 5, this=True, pop=0)}, nslots=0x100)
    E = obj(c, 0x100, {0x190: pystub(c, 0, this=True, ret=P)}, nslots=0x80)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    O2 = obj(c, 0x40, {0x30: pystub(c, 2, this=True, pop=0)}, nslots=0x40)
    L = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=O2)}, nslots=0x40)
    e.w32(0x700390, L)
    A = rnd(c, 0x40)
    for off in (8, 0xc, 0x10, 0x24, 0x28):
        e.wbytes(A + off, struct.pack('<f', fv()))
    this = obj(c, 0x400, {0x370: pystub(c, 0, this=True),
                          0x7c: pystub(c, 2, this=True, stackmark=(0, 1),
                                       side=lambda emu, k: (lg(emu, 'm7c', emu.arg32(0), 36), lg(emu, 'o7c', emu.arg32(1), 12)))}, nslots=0x200)
    e.w32(this + 0x5c, A)
    w32u(this + 0x123, 0 if r.random() < 0.1 else rb() | 1)
    e.wbytes(this + 0x2d8, struct.pack('<3f', fv(), fv(), fv()))
    e.wbytes(this + 0x2f0, struct.pack('<f', fv()))
    state = r.choice([1, 1, 3, 3, 2, 0, 5])
    w32u(this + 0x2f4, state)
    e.wbytes(this + 0x2f8, struct.pack('<f', fv()))
    e.wbytes(this + 0x2fc, bytes([r.choice([0, 1, 0x80])]))
    w32u(this + 0x216, rb())
    e.wbytes(this + 0x60, struct.pack('<3f', fv(), fv(), fv()))
    e.wbytes(this + 0x6c, bytes(r.getrandbits(8) for _ in range(36)))
    e.wbytes(this + 0x90, bytes(r.getrandbits(8) for _ in range(12)))
    e.wbytes(this + 0x9c, bytes(r.getrandbits(8) for _ in range(36)))

    def mat9():
        return struct.pack('<9f', *[fv() for _ in range(9)])

    def s527(emu, k):
        lg(emu, 'l527', emu.arg32(2), 12)
        emu.wbytes(emu.arg32(0), mat9())
        emu.wbytes(emu.arg32(1), struct.pack('<3f', fv(), fv(), fv()))
    hook_rec(c, 0x527d10, 7, pop=28, this=True, stackmark=(0, 1, 2), side=s527)

    def sde(emu, k):
        lg(emu, 'de_dir', emu.reg('edx'), 12)
        emu.wbytes(emu.reg('ecx'), mat9())
    hook_rec(c, 0x4de040, 1, pop=4, this='mark', side=sde)

    def s520(emu, k):
        lg(emu, 'v60', emu.arg32(1), 12)
        lg(emu, 'm6c', emu.arg32(0), 36)
        lg(emu, 'min', emu.arg32(2), 36)
        lg(emu, 'oin', emu.arg32(3), 12)
        emu.wbytes(emu.arg32(2), mat9())
        emu.wbytes(emu.arg32(3), struct.pack('<3f', fv(), fv(), fv()))
    hook_rec(c, 0x520450, 4, pop=16, this=True, stackmark=(2, 3), side=s520)
    hook_rec(c, 0x5233a0, 2, pop=8, this=True, stackmark=(0,), side=lambda emu, k: fill(emu, emu.arg32(0), 3))

    def s4e30(emu, k):
        lg(emu, 'e30', emu.reg('edx'), 12)
    thr = r.choice([K1, K1, K2, K2])
    vals = [thr * 0.5, thr, thr * 2.0 if thr else 1.0, 0.0, -1.0, f32(thr * 0.999), f32(thr * 1.001), thr - 1.0, thr + 1.0]
    hook_rec(c, 0x4e0030, 0, pop=0, this=True, side=s4e30, st0=lambda emu, k: f32(r.choice(vals)))
    hook_rec(c, 0x515930, 2, pop=8, this=True)
    hook_rec(c, 0x521930, 0, pop=0, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x521f90, 'effect_update', 'thiscall', None, ret=None, gen=g521f90)
