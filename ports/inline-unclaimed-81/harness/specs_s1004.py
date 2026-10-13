"""specs_s1004.py - area 81 (residue 0), batch 1004: CRigidBody::Command (0x53e6c0). The command word is picked from the eleven compare words of the object
(or a random word), so each branch runs. The helpers 0x634e90, 0x53f0e0, 0x53eeb0, 0x53efd0 and 0x53f770 are counting stubs; the object's vslot 0x84
is a counting stub. The argument object holds three random dwords."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32

WORDS = (0x5c, 0x5e, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x60)


def g(c):
    for a in (0x634e90, 0x53f0e0, 0x53eeb0, 0x53efd0):
        ss.patch(c, a, ss.rec(c, 1))
    ss.patch(c, 0x53f770, ss.rec(c, 0))
    self_ = obj(c, 0x400, {0x84: _stub(c, 1)})
    vals = {}
    for off in WORDS:
        v = c.rng.randint(0, 0xffff)
        vals[off] = v
        c.emu.wbytes(self_ + off, struct.pack('<H', v))
    arg = obj(c, 0x40)
    for k in range(3):
        c.emu.w32(arg + 4 * k, r32(c))
    cmd = vals[c.rng.choice(WORDS)] if c.rng.random() < 0.85 else c.rng.randint(0, 0xffff)
    return [self_, cmd, arg]


S(0x53e6c0, 'CRigidBody::Command', 'thiscall', None, ret='eax', gen=g)
