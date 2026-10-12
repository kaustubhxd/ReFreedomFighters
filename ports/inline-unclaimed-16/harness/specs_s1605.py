"""specs_s1605.py - unclaimed-16 batch 5 (docs/20-unclaimed-16.md): ZActor::Hide and ZFFActor::GetAimAnim.
The thunk 0x45f070 (Hide) and the tail target 0x473e50 (GetAimAnim) are patched to recording stubs (serial_stubs.rec)
in each case, so the exe and the port both reach the same stub; those two are NOT verified here. Virtual callees are
logging vtables, so their order, the object in ecx and their arguments are compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hide(c):
    ss.patch(c, 0x45f070, ss.rec(c, 1))
    obj = _rnd(c, 0x1000)
    c.emu.w32(obj + 0x640, c.rng.choice([0, 1, 0x1234, c.rng.getrandbits(32)]))
    c.emu.w32(obj, c.emu.logging_vtable('actor_hide', 0x200, argwords={0x58c: 0}))
    return [obj, c.rng.choice([0, 1, 2, 0x100, c.rng.getrandbits(32)])]


def _aim(c):
    ss.patch(c, 0x473e50, ss.rec(c, 0, ret=0x77))
    z = c.rng.choice([0, 1, 5])
    w = c.rng.choice([0x12, 0x13, 0x11, c.rng.getrandbits(32)])
    y = _rnd(c, 0x100)
    c.emu.w32(y, c.emu.logging_vtable('y_obj', 0x100, impl={0x300: lambda e, a, v=z: (v, None)}))
    x = _rnd(c, 0x100)
    c.emu.w32(x, c.emu.logging_vtable('x_obj', 0x100, impl={0x350: lambda e, a, v=y: (v, None)}))
    first = x if c.rng.random() < 0.8 else 0
    obj = _rnd(c, 0x1000)
    c.emu.w32(obj + 0x90f, c.rng.choice([0, 0, 1]))
    c.emu.w32(obj + 0x64c, c.rng.choice([10, 9, 11, 0]))
    c.emu.w32(obj + 0x91c, c.rng.choice([0, 0, 1, 0x100]))
    c.emu.w32(obj + 0x918, c.rng.getrandbits(32))
    c.emu.w32(obj, c.emu.logging_vtable('aim', 0x400,
                                        impl={0x50c: lambda e, a, v=first: (v, None),
                                              0x3f0: lambda e, a, v=w: (v, None)}))
    return [obj]


S(0x478ff0, 'ZActor::Hide (unknown) thiscall', 'thiscall', None, ret=None, gen=_hide,
  note='unclaimed-16 b5; thunk 0x45f070 stubbed (not verified); slot 0x58c if +0x640 nonzero')
S(0x59fc60, 'ZFFActor::GetAimAnim (unknown) thiscall', 'thiscall', None, ret='eax', gen=_aim,
  note='unclaimed-16 b5; tail target 0x473e50 stubbed (not verified); slots 0x50c 0x350 0x300 0x3f0')
