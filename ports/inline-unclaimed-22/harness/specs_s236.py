"""specs_s236.py - area 59, batch236 (src/batch236.cpp): 0x5477a0. The callee 0x43e920 builds a local (its address is a
stack address, so it is not logged): the stub stores only its argument (the destination), which is a heap address, and
returns 0 with ret 4."""
import struct
from pilot import S, F
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


def _g_5477a0(c):
    self_ = _rnd(c, 0x40)
    B0 = _rnd(c, 0x400)
    c.emu.w32(self_ + 0xf, B0)
    P = _rnd(c, 0x20)
    Q = _rnd(c, 0x20)
    R = _rnd(c, 0x20)
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    # 0x43e920 stand-in: mov eax,[esp+4]; mov [slot],eax; xor eax,eax; ret 4
    jmp_patch(c, 0x43e920, ss.code(c, b'\x8b\x44\x24\x04\xa3' + ss.P(slot) + b'\x31\xc0\xc2\x04\x00'))
    _flush_heap_code(c)
    return [self_, c.rng.randrange(0, 6), P, Q, F(c.rng.uniform(-10.0, 10.0)), R]


S(0x5477a0, 'setRow (GUESS)', 'thiscall', None, ret=None, gen=_g_5477a0,
  note='batch236; table row at this[+0xf] + a1 * 0x34; 0x43e920 stubbed (stores its argument)')
