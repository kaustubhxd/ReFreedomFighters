"""specs_s757.py - gap band batch 757 (docs/20-gap-band-401000.md): 0x401ef0. The cdecl 0x401970 (three args) is a logging stub; the function
then writes -1 to five fields of the block a."""
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
    ss.patch(c, 0x401970, c.emu.stub_fn('401970 logger', lambda e, r: (e.calllog.append(('0x401970', (e.arg32(1), e.arg32(2)))),
                                                                       e.ret(eax=0x1234, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x401ef0, 'CRT helper 0x401ef0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=lambda c: [_rnd(c, 0x80), c.rng.getrandbits(32)],
  setup=_setup, note='gap band batch 757: 0x401970 stub, then five fields to -1')
