"""specs_s7921.py - unclaimed-79 batch 21 (docs/20-unclaimed-79.md, gap band): ZPlayer::ForceFacing (0x4835c0). Orchestration verified,
helpers stubbed (call-recording). The helpers write random floats through their pointer arguments so the port's stored values are
compared; slot +0x84 and +0x59c write into the vectors they are given."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

H43E920, H4E09B0, H4DE040, H4825C0 = 0x43e920, 0x4e09b0, 0x4de040, 0x4825c0


def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p


def _blk(c, n=0x200):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-2, 2)))[0]


def _vec_writer(c, name, nargs):
    def h(e, r):
        p = e.arg32(0)
        e.calllog.append((name, _norm(e, e.reg('ecx')), _norm(e, e.reg('edx')), _norm(e, e.arg32(0)) if nargs else 0))
        for k in range(3):
            e.w32(p + 4 * k, _fl(c))
        e.ret(eax=0, argbytes=4 * nargs)
    return h


def _gen(c):
    self_ = _blk(c)
    dir_ = _blk(c, 0x20)
    vt = c.emu.fake_vtable('ZPlayer-facing', 0x240, {
        0x84: _vec_writer(c, 'ZPlayer::slot84', 1),
        0x59c: _vec_writer(c, 'ZPlayer::slot59c', 2),
    })
    c.emu.w32(self_, vt)

    def h43(e, r):
        e.calllog.append(('Vec::43e920', _norm(e, e.reg('ecx')), _norm(e, e.reg('edx')), _norm(e, e.arg32(0))))
        for k in range(3):
            e.w32(e.reg('ecx') + 4 * k, _fl(c))
        e.ret(eax=0, argbytes=4)

    def h4e0(e, r):
        e.calllog.append(('Vec::4e09b0', _norm(e, e.reg('ecx'))))
        e.w32(e.reg('ecx') + 4, _fl(c))
        e.ret(eax=0, argbytes=0)

    def hde(e, r):
        e.calllog.append(('Mat::4de040', _norm(e, e.reg('ecx')), _norm(e, e.reg('edx')), e.arg32(0)))
        e.w32(e.reg('ecx'), _fl(c))
        e.ret(eax=0, argbytes=4)

    def h825(e, r):
        e.calllog.append(('ZPlayer::ContactMove', e.reg('ecx'), _norm(e, e.arg32(0)), _norm(e, e.arg32(1)), _norm(e, e.arg32(2)), _norm(e, e.arg32(3))))
        e.ret(eax=0, argbytes=16)
    ss.patch(c, H43E920, c.emu.stub_fn('Vec::43e920', h43))
    ss.patch(c, H4E09B0, c.emu.stub_fn('Vec::4e09b0', h4e0))
    ss.patch(c, H4DE040, c.emu.stub_fn('Mat::4de040', hde))
    ss.patch(c, H4825C0, c.emu.stub_fn('ZPlayer::ContactMove', h825))
    return [self_, dir_]


S(0x4835c0, 'ZPlayer::ForceFacing(const float*) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-79 batch 21; orchestration verified, helpers stubbed (call-recording)')
