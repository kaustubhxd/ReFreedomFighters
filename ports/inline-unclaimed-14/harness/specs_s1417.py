"""specs_s1417.py - unclaimed-14 batch 17 (residue 13): FUN_5c1910 (0x5c1910, GUESS name; thiscall, no arguments, plain ret).

Engine objects are stubs (helper_stubs.stub, checksums; each returns a fixed value per case):
  B = global(0x70039c)+0x9b with B+0xadc = O: O.vt[+0x25c] returns R (zero in half the cases), O.vt[+0x294] returns R2;
  B.vt[+0x138] returns S; B.vt[+0x4c] returns Y; S.vt[+0x60] records its arguments.
  K = global(0x70038c): K.vt[+0x20] returns v (zero in half); K+8 is a stub (called when K+0xc <= this < K+0x10);
  K.vt[+0xac] records its argument.
  X = this+0xe0 (R or R2): X.vt[+0x21c] records its argument.
  T = global(0x7003b8)+0x2c15: byte +0x103f random.
  P = this+0x44: P.vt[+0x1e0] returns a random eax (al is used), P.vt[+0x20] returns a random eax, P.vt[+0x3c] records.
  0x5c1aa0 (the loop helper) is a checksum stub too (GUESS; its effects are not modelled).
Memory before this (this-4) is random; it is zero in half the cases. Faulting cases must be 0."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x1000, 4)
    for off, (nargs, ret, cleanup) in slots.items():
        s, _, _ = hs.stub(c, nargs, ecx=True, edx=False, ret=ret, cleanup=cleanup)
        c.emu.w32(vt + off, s)
    return vt


def _init(c):
    # this, with 4 bytes before it (this-4 is read)
    base = c.emu.alloc(0x900, 16)
    c.emu.wbytes(base, bytes(c.rng.getrandbits(8) for _ in range(0x900)))
    self_ = base + 0x10
    c.emu.w32(self_ - 4, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    c.emu.wbytes(self_ + 0x10c, bytes([0 if c.rng.random() < 0.5 else c.rng.getrandbits(8) | 1]))
    # this+0x44 = P
    vt_p = _vt(c, {0x1e0: (1, c.rng.getrandbits(32), True), 0x20: (0, c.rng.getrandbits(32), True),
                   0x3c: (1, 0, True)})
    p = _rnd(c, 0x200)
    c.emu.w32(p, vt_p)
    c.emu.w32(self_ + 0x44, p)
    # X objects (R and R2) have vt +0x21c
    vt_x = _vt(c, {0x21c: (1, 0, True)})
    r = _rnd(c, 0x80)
    c.emu.w32(r, vt_x)
    r2 = _rnd(c, 0x80)
    c.emu.w32(r2, vt_x)
    # global 0x70039c -> B = G+0x9b; B+0xadc = O
    s_obj = _rnd(c, 0x80)
    vt_s = _vt(c, {0x60: (2, 0, True)})
    c.emu.w32(s_obj, vt_s)
    y = c.rng.getrandbits(32)
    vt_b = _vt(c, {0x138: (0, s_obj, True), 0x4c: (2, y, True)})
    b = _rnd(c, 0x1000)
    c.emu.w32(b, vt_b)
    rr = 0 if c.rng.random() < 0.5 else r
    vt_o = _vt(c, {0x25c: (2, rr, True), 0x294: (4, r2, True)})
    o = _rnd(c, 0x200)
    c.emu.w32(o, vt_o)
    c.emu.w32(b + 0xadc, o)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)
    # global 0x70038c -> K
    k_k8 = hs.stub(c, 0, ecx=True, edx=False, ret=c.rng.getrandbits(32))[0]
    vt_k = _vt(c, {0x20: (1, c.rng.choice([0, c.rng.getrandbits(32)]), True), 0xac: (1, 0, True)})
    k = _rnd(c, 0x200)
    c.emu.w32(k, vt_k)
    c.emu.w32(k + 8, k_k8 if c.rng.random() < 0.8 else 0)
    c.emu.w32(k + 0xc, 0 if c.rng.random() < 0.7 else 0xffffffff)
    c.emu.w32(k + 0x10, 0xffffffff if c.rng.random() < 0.7 else 0)
    c.emu.w32(0x70038c, k)
    # global 0x7003b8 -> T; T+0x2c15 = obj with byte +0x103f
    tbase = _rnd(c, 0x2c20)
    tobj = _rnd(c, 0x1100)
    c.emu.wbytes(tobj + 0x103f, bytes([c.rng.choice([0, 1, 2])]))
    c.emu.w32(tbase + 0x2c15, tobj)
    c.emu.w32(0x7003b8, tbase)
    # the loop helper 0x5c1aa0 (checksum stub)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False)
    ss.patch(c, 0x5c1aa0, s)
    return [self_]


S(0x5c1910, 'FUN_5c1910 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-14 batch 17 (residue 13); engine objects are checksum stubs; 0x5c1aa0 is a stub (GUESS)')
