"""specs_s66001.py - cascade s4 batch 66001: 0x5e93f0 (erase one entry of an inline table of (key, value) pairs)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g5e93f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = e.alloc(0x100, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x100)))
    count = r.choice([0, 1, 2, 3, 5, 8])
    e.w32(t + 0x48, count)
    keys = []
    for i in range(count):
        k = r.choice([0, 0, 1, 2, 3, 0x80000000, r.getrandbits(32)])
        keys.append(k)
        e.w32(t + 0x4c + 8 * i, k)
        e.w32(t + 0x50 + 8 * i, r.getrandbits(32))
    flag = r.choice([0, 1, 1, 0x100, 0x101])
    val = r.choice(keys + [5, 7]) if keys else 5
    return [t, val, flag]


S(0x5e93f0, 'GUESS erase one entry of an inline (key, value) table', 'thiscall', None, ret=None, gen=_g5e93f0, note='batch66001')
