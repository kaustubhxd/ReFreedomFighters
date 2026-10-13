"""specs_s789.py - gap band batch 789 (docs/20-gap-band-401000.md): 0x410280, cdecl (p, a2). 0x634d58 (cdecl, one argument) is a fake returning a
fixed block per call size (the same block for the same size, so both runs agree). p is NULL in one case in six."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    blocks = {}

    def alloc_fake(e, r):
        sz = e.arg32(0)
        if sz not in blocks:
            blocks[sz] = e.alloc(0x100, 4) if False else None
        e.calllog.append(('0x634d58', (sz,)))
        e.ret(eax=(0x30000000 + sz * 16) & 0xffffffff, argbytes=0)
    ss.patch(c, 0x634d58, c.emu.stub_fn('634d58 fake', alloc_fake))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    if c.rng.random() < 1 / 6:
        return [0, c.rng.getrandbits(32)]
    p = c.emu.alloc(0x200, 4)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    return [p, c.rng.getrandbits(32)]


S(0x410280, 'CRT helper 0x410280 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 789: zero a record, three allocations, store the pointers')
