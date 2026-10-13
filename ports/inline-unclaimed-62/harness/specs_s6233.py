"""specs_s6233.py - unclaimed-62 claim 26 (short exe leaves): 0x54dbd0 (thiscall, one argument; counter at this+0x8031 zero in a third of cases,
argument zero in a fifth), 0x54a240 (no arguments; the engine's +0x190f pointer null in half the cases, the dwords at +0x133 and +0x9db compared),
0x5646b0 (thiscall, returns al; the bytes at +0x85 and +0x18a and the dword at +0xc9a are set to zero or to the tested values in turn).
The engine object at 0x70039c is a 0x1000-byte random block. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x54d(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x9000)
    e.w32(rec + 0x8031, r.choice([0, 0, r.randint(1, 1000)]))
    return [rec, r.choice([0, r.getrandbits(16)])]


def _x54a2(c):
    e = c.emu
    r = c.rng
    eng = rnd(c, 0x1000)
    sub = rnd(c, 0x200)
    e.w32(eng + 0x190f, sub if r.random() < 0.5 else 0)
    e.w32(0x70039c, eng)
    return []


def _x5646(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    e.w8(rec + 0x85, r.choice([0, 1]))
    e.w32(rec + 0xc9a, r.choice([0xa, r.getrandbits(8)]))
    e.w8(rec + 0x18a, r.choice([0, 1]))
    return [rec]


S(0x54dbd0, 'unnamed 0x54dbd0', 'thiscall', None, ret='eax', gen=_x54d, n=1000)
S(0x54a240, 'unnamed 0x54a240', 'cdecl', None, ret='eax', gen=_x54a2, n=1000)
S(0x5646b0, 'unnamed 0x5646b0', 'thiscall', None, ret='al', gen=_x5646, n=1000)
