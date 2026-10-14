"""specs_u69_34.py - area 69, group 34 (slice 8): four tail-jump thunks. Targets 0x4dbd10, 0x6402b0, 0x4d0d20 and 0x4cdb20 are GUESS stubs (other areas).
Only small integers are logged; ECX pointers are never logged."""
from pilot import S
from ckit import rnd


def _hooks(e):
    e.hook(0x4dbd10, lambda e, res: (e.calllog.append(('target4dbd10', e.reg('ecx'))),
                                     e.ret(eax=(e.reg('ecx') * 3) & 0xffffffff, argbytes=0)))
    e.hook(0x6402b0, lambda e, res: (e.calllog.append(('target6402b0', e.arg32(0))),
                                     e.ret(eax=(e.arg32(0) * 5 + 1) & 0xffffffff, argbytes=4)))
    e.hook(0x4d0d20, lambda e, res: (e.calllog.append(('target4d0d20', e.reg('ecx'), e.arg32(0))),
                                     e.ret(eax=((e.reg('ecx') ^ e.arg32(0)) + 7) & 0xffffffff, argbytes=4)))
    e.hook(0x4cdb20, lambda e, res: (e.calllog.append(('target4cdb20',)), e.ret(eax=0x77, argbytes=0)))


def _small(c):
    return c.rng.choice([0, 1, 0x40, 0x77, c.rng.getrandbits(16)])


def _t45(c):
    _hooks(c.emu)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, _small(c))
    return [o]


def _t615(c):
    _hooks(c.emu)
    return [rnd(c, 0x20), _small(c)]


def _t41f(c):
    _hooks(c.emu)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x31, _small(c))
    return [o, _small(c)]


def _t4c(c):
    _hooks(c.emu)
    return [rnd(c, 0x40)]


S(0x45f400, 'thunk45f400 (thiscall, no args)', 'thiscall', None, ret='eax', gen=_t45, note='u69 group 34; target 0x4dbd10 is a GUESS stub')
S(0x615380, 'thunk615380 (thiscall, one arg)', 'thiscall', None, ret='eax', gen=_t615, note='u69 group 34; target 0x6402b0 is a GUESS stub')
S(0x41f1c0, 'thunk41f1c0 (thiscall, one arg)', 'thiscall', None, ret='eax', gen=_t41f, note='u69 group 34; target 0x4d0d20 is a GUESS stub')
S(0x4cdb80, 'thunk4cdb80 (thiscall, no args)', 'thiscall', None, ret='eax', gen=_t4c, note='u69 group 34; target 0x4cdb20 is a GUESS stub')
