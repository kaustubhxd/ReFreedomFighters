"""specs_u69_69.py - area 69, group 69 (slice 8): three scalar deleting destructors (0x45b580, 0x44ca80, 0x4f3c40). GUESS stubs: base dtors 0x43de70 and
0x43ea20 (thiscall, no args), and the delete helper 0x45c510 (cdecl, one arg). The empty helper 0x4690b0 is stubbed too (logging its args) so its size argument is observed.
The stubs log whether ECX (or the one arg) is the spec's object, as a boolean, and never log the pointer."""
from pilot import S
from ckit import rnd


def _hooks(e, o):
    e.hook(0x43de70, lambda e, res: (e.calllog.append(('base43de70', int(e.reg('ecx') == o))), e.ret(argbytes=0)))
    e.hook(0x43ea20, lambda e, res: (e.calllog.append(('base43ea20', int(e.reg('ecx') == o))), e.ret(argbytes=0)))
    e.hook(0x45c510, lambda e, res: (e.calllog.append(('del45c510', int(e.arg32(0) == o))), e.ret(argbytes=0)))
    e.hook(0x4690b0, lambda e, res: (e.calllog.append(('t4690b0', int(e.arg32(0) == o), e.arg32(1))), e.ret(argbytes=0)))


def _gen(c):
    o = rnd(c, 0x100)
    _hooks(c.emu, o)
    return [o, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7])]


S(0x45b580, 'dtorBulletMarks45b580 (thiscall, one arg, ret 4, returns this)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 69; GUESS stubs 0x43de70 and 0x45c510')
S(0x44ca80, 'dtorBloodSpray44ca80 (thiscall, one arg, ret 4, returns this)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 69; GUESS stubs 0x43de70 and 0x45c510')
S(0x4f3c40, 'dtorWindow4f3c40 (thiscall, one arg, ret 4, returns this)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 69; GUESS stubs 0x43ea20 and 0x45c510')
