"""specs_s775.py - unclaimed-77 claim 5 (docs/20-unclaimed-77.md): two leaves returning a global dword. Thiscall, no arguments,
no callees. The function ignores this; the global is in the exe's .data section, which the harness compares."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x40)]


S(0x4f1880, 'ZActionMapZWINDOWSKEYS_ALL::GetActionDefinitions (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 5; returns global 0x6e80fc')
S(0x56c800, 'ZActionMapMenuAddOn::GetActionDefinitions (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 5; returns global 0x6ec7b8')
