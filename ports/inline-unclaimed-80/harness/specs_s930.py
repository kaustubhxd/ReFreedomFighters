"""specs_s930.py - unclaimed-80 claim 10 (docs/20-unclaimed-80.md): ZInputActions::GetInputNode (0x4392b0). The global list at
0x6e48c0 (stride 16) holds one to three tables, each with one to four entries (12 bytes; the first dword is the name pointer).
The compare at 0x676414 is a cdecl stub that returns zero when its two pointers are equal (so a name is found by identity) and
one otherwise. The argument is one of the entry names 60% of the time, else a new pointer. The base values at 0x6e48b8+16i are
random; the list terminators are written after the last record."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


CMP_CODE = (b'\x8b\x44\x24\x04'          # mov eax,[esp+4]
            + b'\x3b\x44\x24\x08'        # cmp eax,[esp+8]
            + b'\x0f\x95\xc0'            # setne al
            + b'\x0f\xb6\xc0'            # movzx eax,al
            + b'\xc3')                    # ret (cdecl)


def _getnode(c):
    ntab = c.rng.randint(1, 3)
    tables = []
    names = []
    for i in range(ntab):
        k = c.rng.randint(1, 4)
        t = c.emu.alloc(12 * (k + 1), 4)
        c.emu.wbytes(t, bytes(12 * (k + 1)))
        for j in range(k):
            nm = c.emu.alloc(8, 4)
            c.emu.w32(nm, c.rng.getrandbits(32))
            c.emu.w32(t + 12 * j, nm)
            names.append((i, j, nm))
        tables.append(t)
    for i, t in enumerate(tables):
        c.emu.w32(0x6e48c0 + 16 * i, t)
        c.emu.w32(0x6e48b8 + 16 * i, c.rng.getrandbits(32))
    c.emu.w32(0x6e48c0 + 16 * ntab, 0)
    stub = ss.code(c, CMP_CODE)
    c.emu.w32(0x676414, stub)
    if names and c.rng.random() < 0.6:
        arg = c.rng.choice(names)[2]
    else:
        arg = c.emu.alloc(8, 4)
        c.emu.w32(arg, c.rng.getrandbits(32))
    return [_rnd(c, 0x40), arg]


S(0x4392b0, 'ZInputActions::GetInputNode (unknown) thiscall', 'thiscall', None, ret='eax', gen=_getnode,
  note='unclaimed-80 claim 10; compare by pointer identity (stub at 0x676414); global table list at 0x6e48c0')
