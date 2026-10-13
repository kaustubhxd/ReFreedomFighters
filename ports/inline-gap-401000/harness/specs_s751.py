"""specs_s751.py - gap band batch 751 (docs/20-gap-band-401000.md): 0x410490, cdecl, one argument. The CRT free 0x634d52 is a logging stub.
0x410470 is the exe code (run for real). Arguments: a is a block whose first dword is a pointer (or 0) and which is 0 in one case in ten."""
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
    if c.rng.random() < 0.1:
        return [0]
    blk = _rnd(c, 0x40)
    v = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    c.emu.w32(blk, v)
    return [blk]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634d52, c.emu.stub_fn('634d52 logger', lambda e, r: (e.calllog.append(('0x634d52', (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x410490, 'CRT helper 0x410490 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 751: frees [a] (stub) then calls 0x410470')
