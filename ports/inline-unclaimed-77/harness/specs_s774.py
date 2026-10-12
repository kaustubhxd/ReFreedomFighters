"""specs_s774.py - unclaimed-77 claim 4 (docs/20-unclaimed-77.md): two pure leaves, thiscall, no arguments, no callees.
The object is 0x1000 random bytes (0x1400 for GetTexCon, which reads +0x11a7), so every load and store lands inside it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_big(c):
    return [_rnd(c, 0x1400)]   # GetTexCon reads +0x11a7 (past 0x1000), so its object must cover it


S(0x4d7700, 'FsZip_t::useSecondaryArchive (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-77 claim 4; byte 1 at +0x21')
S(0x60d980, 'ZRenderGC::GetTexCon (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_big,
  note='unclaimed-77 claim 4; dword at +0x11a7')
