"""specs_s726.py - soldier AI batch 726: ZFFActorIf::CheckPosDir. Inputs: six floats (target position in items 0..2, direction
in items 3..5). Half of the cases are near (position close to the actor in x and z, direction almost straight down the
actor's up axis, so the pass path runs); the rest are random and take the fail path. The actor (this+0x1c) is a fake with
slots 0x20 (the name object), 0x57c (position into the second argument), 0x84 (root point), 0x88 (in-place vector); the name
object has slot 0x1d8 (fills the MYSTR). The engine's db (0x9b) has slot 0xb4 and the scene (db+0xadc) has the line
slot 0x218 and the update slot 0x21c, which log the vector contents. Cached handles at 0x7140bc, 0x7140c0 and 0x7140c4 are
set in some cases to exercise the update path. The vector helpers, accessor, MYSTR and the logger run as exe code or the
shared _log_world hooks."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _list(c, e, items, count):
    """accessor object: +0 -> inner (items at +0, count at +8); items are 8 bytes (value, type byte)."""
    inner = _rnd(c, 0x20)
    arr = _rnd(c, 8 * max(count, 2))
    for i in range(max(count, 2)):
        e.wbytes(arr + 8 * i, struct.pack('<II', items[i] if i < len(items) else c.rng.getrandbits(32), 0))
    e.w32(inner, arr)
    e.w32(inner + 8, count)
    acc = _rnd(c, 0x20)
    e.w32(acc, inner)
    e.w32(acc + 4, 0)
    e.w32(acc + 8, count)
    return acc


def _cpd(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0xb00)      # the scene pointer lives at +0xadc
    e.w32(eng + 0x9b, db)
    scene = _rnd(c, 0x100)
    e.w32(db + 0xadc, scene)

    near = c.rng.random() < 0.5
    vals = [c.rng.uniform(-30.0, 30.0) for _ in range(3)]
    if near:
        dirv = [c.rng.uniform(-0.3, 0.3), c.rng.uniform(-0.3, 0.3), -c.rng.uniform(1.0, 4.0)]
    else:
        dirv = [c.rng.uniform(-5.0, 5.0) for _ in range(3)]
    items = [_f(vals[0]), _f(vals[1]), _f(vals[2]), _f(dirv[0]), _f(dirv[1]), _f(dirv[2])]

    handles = [c.rng.getrandbits(32) | 1 for _ in range(3)]
    for addr, h in zip((0x7140bc, 0x7140c0, 0x7140c4), handles):
        e.w32(addr, h if c.rng.random() < 0.3 else 0)

    def ray218(em, r):
        a, b, f = em.arg32(0), em.arg32(1), em.arg32(2)
        log('scene', 0x218, (em.rbytes(a, 12), em.rbytes(b, 12), f))
        em.ret(eax=handles[0], argbytes=12)

    def ray21c(em, r):
        h, a, b, f = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        log('scene', 0x21c, (h, em.rbytes(a, 12), em.rbytes(b, 12), f))
        em.ret(eax=0, argbytes=16)

    svt = e.fake_vtable('scene', 0x240, {0x218: ray218, 0x21c: ray21c})
    e.w32(scene, svt)

    def db_b4(em, r):
        log('db', 0xb4, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    e.w32(db, e.fake_vtable('db', 0x200, {0xb4: db_b4}))

    gname = _rnd(c, 0x20)
    obj = _rnd(c, 0x40)

    def namefill(em, r):
        out, flag = em.arg32(0), em.arg32(1)
        log('obj', 0x1d8, (flag,))
        em.w32(out, gname)
        em.ret(eax=out, argbytes=8)
    e.w32(obj, e.fake_vtable('obj', 0x240, {0x1d8: namefill}))

    actor = _rnd(c, 0x80)

    def m20(em, r):
        log('actor', 0x20, ())
        em.ret(eax=obj, argbytes=0)

    def m57c(em, r):
        vec = em.arg32(1)
        log('actor', 0x57c, ())
        if near:
            x = vals[0] + c.rng.uniform(-1.4, 1.4)
            z = vals[2] + c.rng.uniform(-1.4, 1.4)
        else:
            x, z = c.rng.uniform(-30.0, 30.0), c.rng.uniform(-30.0, 30.0)
        y = c.rng.uniform(-30.0, 30.0)
        e.wbytes(vec, struct.pack('<fff', x, y, z))
        em.ret(eax=0, argbytes=8)

    def m84(em, r):
        p = em.arg32(0)
        log('actor', 0x84, ())
        e.wbytes(p, struct.pack('<fff', c.rng.uniform(-100.0, 100.0), c.rng.uniform(-100.0, 100.0),
                                c.rng.uniform(-100.0, 100.0)))
        em.ret(eax=0, argbytes=4)

    tilt = c.rng.random() < 0.3

    def m88(em, r):
        v = em.arg32(0)
        log('actor', 0x88, ())
        if tilt:
            e.wbytes(v, struct.pack('<fff', c.rng.uniform(-1.0, 1.0), c.rng.uniform(-1.0, 1.0), 1.0))
        em.ret(eax=0, argbytes=4)

    e.w32(actor, e.fake_vtable('actor', 0x600, {0x20: m20, 0x57c: m57c, 0x84: m84, 0x88: m88}))

    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, actor)

    args = _rnd(c, 0x20)
    e.w32(args + 4, _list(c, e, items, 6))
    e.w32(args + 8, _list(c, e, [], 0))
    return [self_, args]


S(0x558390, 'ZFFActorIf::CheckPosDir', 'thiscall', None, ret=None, gen=_cpd,
  note='b726 [high]; actor, name, scene and db slots are fakes; pass and fail paths both exercised; cached handles varied')
