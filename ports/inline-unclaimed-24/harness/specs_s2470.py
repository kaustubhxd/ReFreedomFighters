"""specs_s2470.py - decomp area 24, batch 2470 (parked: ZROOM::CalcBestRoom, 0x4442d0).
Logger (global 0x700390): slot 0x20 is called thiscall with (0x67d564, 0x267) and returns R1 (recorder, returns R1). R1's vtable
slot 0x2c is called cdecl with (R1, 0x67d5a4) (recorder, pops nothing). The global function pointer at 0x7003b0 is called with
no pushed argument and pops nothing; the entry's four arguments stay on the stack for it and are popped by this function's
ret 16. Its first stack word differs between builds (a return address), so the recorder takes zero arguments. Returns 0, stdcall."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks
import struct


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    R1 = obj(c, 0x40, {0x2c: pystub(c, 2, pop=0)})
    L = obj(c, 0x40, {0x20: pystub(c, 2, ret=lambda emu, k: R1)})
    e.w32(0x700390, L)
    e.w32(0x7003b0, pystub(c, 0, pop=0))
    return [r.getrandbits(32), rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)]


S(0x4442d0, 'ZROOM::CalcBestRoom', 'stdcall', None, ret='eax', gen=_gen, note='batch2470')
