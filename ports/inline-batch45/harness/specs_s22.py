"""specs_s22.py - inline session batch 22 (Haiku, overnight): 0x48db70, 0x485ca0, 0x485e30."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x48db70 thiscall: object words at +4, +8, +0xc, +0x10. The top two bits of +4 are chosen to hit each branch.
def _decode(c):
    r = c.rng
    obj = _rnd(c, 0x20)
    top = r.choice([0x00000000, 0x40000000, 0x80000000, 0xc0000000])
    low = r.getrandbits(30) if r.random() < 0.7 else r.choice([8, 0x2000000, 0])
    c.emu.w32(obj + 4, top | low)
    if r.random() < 0.3:
        c.emu.w32(obj + 8, (top | low) & 0x3fffffff if r.random() < 0.5 else r.getrandbits(32))
    else:
        c.emu.w32(obj + 8, r.randint(0, 0x40000000))
    return [obj]


S(0x48db70, 'decodeSlot (unknown) thiscall', 'thiscall', None, ret='eax', gen=_decode,
  note='batch22; top two bits of this+4 select the field; zero difference returns 0')


# 0x485ca0 thiscall, nine dword args: a record constructor. The stores are at +4 .. +0x24 with a5/a6 swapped.
def _rec9(c):
    obj = _rnd(c, 0x40)
    return [obj] + [c.rng.getrandbits(32) for _ in range(9)]


S(0x485ca0, 'initRec9 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_rec9,
  note='batch22; nine stack args stored with a5 and a6 swapped; vtable word 0x68cd8c')


# 0x485e30 thiscall, ten dword args: a record constructor. The stores are at +4 .. +0x28 with a7 and a8 swapped.
def _rec10(c):
    obj = _rnd(c, 0x40)
    return [obj] + [c.rng.getrandbits(32) for _ in range(10)]


S(0x485e30, 'initRec10 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_rec10,
  note='batch22; ten stack args stored with a7 and a8 swapped; vtable word 0x68cd3c')
