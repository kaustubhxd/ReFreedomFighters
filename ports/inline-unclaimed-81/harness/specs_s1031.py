"""specs_s1031.py - area 81, batch 1031: 0x5022e0 (thiscall: this; P). The helper 0x5003d0 is the real exe code (not patched). P+4 is a table object T whose +0 is a
record table S and whose +4 is a base offset (0..3); S+0 is the record array and S+8 its limit (256). Records are 8 bytes: dword 0 is a value (kind 3), an
object with slot 0x34 (kind 4, returning a random value), or any other word (kind 5: the debug print and the hook path); byte +4 is the kind. The render
manager's slot 0x114 returns a random word (four arguments). The object at this+0xc has slot 0x12c (three arguments; counting). The debug object's slot 0x20
gives a channel whose slot 0x2c is a three-argument cdecl stub; the hook global 0x7003b0 is a counting stub."""
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
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    arr = c.emu.alloc(8 * 16, 8)
    for e in range(8):
        kind = rnd.choice([3, 3, 4, 4, 5])
        Z = obj(c, 0x40, {0x34: _stub(c, 0, ret=r32(c))})
        dword = Z if kind == 4 else r32(c)
        c.emu.w32(arr + 8 * e, dword)
        c.emu.wbytes(arr + 8 * e + 4, bytes([kind]))
    Sobj = obj(c, 0x40)
    c.emu.w32(Sobj + 0, arr)
    c.emu.w32(Sobj + 8, 256)
    T = obj(c, 0x40)
    c.emu.w32(T + 0, Sobj)
    c.emu.w32(T + 4, rnd.randint(0, 3))
    c.emu.w32(T + 8, 256)
    P = obj(c, 0x40)
    c.emu.w32(P + 4, T)
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    rm = obj(c, 0x40, {0x114: _stub(c, 4, ret=r32(c))})
    c.emu.w32(sysobj + 0x9b, rm)
    dbgchan = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgchan)})
    c.emu.w32(0x700390, dbg)
    K = obj(c, 0x40, {0x12c: _stub(c, 3)})
    X = obj(c, 0x40)
    c.emu.w32(X + 0xc, K)
    return [X, P]


S(0x5022e0, '0x5022e0 record chain', 'thiscall', gen=g)
