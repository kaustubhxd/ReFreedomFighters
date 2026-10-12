"""specs_s228.py - small leaves, slices 0/1 (batch228). The argument's vtable slots (0x68, 0x64, 0x4c) log their word or
float bits; the original 0x529fa0 (thiscall, ret 4) is stubbed: it logs ecx and its word. Returns al (bool)."""
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


def _pair_obj(c):
    self_ = _rnd(c, 0x40)
    a = ss.mkobj(c, {0x68: ss.rec(c, 1, ret=0, log=True), 0x64: ss.rec(c, 1, ret=0, log=True),
                     0x4c: ss.rec(c, 1, ret=0, log=True)}, size=0x40)
    cc, cw = _cell(c), _cell(c)
    ss.patch(c, 0x529fa0, ss.code(c, b'\x89\x0d' + struct.pack('<I', cc)
                                  + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cw)
                                  + b'\xc2\x04\x00'))
    _flush(c)
    return [self_, a]


S(0x529f40, 'pushPair (GUESS)', 'thiscall', None, ret='al', gen=_pair_obj,
  note='batch228; vt 0x68/0x64/0x68/0x4c/0x4c on the argument, then 0x529fa0 (stubbed); returns al = 1')
