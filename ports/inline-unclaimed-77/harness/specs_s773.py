"""specs_s773.py - unclaimed-77 claim 3 (docs/20-unclaimed-77.md): three pure leaves, thiscall, no arguments, no callees.
The object is 0x1000 random bytes, so every load lands inside it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


S(0x449540, 'ZLIGHT::LightAttributeChanged (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 3; (dword +0x18 >> 3) with low byte replaced by bit 0')
S(0x4cdd40, 'STATICREFTAB::Count (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 3; dword at +0x14')
S(0x64fc40, 'ZRenderBaseDll::GetRagdollContainer (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 3; dword at +0x38')
