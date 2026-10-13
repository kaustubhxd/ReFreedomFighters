"""specs_s1110.py - unclaimed-11 batch 10 (core-todo residue-10): ZFFActor::ClassFrameUpdate at 0x59e2a0, thiscall, no args.
Body: if the byte at +0x79f is set, the render object (global 0x70039c, +0x9b) slot 0x58 gets +0x78a; a nonzero result gets
slot 0x2d0(0, 0); the byte is cleared. Then the global 0x70038c object's slot 0x48 gets 0xff0000 and its result is kept;
0x477a30(this) runs; slot 0x48 is called again with the kept result; 0x59ead0(this) runs; then this's slot 0x438 gives al,
and if al is nonzero and +0x784 and +0x92e are both nonzero, +0x784 is cleared.
Stubs (unverified callees, no GC names or large exe bodies): 0x477a30, 0x59ead0 and the tail-jump target 0x5a3000 are rec stubs (no args, ret 0);
the render objects, the item-like object and this's slot 0x438 are mkobj stubs. The globals are set to stub objects."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S

G_RM = 0x70039c
G_ENG = 0x70038c


def _cfu(c):
    b = c.rng.getrandbits(8)
    t_obj = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=0), 0x2d0: ss.rec(c, 2)}, size=0x40)
    ret58 = t_obj if c.rng.random() < 0.7 else 0
    a = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=ret58), 0x2d0: ss.rec(c, 2)}, size=0x40)
    o_rm = ss.mkobj(c, {0x138: ss.code(c, b'\xc3')}, size=0x40)
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, a)
    c.emu.w32(G_RM, rm)
    eng = ss.mkobj(c, {0x48: ss.rec(c, 1, ret=c.rng.getrandbits(32))}, size=0x40)
    c.emu.w32(G_ENG, eng)
    ss.patch(c, 0x477a30, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x59ead0, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x5a3000, ss.rec(c, 0, ret=0))
    this = ss.mkobj(c, {0x438: ss.rec(c, 0, ret=c.rng.getrandbits(8))}, size=0x980)
    c.emu.w8(this + 0x79f, c.rng.choice([0, 1, 1]))
    c.emu.w32(this + 0x78a, c.rng.getrandbits(32))
    c.emu.w32(this + 0x784, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    c.emu.w32(this + 0x92e, 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    c.emu._image_dirty = True
    return [this]


S(0x59e2a0, 'ZFFActor::ClassFrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_cfu,
  note='unclaimed-11 batch 10 (residue 10); callees stubbed')
