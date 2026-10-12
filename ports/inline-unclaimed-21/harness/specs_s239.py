"""specs_s239.py - gap band 0x645ec0 (batch239). SEH frame not reproduced. Callees: the child's vt 0x50 (one word) returns
an id; the render-manager object's vt 0x20 (one word) returns a heap block; the error object's vt 0x20 (two words, callee pops)
returns P; P's vt 0x2c (three words, caller pops: ret 0) logs; 0x4da2f0 (two words, ret 8) logs its second word and returns a
heap block; 0x4cc1d0 logs ecx and returns a value; 0x63d7d0 and 0x4cbec0 log ecx."""
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


def _ring(c, nwords, ret_bytes, val=None, skip=()):
    """thiscall with nwords stack words: appends ecx and the words not in skip to a ring of 16; returns val if given."""
    n = 1 + nwords
    ring = c.emu.alloc(4 * (n + 1) * 16, 4)
    c.emu.wbytes(ring, bytes(4 * (n + 1) * 16))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    if val is not None:
        body += b'\xb8' + struct.pack('<I', val & 0xffffffff)
    body += b'\xc2' + struct.pack('<H', ret_bytes)
    return ss.code(c, body)


def _gen(c):
    self_ = _rnd(c, 0x100)
    X = c.rng.choice([0, c.rng.getrandbits(32)])
    B = c.rng.getrandbits(32)
    id_val = c.rng.getrandbits(32)
    n = c.rng.randrange(0, 4)
    c.emu.w32(self_ + 0x69, n)
    for i in range(n):
        base = self_ + 0x6d + i * 56
        found_here = c.rng.random() < 0.5
        c.emu.w32(base, id_val if found_here else c.rng.getrandbits(32))
        c.emu.w32(base + 4, B if found_here else c.rng.getrandbits(32))
        c.emu.wbytes(base + 8, bytes(c.rng.getrandbits(8) for _ in range(48)))
    rm = _rnd(c, 0x2000)
    child = ss.mkobj(c, {0x50: _ring(c, 1, 4, val=id_val)}, size=0x40)
    c.emu.w32(rm + 0x9b, child)
    blk1 = _rnd(c, 0x40)
    o = ss.mkobj(c, {0x20: _ring(c, 1, 4, val=blk1)}, size=0x40)
    c.emu.w32(rm + 0x190f, o)
    c.emu.w32(0x70039c, rm)
    P = ss.mkobj(c, {0x2c: _ring(c, 3, 0)}, size=0x40)
    D = ss.mkobj(c, {0x20: _ring(c, 2, 8, val=P)}, size=0x40)
    c.emu.w32(0x700390, D)
    blk2 = _rnd(c, 0x40)
    c2 = c.emu.alloc(8, 4)   # 0x4da2f0 (ecx, p1 = a stack block, p2): logs ecx and p2 only; returns blk2
    c.emu.w32(c2, 0)
    c.emu.w32(c2 + 4, 0)
    ss.patch(c, 0x4da2f0, ss.code(c, b'\x89\x0d' + struct.pack('<I', c2) + b'\x8b\x54\x24\x08' + b'\x89\x15'
                                  + struct.pack('<I', c2 + 4) + b'\xb8' + struct.pack('<I', blk2) + b'\xc2\x08\x00'))
    ss.patch(c, 0x4cc1d0, _ring(c, 0, 0, val=c.rng.getrandbits(32)))
    ss.patch(c, 0x63d7d0, _ring(c, 0, 0))
    ss.patch(c, 0x4cbec0, ss.code(c, b'\xc3'))
    _flush(c)
    return [self_, X, B]


S(0x645ec0, 'listRemove645 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch239; gap band; SEH not reproduced; vt 0x50 id search, found-removal or error-log path')
