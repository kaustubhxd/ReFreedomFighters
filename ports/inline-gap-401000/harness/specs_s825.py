"""specs_s825.py - core batch 825 (docs/20-unclaimed-65.md). 0x4fc690: thiscall, no arguments. The render sub-object's slot 0x138 returns an
object X (its slot 0x88 with two arguments writes a fixed dword through the second and logs both). When [this+0x6e] is zero the path runs.
The object at this+0x44 has slot 0x240 (one argument, logged) and a +0x48 dword. 0x4fdac0 is HOOKED by address (GUESS): thiscall, no
arguments, logs ecx. The byte at this+0x4d and the dword at this+0x6e are random."""
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
    ss.patch(c, 0x4fdac0, c.emu.stub_fn('4fdac0 hook', lambda e, r: (e.calllog.append(('0x4fdac0', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    x_vt = c.emu.fake_vtable('c825-x', 0x100, {
        0x88: lambda e, r: (e.calllog.append(('0x88', e.reg('ecx'), e.arg32(0))), e.w32(e.arg32(1), 0x5a5a1234),
                            e.ret(eax=0, argbytes=8))[-1]})
    x = _rnd(c, 0x40)
    c.emu.w32(x, x_vt)
    r9_vt = c.emu.fake_vtable('c825-r9', 0x400, {
        0x138: lambda e, r: (e.calllog.append(('0x138', e.reg('ecx'))), e.ret(eax=x, argbytes=0))[-1]})
    r9 = _rnd(c, 0x100)
    c.emu.w32(r9, r9_vt)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    obj_vt = c.emu.fake_vtable('c825-obj', 0x400, {
        0x240: lambda e, r: (e.calllog.append(('0x240', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))[-1]})
    obj = _rnd(c, 0x100)
    c.emu.w32(obj, obj_vt)
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x44, obj)
    c.emu.w32(this + 0x6e, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.wbytes(this + 0x4d, bytes([c.rng.choice([0, 1])]))
    return [this]


S(0x4fc690, 'CMAINCAMERACONTROL::Init2 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 825: optional slot 0x138/0x88 path, slot 0x240, hooked 0x4fdac0, bit 22 update')
