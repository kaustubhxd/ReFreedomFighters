"""specs_s1125.py - collision thread batch 1125: ZOctreeCompiled::CheckCube. A compiled block (dword 0 = item offset,
records from +0x14) and an octree object (origin, scale, block pointer). The walk (0x4e3380) runs as exe code; its
item callbacks log their item index. The box a..b is drawn in world units around the origin so it covers the tree."""
import random, struct
from pilot import S, F
from specs_s1123 import _tree


def _cube(c):
    e, r = c.emu, c.rng
    oct_ = e.alloc(0x20, 4)
    org = [r.uniform(-500, 500) for _ in range(3)]
    sc = r.choice([1.0, 0.5, 2.0, r.uniform(0.2, 4.0)])
    for k in range(3):
        e.wf32(oct_ + 4 + 4 * k, org[k])
    e.wf32(oct_ + 0x10, sc)
    # block: records and items from the batch-1123 builder, copied into one block at +0x14 and at the item offset
    base, info_tmp = _tree(c)
    block = e.alloc(0x4000, 16)
    # the 1123 builder laid out its own record array (base) and item array (info_tmp+0x10): copy both into the block
    items_src = e.r32(info_tmp + 0x10)
    nbytes_items = 16 * 64
    recs = bytes(e.mu.mem_read(base, 6 * 64))
    items_off = 0x14 + len(recs)
    items_off = (items_off + 15) & ~15
    e.w32(block, items_off)
    e.wbytes(block + 0x14, recs)
    e.wbytes(block + items_off, bytes(e.mu.mem_read(items_src, nbytes_items)))
    e.w32(oct_ + 0x14, block)
    info = e.alloc(0x40, 4)
    e.w32(info + 4, e.r32(info_tmp + 4))
    # query box in world units: centre around origin, wide enough to reach the tree
    a = e.alloc(0x10, 4)
    b = e.alloc(0x10, 4)
    for k in range(3):
        lo = org[k] + r.uniform(-0.5, 0.5) * 65536 / sc
        hi = lo + r.uniform(0.1, 1.2) * 65536 / sc
        e.wf32(a + 4 * k, lo)
        e.wf32(b + 4 * k, hi)
    return [oct_, info, a, b]


S(0x4e3520, 'ZOctreeCompiled::CheckCube', 'thiscall', None, gen=_cube, note='batch1125')
