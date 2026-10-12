"""specs_s818.py - core batch 818 (docs/20-unclaimed-65.md). 0x46f510: thiscall, no arguments. It calls 0x45f3a0 with ecx = this (the callee
takes no arguments) and tail-jumps to 0x46f240 with the same ecx. Both are HOOKED by address (GUESS): each logs ecx and returns zero, popping
nothing. The object is random."""
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
    ss.patch(c, 0x45f3a0, c.emu.stub_fn('45f3a0 hook', lambda e, r: (e.calllog.append(('0x45f3a0', e.reg('ecx'))),
                                                                     e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x46f240, c.emu.stub_fn('46f240 hook', lambda e, r: (e.calllog.append(('0x46f240', e.reg('ecx'))),
                                                                     e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x46f510, 'core method 0x46f510 (unknown) thiscall no args', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x100)], setup=_setup, note='core batch 818: call 0x45f3a0, then tail jump to 0x46f240 (both hooked)')
