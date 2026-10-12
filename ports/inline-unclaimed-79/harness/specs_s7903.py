"""specs_s7903.py - unclaimed-79 batch 3 (docs/20-unclaimed-79.md): ZObjectives::LoadInit2 (0x577d60). Logging fake objects: the
system interface's +0x9b object (slots 0x138 returns the object esi, 0x4c returns a random dword), esi (slot 0x60), the object
at +0x1dc (slot 0x25c returns random), and the objects at +0x1d8 and +0x1d0 (slot 0xbc). The helpers 0x563610 and 0x573b20 are
patched to logging stubs. The dword at +0x94 is a 0x13300-byte object half the time (it gets the +0x132a7 store)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H_563610, H_573B20 = 0x563610, 0x573b20


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c, name, slots, size=0x260):
    vt = c.emu.fake_vtable(name, size, slots)
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    return o


def _init2(c):
    self_ = _rnd(c, 0x300)
    esi = _obj(c, 'ZObj-esi', {0x60: logged_slot('ZObj::slot60', eax=0, argbytes=12)})
    t = _obj(c, 'ZObj-sys', {
        0x138: logged_slot('SysItem::slot138', eax=esi, argbytes=0),
        0x4c: logged_slot('SysItem::slot4c', eax=c.rng.getrandbits(32), argbytes=4),
    })
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    ret25c = c.rng.getrandbits(32)
    o1dc = _obj(c, 'ZObj-1dc', {0x25c: logged_slot('ZObj::slot25c', eax=ret25c, argbytes=8)})
    o1d8 = _obj(c, 'ZObj-1d8', {0xbc: logged_slot('ZObj::slot_bc_1d8', eax=0, argbytes=4)})
    o1d0 = _obj(c, 'ZObj-1d0', {0xbc: logged_slot('ZObj::slot_bc_1d0', eax=0, argbytes=4)})
    c.emu.w32(self_ + 0x1dc, o1dc)
    c.emu.w32(self_ + 0x1d8, o1d8)
    c.emu.w32(self_ + 0x1d0, o1d0)
    c.emu.w32(self_ + 0x1d4, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x44, c.rng.getrandbits(32))
    if c.rng.random() < 0.5:
        big = c.emu.alloc(0x13300, 4)
        c.emu.w32(self_ + 0x94, big)
    else:
        c.emu.w32(self_ + 0x94, 0)

    def h563610(e, r):
        e.calllog.append(('ZObjectives::helper563610', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h573b20(e, r):
        e.calllog.append(('ZObjectives::helper573b20', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    ss.patch(c, H_563610, c.emu.stub_fn('ZObjectives::helper563610', h563610))
    ss.patch(c, H_573B20, c.emu.stub_fn('ZObjectives::helper573b20', h573b20))
    return [self_]


S(0x577d60, 'ZObjectives::LoadInit2() thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='unclaimed-79 batch 3; logging objects, helpers 0x563610 and 0x573b20 stubbed')
