"""specs_s789.py - unclaimed-77 claim 19 (docs/20-unclaimed-77.md): RandomRange(float, float). Stdcall, ret 8, result in st0 (double
precision). The render-manager (global 0x70039c) is an object whose slot 0x1c0 is a logger stub (GUESS): it logs its two arguments and
returns a finite float in st0. The arguments are passed as F(...) floats."""
import struct
from pilot import S, F
import serial_stubs as ss


def _stub1c0(c, retbits):
    """Thiscall, two stack arguments (ret 8), logs both in a ring of 8 (8 bytes each), returns a float in st0 (fld of a constant)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    const = c.emu.alloc(4, 4)
    c.emu.wbytes(const, struct.pack('<I', retbits))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xd9\x05' + ss.P(const)
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _gen(c):
    rm = ss.mkobj(c, {0x1c0: _stub1c0(c, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-2.0, 2.0)))[0])}, size=0x100)
    c.emu.w32(0x70039c, rm)
    lo = c.rng.uniform(-100.0, 100.0)
    hi = c.rng.uniform(-100.0, 100.0)
    return [F(lo), F(hi)]


S(0x4de000, 'RandomRange (unknown) stdcall', 'stdcall', None, ret='st0', gen=_gen,
  note='unclaimed-77 claim 19; render-manager slot 0x1c0 stubbed (GUESS); result in st0 at double precision')
