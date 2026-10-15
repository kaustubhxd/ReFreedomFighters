"""specs_s42008.py - Sonnet t3 batch 42008. 0x5ec090: no callees. Entry array at [+0x62] (unaligned) of heap records with word fields +4/+6 (divisors, often 0), +0x28/+0x2a (cached size,
sometimes already equal to the new size); the cached pair at +0x6e/+0x72 (unaligned) sometimes equals the arguments."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g5ec090(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    w = r.choice([0, 1, 0x40, 0x100, 0x500, r.getrandbits(16), r.getrandbits(32), 0xffffffff])
    h = r.choice([0, 1, 0x40, 0x100, 0x2d0, r.getrandbits(16), r.getrandbits(32)])
    me = rnd(c, 0xc0)
    n = r.choice([0, 1, 2, 3, 5])
    arr = rnd(c, 4 * 8)
    for i in range(n):
        ent = rnd(c, 0x40)
        e.w32(arr + 4 * i, ent)
        e.wbytes(ent + 4, struct.pack('<HH', r.choice([0, 1, 4, 16, r.getrandbits(16)]), r.choice([0, 1, 3, 9, r.getrandbits(16)])))
        if r.random() < 0.4:
            e.wbytes(ent + 0x28, struct.pack('<HH', w & 0xffff, h & 0xffff))
    e.wbytes(me + 0x3e, struct.pack('<I', n))
    e.wbytes(me + 0x62, struct.pack('<I', arr))
    if r.random() < 0.3:
        e.wbytes(me + 0x6e, struct.pack('<I', w))
    if r.random() < 0.5:
        e.wbytes(me + 0x72, struct.pack('<I', h))
    return [me, w, h]


S(0x5ec090, 'GUESS update cached size and entry scale factors', 'thiscall', None, ret=None, gen=g5ec090, note='batch42008')
