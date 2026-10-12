"""specs_s1914.py - unclaimed-66 batch 1914: GUESS FUN_004dd910 (forwarder to 0x441a60, x87 vector transform run as original code).

Thiscall with one stack argument (the destination float[3], heap). The source is the object (a float[3] at its start plus the
transform matrix at +0x18..+0x20 read by 0x441a60; the object is 0x40 random bytes so every read is inside it)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    return [_rnd(c, 0x40), _rnd(c, 12)]


S(0x4dd910, 'GUESS FUN_004dd910 (forward to 0x441a60)', 'thiscall', None, ret=None, gen=_fwd,
  note='unclaimed-66 batch 1914; slice-5 (GUESS); 0x441a60 is original code (ext)')
