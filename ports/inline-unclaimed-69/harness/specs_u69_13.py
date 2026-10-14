"""specs_u69_13.py - area 69, group 13 (unclaimed-69 thread): 0x61bbd0 wrapper around cdecl 0x61be30."""
from pilot import S
from ckit import rnd


def _w(c):
    e = c.emu
    # 0x61be30 is another area's function: a logging stub (GUESS). Only small integers are logged, never pointers.
    e.hook(0x61be30, lambda e, res: (e.calllog.append(('helper61be30', e.arg32(0))), e.ret(argbytes=0)))
    o = rnd(c, 0x40)
    e.w32(o + 4, c.rng.choice([0, 1, 0x1234, c.rng.getrandbits(16)]))
    return [o]


S(0x61bbd0, 'wrapper61bbd0 (thiscall, calls cdecl 0x61be30)', 'thiscall', None, ret=None, gen=_w,
  note='u69 group 13; 0x61be30 is a GUESS stub (other area)')
