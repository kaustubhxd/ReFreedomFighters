"""specs_s8030.py - residue 18 unported list (docs/20-unclaimed-79.md). Each function gets its own random object.
Helper 0x61f590 is cdecl and stubbed (logs its argument, pops nothing); stack-pointer logs are not used here."""
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

def _g638ce0(c):
    return [_obj(c, 0x40)]

def _g64b160(c):
    return [_obj(c, 0x10)]

def _g64fc60(c):
    return [_obj(c, 0x100)]

def _g446d60(c):
    return [_obj(c, 0x40), c.rng.getrandbits(32)]

def _g5f3fa0(c):
    def h(e, r):
        e.calllog.append(("slot 28", e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("VtP30", 0x200, {0x28: h})
    c.emu.w32(o, vt)
    return [o]

def _g61bbe0(c):
    rv = c.rng.getrandbits(32)
    def h(e, r):
        e.calllog.append(("helper 61f590", e.arg32(0)))
        e.ret(eax=rv, argbytes=0)
    ss.patch(c, 0x61f590, c.emu.stub_fn("helper 61f590", h))
    return [_obj(c, 0x10)]

def _g594fa0(c):
    return [_obj(c, 0x900), c.rng.getrandbits(32)]

S(0x638ce0, '(GUESS) 0x638ce0 getter +0x20', 'thiscall', None, ret='eax', gen=_g638ce0,
  note='residue 18 unported: returns this+0x20')
S(0x64b160, '(GUESS) 0x64b160 constant 0x20', 'thiscall', None, ret='eax', gen=_g64b160,
  note='residue 18 unported: returns 0x20')
S(0x64fc60, '(GUESS) 0x64fc60 getter +0x88', 'thiscall', None, ret='eax', gen=_g64fc60,
  note='residue 18 unported: returns this+0x88')
S(0x446d60, '(GUESS) 0x446d60 store arg at +0x1c', 'thiscall', None, ret=None, gen=_g446d60,
  note='residue 18 unported: stores its argument at this+0x1c')
S(0x5f3fa0, '(GUESS) 0x5f3fa0 stdcall slot 0x28', 'stdcall', None, ret=None, gen=_g5f3fa0,
  note='residue 18 unported: stdcall, calls slot +0x28 of its argument')
S(0x61bbe0, '(GUESS) 0x61bbe0 cdecl helper 61f590', 'thiscall', None, ret='eax', gen=_g61bbe0,
  note='residue 18 unported: calls 0x61f590 (stubbed) with this+4, returns its eax')
S(0x594fa0, '(GUESS) 0x594fa0 store byte at +0x828', 'thiscall', None, ret=None, gen=_g594fa0,
  note='residue 18 unported: stores its byte argument at this+0x828')
