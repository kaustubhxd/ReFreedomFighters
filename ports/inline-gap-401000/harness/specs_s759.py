"""specs_s759.py - gap band batch 759 (docs/20-gap-band-401000.md): 0x401320, cdecl (a1, out, n). 0x410de0 (cdecl, two args) is a logging
stub returning a per-case value; n is 0 to 9 (zero is the early return)."""
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
    seed = c.rng.getrandbits(32)
    ss.patch(c, 0x410de0, c.emu.stub_fn('410de0 logger', lambda e, r: (e.calllog.append(('0x410de0', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=(seed * (e.arg32(0) | 1)) & 0xffffffff, argbytes=0))))   # cdecl: the caller removes the two arguments
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    return [c.rng.getrandbits(32), _rnd(c, 0x20), c.rng.randint(0, 9)]


S(0x401320, 'CRT helper 0x401320 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 759: n calls of 0x410de0 writing one byte each')
