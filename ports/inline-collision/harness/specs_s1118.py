"""specs_s1118.py - collision thread batch 1118: GetGeomsInBoxLocal. The tree's slot 0x344 and the box's slots
the tree's 0x344 / 0x98 and the box's 0x7c are logging stubs; the stubs return small per-case counts and write nothing."""
from pilot import S, F
from specs_s1110 import _vt


def _gl(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x100, 4)
    n344 = r.choice([0, 1, 2, 3])
    n7c = r.choice([0, 1, 2])
    tree = e.alloc(0x10, 4)
    # the matrix and vector are frame-local (their addresses differ between runs), so the stubs log values only
    def vals(em, a):
        return tuple(a[:2]) + tuple(a[2:3]) + tuple(a[5:])
    def mv(em, a):
        return (tuple(round(em.rf32(a[0] + 4 * i), 6) for i in range(9)), tuple(round(em.rf32(a[1] + 4 * i), 6) for i in range(3)))
    e.w32(tree, _vt(c, 'tree', {0x344: (8, lambda em, a: (n344, vals(em, a))),
                                0x98: (2, lambda em, a: (0, mv(em, a)))}, 0x348 // 4))
    e.w32(self_, _vt(c, 'cbase', {0x7c: (8, lambda em, a: (n7c, vals(em, a)))}, 0x80 // 4))
    a = e.alloc(0x80, 4)
    b = e.alloc(0x80, 4)
    mat = e.alloc(0x24, 4)
    for i in range(9):
        e.wf32(mat + 4 * i, r.uniform(-1, 1))
    vec = e.alloc(0x10, 4)
    for i in range(3):
        e.wf32(vec + 4 * i, r.uniform(-20, 20))
    return [self_, a, b, tree, r.getrandbits(32), mat, vec, r.getrandbits(32),
            r.getrandbits(8) & 1, r.getrandbits(8) & 1, r.getrandbits(8) & 1, r.getrandbits(8) & 1]


S(0x4ed0e0, 'ZCollisionBase::GetGeomsInBoxLocal', 'thiscall', None, ret='eax', gen=_gl, note='batch1118')
