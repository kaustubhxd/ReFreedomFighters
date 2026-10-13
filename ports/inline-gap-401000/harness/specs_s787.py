"""specs_s787.py - gap band batch 787 (docs/20-gap-band-401000.md): 0x4063d0, cdecl (p). 0x406430 (band batch 764, run for real) and the frees
0x634d52 (logging stub) are called. n is 0 to 2 (the loop runs 4n times); the record and the arrays are random."""
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
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    n = c.rng.randint(0, 2)
    p = _rnd(c, 0x40)
    c.emu.w32(p, n)
    rec = _rnd(c, 0x18 * 8 + 0x20)
    c.emu.w32(p + 4, rec)
    arr = _rnd(c, 0x80)
    for i in range(8):
        c.emu.w32(arr + 4 * i, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(p + 0x14, arr)
    c.emu.w32(p + 0x10, c.rng.choice([0, 0]))
    return [p]


S(0x4063d0, 'CRT helper 0x4063d0 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 787: per-element release (0x406430 real, free stubbed), then the arrays')
