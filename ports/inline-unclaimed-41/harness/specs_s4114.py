"""specs_s4114.py - unclaimed-41 batch 14 (slice 13): 0x4e89d0 (stdcall, six arguments, ret 0x18).

Arguments: out (12-byte heap buffer), x (float in [-1, 20]), limit (s32 in [-2, 10]), data (0x40 bytes: data[0] is the bit width
w in 1..8, the rest random), data2 (0x200 bytes: data2[0] = w2 in 1..8), table (0x1000 bytes of random floats in [-50, 50]).
The bit reader 0x4e8b70 is original code. The error hook at 0x7003b0 is a counter stub (set in every case; the exe traps when
it is zero, not modelled). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _dec(c):
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + ss.P(hook_cnt) + b'\xc3'))
    out = _rnd(c, 0x10)
    x = _f(c, -1.0, 20.0)
    limit = c.rng.randint(-2, 10) & 0xffffffff
    data = _rnd(c, 0x40)
    c.emu.wbytes(data, bytes([c.rng.randint(1, 8)]))
    data2 = _rnd(c, 0x200)
    c.emu.wbytes(data2, bytes([c.rng.randint(1, 8)]))
    table = c.emu.alloc(0x1000, 4)
    for i in range(0x1000 // 4):
        c.emu.w32(table + 4 * i, _f(c, -50.0, 50.0))
    return [out, x, limit, data, data2, table]


S(0x4e89d0, 'fn4e89d0 (GUESS) stdcall', 'stdcall', None, ret=None, gen=_dec,
  note='unclaimed-41 batch 14; bit reader 0x4e8b70 is original code; hook is a counter stub')
