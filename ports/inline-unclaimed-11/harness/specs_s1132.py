"""specs_s1132.py - unclaimed-11 batch 33 (gap band): 0x5a5be0 (GUESS, no name), thiscall, one float argument (ret 4).
If this+0x689 (pointer obj) is nonnull: obj byte +0x35 = 0; the float at this+0x68d += arg, and it is set to 1.0 when it is
above 1.0 (ordered); then 0x5ec2b0(obj, that float, -1) runs (stubbed: rec, two arguments); obj byte +0x35 = 1.
If obj is null nothing happens. The object is 0x100 random bytes; obj is 0x40 bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S, F


def _gen(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    if c.rng.random() < 0.2:
        c.emu.w32(o + 0x689, 0)
    else:
        obj = c.emu.alloc(0x40, 4)
        c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(o + 0x689, obj)
    near = c.rng.random() < 0.4
    field = c.rng.uniform(0.9, 1.0) if near else c.fv(-2.0, 2.0)
    delta = c.rng.uniform(0.0, 0.1) if near else c.fv(-1.5, 1.5)
    c.emu.wf32(o + 0x68d, field)
    ss.patch(c, 0x5ec2b0, ss.rec(c, 2))
    return [o, F(delta)]


S(0x5a5be0, 'GUESS (no name) fade and flag thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 33 (gap band); 0x5ec2b0 stubbed')
