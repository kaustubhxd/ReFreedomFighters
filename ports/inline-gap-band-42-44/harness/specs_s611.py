"""specs_s611.py - band 0x421000-0x441000, batch 611: ZSysInterface::ProjectPath / StreamFile / StreamIdxFile (see src/batch611.cpp).
The member at this+off is a char * (random short C string, or 0 for the exe's empty default). The copy runs the exe's own
MYSTR assign (0x4cbe50), so nothing is hooked here. Strings are at most 100 characters (the long-string allocation path is
not reached by these inputs, as in docs/18-level1-haiku-trial.md).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _gen_for(off):
    def gen(c):
        r = c.rng
        self_ = c.emu.alloc(0x900, 16)
        c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x900)))
        n = r.randint(0, 100)
        text = bytes(r.randint(0x21, 0x7e) for _ in range(n))
        if r.random() < 0.1:
            c.emu.w32(self_ + off, 0)
        else:
            s = c.emu.alloc(len(text) + 1, 4)
            c.emu.wbytes(s, text + b'\x00')
            c.emu.w32(self_ + off, s)
        dest = c.emu.alloc(0x40, 16)
        c.emu.wbytes(dest, bytes(r.getrandbits(8) for _ in range(0x40)))
        return [self_, dest]
    return gen


S(0x42ee20, 'ZSysInterface::ProjectPath', 'thiscall', None, ret='eax', gen=_gen_for(0x123))
S(0x42fc30, 'ZSysInterface::StreamFile', 'thiscall', None, ret='eax', gen=_gen_for(0x8a3))
S(0x42fc60, 'ZSysInterface::StreamIdxFile', 'thiscall', None, ret='eax', gen=_gen_for(0x7a3))
