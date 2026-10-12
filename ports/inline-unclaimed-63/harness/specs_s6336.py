"""specs_s6336.py - unclaimed-63 gap-band batch 36: 0x4cea50 (C-set; thiscall, no stack arguments, plain ret).
Fakes per case (the image is restored between runs):
  * this: vtable slot +0x4c (records ECX and its pointer argument, ret 4) and slot +0x64 (returns the next node of a short ring, 0 at
    the end, and records ECX). this+0x18 is k, 3 to 8, so the float read is inside a 0x40-byte node;
  * logger 0x700390: slot +0x20 (file, line) returns the log object (thiscall, ret 8), like the other specs;
  * the log object: slot +0x2c is a cdecl printf-like that records its four arguments (the log, the format, the value and the double).
Node first dwords and floats are random bit patterns (NaN included), so the double conversion runs both ways."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_cea5(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x18, c.rng.randint(3, 8))
    nodes = [_rnd(c, 0x40) for _ in range(c.rng.randint(0, 3))]
    seq = list(nodes) + [0]
    pos = [0]

    def slot4c(em, args):
        em.calllog.append(('this.setup', 0x4c, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def slot64(em, args):
        em.calllog.append(('this.next', 0x64, em.reg('ecx'), (em.arg32(0),)))
        v = seq[pos[0]] if pos[0] < len(seq) else 0
        pos[0] += 1
        em.ret(eax=v, argbytes=4)
    vt = e.fake_vtable('this', 0x80, {0x4c: slot4c, 0x64: slot64})
    e.w32(self_, vt)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=0)
    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x4cea50, 'unnamed C-set 0x4cea50 thiscall', 'thiscall', None, ret=None, gen=_gen_cea5, note='unclaimed-63 band batch 36')
