"""specs_s236.py - small leaves, slice 0/1 (batch236). The argument's vtable (0x70, 0x68, 0x60, 0x44, 0x3c: one word; 0x10:
two words) logs ecx and its words into a ring of 16 records per slot. thiscall(a): ecx = this, a is the stack argument."""
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


def _ring(c, nwords, ret_bytes):
    """thiscall with nwords stack words (ret ret_bytes): appends ecx and the words to a ring of 16 records."""
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 16, 4)
    c.emu.wbytes(ring, bytes(4 * n * 16))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    body += b'\xc2' + struct.pack('<H', ret_bytes)
    return ss.code(c, body)


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0x34, bytes([c.rng.getrandbits(8)]))
    c.emu.wbytes(self_ + 0x35, bytes([c.rng.getrandbits(8)]))
    c.emu.wbytes(self_ + 0xa6, bytes([c.rng.getrandbits(8)]))
    p = _rnd(c, 0x20)                                   # [this+0x3a] -> p (p[0], p[1] are values)
    c.emu.w32(self_ + 0x3a, p)
    c.emu.w32(self_ + 0x3e, c.rng.randrange(0, 4))
    items = c.emu.alloc(4 * 4, 4)
    k = c.rng.randrange(0, 4)
    for i in range(4):
        c.emu.w32(items + 4 * i, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x62, items)
    c.emu.w32(self_ + 0x66, items + 4 * k)
    a = ss.mkobj(c, {0x70: _ring(c, 1, 4), 0x68: _ring(c, 1, 4), 0x60: _ring(c, 1, 4),
                     0x44: _ring(c, 1, 4), 0x3c: _ring(c, 1, 4), 0x10: _ring(c, 2, 8)}, size=0x40)
    _flush(c)
    return [self_, a]


S(0x5ec190, 'serialize (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch236; vtable calls on the argument (0x70, 0x68, 0x60, 0x44, 0x3c one word; 0x10 two words), loop over a range')
