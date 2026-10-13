"""specs_s1005.py - unclaimed-02 batch 5 (docs/20-unclaimed-02.md): CExplode::Init2 (0x584450). Its callee
CExplode::Explode (0x5833e0, not ported) is patched to a logging stub for both sides, so only the call and its
arguments are compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

EXPLODE = 0x5833e0


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init2(c):
    self_ = _rnd(c, 0x100)
    mid = _rnd(c, 0x100)
    inner = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x44, mid)
    c.emu.w32(mid + 8, inner)
    c.emu.w32(inner + 0x3c, c.rng.getrandbits(32))
    c.emu.w8(self_ + 0x5d, c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)]))

    def h(e, r):
        e.calllog.append(('CExplode::Explode', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)
    ss.patch(c, EXPLODE, c.emu.stub_fn('CExplode::Explode stub', h))
    return [self_]


S(0x584450, 'CExplode::Init2() thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='unclaimed-02 batch 5; calls CExplode::Explode(this, 0, 0) when bit 10 of inner dword is clear and byte +0x5d set')
