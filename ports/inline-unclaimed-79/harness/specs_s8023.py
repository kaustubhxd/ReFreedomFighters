"""specs_s8023.py - unclaimed-79 unclaimed small rows (docs/20-unclaimed-79.md). Each function gets its own random object."""
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

def _g499d20(c):
    _stub_free(c)
    return [_obj(c, 0x20), c.rng.getrandbits(32)]

def _g48f4d0(c):
    _stub_free(c)
    o = _obj(c, 0xb00)
    c.emu.w32(o + 0xaec, c.rng.getrandbits(32) if c.rng.random() < 0.6 else 0)
    return [o]

def _g495920(c):
    _stub_free(c)
    def h(e, r):
        e.calllog.append(("slot 0", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    o = _obj(c, 0x20)
    for off in (0x0, 0x10):
        if c.rng.random() < 0.7:
            child = _obj(c, 0x40)
            vt = c.emu.fake_vtable("VtS23_%x" % off, 0x10, {0x0: h})
            c.emu.w32(child, vt)
            c.emu.w32(o + off, child)
        else:
            c.emu.w32(o + off, 0)
    c.emu.w32(o + 0x4, c.rng.getrandbits(32) if c.rng.random() < 0.6 else 0)
    return [o]

S(0x499d20, '(GUESS) 0x499d20 ctor, free if bit 0', 'thiscall', None, ret='eax', gen=_g499d20,
  note='unclaimed-79 unclaimed small row: vtable 0x68e9cc, frees this (0x13c) when arg bit 0')
S(0x48f4d0, '(GUESS) 0x48f4d0 free +0xaec, zero fields', 'thiscall', None, ret=None, gen=_g48f4d0,
  note='unclaimed-79 unclaimed small row: frees this+0xaec when nonzero, zeroes it and +0xae8')
S(0x495920, '(GUESS) 0x495920 free +4, slot 0 of two children', 'thiscall', None, ret=None, gen=_g495920,
  note='unclaimed-79 unclaimed small row: frees this+4 (size 1), calls slot 0 of this+0 and this+0x10 with 1')
