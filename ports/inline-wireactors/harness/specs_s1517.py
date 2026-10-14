"""specs_s1517.py - recruits thread batch 1517: the two bit-table helpers (GUESS names) used by the save-mission code.
Plain exe code, no callees. The table object has random group counts (0..40, so the >32-bit wrap is covered) and
random words."""
from pilot import S
from recruits_util import rnd


def _gen(c):
    r = c.rng
    e = c.emu
    t = rnd(c, 0x200)
    # words first: the word area (0x76..) overlaps the count area (0xb2..), so the counts are written last
    for idx in range(0x40):
        e.w32(t + 0x76 + 4 * idx, r.getrandbits(32) if r.random() < 0.7 else 0xffffffff)
    for k in range(5):
        e.w32(t + 0xb2 + 4 * k, r.choice([0, r.randint(1, 8), r.randint(1, 40)]))
    return [t, r.randint(0, 4), r.randint(0, 3)]


S(0x5ad6c0, 'bit-table count of a group (GUESS, 0x5ad6c0)', 'thiscall', ret='eax', gen=_gen, note='batch1517')
S(0x5ad640, 'bit-table all-set of a group (GUESS, 0x5ad640)', 'thiscall', ret='al', gen=_gen, note='batch1517')
