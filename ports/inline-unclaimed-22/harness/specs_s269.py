"""specs_s269.py - area 22, batch269 (src/batch269.cpp): ZFFActor::ControlBreathing. Every object is a Python vtable;
GetPos-style slots (vt 0x84) write per-case floats into their buffer and log nothing else. IsSoundCommandDone 0x467ca0 and
the sound-length setter 0x441890 (inline-soundtimers) and PSVECSubtract 0x43e920 (inline-batch45) run as original code.
The render manager's random slot vt 0x1c0 returns a float in st0 from a Python handler."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


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


def _g_59ead0(c):
    e = c.emu
    rm = _rnd(c, 0x1c00)
    db = _rnd(c, 0x40)
    last = _r(c)
    prev = 0
    if c.rng.random() < 0.85:
        prev = _rnd(c, 0x80)
        e.w32(prev + 0x70, c.rng.choice([0, 0, 0, 0, _fb(0.5), 0x80000000, 0x7fc00000]))
    snd = 0
    if c.rng.random() < 0.8:
        snd = _rnd(c, 0x100)
        e.w32(snd + 0x88, c.rng.choice([0, _r(c)]))
        e.w32(snd + 0x70, _fb(c.rng.uniform(0, 3)))
        e.w32(snd + 0x64, c.rng.randrange(-100000, 100000) & 0xffffffff)
    sid = _r(c)
    rid = sid if c.rng.random() < 0.9 else _r(c)

    def db60(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.60', 0, None, (a,)))
        em.ret(eax=prev if a == last else (snd if a == sid else 0), argbytes=4)
    e.w32(db, _pyvt(c, {0x60: db60}))
    rnd = c.rng.uniform(0, 1)

    def rm1c0(em, r):
        em.calllog.append(('rm.1c0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(st0=rnd, argbytes=8)
    e.w32(rm, _pyvt(c, {0x1c0: rm1c0}))
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1a9f, c.rng.choice([_r(c) | 1, _r(c) | 1, _r(c) | 1, 0]))
    e.w32(rm + 0x1b5d, c.rng.choice([0, 0, 0, 1, 2]))
    e.w32(rm + 0x48, _fb(c.rng.choice([0.016, 0.033, 0.1, 0.0, c.rng.uniform(0, 0.5)])))
    e.w32(0x70039c, rm)
    near = c.rng.random() < 0.6
    p2 = [c.rng.uniform(-50, 50) for _ in range(3)]
    if near:
        p1 = [p2[0] + c.rng.uniform(-400, 400), p2[1] + c.rng.uniform(-170, 170), p2[2] + c.rng.uniform(-400, 400)]
        if c.rng.random() < 0.3:
            p1 = [p2[0] + c.rng.uniform(-2, 2), p2[1], p2[2] + c.rng.uniform(-2, 2)]
    else:
        p1 = [c.rng.uniform(-2000, 2000) for _ in range(3)]
    mode = c.rng.choice(['rnd'] * 8 + ['t0', 'eqrange', 'h145'])
    if mode in ('eqrange', 'h145'):
        p2 = [0.0, 0.0, 0.0]
        p1 = [300.0, 0.0, 0.0] if mode == 'eqrange' else [c.rng.choice([1.45, 1.41, 1.49]), 0.0, 0.0]
    lis = _rnd(c, 0x10)
    e.w32(lis, _pyvt(c, {0x84: _fill('lis.84', 0, (3, [_fb(v) for v in p1]))}))
    self_ = _rnd(c, 0xa00)
    e.w32(self_, _pyvt(c, {0x84: _fill('self.84', 0, (3, [_fb(v) for v in p2])),
                           0x6e8: _slot('self.6e8', 3, rid)}))
    e.w32(self_ + 0x13b, last)
    e.w32(self_ + 0x92e, lis)
    e.w32(self_ + 0x941, _fb(c.rng.choice([-0.01, 0.01, 0.02, c.rng.uniform(-1, 1)])))
    tired = 0.0 if mode == 'eqrange' else c.rng.uniform(0, 1)
    e.w32(self_ + 0x945, _fb(tired))
    e.w32(self_ + 0x949, _fb(tired if mode == 'eqrange' else c.rng.choice([tired, 0.0, 1.0, c.rng.uniform(0, 1)])))
    if mode != 'rnd':
        e.w32(rm + 0x1a9f, 1)
        e.w32(rm + 0x1b5d, 0)
        if prev:
            e.w32(prev + 0x70, 0)
    if mode == 't0':
        e.w32(self_ + 0x941, e.r32(rm + 0x48))
    elif mode != 'rnd':
        e.w32(self_ + 0x941, _fb(-0.5))
    e.w8(self_ + 0x940, c.rng.choice([0, 1, 0x40]))
    e.w8(self_ + 0x93f, c.rng.choice([0, 1, 7]))
    e.mu.ctl_flush_tb()
    return [self_]


S(0x59ead0, 'ZFFActor::ControlBreathing', 'thiscall', None, ret=None, gen=_g_59ead0, nan_heap=True,
  note='batch269; void; IsSoundCommandDone, sound length, PSVECSubtract as exe code; SEH cookie not reproduced')
