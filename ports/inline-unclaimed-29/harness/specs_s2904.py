"""specs_s2904.py - unclaimed-29 batch 4 (docs/20-unclaimed-29.md, claim 4, slice 8): ZMoveOnSplineIf::~ZMoveOnSplineIf (base
dtor 0x500a10 and operator delete 0x634273 stubbed) and ZVehicleIf::collectOpaqueInfo (0x51a790 stubbed; this's slot +0x38 and
the argument's slot 0 are logging vtables). Translation cache flushed after each patch."""
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


def _logger(name, nargs, cdecl=False):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=0, argbytes=0 if cdecl else 4 * nargs)
    return h


def _setup_dtor(c):
    from serial_stubs import patch
    patch(c, 0x500a10, c.emu.stub_fn('0x500a10', _logger('0x500a10', 0)))
    patch(c, 0x634273, c.emu.stub_fn('0x634273', _logger('0x634273', 2, cdecl=True)))
    _flush_code(c)


def _dtor_gen(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _setup_collect(c):
    from serial_stubs import patch
    patch(c, 0x51a790, c.emu.stub_fn('0x51a790', _logger('0x51a790', 1)))
    _flush_code(c)


def _collect_gen(c):
    # this: slot +0x38 returns a value (logged, no args); the argument: slot 0 takes one stack arg (logged)
    vt_this = c.emu.logging_vtable('zvehicle-if', 0x40, impl={0x38: lambda e, a: (c_ret, None)}, argwords={0x38: 0})
    c_ret = c.rng.getrandbits(32)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_, vt_this)
    vt_arg = c.emu.logging_vtable('serial-buf', 0x10, argwords={0: 1})
    arg = _rnd(c, 0x40)
    c.emu.w32(arg, vt_arg)
    return [self_, arg]


S(0x519440, 'ZMoveOnSplineIf::~ZMoveOnSplineIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor_gen,
  setup=_setup_dtor, note='unclaimed-29 batch 4 (slice 8); vtable 0x69f224; base 0x500a10; delete 0x18 if flag bit 0')
S(0x51f200, 'ZVehicleIf::collectOpaqueInfo (unknown) thiscall', 'thiscall', None, ret=None, gen=_collect_gen,
  setup=_setup_collect, note='unclaimed-29 batch 4 (slice 8, low name); 0x51a790 with arg; this slot +0x38; arg slot 0 with that result')
