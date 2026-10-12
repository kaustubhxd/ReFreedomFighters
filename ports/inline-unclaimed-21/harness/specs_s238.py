"""specs_s238.py - small leaves, slice 0/1 (batch238). 0x5003d0 (one word, ret 4) returns block[word] from a table of three
blocks (the same blocks serve both lookups); the blocks' byte +4 is 0 or 2 (so the exe's error branch is not taken). The
vtable slot 0x8c (one pointer) logs ecx and XORs V[1] through the pointer (so both the pre-call and post-call values are observed)."""
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


def _table_stub(c, blocks):
    tbl = c.emu.alloc(4 * len(blocks), 4)
    for k, b in enumerate(blocks):
        c.emu.w32(tbl + 4 * k, b)
    return ss.code(c, b'\x8b\x44\x24\x04' + b'\x8b\x04\x85' + struct.pack('<I', tbl) + b'\xc2\x04\x00')


def _gen(c):
    self_ = _rnd(c, 0x40)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 4, _rnd(c, 0x40))
    c.emu.w32(a + 8, _rnd(c, 0x40))
    blocks = [_rnd(c, 0x40) for _ in range(3)]
    for b in blocks:
        c.emu.wbytes(b + 4, bytes([c.rng.choice([0, 2])]))
    ss.patch(c, 0x5003d0, _table_stub(c, blocks))
    cell = _cell(c)
    K = c.rng.getrandbits(32)
    stub8c = ss.code(c, b'\x89\x0d' + struct.pack('<I', cell)
                     + b'\x8b\x54\x24\x04' + b'\x8b\x42\x04' + b'\x35' + struct.pack('<I', K)   # mov edx,[esp+4]; mov eax,[edx+4]; xor eax,K
                     + b'\x89\x42\x04'                                                              # mov [edx+4], eax
                     + b'\xc2\x04\x00')
    O = ss.mkobj(c, {0x8c: stub8c}, size=0x40)
    c.emu.w32(self_ + 0xc, O)
    _flush(c)
    return [self_, a]


S(0x501550, 'vecStore (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch238; three lookups read floats, vt 0x8c on O with &V, three block writes (byte 2) after the call')
