"""specs_s210041.py - Sonnet-w3a: UTF-16 class scanners, pool free with callbacks, pool alloc with callbacks; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _scan(le):
    def g(c):
        clear_hooks(c)
        base = rnd(c, 0x180)
        c.emu.wbytes(base + 0x4c, bytes(c.rng.choice([0x19, 0x19, 0x19, 0x12, 0x00, 0x18, 0x1a]) for _ in range(256)))
        L = c.rng.choice([0, 1, 2, 3, 4])
        buf = rnd(c, 0x40)
        pairs = []
        for _ in range(0x10):
            z = c.rng.random()
            lo = c.rng.choice([0, 0, 0x41, 0x78, 0x20, 0xff]); hi = c.rng.choice([0, 0, 0x78, 0x41, 0x12, 0x19])
            pairs += [lo, hi]
        if c.rng.random() < 0.3:
            pairs[0:2] = ([0, 0x78] if le else [0x78, 0]) 
        c.emu.wbytes(buf, bytes(pairs))
        hook_rec(c, 0x6279e0 if le else 0x629a40, 4, ret=_r(c), pop=0)
        hook_rec(c, 0x62c640, 2, ret=lambda e, k: c.rng.choice([0x19, 0x19, 0x12, 0x18, 0]), pop=0)
        return [base, buf, buf + 2 * L, rnd(c, 8)]
    return g


def g62ee40(c):
    clear_hooks(c)
    r = c.rng.random()
    if r < 0.1: return [0]
    A = rnd(c, 0x40)
    rec = rnd(c, 0x50)
    c.emu.w32(rec + 4, c.rng.choice([0x2a, 0x71, 0x29a, 0x70, 0]))
    for off in (8, 0x3c, 0x38, 0x30):
        c.emu.w32(rec + off, 0 if c.rng.random() < 0.4 else _r(c))
    c.emu.w32(A + 0x1c, 0 if r < 0.2 else rec)
    c.emu.w32(A + 0x24, pystub(c, 2, ret=_r(c), pop=0))
    c.emu.w32(A + 0x28, _r(c))
    return [A]


def g632230(c):
    clear_hooks(c)
    A = rnd(c, 0x40)
    a_ok = c.rng.random()
    outs = [rnd(c, 0x80), rnd(c, 0x40), rnd(c, 0x40)]
    pattern = c.rng.choice([(1, 1, 1), (1, 1, 1), (0, 0, 0), (1, 0, 0), (1, 1, 0)])

    def alloc(e, k):
        return outs[k] if pattern[min(k, 2)] else 0
    c.emu.w32(A + 0x20, pystub(c, 3, ret=alloc, pop=0))
    c.emu.w32(A + 0x24, pystub(c, 2, ret=_r(c), pop=0))
    c.emu.w32(A + 0x28, _r(c))
    hook_rec(c, 0x6322e0, 3, ret=_r(c), pop=0)
    return [A, _r(c), c.rng.choice([0, 1, 8, 0x20])]


S(0x627470, 'utf16_scanner_le', 'cdecl', None, ret='eax', gen=_scan(True), note='batch210041')
S(0x6294d0, 'utf16_scanner_be', 'cdecl', None, ret='eax', gen=_scan(False), note='batch210041')
S(0x62ee40, 'free_record_callbacks', 'stdcall', None, ret='eax', gen=g62ee40, note='batch210041')
S(0x632230, 'alloc_record_callbacks', 'cdecl', None, ret='eax', gen=g632230, note='batch210041')
