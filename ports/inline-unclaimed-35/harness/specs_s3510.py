"""specs_s3510.py - area 35 claim 10 (docs/20-unclaimed-35.md): four GUESS-named leaves in slice 14.

Stubbed (logged): slot 0 of the object at this+0x65 (one argument, ret 4), for FUN_436060. The object at +0x65 is null in half
the cases. The global at 0x724270 is written per case (random dword). The objects are 0x200 random bytes."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _self(c):
    return [_rnd(c, 0x200)]


def _self_arg(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _callslot(c):
    o = _rnd(c, 0x200)
    if c.rng.random() < 0.5:
        child = _rnd(c, 0x100)
        cvt = c.emu.logging_vtable('ZGuessChild', 0x40, impl={}, argwords={0: 1})
        c.emu.w32(child, cvt)
        c.emu.w32(o + 0x65, child)
    else:
        c.emu.w32(o + 0x65, 0)
    return [o, c.rng.getrandbits(32)]


def _global(c):
    c.emu.w32(0x724270, c.rng.getrandbits(32))
    return [_rnd(c, 0x200)]


S(0x5eeba0, 'GUESS FUN_5eeba0 thiscall', 'thiscall', None, ret=None, gen=_self_arg,
  note='area 35 claim 10; byte +0x4d = low byte of the argument')
def _counter(c):
    return [_rnd(c, 0x5d48)]   # the counter is at +0x5d41: the object must contain it


S(0x490920, 'GUESS FUN_490920 thiscall', 'thiscall', None, ret=None, gen=_counter,
  note='area 35 claim 10; increments dword +0x5d41')
S(0x5fa5e0, 'GUESS FUN_5fa5e0 thiscall', 'thiscall', None, ret=None, gen=_global,
  note='area 35 claim 10; vtable 0x6b91dc, global 0x724270 = 0')
S(0x436060, 'GUESS FUN_436060 thiscall', 'thiscall', None, ret='al', gen=_callslot,
  note='area 35 claim 10; slot 0 of +0x65 (logged), returns true')
