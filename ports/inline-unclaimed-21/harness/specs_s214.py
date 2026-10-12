"""specs_s214.py - unclaimed area 21: 0x5aaf60 (batch214). Entries and the lookup record are raw stubs (logged arguments)."""
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


def _entry_arr(c, n):
    """An array of n words, each 0 or a fresh entry object whose vtable slot 0x1e0 returns 0 or 1 and logs its argument."""
    arr = c.emu.alloc(4 * 4, 4)
    for k in range(4):
        v = 0
        if k < n and c.rng.random() < 0.8:
            ok = c.rng.choice([0, 1])
            v = ss.mkobj(c, {0x1e0: ss.rec(c, 1, ret=ok, log=True)}, size=0x40)
        c.emu.w32(arr + 4 * k, v)
    return arr


def _flags(c):
    self_ = _rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 3, 4])
    c.emu.w32(self_, n)
    c.emu.w32(self_ + 4, _entry_arr(c, n))
    c.emu.w32(self_ + 8, _entry_arr(c, n))
    rec = _rnd(c, 0x40)                         # lookup result: dword at +0x23 is the key passed to 0x1e0
    c.emu.w32(rec + 0x23, c.rng.getrandbits(32))
    rm = _rnd(c, 0x100)
    cell1 = c.emu.alloc(4, 4)
    cell2 = c.emu.alloc(4, 4)
    c.emu.w32(cell1, 0)
    c.emu.w32(cell2, 0)
    # 0x154 (ret 8): stores both stack words (the key and the second argument) and returns rec
    lookup = ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cell1)
                     + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cell2)
                     + b'\xb8' + struct.pack('<I', rec) + b'\xc2\x08\x00')
    obj = ss.mkobj(c, {0x154: lookup}, size=0x40)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [self_, c.rng.getrandbits(32)]


S(0x5aaf60, 'flagArrays (GUESS)', 'thiscall', None, ret=None, gen=_flags,
  note='batch214; piece of 0x5a76c0: loops over this+4 and this+8 with a lookup on the render-manager child')
