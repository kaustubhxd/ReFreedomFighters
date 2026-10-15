"""specs_s993.py - residue-11, batch 993: ZActionChamberItem::Save (0x486f30). The save object's slots (0x4c float, 0x60, 0x3c) are counting
stubs; the free hook at 0x7003b0 is a counting stub (a null hook would be an int3 in the exe, so the spec always sets one). The index
[this+0x28] is picked to equal one of the six indices or to match none (the hook path), or to be zero."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    s = obj(c, 0x40, {0x4c: _stub(c, 1), 0x60: _stub(c, 1), 0x3c: _stub(c, 1)})
    t = obj(c, 0x80)
    vals = [r32(c) for _ in range(6)]
    for off, v in zip((0x10, 0x14, 0x18, 0x1c, 0x20, 0x24), vals):
        c.emu.w32(t + off, v)
    c.emu.w32(t + 0x2c, rf(c, -5, 5))
    pick = c.rng.choice([0, 1, 2, 3, 4, 5, 6])
    e = 0 if pick == 0 else (vals[pick - 1] if pick <= 6 else r32(c))
    c.emu.w32(t + 0x28, e if c.rng.random() < 0.9 else r32(c))
    return [t, s]


S(0x486f30, 'ZActionChamberItem::Save', 'thiscall', gen=g)
