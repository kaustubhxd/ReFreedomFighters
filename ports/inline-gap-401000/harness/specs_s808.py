"""specs_s808.py - core batch 808 (docs/20-unclaimed-65.md). 0x485f60: thiscall with one stack word (the flag; bit 0 chooses the free call).
The object is a random block; the vtable store 0x685294 is checked through the object's first dword. 0x634273 (the CRT free) is a logging
stub that returns zero and is cdecl, so the stub pops nothing (the caller removes the two pushed words)."""
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
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    obj = _rnd(c, 0x100)
    return [obj, c.rng.getrandbits(32)]


S(0x485f60, 'core method 0x485f60 (unknown) thiscall one arg', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='core batch 808: vtable store, then the CRT free when bit 0 of the flag is set')
