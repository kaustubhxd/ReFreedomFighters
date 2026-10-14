"""specs_s5724.py - unclaimed-57, band batch 24: 0x5c7720 (thiscall, one arg, returns al = 1) and 0x5d9180 (thiscall, one arg). 0x5c7720:
the object's slot +0x60 (one argument) is a logging stub. 0x5d9180: reader A (0x4e5e60, ECX = the argument) is hooked; its result is
the argument's dword plus a fixed value chosen in gen, so the store is compared exactly."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_call(c):
    vt = c.emu.logging_vtable('band5c7720_obj', 40, argwords={0x60: 1})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    self = _rnd(c, 0x200)
    return [self, obj]


def _reader(c):
    k = c.rng.getrandbits(32)
    c.emu.hook(0x4e5e60, lambda em, r: em.ret(eax=(em.r32(em.reg('ecx')) + k) & 0xffffffff, argbytes=0))
    return [_rnd(c, 0x200), _rnd(c, 0x40)]


S(0x5c7720, 'unnamed_5c7720 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_obj_call,
  note='unclaimed-57 band batch 24; obj slot +0x60 stubbed (logged); returns 1')
S(0x5d9180, 'unnamed_5d9180 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_reader,
  note='unclaimed-57 band batch 24; reader 0x4e5e60 hooked (dword of ECX + fixed value)')
