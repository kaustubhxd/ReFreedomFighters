"""specs_s823.py - core batch 823 (docs/20-unclaimed-65.md). 0x584450: thiscall, no arguments. [[this+0x44]+8]+0x3c is a random dword, and the
byte at this+0x5d is random. 0x5833e0 is HOOKED by address (GUESS): thiscall with two stack words (callee pops 8); it logs ecx and both words."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x5833e0, c.emu.stub_fn('5833e0 hook', lambda e, r: (
        e.calllog.append(('0x5833e0', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    blk = _rnd(c, 0x40)
    c.emu.w32(blk + 0x3c, c.rng.getrandbits(32))
    mid = _rnd(c, 0x40)
    c.emu.w32(mid + 8, blk)
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x44, mid)
    c.emu.wbytes(this + 0x5d, bytes([c.rng.choice([0, 1, 0x80])]))
    return [this]


S(0x584450, 'CExplode::Init2 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 823: bit 10 test and a call to 0x5833e0 (hooked)')
