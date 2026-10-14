"""specs_u69_57.py - area 69, group 57 (slice 8): 0x4ee240, a constructor over the base constructor 0x43de40 (GUESS stub: logs
ECX as a boolean against the object and its three args as small values; no memory effect)."""
from pilot import S
from ckit import rnd


def _ctor(c):
    e = c.emu
    o = rnd(c, 0x100)
    a, b, cc = (c.rng.choice([0, 1, 0x10, c.rng.getrandbits(16)]) for _ in range(3))
    e.hook(0x43de40, lambda e, res: (e.calllog.append(('t43de40', int(e.reg('ecx') == o), e.arg32(0), e.arg32(1), e.arg32(2))),
                                     e.ret(argbytes=0xc)))
    return [o, a, b, cc]


S(0x4ee240, 'ctor697e9c4ee240 (thiscall, three args, ret 0xc, returns this)', 'thiscall', None, ret='eax', gen=_ctor,
  note='u69 group 57; base ctor 0x43de40 is a GUESS stub (other area)')
