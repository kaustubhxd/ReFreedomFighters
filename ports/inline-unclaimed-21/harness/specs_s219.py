"""specs_s219.py - core residue 0: 0x460c80 (batch219). The release 0x634273 is stubbed: it stores its two cdecl words."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _dtor_obj(c):
    obj = _rnd(c, 0x40)
    cell_p, cell_n = c.emu.alloc(4, 4), c.emu.alloc(4, 4)
    c.emu.w32(cell_p, 0)
    c.emu.w32(cell_n, 0)
    # cdecl: [esp+4] = pointer, [esp+8] = size
    ss.patch(c, 0x634273, ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + struct.pack('<I', cell_p)
                                  + b'\x8b\x44\x24\x08' + b'\xa3' + struct.pack('<I', cell_n) + b'\xc3'))
    _flush(c)
    return [obj, c.rng.getrandbits(32)]


S(0x460c80, 'ZLnkActionDtor (GUESS)', 'thiscall', None, ret='eax', gen=_dtor_obj,
  note='batch219; vtable 0x685294; release 0x634273(this, 8) when flags & 1')
