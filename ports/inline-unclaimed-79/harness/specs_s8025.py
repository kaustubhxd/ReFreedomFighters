"""specs_s8025.py - unclaimed core row (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _g(c):
    def h(e, r):
        e.calllog.append(("ctor 480980", e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x480980, c.emu.stub_fn("ctor 480980", h))
    return [_obj(c, 0x80), c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x4876e0, '(GUESS) 0x4876e0 ctor, three 0x480980 calls, SEH frame not reproduced', 'thiscall', None, ret='eax', gen=_g,
  note='unclaimed core row: vtable 0x68d018, fields a/b, calls 0x480980 (stubbed) on +0x25, +0x3d, +0x55; SEH frame not reproduced')
