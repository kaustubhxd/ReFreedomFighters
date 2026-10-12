"""specs_s627.py - band 0x421000-0x441000, batch 627 (see src/batch627.cpp).
0x423950: the receiver's slot 0x1fc writes a value through its first pointer argument; that stack address is NOT recorded
(it differs between the two runs), the other four arguments are recorded. 0x42c0d0: slot 0x1b0 answers a member (or 0),
the member's slot 0x28 (one argument) answers a value; the argument is recorded.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _gen_store(c):
    r = c.rng
    val = r.getrandbits(32)

    def h1fc(e, rr):
        e.calllog.append(('recv.1fc', 0x1fc, e.reg('ecx'), (e.arg32(1), e.arg32(2), e.arg32(3), e.arg32(4))))
        e.w32(e.arg32(0), val)                       # the callee's result goes through the pointer
        e.ret(eax=0, argbytes=20)
    recv = c.emu.fake_object('recv', 0x2000, nslots=0x800, slots={0x1fc: h1fc})   # receiver = this (its +0x1b49 is stored)
    c.emu.wbytes(recv + 0x1b49, b'\x00' * 4)
    return [recv, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _gen_chain(c):
    r = c.rng

    def h28(e, rr):
        e.calllog.append(('member.28', 0x28, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=r.getrandbits(32) & 0xffff, argbytes=4)
    member = c.emu.fake_object('member', 0x40, nslots=0x40, slots={0x28: h28})
    if r.random() < 0.2:
        ret_m = 0
    else:
        ret_m = member
    def h1b0(e, rr):
        e.calllog.append(('self.1b0', 0x1b0, e.reg('ecx'), ()))
        e.ret(eax=ret_m, argbytes=0)
    self_ = c.emu.fake_object('self', 0x40, nslots=0x200, slots={0x1b0: h1b0})
    return [self_, r.getrandbits(32)]


S(0x423950, 'store slot 0x1fc result into +0x1b49', 'thiscall', None, ret=None, gen=_gen_store)
S(0x42c0d0, 'slot 0x1b0 member, then tail slot 0x28', 'thiscall', None, ret='eax', gen=_gen_chain)
