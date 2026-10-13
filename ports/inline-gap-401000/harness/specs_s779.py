"""specs_s779.py - gap band batch 779 (docs/20-gap-band-401000.md): 0x41fe80, thiscall. The six 0x4cbec0 calls run as the exe code on a 0x2000
block (its list heads are random, so a non-empty head reaches the delete helper 0x634273, a logging stub). The tail target 0x42bae0 is a
logging stub returning 0x55 (thiscall, no arguments, the tail jump keeps the caller's return)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    self_ = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    for off in (0x1e0b, 0x1d71, 0x1cf1, 0x1c71, 0x1bf1, 0x1b71):
        c.emu.w32(self_ + off, c.rng.choice([self_ + off + 4, c.rng.getrandbits(32) | 1]))
    return [self_]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x42bae0, c.emu.stub_fn('42bae0 tail', lambda e, r: (e.calllog.append(('0x42bae0', e.reg('ecx'))), e.ret(eax=0x55, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x41fe80, 'CRT helper 0x41fe80 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band batch 779: six release calls then a tail jump')
