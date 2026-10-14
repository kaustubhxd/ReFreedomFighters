"""specs_s1206.py - pathfinding batch 1206: octree iterator (element / node moves, element bits)."""
from pilot import S
from pfspec import rnd

NN = 40     # component nodes
NA = 40     # area records
NL = 12     # leaf blocks


SOLID = [False]   # set by specs that need every cell to resolve (no 0 child ids)


def octree(c):
    """A random packed octree: every index stays inside its table (with a small chance of a wild one)."""
    r = c.rng
    e = c.emu
    o = rnd(c, 0xd20)   # full ZPFOctree_packed size (0xd1e)
    wild = r.random() < 0.05
    comp = rnd(c, NN * 0x16 + 0x20)
    for k in range(NN):
        e.w16(comp + k * 0x16 + 4, r.randrange(NN))
        for j in range(8):
            e.w16(comp + k * 0x16 + 6 + 2 * j, r.randrange(1 if SOLID[0] else 0, NA if r.random() < 0.5 else NN))
    area = rnd(c, NA * 12 + 0x20)
    for k in range(NA):
        e.w16(area + k * 12 + 4, r.randrange(NN))
        e.w16(area + k * 12 + 6, 0 if r.random() < 0.15 else r.randrange(1, NL))
    bpe = r.choice([1, 1, 2, 3])
    dw = r.choice([2 * bpe, 2 * bpe + 1])
    bits = rnd(c, (NL + 1) * dw * 4 + 0x40)
    e.w32(o + 0x48, bpe)
    e.w16(o + 0x2a, dw)
    e.w32(o + 0x72, bits)
    e.w32(o + 0x54, comp)
    e.w32(o + 0x5a, area)
    e.w32(o + 0x38, r.randint(2, 7))
    if wild and not SOLID[0]:
        e.w16(comp + r.randrange(NN) * 0x16 + 6 + 2 * r.randrange(8), r.getrandbits(16))
    return o


def iterator(c, o):
    r = c.rng
    e = c.emu
    it = rnd(c, 0x30)
    e.w32(it, o)
    e.w32(it + 0x12, r.randint(0, 6))
    e.w16(it + 0x16, r.randrange(NA))
    for k in range(3):
        e.w16(it + 0x18 + 2 * k, r.randint(0, 200) if r.random() < 0.9 else r.getrandbits(16))
        e.w32(it + 0x21 + 4 * k, r.choice([1, 2, 4, 8, 16]) if r.random() < 0.9 else r.getrandbits(32))
    e.w8(it + 0x20, r.choice([1, 2, 1, 2, 0, 3]))
    return it


def delta(c):
    r = c.rng
    d = c.emu.alloc(8, 2)
    for k in range(3):
        c.emu.w16(d + 2 * k, r.choice([0, 0, 1, -1, 2, -2, 8, -8]) & 0xffff if r.random() < 0.9 else r.getrandbits(16))
    return d


def _bits(c):
    o = octree(c)
    out = rnd(c, 4)
    return [o, out, c.emu.r32(o + 0x72) + 4 * c.rng.randrange(8), c.rng.randrange(64)]


S(0x5308e0, 'ZPFOctree_packed::<element bits> (no GC name)', 'thiscall', None, gen=_bits)


def _emove(c):
    o = octree(c)
    return [iterator(c, o), delta(c)]


S(0x52e320, 'ZPFOctreeIterator_packed::ElementMove', 'thiscall', None, ret='ax', gen=_emove)
S(0x531070, 'ZPFOctreeIterator_packed::NodeMove', 'thiscall', None, ret='ax', gen=_emove)
