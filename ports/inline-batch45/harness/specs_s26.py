"""specs_s26.py - inline session batch 26 (Haiku, overnight): 0x4e4960, 0x4f39a0, 0x4e4a50."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4e4960 stdcall: one node pointer. Next and prev links are other nodes or 0; +0x18 points at a holder.
def _unlink(c):
    r = c.rng
    n1 = _rnd(c, 0x40)
    n2 = _rnd(c, 0x40)
    n3 = _rnd(c, 0x40)
    holder = _rnd(c, 0x20)
    c.emu.w32(n1, n2 if r.random() < 0.7 else 0)
    c.emu.w32(n1 + 4, n3 if r.random() < 0.5 else 0)
    c.emu.w32(n1 + 0x18, holder)
    return [n1]


S(0x4e4960, 'unlinkNode (unknown) stdcall', 'stdcall', None, ret=None, gen=_unlink,
  note='batch26; relinks the neighbours; the head goes to the holder when there is no previous link')


# 0x4f39a0 thiscall, one byte argument. The object at +0x6f is a 0x60-byte record.
def _flag(c):
    r = c.rng
    obj = _rnd(c, 0x600)
    rec = _rnd(c, 0x60)
    c.emu.w32(obj + 0x6f, rec)
    c.emu.wbytes(obj + 0x5fc, bytes([r.choice([0, 1])]))
    return [obj, r.getrandbits(8)]


S(0x4f39a0, 'setFlag (unknown) thiscall', 'thiscall', None, ret=None, gen=_flag,
  note='batch26; sets or clears 0x8000 and writes 5 or 0 at +0x30 of the record at this+0x6f')


# 0x4e4a50 thiscall, two stack args: a holder whose first dword is the base, and the element e (or 0).
def _index(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    holder = c.emu.alloc(8, 4)
    blk = c.emu.alloc(0x2000, 16)
    c.emu.w32(holder, blk)
    c.emu.wbytes(blk, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    if r.random() < 0.15:
        e = 0
    else:
        e = blk + 16 * r.randint(0, 0x1f0)
    return [obj, holder, e]


S(0x4e4a50, 'setIndex (unknown) thiscall', 'thiscall', None, ret=None, gen=_index,
  note='batch26; index is (e - base) >> 4 in a word; the word at e+0xa plus one; null e gives 0')
