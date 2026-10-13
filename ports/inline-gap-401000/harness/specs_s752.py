"""specs_s752.py - gap band batch 752 (docs/20-gap-band-401000.md): 0x40ce80, cdecl with a second stack argument. 0x40ceb0 (five args) is a
logging stub for both sides (its own claim). The count n is 1 in a quarter of the cases (the early return)."""
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


def _gen(c):
    blk = _rnd(c, 0x40)
    n = 1 if c.rng.random() < 0.25 else c.rng.randint(0, 6)
    base = _rnd(c, 0x40)
    c.emu.w32(blk, n)
    c.emu.w32(blk + 4, base)
    c.emu.w32(blk + 8, c.rng.getrandbits(32))
    return [blk, c.rng.getrandbits(32)]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x40ceb0, c.emu.stub_fn('40ceb0 logger', lambda e, r: (e.calllog.append(('0x40ceb0', tuple(e.arg32(k) for k in range(5)))),
                                                                       e.ret(eax=0x5a5a, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x40ce80, 'CRT helper 0x40ce80 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 752: calls 0x40ceb0 with (n, b, base, base+4n, c) unless n == 1')
