"""specs_s233.py - small leaves, slice 0/1 (batch233). 0x5003d0 (ret 4) returns one of four blocks by its word; 0x59db50
(thiscall, four words, ret 0x10) logs ecx and its words and returns a fixed value; 0x5002f0 (ret 4) stores its word into
[ecx] and sets [ecx+4]=1 (its 0/1 path; the blocks' byte is set to 0 or 1)."""
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


def _block(c):
    b = _rnd(c, 0x40)
    c.emu.wbytes(b + 4, bytes([c.rng.choice([0, 1])]))
    return b


def _lookup_by_word(c, blocks):
    """0x5003d0 (ecx = p, one stack word, ret 4): returns blocks[word] (word in 0..3)."""
    tbl = c.emu.alloc(4 * len(blocks), 4)
    for k, b in enumerate(blocks):
        c.emu.w32(tbl + 4 * k, b)
    body = b'\x8b\x44\x24\x04' + b'\x8b\x04\x85' + struct.pack('<I', tbl) + b'\xc2\x04\x00'
    return ss.code(c, body)


def _call59_stub(c, ret):
    ca, c1, c2, c3, c4 = (_cell(c) for _ in range(5))
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', ca)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', c1)
                   + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', c2)
                   + b'\x8b\x54\x24\x0c' + b'\x89\x15' + struct.pack('<I', c3)
                   + b'\x8b\x54\x24\x10' + b'\x89\x15' + struct.pack('<I', c4)
                   + b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2\x10\x00')


def _store_stub(c):
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x11' + b'\xc6\x41\x04\x01' + b'\xc2\x04\x00')


def _gen(c):
    self_ = _rnd(c, 0x40)
    o = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, o)
    a = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(a + 4, q)
    c.emu.w32(a + 8, q)
    blocks = [_block(c) for _ in range(4)]
    ss.patch(c, 0x5003d0, _lookup_by_word(c, blocks))
    ss.patch(c, 0x59db50, _call59_stub(c, c.rng.getrandbits(32)))
    ss.patch(c, 0x5002f0, _store_stub(c))
    _flush(c)
    return [self_, a]


S(0x557d00, 'lookupCall (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch233; four 0x5003d0 lookups (words 0..3), 0x59db50 (stubbed), 0x5003d0 then 0x5002f0 store')
