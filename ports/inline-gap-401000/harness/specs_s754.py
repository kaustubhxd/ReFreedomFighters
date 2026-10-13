"""specs_s754.py - gap band batch 754 (docs/20-gap-band-401000.md): 0x41ef50, thiscall, void. The counter at +0x45 is slot 4 of the array at
+0x35 (as in the exe): the spec keeps it a small count, the other slots are pointers or 0; both sides' reads and writes are compared through memory. 0x4d0f80 is a
logging stub (thiscall, ecx logged); 0x634273 (cdecl, two arguments, caller cleans) is a logging stub."""
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
    self_ = _rnd(c, 0x100)
    # slot 4 of the array (at +0x45) is the counter itself: it keeps the count, the other slots hold a pointer or 0
    for i in range(10):
        if i == 4:
            continue
        c.emu.w32(self_ + 0x35 + 4 * i, 0 if c.rng.random() < 0.3 else _rnd(c, 0x20))
    c.emu.w32(self_ + 0x45, c.rng.randint(1, 9))
    return [self_]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x4d0f80, c.emu.stub_fn('4d0f80 logger', lambda e, r: (e.calllog.append(('0x4d0f80', e.reg('ecx'))),
                                                                       e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x41ef50, 'CRT helper 0x41ef50 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 754: decrement, release the slot pointer if nonzero')
