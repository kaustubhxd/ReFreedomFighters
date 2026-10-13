"""specs_s8031.py - residue 18 unported list (docs/20-unclaimed-79.md). Each function gets its own random object.
Helpers are stubbed and logged; the stubs pop the stack bytes their callers push."""
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

def _stub(c, addr, name, nargs, argb, eax_fn):
    def h(e, r):
        e.calllog.append((name, e.reg("ecx"), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=eax_fn(), argbytes=argb)
    ss.patch(c, addr, c.emu.stub_fn(name, h))

def _vt(c, slot, nargs, eax_fn, tag):
    def h(e, r):
        e.calllog.append((tag, e.reg("ecx"), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=eax_fn(), argbytes=4 * nargs)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("VtS31_%x" % slot, 0x200, {slot: h})
    c.emu.w32(o, vt)
    return o

def _g64c7e0(c):
    self_ = _obj(c, 0x10080)
    table = _obj(c, 0x4000)
    c.emu.w32(self_ + 0x10071, table)
    return [self_, c.rng.getrandbits(32)]

def _g52cea0(c):
    return [_obj(c, 0x60), c.rng.getrandbits(32)]

def _g5625a0(c):
    _stub(c, 0x562440, "helper 562440", 0, 0, lambda: 0)
    _stub(c, 0x563510, "helper 563510", 1, 4, lambda: 0)
    return [_obj(c, 0x800)]

def _g4e5e60(c):
    rv = c.rng.getrandbits(32)
    _stub(c, 0x4e5f10, "helper 4e5f10", 0, 0, lambda: rv)
    _stub(c, 0x4e6420, "helper 4e6420", 0, 0, lambda: 0)
    return [_obj(c, 0x100)]

def _g6043a0(c):
    o = _vt(c, 0x8, 1, lambda: 0, "obj slot 8")
    g = _obj(c, 0x40)
    c.emu.w32(g + 0x3c, o)
    c.emu.w32(0x724278, g)
    self_ = _obj(c, 0x40)
    return [self_]

def _g4d39e0(c):
    _stub(c, 0x4d2700, "helper 4d2700", 5, 20, lambda: c.rng.getrandbits(32))
    return [_obj(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]

def _g4875e0(c):
    o = _vt(c, 0x0, 1, lambda: c.rng.getrandbits(8), "obj slot 0")
    self_ = _obj(c, 0x40)
    c.emu.w32(self_ + 0x4, c.rng.getrandbits(32))
    obj = 0 if c.rng.random() < 0.2 else o
    return [self_, obj]

S(0x64c7e0, '(GUESS) 0x64c7e0 table lookup', 'thiscall', None, ret='eax', gen=_g64c7e0,
  note='residue 18 unported: table[a & 0xfff] at this+0x10071')
S(0x52cea0, '(GUESS) 0x52cea0 store and clear', 'thiscall', None, ret='eax', gen=_g52cea0,
  note='residue 18 unported: stores its argument at +0x44, clears +0x48/+0x49, returns this')
S(0x5625a0, '(GUESS) 0x5625a0 two helpers', 'thiscall', None, ret=None, gen=_g5625a0,
  note='residue 18 unported: helpers 0x562440 and 0x563510 (stubbed) with constant 0x6a6850')
S(0x4e5e60, '(GUESS) 0x4e5e60 helper pair returns eax', 'thiscall', None, ret='eax', gen=_g4e5e60,
  note='residue 18 unported: helpers 0x4e5f10 (value) and 0x4e6420 (stubbed), returns the first')
S(0x6043a0, '(GUESS) 0x6043a0 global vcall slot 8 with word', 'thiscall', None, ret=None, gen=_g6043a0,
  note='residue 18 unported: slot +8 of [[0x724278]+0x3c] with the word at this+0x24')
S(0x4d39e0, '(GUESS) 0x4d39e0 helper with five args', 'thiscall', None, ret=None, gen=_g4d39e0,
  note='residue 18 unported: calls helper 0x4d2700 (stubbed) with (a, 2, d, b, c)')
S(0x4875e0, '(GUESS) 0x4875e0 slot 0 of argument', 'thiscall', None, ret='al', gen=_g4875e0,
  note='residue 18 unported: returns slot 0 of obj with this+4, or 1 when obj is null')
