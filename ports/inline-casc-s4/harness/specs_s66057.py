"""specs_s66057.py - cascade s4 batch 66057: 0x410140 (assemble a big-endian 64-bit value from record bytes 13..6)."""
from pilot import S
from recruits_util import clear_hooks


def _g410140(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    q = e.alloc(0x20, 8)
    mode = r.random()
    if mode < 0.3:
        data = bytes(r.choice([0, 0xff, 0x80, 1]) for _ in range(0x20))
    else:
        data = bytes(r.getrandbits(8) for _ in range(0x20))
    e.wbytes(q, data)
    pp = e.alloc(8, 8)
    e.w32(pp, q)
    return [pp]


S(0x410140, 'GUESS assemble a big-endian 64-bit value from record bytes', 'cdecl', None, ret='eax:edx', gen=_g410140, note='batch66057')
