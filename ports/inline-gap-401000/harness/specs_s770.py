"""specs_s770.py - gap band batch 770 (docs/20-gap-band-401000.md): 0x406770, cdecl (p). The frees 0x634d52 are logging stubs; p is NULL in
one case in six."""
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
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    if c.rng.random() < 1 / 6:
        return [0]
    p = _rnd(c, 0x20)
    for off in (8, 0xc):
        c.emu.w32(p + off, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    return [p]


S(0x406770, 'CRT helper 0x406770 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 770: free two pointers, zero five dwords')
