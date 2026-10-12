"""specs_s7922.py - unclaimed-79 batch 22 (docs/20-unclaimed-79.md, gap band): ZPlayer::ForceRHandItem (0x4836f0). Logging fake vtables:
this (slot +0x510 returns 0, 1 or 2; +0x45c and +0x520 log), the system interface's +0x9b object (slot +0x4c returns a random dword), and
the item (slot +0x2d0 logs). Item null about one time in four; flag random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot


def _blk(c, n=0x200):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fh(c):
    self_ = _blk(c)
    vt = c.emu.fake_vtable('ZPlayer-rhand', 0x240, {
        0x510: logged_slot('ZPlayer::slot510', eax=c.rng.choice([0, 1, 2]), argbytes=0),
        0x45c: logged_slot('ZPlayer::slot45c', eax=0, argbytes=8),
        0x520: logged_slot('ZPlayer::slot520', eax=0, argbytes=4),
    })
    c.emu.w32(self_, vt)
    item = _blk(c, 0x100) if c.rng.random() < 0.75 else 0
    if item:
        vti = c.emu.fake_vtable('ZItem-rhand', 0x240, {0x2d0: logged_slot('ZItem::slot2d0', eax=0, argbytes=8)})
        c.emu.w32(item, vti)
    t = _blk(c, 0x100)
    vtt = c.emu.fake_vtable('SysItem-rhand', 0x240, {0x4c: logged_slot('SysItem::slot4c', eax=c.rng.getrandbits(32), argbytes=4)})
    c.emu.w32(t, vtt)
    sys_ = _blk(c, 0x200)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    flag = c.rng.choice([0, 0, 1])
    return [self_, item, flag]


S(0x4836f0, 'ZPlayer::ForceRHandItem(ZItem*, bool) thiscall', 'thiscall', None, ret=None, gen=_fh,
  note='unclaimed-79 batch 22; slot 0x510 gate, 0x45c with 6 or 0xa, or the null-item and item paths')
