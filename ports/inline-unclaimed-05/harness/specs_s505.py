"""specs_s505.py - unclaimed-05 batch 5 (claim 5): ZItemWeapon::CopyDataBlock (0x46d240). The base copy and the data-block
helpers are the exe's own code; the weapon and the data block are zeroed (random pointers fault in those helpers)."""
from pilot import S


def _zeroed(c, n):
    a = c.emu.alloc(n, 16)
    c.emu.wbytes(a, bytes(n))
    return a


def _copy(c):
    return [_zeroed(c, 0x400), _zeroed(c, 0x400)]


S(0x46d240, 'ZItemWeapon::CopyDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-05 batch 5; base copy 0x43f900, field copies 0x4e12e0/0x4e11e0 with finish 0x4e1b30')
