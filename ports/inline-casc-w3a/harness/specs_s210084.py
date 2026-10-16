"""specs_s210084.py - Sonnet-w3a: 0x635380. The 78-entry table (byte + packed string pointer) at 0x6f5728 is written by the spec over a small pool of strings; the string-compare import at IAT 0x676414 returns the real comparison."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g635380(c):
    clear_hooks(c)
    e = c.emu
    pool = []
    for _ in range(5):
        p = rnd(c, 0x10)
        e.wbytes(p, bytes(c.rng.choice(b'abc') for _ in range(c.rng.choice([0, 1, 2]))) + b'\0')
        pool.append(p)

    def sc(emu, k):
        x = emu.rbytes(emu.arg32(0), 4).split(b'\0')[0]
        y = emu.rbytes(emu.arg32(1), 4).split(b'\0')[0]
        return ((x > y) - (x < y)) & 0xffffffff
    e.w32(0x676414, pystub(c, 2, ret=sc, pop=0))
    other = rnd(c, 0x10); e.wbytes(other, b'zz\0')
    key = rnd(c, 0x10)
    e.wbytes(key, bytes(c.rng.choice(b'abc') for _ in range(c.rng.choice([0, 1, 2]))) + b'\0')
    single = c.rng.random() < 0.5
    k = c.rng.choice([0, 1, 76, 77, c.rng.randrange(78)])
    mp = rnd(c, 0x10); e.wbytes(mp, e.rbytes(key, 4))
    for i in range(78):
        ptr = (mp if i == k else other) if single else c.rng.choice(pool)
        e.wbytes(0x6f5728 + 5 * i, bytes([c.rng.randrange(1, 256)]) + ptr.to_bytes(4, 'little'))
    if not single and c.rng.random() < 0.7:
        e.wbytes(key, e.rbytes(c.rng.choice(pool), 4))
    return [key]


S(0x635380, 'lookup_key_char', 'stdcall', None, ret='al', gen=g635380, note='batch210084')
