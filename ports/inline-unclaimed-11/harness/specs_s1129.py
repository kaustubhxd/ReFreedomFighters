"""specs_s1129.py - unclaimed-11 batch 30 (gap band), two GUESS functions.
0x5bd6d0 (thiscall, ret 0): calls the base constructor 0x469870 (exe, via ext; needs the render-manager timer as in batch 25),
then |= 0x20 at +4, dword 0 at +0x44, vtable 0x6b33b4, 16 bytes of zero at +0x48, 16 bytes of zero at +0x58, zero at +0x68,
zero at +0x6c, -1 at +0x70, zero at +0x7d.
0x5a4690 (thiscall, one pointer arg, ret 4): if arg is nonnull and arg's slot 0x1e0 (a rec stub) returns true for 0x2003e8, and
arg+0x54 is nonnull, d = dword at (arg+0x54)+4 minus 3; if d is -1 or above 6 (signed) the result is null, else this+0x61+18*d."""
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


def _ptr(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    if c.rng.random() < 0.1:
        return [o, 0]
    inner = c.emu.alloc(0x40, 4)
    c.emu.wbytes(inner, bytes(0x40))
    c.emu.w32(inner + 4, c.rng.randint(-3, 10) & 0xffffffff)
    arg = ss.mkobj(c, {0x1e0: ss.rec(c, 1, ret=c.rng.choice([0, 1]))}, size=0x100)
    c.emu.w32(arg + 0x54, 0 if c.rng.random() < 0.1 else inner)
    return [o, arg]


S(0x5bd6d0, 'GUESS (no name) constructor over base 0x469870 thiscall ret 0', 'thiscall', None, ret=None, gen=_ctor,
  note='unclaimed-11 batch 30 (gap band)')
S(0x5a4690, 'GUESS (no name) indexed pointer from argument thiscall ret 4', 'thiscall', None, ret='eax', gen=_ptr,
  note='unclaimed-11 batch 30 (gap band)')
