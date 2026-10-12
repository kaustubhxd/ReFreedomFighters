"""specs_s1014.py - unclaimed-07 batch 14 (slice 6): CSteeringWheel::Init (0x529960).
The two group objects g and p are logging vtables: slots +0x84 and +0x8c write three random dwords through their pointer
argument (the block at this+4); g's slot +0x25c returns r (0 about a third of the time, which takes the log path).
The member object at this+0x30 has a logging slot 0. The engine log (global 0x700390) gives a stream whose cdecl slot
+0x2c is logged. Names at +4 of g and p are random or 0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _named(c, obj_size=0x40):
    o = _rnd(c, obj_size)
    c.emu.w32(o + 4, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    return o


def _steering(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    flag = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    g = _named(c)
    p = _named(c)
    vals = [c.rng.getrandbits(32) for _ in range(3)]

    def writer(off):
        def h(em, r):
            blk = em.arg32(0)
            em.calllog.append(('steer', off, em.reg('ecx'), (blk,)))
            for k in range(3):
                em.w32(blk + 4 * k, vals[k])
            em.ret(eax=0, argbytes=4)
        return h

    # the vtables: g has slots +0x84 and +0x25c (returns r); p has +0x8c
    r = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32) | 1
    def g25c(em, rr):
        em.calllog.append(('steer_g', 0x25c, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=r, argbytes=8)
    gvt = e.fake_vtable('steer_g', 0x260 // 4 + 1, {0x84: writer(0x84), 0x25c: g25c})
    e.w32(g, gvt)
    pvt = e.fake_vtable('steer_p', 0x90 // 4, {0x8c: writer(0x8c)})
    e.w32(p, pvt)

    # the member at this+0x30: slot 0 logs its three arguments
    def member0(em, rr):
        em.calllog.append(('steer_member', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    e.w32(self_o + 0x30, e.fake_vtable('steer_member', 4, {0: member0}))

    def printf(em, rr):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=0)

    stream = _rnd(c, 16)
    e.w32(stream, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [self_o, p, g, flag]


S(0x529960, 'CSteeringWheel::Init (unknown) thiscall', 'thiscall', None, ret='al', gen=_steering,
  note='unclaimed-07 batch 14; g slots +0x84, +0x25c; p slot +0x8c; member slot 0; log path when r is 0')
