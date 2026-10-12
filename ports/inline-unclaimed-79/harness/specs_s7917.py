"""specs_s7917.py - unclaimed-79 batch 17 (docs/20-unclaimed-79.md, gap band): ZPlayer::SetContactGeom (0x484f30). The system
interface's +0x9b object returns a geometry (or zero) for the id; helper 0x4dafb0 returns a record (or zero) and 0x4db6c0 logs; this's
slot +0x428 returns the id half the time. Helpers are call-recording stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H_DAF, H_6C0 = 0x4dafb0, 0x4db6c0


def _blk(c, n=0x600):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setcontact(c):
    self_ = _blk(c)
    gid = c.rng.getrandbits(32)
    geom_has = c.rng.random() < 0.75
    geom = _blk(c, 0x40)
    rec = _blk(c, 0x40)
    cur = gid if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    vtT = c.emu.fake_vtable('SysItem-geom', 0x240, {
        0x58: logged_slot('SysItem::slot58-geom', eax=geom if geom_has else 0, argbytes=4)})
    t = _blk(c, 0x40)
    c.emu.w32(t, vtT)
    sys_ = _blk(c, 0x200)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    c.emu.w32(geom + 8, _blk(c, 0x40))
    rec_ok = c.rng.random() < 0.7
    ss.patch(c, H_DAF, c.emu.stub_fn('ZPlayer::helper4dafb0', lambda e, r: (
        e.calllog.append(('ZPlayer::helper4dafb0', e.reg('ecx'))), e.ret(eax=rec if rec_ok else 0, argbytes=0))))
    ss.patch(c, H_6C0, c.emu.stub_fn('ZPlayer::helper4db6c0', lambda e, r: (
        e.calllog.append(('ZPlayer::helper4db6c0', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    vtS = c.emu.fake_vtable('ZPlayer-contact', 0x480, {0x428: logged_slot('ZPlayer::slot428', eax=cur, argbytes=0)})
    c.emu.w32(self_, vtS)
    return [self_, gid]


S(0x484f30, 'ZPlayer::SetContactGeom(unsigned int) thiscall', 'thiscall', None, ret=None, gen=_setcontact,
  note='unclaimed-79 batch 17; system lookup, helpers 0x4dafb0 and 0x4db6c0 stubbed, slot 0x428 compare')
