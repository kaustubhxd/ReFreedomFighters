"""specs_s756.py - gap band batch 756 (docs/20-gap-band-401000.md): 0x41ef80. Slot 0x54 of the global object [0x70038c] (logged, returns a
per-case value, callee pops 4) and 0x4d0b30 (a logging stub, thiscall, no args) are fakes."""
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
    ss.patch(c, 0x4d0b30, c.emu.stub_fn('4d0b30 logger', lambda e, r: (e.calllog.append(('0x4d0b30', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    vals = [c.rng.getrandbits(32) for _ in range(2)]
    vt = c.emu.fake_vtable('g756-o', 0x100, {0x54: lambda e, r: (e.calllog.append(('0x54', e.reg('ecx'), (e.arg32(0),))),
                                                                e.ret(eax=vals[0] if e.arg32(0) == 0xffffffff else vals[1], argbytes=4))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    c.emu.w32(0x70038c, o)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x31, _rnd(c, 0x40))
    return [self_]


S(0x41ef80, 'CRT helper 0x41ef80 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 756: two slot 0x54 calls around 0x4d0b30')
