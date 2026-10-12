"""specs_s604.py - unclaimed-06 claim 4 (docs/20-unclaimed-06.md): ZCollisionBase::LockCollisionBox(char*, unsigned int).
Thiscall, two arguments, ret 8. The object is 0x1000 random bytes; the char* is a random 64-byte buffer. The two callees
(0x4ea380, 0x4eb060) run as original code on both sides, so their effect is checked by the same case comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x1000), _rnd(c, 64, 1), c.rng.getrandbits(32)]


S(0x4edd10, 'ZCollisionBase::LockCollisionBox (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-06 claim 4; calls original 0x4ea380 and 0x4eb060, clears +0xc, returns this+4')
