"""specs_s624.py - band 0x421000-0x441000, batch 624 (see src/batch624.cpp). The member at this+0xd (possibly null) has slot 0x20,
recorded with its receiver and its one argument (both the member). Return value: al = 1.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _gen(c):
    r = c.rng
    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    mem = c.emu.fake_object('mem20', 0x40, nslots=0x40, slots={0x20: _rec('mem.20', 0x20, 1, r.getrandbits(32))}) \
        if r.random() < 0.8 else 0
    c.emu.w32(self_ + 0xd, mem)
    return [self_]


S(0x429b10, 'member slot 0x20 (member as receiver and argument), byte +0x1b1 = 0, return 1', 'thiscall', None, ret='al', gen=_gen)
S(0x429b30, 'member slot 0x20 (member as receiver and argument), byte +0x45 = 0, return 1', 'thiscall', None, ret='al', gen=_gen)
