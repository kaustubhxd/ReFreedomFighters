"""specs_s4136.py - unclaimed-41 batch 36 (core-todo residue-19): 0x4c5cb0 ZFollowShape::Save(ZSaveGame*) (thiscall, one stack argument s,
ret 4, returns al = 1).

self: 0x100 random bytes. s: a 0x40-byte object whose vtable slots 0x44, 0x54 and 0x60 are one-argument checksum stubs (callee pops).
Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    vt = c.emu.alloc(0x400, 4)
    for off in (0x44, 0x54, 0x60):
        st, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
        c.emu.w32(vt + off, st)
    s = _rnd(c, 0x40)
    c.emu.w32(s, vt)
    self_ = _rnd(c, 0x100)
    return [self_, s]


S(0x4c5cb0, 'ZFollowShape::Save(ZSaveGame*)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 36; the save object slots 0x44, 0x54 and 0x60 are checksum stubs (GUESS); the /GS cookie check does not apply')
