"""specs_s735.py - residue 11: ZActor::UpdateFootDust. The global record (0x7003b8) carries the byte at +0xab8 (set in a
quarter of the cases). The actor's mode at +0x64c is 0..6 and its timer at +0x772 is a random float in [-50, 200]. The engine
(0x70039c) carries the frame counter at +0x40. Slot 0x400 is a fake that logs its float argument. The first argument is a
pointer that the function never reads (a fake block)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _ufd(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    gl = _rnd(c, 0xb00)
    e.w32(0x7003b8, gl)
    e.wbytes(gl + 0xab8, bytes([1 if c.rng.random() < 0.25 else 0]))
    eng = _rnd(c, 0x100)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x40, c.rng.randint(-100000, 100000))

    def f400(em, r):
        log('actor', 0x400, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    self_ = _rnd(c, 0x800)
    e.w32(self_, e.fake_vtable('actor', 0x500, {0x400: f400}))
    e.w32(self_ + 0x64c, c.rng.randint(0, 6))
    dt = _f(c.rng.uniform(0.0, 80.0))
    if c.rng.random() < 0.3:      # timer lands on the threshold: the boundary (> 150) is exercised
        timer = _f(150.0 - _f(min(50.0, dt)))
    else:
        timer = _f(c.rng.uniform(-50.0, 200.0))
    e.wbytes(self_ + 0x772, struct.pack('<f', timer))
    dtbits = struct.unpack('<I', struct.pack('<f', dt))[0]
    return [self_, _rnd(c, 0x10), dtbits]


S(0x47cdf0, 'ZActor::UpdateFootDust', 'thiscall', None, ret=None, gen=_ufd,
  note='b735 residue 11 [medium]; slot 0x400 fake, timer threshold 150')
