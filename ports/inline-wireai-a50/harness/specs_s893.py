"""specs_s893.py - gap-band slice, batch 893: 0x41f190 (GUESS name Fix41f190), thiscall (ECX unused), one stack arg (pointer), ret 4,
void. The pointer is the middle of a random block; the header word (p-8) is drawn negative about half the time, and the xor of the
six words is drawn zero sometimes so the cmove branch runs. Heap bytes are compared."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    blk = rnd(c, 0x40)
    p = blk + 0x20
    neg = r.random() < 0.5
    h = r.getrandbits(32) | (0x80000000 if neg else 0)
    h &= 0xffffffff if neg else 0x7fffffff
    if r.random() < 0.15:
        h = 0                   # zero header: the sign test boundary
    e.w32(p - 8, h)
    words = [h, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    if r.random() < 0.3:
        x = 0
        for w in words:
            x ^= w
        words[-1] ^= x          # make the six-word xor zero
    e.w32(p - 0xc, words[1])
    e.w32(p - 0x14, words[2])
    e.w32(p - 0x18, words[3])
    e.w32(p - 0x1c, words[4])
    e.w32(p - 0x20, 0)
    return [0, p]


S(0x41f190, 'Fix41f190 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch893 (band slice)')
