"""specs_s1112.py - collision thread batch 1112: 0x4eb410 ZCollisionBase::CalcColiLort.
Geoms: identity or random local frames (parent chains), boxes around the origin so the segment often hits;
bound objects with class descriptor chains (group 0x100000 with children, 0x200006 primitive caster, others);
this's slot 0x54 (the recursion) and the casters are logging stubs (values behind pointer args)."""
import struct
from pilot import S, F
from specs_s1110 import _world, _vt


def _fv(em, p):
    return bytes(em.mu.mem_read(p, 12)).hex()


def _bound(c, cls_chain, nslots=0x280 // 4):
    e, r = c.emu, c.rng
    b = e.alloc(0x70, 4)
    nxt = 0
    for cid in reversed(cls_chain):
        d = e.alloc(0x30, 4)
        e.w32(d + 0xc, nxt)
        e.w32(d + 0x23, cid)
        nxt = d
    e.w32(b + 0xc, nxt)
    e.w32(b, _vt(c, 'bnd', {0x27c: (3, lambda em, a: (c.vars['r27c'], (a[0], _fv(em, a[1]), _fv(em, a[2])))),
                            0x38: (0, lambda em, a: (c.vars['btype'], ()))}, nslots))
    return b


def _geom(c, type_):
    e, r = c.emu, c.rng
    g = e.alloc(0x80, 4)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x80)))
    for i in range(9):
        e.wf32(g + 4 * i, [1, 0, 0, 0, 1, 0, 0, 0, 1][i] if r.random() < 0.6 else r.uniform(-1, 1))
    for i in range(3):
        e.wf32(g + 0x24 + 4 * i, r.uniform(-5, 5))
        e.wf32(g + 0x30 + 4 * i, r.uniform(-5, 5))
        e.wf32(g + 0x40 + 4 * i, r.uniform(0.5, 20))
    e.w32(g + 0x50, 0)
    if r.random() < 0.3:
        par = e.alloc(0x80, 4)
        for i in range(9):
            e.wf32(par + 4 * i, r.uniform(-1, 1))
        for i in range(3):
            e.wf32(par + 0x24 + 4 * i, r.uniform(-5, 5))
        e.w32(g + 0x50, par)
    c.vars['btype'] = type_ if r.random() < 0.8 else type_ ^ 1
    return g, None


def _ccl(c):
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    c.vars['r27c'] = r.choice([0, r.getrandbits(32)])
    c.vars['hit'] = r.choice([0, 1, 0x100])
    o1c = e.alloc(0x10, 4)
    e.w32(o1c, _vt(c, 'caster', {0x64: (6, lambda em, a: (c.vars['hit'], (a[0], a[1], _fv(em, a[2]), _fv(em, a[3]), a[4], a[5])))}, 0x68 // 4))
    e.w32(X + 0x1c, o1c)
    this = e.alloc(0x20, 4)
    c.vars['rec'] = r.choice([0, 1, 0x100])
    e.w32(this, _vt(c, 'cbase', {0x54: (7, lambda em, a: (c.vars['rec'], tuple(a)))}, 0x58 // 4))
    type_ = r.getrandbits(32)
    g, tree = _geom(c, type_)
    k = r.random()
    if k < 0.25:
        b = _bound(c, [0x100000 | r.getrandbits(8)])
        ch = 0
        for _ in range(r.choice([0, 1, 3])):
            cg = e.alloc(0x70, 4)
            f = r.getrandbits(32)
            if r.random() < 0.5:
                f &= ~0xc00
            if r.random() < 0.2:
                f &= ~0xff
            e.w32(cg + 0x3c, f)
            e.w32(cg + 0x60, ch)
            ch = cg
        e.w32(b + 0x50, ch)
    elif k < 0.55:
        b = _bound(c, r.choice([[0x200006], [0x200010, 0x200006], [0x300000, 0x200011, 0x200006]]))
    elif k < 0.8:
        b = _bound(c, [r.choice([0x200002, 0x200004, 0x2])])
    else:
        b = 0
    e.w32(g + 0x54, b)
    mask = r.getrandbits(32)
    if r.random() < 0.3:
        e.w32(g + 0x3c, e.r32(g + 0x3c) & ~mask)
    imp = e.alloc(0x60, 4)
    e.wbytes(imp, bytes(r.getrandbits(8) for _ in range(0x60)))
    e.wf32(imp, r.choice([1.0, 1.0, 0.5, 0.05, 2.0, 0.0, 0.0]))
    f = e.alloc(0x10, 4)
    v = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(f + 4 * j, r.uniform(-30, 30))
        e.wf32(v + 4 * j, r.uniform(-60, 60))
    return [this, imp, g, type_, f, v, mask, r.getrandbits(32)]


S(0x4eb410, 'ZCollisionBase::CalcColiLort', 'thiscall', None, ret='al', gen=_ccl, note='batch1112')


def _cdl(c):
    from specs_s1109 import _cls
    e, r = c.emu, c.rng
    qt, _info, f, t = _cls(c)          # a real quadtree (CheckLinesegment and its walk run as exe code)
    sysobj, rm, X = _world(c)          # after _cls: the render manager maps object keys to geoms
    mask = r.getrandbits(32) | 1
    keys = list(c.vars['cbret'].keys())
    for pay in keys:
        key = r.getrandbits(32)
        e.w32(pay, key)
        if r.random() < 0.85:
            g = e.alloc(0x70, 4)
            fl = r.getrandbits(32)
            k = r.random()
            if k < 0.5:
                fl = (fl | 1) & ~0xc00
            elif k < 0.8:   # shares no bit with the mask: the collect callback drops it
                fl = fl & ~mask & ~0xc00
            e.w32(g + 0x3c, fl)
            cls = r.choice([[0x200006], [0x200010, 0x200006], [0x200002], None])
            if cls:
                b = _bound(c, cls, 0x250 // 4)
                srcobj = 0
                if r.random() < 0.7:
                    srcobj = e.alloc(0x10, 4)

                    def fill(em, a):
                        for i in range(9):
                            em.wf32(a[0] + 4 * i, c.vars['M'][i])
                        for i in range(3):
                            em.wf32(a[1] + 4 * i, c.vars['P'][i])
                        return 0, (a[2], a[3])
                    e.w32(srcobj, _vt(c, 'src', {0xc: (4, fill)}, 0x10 // 4))
                e.w32(b, _vt(c, 'bnd2', {0x24c: (0, lambda em, a, s=srcobj: (s, ()))}, 0x250 // 4))
                e.w32(g + 0x54, b)
            c.vars['geoms'][key] = g
    c.vars['M'] = [r.uniform(-1, 1) for _ in range(9)]
    c.vars['P'] = [r.uniform(-20, 20) for _ in range(3)]
    imp = e.alloc(0x60, 4)
    e.wbytes(imp, bytes(r.getrandbits(8) for _ in range(0x60)))
    for i in range(3):
        e.wf32(imp + 4 + 4 * i, r.uniform(-20, 20))
    if r.random() < 0.2:
        e.w32(imp + 0x3c, 0)
    gs = list(c.vars['geoms'].values())
    e.w32(imp + 0x10, r.choice(gs) if gs else e.alloc(0x70, 4))
    c.vars['lort'] = {}

    def lort(em, a):
        return c.vars['lort'].setdefault(a[1], r.choice([0, 0, 1, 0x100])), tuple(a)
    this = e.alloc(0x21c0, 4)
    e.w32(this, _vt(c, 'cbase', {0x54: (7, lambda em, a: (c.vars['lortv'].get(a[1], 0), tuple(a)))}, 0x58 // 4))
    c.vars['lortv'] = {g: r.choice([0, 0, 1, 0x100]) for g in c.vars['geoms'].values()}
    tree = e.alloc(0x20, 4)
    x8 = e.alloc(0x40, 4)
    e.w32(x8 + 0x3c, r.getrandbits(32) & (0xfffffbff if r.random() < 0.85 else 0xffffffff))
    e.w32(tree + 8, x8)
    c.vars['qt'] = qt if r.random() < 0.9 else 0
    e.w32(tree, _vt(c, 'tree', {0x314: (0, lambda em, a: (c.vars['qt'], ()))}, 0x318 // 4))
    v = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(v + 4 * j, e.rf32(t + 4 * j) - e.rf32(f + 4 * j))
    return [this, imp, tree, r.getrandbits(32), f, v, r.getrandbits(32), mask]


S(0x4eb680, 'ZCollisionBase::CalcDynamicLineCollision', 'thiscall', None, ret='al', gen=_cdl, note='batch1112')
