"""specs_s7907.py - unclaimed-79 batch 7 (docs/20-unclaimed-79.md): ZItemTemplateAmmo::CopyDataBlock (0x46cf60). The base copy
0x46cee0 and the DBLK helpers (0x4e11e0, 0x4e12f0, 0x4e12e0, 0x4e1b30) are logging stubs; 0x4e1600 returns 3 about half the time,
else another byte. The DBLK helpers write a random value into their pointer argument (the int read goes through the argument
slot). The logger global 0x700390 is a fake object (slot +0x20 returns a second fake object, whose cdecl slot +0x2c logs)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H = {'base': 0x46cee0, 'h11e0': 0x4e11e0, 'h12f0': 0x4e12f0, 'h12e0': 0x4e12e0, 'type': 0x4e1600, 'end': 0x4e1b30}


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _reader(c, name):
    def h(e, r):
        p = e.arg32(0)
        # the pointer is the exe's own argument slot (a stack address that differs between the two frames): log a marker
        # for it; the write and the readback are still compared through the port's use of the value
        pl = 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p
        e.calllog.append((name, e.reg('ecx'), pl, e.arg32(1)))
        e.w32(p, c.rng.getrandbits(32))
        e.ret(eax=0, argbytes=8)
    return h


def _copy(c):
    self_ = _rnd(c, 0x200)
    blk = _rnd(c, 0x100)
    ss.patch(c, H['base'], c.emu.stub_fn('ItemTemplate::CopyDataBlock', lambda e, r: (
        e.calllog.append(('ItemTemplate::CopyDataBlock', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))))
    ss.patch(c, H['h11e0'], c.emu.stub_fn('DBLK::Get11e0', _reader(c, 'DBLK::Get11e0')))
    ss.patch(c, H['h12f0'], c.emu.stub_fn('DBLK::Get12f0', _reader(c, 'DBLK::Get12f0')))
    ss.patch(c, H['h12e0'], c.emu.stub_fn('DBLK::Get12e0', _reader(c, 'DBLK::Get12e0')))
    tv = 3 if c.rng.random() < 0.5 else c.rng.getrandbits(8)
    ss.patch(c, H['type'], c.emu.stub_fn('DBLK::GetType', lambda e, r: (
        e.calllog.append(('DBLK::GetType', e.reg('ecx'))), e.ret(eax=tv, argbytes=0))))
    ss.patch(c, H['end'], c.emu.stub_fn('ZItemTemplateAmmo::end', lambda e, r: (
        e.calllog.append(('ZItemTemplateAmmo::end', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    obj2 = _rnd(c, 0x40)
    vt2 = c.emu.fake_vtable('ItemAmmo-logobj', 0x30, {0x2c: logged_slot('Logger::cdecl2c', eax=0, argbytes=0)})
    c.emu.w32(obj2, vt2)
    vt1 = c.emu.fake_vtable('ItemAmmo-logger', 0x9, {0x20: logged_slot('Logger::get20', eax=obj2, argbytes=8)})
    obj1 = _rnd(c, 0x40)
    c.emu.w32(obj1, vt1)
    c.emu.w32(0x700390, obj1)
    return [self_, blk]


S(0x46cf60, 'ZItemTemplateAmmo::CopyDataBlock(DBLK*) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-79 batch 7; base copy and DBLK helper stubs; type 3 path or logged error path')
