"""specs_s1125.py - unclaimed-11 batch 26 (gap band).
0x5bf4a0 (GUESS, no name): constructor over base 0x469870 (exe, via ext); |= 0x20 at +4; dword 0 at +0x44; vtable 0x6b36bc; eax = this.
0x5a40b0 (GUESS, no name): thiscall with one pointer argument (ret 4); copies dwords at arg+0x113, +0x117, +0x11f to this+0x113, +0x117, +0x11f.
Both use the render-manager timer that the base constructor needs (set fresh per case), and the arg buffer is 0x200 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rm_setup(c):
    obj = ss.mkobj(c, {0x30: ss.rec(c, 1)}, size=0x1000)
    c.emu.wf32(obj + 0xae0, c.rng.uniform(0.0, 0.9))
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(rm + 0x40, c.rng.getrandbits(16))
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True


def _ctor(c):
    _rm_setup(c)
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [o]


def _copy(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    a = c.emu.alloc(0x200, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    return [o, a]


S(0x5bf4a0, 'GUESS (no name) constructor over base 0x469870 thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-11 batch 26 (gap band)')
S(0x5a40b0, 'GUESS (no name) copy three dwords from arg thiscall ret 4', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-11 batch 26 (gap band)')
