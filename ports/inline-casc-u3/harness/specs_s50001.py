"""specs_s50001.py - u3 (Sonnet) batch 50001, tier H (integer, vectorised in the exe). 0x41eac0: container with a reftab-style vtable (slots 0x4c / 0x64) listing element records
[name ptr, ..., +8 total, +0xc counter array, +0x10 unit size]; _stricmp (IAT 0x676414) is a recorder returning nonzero until the chosen element; counter arrays are random-filled,
positions run from inside one unit to many units (the exe's 8-wide vector loop and its scalar tail) and amounts include negatives."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, reftab_vt


def _g41eac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x40)
    if r.random() < 0.05:
        e.w32(me + 0x20, 0)
        return [me, rnd(c, 0x10), r.getrandbits(32), r.getrandbits(32)]
    n = r.randrange(0, 5)
    N = r.choice([4, 5, 8, 9, 12, 17, 40, 70])
    elems = []
    for _ in range(n):
        u = r.choice([1, 2, 3, 4, 5, 10, 16, 100, r.randrange(1, 500)])
        arr = rnd(c, 4 * N + 32)
        el = rnd(c, 0x20)
        e.w32(el, rnd(c, 0x10))
        e.w32(el + 0xc, arr)
        e.w32(el + 0x10, u)
        elems.append((el, u))
    vt = reftab_vt(c, [x[0] for x in elems])
    cont = rnd(c, 0x20)
    e.w32(cont, vt)
    e.w32(me + 0x20, cont)
    hit = r.randrange(0, n + 1)
    if elems and hit < n:
        el, u = elems[hit]
    else:
        el, u = (elems[0] if elems else (0, 7))
    cmpret = [r.choice([1, -1, 5]) for _ in range(hit)] + [0]
    e.w32(0x676414, pystub(c, 2, ret=lambda em, k: cmpret[min(k, len(cmpret) - 1)] & 0xffffffff, pop=0))
    k = r.random()
    if k < 0.3:
        pos = r.randrange(0, u)
        amt = r.randrange(0, 2 * u + 1)
    elif k < 0.55:
        pos = r.randrange(0, u * (N // 2))
        amt = r.randrange(0, u * (N // 2))
    elif k < 0.75:
        pos = r.randrange(0, u * (N - 2))
        amt = r.randrange(0, u * 3)
    elif k < 0.9:
        pos = r.randrange(u, u * (N - 2) + u)
        amt = -r.randrange(0, u + 1)
    else:
        pos = r.randrange(0, u * N)
        amt = 0
    sa = amt - (1 << 32) if amt >= 1 << 31 else amt
    while (pos + sa) // u > N - 1 or pos // u > N - 1 or pos + sa < 0:   # keep both indices inside the array
        pos //= 2
        sa //= 2
    amt = sa
    return [me, rnd(c, 0x10), pos & 0xffffffff, amt & 0xffffffff]


S(0x41eac0, 'GUESS subtract amount from per-unit counters between positions', 'thiscall', None, ret=None, gen=_g41eac0, note='batch50001')
