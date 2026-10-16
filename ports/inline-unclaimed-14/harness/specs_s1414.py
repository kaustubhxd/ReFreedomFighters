"""specs_s1414.py - unclaimed-14 batch 14 (residue 13): BasicShape::Save (0x460c10, thiscall, one stack argument, ret 4,
returns al = 1). The pointer at +0xc is null in about 1 case in 3. The CRT free wrapper 0x634273 (cdecl, size 0x38) is
replaced by a plain-ret stub that accumulates its two arguments (helper_stubs.stub with cleanup=False); the caller pops."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    s, _, _ = hs.stub(c, 2, ecx=False, edx=False, cleanup=False)
    ss.patch(c, 0x634273, s)
    o = _rnd(c, 0x100)
    p = _rnd(c, 0x80) if c.rng.random() < 0.7 else 0
    c.emu.w32(o + 0xc, p)
    return [o, _rnd(c, 0x40)]


S(0x460c10, 'BasicShape::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-14 batch 14 (residue 13); CRT free 0x634273 is a checksum stub (cdecl)')
