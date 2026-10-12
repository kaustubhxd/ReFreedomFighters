"""specs_s8800.py - hitreact batch 8800: ZIKLNKOBJ::HitRagdoll (0x466c10), ZActor::DieByForce (0x4783f0).
Both forward to a virtual slot; the receiver is a recording stub (pointer args are heap pointers from the gen, the float
is recorded as its bits)."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge


def _fbits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _strength(c):
    r = c.rng
    return _fbits(r.choice((1.0, 2.0, 0.2, 0.6, 4.0, fedge(c), r.uniform(-5, 50))))


def _hit(c):
    bm = obj(c, 0x300, {0x3c: stub(c, 3)})
    self = rnd(c, 0x200)
    c.emu.w32(self + 0x6c, bm)
    return [self, rnd(c, 16), rnd(c, 16), _strength(c)]


S(0x466c10, 'ZIKLNKOBJ::HitRagdoll', 'thiscall', ret=None, gen=_hit)


def _die(c):
    a = obj(c, 0x900, {0x664: stub(c, 0)})
    return [a, rnd(c, 16), rnd(c, 16), _strength(c), c.rng.choice((0, 1, c.rng.getrandbits(32)))]


S(0x4783f0, 'ZActor::DieByForce', 'thiscall', ret=None, gen=_die)
