"""specs_s809.py - core batch 809 (docs/20-unclaimed-65.md). 0x45f9a0: thiscall with two stack words (ret 8). The chain this+0x10 -> +0x1c
-> +4 -> +4 is random blocks; a zero link at +0x10 or +0x1c skips the call (the cases are drawn per run). The global object at 0x7003a4 has
slot 0x5c, which logs ecx and its three stack words and pops them (ret 12). The global is set in setup."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    g_vt = c.emu.fake_vtable('c809-5c', 0x100, {
        0x5c: lambda e, r: (e.calllog.append(('0x5c', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2)))), e.ret(eax=0, argbytes=12))[-1]})
    g = _rnd(c, 0x40)
    c.emu.w32(g, g_vt)
    c.emu.w32(0x7003a4, g)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x40)
    mode = c.rng.choice(['full', 'full', 'nop_p', 'nop_q'])
    p = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x10, 0 if mode == 'nop_p' else p)
    q = _rnd(c, 0x40)
    c.emu.w32(p + 0x1c, 0 if mode == 'nop_q' else q)
    y = _rnd(c, 0x20)
    c.emu.w32(q + 4, y)
    x = _rnd(c, 0x20)
    c.emu.w32(y + 4, x)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x45f9a0, 'core method 0x45f9a0 (unknown) thiscall two args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 809: call through the global object slot 0x5c when the links are set')
