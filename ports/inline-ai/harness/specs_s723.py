"""specs_s723.py - soldier AI batch 723: CCoverSpot::Init (0x5def10) and its ray helper 0x5ded60.
The scene (db 0x9b -> 0xadc) answers the ray test (slot 0x2e0) with a random bool and logs the COLI contents it is given
(start and delta as floats, the flag byte). CheckShootOver (0x5deb20) is hooked: it logs its arguments and returns a
random bool. The vector helpers, the COLI constructor, vrot and the libm cos/sin run as exe code (math stubs are the
harness's). Spot +0x34 starts at 0 as in CreateSpot; the type is 0, 1 or 2; the flags word is random."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _vec(c, lo=-3.0, hi=3.0):
    return [f32(c.rng.uniform(lo, hi)) for _ in range(3)]


def _world(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, 0, args))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    sc = _rnd(c, 0x40)

    def ray(em, r):
        p = em.arg32(0)
        start = tuple(struct.unpack('<3I', em.rbytes(p, 12)))
        delta = tuple(struct.unpack('<3I', em.rbytes(p + 0xc, 12)))
        log('scene', 0x2e0, (start, delta, em.r8(p + 0x6c), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5)))
        em.ret(eax=_bool(c) if c.rng.random() < 0.6 else 0, argbytes=24)
    e.w32(sc, e.fake_vtable('scene', 0x300, {0x2e0: ray}))
    e.w32(db + 0xadc, sc)
    e.hook(0x5deb20, lambda em, r: (log('CheckShootOver', 0, (em.reg('ecx'),
                                                                   tuple(nostk(em.arg32(0)) for _ in range(1)),
                                                                   em.arg32(1), em.arg32(2))),
                                   em.ret(eax=_bool(c), argbytes=12)))


def _init(c):
    _world(c)
    spot = _rnd(c, 0x48)
    e = c.emu
    e.w32(spot + 0x34, 0)
    B = _rnd(c, 12); e.wbytes(B, struct.pack('<3f', *_vec(c)))
    A = _rnd(c, 12); e.wbytes(A, struct.pack('<3f', *_vec(c)))
    C = _rnd(c, 12); e.wbytes(C, struct.pack('<3f', *_vec(c)))
    D = _rnd(c, 12); e.wbytes(D, struct.pack('<3f', *_vec(c, 0.2, 2.0)))
    return [spot, B, A, C, D, c.rng.choice([0, 1, 2]), c.rng.getrandbits(32)]


def _ray(c):
    _world(c)
    spot = _rnd(c, 0x48)
    e = c.emu
    e.w32(spot + 0x34, 0)
    C = _rnd(c, 12); e.wbytes(C, struct.pack('<3f', *_vec(c)))
    D = _rnd(c, 12); e.wbytes(D, struct.pack('<3f', *_vec(c, 0.2, 2.0)))
    return [spot, C, c.rng.choice([0.5, 1.0, 2.0, -1.0, c.rng.uniform(-3, 3)]), D, c.rng.choice([0, 1])]


S(0x5def10, 'CCoverSpot::Init', 'thiscall', None, ret='al', gen=_init,
  note='b723 [low]; CheckShootOver hooked; ray test and math exe code')
S(0x5ded60, 'CCoverSpot ray helper (unnamed)', 'thiscall', None, ret='al', gen=_ray, note='b723')
