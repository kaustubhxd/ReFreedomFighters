"""specs_s1121.py - collision thread batch 1120/1121: the dynamic box query and its collect chain (0x4ecb40,
0x4edd40, 0x4eddf0, 0x4ec720). The world: the render manager's slot 0x54 maps any key to one of the case's
geoms (key % count), slot 0x178 is 'not busy', slot 0x40 'lighting on'; the dynamic tree's slot 0x314 returns a
random quadtree (batch 1109 builder). Geoms come from the batch 1113 builder (flags, room, class chains)."""
from pilot import S, F
from specs_s1110 import _vt
from specs_s1113 import _geom
from specs_s1109 import _cls


def _world(c, geoms):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1b00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0x5e00, 4)
    e.w32(sysobj + 0x9b, rm)
    e.w32(rm, _vt(c, 'rm', {0x54: (1, lambda em, a: (geoms[a[0] % len(geoms)] if geoms else 0, a[0])),
                           0x178: (0, lambda em, a: (0, ())),
                           0x40: (0, lambda em, a: (1, ()))}, 0x180 // 4))
    return sysobj, rm


def _dyn(c):
    e, r = c.emu, c.rng
    qt, info1, f1, t1 = _cls(c)          # quadtree with random object payloads (keys)
    sysobj, rm = _world(c, c.vars.get('dgeoms', []))
    tree = e.alloc(0x40, 4)
    qtr = 0 if r.random() < 0.1 else qt   # no dynamic quadtree: the query returns 0
    e.w32(tree, _vt(c, 'dyntree', {0x314: (0, lambda em, a: (qtr, ()))}, 0x318 // 4))
    e.w32(rm + 0xadc, tree)
    return qt, rm


def _gen(c):
    e, r = c.emu, c.rng
    n = r.choice([1, 2, 5, 12, 30])
    geoms = [_geom(c, 0) for _ in range(n)]
    c.vars['dgeoms'] = geoms
    c.vars['btype'] = r.choice([0, 1, 2, 0x100])
    _bounds_fix(c, geoms)
    qt, rm = _dyn(c)
    e.w32(rm + 0x200, 0)
    this = e.alloc(0x1b0, 4)
    cap = r.choice([0, 1, 3, 8, 64, 64])
    a = e.alloc(4 * cap + 0x40, 4)
    b = a + 4 * cap
    mat = e.alloc(0x24, 4)
    for i in range(9):
        e.wf32(mat + 4 * i, r.uniform(-1, 1))
    # the box is drawn in quantised tree space and mapped back to world units, so queries hit the tree's objects
    sc = e.rf32(qt + 0x1d)
    org = [e.rf32(qt + 0x21 + 4 * i) for i in range(3)]
    centre = e.alloc(0x10, 4)
    half = e.alloc(0x10, 4)
    for i in range(3):
        cq = r.uniform(0x3000, 0xd000)
        hq = r.uniform(100, 0x6000) if r.random() < 0.8 else r.uniform(1, 40)
        w = (cq - 32768.0) / sc if sc else 0.0
        e.wf32(centre + 4 * i, org[i] + w)
        e.wf32(half + 4 * i, hq / sc if sc else 1.0)
    return [this, a, b, r.choice([0, 1, 2, 0x100]), mat, centre, half, r.getrandbits(32) | r.choice([0, 0x1, 0xff]),
            r.getrandbits(8) & 1]


S(0x4ecb40, 'ZCollisionBase::GetDynamicGeomsInBox', 'thiscall', None, ret='eax', gen=_gen, note='batch1121')


def _list_(c):
    e, r = c.emu, c.rng
    lst = e.alloc(0x40, 4)
    n = r.choice([0, 1, 3, 8])
    entries = [e.alloc(0x10, 4) for _ in range(n)]
    for i, p in enumerate(entries):
        e.w32(lst + 4 * i, p)
    e.w8(lst + 0x1c, n)
    k = r.random()
    if k < 0.4 and entries:
        room = r.choice(entries)                 # a listed room
    else:
        room = e.alloc(0x10, 4)                  # a room that is not listed
        if k > 0.7:                              # ...but sits just past the count (a scan one too far finds it)
            e.w32(lst + 4 * n, room)
    return [lst, room]


def _info_(c, geoms):
    e, r = c.emu, c.rng
    info = e.alloc(0x1078, 4)
    e.wbytes(info, bytes(r.getrandbits(8) for _ in range(0x1078)))
    e.w32(info + 0x68, r.getrandbits(32) | r.choice([0, 0x1, 0x3, 0xff00]))
    e.w32(info + 0x6c, r.choice([0, 1, 2, 0x100]))
    cap = r.choice([0, 1, 3, 16])
    arr = e.alloc(4 * cap + 0x40, 4)
    e.w32(info + 0x5c, arr)
    e.w32(info + 0x60, arr + 4 * cap)
    e.w32(info + 0x64, r.choice([0, 0, 1, 2]) if cap else 0)
    e.w32(info + 0x70, 0)
    e.w32(info + 0x1074, r.choice([0, 0, 5, 0x3ff, 0x400]))
    return info


def _bounds_fix(c, geoms):
    """every bound object answers slot 0x38 (tree type) with the case's type, the way GetBoundTreeType reads it"""
    e = c.emu
    seen = set()
    def walk(g):
        if not g or g in seen:
            return
        seen.add(g)
        b = e.r32(g + 0x54)
        if b:
            e.w32(b, _vt(c, 'bnd38', {0x38: (0, lambda em, a: (c.vars['btype'], ()))}, 0x40 // 4))
            ch = e.r32(b + 0x50)
            while ch:
                walk(ch)
                ch = e.r32(ch + 0x60)
    for g in geoms:
        walk(g)


def _draw(c, geoms, room):
    """draw-list object at [rm]+8: slot 0x5c returns a room list holding `room` or not (GetRoomList)"""
    e, r = c.emu, c.rng
    lst = e.alloc(0x40, 4)
    members = [room] if r.random() < 0.7 else []
    members += [e.alloc(0x10, 4) for _ in range(r.choice([0, 1, 2]))]
    for i, p in enumerate(members):
        e.w32(lst + 4 * i, p)
    e.w8(lst + 0x1c, len(members))
    dl = e.alloc(0x10, 4)
    e.w32(dl, _vt(c, 'drawlists', {0x5c: (1, lambda em, a: (lst, ())), 0x4c: (0, lambda em, a: (0, ()))}, 0x60 // 4))
    rm = e.r32(e.r32(0x70039c) + 0x9b)
    e.w32(rm + 8, dl)


def _logger(c):
    """the logger global 0x700390 (used when the info record's count reaches 0x400): slot 0x20 (thiscall, two args) opens a
    stream; slot 0x2c of the stream is cdecl (the caller pops two). Both record constants only."""
    e = c.emu

    def rec(em, rr):
        em.calllog.append(('log2c', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)

    def opn(em, rr):
        em.calllog.append(('log20', em.arg32(0), em.arg32(1)))
        em.ret(eax=stream, argbytes=8)

    svt = e.fake_vtable('stream_4edd40', 0x30, {0x2c: rec})
    stream = e.alloc(0x40, 4)
    e.w32(stream, svt)
    lvt = e.fake_vtable('logger_4edd40', 0x30, {0x20: opn})
    logger = e.alloc(0x40, 4)
    e.w32(logger, lvt)
    e.w32(0x700390, logger)


def _mc(c):
    """dynCollect: object key, info record, and the render world"""
    e, r = c.emu, c.rng
    _logger(c)
    geoms = [_geom(c, 0) for _ in range(r.choice([1, 3, 6]))]
    c.vars['dgeoms'] = geoms
    c.vars['btype'] = r.choice([0, 1, 2, 0x100])
    _bounds_fix(c, geoms)
    sysobj, rm = _world(c, geoms)
    room = e.alloc(0x10, 4)
    _draw(c, geoms, room)
    info = _info_(c, geoms)
    e.w32(info + 0x70, room if r.random() < 0.5 else 0)
    if r.random() < 0.5:
        e.w32(info + 0x6c, c.vars['btype'])
    obj = e.alloc(0x10, 4)
    e.w32(obj, r.getrandbits(32))
    return [obj, info]


def _mf(c):
    e, r = c.emu, c.rng
    geoms = [_geom(c, 0) for _ in range(r.choice([1, 2, 4]))]
    c.vars['btype'] = r.choice([0, 1, 2, 0x100])
    _bounds_fix(c, geoms)
    info = _info_(c, geoms)
    g0 = r.choice(geoms)
    fl = e.r32(g0 + 0x3c)
    k = r.random()
    if k < 0.3:   # mask inside the geom's flags
        e.w32(info + 0x68, fl & r.getrandbits(32) or fl & 1)
    elif k < 0.6:   # mask outside the geom's flags
        e.w32(info + 0x68, (~fl) & r.getrandbits(32) or 0x80000000)
    if r.random() < 0.5:
        e.w32(info + 0x6c, c.vars['btype'])
    return [info, g0]


def _ll(c):
    return _list_(c)


S(0x4ec720, 'room list contains (guessed)', 'thiscall', None, ret='al', gen=_ll, note='batch1120')
S(0x4eddf0, 'MatchGeom (guessed)', 'fastcall', None, ret='al', gen=_mf, note='batch1120')
S(0x4edd40, 'dyn collect callback (guessed)', 'fastcall', None, ret='al', gen=_mc, note='batch1120')
