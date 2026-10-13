"""dbread_cursor.py - shared stream-cursor stand-in for the DBREAD operators (one cursor for all of them).

Why a cursor and not a sequence per operator: the port and the original must consume the stream in the same order. A
single cursor, shared by the u32, u16 and float operators, makes a reordered read (in the port) pull a different value
into a different field, so the heap compare catches it. Separate per-operator sequences would not.

install(c, values): writes a buffer of 4-byte values (the stream) and patches the three operators to read the next
value at the shared cursor, advancing 4 bytes each call:
    0x4e5e60  DBREAD::operator unsigned int()   returns eax = dword
    0x4e5e40  DBREAD::operator unsigned short() returns ax  = low word
    0x4e5e80  DBREAD float operator             returns st0 = float bits of the dword
GetRefTab 0x4e6330 is stubbed by address and logged (not verified: its effect is not modelled).
Stubs are thiscall with no stack arguments, plain ret. The stream memory is allocated per run (setup runs once per run).
"""
import struct
from serial_stubs import patch, code, rec, P

DBREAD_U32 = 0x4e5e60
DBREAD_U16 = 0x4e5e40
DBREAD_F32 = 0x4e5e80
DBREAD_GETREFTAB = 0x4e6330


def install(c, values):
    """values: the stream content, in call order. Returns the stream buffer address. Operators past the end read zero."""
    n = len(values) + 8
    buf = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(buf, b''.join(P(v) for v in list(values) + [0] * 8))
    cur = c.emu.alloc(4, 4)
    c.emu.w32(cur, buf)
    # u32: mov eax,[cur]; mov ecx,[eax]; add dword [cur],4; mov eax,ecx; ret
    u32 = code(c, b'\xa1' + P(cur) + b'\x8b\x08' + b'\x83\x05' + P(cur) + b'\x04' + b'\x89\xc8' + b'\xc3')
    # u16: mov eax,[cur]; movzx eax, word [eax]; add dword [cur],4; ret
    u16 = code(c, b'\xa1' + P(cur) + b'\x0f\xb7\x00' + b'\x83\x05' + P(cur) + b'\x04' + b'\xc3')
    # float: mov eax,[cur]; fld dword [eax]; add dword [cur],4; ret
    f32 = code(c, b'\xa1' + P(cur) + b'\xd9\x00' + b'\x83\x05' + P(cur) + b'\x04' + b'\xc3')
    patch(c, DBREAD_U32, u32)
    patch(c, DBREAD_U16, u16)
    patch(c, DBREAD_F32, f32)
    patch(c, DBREAD_GETREFTAB, rec(c, 1, log=False))
    return buf
