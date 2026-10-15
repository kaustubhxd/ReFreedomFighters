"""specs_s41007.py - t2 (Sonnet) batch 41007: 0x457c30. Allocator 0x41e290 is a scripted recorder (two blocks), engine slot 0xf8 returns a record block or null."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g457c30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    w, h = r.choice([(0, 3), (1, 1), (2, 3), (3, 2), (5, 1), (1, 7), (4, 4), (0, 0)]), None
    a, b = w
    n = (a * b) & 0xffffffff
    blkA = rnd(c, 8)
    blkB = rnd(c, n * 0x44 + 8)
    seq = [blkA, blkB]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: seq[min(k, 1)])
    rec = rnd(c, 0x20)
    qo = obj(c, 0x20, {0xf8: pystub(c, 1, this=True, ret=rec if r.random() < 0.7 else 0)}, nslots=0xfc // 4)
    oo = rnd(c, 0x40)
    e.w32(oo + 0x18, qo)
    so = sysobj(c)
    e.w32(so + 0x1aa3, oo)
    me = rnd(c, 0xa0)
    e.w32(me + 8, rnd(c, 0x80))
    e.w32(me + 0x88, a)
    e.w32(me + 0x8c, b)
    return [me]


S(0x457c30, 'GUESS init particle buffer', 'thiscall', None, ret=None, gen=g457c30, nan_heap=True, note='batch41007')
