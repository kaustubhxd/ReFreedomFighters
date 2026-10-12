"""specs_s8016.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
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
    # 0x634273 is cdecl (caller pops): log both pushed arguments, return with nothing popped
    def h(e, r):
        e.calllog.append(("heap free wrapper", e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x634273, c.emu.stub_fn("heap free wrapper", h))

def _g48a340(c):
    _stub_free(c)
    return [_obj(c, 0x20), c.rng.getrandbits(32)]

def _g48f6d0(c):
    _stub_free(c)
    return [c.rng.getrandbits(32)]

S(0x48a340, '(GUESS) 0x48a340 wrapper, flag bit 0 calls free', 'thiscall', None, ret='eax', gen=_g48a340,
  note='unclaimed-79 gap-band thiscall, 0x4e66a0 then conditional 0x634273(this, 0xc), returns this')

S(0x48f6d0, '(GUESS) 0x48f6d0 stdcall free wrapper', 'stdcall', None, ret=None, gen=_g48f6d0,
  note='unclaimed-79 gap-band stdcall, calls 0x634273(arg, 0x18)')
