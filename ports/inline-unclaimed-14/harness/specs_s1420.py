"""specs_s1420.py - unclaimed-14 batch 20 (residue 13): ZActionPushButton::CallBack (0x486190, thiscall, no arguments, plain
ret, returns al = 0).

Checksum stubs: this+8 object's vtable slot +0x2d0 (two stack arguments, callee pops); the helper 0x467410 (six stack
arguments, ret 0x18, ecx = this+0x10+4). The helper's effects are not modelled (GUESS), so this batch checks the calls,
the argument values (including the 0.3f constant and the four local dwords), and the return value.
Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cb(c):
    s, _, _ = hs.stub(c, 6, ecx=True, edx=False)
    ss.patch(c, 0x467410, s)
    vt = c.emu.alloc(0x400, 4)
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, ret=c.rng.getrandbits(32))
    c.emu.w32(vt + 0x2d0, s)
    obj = _rnd(c, 0x100)
    c.emu.w32(obj, vt)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 8, obj)
    c.emu.w32(self_ + 0xc, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x10, _rnd(c, 0x40))
    return [self_]


S(0x486190, 'ZActionPushButton::CallBack (unknown) thiscall', 'thiscall', None, ret='al', gen=_cb,
  note='unclaimed-14 batch 20 (residue 13); vt +0x2d0 and helper 0x467410 are checksum stubs')
