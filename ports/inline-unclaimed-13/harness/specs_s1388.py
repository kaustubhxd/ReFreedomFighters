"""specs_s1388.py - unclaimed-13 claim 7 (docs/20-unclaimed-13.md): ZItem::CorrectOwnerDrawMatrix (0x46d400, thiscall,
ret 0xc). The object is 0x800 random bytes with +8 pointing to a 0x100-byte random float block. Its vtable: slot +0x2dc
returns either 0 or a second object P (whose +8 is also a float block), slot +0x8c records its argument, slot +0x84 counts
calls (it takes v as one argument, pushed by the original before the call). These three slots are STUBS (not verified); the helpers 0x441970, 0x4419f0 (via 0x4de480), 0x4dfd10, 0x441940,
0x4e0830, 0x4e0d80 and 0x43e960 run as original code. Mode is 0xb one time in three (that path runs the tail)."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _cord(c):
    rec = c.emu.alloc(0x10, 4)
    a = rec.to_bytes(4, 'little')
    # slot +0x8c (thiscall, one argument): mov eax,[esp+4]; mov [rec],eax; ret 4
    s8c = b'\x8b\x44\x24\x04' + b'\xa3' + a + b'\xc2\x04\x00'
    # slot +0x84 (thiscall, one stack argument, callee cleans): inc dword [rec+4]; ret 4
    s84 = b'\xff\x05' + (rec + 4).to_bytes(4, 'little') + b'\xc2\x04\x00'
    # slot +0x2dc: mov eax, imm32; ret
    o = _rnd(c, 0x800)
    q = _rnd(c, 0x100)
    c.emu.w32(o + 8, q)
    if c.rng.random() < 0.5:
        p = _rnd(c, 0x800)
        c.emu.w32(p + 8, _rnd(c, 0x100))
        target = p
    else:
        target = 0
    s2dc = _stub(c, b'\xb8' + target.to_bytes(4, 'little') + b'\xc3')
    vt = c.emu.alloc(0x300, 4)
    c.emu.w32(vt + 0x2dc, s2dc)
    c.emu.w32(vt + 0x8c, _stub(c, s8c))
    c.emu.w32(vt + 0x84, _stub(c, s84))
    c.emu.w32(o, vt)
    m = _rnd(c, 0x40)
    v = _rnd(c, 0x40)
    mode = 0xb if c.rng.random() < 1 / 3 else c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()   # translation flush: the stubs above were written into memory that may hold old code
    return [o, m, v, mode]


S(0x46d400, 'ZItem::CorrectOwnerDrawMatrix (unknown) thiscall', 'thiscall', None, ret=None, gen=_cord,
  note='unclaimed-13 claim 7; slot +0x2dc/+0x8c/+0x84 are stubs; helpers are original code')
