"""specs_s7915.py - unclaimed-79 batch 15 (docs/20-unclaimed-79.md, gap band): ZPlayer::CopyData (0x4827c0). The base copy 0x462000
and the helper 0x4dc630 are call-recording stubs; the object's slot +0x20 returns a second object whose +8 feeds the last helper."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss


def _blk(c, n=0x200):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    geom = _blk(c, 0x80)
    r = _blk(c, 0x40)
    r8 = _blk(c, 0x40)
    c.emu.w32(r + 8, r8)
    self_ = _blk(c)
    m8 = _blk(c, 0x40)
    c.emu.w32(self_ + 8, m8)
    vt = c.emu.fake_vtable('ZPlayer-copy', 0x90, {0x20: logged_slot('ZPlayer::slot20', eax=r, argbytes=0)})
    c.emu.w32(self_, vt)
    ss.patch(c, 0x462000, c.emu.stub_fn('ZPlayer::base462000', lambda e, r_: (
        e.calllog.append(('ZPlayer::base462000', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))))
    ss.patch(c, 0x4dc630, c.emu.stub_fn('ZPlayer::helper4dc630', lambda e, r_: (
        e.calllog.append(('ZPlayer::helper4dc630', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    return [self_, geom]


S(0x4827c0, 'ZPlayer::CopyData(const ZGEOM*) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-79 batch 15; base copy and 0x4dc630 stubbed; slot +0x20 result feeds the last helper')
