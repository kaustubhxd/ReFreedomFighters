"""specs_s767.py - gap band batch 767 (docs/20-gap-band-401000.md): 0x40f850, cdecl (p, n). The allocator 0x634df4 (cdecl, two args) returns a
fixed block; 0x40f890 (cdecl, three args) is a logging stub."""
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
    blk = _rnd(c, 0x100)
    ss.patch(c, 0x634df4, c.emu.stub_fn('634df4 logger', lambda e, r: (e.calllog.append(('0x634df4', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=blk, argbytes=0))))
    ss.patch(c, 0x40f890, c.emu.stub_fn('40f890 logger', lambda e, r: (e.calllog.append(('0x40f890', (e.arg32(0), e.arg32(1), e.arg32(2)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x40f850, 'CRT helper 0x40f850 (unknown) cdecl', 'cdecl', None, ret=None, gen=lambda c: [_rnd(c, 0x20), c.rng.getrandbits(16)], setup=_setup,
  note='gap band batch 767: two allocations and the 0x40f890 call')
