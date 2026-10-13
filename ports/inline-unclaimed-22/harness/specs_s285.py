"""specs_s285.py - area 22, batch285 (src/batch285.cpp): ZCollisionBase::ExpandThroughGates. GetCen 0x4daf90 (verified
in inline-collision) is hooked and writes a per-case centre; rectBoxColi 0x4df330 is a GUESS hook (logs its inputs by
content (the 3x3 part of the copied matrix only: mcpy copies 9 floats), answers a per-call bool with junk upper bytes); mcpy 0x4de420, vmmul 0x4419f0 and PSVECAdd 0x441940
(inline-batch45) run as exe code. Rooms, gate lists, gates and room lists are Python vtables over a per-case world:
a pool of rooms with fixed vt 0x37c flags, gates that lead to random rooms of the pool."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _list(c, name, items):
    """REFTAB stand-in: vt 0x14 count, vt 0x4c start, vt 0x5c next (iterator word 0 at the end, mixed words before)."""
    st = {'i': 0}

    def cnt(em, r):
        em.calllog.append((name + '.14', 0, None, ()))
        em.ret(eax=len(items) if c.rng.random() < 0.9 or not items else len(items) | 0x100, argbytes=0)

    def start(em, r):
        st['i'] = 0
        em.calllog.append((name + '.4c', 0, None, ()))
        em.w32(em.arg32(0), 0x11 if items else 0)
        em.ret(eax=_r(c), argbytes=4)

    def nxt(em, r):
        p = em.arg32(0)
        i = st['i']
        st['i'] += 1
        em.calllog.append((name + '.5c', 0, None, (i,)))
        if i < len(items):
            em.w32(p, c.rng.choice([1, 2, 0x80000000, _r(c) | 1]))
            em.ret(eax=items[i], argbytes=4)
        else:
            em.w32(p, 0)
            em.ret(eax=_r(c), argbytes=4)
    o = _rnd(c, 0x10)
    c.emu.w32(o, _pyvt(c, {0x14: cnt, 0x4c: start, 0x5c: nxt}))
    return o


def _g_4ec750(c):
    e = c.emu

    def cen(em, r):
        o = em.arg32(0)
        em.calllog.append(('getcen', 0x4daf90, em.reg('ecx'), ()))
        for k in range(3):
            em.w32(o + 4 * k, _fb(c.rng.uniform(-50, 50)))
        em.ret(eax=0, argbytes=4)

    def rbc(em, r):
        m, p = em.reg('ecx'), em.reg('edx')
        ex, gm, gc, gx = (em.arg32(i) for i in range(4))
        em.calllog.append(('rectbox', 0x4df330, None, tuple(em.r32(m + 4 * k) for k in range(9)) +
                           tuple(em.r32(p + 4 * k) for k in range(3)) + (ex, gm, gx) +
                           tuple(em.r32(gc + 4 * k) for k in range(3))))
        em.ret(eax=(_r(c) & ~0xff) | c.rng.choice([0, 1, 1, 0x80]), argbytes=16)
    e.hook(0x4daf90, cen)
    e.hook(0x4df330, rbc)
    db = _rnd(c, 0x10)
    ids = {}

    def db58(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.58', 0, None, (a,)))
        em.ret(eax=ids.get(a, 0), argbytes=4)
    e.w32(db, _pyvt(c, {0x58: db58}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    npool = c.rng.choice([2, 4, 6, 9])
    pool = []
    for k in range(npool):
        rr = _rnd(c, 0xb0)
        flags = c.rng.choice([0, 1, 3, 2, 1 | 0x100, 0x80])

        def s378(em, r, k=k):
            em.calllog.append(('room%d.378' % k, 0, None, (em.arg32(0), em.arg32(1))))
            em.ret(eax=_r(c), argbytes=8)

        def s37c(em, r, k=k, flags=flags):
            em.calllog.append(('room%d.37c' % k, 0, None, ()))
            em.ret(eax=(_r(c) & ~0xff) | flags & 0xff, argbytes=0)

        def s94(em, r, k=k):
            m, p = em.arg32(0), em.arg32(1)
            em.calllog.append(('room%d.94' % k, 0, None, tuple(em.r32(m + 4 * j) for j in range(9)) +
                               tuple(em.r32(p + 4 * j) for j in range(3))))
            for j in range(3):
                em.w32(p + 4 * j, _fb(c.rng.uniform(-100, 100)))
            em.ret(eax=0, argbytes=8)
        e.w32(rr, _pyvt(c, {0x378: s378, 0x37c: s37c, 0x94: s94}))
        pool.append(rr)
    # gates: each room gets a list of gate ids; a gate is a portal object whose +8 is a geometry block
    for k, rr in enumerate(pool):
        gl = 0
        if c.rng.random() < 0.85:
            gids = []
            for g in range(c.rng.choice([0, 1, 2, 3])):
                gid = _r(c)
                gobj = _rnd(c, 0x10)
                geo = _rnd(c, 0x50)
                for j in range(0x14):
                    e.w32(geo + 4 * j, _fb(c.rng.uniform(-1, 1) if j < 9 else c.rng.uniform(-100, 100)))
                behind = []
                for _ in range(c.rng.choice([0, 1, 2, 3])):
                    xid = _r(c)
                    o2 = _rnd(c, 0x10)
                    tgt = c.rng.choice(pool)

                    def o20(em, r, tgt=tgt):
                        em.calllog.append(('o2.20', 0, None, ()))
                        em.ret(eax=tgt, argbytes=0)
                    e.w32(o2, _pyvt(c, {0x20: o20}))
                    ids[xid] = o2
                    behind.append(xid)
                rl = _list(c, 'rl', behind) if c.rng.random() < 0.9 else 0
                portal = c.rng.choice([0, 1, 1, 1, 0x100])

                def g234(em, r, portal=portal):
                    em.calllog.append(('gate.234', 0, None, ()))
                    em.ret(eax=(_r(c) & ~0xff) | portal, argbytes=0)

                def g230(em, r, rl=rl):
                    em.calllog.append(('gate.230', 0, None, ()))
                    em.ret(eax=rl, argbytes=0)
                e.w32(gobj, _pyvt(c, {0x234: g234, 0x230: g230}))
                e.w32(gobj + 8, geo)
                ids[gid] = gobj
                gids.append(gid)
            gl = _list(c, 'gl', gids)
        e.w32(rr + 0xa4, gl)
    order = pool[:]
    c.rng.shuffle(order)
    cnt = c.rng.choice([0, 1, 1, 2, 3, npool])
    cnt = min(cnt, npool)
    cap = cnt + c.rng.choice([0, 1, 2, 4, 6])
    rooms = _rnd(c, 4 * max(cap, 1))
    for k in range(cap):
        e.w32(rooms + 4 * k, order[k] if k < cnt else _r(c))
    ng = c.rng.choice([0, 1, 3, 6, 12])
    gates = _rnd(c, 4 * max(ng, 1))
    for k in range(ng):
        e.w32(gates + 4 * k, _r(c))
    first = _rnd(c, 4 * max(cap, 1))
    for k in range(cap):
        e.w32(first + 4 * k, _r(c))
    mat = _rnd(c, 0x30)
    for k in range(12):
        e.w32(mat + 4 * k, _fb(c.rng.uniform(-1, 1)))
    pos = _rnd(c, 0x10)
    ext = _rnd(c, 0x10)
    for k in range(3):
        e.w32(pos + 4 * k, _fb(c.rng.uniform(-100, 100)))
        e.w32(ext + 4 * k, _fb(c.rng.uniform(0, 30)))
    changed = _rnd(c, 4)
    e.w32(changed, c.rng.choice([0, 0x01010100]))
    return [_rnd(c, 0x10), changed, rooms, rooms + 4 * cap, cnt, gates, gates + 4 * ng, first, mat, pos, ext]


S(0x4ec750, 'ZCollisionBase::ExpandThroughGates', 'thiscall', None, ret='u32', gen=_g_4ec750, nan_heap=True,
  note='batch285; returns the room count; GetCen hooked, rectBoxColi GUESS hook; mcpy, vmmul, PSVECAdd as exe code')
