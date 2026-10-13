"""specs_s750.py - gap band batch 750 (docs/20-gap-band-401000.md): 0x41d200. The cdecl call 0x41e010 is a logging stub (its argument is
logged, it returns 0). Global 0x6fd1a0 is zero in half the cases; otherwise it is the address of a logging stub that returns 0x1234 and
pops nothing (the tail jump's target returns to the caller of 0x41d200 directly)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x41e010, c.emu.stub_fn('41e010 logger', lambda e, r: (e.calllog.append(('0x41e010', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    tgt = c.emu.stub_fn('tail target', lambda e, r: (e.calllog.append(('tail',)), e.ret(eax=0x1234, argbytes=0))) \
        if c.rng.random() < 0.5 else 0
    c.emu.w32(0x6fd1a0, tgt)
    _flush_code(c)


S(0x41d200, 'CRT tail 0x41d200 (unknown) cdecl', 'cdecl', None, ret='eax', gen=lambda c: [], setup=_setup,
  note='gap band batch 750: tail jump through 0x6fd1a0')
