"""specs_s824.py - core batch 824 (docs/20-unclaimed-65.md). 0x53f5d0: thiscall, no arguments. The object at this+0x44 has slot 0x40 (no
arguments, logged) and its +8 block is the argument of the hooked callees. Hooks (GUESS, all by address): 0x4dc630 (two words, callee pops,
logs ecx and both), 0x4db7c0 (one pointer, callee pops, writes a fixed dword into the local, logs ecx), 0x6352a0 (two words, callee pops,
logs ecx and both). The exe's cookie check 0x633654 is stubbed to a return."""
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
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    ss.patch(c, 0x4dc630, c.emu.stub_fn('4dc630 hook', lambda e, r: (
        e.calllog.append(('0x4dc630', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    ss.patch(c, 0x4db7c0, c.emu.stub_fn('4db7c0 hook', lambda e, r: (
        e.calllog.append(('0x4db7c0', e.reg('ecx'))), e.w32(e.arg32(0), 0x1234), e.ret(eax=0, argbytes=4))))
    ss.patch(c, 0x6352a0, c.emu.stub_fn('6352a0 hook', lambda e, r: (
        e.calllog.append(('0x6352a0', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    o_vt = c.emu.fake_vtable('c824-o', 0x100, {
        0x40: lambda e, r: (e.calllog.append(('0x40', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    blk = _rnd(c, 0x40)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, o_vt)
    c.emu.w32(obj + 8, blk)
    this = _rnd(c, 0x200)
    c.emu.w32(this + 0x44, obj)
    return [this]


S(0x53f5d0, 'CRigidBody::Setup (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 824: three hooked helpers and a slot 0x40 call')
