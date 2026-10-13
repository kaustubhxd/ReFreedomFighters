"""specs_s1135.py - collision thread batch 1135 (GUESS name): 0x55ec00, a stdcall that tail-jumps to slot 0 of its argument
with the argument replaced by 1. The slot-0 target is a logging fake (thiscall, one argument, logged; its per-case EAX is the
result). A null argument returns at once."""
from pilot import S, F


def _tail(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)
    vt = e.logging_vtable('obj0_55ec00', 0x10, impl={0: lambda em, a: (retv, None)}, argwords={0: 1})
    o = e.alloc(0x40, 4)
    e.w32(o, vt)
    return [o if r.random() < 0.8 else 0]


S(0x55ec00, 'stdcall: null returns; else slot 0 of the argument with argument 1 (name GUESS)', 'stdcall', None, ret='eax',
  gen=_tail, note='batch1135')
