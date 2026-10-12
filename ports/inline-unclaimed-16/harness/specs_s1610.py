"""specs_s1610.py - unclaimed-16 batch 10 (docs/20-unclaimed-16.md): 0x4a0940, GUESS name CAction::Update (the map says
CAction::Initialize, which has eight arguments; this body has one). The tail target 0x4a20e0 is patched per case to a
recording stub that takes one argument, so the exe and the port reach the same stub; it is NOT verified."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _update(c):
    ss.patch(c, 0x4a20e0, ss.rec(c, 1))
    obj = _rnd(c, 0x1000)
    c.emu.wbytes(obj + 0x64, bytes([c.rng.choice([0, 1, 2, 0x80, c.rng.getrandbits(8)])]))
    p = _rnd(c, 0x100)
    q = _rnd(c, 0x100)
    c.emu.w32(q + 0x3c, c.rng.choice([0, 0x400, 0x3ff, 0x800, c.rng.getrandbits(32)]))
    c.emu.w32(p + 8, q)
    c.emu.w32(obj + 0x44, p)
    return [obj, c.rng.getrandbits(32)]


S(0x4a0940, 'CAction::Update (GUESS; map says Initialize) thiscall', 'thiscall', None, ret=None, gen=_update,
  note='unclaimed-16 b10; name GUESS; tail call 0x4a20e0 stubbed (not verified)')
