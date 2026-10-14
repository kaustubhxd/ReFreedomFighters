"""specs_u69_51.py - area 69, group 51 (slice 8): 0x4ce1c0, the insert/merge companion of 0x4cda40 (no callees).
Runs are biased toward the merge cases: x + len touching an entry's start, x touching an entry's end, and the chains that absorb a
second entry. For the chains the pair is put first in the list, so the scan reaches it before any other entry."""
from pilot import S
from ckit import rnd


def _write(e, P, ents):
    for i, (st, ln) in enumerate(ents):
        e.w32(P + 8 * i, st & 0xffffffff)
        e.w32(P + 8 * i + 4, ln)


def _gen(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x10)
    P = rnd(c, 8 * 16)
    e.w32(o + 4, P)
    n = r.randrange(0, 9)
    e.w32(o + 8, n)
    ents = []
    base = r.randrange(0, 0x800)
    for i in range(n):
        start = base + r.randrange(0, 0x80)
        ln = r.randrange(1, 0x60)
        ents.append((start, ln))
        base = start + ln + r.randrange(1, 0x40)
    k = r.random()
    if n and k < 0.25:                       # MERGE_LEFT: x == some entry's end
        s, l = r.choice(ents)
        x = (s + l) & 0xffffffff
        L = r.randrange(0, 0x40)
    elif n and k < 0.5:                      # MERGE_RIGHT: x + len == some entry's start
        s, l = r.choice(ents)
        L = r.randrange(0, 0x40)
        x = (s - L) & 0xffffffff
    elif n >= 2 and k < 0.7:                 # chain for MERGE_LEFT: A ends at x, B starts at x+L; A first, then B
        a, b = r.sample(ents, 2)
        x = (a[0] + a[1]) & 0xffffffff
        L = (b[0] - x) & 0xffffffff
        if b[0] < a[0] + a[1]:
            L = r.randrange(0, 0x20)
        ents = [a, b] + [t for t in ents if t is not a and t is not b]
    elif n >= 2 and k < 0.85:                # chain for MERGE_RIGHT: S starts at x+L, T ends at x; S first, then T
        s, t = r.sample(ents, 2)
        x = (t[0] + t[1]) & 0xffffffff
        L = (s[0] - x) & 0xffffffff
        if s[0] < t[0] + t[1]:
            L = r.randrange(0, 0x20)
        ents = [s, t] + [q for q in ents if q is not s and q is not t]
    else:
        x = r.getrandbits(12)
        L = r.randrange(0, 0x60)
    _write(e, P, ents)
    return [o, x & 0xffffffff, L & 0xffffffff]


S(0x4ce1c0, 'insertRange4ce1c0 (thiscall, two args, ret 8, void)', 'thiscall', None, ret=None, gen=_gen,
  note='u69 group 51; no callees')
