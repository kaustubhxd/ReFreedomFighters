"""specs_s777.py - unclaimed-77 claim 7 (docs/20-unclaimed-77.md): two constant-returning leaves. Thiscall, no arguments, no
callees. The object is a random 0x40-byte block (the functions ignore it)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x40)]


S(0x614f00, 'ZDrawArray<ZPrimInstDrawEntryGC,...>::Entries (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 7; returns 0x91')
S(0x64b140, 'ZDrawArray<ZGateViewEntry,...>::Entries (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 7; returns 0x34')
