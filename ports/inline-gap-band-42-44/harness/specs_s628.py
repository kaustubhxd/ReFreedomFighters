"""specs_s628.py - band 0x421000-0x441000, batch 628 (see src/batch628.cpp). Finite random floats only (the comparisons are
ordered, the heap compare would otherwise see NaN payloads). 0x436200's device answers slot 0x3c, recorded.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _gen_dev(c):
    r = c.rng
    self_ = c.emu.alloc(0x100, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    n = r.randint(0, 4)
    c.emu.w32(self_ + 0x60, n)
    for k in range(4):
        dev = c.emu.fake_object('dev%d' % k, 0x40, nslots=0x40, slots={0x3c: _rec('dev.3c', 0x3c, 1, 0)}) \
            if (k < n and r.random() < 0.8) else 0
        c.emu.w32(self_ + 0x20 + 4 * k, dev)
    i = r.choice((0, 1, 2, 3, 4, 7, 0xffffffff))
    return [self_, i, r.getrandbits(32)]


def _gen_scan(c):
    r = c.rng
    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(self_ + 0x80, r.randint(0, 6))
    for k in range(7):
        c.emu.wf32(self_ + 0x1c + 0x18 * k - 4, r.uniform(-10.0, 10.0))
        c.emu.wf32(self_ + 0x1c + 0x18 * k, r.uniform(-10.0, 10.0))
    return [self_]


S(0x436200, 'device i present: slot 0x3c with y, returns bool', 'thiscall', None, ret='al', gen=_gen_dev)
S(0x43cfc0, 'max/min scan over the 0x18-stride float table', 'thiscall', None, ret=None, gen=_gen_scan)
