"""specs_s736.py - CEnemyFlag::FrameUpdate. SetFlagFrame (0x5c2120) is hooked (logs its argument). ZGameOSD::ActionMarkerAdd
(0x598d90) is hooked (logs the marker object, the vector, the type, the time and the colour). The squad list at gl+0x40c with
count at gl+0x408 holds 0..4 actors (some null); each actor's +0x852 is a marker object. The float fields are random in
about [-2, 2], with the threshold cases (0.4, 1.1, 0.5) hit often enough for the branches to run."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _enemy(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    gl = _rnd(c, 0x2000)
    e.w32(0x7003b8, gl)
    n = c.rng.randint(0, 4)
    e.w32(gl + 0x408, n)
    for i in range(n):
        if c.rng.random() < 0.2:
            e.w32(gl + 0x40c + 4 * i, 0)
            continue
        a = _rnd(c, 0x900)
        mcl = _rnd(c, 0x40)
        e.w32(a + 0x852, mcl)
        e.w32(gl + 0x40c + 4 * i, a)

    def h_setframe(em, r):
        log('flag', 0x5c2120, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def h_marker(em, r):
        # stack order (top first): vec, type, time, colour
        vec = em.rbytes(em.arg32(0), 12)
        log('mk', 0x598d90, (em.reg('ecx'), vec, em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0, argbytes=16)
    e.hook(0x5c2120, h_setframe)
    e.hook(0x598d90, h_marker)

    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0x48, c.rng.getrandbits(32))
    xv = _f(c.rng.uniform(-2.0, 2.0))
    e.wbytes(self_ + 0x64, struct.pack('<f', xv))
    r = c.rng.random()
    yv = _f(0.4 - xv) if r < 0.25 else (_f(1.1 - xv) if r < 0.5 else _f(c.rng.uniform(-2.0, 2.0)))
    e.wbytes(self_ + 0x68, struct.pack('<f', yv))
    e.w32(self_ + 0x6c, c.rng.getrandbits(24))
    for off in (0x7c, 0x80, 0x84):
        e.wbytes(self_ + off, struct.pack('<f', _f(c.rng.uniform(-100.0, 100.0))))
    e.w32(self_ + 0x88, c.rng.choice([0, 1, 2, 5, 7, 0x80000000]) if c.rng.random() < 0.3 else c.rng.getrandbits(16) | 1)
    return [self_]


S(0x5c1670, 'CEnemyFlag::FrameUpdate', 'thiscall', None, ret=None, gen=_enemy,
  note='b736 residue-11 slice [high]; SetFlagFrame and ActionMarkerAdd hooked')
