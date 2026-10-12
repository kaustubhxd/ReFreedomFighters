"""specs_s2404.py - decomp area 24, batch 2404: GUESS CollectSubZoneCodes (0x5b0e30), a helper of CSaveMissions.
The missions record (count at +0x5b8, names at +8+4i, states at +0x5c0+4i) is random with the states mostly 0.
The name argument shares its first three characters with the record's names about half the time, so the match and
dedupe paths run. CSaveMissions::LevelCompleted (0x5b1000) runs as exe code on the same record."""
from pilot import S
from recruits_util import rnd, clear_hooks


PREFIXES = [b'C01', b'C00', b'C02', b'C05', b'C0X']


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = rnd(c, 0x800)
    n = r.randint(0, 9)
    e.w32(m + 0x5b8, n)
    shared = r.random() < 0.6       # half the cases use one prefix and a small letter set, so codes repeat and reach 5
    for i in range(n):
        p = b'C01' if shared else r.choice(PREFIXES)
        lo = 0x41 if not shared else 0x41
        hi = 0x48 if shared else 0x5a
        s = p + bytes([r.randint(lo, hi), r.randint(lo, hi)]) + b'\0'
        a = c.emu.alloc(len(s) + 4, 4)
        e.wbytes(a, s)
        e.w32(m + 8 + 4 * i, a)
        e.w32(m + 0x5c0 + 4 * i, 0 if r.random() < 0.8 else r.choice([1, 4]))
        e.w32(m + 0x3c0 + 4 * i, r.choice([0, 1, 1]))   # LevelCompleted's flag; zero makes the entry not completed
    q = (b'C01' if shared else r.choice(PREFIXES[:4])) + bytes([r.randint(0x41, 0x48), r.randint(0x41, 0x48)]) + b'\0'
    qa = c.emu.alloc(len(q) + 4, 4)
    c.emu.wbytes(qa, q)
    out = rnd(c, 0x20)
    return [m, qa, out]


S(0x5b0e30, 'GUESS: CSaveMissions::CollectSubZoneCodes (0x5b0e30)', 'thiscall', None, ret=None, gen=_gen, note='batch2404')
