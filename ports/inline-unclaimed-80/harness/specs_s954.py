"""specs_s954.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x44f540 and 0x4351a0 (see src/batch954.cpp).
0x44f540: the object is 0x200 random bytes; the callee 0x450980 is hooked by address with a recording stub (it faults in the emulator
without its state; it has its own row). 0x4351a0: self+8 is an inner object (null 30%)
whose logging vtable slot +0x90 takes one stack argument (callee-cleaned) and returns a per-case value. The null path leaves EAX as it
came in, so that row is checked with ret=None (the stack pop and the calls are still compared)."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    ss.patch(c, 0x450980, ss.rec(c, 1, ret=0))   # the callee faults for real here (its own row); hooked by address
    return [_rnd(c, 0x200)]


def _tail(c):
    v = c.rng.getrandbits(32)
    self_o = _rnd(c, 0x40)
    if c.rng.random() < 0.3:
        c.emu.w32(self_o + 8, 0)
    else:
        inner = _rnd(c, 0x40)
        c.emu.w32(inner, c.emu.logging_vtable('ZTailInner', 0x25, impl={0x90: (lambda e, a, r=v: (r, None))},
                                               argwords={0x90: 1}))
        c.emu.w32(self_o + 8, inner)
    return [self_o, c.rng.getrandbits(32)]


S(0x44f540, 'calls 0x450980 with one argument (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-80 gap band; push 1, call 0x450980 (real), ret')
S(0x4351a0, 'tail call through vtable +0x90 (unknown) thiscall', 'thiscall', None, ret=None, gen=_tail,
  note='unclaimed-80 gap band; one stack argument, ret 4; null path leaves EAX (ret=None)')
