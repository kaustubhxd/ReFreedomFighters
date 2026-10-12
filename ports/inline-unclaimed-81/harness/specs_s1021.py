"""specs_s1021.py - area 81, batch 1021: ZFFHeroMovementCloseCombat::FrameUpdate (0x5e2020). The CRT sqrt at 0x634d7c is hooked by a sqrtsd stub (exe side;
the port uses __builtin_sqrt). The fastcall helper 0x43e920 writes a random vector to its ecx. The helpers 0x4e09e0 and 0x4de040 are counting stubs. The
render manager (sys+0x9b): slot 0x58 returns R (or null), slot 0x4c returns a random word, slot 0x114 (six arguments, the fifth a stack address) returns a
word. R: slot 0x80 writes the two out vectors (stack addresses, from random source vectors), slot 0x578 and slot 0x7c (O, returned by R's slot 0x20) are
counting stubs, slot 0x674 returns two different random ints in turn (so T1 and T2 can differ), slot 0x128 counts; R+0xc points to a kind object whose dword at +0x23 selects the hook or the 0x2007f9 path;
R+0x7ff is a random float. The hero object H (this+0x36d) has slot 0x80 (writes two vectors) and is passed to rm's slot 0x4c. The debug object (0x700390)
returns a channel whose slot 0x2c is a cdecl stub taking a double. The hook global 0x7003b0 is a counting stub."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf


def fast_vec_stub(c, src):
    code = b''
    for j in range(3):
        code += b'\x8b\x05' + struct.pack('<I', src + 4 * j) + b'\x89\x41' + bytes([4 * j])
    code += b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals), 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


def g(c):
    rnd = c.rng
    sq = c.emu.alloc(16, 16)
    c.emu.wbytes(sq, b'\xf2\x0f\x51\xc0\xc3')           # sqrtsd xmm0,xmm0; ret
    ss.patch(c, 0x634d7c, sq)
    ss.patch(c, 0x43e920, fast_vec_stub(c, fill(c, [rf(c, -200, 200) for _ in range(3)])))
    ss.patch(c, 0x4e09e0, ss.rec(c, 0))
    ss.patch(c, 0x4de040, ss.rec(c, 1))
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    srcB = fill(c, [rf(c, -3, 3) for _ in range(3)])
    srcA = fill(c, [rf(c, -3, 3) for _ in range(4)])
    srcD = fill(c, [rf(c, -3, 3) for _ in range(3)])
    srcC = fill(c, [rf(c, -3, 3) for _ in range(3)])
    O = obj(c, 0x40, {0x7c: _stub(c, 2, skip=(0, 1))})
    K_hook = obj(c, 0x40)
    kr = rnd.random()
    c.emu.w32(K_hook + 0x23, 0x2007f9 if kr < 0.2 else (0x2003e8 if kr < 0.4 else r32(c)))
    R = obj(c, 0x810, {0x80: _stub(c, 2, skip=(0, 1), ofills=((0, 0, srcB, 3), (1, 0, srcA, 3))),
                       0x578: _stub(c, 2, skip=(0, 1)),
                       0x20: _stub(c, 0, ret=O),
                       0x674: ss.seqr(c, 0, [rnd.randint(-100, 100) & 0xffffffff, rnd.randint(-100, 100) & 0xffffffff]),
                       0x128: _stub(c, 1)})
    c.emu.w32(R + 0xc, K_hook)
    c.emu.w32(R + 0x7ff, rf(c, -200, 200))
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=R if rnd.random() < 0.8 else 0),
                       0x4c: _stub(c, 1, ret=r32(c)),
                       0x114: _stub(c, 6, skip=(4,), ret=r32(c))})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(0, 6000))
    c.emu.w32(sysobj + 0x9b, rm)
    H = obj(c, 0x40, {0x80: _stub(c, 2, skip=(0, 1), ofills=((0, 0, srcD, 3), (1, 0, srcC, 3)))})
    dbgchan = obj(c, 0x40, {0x2c: cstub(c, 4)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgchan)})
    c.emu.w32(0x700390, dbg)
    self_ = obj(c, 0x700, {})
    c.emu.w32(self_ + 0x36d, H)
    c.emu.wbytes(self_ + 0x5b5, bytes([1 if rnd.random() < 0.15 else 0]))
    c.emu.w32(self_ + 0x5ad, rf(c, -2, 2))
    c.emu.w32(self_ + 0x59c, rf(c, -2, 2))
    c.emu.w32(self_ + 0x5a0, rf(c, -2, 2))
    c.emu.w32(self_ + 0x5b6, r32(c))
    c.emu.w32(self_ + 0x5a8, r32(c))
    c.emu.w32(self_ + 0x5a4, rf(c, -3, 3))
    c.emu.w32(self_ + 0x5ba, rf(c, -3, 3))
    c.emu.w32(self_ + 0x5be, rf(c, -3, 3))
    c.emu.w32(self_ + 0x5c2, rf(c, -3, 3))
    for k in range(3):
        c.emu.w32(self_ + 0x5c6 + 4 * k, rf(c, -1, 1))
    c.emu.wbytes(self_ + 0x610, bytes([0]))
    c.emu.wbytes(self_ + 0x5ac, bytes([rnd.randint(0, 1)]))
    return [self_]


S(0x5e2020, 'ZFFHeroMovementCloseCombat::FrameUpdate', 'thiscall', gen=g)
