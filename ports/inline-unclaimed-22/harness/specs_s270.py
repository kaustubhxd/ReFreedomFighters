"""specs_s270.py - area 22, batch270 (src/batch270.cpp): ZActorIf::MoveToSceneLocationWithForceToGroundLevel. Every object
is a Python vtable; slots log values only (matrix, position, the initialised COLI words), never stack addresses. The
parameter accessor 0x5003d0 (unclaimed-64), the random-spot helper 0x5094c0 (unclaimed-35; its two rm vt 0x1c0 randoms
come from a per-case Python st0 sequence), COLI::COLI 0x4e1b60 and the negate helper 0x4e09b0 (inline-batch45) run as
original code. The rooms line test always writes a floor point into COLI +0x28 (the COLI is otherwise stack garbage)."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _fill(name, ret, *counts):
    """Slot whose stack-buffer arguments get per-case floats (len(counts) arguments, counts[i] floats each)."""
    def h(em, r):
        em.calllog.append((name, 0, None, ()))
        for i, (n, vals) in enumerate(counts):
            a = em.arg32(i)
            for j in range(n):
                em.w32(a + 4 * j, vals[j])
        em.ret(eax=ret, argbytes=4 * len(counts))
    return h


def _fl(c, n, lo, hi):
    return [_fb(c.rng.uniform(lo, hi)) for _ in range(n)]


def _g_507810(c):
    e = c.emu
    _log_world(c, pslot=0x2c, deref=True)
    rm = _rnd(c, 0x1c00)
    db = _rnd(c, 0xb00)
    gid = _r(c)
    rnds = [c.rng.uniform(0, 1) for _ in range(2)]
    seq = list(rnds)

    def rm1c0(em, r):
        em.calllog.append(('rm.1c0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(st0=seq.pop(0) if seq else 0.25, argbytes=8)
    e.w32(rm, _pyvt(c, {0x1c0: rm1c0}))
    g = 0
    if c.rng.random() < 0.85:
        g = _rnd(c, 0x40)
        box = _rnd(c, 0x60)
        for o in (0x40, 0x44, 0x48):
            e.w32(box + o, _fb(c.rng.uniform(1, 500)))
        e.w32(g + 8, box)
        e.w32(g, _pyvt(c, {0x80: _fill('g.80', 0, (9, _fl(c, 9, -1, 1)), (3, _fl(c, 3, -1000, 1000))),
                           0x1e0: _slot('g.1e0', 1, (_r(c) & ~0xff) | c.rng.choice([0, 1]))}))
    e.w32(db, _pyvt(c, {0x58: _slot('db.58', 1, lambda em: g if em.arg32(0) == gid else 0)}))
    hit = _fl(c, 3, -1000, 1000)

    def rooms2e0(em, r):
        a = [em.arg32(i) for i in range(6)]
        co = a[0]
        em.calllog.append(('rooms.2e0', 0, None, (em.rbytes(co, 0x18), em.r32(co + 0x34), em.r32(co + 0x44), em.rbytes(co + 0x6c, 1)) + tuple(a[1:])))
        for j in range(3):
            em.w32(co + 0x28 + 4 * j, hit[j])
        em.ret(eax=0, argbytes=24)
    rooms = _rnd(c, 0x10)
    e.w32(rooms, _pyvt(c, {0x2e0: rooms2e0}))
    e.w32(db + 0xadc, rooms)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    nm = _rnd(c, 0x10)
    e.w32(nm + 4, _rnd(c, 0x10))

    def a624(em, r):
        em.calllog.append(('a.624', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def a634(em, r):
        em.calllog.append(('a.634', 0, None, (em.rbytes(em.arg32(0), 12), em.rbytes(em.arg32(1), 36))))
        em.ret(eax=0, argbytes=8)
    actor = _rnd(c, 0x10)
    e.w32(actor, _pyvt(c, {0x20: _slot('a.20', 0, nm), 0x624: a624, 0x634: a634}))
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x18, actor)
    ents = _rnd(c, 0x40)
    base = c.rng.randrange(0, 4)
    e.w32(ents + 8 * base, c.rng.choice([gid, gid, gid, _r(c)]))
    lst = _rnd(c, 0x10)
    e.w32(lst, ents)
    e.w32(lst + 8, base + 1 + c.rng.randrange(0, 3))
    q = _rnd(c, 0x10)
    e.w32(q, lst)
    e.w32(q + 4, base)
    e.w32(q + 8, 1 + c.rng.randrange(0, 2))
    par = _rnd(c, 0x10)
    e.w32(par + 4, q)
    e.mu.ctl_flush_tb()
    return [self_, par]


S(0x507810, 'ZActorIf::MoveToSceneLocationWithForceToGroundLevel', 'thiscall', None, ret=None, gen=_g_507810, nan_heap=True,
  note='batch270; void; param accessor, random spot, COLI ctor, negate as exe code; SEH cookie not reproduced')
