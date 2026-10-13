"""specs_s792.py - gap band batch 792 (docs/20-gap-band-401000.md): 0x4061e0, cdecl (p, out, a3, n). 0x405f20 (cdecl, two arguments) is a fake
returning -1 in one call in four, otherwise a row index 0..3 (a function of the arguments and the case seed). p[0] (the row length) is 0 to 4,
p[3] points at a 4*4*4-byte table. out holds 0x40 dwords. n is 0 to 9."""
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

    def f(e, r):
        v = hash((seed, e.arg32(1))) % 4
        r_ = -1 if (hash((seed, 'm', e.arg32(1))) % 4 == 0) else v
        e.calllog.append(('0x405f20', (e.arg32(1), r_)))
        e.ret(eax=r_ & 0xffffffff, argbytes=0)
    ss.patch(c, 0x405f20, c.emu.stub_fn('405f20 fake', f))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x20)
    c.emu.w32(p, c.rng.randint(1, 4))   # a zero row length never advances the copy (the exe loops forever on it too)
    tab = _rnd(c, 0x100)
    c.emu.w32(p + 0xc, tab)
    out = _rnd(c, 0x100)
    return [p, out, c.rng.getrandbits(32), c.rng.randint(0, 9)]


S(0x4061e0, 'CRT helper 0x4061e0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 792: row copy loop with the 0x405f20 row index')
