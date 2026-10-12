"""specs_s237.py - small leaves, slice 0/1 (batch237). 0x5625c0 (thiscall(a1), ret 4).

vtable slot 0x84 on this is called twice per run: the first call pushes nothing (its stub pops 0) and returns r2; the second
pushes one word (its stub pops 4) and returns table[1]. A call counter selects the pop: the stub returns table[count], and
pops 0 when the count was 0, else 4 (conditional ret). Slot 0xc4 (one word) and 0xe8 (no words) and the 0x12c child
(three words, two logged) are rings. The sub-object r2+0xcb holds the vtable VT whose slot 0x14 returns a fixed value.
0x4f21f0 (ret 4) is stubbed here: the real routine (reads its stack byte, writes r4+0x68/+0x6a/+0x6b, and calls 0x4f2240)
showed a heap difference at r4+0x68 in later cases when run as exe code; that is unresolved (see the claim doc)."""
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


def _ring(c, nwords, ret_bytes):
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    body += b'\xc2' + struct.pack('<H', ret_bytes)
    return ss.code(c, body)


def _counter_stub(c, table):
    """thiscall slot 0x84: returns table[count] and returns with ret 0 (it never pops: the pushed 0 of the second call is
    popped by the original 0x4f21f0, which is ret 4)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tbl = c.emu.alloc(4 * len(table), 4)
    for k, v in enumerate(table):
        c.emu.w32(tbl + 4 * k, v)
    body = (b'\x8b\x0d' + struct.pack('<I', cnt)                      # mov ecx, [cnt]
            + b'\x8b\x04\x8d' + struct.pack('<I', tbl)                # mov eax, [ecx*4 + tbl]
            + b'\x83\x05' + struct.pack('<I', cnt) + b'\x01'          # add dword [cnt], 1
            + b'\x85\xc9'                                             # test ecx, ecx
            + b'\xc3')                                                 # ret 0
    return ss.code(c, body)


def _ring12c(c):
    """vtable 0x12c (three stack words, ret 0xc): logs ecx and the first two words, and the word the third one addresses."""
    ring = c.emu.alloc(4 * 4 * 8, 4)
    c.emu.wbytes(ring, bytes(4 * 4 * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    cell = _cell(c)
    body = (b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'                   # mov eax,[ptr]; mov [eax],ecx
            + b'\x8b\x54\x24\x04' + b'\x89\x50\x04'                         # word 1
            + b'\x8b\x54\x24\x08' + b'\x89\x50\x08'                         # word 2
            + b'\x8b\x54\x24\x0c' + b'\x8b\x12' + b'\x89\x50\x0c'            # the word its pointer addresses
            + b'\x83\x05' + struct.pack('<I', ptr) + b'\x10'                  # add dword [ptr], 16
            + b'\xc2\x0c\x00')
    return ss.code(c, body)


def _ret_val_stub(c, val):
    a = _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', a) + b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc3')


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0x85, bytes([1 if c.rng.random() < 0.3 else 0]))
    c.emu.w32(self_ + 0xdc, c.rng.choice([0xffffffff, 0, 1, 2, 3, 0x7fffffff]))
    c.emu.wbytes(self_ + 0x74, struct.pack('<H', c.rng.getrandbits(16)))
    O = ss.mkobj(c, {0x12c: _ring12c(c)}, size=0x40)
    c.emu.w32(self_ + 0x44, O)
    r2 = _rnd(c, 0x100)
    VT = c.emu.alloc(0x40, 4)
    c.emu.w32(VT + 0x14, _ret_val_stub(c, c.rng.choice([0, 1, 5, 0xfffffffd])))
    c.emu.w32(r2 + 0xcb, VT)
    r4 = _rnd(c, 0x100)                     # the object 0x4f21f0 writes into (+0x64, +0x68, +0x6a, +0x6b)
    stub84 = _counter_stub(c, [r2, r4])
    vt_self = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_self + 0xc4, _ring(c, 1, 4))
    c.emu.w32(vt_self + 0xe8, _ring(c, 0, 0))
    c.emu.w32(vt_self + 0x84, stub84)
    c.emu.w32(self_, vt_self)
    a1 = 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x30, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x4f21f0, ss.code(c, b'\x89\x0d' + struct.pack('<I', _cell(c)) + b'\xc2\x04\x00'))   # ret 4 (checked): stores ecx
    _flush(c)
    return [self_, a1]


def _ret8_store_stub(c):
    ca, cb, cc = _cell(c), _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', ca)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cb)
                   + b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cc)
                   + b'\xc2\x08\x00')


def _cell_store_stub(c):
    a = _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', a) + b'\xc3')


S(0x5625c0, 'path5625 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch237; two vtable 0x84 calls (pop 0 then pop 4), VT 0x14 on r2+0xcb, ext 0x4f21f0, vt 0x12c with &a1')
