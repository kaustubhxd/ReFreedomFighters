"""specs_s2906.py - unclaimed-29 batch 6 (docs/20-unclaimed-29.md, claim 6, slice 8): ZActorIf::GetInitialRefPos. Fake objects:
the global at 0x700390 (slot +0x20 returns X), this+0x18 (slot +0x20 returns Y), X (slot +0x2c logs its three arguments and
ecx), and the global function pointer at 0x7003b0 (a stub that counts calls and returns a per-case value). The translation
cache is flushed after the stub is set up."""
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


def _gen(c):
    # X: slot +0x2c (three stack args) logs; returns nothing
    # the original cleans the three arguments itself (add esp, 0xc after the call), so the slot pops nothing
    def x_slot(e, r):
        args = tuple(e.arg32(k) for k in range(3))
        e.calllog.append(('init-x', e.reg('ecx'), args))
        e.ret(eax=0, argbytes=0)
    vt_x = c.emu.fake_vtable('init-x', 0x30, {0x2c: x_slot})
    x = _rnd(c, 0x40)
    c.emu.w32(x, vt_x)
    # Y: slot +0x20 (no args) returns nothing useful; its +4 decides the callee's this and the default
    vt_y = c.emu.logging_vtable('init-y', 0x30, argwords={0x20: 0})
    y = _rnd(c, 0x40)
    c.emu.w32(y, vt_y)
    c.emu.w32(y + 4, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    # global object: slot +0x20 (two stack args) returns X
    vt_g = c.emu.logging_vtable('init-global', 0x30, impl={0x20: lambda e, a: (x, None)}, argwords={0x20: 2})
    g = _rnd(c, 0x40)
    c.emu.w32(g, vt_g)
    c.emu.w32(0x700390, g)
    # this+0x18 object: slot +0x20 (no args) returns Y
    vt_m = c.emu.logging_vtable('init-member', 0x30, impl={0x20: lambda e, a: (y, None)}, argwords={0x20: 0})
    member = _rnd(c, 0x40)
    c.emu.w32(member, vt_m)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x18, member)
    # global function pointer (no args; counts calls, returns a per-case value)
    import serial_stubs as ss
    rv = c.rng.getrandbits(32)
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=rv, log=False))   # counts calls and returns rv
    _flush_code(c)
    return [self_, _rnd(c, 0x40)]


S(0x506e80, 'ZActorIf::GetInitialRefPos (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-29 batch 6 (slice 8); chained slot calls on global, this+0x18 and X; then the global fn pointer 0x7003b0')
