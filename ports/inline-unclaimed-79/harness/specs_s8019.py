"""specs_s8019.py - unclaimed-79 resumed parked rows (docs/20-unclaimed-79.md). Each function gets its own random object."""
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

def _stub_free(c):
    # 0x634273 is cdecl: log both pushed arguments; the caller pops
    def h(e, r):
        e.calllog.append(("heap free wrapper", e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x634273, c.emu.stub_fn("heap free wrapper", h))

def _stub_4e18e0(c):
    # 0x4e18e0 is thiscall with five stack arguments: log them, pop 20 bytes
    def h(e, r):
        e.calllog.append(("ctor 4e18e0", e.reg("ecx"), tuple(e.arg32(k) for k in range(5))))
        e.ret(eax=c.rng.getrandbits(32), argbytes=20)
    ss.patch(c, 0x4e18e0, c.emu.stub_fn("ctor 4e18e0", h))

def _g49d2c0(c):
    _stub_free(c)
    o = _obj(c, 16)
    c.emu.w32(o + 0x4, c.rng.getrandbits(32))
    c.emu.w32(o + 0x8, c.rng.getrandbits(32))
    return [o]

def _g493b60(c):
    _stub_4e18e0(c)
    return [_obj(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x49d2c0, '(GUESS) 0x49d2c0 ctor, two frees', 'thiscall', None, ret=None, gen=_g49d2c0,
  note='unclaimed-79 resumed parked row: vtable 0x68ee80, frees this+4 and this+8 via 0x634273')

S(0x493b60, '(GUESS) 0x493b60 stdcall, calls 0x4e18e0', 'stdcall', None, ret='eax', gen=_g493b60,
  note='unclaimed-79 resumed parked row: stdcall of four args, calls 0x4e18e0 (stubbed) with (a, b, c, 0, 0)')
