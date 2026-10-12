"""specs_s2807.py - unclaimed-28 batch 7 (docs/20-unclaimed-28.md): ZBoneModifyBase::UnfixParticle (0x6475f0). The pointer at
+0x291 is set to a random heap object half the time. The callee 0x645100 is patched to a logging stub for both sides."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss

CALLEE = 0x645100


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _unfix(c):
    self_ = _rnd(c, 0x300)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x291, _rnd(c, 0x100))
    else:
        c.emu.w32(self_ + 0x291, 0)

    def h(e, r):
        e.calllog.append(('ZBoneModify::callee645100', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, CALLEE, c.emu.stub_fn('ZBoneModify::callee645100', h))
    return [self_, c.rng.getrandbits(32)]


S(0x6475f0, 'ZBoneModifyBase::UnfixParticle(int) thiscall', 'thiscall', None, ret=None, gen=_unfix,
  note='unclaimed-28 batch 7; tail-jumps to 0x645100 when this+0x291 is nonzero')
