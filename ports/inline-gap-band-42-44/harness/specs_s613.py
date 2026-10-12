"""specs_s613.py - band 0x421000-0x441000, batch 613 (see src/batch613.cpp).
Every slot is a recording fake: the call log holds (name, slot, ecx, args), so the ecx of each call is compared too.
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


def _gen_member(off):
    def gen(c):
        r = c.rng
        self_ = c.emu.alloc(0x200, 16)
        c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
        if r.random() < 0.8:
            o = c.emu.fake_object('mem', 0x40, nslots=0x40,
                                  slots={off: _rec('mem.%x' % off, off, 1, r.getrandbits(32))})
        else:
            o = 0
        c.emu.w32(self_ + 0x71, o)
        return [self_]
    return gen


def _gen_two(c):
    r = c.rng
    self_ = c.emu.fake_object('two', 0x40, nslots=0x60, slots={
        0x0: _rec('two.0', 0, 0, r.getrandbits(32)),
        0x4c: _rec('two.4c', 0x4c, 0, r.getrandbits(32))})
    return [self_]


S(0x428800, 'flag after slot 0x1c of this+0x71', 'thiscall', None, ret='al', gen=_gen_member(0x1c))
S(0x429ae0, 'flag after slot 0x20 of this+0x71', 'thiscall', None, ret='al', gen=_gen_member(0x20))
S(0x432cd0, 'and of slot 0 and slot 0x4c', 'thiscall', None, ret='al', gen=_gen_two)
