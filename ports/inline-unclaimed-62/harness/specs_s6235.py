"""specs_s6235.py - unclaimed-62 claim 28 (short call-free exe functions): 0x54dbb0 (stdcall, one pointer argument; the two divisors are 1..9 so the
divisions are defined), 0x54e430 (thiscall, no argument; the counter at +0x1c5 is -1..4 so the signed loop runs 0..4 times over the strided records),
0x54e9a0 (thiscall, no argument; returns this; the vtable word and the two zeroed words are compared), 0x4cdaf0 (thiscall, one mask argument in 0..63; a
64-entry table gives the words the bit test reads; the flag word is random). Records are 0x1000 random bytes. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x54dbb0(c):
    e = c.emu
    r = c.rng
    a = rnd(c, 0x100)
    e.w32(a + 0x24, r.getrandbits(32))
    e.w32(a + 0xc, r.randint(1, 9))
    e.w32(a + 0x1c, r.randint(1, 9))
    return [a]


def _x54e430(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    e.w32(rec + 0x1c5, r.randint(-1, 4) & 0xffffffff)
    return [rec]


def _x54e9a0(c):
    return [rnd(c, 0x100)]


def _x4cdaf0(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x100)
    table = e.alloc(4 * 64)
    e.wbytes(table, bytes(r.getrandbits(8) for _ in range(256)))
    e.w32(rec + 4, table)
    e.w32(rec + 0x10, r.getrandbits(32))
    return [rec, r.randint(0, 63)]


S(0x54dbb0, 'unnamed 0x54dbb0', 'stdcall', None, ret='eax', gen=_x54dbb0, n=300)
S(0x54e430, 'unnamed 0x54e430', 'thiscall', None, gen=_x54e430, n=300)
S(0x54e9a0, 'unnamed 0x54e9a0', 'thiscall', None, ret='eax', gen=_x54e9a0, n=300)
S(0x4cdaf0, 'unnamed 0x4cdaf0', 'thiscall', None, ret='al', gen=_x4cdaf0, n=300)
