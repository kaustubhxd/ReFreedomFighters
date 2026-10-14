"""specs_u69_45.py - area 69, group 45 (slice 8): 0x4c4b10 (SEH tag: the frame is not reproduced).
GUESS stubs: 0x4c4a70 (other area, thiscall, no args, its own SEH frame), 0x4690b0 (empty cdecl), and 0x40ce50 (the indirect-call target:
the spec points the global 0x7003b0 at it, since the original traps with int3 when that global is null)."""
from pilot import S
from ckit import rnd


def _gen(c):
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(0x7003b0, 0x40ce50)
    e.hook(0x4c4a70, lambda e, res: (e.calllog.append(('t4c4a70', int(e.reg('ecx') == o))), e.ret(argbytes=0)))
    e.hook(0x4690b0, lambda e, res: (e.calllog.append(('t4690b0', int(e.arg32(0) == o), e.arg32(1))), e.ret(argbytes=0)))
    e.hook(0x40ce50, lambda e, res: (e.calllog.append(('indirect',)), e.ret(argbytes=0)))
    return [o, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7, c.rng.getrandbits(8)])]


S(0x4c4b10, 'checkedCall4c4b10 (thiscall, one arg, ret 4; SEH tag)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 45; SEH frame not reproduced; GUESS stubs 0x4c4a70, 0x4690b0, 0x40ce50 (indirect target)')
