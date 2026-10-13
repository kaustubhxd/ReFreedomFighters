"""specs_s1113.py - collision thread batch 1113: GetDynamicParent, GetRoomList, AttachToRoomsDrawLists.
Fake render side: [[0x70039c]+0x9b]+8 is a draw-list object (slot 0x40 'already in list' answers from a per-case
table, slot 0x38 returns a new head derived from its args, slot 0x4c returns a geom array base, slot 0x5c returns a
room list); [[0x70039c]+0x9b]+0xadc a dynamic-tree pointer; [0x70039c]+0x190f an optional notify object (slot
0x18c). Geoms and bound objects carry random class chains drawn from the ids the function tests."""
import struct
from pilot import S, F
from specs_s1110 import _vt

CLASSES = [[0x200002], [0x4000022], [0x200015], [0x100000], [0x100021], [0x100020], [0x100030, 0x100021],
           [0x200010, 0x100020], [0x800000], [0]]


def _setup(c):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1a00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0x5e00, 4)
    e.w32(sysobj + 0x9b, rm)
    c.vars['has'] = {}

    def has(em, a):
        k = (a[0], a[1])
        v = c.vars['has'].setdefault(k, r.choice([0, 0, 1, 0x100]))
        return v, tuple(a)

    def add(em, a):
        return (a[0] * 7 + a[1] * 3 + 1) & 0xffffffff, tuple(a)
    garr = e.alloc(0x70 * 4, 4)
    c.vars['garr'] = garr
    rooms = []
    for _ in range(4):
        rr = e.alloc(0xc0, 4)
        e.w32(rr + 0xbc, r.getrandbits(32))
        rooms.append(rr)
    c.vars['rooms'] = rooms
    rl = e.alloc(0x20, 4)
    n = r.choice([0, 1, 2, 4])
    for i in range(4):
        e.w32(rl + 4 * i, rooms[i])
    e.w8(rl + 0x1c, n)
    c.vars['rl'] = rl if r.random() < 0.85 else 0
    dl = e.alloc(0x10, 4)
    e.w32(dl, _vt(c, 'dl', {0x40: (2, has), 0x38: (3, add), 0x3c: (3, add), 0x4c: (0, lambda em, a: (garr, ())),
                            0x5c: (1, lambda em, a: (c.vars['rl'], a[0]))}, 0x60 // 4))
    e.w32(rm + 8, dl)
    nt = 0
    if r.random() < 0.7:
        nt = e.alloc(0x10, 4)
        e.w32(nt, _vt(c, 'notify', {0x18c: (1, lambda em, a: (0, a[0]))}, 0x190 // 4))
    e.w32(sysobj + 0x190f, nt)
    return sysobj, rm


def _bound(c, cls):
    e, r = c.emu, c.rng
    b = e.alloc(0xc0, 4)
    e.wbytes(b, bytes(r.getrandbits(8) for _ in range(0xc0)))
    nxt = 0
    for cid in reversed(cls):
        d = e.alloc(0x30, 4)
        e.w32(d + 0xc, nxt)
        e.w32(d + 0x23, cid)
        nxt = d
    e.w32(b + 0xc, nxt)
    rv = {0xd0: r.choice([0, 1, 0x100]), 0x310: r.choice([0, 1, 0x100])}
    e.w32(b, _vt(c, 'bnd', {0xd0: (0, lambda em, a: (rv[0xd0], ())), 0x310: (0, lambda em, a: (rv[0x310], ()))},
                 0x314 // 4))
    e.w32(b + 0x50, 0)
    return b


def _geom(c, depth=0):
    e, r = c.emu, c.rng
    g = e.alloc(0x70, 4)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x70)))
    f = r.getrandbits(32)
    k = r.random()
    if k < 0.75:
        f &= ~0x202c00
    if r.random() < 0.5:
        f &= ~0x40040000
    e.w32(g + 0x3c, f)
    e.w16(g + 0x5c, r.choice([0, 1, 2, 3, 4]))
    e.w32(g + 0x50, 0)
    e.w32(g + 0x60, 0)
    cls = r.choice(CLASSES)
    b = _bound(c, cls) if r.random() < 0.85 else 0
    if b == 0 and depth == 0:
        b = _bound(c, [0x100000])
    e.w32(g + 0x54, b)
    if b and (cls == [0x100000] or 0x100021 in cls) and depth < 2:
        ch = 0
        for _ in range(r.choice([0, 1, 2, 3])):
            cg = _geom(c, depth + 1)
            e.w32(cg + 0x60, ch)
            ch = cg
        e.w32(b + 0x50, ch)
    return g


def _att(c):
    e, r = c.emu, c.rng
    sysobj, rm = _setup(c)
    g = _geom(c)
    # ancestors for the custom-draw search
    p = g
    for _ in range(r.choice([0, 1, 2, 3])):
        a = e.alloc(0x70, 4)
        e.w32(a + 0x50, 0)
        b = _bound(c, r.choice([[0x100021], [0x100030, 0x100021], [0x200002], [0x100020]])) if r.random() < 0.8 else 0
        e.w32(a + 0x54, b)
        e.w32(p + 0x50, a)
        p = a
        if b and r.random() < 0.3:
            e.w32(rm + 0xadc, b)
    # dynamic parent slots in the geom array
    for i in range(4):
        e.wbytes(c.vars['garr'] + 0x70 * i, bytes(e.mu.mem_read(g, 0x70)))
    room = r.choice(c.vars['rooms']) if r.random() < 0.4 else 0
    return [g, room]


def _gdp(c):
    e, r = c.emu, c.rng
    _setup(c)
    g = e.alloc(0x70, 4)
    e.w32(g + 0x3c, r.getrandbits(32))
    e.w16(g + 0x5c, r.choice([0, 1, 2, 0xffff]))
    return [g]


S(0x4dafb0, 'ZBaseGeom::GetDynamicParent', 'thiscall', None, ret='eax', gen=_gdp, note='batch1113')
S(0x4db550, 'ZBaseGeom::GetRoomList', 'thiscall', None, ret='eax', gen=_gdp, note='batch1113')
S(0x4d9d20, 'ZBaseGeom::AttachToRoomsDrawLists', 'thiscall', None, gen=_att, note='batch1113')
S(0x4da770, 'ZBaseGeom::DetachFromRoomsDrawLists', 'thiscall', None, gen=_att, note='batch1113')
