"""specs_s270.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x4b89d0, a timed tick that calls exe
0x4b8ab0 (not claimed) and this's vtbl[0x68]."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tick(c):
    e = c.emu
    vt = e.logging_vtable('tick4b89', 0x1b, impl={}, argwords={0x68: 2})
    self_ = _rnd(c, 0x80)
    e.w32(self_, vt)
    e.w32(self_ + 0x4c, 0)                    # the list pass in 0x4b8ab0 then exits at once
    f1, f2 = c.rng.uniform(-300.0, 300.0), c.rng.uniform(-300.0, 300.0)
    e.w32(self_ + 0x50, struct.unpack('<I', struct.pack('<f', f1))[0])
    e.w32(self_ + 0x54, struct.unpack('<I', struct.pack('<f', f2))[0])
    g = struct.unpack('<f', struct.pack('<I', e.r32(0x678620)))[0]
    t = struct.unpack('<f', struct.pack('<f', struct.unpack('<f', struct.pack('<f', f1 + f2))[0] * g))[0]
    eng = _rnd(c, 0x200)
    lim = int(t)                              # the exact limit, so the '<' versus '<=' boundary is hit
    e.w32(eng + 0x40, (lim if c.rng.random() < 0.5 else c.rng.randrange(-2000, 2000)) & 0xffffffff)
    e.w32(0x70039c, eng)
    return [self_]


S(0x4b89d0, 'tick (GUESS)', 'thiscall', None, ret=None, gen=_tick, note='batch270; calls exe 0x4b8ab0; ret')
