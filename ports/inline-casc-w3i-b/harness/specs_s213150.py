"""specs_s213150.py - batch 213150: list of items configured by kind (jump table, x87 float returns, bit loops), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    try:
        return struct.unpack('<f', struct.pack('<f', v))[0]
    except OverflowError:
        return float('inf')


def g57b6d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    tab = struct.unpack('<4f', bytes(e.rbytes(0x6aa1cc, 16)))
    eps = struct.unpack('<f', bytes(e.rbytes(0x679540, 4)))[0]

    def fval(kind):
        if kind == 'loop':
            t = r.choice(tab)
            b = f32(t + eps)
            ch = [b, b, 0.0, 0.5, 0.8, 1.0, 1.2, 5.0, -1.0, float('nan'), struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', b))[0] + 1))[0],
                  struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', b))[0] - 1))[0]]
        elif kind == 'scale':
            ch = [0.0, 0.5, 1.0, 0.3, 2.5, 100.0, -0.7, 1e9, float('nan'), 0.01, 0.015, 1.99999]
        else:
            ch = [0.0, 0.5, 1.25, 2.0, 3.0, 7.0, 1e-3, -1.0, 1e30, float('nan'), 0.3, 1.5]
        return r.choice(ch)

    def x58(emu, k):
        name = emu.arg32(0)
        if name == 0x6922d4:
            return fval('loop')
        if name == 0x683724:
            return fval('scale')
        return fval('inv')

    def x58log(emu, k):
        emu.calllog.append(('x58', emu.arg32(0), emu.arg32(1)))
    X = obj(c, 0x20, {0x58: pystub(c, 2, this=True, st0=x58, side=x58log),
                      0x5c: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x40)
    flags = r.choice([0, 0x10, 2, 8, 4, 0x1e, 0xff, 0x12, 0x0a, 6])
    mask = r.choice([0, 0xffffffff, 0x6, 0xa, rb(), 0x80000000, 0x40000000, 2, 4, 0x1c])

    def y1cc(emu, k):
        emu.wbytes(emu.arg32(0), bytes([flags]) + b'\0\0\0' + struct.pack('<I', mask))

    def y1d4(emu, k):
        n = emu.arg32(0)
        emu.calllog.append(('y1d4', n))
        v = r.choice([0, 1, 2, 3, 5, 31, 32, 33, 0xffffffff]) if n == 2 else r.choice([0, 1, 0xffffffff, rb(), 3])
        emu.wbytes(emu.arg32(1), struct.pack('<I', v))
    Y = obj(c, 0x20, {0x1cc: pystub(c, 1, this=True, stackmark=(0,), side=y1cc),
                      0x1d4: pystub(c, 2, this=True, stackmark=(1,), side=y1d4)}, nslots=0x80)
    T = obj(c, 0x20, {0x4c: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x20)
    E = obj(c, 0x2000, {0xbc: pystub(c, 0, this=True, ret=X)}, nslots=0x70)
    for off in (0x93, 0x97, 0x8f):
        w32u(E + off, r.choice([0, 1, 2, 3, 4, rb()]))
    e.wbytes(E + 0x68, bytes([r.getrandbits(8)]))
    w32u(E + 0x9b, T)
    w32u(E + 0x190f, Y)
    e.w32(0x70039c, E)
    nodes = []
    for i in range(r.choice([0, 1, 2, 3, 4, 6])):
        kd = r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 7, 10, 11, 12, 0, 13, 20])
        item = obj(c, 0x40, {0x310: pystub(c, 0, this=True, ret=kd),
                             0x36c: pystub(c, 2, this=True), 0x360: pystub(c, 2, this=True),
                             0x2d8: pystub(c, 0, this=True), 0x2dc: pystub(c, 0, this=True),
                             0x378: pystub(c, 1, this=True), 0x368: pystub(c, 0, this=True, ret=lambda emu, k: rb())}, nslots=0x1c0)
        node = rnd(c, 0x80)
        w32u(node + 0x54, item)
        nodes.append(node)
    st = {'i': 1}

    def nxt(emu, k):
        i = st['i']
        st['i'] += 1
        emu.w32(emu.arg32(0), nodes[i] if i < len(nodes) else 0)
    L = obj(c, 0x20, {0x50: pystub(c, 1, this=True, stackmark=(0,), side=nxt)}, nslots=0x20)
    w32u(L + 8, nodes[0] if nodes else 0)
    hook_rec(c, 0x4db9a0, 1, pop=4, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.75 else 0))
    this = obj(c, 0x100, {0xb4: pystub(c, 1, this=True)}, nslots=0x30)
    w32u(this + 0x54, L)
    return [this]


S(0x57b6d0, 'item_config', 'thiscall', None, ret=None, gen=g57b6d0)
