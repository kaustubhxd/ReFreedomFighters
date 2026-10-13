"""specs_s8032.py - residue 18 unported list (docs/20-unclaimed-79.md). Each function gets its own random object.
Helpers are stubbed and logged; the cdecl wrapper 0x634273 pops nothing (the caller pops)."""
from pilot import S, F
import os, sys, struct
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _stub0(c, addr, name):
    def h(e, r):
        e.calllog.append((name, e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, addr, c.emu.stub_fn(name, h))

def _g529ca0(c):
    o = _obj(c, 0x60)
    for off in (0x8, 0x44):
        c.emu.w32(o + off, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0])
    return [o, F(c.rng.uniform(-10.0, 10.0))]

def _g4bb160(c):
    _stub0(c, 0x469870, "helper 469870")
    return [_obj(c, 0x60)]

def _g57baa0(c):
    _stub0(c, 0x564460, "helper 564460")
    return [_obj(c, 0x190)]

def _g42bf60(c):
    _stub0(c, 0x42bae0, "helper 42bae0")
    def hfree(e, r):
        e.calllog.append(("heap free 634273", e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x634273, c.emu.stub_fn("heap free 634273", hfree))
    return [_obj(c, 0x40), c.rng.getrandbits(32)]

S(0x529ca0, '(GUESS) 0x529ca0 float pair', 'thiscall', None, ret=None, gen=_g529ca0,
  note='residue 18 unported: this+0x28 and +0x2c from this+8 and this+0x44 * a')
S(0x4bb160, '(GUESS) 0x4bb160 helper then fields', 'thiscall', None, ret='eax', gen=_g4bb160,
  note='residue 18 unported: helper 0x469870 (stubbed), flags, vtable 0x692c38, zeroed fields; returns this')
S(0x57baa0, '(GUESS) 0x57baa0 helper then vtable', 'thiscall', None, ret='eax', gen=_g57baa0,
  note='residue 18 unported: helper 0x564460 (stubbed), vtable 0x6aa368, field +0x180, byte +0x86; returns this')
S(0x42bf60, '(GUESS) 0x42bf60 helper then optional free', 'thiscall', None, ret='eax', gen=_g42bf60,
  note='residue 18 unported: helper 0x42bae0 (stubbed), cdecl 0x634273(this, 0x1b71) when bit 0 is set')
