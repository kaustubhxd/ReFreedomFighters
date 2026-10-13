"""specs_s6543.py - unclaimed-65 batch 43 (docs/20-unclaimed-65.md, claim 23): 0x4d2330, the destructor of the class with vtables 0x696220
then 0x696168. The callees 0x4cee30, 0x4cd180 and 0x4ccf60, and the slot 0xc of the object at this+0x4008, are logging stubs for both sides
(other claims). The memory writes of the destructor are compared. The cookie check is patched to a ret."""
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
    ss.patch(c, 0x4cee30, c.emu.stub_fn('4cee30', lambda e, r: (e.calllog.append(('0x4cee30', e.reg('ecx'), (e.arg32(0), e.arg32(1)))),
                                                               e.ret(eax=0, argbytes=8))))
    ss.patch(c, 0x4cd180, c.emu.stub_fn('4cd180', lambda e, r: (e.calllog.append(('0x4cd180', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4ccf60, c.emu.stub_fn('4ccf60', lambda e, r: (e.calllog.append(('0x4ccf60', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    _flush_code(c)


def _gen(c):
    vt = c.emu.fake_vtable('dtor4d2330-obj', 0x40, {
        0xc: lambda e, r: (e.calllog.append(('0xc', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    self_ = _rnd(c, 0x4100)
    c.emu.w32(self_ + 0x4008, vt)
    return [self_]


S(0x4d2330, 'ZFFClass dtor 0x4d2330 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 43 (claim 23): destructor; helpers stubbed')
