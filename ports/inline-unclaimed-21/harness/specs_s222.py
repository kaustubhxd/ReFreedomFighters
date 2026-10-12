"""specs_s220.py - core residue 0: 0x5a5690 (batch222). 0x5a54b0 and 0x45c510 are stubbed (they log ecx / their word);
0x4690b0 runs as exe code (a bare ret)."""
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


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _init_obj(c):
    obj = _rnd(c, 0x100)
    c_this = _cell(c)
    # 0x5a54b0 (thiscall, no words): stores ecx
    ss.patch(c, 0x5a54b0, ss.code(c, b'\x89\x0d' + struct.pack('<I', c_this) + b'\xc3'))
    c_rel = _cell(c)
    # 0x45c510 (cdecl, one word): stores [esp+4]; ret
    ss.patch(c, 0x45c510, ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + struct.pack('<I', c_rel) + b'\xc3'))
    _flush(c)
    return [obj, c.rng.getrandbits(32)]


S(0x5a5690, 'initRelease5 (GUESS)', 'thiscall', None, ret='eax', gen=_init_obj,
  note='batch222; ext 0x5a54b0 (stubbed), then 0x4690b0(this, 0x8d8) or 0x45c510(this) by flags')
