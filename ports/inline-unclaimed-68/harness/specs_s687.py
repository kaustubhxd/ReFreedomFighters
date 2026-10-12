"""specs_s687.py - unclaimed-68 batch 7 (claim 6): 0x435eb0 (GUESS FUN_435eb0). The array at +0x10 holds logging objects whose
slot +0x10 returns a value fixed by the gen. The count at +0x1c is 0..3 (the entries at +0x10..+0x1b must not overlap it; counts above 3 are not modelled) and the index is 0..9."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _acc(c):
    o = zero_obj(c, 0x400)
    # the array at +0x10 holds 4-byte entries and the count sits at +0x1c, so the spec keeps the count to 0..3 (no overlap)
    n = c.rng.randrange(0, 4)
    c.emu.w32(o + 0x1c, n)
    for i in range(n):
        v = c.rng.getrandbits(32)
        e = logged_obj(c, 'ZArrElem%d' % i, 0x80, impl={0x10: (lambda vv: (lambda em, a: (vv, None)))(v)}, argwords={0x10: 0})
        c.emu.w32(o + 0x10 + 4 * i, e)
    idx = c.rng.randrange(0, 10)
    return [o, idx]


S(0x435eb0, 'GUESS FUN_435eb0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_acc,
  note='unclaimed-68 batch 7; GUESS name; indexed accessor, element slot +0x10')
