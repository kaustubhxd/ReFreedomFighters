"""specs_s987.py - residue-11, batch 987: ZActor::ActivateAnimSegment (0x477670). The tail 0x461250 is a counting stub (five args, ret 0x14)
that answers a random value (EAX is the function's result). The actor's slots 0x628, 0x588 and 0x62c are stubs. The header's
flag byte, vector and the actor's flag and count fields are random, with zero vectors and the count 10 in some cases, so every branch
is reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x461250, _stub(c, 5, ret=r32(c)))
    t = obj(c, 0x800, {0x628: _stub(c, 3), 0x588: _stub(c, 0, ret=r32(c)), 0x62c: _stub(c, 1)})
    c.emu.wbytes(t + 0x726, bytes([1 if c.rng.random() < 0.7 else 0]))
    c.emu.w32(t + 0x64c, 10 if c.rng.random() < 0.2 else r32(c))
    h = obj(c, 0x100)
    c.emu.wbytes(h + 0x7c, bytes([0x40 if c.rng.random() < 0.7 else r32(c) & 0xff]))
    for off in (0x70, 0x74, 0x78):
        c.emu.w32(h + off, 0 if c.rng.random() < 0.3 else rf(c, -0.01, 0.01))
    flags = c.rng.choice([0, 4, 1, 5, r32(c)])
    return [t, h, flags, rf(c, -1, 1), rf(c, -1, 1), rf(c, -1, 1)]


S(0x477670, 'ZActor::ActivateAnimSegment', 'thiscall', ret='eax', gen=g)
