"""specs_u69_52.py - area 69, group 52 (slice 8): 0x61ad80, MMX packing into the fixed tables 0x812840 and 0x812940 (no callees).
count is 1..8 (the original loops until the counter wraps at 0). Half the runs use flags with 0x2000 set."""
from pilot import S
from ckit import rnd


def _gen(c):
    r = c.rng
    # the two tables start with random bytes, so a store that is skipped or lands in the wrong place is visible
    c.emu.wbytes(0x812840, bytes(r.getrandbits(8) for _ in range(0x100)))
    c.emu.wbytes(0x812940, bytes(r.getrandbits(8) for _ in range(0x100)))
    src = rnd(c, 0x400)
    n = r.randrange(1, 9)
    flags = (0x2000 | r.getrandbits(14)) if r.random() < 0.5 else (r.getrandbits(14) & ~0x2000)
    return [src, n, flags]


S(0x61ad80, 'pack61ad80 (stdcall, three args, ret 0xc, void)', 'stdcall', None, ret=None, gen=_gen,
  note='u69 group 52; no callees; writes the fixed tables 0x812840 and 0x812940 (compared as .data)')
