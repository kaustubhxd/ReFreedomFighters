"""specs_s6544.py - unclaimed-65 batch 44 (docs/20-unclaimed-65.md, claim 24): 0x4d2280, the constructor (returns this). The callees
0x4ccba0 and 0x4ccdd0 are logging stubs for both sides (other claims; 0x4ccdd0's operator new is not run). The cookie is patched to a ret."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    ss.patch(c, 0x4ccba0, c.emu.stub_fn('4ccba0', lambda e, r: (e.calllog.append(('0x4ccba0', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4ccdd0, c.emu.stub_fn('4ccdd0', lambda e, r: (e.calllog.append(('0x4ccdd0', e.reg('ecx'),
                                                                               (e.arg32(0), e.arg32(1), e.arg32(2)))),
                                                              e.ret(eax=0, argbytes=12))))
    _flush_code(c)


def _gen(c):
    self_ = _rnd(c, 0x4100)
    return [self_]


S(0x4d2280, 'ZFFClass ctor 0x4d2280 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 44 (claim 24): constructor; helpers stubbed')
