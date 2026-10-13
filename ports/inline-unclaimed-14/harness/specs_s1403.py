"""specs_s1403.py - unclaimed-14 batch 3 (docs/20-unclaimed-14.md): ZRelayMessage::CopyData (0x4b85f0, thiscall, one
stack argument, ret 4) and CMAINCAMERACONTROL::End (0x4fc140, thiscall, no arguments).

CopyData gets two random 0x800-byte objects. End reads the global at 0x70039c: each case writes a fresh chain there
(the global points to a 0x2000-byte object A; A+0x1907 points to object O, or is null about 1 case in 5). O's vtable
slot +0x14 is a stub that stores its argument at O+0x20 and returns (ret 4), so the call is visible in the heap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    return [_rnd(c, 0x800), _rnd(c, 0x800)]


def _end(c):
    a = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(0x70039c, a)
    if c.rng.random() < 0.2:
        c.emu.w32(a + 0x1907, 0)
    else:
        o = c.emu.alloc(0x200, 4)
        c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
        vt = c.emu.alloc(0x40, 4)
        # mov eax,[esp+4]; mov [ecx+0x20],eax; ret 4  (ecx = the object, the stub's only argument at [esp+4])
        stub = b'\x8b\x44\x24\x04\x89\x41\x20\xc2\x04\x00'
        code = c.emu.alloc(len(stub) + 16, 16)
        c.emu.wbytes(code, stub)
        c.emu.w32(vt + 0x14, code)
        c.emu.w32(o, vt)
        c.emu.w32(a + 0x1907, o)
    return [_rnd(c, 0x800)]


S(0x4b85f0, 'ZRelayMessage::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-14 batch 3; copies words +0x48,+0x4a and dword +0x4c from the argument')
S(0x4fc140, 'CMAINCAMERACONTROL::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_end,
  note='unclaimed-14 batch 3; calls [[[0x70039c]+0x1907]]+0x14 with 0x67d9e8 when the pointer is nonzero')
