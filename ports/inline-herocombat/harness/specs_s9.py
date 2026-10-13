"""specs_s9.py - inline session batch 9 (Haiku, overnight): 0x46abf0, 0x4ce180, 0x613ae0, 0x439230."""
from pilot import S, f32  # noqa: F401


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x46abf0 thiscall: (this, value). Count 0..10 with values from a small pool so duplicates occur.
def _insert(c):
    r = c.rng
    o = _rnd(c, 0x8b8 + 4 * 12)
    n = r.randint(0, 10)
    c.emu.w32(o + 0x8b4, n)
    for i in range(12):
        c.emu.w32(o + 0x8b8 + 4 * i, r.randint(0, 5))
    return [o, r.randint(0, 6)]


S(0x46abf0, 'insertUnique (unknown) thiscall', 'thiscall', None, ret=None, gen=_insert,
  note='batch9; appends when absent, no capacity check in the original (count kept <= 10)')


# 0x4ce180 thiscall: (this, idx). Power-of-two size 1..16; head -1 or an index inside the size.
def _bitmap(c):
    r = c.rng
    o = _rnd(c, 0x20)
    bits = _rnd(c, 16 * 4)
    size = r.choice([1, 2, 4, 8, 16])
    c.emu.w32(o + 4, bits)
    c.emu.w32(o + 8, size)
    c.emu.w32(o + 0xc, 0xffffffff if r.random() < 0.4 else r.randrange(size))
    c.emu.w32(o + 0x10, r.getrandbits(32))
    return [o, r.getrandbits(32) if r.random() < 0.3 else r.randint(0, 40)]


S(0x4ce180, 'bitmapFreeIndex (unknown) thiscall', 'thiscall', None, ret=None, gen=_bitmap,
  note='batch9; size is a power of two so the index mask is in range')


# 0x613ae0 thiscall: (this). Field at +2 is 0xffff (returns 0) or a small index.
def _advance(c):
    r = c.rng
    o = _rnd(c, 0x200)
    c.emu.w16(o + 2, 0xffff if r.random() < 0.2 else r.randint(0, 7))
    return [o]


S(0x613ae0, 'advanceSlot (unknown) thiscall', 'thiscall', None, ret='eax', gen=_advance,
  note='batch9; returns node+0x10 or 0')


# 0x439230 stdcall: (key). Table of 0..7 entries at the exe global 0x6e48c0, terminated by a zero key.
def _table(c):
    r = c.rng
    n = r.randint(0, 7)
    for i in range(n):
        c.emu.w32(0x6e48c0 + 16 * i, r.randint(1, 5))
        c.emu.w32(0x6e48c0 + 16 * i + 4, r.getrandbits(32))
    c.emu.w32(0x6e48c0 + 16 * n, 0)
    return [r.randint(0, 6)]


S(0x439230, 'findTableSlot (unknown) stdcall', 'stdcall', None, ret='eax', gen=_table,
  note='batch9; reads and writes the exe global table at 0x6e48c0')
