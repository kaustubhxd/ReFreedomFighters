"""specs_s766.py - gap band batch 766 (docs/20-gap-band-401000.md): 0x410b50, cdecl (p). The allocator 0x634d58 (cdecl, one argument) returns a
fixed 0x100-byte block (the same address each call, so both runs agree)."""
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
    ss.patch(c, 0x634d58, c.emu.stub_fn('634d58 logger', lambda e, r: (e.calllog.append(('0x634d58', (e.arg32(0),))),
                                                                       e.ret(eax=blk, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x410b50, 'CRT helper 0x410b50 (unknown) cdecl', 'cdecl', None, ret='eax', gen=lambda c: [_rnd(c, 0x20)], setup=_setup,
  note='gap band batch 766: zero five fields, allocate 0x100, set the pointers, first byte 0')
