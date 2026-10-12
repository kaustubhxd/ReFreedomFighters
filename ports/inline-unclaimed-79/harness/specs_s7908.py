"""specs_s7908.py - unclaimed-79 batch 8 (docs/20-unclaimed-79.md): ZFFMortar::FrameUpdate (0x5dd2a0). Five flag bytes at +0x75..+0x79
(zero about one time in four each), four gate objects (slot +0x23c returns 0 or 1), the system interface's +0x9b object (slot +0x58
returns an object with slot +0xbc; slot +0x114 returns a random word), the object at +0x44 (slot +0x138), and PlayAnimation 0x5dd470
as a logging stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

PLAY = 0x5dd470


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c, name, slots):
    vt = c.emu.fake_vtable(name, 0x240, slots)
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    return o


def _frame(c):
    self_ = _rnd(c, 0x200)
    for off in (0x75, 0x76, 0x77, 0x78, 0x79):
        c.emu.w8(self_ + off, 0 if c.rng.random() < 0.25 else c.rng.getrandbits(8) | 1)
    gate_ret = [0 if c.rng.random() < 0.6 else 1 for _ in range(4)]
    for off, r in zip((0x65, 0x69, 0x6d, 0x71), gate_ret):
        o = _obj(c, 'MortarGate-%x' % off, {0x23c: logged_slot('MortarGate::slot23c', eax=r, argbytes=8)})
        c.emu.w32(self_ + off, o)
    o114 = c.rng.getrandbits(16)
    obj_bc = _obj(c, 'MortarObj-bc', {0xbc: logged_slot('MortarObj::slotbc', eax=0, argbytes=4)})
    t = _obj(c, 'SysItem-mortar', {
        0x58: logged_slot('SysItem::slot58', eax=obj_bc, argbytes=4),
        0x114: logged_slot('ZEngineDataBase::RegisterZMsg', eax=o114, argbytes=16),
    })
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    c.emu.w32(self_ + 0x5d, c.rng.getrandbits(32))
    o44 = _obj(c, 'MortarObj-44', {0x138: logged_slot('MortarObj::slot138', eax=0, argbytes=12)})
    c.emu.w32(self_ + 0x44, o44)

    def play(e, r):
        e.calllog.append(('ZFFMortar::PlayAnimation', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)
    ss.patch(c, PLAY, c.emu.stub_fn('ZFFMortar::PlayAnimation', play))
    return [self_]


S(0x5dd2a0, 'ZFFMortar::FrameUpdate() thiscall', 'thiscall', None, ret=None, gen=_frame,
  note='unclaimed-79 batch 8; flag bytes and four gates, sys object slots 0x58/0x114, object slot 0x138, PlayAnimation stub')
