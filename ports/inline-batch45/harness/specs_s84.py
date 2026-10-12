"""specs_s84.py - inline session batch 84 (2026-10-12, docs/41): ZFFHeroMovementCloseCombat::FrameUpdate (0x5e2020) with its
vector helpers as exe code (d = a - b 0x43e920, vneg(dst, src) 0x4e09e0, createmat 0x4de040). Built on the area 81 spec
(inline-unclaimed-81 specs_s1021.py) with these changes: the three helpers are no longer patched, the character's slot 0x578
and its object's slot 0x7c record the 3x3 frame and the position they get, the event's argument block is recorded by
contents, and the stored direction +0x5c6 is a unit vector half the time. The CRT sqrt 0x634d7c is still patched with
sqrtsd (the CRT, not game code)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
_u81 = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'inline-unclaimed-81', 'harness')
if _u81 not in sys.path:
    sys.path.append(_u81)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf
from specs_s82 import _rec


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals) + 4, 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


def ff(c, vals):
    return fill(c, [struct.unpack('<I', struct.pack('<f', v))[0] for v in vals])


def g(c):
    rnd = c.rng
    sq = c.emu.alloc(16, 16)
    c.emu.wbytes(sq, b'\xf2\x0f\x51\xc0\xc3')           # sqrtsd xmm0,xmm0; ret
    ss.patch(c, 0x634d7c, sq)
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    # target R (slot 0x80: matrix row B and position A) and hero H (slot 0x80: D and position C), near each other
    tgt = [rnd.uniform(-300, 300) for _ in range(3)]
    hp = [tgt[j] + rnd.choice((rnd.uniform(-200, 200), rnd.uniform(-60, 60))) for j in range(3)]
    if rnd.random() < 0.05:
        hp = list(tgt)
    srcB = ff(c, [rnd.uniform(-1, 1) for _ in range(3)])
    srcA = ff(c, tgt + [0.0])
    srcD = ff(c, [rnd.uniform(-1, 1) for _ in range(3)])
    srcC = ff(c, hp)
    O = obj(c, 0x40, {0x7c: _rec(c, 2, skip=(0, 1), copies=((0, 9), (1, 3)))})
    K_hook = obj(c, 0x40)
    kr = rnd.random()
    c.emu.w32(K_hook + 0x23, 0x2007f9 if kr < 0.4 else (0x2003e8 if kr < 0.8 else r32(c)))
    R = obj(c, 0x810, {0x80: _stub(c, 2, skip=(0, 1), ofills=((0, 0, srcB, 3), (1, 0, srcA, 3))),
                       0x578: _rec(c, 2, skip=(0, 1), copies=((0, 9), (1, 3))),
                       0x20: _stub(c, 0, ret=O),
                       0x674: ss.seqr(c, 0, [rnd.randint(-100, 100) & 0xffffffff, rnd.randint(-100, 100) & 0xffffffff]),
                       0x128: _stub(c, 1)})
    c.emu.w32(R + 0xc, K_hook)
    c.emu.w32(R + 0x7ff, rf(c, -200, 200))
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=R if rnd.random() < 0.85 else 0),
                       0x4c: _stub(c, 1, ret=r32(c)),
                       0x114: _rec(c, 6, rets=(r32(c),), skip=(4,), copies=((4, 11),))})
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
    c.emu.wbytes(self_ + 0x5b5, bytes([1 if rnd.random() < 0.1 else 0]))
    c.emu.w32(self_ + 0x5ad, rf(c, -2, 2))
    c.emu.w32(self_ + 0x59c, rf(c, -2, 2))
    c.emu.w32(self_ + 0x5a0, rf(c, -2, 2))
    c.emu.w32(self_ + 0x5b6, r32(c))
    c.emu.w32(self_ + 0x5a8, r32(c))
    c.emu.w32(self_ + 0x5a4, rf(c, -3, 3))
    for k in range(3):
        c.emu.wf32(self_ + 0x5ba + 4 * k, tgt[k] + rnd.uniform(-5, 5))
    d = [rnd.uniform(-1, 1) for _ in range(3)]
    if rnd.random() < 0.5:
        n = sum(x * x for x in d) ** 0.5 or 1.0
        d = [x / n for x in d]
    for k in range(3):
        c.emu.wf32(self_ + 0x5c6 + 4 * k, d[k])
    c.emu.wbytes(self_ + 0x610, bytes([0]))
    c.emu.wbytes(self_ + 0x5ac, bytes([rnd.randint(0, 1)]))
    return [self_]


S(0x5e2020, 'ZFFHeroMovementCloseCombat::FrameUpdate (batch84, helpers as exe code)', 'thiscall', None, gen=g,
  note='batch84; wrench tree; 0x43e920, 0x4e09e0, 0x4de040 as exe code; sqrt patched to sqrtsd')
