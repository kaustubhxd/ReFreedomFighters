"""specs_s286.py - area 22, batch286 (src/batch286.cpp): the civilian path builder (0x5bea10). Hooked by address (both
sides reach the hooks): ProcessQueue 0x52c000 and sized delete 0x634273 (GUESS); allocator 0x41e290, free 0x41e2c0
(unclaimed-64) and the path constructor 0x476dc0 (unclaimed-81) are verified and hooked to keep the world small.
ProcessQueue delivers the next prepared result into +0x48 after a per-request number of calls. The db, the name table,
waypoint lists, waypoints, the pathfinder object and the logger are Python vtables."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g_5bea10(c):
    e = c.emu
    _log_world(c)
    self_ = _rnd(c, 0x910)
    nroutes = c.rng.choice([0, 1, 1, 2, 3])
    e.w32(self_ + 0x90c, nroutes if c.rng.random() < 0.95 else 0xffffffff)
    e.w32(self_ + 0x44, _r(c))
    # results the pathfinder hands back, in request order
    results = []
    for _ in range(12):
        r = _rnd(c, 0x20)
        seg = 0
        if c.rng.random() < 0.9:
            seg = _rnd(c, 0x18)
            n = c.rng.choice([0, 1, 2, 3])
            pts = _rnd(c, 16 * max(n, 1)) if c.rng.random() < 0.95 or n else 0
            for k in range(4 * n):
                e.w32(pts + 4 * k, _fb(c.rng.uniform(-300, 300)))
            e.w32(seg + 4, _fb(c.rng.uniform(0, 400)))
            e.w32(seg + 8, n)
            e.w32(seg + 0xc, pts)
            e.w32(seg + 0x10, c.rng.choice([0, _rnd(c, 4)]))
            e.w32(seg + 0x14, c.rng.choice([0, _rnd(c, 4)]))
        e.w32(r + 0x1c, seg)
        results.append((r, c.rng.choice([1, 1, 2, 3])))
    st = {'req': 0, 'left': None}
    e.w32(self_ + 0x48, 0)

    def pq(em, r):
        em.calllog.append(('pq', 0x52c000, em.reg('ecx'), (em.arg32(0),)))
        if st['left'] is None:
            st['left'] = results[st['req'] % len(results)][1]
        st['left'] -= 1
        if st['left'] <= 0:
            em.w32(self_ + 0x48, results[st['req'] % len(results)][0])
            st['req'] += 1
            st['left'] = None
        em.ret(eax=_r(c), argbytes=4)
    e.hook(0x52c000, pq)

    def sdel(em, r):
        em.calllog.append(('sdel', 0x634273, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, sdel)

    def alloc(em, r):
        n = em.arg32(0)
        em.calllog.append(('new', 0x41e290, None, (n,)))
        em.ret(eax=e.alloc(max(n, 4), 4), argbytes=0)
    e.hook(0x41e290, alloc)

    def free(em, r):
        em.calllog.append(('free', 0x41e2c0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x41e2c0, free)
    plen = c.rng.choice([0.0, c.rng.uniform(0, 100)])

    def ctor(em, r):
        p, n = em.reg('ecx'), em.arg32(0)
        em.calllog.append(('pathctor', 0x476dc0, None, (n,)))
        em.w32(p + 4, _fb(plen))
        em.w32(p + 0xc, e.alloc(16 * min(max(n, 1), 64) + 16, 4))   # capped: a wrong count must not exhaust the heap
        em.ret(eax=p, argbytes=4)
    e.hook(0x476dc0, ctor)
    pfid = _r(c)
    ids = {}

    def db58(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.58', 0, None, (a,)))
        em.ret(eax=ids.get(a, 0), argbytes=4)

    def db4c(em, r):
        a = [em.arg32(i) for i in range(7)]
        em.calllog.append(('db.4c', 0, None, (a[0],) + tuple(em.r32(a[1] + 4 * k) for k in range(3)) +
                           tuple(em.r32(a[2] + 4 * k) for k in range(3)) + tuple(a[3:])))
        em.ret(eax=_r(c), argbytes=28)
    names = _rnd(c, 0x10)

    def n88(em, r):
        em.calllog.append(('names.88', 0, None, (em.rbytes(em.arg32(0), 20).split(b'\0')[0],)))
        em.w32(em.arg32(1), pfid)   # the exe does not check the pathfinder object
        em.ret(eax=0, argbytes=8)
    e.w32(names, _pyvt(c, {0x88: n88}))

    def db138(em, r):
        em.calllog.append(('db.138', 0, None, ()))
        em.ret(eax=names, argbytes=0)
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: db58, 0x4c: db4c, 0x138: db138}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    pf = _rnd(c, 0x10)

    def p214(em, r):
        em.calllog.append(('pf.214', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.w32(pf, _pyvt(c, {0x214: p214}))
    ids[pfid] = pf
    for ri in range(max(0, min(nroutes, 3))):
        ent = self_ + 0x4c + ri * 0x3a
        wps = []
        for k in range(c.rng.choice([0, 1, 2, 3, 4])):
            wid = _r(c)
            wo = _rnd(c, 0x10)
            p3 = [_fb(c.rng.uniform(-500, 500)) for _ in range(3)]

            def w84(em, r, p3=p3):
                o = em.arg32(0)
                em.calllog.append(('wp.84', 0, None, tuple(em.r32(o + 4 * j) for j in range(3))))
                for j in range(3):
                    em.w32(o + 4 * j, p3[j])
                em.ret(eax=0, argbytes=4)
            e.w32(wo, _pyvt(c, {0x84: w84}))
            ids[wid] = wo
            wps.append(wid)

        def l14(em, r, wps=wps):
            em.calllog.append(('wl.14', 0, None, ()))
            em.ret(eax=len(wps), argbytes=0)

        def l30(em, r, wps=wps):
            i = em.arg32(0)
            em.calllog.append(('wl.30', 0, None, (i,)))
            em.ret(eax=wps[i] if i < len(wps) else _r(c), argbytes=4)
        wl = _rnd(c, 0x10)
        e.w32(wl, _pyvt(c, {0x14: l14, 0x30: l30}))
        holder = _rnd(c, 0x20)
        e.w32(holder + 0x18, wl)
        e.w32(ent, holder)
        e.w8(ent + 0x39, c.rng.choice([0, 1, 0, 0x80]) if wps else 0)   # a closed empty route reads a null waypoint
        e.w8(ent + 7, c.rng.choice([1, 0xff]))
        e.w32(ent + 0xd, _r(c))
    return [self_]


S(0x5bea10, 'CCivilianPathList::Load2 (civilian path builder)', 'thiscall', None, ret=None, gen=_g_5bea10,
  nan_heap=True, note='batch286; void; pathfinder queue, deletes and path ctor hooked; SEH/cookie not reproduced')
