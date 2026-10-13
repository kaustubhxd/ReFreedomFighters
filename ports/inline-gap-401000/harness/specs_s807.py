"""specs_s807.py - core batch 807 (docs/20-unclaimed-65.md). 0x46d6c0: a stdcall with one argument o; the target is the vtable slot 0x210 of o
(logs ecx and its argument, pops 4). 0x46e9c0: slot 0x25c returns a per-case value (zero in one case in three, so the method returns this).
0x478a80: [ecx] is the pointer p; the render sub-object's +0x44 is random. 0x53e940: the member at +0x135 is 0 or a block; 0x41e2c0 is a logging stub."""
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


def _setup_46d6(c):
    vt = c.emu.fake_vtable('core-807-210', 0x400, {0x210: lambda e, r: (e.calllog.append(('0x210', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0x55, argbytes=4))[-1]})
    c.thisvt = vt
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_46d6(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o, c.thisvt)
    return [c.rng.choice([o, 0])]


S(0x46d6c0, 'core method 0x46d6c0 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen_46d6, setup=_setup_46d6,
  note='core batch 807: rewrite the argument to 1 and tail-jump through slot 0x210 of the object')


def _setup_46e9(c):
    vt = c.emu.fake_vtable('core-807-25c', 0x400, {0x25c: lambda e, r: (e.calllog.append(('0x25c', e.reg('ecx'), (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=c.r25c, argbytes=8))[-1]})
    c.thisvt = vt
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_46e9(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this, c.thisvt)
    c.r25c = c.rng.choice([0, 0, c.rng.getrandbits(32) | 1])
    return [this]


S(0x46e9c0, 'core method 0x46e9c0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_46e9, setup=_setup_46e9,
  note='core batch 807: slot 0x25c result or this')


def _setup_478a(c):
    render = _rnd(c, 0xa00)
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(32))
    c.emu.w32(render + 0x9b, obj)
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_478a(c):
    pp = _rnd(c, 0x10)
    c.emu.w32(pp, c.rng.choice([0, c.rng.getrandbits(32)]))
    return [pp]


S(0x478a80, 'core method 0x478a80 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_478a, setup=_setup_478a,
  note='core batch 807: pointer plus a field of the render sub-object, or 0')


def _setup_53e9(c):
    import serial_stubs as ss
    ss.patch(c, 0x41e2c0, c.emu.stub_fn('41e2c0 delete', lambda e, r: (e.calllog.append(('0x41e2c0', (e.arg32(0),))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_53e9(c):
    this = _rnd(c, 0x200)
    c.emu.w32(this + 0x135, c.rng.choice([0, _rnd(c, 0x20)]))
    return [this]


S(0x53e940, 'core method 0x53e940 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_53e9, setup=_setup_53e9,
  note='core batch 807: release the member at +0x135 and clear it')
