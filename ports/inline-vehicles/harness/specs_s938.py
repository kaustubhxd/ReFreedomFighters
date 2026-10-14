"""specs_s938.py - vehicles batch 938: ZCar::ClassInit. The vehicle class init (0x515630) is stood in; the sound manager,
the render-manager script object and the car's transform slot are stubs. The script object's slot 0x88 writes its
out pointer through the wr stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x515630, ss.rec(c, 0))
    car = obj(c, 0x1800, {0x80: _stub(c, 2)})
    c.emu.w32(car + 0x12f, r32(c))
    sm = obj(c, 0x40, {0x60: _stub(c, 2, ret=r32(c))}) if c.rng.random() < 0.8 else 0
    script = obj(c, 0x40, {0x88: ss.wr(c, 2, 1, 4, r32(c))})
    rmo = obj(c, 0x40, {0x138: _stub(c, 0, ret=script), 0x58: _stub(c, 1, ret=r32(c))})
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, rmo)
    sysm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(sysm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sysm + 0x9b, rmo)
    c.emu.w32(sysm + 0x1a9f, sm)
    c.emu.w32(0x70039c, sysm)
    c.emu._image_dirty = True
    c.emu.mu.ctl_flush_tb()
    return [car]


S(0x5175a0, 'ZCar::ClassInit', 'thiscall', gen=g)
