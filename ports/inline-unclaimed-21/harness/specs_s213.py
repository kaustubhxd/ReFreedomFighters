"""specs_s213.py - unclaimed area 21: 0x5ec5c0 (batch213). 0x4de420 runs as exe code (a fastcall copy from edx to ecx)."""
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
    obj = _rnd(c, 0x40)
    src = _rnd(c, 0x40)          # a: the struct copied by 0x4de420 (0x24 bytes), so it must be readable
    b = _rnd(c, 12)
    _flush(c)
    return [obj, src, b]


S(0x5ec5c0, 'copyVec3Flag2 (GUESS)', 'thiscall', None, ret=None, gen=_copy_obj,
  note='batch213; calls original 0x4de420 on this+4, copies 3 dwords from arg2, sets byte +0x34')
