"""specs_s2808.py - unclaimed-28 batch 8 (docs/20-unclaimed-28.md): ZFollowGeom::Load (0x4c5990). The function pointer at 0x7003b0
points at a logging no-argument stub; the helper 0x4e5e60 is patched to a logging stub that returns a random dword; the load
game is a logging fake vtable with slot +0x6c."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

HELPER = 0x4e5e60


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    self_ = _rnd(c, 0x100)
    fp = c.emu.stub_fn('ZFollowGeom::fnptr', lambda e, r: (e.calllog.append(('ZFollowGeom::fnptr',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, fp)
    retv = c.rng.getrandbits(32)

    def h(e, r):
        e.calllog.append(('ZFollowGeom::helper4e5e60', e.reg('ecx')))
        e.ret(eax=retv, argbytes=0)
    ss.patch(c, HELPER, c.emu.stub_fn('ZFollowGeom::helper4e5e60', h))
    vt = c.emu.fake_vtable('ZLoadGame-followgeom', 0x1c, {0x6c: logged_slot('ZLoadGame::slot6c', eax=0, argbytes=4)})
    ld = _rnd(c, 0x100)
    c.emu.w32(ld, vt)
    return [self_, ld]


S(0x4c5990, 'ZFollowGeom::Load(ZLoadGame*) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-28 batch 8; pointer call at 0x7003b0, helper 0x4e5e60 (null this) stored at +0x48, load slot +0x6c with +0x4c')
