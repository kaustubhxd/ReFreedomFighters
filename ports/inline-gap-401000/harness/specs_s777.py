"""specs_s777.py - gap band batch 777 (docs/20-gap-band-401000.md): 0x41cf80, cdecl with no arguments. The globals 0x6fcd44 (a block for the
release 0x634273, a logging stub) and 0x6fcd48 (an object with slot 0x10, no args, and slot 0 with one arg; both log) are set per case;
either may be zero."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    vt = c.emu.fake_vtable('g777-o', 0x100, {
        0x10: lambda e, r: (e.calllog.append(('0x10', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1],
        0x0: lambda e, r: (e.calllog.append(('0x0', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1]})
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    c.emu.w32(0x6fcd48, o if c.rng.random() < 0.7 else 0)
    blk = c.emu.alloc(0x20, 4)
    c.emu.w32(0x6fcd44, blk if c.rng.random() < 0.6 else 0)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x41cf80, 'CRT helper 0x41cf80 (unknown) cdecl', 'cdecl', None, ret=None, gen=lambda c: [], setup=_setup,
  note='gap band batch 777: release a global block and a global object')
