"""specs_s234.py - small leaves, slice 0/1 (batch234). thiscall(mode, flag). The vtable slots of the children and of
this log their ecx (and their word, for 0xd4 and 0xbc) to a ring (one record per call). A non-null n is always paired with
a non-null m (the exe calls m's vtable 0xbc inside the n branch of mode 3)."""
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
    """thiscall with nwords stack words (ret ret_bytes): appends ecx and the words to a ring of 8 records."""
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


def _ring70(c):
    """thiscall with one stack pointer (ret 4): logs ecx and the two words the pointer addresses (never the pointer)."""
    ring = c.emu.alloc(12 * 8, 4)
    c.emu.wbytes(ring, bytes(12 * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = (b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'            # mov eax,[ptr]; mov [eax],ecx
            + b'\x8b\x54\x24\x04' + b'\x8b\x12' + b'\x89\x50\x04'   # mov edx,[esp+4]; mov edx,[edx]; mov [eax+4],edx
            + b'\x8b\x54\x24\x04' + b'\x8b\x52\x04' + b'\x89\x50\x08'   # mov edx,[esp+4]; mov edx,[edx+4]; mov [eax+8],edx
            + b'\x83\x05' + struct.pack('<I', ptr) + b'\x0c'            # add dword [ptr], 12
            + b'\xc2\x04\x00')
    return ss.code(c, body)


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x8b, c.rng.getrandbits(32))
    n_on = c.rng.random() < 0.7
    m_on = (c.rng.random() < 0.8) or n_on           # a non-null n needs a non-null m
    n = ss.mkobj(c, {0x70: _ring70(c)}, size=0x40) if n_on else 0
    m = ss.mkobj(c, {0x70: _ring70(c), 0xbc: _ring(c, 1, 4)}, size=0x40) if m_on else 0
    c.emu.w32(self_ + 0x4c, n)
    c.emu.w32(self_ + 0x50, m)
    # this: vtable 0xd4 logs its word (the mode-2/3 flag branches)
    vt_self = c.emu.alloc(0x100, 4)
    c.emu.w32(vt_self + 0xd4, _ring(c, 1, 4))
    c.emu.w32(self_, vt_self)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x73, c.rng.randrange(0, 0x40))
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [self_, c.rng.choice([0, 1, 2, 3, 4, 5, 6]), c.rng.getrandbits(32)]


S(0x563750, 'modeCall (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch234; mode 2/3/5 vtable 0x70 on the local block; 0xd4, 0xbc on children and this (logged)')
