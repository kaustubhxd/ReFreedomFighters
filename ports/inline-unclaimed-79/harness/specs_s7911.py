"""specs_s7911.py - unclaimed-79 batch 11 (docs/20-unclaimed-79.md): ZFFActor::CopyDataBlock (0x59ee60). SEH frame not reproduced
(fs:[0] writes not compared). Callees are call-recording stubs: the DBLK readers (0x4e12e0, 0x4e11e0) write a random dword into
their pointer argument (the exe's own argument slot is one of them), 0x4e1600 returns 8 or another type, the allocator returns a
block or zero, the constructor returns a random value, and the base copy 0x4780f0 is a stub. The object at this+0xc0-chain gives a
slot +0xc value; this has slot +0x5a4."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

ADDR = {'base': 0x4780f0, 'r12': 0x4e12e0, 'r11': 0x4e11e0, 'typ': 0x4e1600, 'end': 0x4e1b30, 'alloc': 0x41e290,
        'ctor': 0x59d330}


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p


def _reader(name, c):
    def h(e, r):
        p = e.arg32(0)
        e.calllog.append((name, e.reg('ecx'), _norm(e, p), e.arg32(1)))
        e.w32(p, c.rng.getrandbits(32))
        e.ret(eax=0, argbytes=8)
    return h


def _copy(c):
    self_ = _rnd(c, 0x800)
    blk = _rnd(c, 0x100) if c.rng.random() < 0.9 else 0
    alloc_ok = c.rng.random() < 0.7
    obj_mem = _rnd(c, 0x40)
    ss.patch(c, ADDR['base'], c.emu.stub_fn('ZActor::CopyDataBlock', lambda e, r: (
        e.calllog.append(('ZActor::CopyDataBlock', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))))
    ss.patch(c, ADDR['r12'], c.emu.stub_fn('DBLK::Get12e0', _reader('DBLK::Get12e0', c)))
    ss.patch(c, ADDR['r11'], c.emu.stub_fn('DBLK::Get11e0', _reader('DBLK::Get11e0', c)))
    tv = c.rng.choice([8, 8, c.rng.getrandbits(8)])
    ss.patch(c, ADDR['typ'], c.emu.stub_fn('DBLK::GetType', lambda e, r: (
        e.calllog.append(('DBLK::GetType', e.reg('ecx'))), e.ret(eax=tv, argbytes=0))))
    ss.patch(c, ADDR['end'], c.emu.stub_fn('ZFFActor::end', lambda e, r: (
        e.calllog.append(('ZFFActor::end', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, ADDR['alloc'], c.emu.stub_fn('operator_new', lambda e, r: (
        e.calllog.append(('operator_new', e.arg32(0))), e.ret(eax=obj_mem if alloc_ok else 0, argbytes=0))))
    rv = c.rng.getrandbits(32)
    ss.patch(c, ADDR['ctor'], c.emu.stub_fn('GameEntity::GameEntity', lambda e, r: (
        e.calllog.append(('GameEntity::GameEntity', e.reg('ecx'), _norm(e, e.arg32(0)), e.arg32(1))),
        e.ret(eax=rv, argbytes=8))))
    vtS = c.emu.fake_vtable('ZFFActor-cdb', 0x2c0, {0x5a4: logged_slot('ZFFActor::slot5a4', eax=0, argbytes=4)})
    c.emu.w32(self_, vtS)
    Y = _rnd(c, 0x100)
    vtY = c.emu.fake_vtable('CdbSlotY', 0x10, {0xc: logged_slot('CdbY::slotc', eax=c.rng.getrandbits(32), argbytes=4)})
    c.emu.w32(Y, vtY)
    X = _rnd(c, 0x100)
    c.emu.w32(X + 0x18, Y)
    sys_ = _rnd(c, 0x2000)
    c.emu.w32(sys_ + 0x1aa3, X)
    c.emu.w32(0x70039c, sys_)
    return [self_, blk]


S(0x59ee60, 'ZFFActor::CopyDataBlock(DBLK*) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-79 batch 11; SEH frame not reproduced (fs:[0] writes not compared); DBLK readers write back; allocator and ctor stubs')
