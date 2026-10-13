"""specs_s1035.py - area 81, batch 1035: 0x43a380 (thiscall, this; plain ret). The global table at 0x6e48c0 has a record at 0x6e48b8 whose link word is the
sentinel 0x6e41d0, so the first record is used; the record gives a buffer, an array (at 0x6e41d0, 12-byte entries) and a count of 0..3. this+0xa8 is a
slot returning a random index 0..40; this+0x131c is a random buffer offset 0..6. The sys object's flag bytes at +0xf0b are random (both bit 0x40 and the
0x80 threshold are hit)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj


def g(c):
    rnd = c.rng
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.wbytes(sysobj + 0xf0b, bytes(rnd.getrandbits(8) for _ in range(5 * 41 + 8)))
    count = rnd.randint(0, 3)
    buf = c.emu.alloc(32, 4)
    c.emu.wbytes(buf, bytes(rnd.getrandbits(8) for _ in range(32)))
    c.emu.w32(0x6e48c0, 0x6e41d0)
    c.emu.w32(0x6e48b8, buf)
    c.emu.w32(0x6e48c4, count)
    for i in range(3):
        c.emu.w32(0x6e41d0 + 12 * i + 4, rnd.getrandbits(32))
    self_ = obj(c, 0x1400, {0xa8: _stub(c, 1, ret=rnd.randint(0, 40))})
    c.emu.w32(self_ + 0x131c, rnd.randint(0, 6))
    return [self_]


S(0x43a380, 'GUESS 0x43a380 flag table', 'thiscall', None, ret=None, gen=g)
