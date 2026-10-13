"""specs_s806.py - core batch 806 (docs/20-unclaimed-65.md): 0x5dbeb0 (thiscall with one stack argument that becomes ecx; reads this+0x48), 0x469200
(plain; the object at [0x70039c]+0x1907 or none), 0x479030 (thiscall; stores the slot 0x21c result at +0x74f). The callees are logging stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(tag, nargs, ret):
    def h(e, r):
        e.calllog.append((tag, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _setup_5dbe(c):
    import serial_stubs as ss
    ss.patch(c, 0x4e6330, c.emu.stub_fn('4e6330', _stub('4e6330', 1, 0x21)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_5dbe(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x48, c.rng.getrandbits(32))
    return [this, c.rng.getrandbits(32)]


S(0x5dbeb0, 'core method 0x5dbeb0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_5dbe, setup=_setup_5dbe,
  note='core batch 806: push [this+0x48], this := the stack argument, call 0x4e6330')


def _setup_469(c):
    vt = c.emu.fake_vtable('core-806-14', 0x100, {0x14: lambda e, r: (e.calllog.append(('0x14', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1]})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    render = _rnd(c, 0x2000)
    c.emu.w32(render + 0x1907, obj if c.rng.random() < 0.7 else 0)
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


S(0x469200, 'core method 0x469200 (unknown) cdecl', 'cdecl', None, ret=None, gen=lambda c: [], setup=_setup_469,
  note='core batch 806: slot 0x14 of the render sub-object when it exists')


def _setup_479(c):
    vt = c.emu.fake_vtable('core-806-21c', 0x800, {0x21c: lambda e, r: (e.calllog.append(('0x21c', e.reg('ecx'), (e.arg32(0),))),
                                                                       e.ret(eax=0x1357 ^ e.arg32(0), argbytes=4))[-1]})
    c.thisvt = vt
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_479(c):
    this = _rnd(c, 0x800)
    c.emu.w32(this, c.thisvt)
    return [this]


S(0x479030, 'core method 0x479030 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_479, setup=_setup_479,
  note='core batch 806: store slot 0x21c result at +0x74f')
