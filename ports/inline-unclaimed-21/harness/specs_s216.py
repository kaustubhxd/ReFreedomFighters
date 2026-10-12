"""specs_s216.py - unclaimed area 21: 0x45fb00 (batch216). Stubs log their stack words per call through heap cells."""
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


def _lookup_obj(c):
    """The 0x58 stub of the child: logs its argument, returns r (0 or an object with a logging 0x138)."""
    rnd_obj = None
    if c.rng.random() < 0.7:
        cells = [_cell(c), _cell(c), _cell(c)]
        rnd_obj = ss.mkobj(c, {0x138: ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cells[0])
                                              + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cells[1])
                                              + b'\x8b\x54\x24\x0c' + b'\x89\x15' + struct.pack('<I', cells[2])
                                              + b'\xc2\x0c\x00')}, size=0x40)
    r = rnd_obj or 0
    child = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=r, log=True)}, size=0x40)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    return child


def _call_obj(c):
    _lookup_obj(c)
    self_ = _rnd(c, 0x40)
    a, b, cc = c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)
    _flush(c)
    return [self_, a, b, cc]


S(0x45fb00, 'lookupCall (GUESS)', 'thiscall', None, ret=None, gen=_call_obj,
  note='batch216; child vtable 0x58 with arg a, then the returned object vtable 0x138 with (b, c, this)')
