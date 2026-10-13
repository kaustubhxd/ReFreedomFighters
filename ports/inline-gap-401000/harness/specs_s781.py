"""specs_s781.py - gap band batch 781 (docs/20-gap-band-401000.md): 0x4050a0, cdecl (x). The callee 0x634e06 is the CRT ldexp import; the
harness has no stub for it, so it is a logging stub for both sides that records its three arguments (the two halves of the double and the
exponent) and returns zero. The conversion before the call (fild, fstp, fchs, the exponent) is verified; ldexp itself is unverified."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634e06, c.emu.stub_fn('ldexp model', lambda e, r: (e.calllog.append(('0x634e06', tuple(e.arg32(k) for k in range(3)))),
                                                                     e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x4050a0, 'CRT helper 0x4050a0 (unknown) cdecl', 'cdecl', None, ret=None, gen=lambda c: [c.rng.getrandbits(32)], setup=_setup,
  note='gap band batch 781: integer to double with exponent, then the ldexp stand-in 0x634e06')
