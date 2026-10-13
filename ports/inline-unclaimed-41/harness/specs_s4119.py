"""specs_s4119.py - unclaimed-41 batch 19 (slice 13): 0x4c5c50 ZFollowShape::Load(ZLoadGame*) (thiscall, one stack argument o, ret 4;
returns al = 1).

self: 0x100 random bytes. o: a 0x40-byte object whose vtable holds checksum stubs at +0x48, +0x58 and +0x68 (one argument each,
callee pops). 0x4c79f0 (the base Load, one stack argument, ecx = self) is a checksum stub (GUESS). The error hook (0x7003b0) is
a counter stub (the exe traps when it is zero). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, ret=0)
    ss.patch(c, 0x4c79f0, s)

    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + ss.P(hook_cnt) + b'\xc3'))

    vt = c.emu.alloc(0x80, 4)
    for off in (0x48, 0x58, 0x68):
        st, _, _ = hs.stub(c, 1, ecx=True, edx=False, ret=0)
        c.emu.w32(vt + off, st)
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)

    self_ = _rnd(c, 0x100)
    return [self_, o]


S(0x4c5c50, 'ZFollowShape::Load(ZLoadGame*) (vtable)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 19; 0x4c79f0 is a checksum stub (GUESS); the three vtable slots are checksum stubs (GUESS); hook set to a counter stub')
