"""specs_s1007.py - unclaimed-02 batch 7 (docs/20-unclaimed-02.md): ZItemTemplateWeapon::CreateItem (0x46d5d0). The callee
ZItemTemplate::CreateItem (0x46d530, inventory's port) is patched to a logging stub for both sides; its return value is
random, so eax is compared through CreateItem."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

CALLEE = 0x46d530


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _create(c):
    self_ = _rnd(c, 0x100)
    group = _rnd(c, 0x100)
    t = _rnd(c, 0x100)
    c.emu.w32(t + 0xadc, c.rng.getrandbits(32))
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    retv = c.rng.getrandbits(32)

    def h(e, r):
        e.calllog.append(('ZItemTemplate::CreateItem stub', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=retv, argbytes=8)
    ss.patch(c, CALLEE, c.emu.stub_fn('ZItemTemplate::CreateItem stub', h))
    return [self_, group, c.rng.getrandbits(32)]


S(0x46d5d0, 'ZItemTemplateWeapon::CreateItem(ZGROUP*, unsigned int) thiscall', 'thiscall', None, ret='eax', gen=_create,
  note='unclaimed-02 batch 7; calls ZItemTemplate::CreateItem(this, [sys+0x9b]+0xadc, arg), returns its eax')
