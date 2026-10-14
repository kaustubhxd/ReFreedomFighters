"""specs_u69_39.py - area 69, group 39 (slice 8). GUESS stubs: 0x656de0 (other area), 0x6043c0 (fastcall, SEH frame not reproduced).
Only small integers are logged, never pointers."""
from pilot import S
from ckit import rnd


def _ctor(c):
    e = c.emu
    e.hook(0x656de0, lambda e, res: (e.calllog.append(('t656de0', e.arg32(0))), e.ret(eax=0, argbytes=4)))
    return [rnd(c, 0x20), c.rng.choice([0, 1, 0x40, c.rng.getrandbits(16)])]


def _byte(c):
    return [rnd(c, 0x100)]


def _wrap(c):
    e = c.emu
    e.hook(0x6043c0, lambda e, res: (e.calllog.append(('t6043c0', e.reg('ecx'), e.reg('edx'))),
                                     e.ret(eax=(e.reg('ecx') ^ e.reg('edx')) + 5 & 0xffffffff, argbytes=0)))
    return [c.rng.choice([0, 1, 0x10, c.rng.getrandbits(16)]), c.rng.getrandbits(32)]


S(0x607c80, 'ctorVt6b9fc4 (thiscall, one arg, returns this)', 'thiscall', None, ret='eax', gen=_ctor, note='u69 group 39; 0x656de0 is a GUESS stub')
S(0x432540, 'byteAtFd432540 (thiscall, no args, returns byte)', 'thiscall', None, ret='al', gen=_byte, note='u69 group 39; compares al only')
S(0x601ec0, 'wrapper601ec0 (stdcall, two args, ret 8)', 'stdcall', None, ret='eax', gen=_wrap, note='u69 group 39; SEH frame in 0x6043c0 not reproduced; 0x6043c0 is a GUESS stub (SEH tag)')
