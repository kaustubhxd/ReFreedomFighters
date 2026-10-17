"""specs_s4163.py - unclaimed-41 batch 52 (residue 0): 0x528c80 ZTank::Save (thiscall, one stack argument s, ret 4;
returns al = 1). Linear save with loops calling helper functions and s->vt slots.
s: a 0x40-byte object whose vtable slots are checksum stubs (callee pops). this: 0x2400 random bytes to cover all field offsets.
Callees 0x516520, 0x529fa0, 0x516e20 are stubs (GUESS). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    vt = c.emu.alloc(0x800, 4)
    slots = {0x44: 1, 0x4c: 1, 0x60: 1, 0x64: 1, 0x68: 1, 0x70: 1}
    for off, n in slots.items():
        st, _, _ = hs.stub(c, n, ecx=True, edx=False, mask=list(range(1, n + 1)), cleanup=True, ret=0)
        c.emu.w32(vt + off, st)
    s = _rnd(c, 0x40)
    c.emu.w32(s, vt)
    self_ = _rnd(c, 0x2400)

    # Patch the helper callees by address
    import serial_stubs as ss
    st516520, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x516520, st516520)
    st529fa0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x529fa0, st529fa0)
    st516e20, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x516e20, st516e20)

    return [self_, s]


S(0x528c80, 'ZTank::Save (undercarriage)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 52; save-object slots and helper functions are stubs (GUESS); the /GS cookie check does not apply')
