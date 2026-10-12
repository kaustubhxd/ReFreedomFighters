"""specs_s7916.py - unclaimed-79 batch 16 (docs/20-unclaimed-79.md, gap band): ZAnimDefsListRandom dtor (0x481140). The child at
+0x14 is a logging fake (slot 0) or null; the free helper 0x634273 is a logging cdecl stub. The flags argument's low bit is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

FREE = 0x634273


def _blk(c, n=0x100):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    self_ = _blk(c, 0x40)
    if c.rng.random() < 0.7:
        child = _blk(c, 0x40)
        vt = c.emu.fake_vtable('AnimDefsChild', 0x10, {0x0: logged_slot('AnimDefsChild::slot0', eax=0, argbytes=4)})
        c.emu.w32(child, vt)
        c.emu.w32(self_ + 0x14, child)
    else:
        c.emu.w32(self_ + 0x14, 0)
    ss.patch(c, FREE, c.emu.stub_fn('CRT::free634273', lambda e, r: (
        e.calllog.append(('CRT::free634273', e.arg32(0) == self_, e.arg32(1))), e.ret(eax=0, argbytes=0))))
    return [self_, c.rng.getrandbits(32)]


S(0x481140, 'ZAnimDefsListRandom::~ZAnimDefsListRandom() thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-79 batch 16; scalar deleting dtor: vtable store, child release, optional free(this, 0x18)')
