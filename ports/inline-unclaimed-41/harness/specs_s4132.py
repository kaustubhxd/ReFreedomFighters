"""specs_s4132.py - unclaimed-41 batch 32 (core-todo residue-19): 0x43abb0 ZInputActions::ActivateMap(const char*) (thiscall, one stack
argument p, ret 4; ecx is not read). p is a random 0x40-byte object one time in six null. Faulting cases must be 0 (JSON)."""
from pilot import S


def _layout(c):
    ecx = c.emu.alloc(0x40, 4)
    c.emu.wbytes(ecx, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    if c.rng.random() < 1 / 6:
        p = 0
    else:
        p = c.emu.alloc(0x40, 4)
        c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [ecx, p]


S(0x43abb0, 'ZInputActions::ActivateMap(const char*)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 32; ecx is not read; the object clears a dword and two bytes; the /GS cookie check does not apply')
