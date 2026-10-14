"""specs_s2902.py - unclaimed-29 batch 2 (docs/20-unclaimed-29.md, claim 2, slice 8): CCivilianPath::Init2. Two fake
virtual objects (slot +0x58 returns the next object; slot +0x100 returns a third object or 0) and a logging stub for 0x5bef80
(six stack arguments, ret 0x18). The translation cache is flushed after the patch."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def log5bef80(e, r):
        args = tuple(e.arg32(k) for k in range(6))
        e.calllog.append(('0x5bef80', e.reg('ecx'), args))
        e.ret(eax=0, argbytes=24)
    from serial_stubs import patch
    patch(c, 0x5bef80, c.emu.stub_fn('0x5bef80 logger', log5bef80))

    third = c.rng.random() < 0.7                 # slot +0x100 returns a third object in 70% of cases
    obj_c = _rnd(c, 0x40)
    vt_c = c.emu.logging_vtable('civ-c', 0x104, argwords={})
    c.emu.w32(obj_c, vt_c)
    vt_b = c.emu.logging_vtable('civ-b', 0x104, impl={0x100: lambda e, a: (obj_c if third else 0, None)},
                                argwords={0x100: 1})
    obj_b = _rnd(c, 0x40)
    c.emu.w32(obj_b, vt_b)
    vt_a = c.emu.logging_vtable('civ-a', 0x60, impl={0x58: lambda e, a: (obj_b, None)}, argwords={0x58: 1})
    obj_a = _rnd(c, 0x40)
    c.emu.w32(obj_a, vt_a)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, obj_a)
    c.emu.w32(0x70039c, rm)
    _flush_code(c)


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.w8(self_ + 0x58, c.rng.getrandbits(8))
    c.emu.w32(self_ + 0x50, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x4c, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    c.emu.wf32(self_ + 0x54, c.fv(-10.0, 10.0))
    return [self_]


S(0x5bdcc0, 'CCivilianPath::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-29 batch 2 (slice 8); chained virtual calls, then 0x5bef80 with six arguments')
