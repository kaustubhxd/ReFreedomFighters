"""specs_s819.py - core batch 819 (docs/20-unclaimed-65.md). 0x582790 and 0x5c5590: thiscall, one stack argument (the DBREAD reference, a random
block), each a bare frame and a tail jump to 0x584b40 and 0x5c56f0. Both targets are HOOKED by address (GUESS): each logs ecx and its
argument, then pops that argument (ret 4, the argument the target would read)."""
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
    ss.patch(c, 0x584b40, c.emu.stub_fn('584b40 hook', lambda e, r: (e.calllog.append(('0x584b40', e.reg('ecx'), e.arg32(0))),
                                                                     e.ret(eax=0, argbytes=4))))
    ss.patch(c, 0x5c56f0, c.emu.stub_fn('5c56f0 hook', lambda e, r: (e.calllog.append(('0x5c56f0', e.reg('ecx'), e.arg32(0))),
                                                                     e.ret(eax=0, argbytes=4))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    return [_rnd(c, 0x100), _rnd(c, 0x40)]


S(0x582790, 'CExplode::CopyEventDataBlock (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 819: tail jump to 0x584b40 (hooked)')

S(0x5c5590, 'CTargetObtained::CopyEventDataBlock (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 819: tail jump to 0x5c56f0 (hooked)')
