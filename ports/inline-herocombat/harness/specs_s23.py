"""specs_s23.py - inline session batch 23 (Haiku, overnight): 0x45b0f0, 0x446280, 0x46eef0."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


# 0x45b0f0 thiscall: object floats at +0x18, +0x1c, +0x20. Stack args: pointer to three floats and t.
def _box(c):
    obj = _rnd(c, 0x40)
    for i in range(3):
        c.emu.wf32(obj + 0x18 + 4 * i, c.fv())
    v = c.emu.alloc(12, 4)
    for i in range(3):
        c.emu.wf32(v + 4 * i, c.fv())
    return [obj, v, F(c.fv())]


S(0x45b0f0, 'inBox (unknown) thiscall', 'thiscall', None, ret='al', gen=_box,
  note='batch23; each float minus t must be at least |v[k]|; NaN fails')


# 0x446280 thiscall: object floats at +0x3c, +0x40, +0x58 and the flag byte at +0x48. out2 is null only on bit-0-set cases.
def _pair(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    for off in (0x3c, 0x40, 0x58):
        c.emu.wf32(obj + off, c.fv())
    flag = r.getrandbits(8)
    c.emu.wbytes(obj + 0x48, bytes([flag]))
    out = c.fbuf(3)
    if (flag & 1) and r.random() < 0.3:
        out2 = 0
    else:
        out2 = c.fbuf(3)
    return [obj, out, out2]


S(0x446280, 'divPair2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_pair,
  note='batch23; two paths on bit 0 of this+0x48; out2 is null only in the bit-set path')


# 0x46eef0 thiscall: object dwords at +0xaa, +0xae, +0xb2. Each is zero about a quarter of the time.
def _copy(c):
    r = c.rng
    obj = _rnd(c, 0x100)
    for off in (0xaa, 0xae, 0xb2):
        if r.random() < 0.25:
            c.emu.w32(obj + off, 0)
        else:
            c.emu.w32(obj + off, _bits(c.fv()))
    out = c.emu.alloc(12, 4)
    return [obj, out]


S(0x46eef0, 'copy3Check (unknown) thiscall', 'thiscall', None, ret='al', gen=_copy,
  note='batch23; copies three dwords as raw bits, returns 1 unless all three are 0.0')
