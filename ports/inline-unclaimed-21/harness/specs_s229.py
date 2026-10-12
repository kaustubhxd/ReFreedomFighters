"""specs_s229.py - small leaves, slice 0/1 (batch229). The object's vtable slots 0x48 and 0x40 write through their out
pointer (count, item); the render-manager child's slot 0x58 logs its argument and returns a fixed value. fastcall(this, arr)."""
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


def _out_stub(c, val):
    """thiscall, one out pointer (ret 4): writes val through it."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\xc7\x02' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x04\x00')


def _gen(c):
    cnt = c.rng.choice([0, 1, 2, 3])
    x = c.rng.getrandbits(32)
    self_ = ss.mkobj(c, {0x48: _out_stub(c, cnt), 0x40: _out_stub(c, x)}, size=0x40)
    arr = _rnd(c, 0x100)
    c.emu.w32(arr, c.rng.choice([0, 1, 2]))
    rm = _rnd(c, 0x100)
    child = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=c.rng.getrandbits(32), log=True)}, size=0x40)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [self_, arr]


S(0x511bc0, 'fillFromCalls (GUESS)', 'fastcall', None, ret='eax', gen=_gen,
  note='batch229; count from vt 0x48, items from vt 0x40, child vt 0x58 into arr; returns this')
