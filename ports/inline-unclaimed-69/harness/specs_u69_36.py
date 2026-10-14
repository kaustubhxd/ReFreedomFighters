"""specs_u69_36.py - area 69, group 36 (slice 8). 0x41e290 (other area, cdecl one arg) is a GUESS stub; its real tail jumps through [0x6762f0]."""
from pilot import S


def _hooks(e):
    e.hook(0x41e290, lambda e, res: (e.calllog.append(('alloc41e290', e.arg32(0))),
                                     e.ret(eax=(e.arg32(0) * 7 + 3) & 0xffffffff, argbytes=0)))


def _ac(c):
    _hooks(c.emu)
    return [c.rng.choice([0, 1, 0x2a, 0x1c, c.rng.getrandbits(16)]), c.rng.getrandbits(32)]


S(0x6014c0, 'allocCheck6014c0 (stdcall, two args, ret 8)', 'stdcall', None, ret='eax', gen=_ac, note='u69 group 36; 0x41e290 is a GUESS stub (other area)')
