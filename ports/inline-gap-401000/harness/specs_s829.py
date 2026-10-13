"""specs_s829.py - core batch 829 (docs/20-unclaimed-65.md). 0x5a5650: thiscall, one stack flag word (ret 4), returns this. Every case calls 0x43de70
(HOOKED, thiscall, no arguments, logs ecx). Bit 0 of the flag selects the rest; bit 2 selects 0x4690b0 (HOOKED, cdecl two words: logs both; the
caller removes them) or 0x45c510 (HOOKED, cdecl one word: logs it; the caller removes it). Hooks return zero with argbytes 0."""
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
    ss.patch(c, 0x43de70, c.emu.stub_fn('43de70 hook', lambda e, r: (e.calllog.append(('0x43de70', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x45c510, c.emu.stub_fn('45c510 hook', lambda e, r: (e.calllog.append(('0x45c510', e.arg32(0))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4690b0, c.emu.stub_fn('4690b0 hook', lambda e, r: (e.calllog.append(('0x4690b0', e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    this = _rnd(c, 0x100)
    return [this, c.rng.getrandbits(3)]


S(0x5a5650, 'ZFFPRIVATESTDOBJ::~ZFFPRIVATESTDOBJ (unknown) thiscall one arg', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='core batch 829: flag-selected hooked cdecl calls, returns this')
