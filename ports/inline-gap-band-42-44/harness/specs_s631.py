"""specs_s631.py - band 0x421000-0x441000, batch 631 (see src/batch631.cpp).
0x42c100: receiver slots 0x1b0 (member or 0) and the member's slot 0x24 (one argument, recorded). Result not compared (void).
0x422b50: the receiver's slot 0x1fc writes a value through its first pointer (not recorded: a stack address); the other four
arguments are recorded. The returned value is compared.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _gen_chain(c):
    r = c.rng

    def h24(e, rr):
        e.calllog.append(('member.24', 0x24, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    member = c.emu.fake_object('member24', 0x40, nslots=0x40, slots={0x24: h24})

    answer = member if r.random() < 0.8 else 0      # fixed for the run: the same member both times, or none
    def h1b0(e, rr):
        e.calllog.append(('self.1b0', 0x1b0, e.reg('ecx'), ()))
        e.ret(eax=answer, argbytes=0)
    self_ = c.emu.fake_object('self131', 0x40, nslots=0x200, slots={0x1b0: h1b0})
    return [self_, r.choice((0, 0, 1, r.getrandbits(32)))]


def _gen_rand(c):
    r = c.rng
    val = r.getrandbits(32)

    def h1fc(e, rr):
        e.calllog.append(('recv.1fc', 0x1fc, e.reg('ecx'), (e.arg32(1), e.arg32(2), e.arg32(3), e.arg32(4))))
        e.w32(e.arg32(0), val)
        e.ret(eax=0, argbytes=20)
    recv = c.emu.fake_object('recv422', 0x2000, nslots=0x800, slots={0x1fc: h1fc})
    c.emu.w32(recv + 0x1b49, r.getrandbits(32))
    return [recv, r.getrandbits(32), r.getrandbits(32)]


S(0x42c100, 'flag, then slot 0x1b0 twice; tail slot 0x24 with the flag', 'thiscall', None, ret=None, gen=_gen_chain)
S(0x422b50, 'LCG step; slot 0x1fc (&out, 4, 0x12, a, b); returns out', 'thiscall', None, ret='eax', gen=_gen_rand)
