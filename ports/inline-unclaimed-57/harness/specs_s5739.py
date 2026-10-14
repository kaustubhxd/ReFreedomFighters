"""specs_s5739.py - unclaimed-57, band batch 39: 0x5d7ef0 (GUESS), the record-list insert (thiscall, two stack args, ret 8; no calls).
The list count (dword at +0) is 0 to 6 and idx is 0 to 7, so both the append path (idx >= count) and the shift path (idx < count, including
idx == count - 1) run. The record is a random 12-byte block at the second argument (its first 8 bytes and dword +8 are copied). The object
is a random 0x200-byte block, and every record fits inside it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ins(c):
    obj = _rnd(c, 0x200)
    cnt = c.rng.randrange(0, 7)
    c.emu.w32(obj, cnt)
    idx = c.rng.randrange(0, 8)
    rec = _rnd(c, 0x20)
    return [obj, idx, rec]


S(0x5d7ef0, 'unnamed_5d7ef0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_ins,
  note='unclaimed-57 band batch 39; record-list insert (shift path and append path); no calls')
