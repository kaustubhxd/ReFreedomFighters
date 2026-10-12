"""specs_s820.py - core batch 820 (docs/20-unclaimed-65.md). 0x4fb8d0: thiscall, no arguments. 0x4fbd50 is HOOKED by address (GUESS): it logs
ecx and returns the byte the case chose (kept at this+0x60, read back from memory). The render sub-object's slot 0x58 (one argument) returns
an object O or zero; O's slot 0x128 (three arguments, callee pops) is logged. Both fake vtables are written in gen; the hook is installed
in setup."""
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
    import serial_stubs as ss
    ss.patch(c, 0x4fbd50, c.emu.stub_fn('4fbd50 hook', lambda e, r: (
        e.calllog.append(('0x4fbd50', e.reg('ecx'))),
        e.ret(eax=e.rbytes(e.reg('ecx') + 0x60, 1)[0], argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    pick58 = c.rng.random() < 0.8
    o_vt = c.emu.fake_vtable('c820-o', 0x200, {
        0x128: lambda e, r: (e.calllog.append(('0x128', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2)))), e.ret(eax=0, argbytes=12))[-1]})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, o_vt)
    r9_vt = c.emu.fake_vtable('c820-r9', 0x100, {
        0x58: lambda e, r: (e.calllog.append(('0x58', e.reg('ecx'), e.arg32(0))),
                            e.ret(eax=obj if pick58 else 0, argbytes=4))[-1]})
    r9 = _rnd(c, 0x100)
    c.emu.w32(r9, r9_vt)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0x60, bytes([c.rng.getrandbits(1)]))   # the byte 0x4fbd50 returns
    c.emu.wbytes(self_ + 0x48, bytes([c.rng.getrandbits(1)]))   # the stored byte
    return [self_]


S(0x4fb8d0, 'core method 0x4fb8d0 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 820: byte compare with 0x4fbd50, slot 0x58 object, slot 0x128 call (0x4fbd50 hooked)')
