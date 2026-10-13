"""specs_s774.py - gap band batch 774 (docs/20-gap-band-401000.md): 0x4102f0, cdecl (p). The frees 0x634d52 are logging stubs; p is NULL in
one case in six. The block's pointer fields are random, zero in about a third of the cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    if c.rng.random() < 1 / 6:
        return [0]
    p = c.emu.alloc(0x180, 4)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x180)))
    for off in (0, 0x10, 0x14):
        c.emu.w32(p + off, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    return [p]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x4102f0, 'CRT helper 0x4102f0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 774: free three pointers, zero 0x5a dwords')
