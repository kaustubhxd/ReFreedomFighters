"""specs_s7919.py - unclaimed-79 batch 19 (docs/20-unclaimed-79.md, gap band): ZPlayer::CreateMovementBaseMove (0x482970). SEH frame not
reproduced (fs:[0] writes not compared). The allocator returns a block (or zero one time in four); 0x4876e0 is a logging stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

ALLOC, H = 0x41e290, 0x4876e0


def _blk(c, n=0x80):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cmb(c):
    self_ = _blk(c)
    ok = c.rng.random() < 0.75
    ret = c.rng.getrandbits(32)

    def alloc(e, r):
        e.calllog.append(('ZPlayer::alloc', e.arg32(0)))
        e.ret(eax=_blk(c, 0x40) if ok else 0, argbytes=0)

    def helper(e, r):
        e.calllog.append(('ZPlayer::helper4876e0', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=ret, argbytes=8)
    ss.patch(c, ALLOC, c.emu.stub_fn('ZPlayer::alloc', alloc))
    ss.patch(c, H, c.emu.stub_fn('ZPlayer::helper4876e0', helper))
    return [self_]


S(0x482970, 'ZPlayer::CreateMovementBaseMove() thiscall', 'thiscall', None, ret='eax', gen=_cmb,
  note='unclaimed-79 batch 19; SEH frame not reproduced (fs:[0] writes not compared); allocator and helper 0x4876e0 stubbed')
