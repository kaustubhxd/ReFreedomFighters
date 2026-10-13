"""specs_s814.py - core batch 814 (docs/20-unclaimed-65.md). 0x6352f0: thiscall, one stack pointer argument (ret 4). this+0x38 is zero in a
quarter of the cases (the pointer gets zero). Otherwise the chain [0x70039c]+0x9b -> +8 -> +4 gives the object o, and slot 0x30 of o is
called with ecx = o and one argument (count - 1); it logs ecx and the argument and returns a random dword that is written through the pointer."""
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
    ret30 = 0x1f2e3d4c   # fixed answer: the same value in the orig and port runs
    o_vt = c.emu.fake_vtable('c814-o', 0x100, {
        0x30: lambda e, r: (e.calllog.append(('0x30', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=ret30, argbytes=4))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 4, o)
    r9 = _rnd(c, 0x40)
    c.emu.w32(r9 + 8, a)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x80)
    n = 0 if c.rng.random() < 0.25 else c.rng.randint(1, 0xffff)
    c.emu.w32(self_ + 0x38, n)
    out = _rnd(c, 0x10)
    return [self_, out]


S(0x6352f0, 'core method 0x6352f0 (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 814: slot 0x30 of the object at the render chain, or zero')
