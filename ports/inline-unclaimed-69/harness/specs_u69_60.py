"""specs_u69_60.py - area 69, group 60 (slice 8): 0x498700. The cdecl helper 0x41e290 is a GUESS stub: logs its arg (a computed 32-bit value, not a pointer)
and returns a fixed function of it; the caller pops one argument."""
from pilot import S
from ckit import rnd


def _ref(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x80)
    e.w32(o + 0x20, r.choice([0, 1, 1000, 0x7fffffff, 0x80000000, 0xffffffff, 0xec9f6fbf, 0xcf696e8f, 0xeb70399f, 0xd2f3b53f, 0xdba0e8bf, r.getrandbits(32)]))
    e.w32(o + 0x61, r.getrandbits(32))
    e.hook(0x41e290, lambda e, res: (e.calllog.append(('t41e290', e.arg32(0))), e.ret(eax=(e.arg32(0) * 3 + 1) & 0xffffffff, argbytes=0)))
    return [o]


S(0x498700, 'refresh498700 (thiscall, no args)', 'thiscall', None, ret=None, gen=_ref, note='u69 group 60; 0x41e290 is a GUESS stub (cdecl, one arg)')
