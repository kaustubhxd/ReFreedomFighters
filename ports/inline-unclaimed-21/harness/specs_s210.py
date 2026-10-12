"""specs_s210.py - unclaimed area 21 (docs/20-unclaimed-21.md): 0x4cd880 link-node insert (batch210).

Fake vtable slots are raw machine-code stubs (not logging_vtable): a logged slot would record the stack out pointer
&tmp, which differs between the exe and the port. The stubs write their out word and return fixed values chosen per run.
"""
import struct
from pilot import S
import serial_stubs as ss


def _buf(c, n=0x40):
    """A heap buffer with 0x10 bytes of room before the returned pointer (the link writes go below the pointer)."""
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a + 0x10


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pick(c):
    return c.rng.choice([0, 1, c.rng.getrandbits(32)])


def _cell(c):
    """A heap word the stubs write to, so each call (and the flag word of the deleting slot) is visible to the compare."""
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _stub_out(c, value, cell, eax=None):
    """thiscall slot with one out pointer (ret 4): writes value into *out, marks cell, optionally sets eax."""
    body = b'\x8b\x54\x24\x04' + b'\xc7\x02' + struct.pack('<I', value & 0xffffffff)
    body += b'\xc7\x05' + struct.pack('<I', cell) + b'\x01\x00\x00\x00'
    if eax is not None:
        body += b'\xb8' + struct.pack('<I', eax & 0xffffffff)
    return ss.code(c, body + b'\xc2\x04\x00')


def _stub_ret(c, eax, cell):
    """thiscall slot with no argument: marks cell, returns eax."""
    return ss.code(c, b'\xc7\x05' + struct.pack('<I', cell) + b'\x01\x00\x00\x00'
                   + b'\xb8' + struct.pack('<I', eax & 0xffffffff) + b'\xc3')


def _stub_ret4(c, cell):
    """deleting slot 0 (one stack word): stores that word in cell, returns nothing."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cell) + b'\xc2\x04\x00')


def _flush(c):
    """Drops cached translations of the heap (stubs and fake vtables live there) and of the exe image (patched callee)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _link_obj(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, c.rng.choice([0, 1, 2, 3]))
    head = _buf(c) if c.rng.random() < 0.6 else 0
    c.emu.w32(self_ + 0x1c, head)
    c.emu.w32(self_ + 0x20, c.rng.getrandbits(32))
    arg = _buf(c)                        # [edi] = arg writes into this buffer, so arg must be a valid pointer
    ret4cd540 = _buf(c)
    ss.patch(c, 0x4cd540, ss.rec(c, 1, ret=ret4cd540, log=True))   # original callee, used when [this+0x24] is null
    if c.rng.random() < 0.85:
        slots = {
            0x4c: _stub_out(c, _pick(c), _cell(c)),
            0x5c: _stub_out(c, _pick(c), _cell(c), eax=_buf(c)),
            0x44: _stub_out(c, _pick(c), _cell(c)),
            0x14: _stub_ret(c, _pick(c), _cell(c)),
            0x00: _stub_ret4(c, _cell(c)),
        }
        obj = ss.mkobj(c, slots)
        c.emu.w32(self_ + 0x24, obj)
    else:
        c.emu.w32(self_ + 0x24, 0)
    _flush(c)
    return [self_, arg]


S(0x4cd880, 'linkNodeInsert (GUESS)', 'thiscall', None, ret='eax', gen=_link_obj,
  note='batch210; vtable 0x4c, 0x5c, 0x44, 0x14 and slot 0; calls original 0x4cd540 when the object is null')
