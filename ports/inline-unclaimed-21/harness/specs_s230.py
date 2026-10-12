"""specs_s230.py - small leaves, slice 0/1 (batch230). 0x5ac960 (ecx, two stack words, ret 8) and 0x5acac0 (ecx, one word,
ret 4) are stubs that store ecx and their words. The float constants come from the exe image."""
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


def _stub_960(c):
    ca, cb, cc = _cell(c), _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', ca)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cb)
                   + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cc)
                   + b'\xc2\x08\x00')


def _stub_acac0(c):
    ca, cb = _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', ca)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cb)
                   + b'\xc2\x04\x00')


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x88, c.rng.choice([0, 1, 5, 0x1e, 0x1f, 0x21]))
    for off in range(8, 0x100, 4):
        c.emu.w32(self_ + off, c.rng.randrange(0, 0x40))
    c.emu.w32(self_ + 4, 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32))
    for off in (0xa1, 0xa5, 0xa9):
        c.emu.w32(self_ + off, c.rng.getrandbits(32))
    o = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    c.emu.w32(self_ + 0xb1, o)
    c.emu.w32(self_ + 0x94, c.rng.getrandbits(32))
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x5ac960, _stub_960(c))
    ss.patch(c, 0x5acac0, _stub_acac0(c))
    _flush(c)
    return [self_]


S(0x5ef240, 'rangeUpdate (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch230; index-driven range updates via 0x5ac960 and 0x5acac0; float update from the exe constants')
