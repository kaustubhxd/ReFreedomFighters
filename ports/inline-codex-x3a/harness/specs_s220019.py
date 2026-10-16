"""Focused fixed-table fixture for the MMX packing routine at 0x61ad80."""
from pilot import S
from recruits_util import rnd


def g61ad80(c):
    """Exercise both shifts, partial final groups, and the count-vs-group table-2 loop."""
    e = c.emu
    # The function decrements its loop counters before testing them, so zero is
    # intentionally excluded. Values not divisible by four expose the two
    # distinct counters used for the packed and per-record output tables.
    count = (1, 2, 3, 4, 5, 7, 8, 9, 11, 12)[c.case % 10]
    groups = (count + 3) >> 2
    src = rnd(c, groups * 0x90 + 0x20)

    # Stores must be observable even when a loop bound or the zeroing branch is
    # wrong. The fixed regions are game .data, so they participate in parity.
    e.wbytes(0x812840, bytes(c.rng.getrandbits(8) for _ in range(0x180)))
    e.wbytes(0x812940, bytes(c.rng.getrandbits(8) for _ in range(0x180)))

    # Make every high byte nonzero and varied. These are exactly the fields
    # sampled by the second (one qword per count) loop.
    for i in range(count):
        hi = ((0x19 + i * 0x35 + c.case * 0x0b) & 0xff) or 0xa5
        e.w32(src + i * 0x24 + 0x18, (hi << 24) | c.rng.getrandbits(24))

    flags = c.rng.getrandbits(32)
    if c.case & 1:
        flags |= 0x2000
    else:
        flags &= ~0x2000
    return [src, count, flags]


S(0x61ad80, 'pack61ad80', 'stdcall', None, ret=None, gen=g61ad80,
  note='batch220019; MMX byte-lane packing into fixed tables, both flag paths')
