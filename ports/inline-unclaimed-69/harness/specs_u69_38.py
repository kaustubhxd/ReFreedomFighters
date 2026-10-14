"""specs_u69_38.py - area 69, group 38 (slice 8). Target 0x4cdd50 (other area, thiscall, one arg, ret 4) is a GUESS stub.
The stub logs the arg and the field it sees at self+0x28 (small integers only, never pointers)."""
from pilot import S
from ckit import rnd


def _hooks(e):
    e.hook(0x4cdd50, lambda e, res: (e.calllog.append(('t4cdd50', e.arg32(0), e.r32(e.reg('ecx') + 0x28))),
                                     e.ret(eax=((e.arg32(0) ^ 0x33) + 1) & 0xffffffff, argbytes=4)))


def _ch(c):
    _hooks(c.emu)
    o = rnd(c, 0x40)
    a = c.rng.choice([0, 1, 0x20, c.rng.getrandbits(16)])
    c.emu.w32(o + 0x28, c.rng.choice([a, 0, c.rng.getrandbits(16)]))
    return [o, a]


S(0x4cde00, 'chain4cde00 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_ch, note='u69 group 38; target 0x4cdd50 is a GUESS stub')
