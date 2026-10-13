"""specs_s714.py - soldier AI batch 714: CFFCoverList::CreateSpotForArrow. The geom is a fake whose slot 0x80 (GetRootTM)
writes 12 random floats and a root position, slot 0x210 logs its argument. CreateSpot (0x585a40) is hooked: it logs its
seven arguments (pointed-to vectors by content) and pops 0x1c, in both runs."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _fl(c):
    r = c.rng.random()
    if r < 0.06:
        return c.rng.choice([0.0, -0.0, math.nan, math.inf, -math.inf, 1e-30])
    return c.rng.uniform(-100, 100)


def _ar(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))

    def rtm(em, r):
        m, p = em.arg32(0), em.arg32(1)
        log('geom', 0x80, ())
        em.wbytes(m, b''.join(struct.pack('<f', f32(_fl(c))) for _ in range(12)))
        em.wbytes(p, b''.join(struct.pack('<f', f32(_fl(c))) for _ in range(3)))
        em.ret(eax=0, argbytes=8)

    def flagged(em, r):
        log('geom', 0x210, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    g = _rnd(c, 0x40)
    e.w32(g, e.fake_vtable('geom', 0x220, {0x80: rtm, 0x210: flagged}))

    def create(em, r):
        args = [em.arg32(k) for k in range(8)]
        vecs = []
        for k in range(4):
            vecs.append(tuple(struct.unpack('<3I', em.rbytes(args[k], 12))) if nostk(args[k]) == 'stk' else nostk(args[k]))
        em.calllog.append(('CreateSpot', 0, em.reg('ecx'), tuple(vecs) + (args[4] & 0xff, args[5], args[6])))
        em.ret(eax=0, argbytes=0x1c)
    e.hook(0x585a40, create)
    cl = _rnd(c, 0x80)
    return [cl, g, c.rng.choice([0, 1, 2, 0xff00]), _bool(c)]


S(0x585ed0, 'CFFCoverList::CreateSpotForArrow', 'thiscall', None, ret=None, gen=_ar,
  note='b714 [high]; CreateSpot hooked, vneg runs as exe code')
