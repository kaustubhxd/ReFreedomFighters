"""specs_s1110.py - collision thread batch 1110: 0x4ed370 handle resolve, the octree line-cast callbacks
CalcGeomLineCallBack (0x4eb8a0) and CalcRoomLineCallBack (0x4ebed0), and CheckLineColi (0x4ec6c0).
Engine objects are fake: the render manager ([0x70039c]+0x9b) maps a key to a geom through slot 0x54; the room
directory ([[0x70039c]+0x1aa3]+0x18, slot 0xc) returns a room record; the primitive octree's slot 0x18 and the
fallback caster's slot 0x5c log the values behind their pointer args (the pointers themselves are into the
caller's frame) and return a per-case al. Bound objects log slots 0x378 / 0x37c / 0x340."""
import struct
from pilot import S, F

HB = 0x20000000


def _vals(e, ptr, n=3):
    return tuple(round(e.rf32(ptr + 4 * i), 6) if not (ptr >= 0x0fe00000 and ptr < 0x0ff00000) else None for i in range(n))


def _fv(e, ptr):
    return tuple(struct.unpack('<3I', bytes(e.mu.mem_read(ptr, 12))))


def _vt(c, name, slots, nslots):
    e = c.emu
    hs = {}
    for off, (nargs, fn) in slots.items():
        def h(em, rr, off=off, nargs=nargs, fn=fn):
            args = [em.arg32(k) for k in range(nargs)]
            eax, logged = fn(em, args)
            em.calllog.append((name, off, em.reg('ecx'), logged))
            em.ret(eax=eax, argbytes=4 * nargs)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def _geom(c, e, r, flags_mask):
    g = e.alloc(0x80, 4)
    for i in range(9):
        e.wf32(g + 4 * i, [1, 0, 0, 0, 1, 0, 0, 0, 1][i] if r.random() < 0.5 else r.uniform(-1, 1))
    for i in range(3):
        e.wf32(g + 0x24 + 4 * i, r.uniform(-10, 10))
    if r.random() < 0.5:
        par = e.alloc(0x80, 4)
        for i in range(9):
            e.wf32(par + 4 * i, r.uniform(-1, 1))
        for i in range(3):
            e.wf32(par + 0x24 + 4 * i, r.uniform(-10, 10))
        e.w32(g + 0x50, par)
    f = r.getrandbits(32)
    k = r.random()
    if k < 0.6:
        f &= ~0xc00
    if r.random() < 0.7:
        f |= flags_mask
    e.w32(g + 0x3c, f)
    return g


def _world(c):
    """Fake engine: returns (sysobj, rm, X)."""
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1b00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0xb00, 4)
    e.w32(sysobj + 0x9b, rm)
    octb = e.alloc(0x100, 16)
    e.w32(rm + 0xaec, octb)
    c.vars['octb'] = octb
    X = e.alloc(0x40, 4)
    e.w32(sysobj + 0x1aa3, X)
    c.vars['geoms'] = {}
    e.w32(rm, _vt(c, 'rm', {0x54: (1, lambda em, a: (c.vars['geoms'].get(a[0], 0), a[0]))}, 0x58 // 4))
    return sysobj, rm, X


def _hitfn(c, name):
    def fn(em, a):
        return c.vars['hit'], (a[0], _fv(em, a[1]), _fv(em, a[2]))
    return fn


def _chk(c):
    e, r = c.emu, c.rng
    chk = e.alloc(0xd0, 4)
    e.wbytes(chk, bytes(r.getrandbits(8) for _ in range(0xd0)))
    for i in range(6):
        e.wf32(chk + 0x5c + 4 * i, r.uniform(-50, 50))
    imp = e.alloc(0x90, 4)
    e.wbytes(imp, bytes(r.getrandbits(8) for _ in range(0x90)))
    rec = e.alloc(0x20, 4)
    e.wbytes(rec, bytes(r.getrandbits(8) for _ in range(0x20)))
    e.w32(imp + 0x5c, rec)
    e.w32(chk + 0x78, imp)
    return chk


def _gcb(c):
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    c.vars['hit'] = r.choice([0, 1, 0x100, 0x2ff])
    chk = _chk(c)
    mask = 1 << r.randrange(32)
    e.w32(chk + 0x74, mask)
    g = _geom(c, e, r, mask)
    key = r.getrandbits(32)
    if r.random() < 0.9:
        c.vars['geoms'][key] = g
    room = e.alloc(0x10, 4) if r.random() < 0.9 else 0
    e.w32(g + 0x6c, room)
    rd = e.alloc(0x40, 4)
    e.w16(rd + 2, 0 if r.random() < 0.85 else r.choice([0x100, 0x8000, r.randint(1, 0xffff)]))
    prim = e.alloc(0x10, 4)
    e.w32(prim, _vt(c, 'prim', {0x18: (3, _hitfn(c, 'prim'))}, 0x1c // 4))
    k = r.random()
    if k < 0.4:
        h = prim
    elif k < 0.6:   # tagged handle into the octree node array
        h = (prim - c.vars['octb']) | 1
    else:
        h = 0
    e.w32(rd + 0x28, h & 0xffffffff)
    if r.random() < 0.6:
        e.w32(g + 0x3c, e.r32(g + 0x3c) | 0x400000)
    o18 = e.alloc(0x10, 4)
    e.w32(o18, _vt(c, 'rooms', {0xc: (1, lambda em, a: (rd, a[0]))}, 0x10 // 4))
    o1c = e.alloc(0x10, 4)

    def cast(em, a):
        return c.vars['hit'], (a[0], a[1], _fv(em, a[2]), _fv(em, a[3]), a[4], a[5])
    e.w32(o1c, _vt(c, 'caster', {0x5c: (6, cast)}, 0x60 // 4))
    e.w32(X + 0x18, o18)
    e.w32(X + 0x1c, o1c)
    obj = e.alloc(0x10, 4)
    e.w32(obj, key)
    return [obj, chk]


def _rcb(c):
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    c.vars['hit'] = r.choice([0, 1, 0x100, 0x2ff])
    chk = _chk(c)
    off = r.choice([0, 0x10, 0x40])
    e.w32(chk + 0x7c, off)
    base = e.alloc(0x100, 4)
    key = r.getrandbits(32)
    e.w32(base + off + 0x4c, key)
    obj = e.alloc(0x10, 4)
    e.w32(obj, base)
    e.w32(chk + 0xc0, r.choice([0, 3, 15, 0x10, 0x11, r.randint(0, 0x30)]))
    e.w8(chk + 0xc4, r.choice([0, 0, 1]))
    olds = []
    for i in range(16):
        ob = e.alloc(0x10, 4)
        e.w32(ob, _vt(c, 'old%d' % i, {0x378: (2, lambda em, a: (0, tuple(a)))}, 0x37c // 4))
        e.w32(chk + 0x80 + 4 * i, ob)
    g = _geom(c, e, r, 0)
    if r.random() < 0.9:
        c.vars['geoms'][key] = g
    prim = e.alloc(0x10, 4)
    e.w32(prim, _vt(c, 'prim', {0x18: (3, _hitfn(c, 'prim'))}, 0x1c // 4))
    c.vars['b37c'] = r.choice([0, 0, 2, 1, 0x101])
    c.vars['prim'] = prim if r.random() < 0.85 else 0
    b = e.alloc(0x10, 4)
    e.w32(b, _vt(c, 'bound', {0x37c: (0, lambda em, a: (c.vars['b37c'], ())),
                             0x378: (2, lambda em, a: (0, tuple(a))),
                             0x340: (1, lambda em, a: (c.vars['prim'], a[0]))}, 0x380 // 4))
    e.w32(g + 0x54, b)
    return [obj, chk]


def _rh(c):
    e, r = c.emu, c.rng
    _world(c)
    return [r.getrandbits(32)]


def _clc(c):
    e, r = c.emu, c.rng
    this = e.alloc(0x20, 4)
    e.w32(this, _vt(c, 'cb', {0x30: (8, lambda em, a: (c.vars['ret'], tuple(a)))}, 0x34 // 4))
    c.vars['ret'] = r.getrandbits(32)
    return [this] + [r.getrandbits(32) for _ in range(8)]


S(0x4ed370, 'resolve node handle (guessed)', 'fastcall', None, ret='eax', gen=_rh, note='batch1110')
S(0x4eb8a0, 'CalcGeomLineCallBack', 'fastcall', None, ret='al', gen=_gcb, note='batch1110')
S(0x4ebed0, 'CalcRoomLineCallBack', 'fastcall', None, ret='al', gen=_rcb, note='batch1110')
S(0x4ec6c0, 'ZCollisionBase::CheckLineColi', 'thiscall', None, ret='al', gen=_clc, note='batch1110')
