"""specs_s314.py - unclaimed-43 batch 314: 0x5ebde0, thiscall, one stack argument (index 0..3), ret 4, returns the word at
element+0x24 (zero-extended). The object's dword at +0x62 is an array of four element pointers; each element has a random
word at +0x24."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    self_ = E.zero_obj(c, 0x100)
    arr = E.zero_obj(c, 0x40)
    for k in range(4):
        el = E.zero_obj(c, 0x40)
        c.emu.w32(arr + 4 * k, el)
        c.emu.wbytes(el + 0x24, bytes([r.getrandbits(8), r.getrandbits(8)]))
    c.emu.w32(self_ + 0x62, arr)
    idx = r.randrange(4)
    c.emu.mu.ctl_flush_tb()
    return [self_, idx]


S(0x5ebde0, 'indexed word lookup (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-43 batch 314 (leaf)')
