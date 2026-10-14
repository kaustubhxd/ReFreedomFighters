"""specs_s34131.py - 0x49b410: this slot 0x18 (2 args) writes a random byte to its first argument; eight distinct byte targets prefilled with random bytes.
0x4a1bf0: stream object a with slots 0x3c, 0x40, 0x44 recorders (1 arg); this with +4 flags, words at +0x8b0/+0x8b2 (high bits set), count +0x48 of -1..4 (also non-positive), pointer array at +0x5c to dwords, value at +0x6c; ret al."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g49b410(c):
    clear_hooks(c)
    r = c.rng
    byte = r.choice([0, 0xff, 0x80, 0x01, r.getrandbits(8), r.getrandbits(8)])

    def wb(em, k):
        em.wbytes(em.arg32(0), bytes([byte]))
    me = obj(c, 0x20, {0x18: pystub(c, 2, this=True, side=wb, stackmark=(0,))}, nslots=0x1c // 4)
    ps = [rnd(c, 0x10) for _ in range(8)]
    return [me] + ps


def _g4a1bf0(c):
    clear_hooks(c)
    r = c.rng
    a = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x40: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True)}, nslots=0x48 // 4)
    me = rnd(c, 0x8c0)
    n = r.choice([0, 1, 2, 3, 4, -1, 0x7fffffff if False else 5])
    c.emu.w32(me + 0x48, n & 0xffffffff)
    for i in range(max(n, 0)):
        c.emu.w32(me + 0x5c + 4 * i, rnd(c, 0x10))
    return [me, a]


S(0x49b410, 'GUESS unpack a flag byte', 'thiscall', None, ret=None, gen=_g49b410, note='batch34131')
S(0x4a1bf0, 'GUESS write settings to a stream', 'thiscall', None, ret='al', gen=_g4a1bf0, note='batch34131')
