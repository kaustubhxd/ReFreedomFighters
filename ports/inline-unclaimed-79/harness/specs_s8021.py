"""specs_s8021.py - unclaimed-79 resumed parked row (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss

def _g(c):
    # 0x41e290 is cdecl with one argument: returns a fresh 16-byte block or 0; the caller pops 4
    def h(e, r):
        n = e.arg32(0)
        if c.rng.random() < 0.2:
            p = 0
        else:
            p = c.emu.alloc(16, 4)
            c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(16)))
        e.calllog.append(("alloc 41e290", n))
        e.ret(eax=p, argbytes=0)
    ss.patch(c, 0x41e290, c.emu.stub_fn("alloc 41e290", h))
    return []

S(0x48a440, '(GUESS) 0x48a440 allocate, construct, vtable', 'cdecl', None, ret='eax', gen=_g,
  note='unclaimed-79 resumed parked row: 0x41e290(0xc) allocator stubbed; 0x4e6680 and vtable 0x68d468')
