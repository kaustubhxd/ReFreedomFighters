"""specs_s1104.py - collision thread batch 1104: 0x4eaa80 ZCollisionBox::PushOutOfAllTris. The box is built by
the batch 1103 generator; FetchPushList and the vector helpers run as exe code."""
import struct
from pilot import S, F
from specs_s1103 import _fpl


def _pout(c):
    r = c.rng
    e = c.emu
    this, impact, out, pv, sv = _fpl(c)
    # PushOutOfAllTris takes pos and scale and passes pos / scale and 1 / scale to FetchPushList
    sarg = e.alloc(0x20, 4)
    pos = e.alloc(0x20, 4)
    for j in range(3):
        s = e.rf32(sv + 4 * j)
        e.wf32(sarg + 4 * j, 1.0 / s)
        e.wf32(pos + 4 * j, e.rf32(pv + 4 * j) / s)
    fb = e.alloc(0x20, 4)
    for j in range(3):
        e.wf32(fb + 4 * j, e.rf32(pos + 4 * j) + r.uniform(-1, 1))
    return [this, impact, pos, fb, sarg]


S(0x4eaa80, 'ZCollisionBox::PushOutOfAllTris', 'thiscall', None, ret='al', gen=_pout, note='batch1104')
