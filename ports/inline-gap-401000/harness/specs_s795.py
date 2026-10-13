"""specs_s795.py - gap band batch 795 (docs/20-gap-band-401000.md): 0x401820, cdecl (p, size). 0x634d58 (cdecl, one argument) returns a fixed
block; the record's fields are chosen so both branches (reallocate or not) run."""
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
    blk = _rnd(c, 0x400)
    ss.patch(c, 0x634d58, c.emu.stub_fn('634d58 fake', lambda e, r: (e.calllog.append(('0x634d58', (e.arg32(0),))), e.ret(eax=blk, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = _rnd(c, 0x80)
    c.emu.w32(p + 0x44, c.rng.choice([0, _rnd(c, 0x40)]))
    c.emu.w32(p + 0x48, c.rng.randint(0, 0x40))
    c.emu.w32(p + 0x4c, c.rng.randint(0, 0x40))
    c.emu.w32(p + 0x50, c.rng.randint(0, 0x40))
    c.emu.w32(p + 0x54, c.rng.choice([0, _rnd(c, 0x20)]))
    return [p, c.rng.randint(0, 0x30)]


S(0x401820, 'CRT helper 0x401820 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 795: bump allocator step with an optional record allocation')
