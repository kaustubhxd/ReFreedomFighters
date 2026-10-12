"""specs_s7906.py - unclaimed-79 batch 6 (docs/20-unclaimed-79.md): ZMatPosAnim::Load (0x4a5ae0). The load game is a logging fake
vtable (slots 0x44, 0x48, 0x50, 0x58, 0x68, 0x6c, 0x74). The object at +0x44 has slot 0x4c returning a random dword. Helpers
0x4e7c40 and 0x4e78c0 are logging stubs. RegisterMessages (0x4a5c20) runs as the original code, so the system interface global
gets a fake object whose +0x9b has slot 0x114 (four arguments)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H_4E7C40, H_4E78C0 = 0x4e7c40, 0x4e78c0


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    self_ = _rnd(c, 0x300)
    ld_slots = {}
    for off, name, nargs in [(0x44, 'slot44', 4), (0x48, 'slot48', 4), (0x50, 'slot50', 4), (0x58, 'slot58', 4),
                             (0x68, 'slot68', 4), (0x6c, 'slot6c', 4), (0x74, 'slot74', 4)]:
        ld_slots[off] = logged_slot('ZLoadGame::' + name, eax=0, argbytes=nargs)
    ld_vt = c.emu.fake_vtable('ZLoadGame-matpos', 0x40, ld_slots)
    ld = _rnd(c, 0x100)
    c.emu.w32(ld, ld_vt)
    key_obj = _rnd(c, 0x100)
    key_vt = c.emu.fake_vtable('MatPosKeyObj', 0x20, {0x4c: logged_slot('KeyObj::slot4c', eax=c.rng.getrandbits(32), argbytes=4)})
    c.emu.w32(key_obj, key_vt)
    c.emu.w32(self_ + 0x44, key_obj)

    def h4e7c40(e, r):
        e.calllog.append(('ZMatPosAnim::helper4e7c40', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h4e78c0(e, r):
        e.calllog.append(('ZMatPosAnim::helper4e78c0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, H_4E7C40, c.emu.stub_fn('ZMatPosAnim::helper4e7c40', h4e7c40))
    ss.patch(c, H_4E78C0, c.emu.stub_fn('ZMatPosAnim::helper4e78c0', h4e78c0))
    sysvt = c.emu.fake_vtable('SysItem-114', 0x50, {0x114: logged_slot('ZEngineDataBase::RegisterZMsg', eax=0x1234, argbytes=16)})
    t = _rnd(c, 0x100)
    c.emu.w32(t, sysvt)
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    return [self_, ld]


S(0x4a5ae0, 'ZMatPosAnim::Load(ZLoadGame*) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-79 batch 6; about 25 load-game field reads, key-object slot 0x4c, helpers 0x4e7c40 and 0x4e78c0, RegisterMessages')
