"""specs_s345.py - decomp area 64 (docs/20-unclaimed-64.md): 0x45dd30 check; logging path stubbed: logger G3 (0x700390) slot 0x20,
logger L slot 0x2c (cdecl recorder); A slots 0x1cc and 0x210; exe 0x4da440 patched to a counter stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _check(c):
    e = c.emu
    # 0x4da440 (thiscall, one word): a counter stub (so a missing or extra call shows in the compare).
    cnt = e.alloc(8, 4)
    e.wbytes(cnt, bytes(8))
    ss.patch(c, 0x4da440, ss.code(c, b'\xff\x05' + ss.P(cnt) + b'\xb8' + ss.P(0) + b'\xc2\x04\x00'))

    # Logger L: its vtable slot 0x2c is a cdecl recorder (six words copied to a heap cell; the caller pops them, so ret 0).
    rec = e.alloc(0x18, 4)
    e.wbytes(rec, bytes(0x18))
    code = b''
    for i in range(6):
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x15' + ss.P(rec + 4 * i)   # mov edx,[esp+4+4i]; mov [rec+4i], edx
    code += b'\xc3'                                                                       # ret (cdecl: caller pops)
    rec_addr = ss.code(c, code)
    L_vt = _rnd(c, 0x40)
    e.w32(L_vt + 0x2c, rec_addr)
    L = _rnd(c, 0x40)
    e.w32(L, L_vt)

    # Logger G3 at 0x700390: slot 0x20 takes two words and returns L.
    G3_vt = e.logging_vtable('g3_45dd', 0x40, argwords={0x20: 2}, impl={0x20: lambda em, a: (L, None)})
    G3 = _rnd(c, 0x40)
    e.w32(G3, G3_vt)
    e.w32(0x700390, G3)

    # A: slots 0x1cc and 0x210 take one word and return 0.
    A_vt = e.logging_vtable('A45dd', 0x220, argwords={0x1cc: 1, 0x210: 1})
    A = _rnd(c, 0x40)
    e.w32(A, A_vt)
    Q = _rnd(c, 0x40)
    e.w32(A + 0xc, Q)
    e.w32(A + 0x4, c.rng.getrandbits(32) if c.rng.random() < 0.7 else 0)
    e.w32(A + 0x8, _rnd(c, 0x40))

    # self: P at +0xc (the flag test reads P[+0x23] and Q[+0x23]); the string at +4 and an object at +8.
    P = _rnd(c, 0x40)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0xc, P)
    e.w32(self_ + 0x4, c.rng.getrandbits(32) if c.rng.random() < 0.7 else 0)
    e.w32(self_ + 0x8, c.rng.getrandbits(32))
    # Make the test come out both ways: when the bits are equal, x = 0 (the non-logging path).
    pw = c.rng.getrandbits(32)
    e.w32(P + 0x23, pw)
    qw = pw if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    e.w32(Q + 0x23, qw)

    B = c.rng.getrandbits(32) if c.rng.random() < 0.7 else 0
    return [self_, A, B]


S(0x45dd30, 'check (GUESS)', 'thiscall', None, ret='al', gen=_check,
  note='batch345; two stack words A and B; ret 8; logging path (0x700390 slots 0x20, L slot 0x2c) stubbed; exe 0x4da440 stubbed')
