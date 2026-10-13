"""specs_s812.py - core batch 812 (docs/20-unclaimed-65.md). 0x4fc040: thiscall, one stack argument (source), ret 4; copies the dword at +0x78,
the words at +0x7c, +0x7e, +0x80, +0x82 and the dword at +0x6e. 0x522740: thiscall, one stack flag word, ret 4; the vtable store 0x6a06f4,
a call to 0x51aa60 (no arguments; a logging stub here, another claim), then the CRT free 0x634273 when bit 0 is set (logging stub, cdecl)."""
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


def _setup_522(c):
    import serial_stubs as ss
    ss.patch(c, 0x51aa60, c.emu.stub_fn('51aa60 logger', lambda e, r: (e.calllog.append(('0x51aa60', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x4fc040, 'CMAINCAMERACONTROL::CopyData (unknown) thiscall one arg', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x200), _rnd(c, 0x200)], note='core batch 812: copy the camera control fields from the source')


S(0x522740, 'ZTankIf::~ZTankIf (unknown) thiscall one arg', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x200), c.rng.getrandbits(32)], setup=_setup_522,
  note='core batch 812: vtable store, slot call 0x51aa60, conditional CRT free')
