"""specs_s215.py - unclaimed area 21: 0x483780 (batch215). 0x4de420 runs as exe code (fastcall copy)."""
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


def _copy_obj(c):
    r = c.rng.getrandbits(32)
    if c.rng.random() < 0.3:
        r &= ~0xff                          # low byte zero: the early-return path
    obj = ss.mkobj(c, {0x324: ss.rec(c, 1, ret=r, log=True)}, size=0x60)
    a = _rnd(c, 0x40)                       # the destination of 0x4de420 (0x24 bytes)
    b = _rnd(c, 12)
    _flush(c)
    return [obj, a, b]


S(0x483780, 'copyIfReady (GUESS)', 'thiscall', None, ret='eax', gen=_copy_obj,
  note='batch215; vtable 0x324 gate, original 0x4de420 copy, three dwords to b, returns al=1 with eax from +0x50')
