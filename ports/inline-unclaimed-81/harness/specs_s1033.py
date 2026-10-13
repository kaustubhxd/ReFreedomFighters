"""specs_s1033.py - area 81, batch 1033: 0x44ae20 (thiscall: this; a1). The render manager helper (sys+0x1aa3) has a slot-0x18 object M whose slot 0x100 returns a
pointer to a count word (0..5) and whose slot 0xfc returns the element base (six 0x24-byte elements). The argument is an element address (found, about half the
cases) or a random word (not found). this+8 is an object whose +0x6c is a random word. The debug object's slot 0x20 gives a channel whose slot 0x2c is a
two-argument cdecl stub. Counts of 2 to 5 are used in most cases (count - 1 is not zero)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    rnd = c.rng
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    base = c.emu.alloc(0x24 * 6 + 8, 4)
    c.emu.wbytes(base, bytes(rnd.getrandbits(8) for _ in range(0x24 * 6 + 8)))
    cnt = rnd.randint(2, 5) if rnd.random() < 0.9 else rnd.randint(0, 1)
    cntobj = obj(c, 0x40)
    c.emu.w32(cntobj, cnt)
    M = obj(c, 0x40, {0x100: _stub(c, 1, ret=cntobj), 0xfc: _stub(c, 1, ret=base)})
    rm2 = obj(c, 0x40)
    c.emu.w32(rm2 + 0x18, M)
    c.emu.w32(sysobj + 0x1aa3, rm2)
    dbgchan = obj(c, 0x40, {0x2c: cstub(c, 2)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgchan)})
    c.emu.w32(0x700390, dbg)
    O2 = obj(c, 0x80)
    c.emu.w32(O2 + 0x6c, r32(c))
    self_ = obj(c, 0x40)
    c.emu.w32(self_ + 8, O2)
    if rnd.random() < 0.5 and cnt > 0:
        a1 = base + 0x24 * rnd.randint(0, cnt - 1)
    else:
        a1 = r32(c)
    return [self_, a1 & 0xffffffff]


S(0x44ae20, 'GUESS 0x44ae20 index fraction', 'thiscall', None, ret='st0', gen=g)
