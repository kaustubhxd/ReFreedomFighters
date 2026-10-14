"""specs_u69_32.py - area 69, group 32 (slice 8): two unaligned block copies."""
from pilot import S
from ckit import rnd


def _cs(c):
    return [rnd(c, 0x80), rnd(c, 0x80)]


def _st(c):
    return [rnd(c, 0x8d00), rnd(c, 0x30)]


S(0x548ec0, 'copyCShatterFields (CShatter::CopyData, thiscall, one arg)', 'thiscall', None, ret=None, gen=_cs, note='u69 group 32; no callees')
S(0x5a83c0, 'copyStatsOut5a83c0 (ZOnScreenDisplay::GetStats, thiscall, one arg)', 'thiscall', None, ret=None, gen=_st, note='u69 group 32; no callees')
