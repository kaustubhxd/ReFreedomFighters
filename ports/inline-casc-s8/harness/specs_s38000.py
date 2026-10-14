"""specs_s38000.py - cascade s8 batch 38000: 0x52e320 (octree cursor move). Tree with 24 nodes (0x16 bytes, all u16 fields < 24) and 24 table entries
(12 bytes: +4 node < 24, +6 link 0..3); 0x5308e0 hooked (writes a random or zero out dword, records args); assert hook set."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NN = 24


def _g52e320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nodes = e.alloc(NN * 0x16, 4)
    e.wbytes(nodes, bytes(r.getrandbits(8) for _ in range(NN * 0x16)))
    # node layout: +4 first child (u16), +6.. 8 child words; rewrite +4 properly
    for i in range(NN):
        e.wbytes(nodes + i * 0x16 + 4, struct.pack('<9H', *[r.randrange(NN) for _ in range(9)]))
    tab = e.alloc(NN * 12, 4)
    for i in range(NN):
        e.wbytes(tab + i * 12, bytes(r.getrandbits(8) for _ in range(4)) + struct.pack('<HH', r.randrange(NN), r.choice([0, 1, 2, 3, 3])) + bytes(r.getrandbits(8) for _ in range(4)))
    tree = rnd(c, 0x100)
    e.w32(tree + 0x54, nodes)
    e.w32(tree + 0x5a, tab)
    e.w32(tree + 0x72, rnd(c, 0x40))
    e.wbytes(tree + 0x2a, struct.pack('<H', r.randrange(1, 9)))

    def side(em, k):
        em.w32(em.arg32(0), r.choice([0, 0, r.getrandbits(32)]))
    hook_rec(c, 0x5308e0, 3, this=True, pop=12, nullflag=(0,), side=side)
    me = rnd(c, 0x40)
    e.w32(me, tree)
    e.wbytes(me + 0x16, struct.pack('<H', r.randrange(NN)))
    if r.random() < 0.5:
        e.wbytes(me + 0x18, struct.pack('<3H', *[r.choice([0, 7, 8, 0xfff8, 0xffff, r.getrandbits(16)]) for _ in range(3)]))

    def dv():
        return r.choice([0, 0, 1, 2, 7, 8, 9, 0x10, 0xffff, 0xfff8, r.randrange(0x40), r.getrandbits(16)])
    d = rnd(c, 8)
    e.wbytes(d, struct.pack('<3H', dv(), dv(), dv()))
    return [me, d]


S(0x52e320, 'GUESS octree cursor move', 'thiscall', None, ret='eax', gen=_g52e320, note='batch38000')
