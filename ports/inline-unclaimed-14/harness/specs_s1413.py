"""specs_s1413.py - unclaimed-14 batch 13 (slice 13, heavy): ZFFActor::CloseCombatAttack (0x59e7d0, thiscall, two stack
arguments, ret 8; the result is in al).

Original code runs for 0x43e920 (vector math with x87), 0x5eb770 and 0x5eb7a0. Stubs (helper_stubs.stub) cover the vtable
slots that the function calls: this +0x20, +0x3ec, +0x3d8, +0x3f0, +0x6e8, +0x80 (writes the two vectors); the T object +0x84
(writes the third vector, small); the global+0x9b object +0x58 (returns T or 0, the zero path is about 3 cases in 10); the
global object +0x1c0; the global 0x700390 object +0x20 (returns M) and M +0x2c (its ecx is [Y+4]).

Vectors: p40 in [0.2, 1.0], p1c in [0.5, 1.0], p10 in [-0.1, 0.1], so vector 1 (p1c - p10) is positive and the dot product
is usually at least 0.5 (the threshold). this+0x7ae and +0x7b2 are nonzero about 85 cases in 100; +0x7aa is one of
0, 1, 2, 3, 4, 7, 9 (so the counter branch is exercised both ways). The x87 value that the fstp pops is the result of 43e920
as the original leaves it (the port does the same call).
Faulting cases must be 0 (check the JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _cca(c):
    # global objects: G (0x70039c), B = G+0x9b, L (0x700390), M (returned by L), Y (returned by this+0x20), T (B's +0x58)
    vt_g = c.emu.alloc(0x200, 4)
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], ret=0)
    c.emu.w32(vt_g + 0x1c0, s)
    g = _rnd(c, 0x200)
    c.emu.w32(g, vt_g)
    c.emu.w32(0x70039c, g)

    vt_b = c.emu.alloc(0x200, 4)
    t = _rnd(c, 0x100)
    vt_t = c.emu.alloc(0x100, 4)
    ww = [(1, 0, _f(c, -0.1, 0.1)), (1, 4, _f(c, -0.1, 0.1)), (1, 8, _f(c, -0.1, 0.1))]
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], writes=ww)            # T +0x84 writes the small vector
    c.emu.w32(vt_t + 0x84, s)
    c.emu.w32(t, vt_t)
    t_ret = t if c.rng.random() < 0.7 else 0
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=t_ret)           # B +0x58 (a) returns T or 0
    c.emu.w32(vt_b + 0x58, s)
    b = _rnd(c, 0x200)
    c.emu.w32(b, vt_b)
    c.emu.w32(g + 0x9b, b)

    vt_l = c.emu.alloc(0x100, 4)
    vt_m = c.emu.alloc(0x100, 4)
    m = _rnd(c, 0x40)
    c.emu.w32(m, vt_m)
    s, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=False)  # M +0x2c (ecx = [Y+4]); caller pops 12
    c.emu.w32(vt_m + 0x2c, s)
    l = _rnd(c, 0x40)
    c.emu.w32(l, vt_l)
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], ret=m)           # L +0x20 (0x6d7, 0x6ae6a0) returns M
    c.emu.w32(vt_l + 0x20, s)
    c.emu.w32(0x700390, l)

    # the object: this+0x20 returns Y (Y+4 is a heap pointer); +0x3ec returns Z; +0x3d8 returns a random eax; +0x3f0 returns
    # 0 most of the time; +0x80 writes p40 and p1c; +0x6e8 is a stub (its arguments are constants)
    y = _rnd(c, 0x40)
    c.emu.w32(y + 4, _rnd(c, 0x40))
    z = _rnd(c, 0x40)
    vt_s = c.emu.alloc(0x800, 4)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=y)
    c.emu.w32(vt_s + 0x20, s)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=0 if c.rng.random() < 0.6 else c.rng.getrandbits(32))
    c.emu.w32(vt_s + 0x3f0, s)
    s, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3])
    c.emu.w32(vt_s + 0x6e8, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=z)
    c.emu.w32(vt_s + 0x3ec, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=c.rng.getrandbits(32))
    c.emu.w32(vt_s + 0x3d8, s)
    w80 = [(1, 0, _f(c, 0.2, 1.0)), (1, 4, _f(c, 0.2, 1.0)), (1, 8, _f(c, 0.2, 1.0)),
           (2, 0, _f(c, 0.5, 1.0)), (2, 4, _f(c, 0.5, 1.0)), (2, 8, _f(c, 0.5, 1.0))]
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[], writes=w80)
    c.emu.w32(vt_s + 0x80, s)
    this = _rnd(c, 0x800)
    c.emu.w32(this, vt_s)
    c.emu.w32(this + 0x7ae, c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0)
    c.emu.w32(this + 0x7b2, c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0)
    c.emu.w32(this + 0x7aa, c.rng.choice([0, 1, 2, 3, 4, 7, 9]))

    # 0x5eb7a0 calls the hook at 0x7003b0 for any argument other than 0 or 1; the exe's initial value there is junk, so
    # the spec points it at a plain ret (both sides call the same stub; the hook is the exe's error callback).
    hook = ss.code(c, b'\xc3')
    c.emu.w32(0x7003b0, hook)

    a, bb = c.rng.getrandbits(32), c.rng.getrandbits(32)
    return [this, a, bb]


S(0x59e7d0, 'ZFFActor::CloseCombatAttack (unknown) thiscall', 'thiscall', None, ret='al', gen=_cca,
  note='unclaimed-14 batch 13; stubs on this/T/B/G/L/M vtables; 43e920, 5eb770, 5eb7a0 run as original')
