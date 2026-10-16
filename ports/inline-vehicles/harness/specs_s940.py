"""specs_s940.py - vehicles batch 940: ZHeli::ClassInit. The base class init (0x512590) is stood in; the sound manager,
the transform slot (0x80) and the embedded object's slot 4 are stubs. The transform values are written by the 0x80 stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x512590, ss.rec(c, 0))
    blk = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.wf32(blk + 4 * k, c.rng.uniform(-100, 100))
    # slot 0x80 writes the transform (3 floats) through its first pointer argument
    heli = obj(c, 0x600, {0x80: _stub(c, 2, skip=(1,), fills=((0, blk, 3),))})
    emb = obj(c, 0x40, {4: _stub(c, 2, skip=(0,))})
    c.emu.w32(heli + 0x34e, c.emu.r32(emb))      # the embedded object's vtable word lives at +0x34e
    c.emu.w32(heli + 0x12f, c.rng.choice([0, r32(c)]))
    sm = obj(c, 0x40, {0x60: _stub(c, 2, ret=r32(c))}) if c.rng.random() < 0.8 else 0
    sys_ = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(sys_, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sys_ + 0x1a9f, sm)
    c.emu.w32(0x70039c, sys_)
    c.emu._image_dirty = True
    c.emu.mu.ctl_flush_tb()
    return [heli]


S(0x51c140, 'ZHeli::ClassInit', 'thiscall', gen=g)
