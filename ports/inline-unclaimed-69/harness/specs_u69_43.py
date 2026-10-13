"""specs_u69_43.py - area 69, group 43 (slice 8). Builds the pointer chain self+0x10 -> p1, p1+0x1c -> p2, p2+4 -> p3, p3+4 -> small int.
Stub 0x5f4170 (other area, thiscall, no args, ret 0) logs whether ECX is the small int (a boolean)."""
from pilot import S
from ckit import rnd


def _gen(c):
    e = c.emu
    o = rnd(c, 0x40)
    p1 = rnd(c, 0x40)
    p2 = rnd(c, 0x40)
    p3 = rnd(c, 0x40)
    small = c.rng.choice([0, 1, 0x30, c.rng.getrandbits(16)])
    e.w32(o + 0x10, p1)
    e.w32(p1 + 0x1c, p2 if c.rng.random() < 0.8 else 0)
    e.w32(p2 + 4, p3 if c.rng.random() < 0.8 else 0)
    e.w32(p3 + 4, small)
    e.hook(0x5f4170, lambda e, res: (e.calllog.append(('t5f4170', e.reg('ecx') == small and 1 or 0)), e.ret(eax=0x65, argbytes=0)))
    return [o]


def _gen48(c):
    e = c.emu
    o = rnd(c, 0x20)
    e.w32(o + 8, c.rng.choice([0, 1, 0x40, c.rng.getrandbits(16)]))
    a = c.rng.choice([0, 1, 0x40, c.rng.getrandbits(16)])
    e.hook(0x496350, lambda e, res: (e.calllog.append(('t496350', e.arg32(0), e.reg('ecx'))),
                                     e.ret(eax=(e.arg32(0) ^ e.reg('ecx')) + 9 & 0xffffffff, argbytes=4)))
    return [o, a]


S(0x478400, 'chain478400 (thiscall, no args; tail jump to 0x5f4170)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 43; 0x5f4170 is a GUESS stub (other area, 528 bytes)')
S(0x48cf40, 'chain48cf40 (thiscall, one arg; tail jump to 0x496350)', 'thiscall', None, ret='eax', gen=_gen48,
  note='u69 group 44; 0x496350 is a GUESS stub: arity (one stack arg, ret 4) is a GUESS, the final callee is selected at run time')
