"""specs_s623.py - band 0x421000-0x441000, batch 623 (see src/batch623.cpp). Floats are passed with F(x).
0x428960 calls the member's slot 0x1c with (receiver = this, one argument = member): recorded with its ecx.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
from pe_emu import F  # noqa: E402


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_member(c):
    r = c.rng
    self_ = _block(c, 0x200)
    if r.random() < 0.8:
        mem = c.emu.fake_object('mem1c', 0x40, nslots=0x40, slots={0x1c: _rec('mem.1c', 0x1c, 1, r.getrandbits(32))})
    else:
        mem = 0
    c.emu.w32(self_ + 0x71, mem)
    return [self_]


def _gen_flag(c):
    r = c.rng
    self_ = _block(c, 0x100)
    c.emu.w32(self_ + 0x18, r.getrandbits(32))
    return [self_, r.choice((0, 1, r.getrandbits(32)))]


def _gen_four(c):
    r = c.rng
    self_ = _block(c, 0xa00)
    return [self_, F(r.uniform(-50, 50)), F(r.uniform(-50, 50)), F(r.uniform(-50, 50)), F(r.uniform(-50, 50))]


S(0x428960, 'member slot 0x1c with this, byte +0xb1 = (result == 0)', 'thiscall', None, ret=None, gen=_gen_member)
S(0x43e5f0, 'ZHELPER::DispSphere: set/clear bit 1 of dword +0x18 unless bits 2/3 set', 'thiscall', None, ret=None, gen=_gen_flag)
S(0x42fb60, 'store four floats at +0x9a7..+0x9b3', 'thiscall', None, ret=None, gen=_gen_four)
