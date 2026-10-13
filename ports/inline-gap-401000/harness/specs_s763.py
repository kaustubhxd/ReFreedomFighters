"""specs_s763.py - gap band batch 763 (docs/20-gap-band-401000.md): 0x407980, cdecl (p, b, c). 0x40f850 (cdecl, two args) is a logging stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x40f850, c.emu.stub_fn('40f850 logger', lambda e, r: (e.calllog.append(('0x40f850', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = c.emu.alloc(0x20, 4)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    return [p, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x407980, 'CRT helper 0x407980 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 763: zero five fields, set two, call 0x40f850 with (p, 2b)')
