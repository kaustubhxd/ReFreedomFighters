"""specs_s213134.py - batch 213134: timeline position update with 64-bit CRT helpers (_allmul / _alldiv / _allrem / _ftol2 / _ltod3), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4a4ba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    o3 = r.choice([1, 2, 2, 3, 5, 0, 7])
    o2 = r.choice([1, 2, 3, 10, 100, 1000, 0x7fffffff, 0x80000000, 0xffffffff])
    o1 = r.choice([0, 1, 5, 100, 1000, 0x7fffffff, 0x80000000, 0xffffffff, rb()])
    ok = r.random() < 0.85
    edge = r.random() < 0.3   # S == X exactly: f = 1.0, clock - m56 = (o3 - 1) * o2 * 1024
    if edge:
        o3 = r.choice([2, 3, 5])
        o2 = r.choice([1, 2, 3, 10])
        o1 = r.choice([0, 1, 5, 100])
        ok = True

    def s_d4(emu, k):
        emu.w32(emu.arg32(1), o1)
        emu.w32(emu.arg32(2), o2)
        emu.w32(emu.arg32(3), o3)
    Hh = obj(c, 0x40, {0xd4: pystub(c, 4, this=True, stackmark=(1, 2, 3), side=s_d4, ret=lambda emu, k: (rb() & ~0xff) | (1 if ok else 0)),
                       0xd8: pystub(c, 2, this=True)}, nslots=0x60)
    mid = obj(c, 0x40, {}, nslots=4)
    w32u(mid + 0x18, Hh)
    E = rnd(c, 0x2000)
    w32u(E + 0x1aa3, mid)
    clk = r.choice([0, 1, 5, 100, 0x7fffffff, 0xffffff00, 1000])
    w32u(E + 0x30, clk)
    w32u(E + 0x40, r.choice([0, 3, 50, 0x80000000, 100000]))
    m56 = r.choice([0, 1, 10, 0xfffffff0, 100, rb() & 0xff])
    if edge:
        clk = (m56 + (o3 - 1) * o2 * 1024) & 0xffffffff
        w32u(E + 0x30, clk)
        w32u(E + 0x40, clk)
    e.w32(0x70039c, E)
    Y = rnd(c, 0x100)
    w32u(Y + 0x6c, rb())
    Wo = obj(c, 0x40, {0x210: pystub(c, 1, this=True)}, nslots=0x90)
    w32u(Wo + 0x4c, r.choice([1, 1, 2, 0]))
    wsel = [Wo]

    def s20(emu, k):
        return wsel[0] if (k == 0 or r.random() < 0.8) else 0
    X = obj(c, 0x40, {0x20: pystub(c, 0, this=True, ret=s20), 0x28: pystub(c, 0, this=True), 0x210: pystub(c, 1, this=True)}, nslots=0x90)
    e.w32(X + 8, Y)
    this = obj(c, 0x100, {0x58: pystub(c, 0, this=True), 0x68: pystub(c, 2, this=True)}, nslots=0x40)
    e.w32(this + 0x44, X)
    e.wbytes(this + 0x4a, struct.pack('<f', f32(r.uniform(-5, 5))))
    w32u(this + 0x56, m56)
    e.wbytes(this + 0x5a, struct.pack('<f', 1.0 if edge else f32(r.choice([0.0, 1.0, 2.0, -1.0, 60.0, 0.5, 100.0, 3.7, -2.5, 1000.0]))))
    for off in (0x60, 0x61, 0x62, 0x63, 0x65):
        e.wbytes(this + off, bytes([1 if r.random() < (0.5 if off != 0x63 else 0.25) else 0]))
    if edge:
        e.wbytes(this + 0x63, bytes([0]))
    hook_rec(c, 0x4690b0, 0, pop=0, this=True)
    return [this]


S(0x4a4ba0, 'timeline_update', 'thiscall', None, ret=None, gen=g4a4ba0)
