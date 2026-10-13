"""specs_s778.py - gap band batch 778 (docs/20-gap-band-401000.md): 0x40c420, cdecl (p). The frees 0x634d52 and the helper 0x4079c0
(cdecl, one argument) are logging stubs. Fields +0xc and +0x28 are pointers or 0; p is NULL in one case in six."""
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


def _gen(c):
    if c.rng.random() < 1 / 6:
        return [0]
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0xc, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(p + 0x28, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    return [p]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4079c0, c.emu.stub_fn('4079c0 logger', lambda e, r: (e.calllog.append(('0x4079c0', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x40c420, 'CRT helper 0x40c420 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 778: free two members, helper, zero 13 dwords, free the block')
