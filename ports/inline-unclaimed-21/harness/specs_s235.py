"""specs_s235.py - small leaves, slice 0/1 (batch235). 0x5003d0 (one word, ret 4) returns block[word]; block 1's byte +4 is 3
or 4 (the two branches; the error path is never taken). vtable 0x114 (five words: the exe pushes five) logs ecx and four
words, returns a fixed 16-bit value; 0x12c (two words) logs ecx and both words; 0x34 (no args) returns a fixed value."""
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


def _ring_prefix(c, nwords):
    """Code that appends ecx and nwords stack words to a ring of 8 records (no return). Returns the bytes."""
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    return body


def _ring_114(c, val):
    """vtable 0x114 (ecx, five stack words, ret 0x14): logs ecx and four words; also stores the five dwords the fifth
    word addresses (the local block); returns val."""
    body = _ring_prefix(c, 4)
    cells = [c.emu.alloc(4, 4) for _ in range(5)]
    body += b'\x8b\x54\x24\x14'                                  # mov edx, [esp+0x14] (the local block)
    for k, cell in enumerate(cells):
        body += b'\x8b\x4a' + bytes([4 * k]) + b'\x89\x0d' + struct.pack('<I', cell)   # mov ecx,[edx+4k]; mov [cell],ecx
    body += b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x14\x00'
    return ss.code(c, body)


def _ring_ret(c, nwords, ret_bytes, val):
    """Ring prefix, then eax = val and ret ret_bytes."""
    return ss.code(c, _ring_prefix(c, nwords) + b'\xb8' + struct.pack('<I', val & 0xffffffff)
                   + b'\xc2' + struct.pack('<H', ret_bytes))


def _ring_void(c, nwords, ret_bytes):
    return ss.code(c, _ring_prefix(c, nwords) + b'\xc2' + struct.pack('<H', ret_bytes))


def _lookup_table(c, blocks):
    tbl = c.emu.alloc(4 * len(blocks), 4)
    for k, b in enumerate(blocks):
        c.emu.w32(tbl + 4 * k, b)
    return ss.code(c, b'\x8b\x44\x24\x04' + b'\x8b\x04\x85' + struct.pack('<I', tbl) + b'\xc2\x04\x00')


def _gen(c):
    self_ = _rnd(c, 0x100)
    O = ss.mkobj(c, {0x12c: _ring_void(c, 2, 8)}, size=0x40)
    c.emu.w32(self_ + 0xc, O)
    a = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(a + 4, q)
    blocks = [_rnd(c, 0x40) for _ in range(7)]
    use34 = c.rng.random() < 0.5
    B = blocks[1]
    c.emu.wbytes(B + 4, bytes([4 if use34 else 3]))
    if use34:
        o34 = ss.mkobj(c, {0x34: _ring_ret(c, 0, 0, c.rng.getrandbits(32))}, size=0x40)
        c.emu.w32(B, o34)
    for k in (0, 2, 3, 4, 5, 6):
        c.emu.wbytes(blocks[k] + 4, bytes([c.rng.choice([0, 1, 3, 4])]))
    ss.patch(c, 0x5003d0, _lookup_table(c, blocks))
    child = ss.mkobj(c, {0x114: _ring_114(c, c.rng.getrandbits(32))}, size=0x40)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [self_, a]


S(0x503200, 'dispatch503200 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch235; lookups 0x5003d0 words 0..6; vt 0x34 or the dword; vt 0x114 (five pushed words) and vt 0x12c')
