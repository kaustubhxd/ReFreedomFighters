"""specs_u69_59.py - area 69, group 59 (slice 8): 0x549280, a constructor over the base constructor 0x54cc50 (GUESS stub: logs ECX as a boolean and its arg; ret 4 assumed)."""
from pilot import S
from ckit import rnd


def _ctor(c):
    e = c.emu
    o = rnd(c, 0x6400)
    a = c.rng.choice([0, 1, 0x10, c.rng.getrandbits(16)])
    e.hook(0x54cc50, lambda e, res: (e.calllog.append(('t54cc50', int(e.reg('ecx') == o), e.arg32(0))), e.ret(argbytes=4)))
    return [o, a]


S(0x549280, 'ctor6a32b4_549280 (thiscall, one arg, ret 4, returns this)', 'thiscall', None, ret='eax', gen=_ctor,
  note='u69 group 59; base ctor 0x54cc50 is a GUESS stub (other area; ret 4 assumed)')
