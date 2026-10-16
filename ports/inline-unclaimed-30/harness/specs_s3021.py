"""specs_s3021.py - unclaimed-30 claim 2 (residue 10): CActionController::Command (0x49ff20). The two callees (0x49fa80 and 0x4a1850) are
patched with logged stubs (ret 4; their own bodies are not part of this claim). The id is a random word, equal to one of the two stored
words about half the time. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _cmd(c):
    e = c.emu
    r = c.rng
    ss.patch(c, 0x49fa80, ss.rec(c, 1))
    ss.patch(c, 0x4a1850, ss.rec(c, 1))
    self_ = e.alloc(0x900)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x900)))
    w0 = r.getrandbits(16)
    w1 = r.getrandbits(16)
    e.w16(self_ + 0x8b0, w0)
    e.w16(self_ + 0x8b2, w1)
    pick = r.random()
    if pick < 0.4:
        idv = w0
    elif pick < 0.7:
        idv = w1
    else:
        idv = r.getrandbits(16)
    arg = r.getrandbits(32)
    return [self_, idv | (r.getrandbits(16) << 16), arg]


S(0x49ff20, 'CActionController::Command', 'thiscall', None, ret='eax', gen=_cmd, n=300)
