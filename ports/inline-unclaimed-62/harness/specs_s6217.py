"""specs_s6217.py - unclaimed-62 claim 10 (slice 1): 0x516d10 (no name; thiscall, one argument: the archive object; returns al = 1).
The archive is a logged vtable object (slots 0x40, 0x50, 0x68, 0x6c, one argument each; the parameter's stack address is peeked for slot 0x40).
The message table's slot 0x58 (one argument) returns a value per call. The record is 0x80 bytes of random data; every write is compared.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _x(c):
    e = c.emu
    r = c.rng
    arch = e.alloc(0x40)
    e.w32(arch, vtable(c, 'arch516', 0x100,
                       impl={0x40: lambda em, a: 0, 0x50: lambda em, a: 0, 0x68: lambda em, a: 0, 0x6c: lambda em, a: 0},
                       argwords={0x40: 1, 0x50: 1, 0x68: 1, 0x6c: 1},
                       opts={0x40: {'peek': {0: 4}}}))
    vals = [r.getrandbits(32) for _ in range(4)]
    msg = e.alloc(0x80)
    e.w32(msg, vtable(c, 'msg516', 0x80, impl={0x58: lambda em, a: vals[len(em.calllog) % 4]}, argwords={0x58: 1}))
    eng = e.alloc(0x100)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    rec = e.alloc(0x80)
    e.wbytes(rec, bytes(r.getrandbits(8) for _ in range(0x80)))
    return [rec, arch]


S(0x516d10, 'unnamed 0x516d10', 'thiscall', None, ret='al', gen=_x, n=1000)
