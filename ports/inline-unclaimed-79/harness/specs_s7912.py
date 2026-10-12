"""specs_s7912.py - unclaimed-79 batch 12 (docs/20-unclaimed-79.md): ZFFSearchLightGroup::Load (0x5c7220). SEH frame not reproduced
(fs:[0] writes not compared). The load game is a logging fake vtable (slot +0x48 writes the record count, slots +0x40 write a
random dword through their pointer, the others log). ZFFSearchLightGroup::LoadSpot (0x5c73f0) runs as original code; the allocator
(0x41e290) and the REFTAB constructor (0x4ccbe0) are logging stubs (the allocator returns zero about one time in three)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

ALLOC, CTOR = 0x41e290, 0x4ccbe0


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    self_ = _rnd(c, 0x200)
    cnt = c.rng.randint(0, 2)

    def w40(e, r):
        p = e.arg32(0)
        e.calllog.append(('SLLoad::slot40', e.reg('ecx')))
        e.w32(p, c.rng.getrandbits(32))
        e.ret(eax=0, argbytes=4)

    def w48(e, r):
        p = e.arg32(0)
        e.calllog.append(('SLLoad::slot48', e.reg('ecx')))
        e.w32(p, cnt)
        e.ret(eax=0, argbytes=4)

    vtL = c.emu.fake_vtable('SLLoad', 0x30, {
        0x40: w40, 0x48: w48,
        0x50: logged_slot('SLLoad::slot50', eax=0, argbytes=4),
        0x68: logged_slot('SLLoad::slot68', eax=0, argbytes=4),
        0x70: logged_slot('SLLoad::slot70', eax=0, argbytes=4),
    })
    ld = _rnd(c, 0x100)
    c.emu.w32(ld, vtL)
    obj60 = _rnd(c, 0x100)
    vt60 = c.emu.fake_vtable('SLRecord', 0x10, {0x4: logged_slot('SLRecord::slot4', eax=0, argbytes=4)})
    c.emu.w32(obj60, vt60)
    c.emu.w32(self_ + 0x60, obj60)
    t = _rnd(c, 0x100)
    vtT = c.emu.fake_vtable('SLSys', 0x240, {0x58: logged_slot('SLSys::slot58', eax=c.rng.getrandbits(32), argbytes=4)})
    c.emu.w32(t, vtT)
    sys_ = _rnd(c, 0x200)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)

    def alloc(e, r):
        size = e.arg32(0)
        e.calllog.append(('SLLoad::alloc', size))
        blk = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
        e.ret(eax=blk, argbytes=0)

    def ctor(e, r):
        e.calllog.append(('REFTAB::ctor', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=e.reg('ecx'), argbytes=8)
    ss.patch(c, ALLOC, c.emu.stub_fn('SLLoad::alloc', alloc))
    ss.patch(c, CTOR, c.emu.stub_fn('REFTAB::ctor', ctor))
    return [self_, ld]


S(0x5c7220, 'ZFFSearchLightGroup::Load(ZLoadGame*) thiscall', 'thiscall', None, ret=None, gen=_load,
  note='unclaimed-79 batch 12; SEH frame not reproduced (fs:[0] writes not compared); LoadSpot runs as original code')
