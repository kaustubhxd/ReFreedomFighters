"""specs_s1124.py - collision thread batch 1124: octree box walk 0x4e3380. Trees and item callbacks are the batch 1123
builder; the query box is drawn around the root cube (so the walk takes all three branches: item callbacks, whole-subtree
collect through 0x4e3ce0, and partial recursion), at random depth and centre."""
from pilot import S, F
from specs_s1123 import _tree


def _walk(c):
    e, r = c.emu, c.rng
    base, info = _tree(c)
    depth = r.choice([0, 0, 1, 2, 3])
    size = 0x10000 >> (depth + 1)
    cx = r.randint(0, 0x10000)
    cy = r.randint(0, 0x10000)
    cz = r.randint(0, 0x10000)
    q = size >> 1
    for k, c0 in zip((0x14, 0x18, 0x1c), (cx, cy, cz)):
        lo = c0 - size + r.randint(-size, size // 2)
        hi = c0 + size + r.randint(-size // 2, size)
        if r.random() < 0.4:   # query edge exactly on a child cube edge (child centre c0 +- q, half-size size)
            lo = c0 + q + size if r.random() < 0.5 else c0 - q - size
        if r.random() < 0.3:
            hi = c0 - q - size if r.random() < 0.5 else c0 + q + size
        if hi <= lo:
            hi = lo + 1
        e.w32(info + k, lo & 0xffffffff)
        e.w32(info + k + 0xc, hi & 0xffffffff)
    return [base, info, depth, cx, cy, cz]


S(0x4e3380, 'octree cube walk (GUESS CheckCube walk)', 'thiscall', None, gen=_walk, note='batch1124')
