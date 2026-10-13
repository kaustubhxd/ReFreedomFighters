"""specs_s1505.py - unclaimed-15 claim 5 (docs/20-unclaimed-15.md): CEntityTracker::UpdateEntity (0x5c0a20).

The tracker is a 0x200-byte random object with a logging vtable (slot +0x98 logs its call and the entry-pointer argument,
and returns a random eax). The entry array at +0x50 holds 0x17-byte entries (random bytes). The count at +0x54 is drawn
from {-1, 0, 1, 2, 5, 8}. The key is drawn at random and planted as the first dword of one entry about 60% of the time,
so both the tail-jump path and the not-found path run."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tracker(c):
    o = _rnd(c, 0x200)
    vt = c.emu.logging_vtable('ZEntityTracker', 0x100,
                              impl={0x98: lambda e, a: (c.rng.getrandbits(32), None)},
                              argwords={0x98: 1})
    c.emu.w32(o, vt)
    count = c.rng.choice([-1, 0, 1, 2, 5, 8])
    entries = _rnd(c, 0x17 * 8 + 0x17)
    c.emu.w32(o + 0x50, entries)
    c.emu.w32(o + 0x54, count & 0xffffffff)
    key = c.rng.getrandbits(32)
    if count > 0 and c.rng.random() < 0.6:
        idx = c.rng.randrange(count)
        c.emu.w32(entries + idx * 0x17, key)
    return [o, key]


S(0x5c0a20, 'CEntityTracker::UpdateEntity (unknown) thiscall', 'thiscall', None, ret='eax', gen=_tracker,
  note='unclaimed-15 claim 5; key search over 0x17-byte entries; found -> tail to slot +0x98 with entry pointer')
