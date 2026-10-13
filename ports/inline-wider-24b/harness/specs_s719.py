"""specs_s719.py - soldier AI batch 719: CFFCoverList::CreateSpotsAlongSpline. The shape is a fake (length at +0x20,
root point 0x84 adds fixed offsets, root vector 0x88 scales, flag 0x210 logs). BasicShape::GetSplinePosVelocity
(0x460af0) and CreateSpot (0x585a40) are hooked and log their arguments by content; the spline hook writes random
positions and velocities, with zero components about 40% of the time (the normalise branch)."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _cs(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    def spline(em, r):
        pos_p, vel_p, u = em.arg32(0), em.arg32(1), struct.unpack('<f', struct.pack('<I', em.arg32(2)))[0]
        log('spline', 0, (round(u, 6),))
        p = [f32(u * 40.0 + c.rng.uniform(-5, 5)), f32(c.rng.uniform(-30, 30)), f32(c.rng.uniform(-200, 200))]
        v = [f32(c.rng.uniform(-1, 1)), f32(c.rng.uniform(-1, 1)), f32(c.rng.uniform(-1, 1))]
        if c.rng.random() < 0.1:
            v = [0.0, 0.0, 0.0]          # the all-zero vector: no normalise
        for k in range(3):
            if c.rng.random() < 0.4 / 3:
                v[k] = 0.0
        em.wbytes(pos_p, struct.pack('<3f', *p))
        em.wbytes(vel_p, struct.pack('<3f', *v))
        em.ret(eax=0, argbytes=12)
    e.hook(0x460af0, spline)

    def create(em, r):
        args = [em.arg32(k) for k in range(8)]
        vecs = []
        for k in range(4):
            vecs.append(tuple(struct.unpack('<3I', em.rbytes(args[k], 12))) if nostk(args[k]) == 'stk' else nostk(args[k]))
        em.calllog.append(('CreateSpot', 0, nostk(em.reg('ecx')), tuple(vecs) + (args[4] & 0xff, args[5], args[6])))
        em.ret(eax=0, argbytes=0x1c)
    e.hook(0x585a40, create)

    shape = _rnd(c, 0x80)
    e.wbytes(shape + 0x20, struct.pack('<f', f32(c.rng.choice([0.0, -5.0, 10.0, 74.9, 75.0, 75.1, 150.0, c.rng.uniform(0, 400)]))))

    def rootpt(em, r):
        p = em.arg32(0)
        log('shape', 0x84, tuple(struct.unpack('<3I', em.rbytes(p, 12))))
        vals = struct.unpack('<3f', em.rbytes(p, 12))
        em.wbytes(p, struct.pack('<3f', vals[0] + 2.0, vals[1] - 1.0, vals[2] + 0.5))
        em.ret(eax=0, argbytes=4)

    def rootvec(em, r):
        p = em.arg32(0)
        log('shape', 0x88, tuple(struct.unpack('<3I', em.rbytes(p, 12))))
        vals = struct.unpack('<3f', em.rbytes(p, 12))
        em.wbytes(p, struct.pack('<3f', vals[0] * 0.5, vals[1], vals[2] * 2.0))
        em.ret(eax=0, argbytes=4)

    def flagged(em, r):
        log('shape', 0x210, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    svt = e.fake_vtable('shape', 0x220, {0x84: rootpt, 0x88: rootvec, 0x210: flagged})
    e.w32(shape, svt)
    cl = _rnd(c, 0x80)
    return [cl, shape, c.rng.choice([0, 1, 2, 3]), _bool(c)]


S(0x586760, 'CFFCoverList::CreateSpotsAlongSpline', 'thiscall', None, ret=None, gen=_cs,
  note='b719 [medium]; spline evaluator and CreateSpot hooked')
