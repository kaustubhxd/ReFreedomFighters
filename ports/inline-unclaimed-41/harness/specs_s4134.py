"""specs_s4134.py - unclaimed-41 batch 34 (core-todo residue-19): 0x5dcc70 ZFFFlak::Init() (thiscall, no arguments, ret 0, void).

self: 0x80 random bytes with random floats at +0x5c and +0x60 (small, finite). rm (0x70039c): its vtable slot 0x1c0 returns a fixed random
float in st0 (fld from a cell, ret 8; the callee pops its two arguments). The float compare uses the stored values; faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fbits(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _fld_ret(c, bits):
    """Returns a float in st0 from a cell (fld dword [cell]) and pops two stack arguments; both arguments are summed into acc first."""
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, bits)
    acc = c.emu.alloc(8, 4)
    c.emu.w32(acc, 0)
    c.emu.w32(acc + 4, 0)
    b = (b'\x8b\x44\x24\x04' + b'\x01\x05' + struct.pack('<I', acc)        # mov eax,[esp+4]; add [acc], eax
         + b'\x8b\x44\x24\x08' + b'\x01\x05' + struct.pack('<I', acc + 4)    # mov eax,[esp+8]; add [acc+4], eax
         + b'\xd9\x05' + struct.pack('<I', cell)                              # fld dword [cell]
         + b'\xc2\x08\x00')                                                  # ret 8
    return ss.code(c, b)


def _layout(c):
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x1c0, _fld_ret(c, _fbits(c, -3.0, 3.0)))
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm, vt)
    c.emu.w32(0x70039c, rm)

    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x5c, _fbits(c, -50.0, 50.0))
    c.emu.w32(self_ + 0x60, _fbits(c, -4.0, 4.0))
    return [self_]


S(0x5dcc70, 'ZFFFlak::Init()', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 34; rm.vt[0x1c0] returns a float in st0 (a fixed value per case); the /GS cookie check does not apply')
