"""specs_s935.py - unclaimed-80, ZMovementGuide::WantControl (0x489df0; the whole entry, paths 1 to 5 of batch935.cpp). Three kinds of
input, none reaching the continuation: (a) this+0x371 nonzero (40%: true); (b) this+0x371 zero and a small third vector (threshold
exit, 30%: false); (c) this+0x371 zero and a larger x (30%): this+0x375 zero (false) or a pointer whose +0x18 is zero (false, after the
byte at +0x3be is cleared). The object at this+4 has a float at +0x43d."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _entry(c):
    self_o = _rnd(c, 0x400)
    obj4 = _rnd(c, 0x500)
    c.emu.wf32(obj4 + 0x43d, c.rng.uniform(-1, 1))
    c.emu.w32(self_o + 4, obj4)
    c.emu.wbytes(self_o + 0x3be, bytes([c.rng.getrandbits(8) | 1]))
    r = c.rng.random()
    if r < 0.4:
        c.emu.w32(self_o + 0x371, c.rng.randint(1, 0xffffffff))
        x = c.rng.uniform(-0.005, 0.005)
        z = c.rng.uniform(-0.005, 0.005)
    else:
        c.emu.w32(self_o + 0x371, 0)
        if r < 0.7:
            x = c.rng.uniform(-0.005, 0.005)
            z = c.rng.uniform(-0.005, 0.005)
        else:
            x = c.rng.choice([-1, 1]) * c.rng.uniform(0.05, 1.0)
            z = c.rng.uniform(-1, 1)
            if c.rng.random() < 0.3:
                c.emu.w32(self_o + 0x375, 0)
            else:
                p = _rnd(c, 0x40)
                c.emu.w32(p + 0x18, 0)
                c.emu.w32(self_o + 0x375, p)
    v0 = _rnd(c, 12)
    v1 = _rnd(c, 12)
    v2 = c.emu.alloc(12, 4)
    c.emu.wbytes(v2, struct.pack('<fff', x, c.rng.uniform(-1, 1), z))
    return [self_o, v0, v1, v2]


S(0x489df0, 'ZMovementGuide::WantControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_entry,
  note='unclaimed-80 WantControl: entry paths 1-5 ported; continuation (from 0x489ec3) not ported and not reached')
