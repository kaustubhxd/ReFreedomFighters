"""specs_s4147.py - unclaimed-41 batch 47 (core-todo residue-19): 0x515b70 ZVehicle::Save(ZSaveGame*) (thiscall, one stack argument s, ret 4;
returns al). The base save 0x513ff0 is a stub returning al (true one time in four is 0; the function returns 0 then). s: a 0x40-byte object
whose vtable slots 0x10, 0x3c, 0x4c, 0x64, 0x68, 0x70 are checksum stubs (callee pops). this: 0x400 random bytes, so every field read is
defined. Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    s513, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=1 if c.rng.random() < 0.75 else 0)
    import serial_stubs as ss
    ss.patch(c, 0x513ff0, s513)
    vt = c.emu.alloc(0x800, 4)
    slots = {0x10: 2, 0x3c: 1, 0x4c: 1, 0x64: 1, 0x68: 1, 0x70: 1}
    for off, n in slots.items():
        st, _, _ = hs.stub(c, n, ecx=True, edx=False, mask=list(range(1, n + 1)), cleanup=True, ret=0)
        c.emu.w32(vt + off, st)
    s = _rnd(c, 0x40)
    c.emu.w32(s, vt)
    self_ = _rnd(c, 0x400)
    return [self_, s]


S(0x515b70, 'ZVehicle::Save(ZSaveGame*)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 47; the base save 0x513ff0 and the save-object slots are stubs (GUESS); the /GS cookie check does not apply')
