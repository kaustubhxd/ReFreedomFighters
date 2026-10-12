"""specs_s1917.py - unclaimed-66 batch 1917: GUESS FUN_0045ed90 and GUESS FUN_0049e0d0 (thiscall, no arguments).

0x45ed90: the object's +0x10 is null (40%) or an object with a random dword at +0x10. 0x49e0d0: the object's first dword is a
pointer to a 16-byte buffer whose first byte is random (both parities)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sub(c):
    self = _rnd(c, 0x40)
    if c.rng.random() < 0.4:
        c.emu.w32(self + 0x10, 0)
    else:
        inner = _rnd(c, 0x40)
        c.emu.w32(self + 0x10, inner)
    return [self]


def _ptr(c):
    buf = _rnd(c, 0x10)
    self = _rnd(c, 0x20)
    c.emu.w32(self, buf)
    return [self]


S(0x45ed90, 'GUESS FUN_0045ed90 (null-checked sub-object read)', 'thiscall', None, ret='eax', gen=_sub,
  note='unclaimed-66 batch 1917; slice-5 leaf (GUESS)')
S(0x49e0d0, 'GUESS FUN_0049e0d0 (low-bit pointer step)', 'thiscall', None, ret='eax', gen=_ptr,
  note='unclaimed-66 batch 1917; slice-5 leaf (GUESS); returns a constant address when the bit is clear')
