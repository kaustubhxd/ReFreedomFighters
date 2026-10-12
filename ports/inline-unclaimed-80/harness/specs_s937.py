"""specs_s937.py - unclaimed-80 gap row (docs/20-unclaimed-80.md): ZLNKOBJ::CheckActiveAnim (0x461980). The table at this+0x1c has four
24-byte entries; each flag byte has bit 0 set 60% of the time, and each pointer at +0x14 is a record (nonzero 80%). The index is 0..3.
0x4cc850 is a register-logging stub: it records ecx and edx, counts the call, and returns a per-case value (zero 40%)."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _regstub(c, ret):
    P = lambda v: struct.pack('<I', v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(8, 4)
    c.emu.wbytes(ring, bytes(8))
    b = (b'\x89\x0d' + P(ring)                  # mov [ring],ecx
         + b'\x89\x15' + P(ring + 4)            # mov [ring+4],edx
         + b'\xff\x05' + P(cnt)                 # inc [cnt]
         + b'\xb8' + P(ret)                     # mov eax,ret
         + b'\xc3')                             # ret (fastcall: no stack arguments)
    return ss.code(c, b)


def _chk(c):
    ss.patch(c, 0x4cc850, _regstub(c, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32)))
    table = _rnd(c, 24 * 4)
    for k in range(4):
        e = table + 24 * k
        c.emu.wbytes(e + 4, bytes([1 if c.rng.random() < 0.6 else 0]))
        if c.rng.random() < 0.8:
            p = _rnd(c, 0x60)
            c.emu.w32(e + 0x14, p)
        else:
            c.emu.w32(e + 0x14, 0)
    self_o = _rnd(c, 0x40)
    c.emu.w32(self_o + 0x1c, table)
    name = _rnd(c, 16)
    return [self_o, name, c.rng.randint(0, 3)]


S(0x461980, 'ZLNKOBJ::CheckActiveAnim (unknown) thiscall', 'thiscall', None, ret='al', gen=_chk,
  note='unclaimed-80 gap row; 0x4cc850 fastcall stub logs ecx and edx; index 0..3')
