"""specs_s1910.py - unclaimed-66 batch 1910: three slice-5 leaves (GUESS names). Thiscall with stack arguments.

0x435d50: count at +0xc in 0..3 (the store path runs for 0 and 1). 0x435e90: +0x60 in 0..5 and an index that can be past it,
including large unsigned values. 0x4a8210: the word argument equals the word at +0x52 in half the cases."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _push(c):
    self = _rnd(c, 0x100)
    c.emu.w32(self + 0xc, c.rng.randint(0, 3))
    return [self, c.rng.getrandbits(32)]


def _index(c):
    self = _rnd(c, 0x100)
    c.emu.w32(self + 0x60, c.rng.randint(0, 5))
    k = c.rng.random()
    idx = c.rng.randint(0, 7) if k < 0.8 else c.rng.getrandbits(32)
    return [self, idx]


def _word(c):
    self = _rnd(c, 0x100)
    w = c.rng.getrandbits(16)
    c.emu.wbytes(self + 0x52, w.to_bytes(2, 'little'))
    arg = w | (c.rng.getrandbits(16) << 16) if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        arg = (arg & 0xffff0000) | w        # the same low word
    return [self, arg, c.rng.getrandbits(32)]


S(0x435d50, 'GUESS FUN_00435d50 (push into two slots)', 'thiscall', None, ret=None, gen=_push,
  note='unclaimed-66 batch 1910; slice-5 leaf (GUESS)')
S(0x435e90, 'GUESS FUN_00435e90 (bounded index read)', 'thiscall', None, ret='eax', gen=_index,
  note='unclaimed-66 batch 1910; slice-5 leaf (GUESS)')
S(0x4a8210, 'GUESS FUN_004a8210 (word match store)', 'thiscall', None, ret='eax', gen=_word,
  note='unclaimed-66 batch 1910; slice-5 leaf (GUESS)')
