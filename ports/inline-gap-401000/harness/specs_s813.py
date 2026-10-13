"""specs_s813.py - core batch 813 (docs/20-unclaimed-65.md). 0x5c56c0: thiscall, one stack argument (never read), ret 4; returns al = 1.
It clears bit 6 of this+4, then calls 0x6352f0 and 0x5c56f0 with ecx = this and a pointer to a local dword (both callees pop their
argument). Both callees are hooked by address (GUESS): the spec stubs 0x6352f0 to write a random dword through the pointer and 0x5c56f0
to log its ecx. The object and the argument are random blocks."""
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
    seed = 0x0badf00d   # the value 0x6352f0 writes through its pointer (fixed; the flag argument is random)
    ss.patch(c, 0x6352f0, c.emu.stub_fn('6352f0 hook', lambda e, r: (e.calllog.append(('0x6352f0', e.reg('ecx'))),
                                                                     e.w32(e.arg32(0), seed), e.ret(eax=0, argbytes=4))))
    ss.patch(c, 0x5c56f0, c.emu.stub_fn('5c56f0 hook', lambda e, r: (e.calllog.append(('0x5c56f0', e.reg('ecx'), e.r32(e.arg32(0)))),
                                                                     e.ret(eax=0, argbytes=4))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    obj = _rnd(c, 0x200)
    return [obj, c.rng.getrandbits(32)]


S(0x5c56c0, 'core method 0x5c56c0 (unknown) thiscall one arg', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='core batch 813: bit clear, two hooked calls on a local, returns 1')
