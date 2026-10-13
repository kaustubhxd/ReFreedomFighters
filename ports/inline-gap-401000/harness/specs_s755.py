"""specs_s755.py - gap band batch 755 (docs/20-gap-band-401000.md): 0x41c750, seven plain calls then the tail jump to 0x511ad0. Each callee is a
logging stub returning 0 (other claims); the tail target returns 0x77, so eax is compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _setup(c):
    import serial_stubs as ss
    for a in (0x4fae80, 0x53ccb0, 0x49e680, 0x43db70, 0x460cb0, 0x4edef0, 0x52a2c0):
        ss.patch(c, a, c.emu.stub_fn('%x logger' % a, (lambda aa: lambda e, r: (e.calllog.append(('%x' % aa,)), e.ret(eax=0, argbytes=0)))(a)))
    ss.patch(c, 0x511ad0, c.emu.stub_fn('511ad0 logger', lambda e, r: (e.calllog.append(('511ad0',)), e.ret(eax=0x77, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x41c750, 'CRT chain 0x41c750 (unknown) plain', 'cdecl', None, ret='eax', gen=lambda c: [], setup=_setup,
  note='gap band batch 755: seven plain calls then tail jump 0x511ad0')
