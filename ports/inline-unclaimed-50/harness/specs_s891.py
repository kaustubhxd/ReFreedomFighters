"""specs_s891.py - gap-band slice, batch 891: 0x41e650 (GUESS name InBlock41e650), thiscall, one stack arg (pointer), ret 4, bool.
The block base is at this+0x1c5d (zero is drawn too); its header word (base-8) carries a size in the low 29 bits. The probe pointer
is drawn below, inside, at the end and past the block, so every branch runs."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x2000)
    a = rnd(c, 0x200)
    base = a + 8
    size = r.choice([0, 1, 0x10, 0x40, 0x100, r.randint(0, 0x1ff)])
    hdr = (size & 0x1fffffff) | (r.getrandbits(32) & 0xe0000000)
    e.w32(base - 8, hdr)
    if r.random() < 0.1:
        base = 0
    e.w32(self + 0x1c5d, base)
    cands = [base - 1, base, base + 4, base + size - 1, base + size, base + size + 3, 0, 0xffffffff, r.getrandbits(32)]
    p = r.choice(cands) & 0xffffffff
    return [self, p]


S(0x41e650, 'InBlock41e650 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch891 (band slice)')
