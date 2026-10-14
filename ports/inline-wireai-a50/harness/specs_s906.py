"""specs_s906.py - gap-band slice, batch 906: 0x4209f0 (GUESS name Scan4209f0), stdcall, two stack args (a, b; ret 8), returns eax.
The scan works on a random byte block of 0x8200 bytes. Two shapes are drawn: short runs of equal bytes (length 1 to 8), and an
alternating pattern with no run longer than one (so the scan reaches the a+0x7fff limit). The ends b are drawn inside and past the
limit, and a == b and a > b are drawn too. Heap bytes are read only."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    N = 0x8200
    blk = rnd(c, N)
    if r.random() < 0.3:
        buf = bytes((k & 1) for k in range(N))           # no run longer than one: the scan reaches the limit
    else:
        buf = bytearray()
        while len(buf) < N:
            buf += bytes([r.getrandbits(8) & 3]) * r.choice([1, 2, 3, 4, 5, 8])
        buf = bytes(buf[:N])
    e.wbytes(blk, buf)
    a = blk + r.choice([0, 1, 5, 0x40])
    b = blk + r.choice([0, 1, 3, 0x20, 0x80, 0xff, 0x100, 0x7fff, 0x7fff + 1, 0x8100])
    if r.random() < 0.1:
        b = a
    return [a, b]


S(0x4209f0, 'Scan4209f0 (GUESS name)', 'stdcall', None, ret='eax', gen=_gen, note='area50 batch906 (band slice)')
