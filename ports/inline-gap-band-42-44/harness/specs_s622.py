"""specs_s622.py - band 0x421000-0x441000, batch 622 (see src/batch622.cpp). The float argument is passed with F(x).
0x433580 calls the receiver's slot 0xac with the float (recorded as its bit pattern). 0x436170 stores into the object; the
divisor (1 - v) stays away from zero (v is drawn from [-3, 0.9]).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
from pe_emu import F  # noqa: E402


def _rec(name, off):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    return h


def _gen_slot(c):
    r = c.rng
    o = c.emu.fake_object('fwd', 0x40, nslots=0x60, slots={0xac: _rec('fwd.ac', 0xac)})
    return [o, F(r.uniform(-3.0, 0.9))]


def _gen_rumble(c):
    r = c.rng
    self_ = c.emu.alloc(0x100, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [self_, F(r.uniform(-3.0, 0.9))]


S(0x433580, 'slot 0xac of this with the float', 'thiscall', None, ret=None, gen=_gen_slot)
S(0x436170, 'RumbleStartEffect: store v, store c/(c-v)', 'thiscall', None, ret=None, gen=_gen_rumble)
