"""specs_s1404.py - unclaimed-14 batch 4 (slice 13): ZActor::GetMoveFromPos (0x478d10, thiscall, one stack arg, ret 4).

Each case: a random 0x800-byte actor, the byte at +0x726 from {0, 1, 2}, the dword at +0x64c from {0xa, random}, and a
vtable whose slot +0x57c is a stub (two stack arguments, ret 8). The stub stores a random immediate at this+0x6f0 (a field the function never reads),
so a missing or misdirected virtual call changes the heap. The stack cookie check is not in the port (see the source)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _movefrompos(c):
    o = _rnd(c, 0x800)
    c.emu.wbytes(o + 0x726, bytes([c.rng.choice([0, 1, 2])]))
    c.emu.w32(o + 0x64c, 0xa if c.rng.random() < 0.6 else c.rng.getrandbits(32))
    imm = c.rng.getrandbits(32)
    # mov dword ptr [ecx+0x6f0], imm32 (C7 81 disp32 imm32); ret 8 (C2 08 00; the slot takes the buffer and the out pointer)
    code = b'\xc7\x81' + (0x6f0).to_bytes(4, 'little') + imm.to_bytes(4, 'little') + b'\xc2\x08\x00'
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    vt = c.emu.alloc(0x590, 4)
    c.emu.w32(vt + 0x57c, stub)
    c.emu.w32(o, vt)
    out = _rnd(c, 12)
    return [o, out]


S(0x478d10, 'ZActor::GetMoveFromPos (unknown) thiscall const', 'thiscall', None, ret=None, gen=_movefrompos,
  note='unclaimed-14 batch 4; vtable slot 0x57c is a stub writing +0x6f0; flag +0x726; +0x64c==0xa selects +0x6e6')
