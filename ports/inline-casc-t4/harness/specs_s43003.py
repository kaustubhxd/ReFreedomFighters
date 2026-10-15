"""specs_s43003.py - t4 (Sonnet) batch 43003. 0x46f600 / 0x5ddea0: stream readers 0x4e5e80 (float in st0), 0x4e5e60 (eax), 0x4e6180 (writes floats) hooked;
0x5496e0: object with a count word at +0xc, pointer at this+0x5d (unaligned)."""
import struct
import math
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _g46f600(c):
    clear_hooks(c)
    r = c.rng
    vals = [_fl(r) for _ in range(2)]
    hook_rec(c, 0x4e5e80, 0, this='mark', st0=lambda em, k: vals[0])
    hook_rec(c, 0x4e5e60, 0, this='mark', ret=lambda em, k: r.choice([0, 1, 2, _w(c), 0x100]))
    s40 = pystub(c, 1, this=True, deref={0: 1})
    s50 = pystub(c, 1, this=True, deref={0: 1})
    a = obj(c, 0x80, {0x40: s40, 0x50: s50})
    return [rnd(c, 0x80), a]


def _g5ddea0(c):
    clear_hooks(c)
    r = c.rng
    vals = [_fl(r) for _ in range(3)]
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: vals[k % 3])

    def fill(em, k):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, _fb(_fl(r)))
    hook_rec(c, 0x4e6180, 1, this=True, side=fill)
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _g5496e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    m = r.choice([0, 1, 100, 1000, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32), r.randrange(0, 5000)])
    e.w32(o + 0xc, m)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x5d, o.to_bytes(4, 'little'))
    n = r.choice([0, -1, 1, 5, -5, 100, -100, 0x7fffffff, -0x80000000, r.randrange(-3000, 3000), r.randrange(-2**31, 2**31)])
    return [me, n & 0xffffffff]


S(0x46f600, 'GUESS read two pointers via vcalls then stream float and flags', 'thiscall', None, ret='al', gen=_g46f600, note='batch43003')
S(0x5ddea0, 'GUESS read floats and scale three by constant', 'thiscall', None, ret=None, gen=_g5ddea0, note='batch43003')
S(0x5496e0, 'GUESS scale count by fixed-point factor', 'thiscall', None, ret='eax', gen=_g5496e0, note='batch43003')
