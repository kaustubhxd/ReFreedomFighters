"""specs_s1384.py - unclaimed-13 claim 2, batch 3 (docs/20-unclaimed-13.md).
ZFenceGate::Init (0x5c2790, fastcall, value in ecx): the global pointer at 0x7003b8 is set to a fresh 0xd00-byte object
whose count (+0xbe5) is 0..15, so the list store at +0xbe9 + 4*count stays inside it. The count is incremented.
ZMovementAction::GetAnims (0x488ba0, thiscall): the object is 0x800 random bytes; its vtable slot +0x58 is a stub
(mov eax, imm32; ret 4) returning a random value, so both the exe and the port get the same result, stored at +0x1d."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fence(c):
    g = _rnd(c, 0xd00)
    c.emu.w32(g + 0xbe5, c.rng.randint(0, 15))
    c.emu.w32(0x7003b8, g)
    return [c.rng.getrandbits(32)]


def _anim(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x80, 4)
    v = c.rng.getrandbits(32)
    code = b'\xb8' + v.to_bytes(4, 'little') + b'\xc2\x04\x00'   # mov eax, imm32; ret 4
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    c.emu.w32(vt + 0x58, stub)
    c.emu.w32(o, vt)
    return [o]


S(0x5c2790, 'ZFenceGate::Init (unknown) fastcall', 'fastcall', None, ret=None, gen=_fence,
  note='unclaimed-13 claim 2 batch 3; appends ecx to the list of the global at 0x7003b8 (GUESS)')
S(0x488ba0, 'ZMovementAction::GetAnims (unknown) thiscall', 'thiscall', None, ret='eax', gen=_anim,
  note='unclaimed-13 claim 2 batch 3; slot +0x58 with 0x68d420, result stored at +0x1d (GUESS)')
