"""specs_s1211.py - pathfinding batch 1211: line checks."""
from pilot import S
from pfspec import rnd, sf
from specs_s1206 import iterator
from specs_s1209 import geo_octree


def _upd(c):
    o, lv = geo_octree(c)
    it = iterator(c, o)
    c.emu.w32(it + 0x12, c.rng.choice([lv, lv - 1, lv - 2, 0, lv + 1, c.rng.getrandbits(32)]) & 0xffffffff)
    return [it]


S(0x52db40, 'ZPFOctreeIterator_packed::<UpdateLevel> (no GC name)', 'thiscall', None, gen=_upd)


def _rec(c, o, near=None):
    e = c.emu
    r = c.rng
    a = rnd(c, 0x18)
    e.w16(a, r.randrange(40) if r.random() < 0.95 else 0)
    for k, off in enumerate((0x3c, 0x40, 0x44)):
        n = e.r32(o + off)
        v = r.randint(0, n - 1)
        if near is not None and r.random() < 0.7:
            v = max(0, min(n - 1, near[k] + r.randint(-6, 6)))
        e.w16(a + 4 + 2 * k, v)
    return a


def _line(c):
    o, lv = geo_octree(c)
    e = c.emu
    e.w32(o + 0x48, 1)
    a = _rec(c, o)
    b = _rec(c, o, [e.r16(a + 4 + 2 * k) if hasattr(e, 'r16') else e.r32(a + 4 + 2 * k) & 0xffff for k in range(3)])
    return [o, a, b, c.rng.getrandbits(32)]


S(0x52dbb0, 'ZPFOctree_packed::CheckLine(SPFAStarData_packed*...)', 'thiscall', None, ret='eax', gen=_line, n=300)


def _cellline(c):
    o, lv = geo_octree(c)
    e = c.emu
    a = e.alloc(8, 2)
    b = e.alloc(8, 2)
    for k, off in enumerate((0x3c, 0x40, 0x44)):
        n = e.r32(o + off)
        v = c.rng.randint(0, n - 1)
        e.w16(a + 2 * k, v)
        e.w16(b + 2 * k, v if c.rng.random() < 0.3 else max(0, min(n - 1, v + c.rng.randint(-6, 6))))
    return [o, a, b]


S(0x52dfc0, 'ZPFOctree_packed::<cell line check> (no GC name)', 'thiscall', None, ret='al', gen=_cellline, n=300)


def _wpoint(c, o):
    e = c.emu
    p = e.alloc(16, 4)
    for k in range(3):
        mn = e.rf32(o + 6 + 4 * k)
        mx = e.rf32(o + 0x12 + 4 * k)
        v = mn + (mx - mn) * c.rng.random() if c.rng.random() < 0.9 and mx == mx and mn == mn else c.fv(-5000, 5000)
        e.wf32(p + 4 * k, sf(v))
    return p


def _itnear(c):
    o, lv = geo_octree(c)
    it = iterator(c, o)
    return [it, rnd(c, 8), _wpoint(c, o), rnd(c, 4)]


S(0x530bf0, 'ZPFOctreeIterator_packed::<nearest cell of point> (no GC name)', 'thiscall', None, ret='eax',
  gen=_itnear, n=300)


def _wline(c):
    o, lv = geo_octree(c)
    return [o, _wpoint(c, o), _wpoint(c, o), c.rng.getrandbits(32)]


S(0x52e0a0, 'ZPFOctree_packed::CheckLine(float*, float*, bool)', 'thiscall', None, ret='al', gen=_wline, n=300)
