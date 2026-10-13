"""specs_u69_68.py - area 69, group 68 (slice 8): 0x605ac0, a case-insensitive search. The byte compare 0x4cc4b0 is real code (pure).
The bytes come from a small alphabet with both cases, so matches and misses (and empty ranges) are common."""
from pilot import S
from ckit import rnd

_ALPHA = b'aAbBzZ09_-x'


def _srch(c):
    e = c.emu
    r = c.rng
    L2 = r.choice([0, 1, 3, 8, 16])
    L1 = r.choice([0, 1, 2, 5, 12])
    pos2 = rnd(c, L2 + 8)
    s1 = rnd(c, L1 + 8)
    e.wbytes(pos2, bytes(r.choice(_ALPHA) for _ in range(L2)) + bytes(8))
    e.wbytes(s1, bytes(r.choice(_ALPHA) for _ in range(L1)) + bytes(8))
    return [pos2, pos2 + L2, s1, s1 + L1, r.getrandbits(32)]


S(0x605ac0, 'search605ac0 (fastcall, two regs, three stack args, ret 0xc)', 'fastcall', None, ret='eax', gen=_srch,
  note='u69 group 68; 0x4cc4b0 runs as real code (pure, fastcall cl/dl)')
