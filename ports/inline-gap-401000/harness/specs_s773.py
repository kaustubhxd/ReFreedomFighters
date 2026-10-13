"""specs_s773.py - gap band batch 773 (docs/20-gap-band-401000.md): 0x410420, cdecl (p, n). 0x634dee (cdecl, two args) is a logging stub
returning a fixed block (both runs get the same address)."""
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
    blk = _rnd(c, 0x400)
    ss.patch(c, 0x634dee, c.emu.stub_fn('634dee logger', lambda e, r: (e.calllog.append(('0x634dee', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=blk, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0x18, c.rng.randint(0, 20))
    c.emu.w32(p + 0x1c, c.rng.randint(0, 20))
    return [p, c.rng.randint(0, 10)]


S(0x410420, 'CRT helper 0x410420 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 773: grow two arrays when the count fits')
