"""specs_s720.py - soldier AI batch 720: the CFFCoverList spot-vector copy routines 0x5853a0 (forward) and 0x5852f0
(backward). Both take first/last in ECX/EDX and the destination (plus unused words) on the stack. Records are 0x48
bytes of random data; ranges hold 0..6 records, and the destination is a separate heap buffer."""
import struct
from pilot import S
from specs_s701 import _rnd


def _copy_args(c):
    n = c.rng.choice([0, 1, 2, 3, 6])
    src = _rnd(c, 0x48 * 8)
    c.emu.wbytes(src, c.rng.randbytes(0x48 * 8))
    dst = _rnd(c, 0x48 * 8)
    c.emu.wbytes(dst, c.rng.randbytes(0x48 * 8))
    return src, src + 0x48 * n, dst


def _fwd(c):
    f, l, d = _copy_args(c)
    return [f, l, d, c.rng.getrandbits(32)]


def _bwd(c):
    f, l, d = _copy_args(c)
    return [f, l, d, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5853a0, 'CFFCoverList spot copy forward (unnamed)', ('fastcall'), None, ret='eax', gen=_fwd, note='b720; returns the end of the destination')
S(0x5852f0, 'CFFCoverList spot copy backward (unnamed)', ('fastcall'), None, ret=None, gen=_bwd, note='b720')
