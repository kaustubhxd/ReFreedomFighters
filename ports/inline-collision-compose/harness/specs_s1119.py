"""specs_s1119.py - collision thread batch 1119: GetGeomsInBox. The collision object's slot 0x14 (room list, logs
its scalars and returns 0..3 rooms written into the begin array), slot 0x7c (logs scalars, returns a count), each
room's slot 0x94 (logs nothing; values only) and 0x344 (logs scalars, returns a count). Frame pointers are logged
as values only (same reason as batch 1118)."""
from pilot import S, F
from specs_s1110 import _vt


def _gb(c):
    e, r = c.emu, c.rng
    this = e.alloc(0x1b0, 4)
    n14 = r.choice([0, 1, 2, 3])
    n7c = r.choice([0, 1, 2])
    rooms = []
    for _ in range(3):
        rm = e.alloc(0x10, 4)
        n344 = r.choice([0, 1, 2])
        e.w32(rm, _vt(c, 'room', {0x94: (2, lambda em, a: (0, (tuple(round(em.rf32(a[0] + 4 * i), 6) for i in range(9)),
                                                              tuple(round(em.rf32(a[1] + 4 * i), 6) for i in range(3))))),
                                  0x344: (8, lambda em, a: (n344, (a[0], a[1], a[2], a[5], a[6], a[7])))}, 0x348 // 4))
        rooms.append(rm)
    def vals(em, a):
        return tuple(a[:3]) + tuple(a[6:])
    def rl(em, a):
        # the room list writes its rooms into the begin array and returns the count in eax
        for i in range(n14):
            em.w32(a[0] + 4 * i, rooms[i])
        return n14, (a[2], a[3], a[4], a[5])
    e.w32(this, _vt(c, 'cbase', {0x14: (6, rl),
                                  0x7c: (8, lambda em, a: (n7c, vals(em, a)))}, 0x80 // 4))
    # the room list callee writes into a local array; the count comes back in eax
    e.w32(this + 0x19d, e.alloc(0x10, 4))
    a = e.alloc(0x400, 4)
    b = e.alloc(0x400, 4)
    p1 = e.alloc(0x24, 4)
    p2 = e.alloc(0x10, 4)
    p3 = e.alloc(0x10, 4)
    for i in range(9):
        e.wf32(p1 + 4 * i, r.uniform(-1, 1))
    for i in range(3):
        e.wf32(p2 + 4 * i, r.uniform(-20, 20))
        e.wf32(p3 + 4 * i, r.uniform(-20, 20))
    return [this, a, b, r.getrandbits(32), p1, p2, p3, r.getrandbits(32),
            r.getrandbits(8) & 1, r.getrandbits(8) & 1, r.getrandbits(8) & 1]


S(0x4ecf50, 'ZCollisionBase::GetGeomsInBox', 'thiscall', None, ret='eax', gen=_gb, note='batch1119')
