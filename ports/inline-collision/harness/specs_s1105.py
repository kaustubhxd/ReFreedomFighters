"""specs_s1105.py - collision thread batch 1105: 0x4e8ed0 ZCollisionBox::CalcStripsBoundInfo.
Engine globals: [0x70039c] gets a fake system object whose +0x1aa3 and +0x9b point at small blocks holding the
room-offset word (+0x20) and the octree base (+0xaec). [0x700390] is a fake error object: slot 0x20 (thiscall,
2 args) returns a second object whose slot 0x2c is a cdecl call with 3 args; both are logged."""
import struct
from pilot import S, F


def _fv(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.fv(lo, hi, 0.02))
    return a


def _geom(c, rooms):
    e, r = c.emu, c.rng
    depth = r.choice([1, 1, 2, 3])
    nxt = 0
    g = 0
    for _ in range(depth):
        g = e.alloc(0x80, 4)
        for i in range(9):
            e.wf32(g + 4 * i, r.uniform(-1.5, 1.5))
        for i in range(9, 12):
            e.wf32(g + 4 * i, r.uniform(-50, 50))
        e.w32(g + 0x50, nxt)
        nxt = g
    e.w32(g + 0x6c, r.choice(rooms))
    return g


def _csbi(c):
    e, r = c.emu, c.rng
    # engine globals
    sysobj = e.alloc(0x2000, 4)
    blkA = e.alloc(0x40, 4)
    blkB = e.alloc(0xb00, 4)
    off = r.choice([0, 0x10, 0x40])
    e.w32(blkA + 0x20, off)
    e.w32(sysobj + 0x1aa3, blkA)
    e.w32(sysobj + 0x9b, blkB)
    oct_base = e.alloc(0x200, 16)
    e.w32(blkB + 0xaec, oct_base)
    nodes = []
    for k in range(3):
        node_off = 0x20 + 0x40 * k
        for j in range(3):
            e.wf32(oct_base + node_off + 4 + 4 * j, r.uniform(-500, 500))
        e.wf32(oct_base + node_off + 0x10, r.choice([16.0, 32.0, 64.0, 100.0, r.uniform(1, 200)]))
        nodes.append(node_off)
    rooms = []
    for k in range(3):
        room = e.alloc(off + 0x30, 4)
        e.w32(room + off + 0x28, nodes[k] | r.choice([0, 1]))
        rooms.append(room)
    e.w32(0x70039c, sysobj)
    calls = []

    def log2(em, rr):
        o2 = c.vars['o2']
        em.calllog.append(('eh', 0x20, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=o2, argbytes=8)

    def fmt(em, rr):
        em.calllog.append(('o2', 0x2c, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)
    c.vars['o2'] = e.fake_object('o2', 0x10, nslots=0x30 // 4, slots={0x2c: fmt})
    eh = e.fake_object('eh', 0x10, nslots=0x24 // 4, slots={0x20: log2})
    e.w32(0x700390, eh)
    e._image_dirty = True
    # strips
    ns = r.choice([1, 2, 3, 4, 5])
    geoms = [_geom(c, rooms) for _ in range(r.choice([1, 2, 3]))]
    ns_n = [r.choice([3, 4, 5, 8]) for _ in range(ns)]
    nv = sum(ns_n)
    span = (((nv + 2 * ns) * 12 + 0xf) & ~0xf)
    room_boxes = ns if r.random() < 0.8 else r.randint(0, ns - 1)
    size = span + 24 * room_boxes + r.choice([0, 0, 8, 16])
    blk = e.alloc(size + 0x40, 16)
    a = blk
    for k in range(ns):
        n = ns_n[k]
        e.w32(a, n)
        g = geoms[min(k * len(geoms) // ns, len(geoms) - 1)] if r.random() < 0.7 else r.choice(geoms)
        e.w32(a + 0x10, g)
        q = e.alloc(0x10, 4)
        lo = [r.randint(0, 0xffff) for _ in range(3)]
        hi = [min(0xffff, l + r.randint(0, 3000)) for l in lo]
        for j in range(3):
            e.w16(q + 4 + 2 * j, lo[j])
            e.w16(q + 10 + 2 * j, hi[j])
        e.w32(a + 0x14, q)
        for i in range(3 * n):
            e.wf32(a + 0x18 + 4 * i, r.uniform(-10, 10))
        a += 0x18 + 12 * n
    this = e.alloc(0x50, 4)
    e.w32(this + 8, ns)
    e.w32(this + 0xc, blk)
    e.w32(this + 0x10, size)
    e.w32(this + 0x14, r.getrandbits(32))
    for i in range(9):
        e.wf32(this + 0x18 + 4 * i, r.uniform(-1.5, 1.5))
    for i in range(3):
        e.wf32(this + 0x3c + 4 * i, r.uniform(-100, 100))
    return [this]


S(0x4e8ed0, 'ZCollisionBox::CalcStripsBoundInfo', 'thiscall', None, gen=_csbi, note='batch1105')
