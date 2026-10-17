"""specs_s213165.py - batch 213165: map cell neighbour relink (transliterated frame; probes 0x52e320 / 0x531070 / 0x530a40 and the relink 0x52d250 hooked), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g5320b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    pr = r.choice([0.3, 0.7, 1.0])
    nc = r.choice([3, 5, 8])
    a_forced = [None]

    def probe(tag):
        def side(emu, k):
            emu.calllog.append((tag, bytes(emu.rbytes(emu.reg('ecx'), 0x2d)), bytes(emu.rbytes(emu.arg32(0), 6))))
        return side
    ret = lambda emu, k: (rb() & ~0xffff) | (r.randint(1, 0xffff) if r.random() < pr else 0)
    hook_rec(c, 0x52e320, 1, pop=4, this='mark', stackmark=(0,), side=probe('p3'), ret=ret)
    hook_rec(c, 0x531070, 1, pop=4, this='mark', stackmark=(0,), side=probe('pn'), ret=ret)

    def p530(emu, k):
        emu.calllog.append(('n530', bytes(emu.rbytes(emu.reg('ecx'), 0x2d))))
    hook_rec(c, 0x530a40, 0, pop=0, this='mark', side=p530,
             ret=lambda emu, k: (rb() & ~0xffff) | r.choice([0, 1, 2, 3, 4, nc - 1, nc - 2]))
    hook_rec(c, 0x52d250, 2, pop=8, this=True)

    this = rnd(c, 0x400)
    levels = r.choice([1, 2, 3, 4])
    e.w32(this + 0x38, levels)
    cells = e.alloc(nc * 0x15 + 8, 4)
    ent_n = 4
    # 12 byte [0x5a] items and 0x16 byte [0x54] nodes: u16 at +0 is the record index
    items = e.alloc(ent_n * 12, 4)
    nodes = e.alloc(ent_n * 0x16, 4)
    recs = e.alloc(ent_n * 10 + 4, 4)       # [0x78] 10 byte records: u16 at +8 = start in [0x66]
    cnts = e.alloc(8, 4)
    arr66 = e.alloc(16 * 10, 4)
    arr8c = e.alloc(64, 4)
    for i in range(ent_n):
        e.wbytes(items + i * 12, struct.pack('<H', r.randrange(ent_n)) + bytes(r.getrandbits(8) for _ in range(10)))
        e.wbytes(nodes + i * 0x16, struct.pack('<H', r.randrange(ent_n)) + bytes(r.getrandbits(8) for _ in range(0x14)))
        e.wbytes(recs + i * 10, bytes(r.getrandbits(8) for _ in range(8)) + struct.pack('<H', r.randrange(0, 11)))
    e.wbytes(cnts, bytes(r.choice([0, 1, 1, 2, 3]) for _ in range(8)))
    for i in range(16):
        e.wbytes(arr66 + i * 10, bytes([r.choice([0, 1, 2, 3]), r.choice([0, 1, 1, 2, 3])]) + struct.pack('<HHH', r.randint(0, 3), r.randint(0, 3), r.randint(0, 3))
                 + struct.pack('<h', r.choice([0, 1, -1, 2, -2, 5, -5, r.randint(-8, 8)])))
    e.wbytes(arr8c, bytes(r.getrandbits(8) for _ in range(64)))
    for i in range(nc):
        e.wbytes(cells + i * 0x15, struct.pack('<H', r.randrange(ent_n)) + bytes([r.choice([0, 1, 2, 3]), r.choice([0, 1, 2, 3])])
                 + struct.pack('<HHH', r.randint(0, 40), r.randint(0, 40), r.randint(0, 40))
                 + struct.pack('<f', f32(r.choice([0.0, 1.0, 2.5, r.uniform(-5, 40)]))) + bytes(r.getrandbits(8) for _ in range(7)))
        e.wbytes(cells + i * 0x15 + 3, bytes([r.choice([0, 1, 2, 3])]))
    for k in range(nc):
        e.wbytes(cells + k * 0x15 + 0x14, bytes([r.getrandbits(8)]))
    e.w32(this + 0x98, cells)
    e.w32(this + 0x5a, items)
    e.w32(this + 0x54, nodes)
    e.w32(this + 0x78, recs)
    e.w32(this + 0x7c, cnts)
    e.w32(this + 0x66, arr66)
    e.w32(this + 0x8c, arr8c)
    e.wbytes(this + 4, bytes([r.choice([0, 1, 1])]))
    e.wbytes(0x6e9000, bytes([r.choice([0, 1, 1])]))
    if r.random() < 0.35:
        # exact equality of the neighbour height and the limit: only a cell a with v0 differs, all others hold limit(v0)
        e.wbytes(0x6e9000, bytes([0]))
        one = struct.unpack('<f', bytes(e.rbytes(0x678858, 4)))[0]
        k1 = struct.unpack('<f', bytes(e.rbytes(0x68c730, 4)))[0]
        k2 = struct.unpack('<f', bytes(e.rbytes(0x67a284, 4)))[0]
        v0 = f32(r.choice([0.0, 1.0, 2.5, 7.25]))
        xm = f32(f32(f32(f32(v0 + one) + 0.0) - 0.0) + k1)
        lim = f32(xm + k2)
        a_forced[0] = r.randrange(nc)
        for k in range(nc):
            e.wbytes(cells + k * 0x15 + 0xa, struct.pack('<f', v0 if k == a_forced[0] else lim))
    Sb = e.alloc(0x40, 4)
    sb = bytearray(r.getrandbits(8) for _ in range(0x2d))
    sb[0x20] = r.choice([3, 3, 1, 5])
    e.wbytes(Sb, bytes(sb))
    pos = 0
    if r.random() < 0.7:
        pos = e.alloc(8, 4)
        e.wbytes(pos, struct.pack('<3H', r.randint(0, 40), r.randint(0, 40), r.randint(0, 40)))
    a = r.randrange(nc) if a_forced[0] is None else a_forced[0]
    d = r.choice([levels - 1, levels - 1, levels - 2, 0, 5, levels])
    return [this, a | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0), d & 0xffffffff, Sb, pos]


S(0x5320b0, 'cell_relink', 'thiscall', None, ret='ax', gen=g5320b0, stack_arg_bytes=16)
