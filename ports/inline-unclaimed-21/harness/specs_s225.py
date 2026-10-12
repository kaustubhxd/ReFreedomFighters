"""specs_s225.py - small leaves, slices 0/1 (batch225). The release 0x634273 and 0x5003d0 (ret 4) are stubs that store their words;
0x5002f0 (ret 4) stores its word into [ecx] and sets [ecx+4]=1 (its 0/1 path; its other path is not modelled); 0x5ebf00 is pure memory."""
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


def _obj(c):
    return [_rnd(c, 0x100)]


def _dtor(c):
    obj = _rnd(c, 0x40)
    cp, cn = _cell(c), _cell(c)
    ss.patch(c, 0x634273, ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + struct.pack('<I', cp)
                                  + b'\x8b\x44\x24\x08' + b'\xa3' + struct.pack('<I', cn) + b'\xc3'))
    _flush(c)
    return [obj, c.rng.getrandbits(32)]


def _lookup(c):
    self_ = _rnd(c, 0x40)
    e = _rnd(c, 0x800)
    c.emu.w32(e + 0x684, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x18, e)
    a = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.w32(a + 8, p)
    buf = _rnd(c, 0x40)
    c.emu.wbytes(buf + 4, bytes([c.rng.choice([0, 1])]))   # 0x5002f0's 0/1 path (its other path calls out; not modelled)
    cp, cz, cv = _cell(c), _cell(c), _cell(c)
    # 0x5003d0 (ecx = p, [esp+4] = 0; ret 4): stores them, returns buf
    look = ss.code(c, b'\x89\x0d' + struct.pack('<I', cp)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cz)
                   + b'\xb8' + struct.pack('<I', buf) + b'\xc2\x04\x00')
    ss.patch(c, 0x5003d0, look)
    # 0x5002f0 (ecx = r, one stack word, ret 4): [r] = word; [r+4] = 1 (its byte-0/1 path); the buffer's byte is set to 0 or 1
    ss.patch(c, 0x5002f0, ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x11' + b'\xc6\x41\x04\x01' + b'\xc2\x04\x00'))
    _flush(c)
    return [self_, a]


S(0x5ebf00, 'setFlagA6 (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch225; byte +0xa6 = 1')
S(0x50a640, 'dtor50a640 (GUESS)', 'thiscall', None, ret='eax', gen=_dtor,
  note='batch225; vtable 0x69c968; release 0x634273(this, 0xc) when flags & 1')
S(0x55f640, 'lookupStore (GUESS)', 'thiscall', None, ret=None, gen=_lookup,
  note='batch225; 0x5003d0 (one word), then 0x5002f0 stores the pushed E+0x684 word into the result')
