"""specs_s4133.py - unclaimed-41 batch 33 (core-todo residue-19): 0x4edcb0 ZCollisionBase::LoadInternColiTree(char*) (thiscall, one stack
argument buf, ret 4; returns eax = buf + [buf]).

buf: a random 0x40-byte object whose first dword (the size) is 0..0x30. The octree constructor 0x4e3d60 is a checksum stub with ecx = buf+4
and the argument buf+0x20 (GUESS). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _layout(c):
    # the constructor stub reads the dword at ecx (buf+4, the vtable the port stores) into its checksum, so the store is compared
    acc = c.emu.alloc(4, 4)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(acc, 0)
    c.emu.w32(cnt, 0)
    b = (b'\x8b\x01'                          # mov eax, [ecx]
         + b'\x01\x05' + P(acc)               # add [acc], eax
         + b'\xff\x05' + P(cnt)               # inc [cnt]
         + b'\x31\xc0'                        # xor eax, eax
         + b'\xc2\x04\x00')                  # ret 4
    ss.patch(c, 0x4e3d60, ss.code(c, b))
    buf = c.emu.alloc(0x40, 4)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(buf, c.rng.randint(0, 0x30))
    return [buf]


S(0x4edcb0, 'ZCollisionBase::LoadInternColiTree(char*)', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 33; the octree constructor 0x4e3d60 is a checksum stub (GUESS); the /GS cookie check does not apply')
