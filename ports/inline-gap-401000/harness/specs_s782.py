"""specs_s782.py - gap band batch 782 (docs/20-gap-band-401000.md): 0x4057b0, cdecl (p, q). 0x405460 and 0x405240 (cdecl, one argument) are
fakes returning per-case values; 0x405690 is a logging stub. All three are cdecl (the caller cleans). q is a block whose first two dwords are random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    seed = c.rng.getrandbits(32)
    ss.patch(c, 0x405460, c.emu.stub_fn('405460 fake', lambda e, r: (e.calllog.append(('0x405460', (e.arg32(0),))),
                                                                   e.ret(eax=(seed ^ e.arg32(0)) & 0xffffffff, argbytes=0))))
    ss.patch(c, 0x405240, c.emu.stub_fn('405240 fake', lambda e, r: (e.calllog.append(('0x405240', (e.arg32(0),))),
                                                                   e.ret(eax=0 if (e.arg32(0) & 1) else 0x77, argbytes=0))))
    ss.patch(c, 0x405690, c.emu.stub_fn('405690 logger', lambda e, r: (e.calllog.append(('0x405690', (e.arg32(0),))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x4057b0, 'CRT helper 0x4057b0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=lambda c: [_rnd(c, 0x40), _rnd(c, 0x40)], setup=_setup,
  note='gap band batch 782: copy two words, two helpers, release on a zero result')
