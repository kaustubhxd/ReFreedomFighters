"""specs_s273.py - area 22, batch273 (src/batch273.cpp): ZPlayer::CheckMoveObjectTorso. mpul 0x4de520 (matrix
interpolation, not verified anywhere) is hooked as a GUESS stub that logs its inputs and writes a float32 lerp of the two
matrices. vdist, mcpy, PSVECAdd, PSVECSubtract (inline-batch45), vmmul 0x441970 and vmtmul 0x441a60 (unclaimed-24
collision rerun), mmtmul 0x4de4b0 (doc-only batch45) and the CRT thunk 0x634d70 run as original code. The collision
object's vt 0x68 returns a per-case sequence of hit/free results; the reference geom's vt 0x94 logs and rewrites the
reference pose."""
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


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _wfl(e, a, vals):
    for j, v in enumerate(vals):
        e.w32(a + 4 * j, _fb(v))


def _g_481990(c):
    e = c.emu
    _log_world(c, pslot=0x30)

    def mpul(em, r):
        out, a, b = em.reg('ecx'), em.reg('edx'), em.arg32(0)
        t = struct.unpack('<f', struct.pack('<I', em.arg32(1)))[0]
        A = struct.unpack('<9f', em.rbytes(a, 36))
        B = struct.unpack('<9f', em.rbytes(b, 36))
        em.calllog.append(('mpul', 0, None, (em.rbytes(a, 36), em.rbytes(b, 36), em.arg32(1))))
        for j in range(9):
            em.w32(out + 4 * j, _fb(_f32(_f32(A[j] * _f32(1 - t)) + _f32(B[j] * t))))
        em.ret(eax=0, argbytes=8)
    e.hook(0x4de520, mpul)
    seq = [c.rng.choice([0, 1, 1, 0x100, 0x101]) for _ in range(40)]
    sq = list(seq)

    def coli68(em, r):
        a = [em.arg32(i) for i in range(5)]
        em.calllog.append(('coli.68', 0, None, (a[0], a[1], em.rbytes(a[2], 12), em.rbytes(a[3], 36), a[4])))
        em.ret(eax=sq.pop(0) if sq else 0, argbytes=20)
    coli = _rnd(c, 0x10)
    e.w32(coli, _pyvt(c, {0x68: coli68}))
    osd = _rnd(c, 0x20)
    e.w32(osd + 0x1c, coli)
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x1aa3, osd)
    e.w32(0x70039c, rm)
    newref = _fl(c, 9, -1, 1)
    newrp = _fl(c, 3, -100, 100)

    def r94(em, r):
        m, p = em.arg32(0), em.arg32(1)
        em.calllog.append(('ref.94', 0, None, (em.rbytes(m, 36), em.rbytes(p, 12))))
        for j in range(9):
            em.w32(m + 4 * j, newref[j])
        for j in range(3):
            em.w32(p + 4 * j, newrp[j])
        em.ret(eax=0, argbytes=8)
    refo = _rnd(c, 0x10)
    e.w32(refo, _pyvt(c, {0x94: r94}))
    g = _rnd(c, 0x40)
    e.w32(g, _pyvt(c, {0x20: _slot('g.20', 0, refo)}))
    kind = _rnd(c, 0x40)
    e.w32(kind + 0x23, c.rng.choice([0x200000, 0x200000, 0x200000, 0x300000, 0x100000, 0, c.rng.getrandbits(32)]))
    e.w32(g + 0xc, kind)
    tm = _rnd(c, 0x80)
    e.w8(tm + 0x3c, c.rng.choice([0x20, 0x20, 0x20, 0x21, 0]))
    _wfl(e, tm + 0x30, [c.rng.uniform(-50, 50) for _ in range(3)])
    e.w32(tm + 0x6c, c.rng.getrandbits(32))
    e.w32(g + 8, tm)

    def mat():
        return [c.rng.uniform(-1, 1) for _ in range(9)]
    m0 = mat()
    m1 = c.rng.choice([m0, mat(), mat()])
    p0 = [c.rng.uniform(-500, 500) for _ in range(3)]
    p1 = c.rng.choice([p0, [v + c.rng.uniform(-200, 200) for v in p0], [v + c.rng.uniform(-2, 2) for v in p0]])
    if c.rng.random() < 0.15:   # identity poses, short move: the step starts at exactly 0.5
        m0 = [1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0]
        m1 = list(m0)
        p1 = [p0[0] + c.rng.uniform(-0.5, 0.5), p0[1], p0[2]]
        sq[:2] = [1, c.rng.choice([0, 1])]
    bufs = []
    for vals in (m0, p0, m1, p1, mat(), [c.rng.uniform(-100, 100) for _ in range(3)]):
        b = _rnd(c, 4 * len(vals))
        _wfl(e, b, vals)
        bufs.append(b)
    self_ = _rnd(c, 0x480)
    e.mu.ctl_flush_tb()
    return [self_, _rnd(c, 12), _rnd(c, 36), g] + bufs


S(0x481990, 'ZPlayer::CheckMoveObjectTorso', 'thiscall', None, ret='st0', gen=_g_481990, nan_heap=True,
  note='batch273; mpul 0x4de520 hooked (GUESS); vector/matrix helpers and CRT thunk as exe code; SEH cookie not reproduced')
