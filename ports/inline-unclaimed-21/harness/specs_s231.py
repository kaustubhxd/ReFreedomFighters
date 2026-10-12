"""specs_s231.py - small leaves, slice 0/1 (batch231). 0x5ac600 (thiscall, four stack words, ret 0x10) and 0x5edb70
(thiscall, five stack words, ret 0x14) log ecx and every word to a ring (a record per call); the vtable slot 8 of the
[this+0xb1] object logs ecx. The object's byte [this+0xb6] and the pointers are random (never dereferenced by the stubs)."""
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


def _ring_stub(c, nwords, ret_bytes):
    """thiscall with nwords stack words (ret ret_bytes): appends ecx and the words to a ring (4 bytes each)."""
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'          # mov eax,[ptr]; mov [eax],ecx
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])   # mov edx,[esp+4+4k]; mov [eax+4(k+1)],edx
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])   # add dword [ptr], 4n
    body += b'\xc2' + struct.pack('<H', ret_bytes)
    return ss.code(c, body)


def _vt8_stub(c):
    a = _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', a) + b'\xc3')


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0xb6, bytes([c.rng.choice([0, 1])]))
    for off in (0xa1, 0xa5, 0xa9):
        c.emu.w32(self_ + off, c.rng.getrandbits(32))
    o = 0
    if c.rng.random() < 0.7:
        o = ss.mkobj(c, {8: _vt8_stub(c)}, size=0x40)
    c.emu.w32(self_ + 0xb1, o)
    ss.patch(c, 0x5ac600, _ring_stub(c, 4, 0x10))
    ss.patch(c, 0x5edb70, _ring_stub(c, 5, 0x14))
    _flush(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5ef880, 'setRanges (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch231; four stored fields, up to three 0x5ac600 calls, optional 0x5edb70 and vt[8] (stubbed callees)')
