"""specs_u18_10.py - area 18, group 10 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _gp(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    e.wf32(o + 0xa7, c.fv(-1000, 1000)) if hasattr(e, 'wf32') else e.mu.mem_write(o + 0xa7, struct.pack('<f', c.fv(-1000, 1000)))
    e.w32(o + 0xab, r.choice([1, 2, 3, 7, 1000, 0, -4, r.getrandbits(32)]))
    return [o]


S(0x4fa0d0, 'ZScrollbar::GetPosition', 'thiscall', None, ret='st0', gen=_gp, note='u18')


def _sr(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x200)
    e.w32(o + 0x1d5, r.getrandbits(32))
    e.w32(o + 0x1d9, r.choice([0, 0, r.getrandbits(32)]))
    e.w32(o, rvt(e, 'car', {0x2e8: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0],)))}, nslots=0x2ec // 4))
    return [o]


S(0x5144d0, 'ZMoveOnSpline::StartRollingSound', 'thiscall', None, ret='eax', gen=_sr, note='u18')
