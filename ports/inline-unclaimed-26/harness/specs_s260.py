"""specs_s260.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x4a5dd0, a fixed run of vtable calls on the stack object,
then exe helper 0x4e7be0 (not claimed)."""
import struct
from pilot import S, F, f32


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    return f32(c.rng.uniform(-1e4, 1e4))


def _apply(c):
    e = c.emu
    obj = _rnd(c, 0x200)
    for off in (0xbb, 0xc0, 0xc7):           # keep the float fields finite (NaN bits would not compare)
        e.w32(obj + off, struct.unpack('<I', struct.pack('<f', _fl(c)))[0])
    slots = {0x40: 1, 0x44: 1, 0x4c: 1, 0x54: 1, 0x60: 1, 0x68: 1, 0x70: 1}
    vt = e.logging_vtable('ctl4a5', 29, impl={}, argwords=slots)
    b = _rnd(c, 0x40)
    e.w32(b, vt)
    return [obj, b]


S(0x4a5dd0, 'applyFields (GUESS)', 'thiscall', None, ret='al', gen=_apply,
  note='batch260; 22 vtable calls on the stack object, then exe 0x4e7be0; ret 4')
