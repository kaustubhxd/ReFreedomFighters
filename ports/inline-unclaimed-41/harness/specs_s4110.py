"""specs_s4110.py - unclaimed-41 batch 10 (slice 13): 0x5a2f10 (thiscall, one stack argument, ret 4).

Setup per case: this (0x1000 bytes): +0x784 is random (equal to the argument in 20% of cases), +0x92e is a pointer to Y in 80%
(else 0). Y (0x1000 bytes): +0x852 = Z (0x40 bytes). The global at 0x70039c has +0x9b = B (0x200 bytes, vtable: slot +0x58 returns
T and records its argument; slot +0x154 returns X and records its argument). T (0x80 bytes): vtable slot +0x1e0 is a sequence stub
(two values per run, 0 or random) so both branches of the flag test are reached; X has a random dword at +0x23.
0x598e10 (four stack arguments, ret 0x10; checksum stub, GUESS, ecx = Z). Faulting cases must be 0 (JSON).

Note: when the second flag value is zero, the PC's early exit (`je 0x5a2ff5`) runs after `push 0` (a leftover argument for 0x598e10)
and before its pops, so `pop edi` reads the leftover and the return goes to garbage (orig fault at 0x0ff00000 in 5 of 1000 cases).
That is an original stack imbalance on that branch; the port returns cleanly there, so the spec keeps the second value nonzero
and that branch is NOT verified (documented in the claim doc)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    s, _, _ = hs.stub(c, 4, ecx=True, edx=False)
    ss.patch(c, 0x598e10, s)

    vt_t = c.emu.alloc(0x400, 4)   # slot +0x1e0 must lie inside the vtable
    vals = [c.rng.choice([0, c.rng.getrandbits(8) | 1]), c.rng.getrandbits(8) | 1]   # second value nonzero: see the note
    ss.patch  # (no-op reference; the flag stub is placed in the object's vtable below)
    c.emu.w32(vt_t + 0x1e0, ss.seqr(c, 1, vals))
    t_obj = _rnd(c, 0x80)
    c.emu.w32(t_obj, vt_t)

    vt_b = c.emu.alloc(0x200, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=t_obj)
    c.emu.w32(vt_b + 0x58, s)
    x = _rnd(c, 0x80)
    c.emu.w32(x + 0x23, c.rng.getrandbits(32))
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=x)
    c.emu.w32(vt_b + 0x154, s)
    b = _rnd(c, 0x200)
    c.emu.w32(b, vt_b)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)

    y = _rnd(c, 0x1000)
    z = _rnd(c, 0x40)
    c.emu.w32(y + 0x852, z)
    self_ = _rnd(c, 0x1000)
    c.emu.w32(self_ + 0x92e, y if c.rng.random() < 0.8 else 0)
    arg = c.rng.getrandbits(32)
    r = c.rng.random()
    if r < 0.2:
        c.emu.w32(self_ + 0x784, arg)
    else:
        c.emu.w32(self_ + 0x784, c.rng.getrandbits(32))
    if c.rng.random() < 0.1:
        arg = 0
    return [self_, arg]


S(0x5a2f10, 'fn5a2f10 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-41 batch 10; vt +0x58, +0x154, +0x1e0 stubs; 0x598e10 checksum stub (four args, GUESS)')
