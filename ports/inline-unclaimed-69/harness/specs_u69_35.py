"""specs_u69_35.py - area 69, group 35 (slice 8). Targets 0x5ac940 (other area), 0x634273 and 0x634d52 (CRT) are GUESS stubs.
Only small integers are logged; pointers never are."""
from pilot import S
from ckit import rnd


def _hooks(e):
    e.hook(0x5ac940, lambda e, res: (e.calllog.append(('t5ac940', e.reg('ecx'), e.arg32(0))),
                                     e.ret(eax=(e.reg('ecx') + e.arg32(0) * 3 + 1) & 0xffffffff, argbytes=4)))
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', e.arg32(1))), e.ret(argbytes=0)))
    e.hook(0x634d52, lambda e, res: (e.calllog.append(('call634d52',)), e.ret(argbytes=0)))


def _t5(c):
    _hooks(c.emu)
    o = rnd(c, 0x20)
    c.emu.w32(o + 0xc, c.rng.choice([0, 1, 0x40, c.rng.getrandbits(16)]))
    return [o, c.rng.getrandbits(16)]


def _f64(c):
    _hooks(c.emu)
    o = rnd(c, 0x40)
    p = rnd(c, 0x10) if c.rng.random() < 0.7 else 0
    c.emu.w32(o + 0x20, p)
    return [o]


def _f40(c):
    _hooks(c.emu)
    p = rnd(c, 0x10) if c.rng.random() < 0.8 else 0
    # log whether the stub got the spec's pointer (a boolean), never the pointer itself
    c.emu.hook(0x634d52, lambda e, res: (e.calllog.append(('call634d52', int(e.arg32(0) == p))), e.ret(argbytes=0)))
    return [p]


S(0x5ef040, 'thunk5ef040 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_t5, note='u69 group 35; target 0x5ac940 is a GUESS stub')
S(0x64fe40, 'freeSlot64fe40 (thiscall, no args)', 'thiscall', None, ret=None, gen=_f64, note='u69 group 35; sized delete 0x634273 is a GUESS stub')
S(0x402480, 'clear3402480 (cdecl, one arg)', 'cdecl', None, ret=None, gen=_f40, note='u69 group 35; 0x634d52 is a GUESS stub')
