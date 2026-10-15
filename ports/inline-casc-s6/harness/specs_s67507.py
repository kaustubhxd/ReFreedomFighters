"""specs_s67507.py - cascade s6 batch 67507 (0x61bd20, cdecl(buf, n), returns eax). The buffer record {+8 base, +0xc alloc fn, +0x14 free fn, +0x18 start, +0x1c cur, +0x20 end} lives
over a 0x2000-byte spec block (positions chosen to hit the fits / compact / grow / empty cases, with up to 0x400+ consumed history); memmove (IAT 0x676278) really moves, 0x634d22
really copies, the allocator returns 0x8000-byte spec blocks (or null), the free function is a recording stub."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, stub_memmove


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g61bd20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)

    def cp(em, k):
        d, s_, m = em.arg32(0), em.arg32(1), em.arg32(2)
        if m:
            em.wbytes(d, em.rbytes(s_, m))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    pool = [e.alloc(0x8000, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x200)))
    fail = r.random() < 0.08
    alloc = pystub(c, 1, pop=0, ret=lambda em, k: 0 if fail else pool[k % 2])
    free = pystub(c, 1, pop=0)
    s = rnd(c, 0x120)
    mode = r.random()
    if mode < 0.12:
        base = start = cur = end = 0
        n = r.choice([1, 5, 0x100, 0x500, 0x1000])
    else:
        size = 0x2000
        base = e.alloc(size, 4)
        e.wbytes(base, bytes(r.getrandbits(8) for _ in range(size)))
        hist = r.choice([0, 0x10, 0x3ff, 0x400, 0x401, 0x600, 0x900])
        used = r.choice([0, 1, 0x20, 0x100, 0x300, 0x700])
        slack = r.choice([0, 1, 0x40, 0x200, 0x400, 0x800])
        start = base + hist
        cur = start + used
        end = min(cur + slack, base + size)
        n = r.choice([-1, 0, 1, slack, slack + 1, slack + 0x10, slack + 0x300, 0x100, 0x1000, 0x1800, 0x3000])
    _w(c, s + 8, base)
    _w(c, s + 0xc, alloc)
    _w(c, s + 0x14, free)
    _w(c, s + 0x18, start)
    _w(c, s + 0x1c, cur)
    _w(c, s + 0x20, end)
    _w(c, s + 0x114, 0)
    return [s, n & 0xffffffff]


S(0x61bd20, 'GUESS buffer_reserve', 'cdecl', None, ret='eax', gen=_g61bd20, note='batch67507')
