"""specs_s5702.py - unclaimed-57, batch 2: CHitpointControl::Save (0x584f40). Thiscall, one argument (the save object), returns
al = 1. The save object has a logging vtable: slots +0x4c (two calls, one argument: a float's bits) and +0x3c (one argument).
The arguments are logged, so the float bits and the dword are compared exactly."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    e = c.emu
    vt = e.logging_vtable('hitpoint_save', 32, argwords={0x4c: 1, 0x3c: 1})
    sv = _rnd(c, 0x40)
    e.w32(sv, vt)
    return [_rnd(c, 0x800), sv]


S(0x584f40, 'CHitpointControl::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-57 batch 2; save->vt[+0x4c] twice and [+0x3c] stubbed; returns 1')
