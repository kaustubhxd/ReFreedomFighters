"""specs_s1011.py - area 81, batch 1011: CTargetObtained::Command (0x5c53f0). The command word matches this+0x148 in most cases; the helpers 0x5c5620
(returns a bool), 0x589c20 (returns an object O), 0x59a580, 0x5c5810 and 0x596940 are counting stubs; the global test function at 0x676414 is a cdecl
stub returning a random bool. The render manager's slot 0x138 returns an object A whose slot 0x88 writes the local L (a random word). The render manager's
slot 0x58 returns x (or null) whose +0x852 word is random, so both the first block and the second block (flag at this+0x152) run.
The unused second argument is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    rnd = c.rng
    ss.patch(c, 0x5c5620, ss.rec(c, 0, ret=1 if rnd.random() < 0.2 else 0))
    O = obj(c, 0x40)
    ss.patch(c, 0x589c20, ss.rec(c, 1, ret=O))
    ss.patch(c, 0x59a580, ss.rec(c, 3))
    ss.patch(c, 0x5c5810, ss.rec(c, 0))
    ss.patch(c, 0x596940, ss.rec(c, 4, log=False))
    c.emu.w32(0x676414, cstub(c, 2, ret=rnd.choice([0, 1])))
    c.emu.w32(0x7003b8, r32(c))
    Lsrc = c.emu.alloc(4, 4)
    c.emu.w32(Lsrc, r32(c))
    C = obj(c, 0x40)
    B = obj(c, 0x40, {0: _stub(c, 2, ret=C)})
    A = obj(c, 0x40, {0x88: _stub(c, 2, skip=(0, 1), ofills=((1, 0, Lsrc, 1),))})
    x = obj(c, 0x1000, {0x128: _stub(c, 1)})
    c.emu.w32(x + 0x852, r32(c) if rnd.random() < 0.8 else 0)
    rm = obj(c, 0x1000, {0x138: _stub(c, 0, ret=A),
                         0x58: _stub(c, 1, ret=x if rnd.random() < 0.8 else 0),
                         0x114: _stub(c, 6, ret=r32(c))})
    c.emu.w32(rm + 0xae4, B)
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    self_ = obj(c, 0x200)
    cmd_word = rnd.randint(0, 0xffff)
    c.emu.wbytes(self_ + 0x148, bytes([cmd_word & 0xff, cmd_word >> 8]))
    c.emu.wbytes(self_ + 0x152, bytes([1 if rnd.random() < 0.6 else 0]))
    cmd = cmd_word if rnd.random() < 0.8 else rnd.randint(0, 0xffff)
    return [self_, cmd, r32(c)]


S(0x5c53f0, 'CTargetObtained::Command', 'thiscall', None, ret='eax', gen=g)
