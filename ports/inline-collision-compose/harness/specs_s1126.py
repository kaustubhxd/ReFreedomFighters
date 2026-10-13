"""specs_s1126.py - collision thread batch 1126: ZCollisionBase::GetStripsInsideBox 0x4ed5b0.
World: render manager (octree node base), room directory (+0x1c collision object: slot 0x38 is a stub that writes a
random geom list into a/b and returns its count), rooms (disabled or enabled, handle to an octree, tagged or plain),
octrees (real CheckCube 0x4e3520 at slot 0x1c, batch-1125 blocks), the collision object (strip table at +0x190, slot 0x88
helper stub that logs the values behind its pointer args and advances the end pointer by 0x14).
Frame-local pointers are logged as values only (the stub reads through them)."""
import struct
from pilot import S, F
from specs_s1125 import _cube
from specs_s1110 import _vt


def _vals(em, p, n):
    return tuple(round(em.rf32(p + 4 * i), 6) for i in range(n))


def _gsib(c):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1b00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0xb00, 4)
    e.w32(sysobj + 0x9b, rm)
    octbase = e.alloc(0x100, 16)
    e.w32(rm + 0xaec, octbase)
    ds = e.alloc(0x40, 4)
    e.w32(sysobj + 0x1aa3, ds)
    dirOff = r.choice([0x20, 0x40, 0x60])
    e.w32(ds + 0x20, dirOff)

    # octrees (CheckCube with its real vtable slot 0x1c)
    octs = []
    for _ in range(3):
        oct_, info_tmp, _a, _b = _cube(c)
        vt = e.fake_vtable('octree', 0x20 // 4 + 1, {0x1c: 0x4e3520})
        e.w32(oct_, vt)
        octs.append(oct_)

    # rooms: enabled or not, handle plain or tagged into the node base
    rooms = []
    for _ in range(4):
        room = e.alloc(dirOff + 0x40, 4)
        e.wbytes(room, bytes(r.getrandbits(8) for _ in range(dirOff + 0x40)))
        e.w16(room + dirOff + 2, 0 if r.random() < 0.8 else r.choice([1, 0x100]))
        oct_ = r.choice(octs)
        if r.random() < 0.5:
            h = (oct_ - octbase) | 1
        else:
            h = oct_
        if r.random() < 0.1:
            h = 0
        e.w32(room + dirOff + 0x28, h & 0xffffffff)
        rooms.append(room)

    # geoms for the collision object's slot 0x38 to hand back
    geoms = []
    for _ in range(r.choice([0, 1, 3, 6])):
        g = e.alloc(0x80, 4)
        e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x80)))
        e.w32(g + 0x6c, r.choice(rooms) if r.random() < 0.9 else 0)
        e.w32(g + 0x50, 0)   # root geoms: GetLocalMatPos then leaves the frame unchanged (random bytes would fault)
        if r.random() < 0.5:   # a parent frame: GetLocalMatPos then really transforms the query
            par = e.alloc(0x80, 4)
            e.wbytes(par, bytes(r.getrandbits(8) for _ in range(0x80)))
            for i in range(9):
                e.wf32(par + 4 * i, r.uniform(-1, 1))
            for i in range(3):
                e.wf32(par + 0x24 + 4 * i, r.uniform(-30, 30))
            e.w32(par + 0x50, 0)
            e.w32(g + 0x50, par)
        geoms.append(g)

    # the collision object: strip table, helper vtable (slot 0x88), and slot 0x38 (GetGeomsInBox stub)
    strip_tab = e.alloc(0x1000, 16)
    e.wbytes(strip_tab, bytes(r.getrandbits(8) for _ in range(0x1000)))

    def helper88(em, a):
        end, bref, flags = a[0], a[1], a[2]
        em.calllog.append(('helper88', _vals(em, a[3], 9), _vals(em, a[4], 3), _vals(em, a[5], 3), flags, em.r32(end)))
        return (end + 0x14) & 0xffffffff, ()
    self_ = e.alloc(0x200, 4)
    e.w32(self_, _vt(c, 'collision', {0x88: (6, helper88)}, 0x90 // 4))
    e.w32(self_ + 0x190, strip_tab)

    def gg(em, a):
        A, B, typ, p1, p2, p3, start = a[0], a[1], a[2], a[3], a[4], a[5], a[6]
        em.calllog.append(('gg', typ, start, _vals(em, p1, 9), _vals(em, p2, 3), _vals(em, p3, 3)))
        n = len(geoms)
        for i, g in enumerate(geoms):
            em.w32(A + 4 * i, g)
            em.w32(B + 4 * i, g)
        return n, ()
    coll = e.alloc(0x40, 4)
    e.w32(coll, _vt(c, 'coll', {0x38: (10, gg)}, 0x40 // 4))
    e.w32(ds + 0x1c, coll)

    count = r.choice([0xe4, 0xe5, 0xe3, 0x100, 0x400, 0x1000])   # 0xe4 sits on the room test
    out = e.alloc(4, 4)
    strips = e.alloc(count + 0x20, 4)
    e.wbytes(strips, bytes(r.getrandbits(8) for _ in range(count + 0x20)))
    p1 = e.alloc(0x24, 4)
    for i in range(9):
        e.wf32(p1 + 4 * i, r.uniform(-1, 1))
    p2 = e.alloc(0x10, 4)
    p3 = e.alloc(0x10, 4)
    for i in range(3):
        e.wf32(p2 + 4 * i, r.uniform(-60, 60))
        e.wf32(p3 + 4 * i, r.uniform(2000, 30000))   # large boxes so the query reaches the random items
    start = r.getrandbits(32)
    typ = r.getrandbits(8) & 3
    return [self_, out, strips, count, p1, p2, p3, start, typ]


S(0x4ed5b0, 'ZCollisionBase::GetStripsInsideBox', 'thiscall', None, ret='al', gen=_gsib, note='batch1126')
