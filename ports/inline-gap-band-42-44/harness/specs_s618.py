"""specs_s618.py - band 0x421000-0x441000, batch 618 (see src/batch618.cpp).
Float results come back in st0 (ret='st0'). The float tables hold finite random values.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
from pe_emu import F  # noqa: E402

SYS_GLOBAL = 0x70039c


def _rec(name, off, nargs, ret, retst0=False):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_void(c):
    _block(c, 0x40)
    return [_block(c, 0x40)]


def _gen_table(off):
    def gen(c):
        r = c.rng
        self_ = _block(c, 0x80)
        c.emu.w32(self_ + 0x5d, r.randint(-1, 4) & 0xffffffff)
        for k in range(8):
            c.emu.wf32(self_ + off + 4 * k, r.uniform(-100.0, 100.0))
        return [self_, r.randint(-1, 5) & 0xffffffff]   # the table's index range (a wild index reads outside the block)
    return gen


def _gen_slot8(c):
    r = c.rng
    o = c.emu.fake_object('member', 0x40, nslots=0x20, slots={8: _rec('member.8', 8, 3, 0)})
    self_ = _block(c, 0x80)
    c.emu.w32(self_ + 0x65, o)
    return [self_, r.getrandbits(32)]


def _gen_ts(c):
    r = c.rng
    self_ = c.emu.fake_object('ts', 0x40, nslots=0x80,
                              slots={0x1bc: _rec('ts.1bc', 0x1bc, 2, r.getrandbits(31))})
    return [self_, r.getrandbits(32), r.getrandbits(32)]


S(0x435ba0, 'set vtable 0x67a5d8, clear 0x7003a0', 'thiscall', None, ret=None, gen=_gen_void)
S(0x435e30, 'float table at +0xd with count +0x5d', 'thiscall', None, ret='st0', gen=_gen_table(0xd))
S(0x435e50, 'float table at +0x15 with count +0x5d', 'thiscall', None, ret='st0', gen=_gen_table(0x15))
S(0x436130, 'slot 8 of member at +0x65 with (arg, 0, 1.0)', 'thiscall', None, ret=None, gen=_gen_slot8)
S(0x42cb70, 'TimeStampCounter: slot 0x1bc, float result', 'thiscall', None, ret='st0', gen=_gen_ts)
