"""specs_s798.py - gap band batch 798 (docs/20-gap-band-401000.md): 0x408e20, cdecl (p). The count at +8 and +0x1c are 0 to 3; the arrays at +0x18
and +0x20 hold pointers or 0; the frees are logging stubs. p is NULL in one case in six."""
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
    if c.rng.random() < 1 / 6:
        return [0]
    p = _rnd(c, 0x80)
    A = _rnd(c, 0x40)
    B = _rnd(c, 0x40)
    na, nb = c.rng.randint(0, 3), c.rng.randint(0, 3)
    for i in range(4):
        c.emu.w32(A + 4 * i, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
        c.emu.w32(B + 4 * i, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(p + 8, na)
    c.emu.w32(p + 0x18, A)
    c.emu.w32(p + 0x1c, nb)
    c.emu.w32(p + 0x20, B)
    return [p]


S(0x408e20, 'CRT helper 0x408e20 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 798: free two arrays and their elements, zero 0x1d dwords, free the record')
