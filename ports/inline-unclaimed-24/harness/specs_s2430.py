"""specs_s2430.py - decomp area 24, batch 2430.
0x514530 ZMoveOnSpline::StopRollingSound(), thiscall, plain ret: when the handle at +0x1d9 is set, slot 0x2ec of this with
the handle, then the handle is cleared. Slot 0x2ec is a recorder (one argument).
0x5390b0 (GUESS owner), thiscall, plain ret, AL = 1: slot 0xa8 of this (no argument), then slot 0x1bc of this with
this+0x53b2. Both recorders.
0x513130 ZMoveOnSpline::GetRefToPath(), thiscall, plain ret: slot 0x1c of the object at +0x5c gives a value; slot 0x4c of
the sys table (0x70039c)+0x9b is called with that value and its result returned. Both recorders."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _stop(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x200, {0x2ec: pystub(c, 1)})
    e.w32(o + 0x1d9, r.choice([0, r.getrandbits(32) | 1]))
    return [o]


def _two(c):
    clear_hooks(c)
    o = obj(c, 0x5400, {0xa8: pystub(c, 0), 0x1bc: pystub(c, 1)})
    return [o]


def _path(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    self_ = rnd(c, 0x100)
    a = obj(c, 0x40, {0x1c: pystub(c, 0, ret=lambda emu, k: r.getrandbits(32))})
    e.w32(self_ + 0x5c, a)
    return [self_]


S(0x514530, 'ZMoveOnSpline::StopRollingSound', 'thiscall', None, ret=None, gen=_stop, note='batch2430')
S(0x5390b0, 'GUESS: two-call setter returning AL = 1 (0x5390b0)', 'thiscall', None, ret='al', gen=_two, note='batch2430')
S(0x513130, 'ZMoveOnSpline::GetRefToPath', 'thiscall', None, ret='eax', gen=_path, note='batch2430')
