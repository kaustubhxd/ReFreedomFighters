"""specs_s1023.py - area 81, batch 1023: ZShotActivate::Command (0x4c8860), group 1. The globals 0x700370 and 0x70036c are the group-2 words; the spec keeps the
command word away from them (the port traps there). The word 0x700378 is the store command in about a third of cases. The object's fields +0x58 and +0x59
are random. The SEH frame and cookie are not reproduced by the port."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj, r32


def g(c):
    rnd = c.rng
    w1 = rnd.randint(0, 0xffff)
    w2 = (w1 + 1 + rnd.randint(0, 0xfffd)) & 0xffff
    w3 = rnd.randint(0, 0xffff)
    c.emu.wbytes(0x700370, struct.pack('<H', w1))
    c.emu.wbytes(0x70036c, struct.pack('<H', w2))
    c.emu.wbytes(0x700378, struct.pack('<H', w3))
    avoid = {w1, w2}
    while True:
        cmd = w3 if rnd.random() < 0.35 else rnd.randint(0, 0xffff)
        if cmd not in avoid:
            break
    self_ = obj(c, 0x80)
    c.emu.wbytes(self_ + 0x58, bytes([rnd.randint(0, 1)]))
    return [self_, cmd, r32(c)]


S(0x4c8860, 'ZShotActivate::Command', 'thiscall', None, ret='eax', gen=g)
