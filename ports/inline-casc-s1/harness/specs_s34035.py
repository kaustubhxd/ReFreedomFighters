"""specs_s34035.py - cascade tier E, batch 34035: 0x478700. [this+0x695] (unaligned) is null in a seventh; the record has a count at +8 (0..5, sometimes zero or negative), a table (+0xc, 16 bytes per
entry, random) and an array (+0x10, null in a seventh) whose entries are zero or non-zero at random (all-zero included); the object at the unaligned [this+0x5b2] has slot 0x228 as a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, -1, r.randint(1, 5)])
    arr = rnd(c, 0x40)
    for i in range(6):
        e.w32(arr + 4 * i, 0 if r.random() < 0.5 else (r.getrandbits(32) | 1))
    rec = rnd(c, 0x20)
    e.w32(rec + 8, n & 0xffffffff)
    e.w32(rec + 0xc, rnd(c, 0x60))
    e.w32(rec + 0x10, 0 if r.random() < 1 / 7 else arr)
    o = obj(c, 0x20, {0x228: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x240 // 4)
    me = rnd(c, 0x6e0)
    e.wbytes(me + 0x695, (0 if r.random() < 1 / 7 else rec).to_bytes(4, 'little'))
    e.wbytes(me + 0x5b2, o.to_bytes(4, 'little'))
    return [me]


S(0x478700, 'GUESS take first pending entry, remember value and result, clear it', 'thiscall', None, ret=None, gen=_g, note='batch34035')
