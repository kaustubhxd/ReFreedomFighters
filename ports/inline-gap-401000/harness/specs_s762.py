"""specs_s762.py - gap band batch 762 (docs/20-gap-band-401000.md): 0x4103f0, cdecl (p, b). The reallocation 0x634dee is a logging stub (cdecl,
two args, caller cleans) returning a per-case pointer. The counters are chosen so both branches run (the growth test is a signed compare)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    newp = c.rng.getrandbits(32)
    ss.patch(c, 0x634dee, c.emu.stub_fn('634dee logger', lambda e, r: (e.calllog.append(('0x634dee', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=newp, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p = c.emu.alloc(0x20, 4)
    cap = c.rng.randint(-50, 2000)
    c.emu.w32(p, c.rng.getrandbits(32))
    c.emu.w32(p + 4, c.rng.randint(-50, 2000) & 0xffffffff)
    c.emu.w32(p + 8, cap & 0xffffffff)
    return [p, c.rng.randint(-100, 100) & 0xffffffff]


S(0x4103f0, 'CRT helper 0x4103f0 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 762: growth step with reallocation (stub)')
