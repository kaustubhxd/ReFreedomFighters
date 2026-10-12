"""specs_s243.py - batch243 (0x5eb8c0). The helpers 0x43e920, 0x43e8e0, 0x451890, 0x4e0d00, 0x44c840 and the libm sqrt run as
original code (claimed by other batches). Object vtables: this (0x4 returns r in {0x12, 0x13}, a counter table: a second call
returns 0x13), o = [this+8] (0x508 / 0x50c return the block; 0x84 writes through its pointer and logs ecx), the block (0x32c one
word, 0x2d0 two words, 0x35c none), q = o->vt[0x55c](block) (its 0x320 none). The flag [this+0x14] is 0; [rm+0x40] is large
(or small: the early exit)."""
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


def _ring(c, nwords, ret_bytes, val=None):
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    if val is not None:
        body += b'\xb8' + struct.pack('<I', val & 0xffffffff)
    return ss.code(c, body + b'\xc2' + struct.pack('<H', ret_bytes))


def _counter_table(c, table):
    cnt = _cell(c)
    tbl = c.emu.alloc(4 * len(table), 4)
    for k, v in enumerate(table):
        c.emu.w32(tbl + 4 * k, v)
    return ss.code(c, b'\x8b\x0d' + struct.pack('<I', cnt) + b'\x8b\x04\x8d' + struct.pack('<I', tbl)
                   + b'\x83\x05' + struct.pack('<I', cnt) + b'\x01' + b'\xc3')


def _vec84_stub(c):
    """thiscall (one pointer, ret 4): logs ecx, the pointer's three dwords (its content), and XORs the pointer's middle float."""
    ring = c.emu.alloc(4 * 4 * 8, 4)
    c.emu.wbytes(ring, bytes(4 * 4 * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    k = c.rng.getrandbits(32)
    body = (b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
            + b'\x8b\x54\x24\x04' + b'\x8b\x12' + b'\x89\x50\x04'
            + b'\x8b\x54\x24\x04' + b'\x8b\x52\x04' + b'\x89\x50\x08'
            + b'\x8b\x54\x24\x04' + b'\x8b\x52\x08' + b'\x89\x50\x0c'
            + b'\x83\x05' + struct.pack('<I', ptr) + b'\x10'
            + b'\x8b\x54\x24\x04' + b'\x8b\x42\x04' + b'\x35' + struct.pack('<I', k) + b'\x89\x42\x04'
            + b'\xc2\x04\x00')
    return ss.code(c, body)


def _gen(c):
    self_ = _rnd(c, 0x200)
    c.emu.wbytes(self_ + 0x14, b'\x00')
    c.emu.wbytes(self_ + 0x10, struct.pack('<f', c.rng.uniform(-20.0, 20.0)))
    c.emu.wbytes(self_ + 0x15, b''.join(struct.pack('<f', c.rng.uniform(-50.0, 50.0)) for _ in range(3)))
    r1 = c.rng.choice([0x12, 0x13])
    table_self = [r1, 0x13]
    vt_self = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_self + 4, _counter_table(c, table_self))
    c.emu.w32(self_, vt_self)
    o = _rnd(c, 0x200)
    c.emu.w32(self_ + 8, o)
    blk = _rnd(c, 0x200)
    blk2 = _rnd(c, 0x200)
    vt_blk = c.emu.alloc(0x400, 4)
    c.emu.w32(vt_blk + 0x32c, _ring(c, 1, 4))
    c.emu.w32(vt_blk + 0x2d0, _ring(c, 2, 8))
    c.emu.w32(vt_blk + 0x35c, _ring(c, 0, 0))
    c.emu.w32(blk, vt_blk)
    q = _rnd(c, 0x200)
    vt_q = c.emu.alloc(0x400, 4)
    c.emu.w32(vt_q + 0x320, _ring(c, 0, 0))
    c.emu.w32(q, vt_q)
    vt_o = c.emu.alloc(0x800, 4)
    c.emu.w32(vt_o + 0x508, _ring(c, 0, 0, val=blk))
    c.emu.w32(vt_o + 0x50c, _ring(c, 0, 0, val=blk2))
    c.emu.w32(vt_o + 0x84, _vec84_stub(c))
    c.emu.w32(vt_o + 0x55c, _ring(c, 1, 4, val=q))
    c.emu.w32(o, vt_o)
    c.emu.w32(blk2, vt_blk)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x40, c.rng.choice([0x7fffffff, 0, 5, 1000000]))
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [self_]


S(0x5eb8c0, 'actionThrow5eb8 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch243; helpers 0x43e920 0x43e8e0 0x451890 0x4e0d00 0x44c840 run as original code; sqrt via the harness IAT stub')
