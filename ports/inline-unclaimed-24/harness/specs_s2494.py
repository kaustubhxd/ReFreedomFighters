"""specs_s2494.py - decomp area 24, batch 2494 (residue 3, smallest first).
0x54e370 (GUESS): thiscall, void; count dword at +0x37 in -3..6 (the loop bound, read each pass); field copies and clears as in the source.
0x4c2730 (GUESS): thiscall, ret 4, AL = 1; argument object: slots 0x40, 0x3c, 0x3c, 0x4c (recorders, thiscall, one argument each).
0x54ed70 (GUESS): thiscall, ret 8, EAX = 0 or 1; argument object's slot 0 is COM-style (stdcall, three arguments: this, IID, out; pops 12)
returning a fixed HRESULT; when the flag's low byte is set and the HRESULT is non-negative, slot 0x10 of this (recorder)."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _reset(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    e.w32(o + 0x37, r.randint(-3, 6) & 0xffffffff)
    return [o]


def _argcalls(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    arg = obj(c, 0x40, {0x40: pystub(c, 1), 0x3c: pystub(c, 1), 0x4c: pystub(c, 1)})
    o = rnd(c, 0x80)
    e.w32(o + 4, r.getrandbits(32))
    e.w32(o + 0x56, struct.unpack('<I', struct.pack('<f', r.uniform(-50.0, 50.0)))[0])
    return [o, arg]


def _qi(c):
    clear_hooks(c)
    r = c.rng
    hr = r.choice([0, 1, 0x80004002])
    arg = obj(c, 0x40, {0: pystub(c, 3, ret=hr)})
    self_ = obj(c, 0x40, {0x10: pystub(c, 0)})
    return [self_, arg, r.choice([0, 1, 0x100])]


S(0x54e370, 'GUESS field reset loop', 'thiscall', None, ret=None, gen=_reset, note='batch2494')
S(0x4c2730, 'GUESS argument calls', 'thiscall', None, ret='al', gen=_argcalls, note='batch2494')
S(0x54ed70, 'GUESS COM query and notify', 'thiscall', None, ret='eax', gen=_qi, note='batch2494')
