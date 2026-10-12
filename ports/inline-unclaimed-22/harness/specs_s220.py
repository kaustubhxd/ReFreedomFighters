"""specs_s220.py - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1, batch220 (src/batch220.cpp).

Small bodies: one pure mask, one pointer-pair copy, and wrappers around one vtable slot each. Vtables are sparse
(one logged slot at the byte offset the function uses; see helpers22.py). 0x5003d0 is stubbed with ss.rec(c, 1, ...):
the real function is `ret 4` (one stack word), so the stub has the same stack shape.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, _sparse_vt, _ret_const, _void, _stub_5003d0


# batch220 (src/batch220.cpp)
def _g_4d2ed0(c):
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _sparse_vt(c, 0x9c, _ret_const(c), 2))
    return [obj, c.rng.getrandbits(32)]


def _g_4856d0(c):
    return [_rnd(c, 0x40)]


def _g_4cf190(c):
    self_ = _rnd(c, 0x40)
    node = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    if node:
        c.emu.w32(node + 8, c.rng.getrandbits(32))
    c.emu.w32(self_ + 8, node)
    return [self_, _rnd(c, 0x40)]


def _g_45f890(c):
    self_ = _rnd(c, 0x40)
    p = _rnd(c, 0x40) if c.rng.random() < 0.8 else 0
    if p:
        c.emu.w32(p + 8, c.rng.choice([0, c.rng.getrandbits(32)]))
    c.emu.w32(self_ + 0x10, p)
    a1 = _rnd(c, 0x40)
    c.emu.w32(a1, _sparse_vt(c, 0x68, _void, 2))
    return [self_, a1, c.rng.getrandbits(32)]


def _g_45f9d0(c):
    self_ = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    q = _rnd(c, 0x40) if c.rng.random() < 0.8 else 0
    if q:
        r = _rnd(c, 0x40)
        c.emu.w32(r + 4, c.rng.getrandbits(32))
        c.emu.w32(q + 4, r)
    c.emu.w32(p + 0x1c, q)
    c.emu.w32(self_ + 0x10, p)
    gobj = _rnd(c, 0x40)
    c.emu.w32(gobj, _sparse_vt(c, 0x60, _void, 3))
    c.emu.w32(0x7003a4, gobj)
    c.emu.mu.ctl_flush_tb()
    return [self_, _rnd(c, 0x40), c.rng.getrandbits(32)]


def _g_55bb90(c):
    self_ = _rnd(c, 0x40)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _sparse_vt(c, 0x6f0, _ret_const(c), 1))
    c.emu.w32(self_ + 0x1c, obj)
    a = _rnd(c, 0x40)
    buf = _rnd(c, 0x10)
    c.emu.w32(a + 4, c.rng.getrandbits(32))
    _stub_5003d0(c, buf)
    return [self_, a]


def _g_5080d0(c):
    self_ = _rnd(c, 0x40)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _sparse_vt(c, 0x67c, _ret_const(c), 1))
    c.emu.w32(self_ + 0x18, obj)
    a = _rnd(c, 0x40)
    buf = _rnd(c, 0x10)
    c.emu.w32(buf, c.rng.choice([0, 1, 0x80000000, c.rng.getrandbits(32)]))
    c.emu.w32(a + 4, c.rng.getrandbits(32))
    _stub_5003d0(c, buf)
    return [self_, a]


def _g_558350(c):
    self_ = _rnd(c, 0x40)
    o2 = _rnd(c, 0x40)
    c.emu.w32(o2, _sparse_vt(c, 0x2d8, _ret_const(c), 1))
    c.emu.w32(self_ + 0x1c, o2)
    rm = _rnd(c, 0x100)
    inner = _rnd(c, 0x40)
    c.emu.w32(inner, _sparse_vt(c, 0x58, _ret_const(c), 1))
    c.emu.w32(rm + 0x9b, inner)
    c.emu.w32(0x70039c, rm)
    a = _rnd(c, 0x40)
    buf = _rnd(c, 0x10)
    c.emu.w32(a + 4, c.rng.getrandbits(32))
    _stub_5003d0(c, buf)
    return [self_, a]


S(0x4d2ed0, 'vtCall9c_4d2ed0 (GUESS)', 'thiscall', None, ret='eax', gen=_g_4d2ed0,
  note='batch220; vtable 0x9c(a, 2), returns eax')
S(0x4856d0, 'clearSigns3 (GUESS)', 'thiscall', None, ret=None, gen=_g_4856d0,
  note='batch220; three dwords and 0x7fffffff')
S(0x4cf190, 'fillFromNode (GUESS)', 'thiscall', None, ret=None, gen=_g_4cf190,
  note='batch220; out[2], out[0], out[1] from node; node may be null')
S(0x45f890, 'callSlot68Gated (GUESS)', 'thiscall', None, ret=None, gen=_g_45f890,
  note='batch220; a1 vtable 0x68(a1+0x14, a2) when this->[+0x10] and its [+8] are nonzero')
S(0x45f9d0, 'callSlot60Gated (GUESS)', 'thiscall', None, ret=None, gen=_g_45f9d0,
  note='batch220; global 0x7003a4 vtable 0x60 with three stack words')
S(0x55bb90, 'slot6f0Byte (GUESS)', 'thiscall', None, ret='eax', gen=_g_55bb90,
  note='batch220; 5003d0 stub, then vtable 0x6f0 (tail jump)')
S(0x5080d0, 'slot67cFlag (GUESS)', 'thiscall', None, ret='eax', gen=_g_5080d0,
  note='batch220; 5003d0 stub, then vtable 0x67c with setne value (tail jump)')
S(0x558350, 'slot2d8Chain (GUESS)', 'thiscall', None, ret='eax', gen=_g_558350,
  note='batch220; 5003d0 stub, global 0x70039c vtable 0x58, then vtable 0x2d8 (tail jump)')
