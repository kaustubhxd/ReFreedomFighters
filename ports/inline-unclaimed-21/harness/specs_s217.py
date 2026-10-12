"""specs_s217.py - unclaimed area 21: 0x461a40 (batch217). The 0x278 stub logs a, b, c and the local's middle word (never the pointer itself)."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _call_obj(c):
    cells = [_cell(c), _cell(c), _cell(c), _cell(c)]
    stub = ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cells[0])     # a
                   + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cells[1])     # b
                   + b'\x8b\x54\x24\x0c' + b'\x89\x15' + struct.pack('<I', cells[2])     # c
                   + b'\x8b\x54\x24\x10'                                  # mov edx, [esp+0x10] (the local)
                   + b'\x8b\x4a\x04'                                       # mov ecx, [edx+4]
                   + b'\x89\x0d' + struct.pack('<I', cells[3])               # mov [cell], ecx
                   + b'\xc2\x10\x00')                                       # 4 stack words (the local is the 4th)
    self_ = ss.mkobj(c, {0x278: stub}, size=0x40)
    _flush(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x461a40, 'scratchCall (GUESS)', 'thiscall', None, ret=None, gen=_call_obj,
  note='batch217; zeroes a 3-dword local, vtable 0x278 with (a, b, c, &local)')
