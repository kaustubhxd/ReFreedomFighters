"""specs_s213169.py - batch 213169: cursor effect updater (floor thunk on doubles, random strength via CRT rand, x87 random age), Sonnet-w3b."""
import math
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g47ce80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def floor_st0(emu, k):
        x = struct.unpack('<d', struct.pack('<II', emu.arg32(0), emu.arg32(1)))[0]
        if x != x or abs(x) > 1e6:
            return 0.0
        return float(math.floor(x))
    hook_rec(c, 0x634dca, 2, pop=0, st0=floor_st0)
    hook_rec(c, 0x633910, 0, pop=0, ret=lambda emu, k: r.getrandbits(15))
    hook_rec(c, 0x466f60, 1, pop=4, this=True, ret=lambda emu, k: (rb() | 1) if r.random() < 0.7 else 0)

    # engine objects
    def mat9(emu, ptr):
        emu.wbytes(ptr, struct.pack('<9f', *[f32(r.choice([0.0, 1.0, r.uniform(-1, 1)])) for _ in range(9)]))

    def s80(emu, k):
        mat9(emu, emu.arg32(0))
        emu.calllog.append(('s80', bytes(emu.rbytes(emu.arg32(0), 36)), bytes(emu.rbytes(emu.arg32(1), 12))))
    O = obj(c, 0x40, {0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80)}, nslots=0x100)
    node_ok = r.random() < 0.85

    def node_for(emu, k):
        emu.calllog.append(('t60', emu.arg32(0)))
        if not node_ok:
            return 0
        nd = rnd(c, 0x100)
        w32u(nd + 0x60, r.randint(-5, 5))
        w32u(nd + 0x64, r.randint(-5, 5))
        wf(nd + 0x88, r.uniform(0, 100))
        return nd
    nodes = {}

    def t60(emu, k):
        key = emu.arg32(0)
        emu.calllog.append(('t60', key))
        if not node_ok:
            return 0
        if key not in nodes:
            nd = rnd(c, 0x100)
            w32u(nd + 0x60, r.randint(-5, 5))
            w32u(nd + 0x64, r.randint(-5, 5))
            wf(nd + 0x88, r.uniform(0, 100))
            nodes[key] = nd
        return nodes[key]
    blk = rnd(c, 0x100)
    objA = rnd(c, 0x20)
    w32u(objA, 0x10)
    esi_blk = rnd(c, 0x100)
    span = r.choice([1, 2, 4])
    lo = r.randint(0, 3)
    w32u(esi_blk + 0x60, lo)
    w32u(esi_blk + 0x64, lo + span - 1)
    T = obj(c, 0x80, {0x58: pystub(c, 1, this=True, ret=O), 0x60: pystub(c, 1, this=True, ret=t60)}, nslots=0x40)
    w32u(T + 0x44, esi_blk - 0x10)
    TT = obj(c, 0x20, {0x60: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x40)
    eng = obj(c, 0x2000, {0x1c0: pystub(c, 2, this=True, st0=lambda emu, k: f32(r.choice([0.0, 0.5, 1.0, r.uniform(0, 3)])))}, nslots=0x1d0)
    w32u(eng + 0x9b, T)
    w32u(eng + 0x1a9f, TT if r.random() < 0.9 else 0)
    e.w32(0x70039c, eng)

    edge = r.random() < 0.25

    def s94(emu, k):
        v = struct.pack('<3f', *[f32(0.0 if edge else r.choice([0.0, 1.0, r.uniform(-30, 30)])) for _ in range(3)])
        emu.wbytes(emu.arg32(1), v)
        emu.calllog.append(('s94', bytes(emu.rbytes(emu.arg32(0), 36)), v))
    this = obj(c, 0x900, {0x94: pystub(c, 2, this=True, stackmark=(0, 1), side=s94),
                          0x5a8: pystub(c, 1, this=True, ret=objA if r.random() < 0.93 else 0),
                          0x5b0: pystub(c, 0, this=True, ret=lambda emu, k: r.choice([0, 1, 2, 2, 3])),
                          0x3f8: pystub(c, 1, this=True, ret=lambda emu, k: (rb() | 1) if r.random() < 0.7 else 0)}, nslots=0x200)
    w32u(this + 0x492, rb() | 1 if r.random() < 0.9 else 0)
    w32u(this + 8, blk)
    for off in range(0x24, 0x30, 4):
        wf(blk + off, r.choice([0.0, 1.0, r.uniform(-20, 20), r.uniform(-1000, 1000)]))
    if edge:
        e.wbytes(blk + 0x24, struct.pack('<3f', *r.choice([(2000.0, 0.0, 0.0), (0.0, -2000.0, 0.0), (0.0, 0.0, 2000.0), (1999.0, 0.0, 0.0)])))
    w32u(this + 0x64c, 3 if r.random() < 0.9 else 2)
    w32u(this + 0x650, rb())
    vals = [0.0, 0.5, 1.0, 2.0, 3.0, 6.0, 7.0, 10.0, 14.0, 20.0, 21.0, 28.0, 4.0, 5.0]
    wf(this + 0x755, r.choice(vals + [r.uniform(0, 12)]))
    wf(this + 0x77b, r.choice(vals + [r.uniform(0, 30)]))
    w32u(this + 0x777, rb() >> r.choice([0, 8, 16]))
    e.wbytes(this + 0x157, bytes([r.choice([0, 1, 1])]))
    w32u(this + 0x5c2, rb() if r.random() < 0.85 else 0)
    return [this]


S(0x47ce80, 'cursor_effect', 'thiscall', None, ret=None, gen=g47ce80)
