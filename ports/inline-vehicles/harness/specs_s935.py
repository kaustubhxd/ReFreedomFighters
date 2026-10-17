"""specs_s935.py - vehicles batch 935: ZMoveOnSpline::ClassInit (0x512590). Pure exe callees run unchanged (0x4dc110,
0x4cc850). The others are stood in with counting stubs: 0x44a1f0, 0x4db860, 0x4cc1d0, 0x4cbec0, the hook at 0x7003b0,
the render manager (+0x9b), the debug object (0x700390), the exit/ground list objects and the body's geom."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, cstub, fconst, idstub

NAMES = ['CollisionBox_1', 'Coli_2', 'Body_3', 'Exit_Box_4', 'Ground_Box_5', 'Misc_6', 'Body_7']


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text.encode() + b'\0')
    return a


def g(c):
    tmp = _rnd(c, 0x40)
    self = obj(c, 0x300, {0x124: _stub(c, 4), 0x1d8: _stub(c, 2, skip=(0,), ret=tmp)})
    head = prev = 0
    for k in range(c.rng.randint(0, 4)):
        ch = _rnd(c, 0x80)
        nameobj = obj(c, 0x20, {0x1e0: _stub(c, 1, ret=c.rng.choice([0, 1]))})
        c.emu.w32(nameobj + 4, cstr(c, NAMES[c.rng.randrange(len(NAMES))]))
        c.emu.w32(ch + 0x54, nameobj)
        c.emu.w32(ch + 0x60, 0)
        if prev:
            c.emu.w32(prev + 0x60, ch)
        else:
            head = ch
        prev = ch
    c.emu.w32(self + 0x50, head)
    c.emu.w32(self + 0x123, 0)
    c.emu.w32(self + 0x127, obj(c, 0x20, {4: _stub(c, 1, ret=_rnd(c, 0x10))}))
    c.emu.w32(self + 0x12b, obj(c, 0x20, {4: _stub(c, 1, ret=_rnd(c, 0x10))}))
    # vtable of self: slot 0x124 (4 args), 0x1d8 (2 args, returns a temp pointer)
    tmp = _rnd(c, 0x40)
    # 0x44a1f0 (stood in), 0x4db860 (stood in), 0x4cc1d0, 0x4cbec0
    ss.patch(c, 0x44a1f0, ss.rec(c, 0))
    ss.patch(c, 0x4db860, ss.rec(c, 1))
    ss.patch(c, 0x4cc1d0, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4cbec0, ss.rec(c, 0))
    # render manager: 0x50 gives the id of the object passed, 0x58 gives the geom of an id
    tobj = obj(c, 0x40, {0x8: _stub(c, 0), 0x4c: _stub(c, 0), 0x54: _stub(c, 1)})
    c.emu.w32(tobj + 4, c.rng.getrandbits(32))
    c.emu.w32(tobj + 0x30, c.rng.getrandbits(32))
    geom = obj(c, 0x200, {0x10c: _stub(c, 2, ret=tobj), 0x3c: _stub(c, 1)})
    rmo = obj(c, 0x200, {0x50: _stub(c, 1, ret=r32(c)), 0x58: _stub(c, 1, ret=geom)})
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, rmo)
    c.emu.w32(0x70039c, rm)
    # the body's geom t: its +4 flags start random (bit 0 decides the branches)
    c.emu.w32(0x70039c, rm)
    # debug object and hook
    dbgo = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgo)})
    c.emu.w32(0x700390, dbg)
    c.emu.w32(0x7003b0, cstub(c, 0))
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x512590, 'ZMoveOnSpline::ClassInit', 'thiscall', gen=g)
