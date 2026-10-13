"""specs_s6508.py - unclaimed-65 batch 8 (docs/20-unclaimed-65.md, claim 8): ZPlayer::CallBackAimInPosition. This is a call-recording
vtable model: the player (this) has logging slots (+0x518 and +0x51c with one argument, +0x12c with three, which pop their own
arguments); its +0x50c and +0x508 return objects B and S (zero in 25% each); B and S's slot +0x350 return X and Y, whose slot +0x330
return b1 and b2 (per-case values, 0, 1 or random). The render object (global 0x70039c, +0x9b) has slot +0x138 returning Z; Z's slot
+0x88 writes a per-case value through its out pointer; slot +0x114 (four arguments, popped by the callee) returns a per-case word.
this+0x61a is an object whose slot +0x14 returns 0 or 1, slot +0x34 returns a value, slot +0x20 logs. No exe function is patched."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _small(c):
    r = c.rng.random()
    return 0 if r < 0.3 else (1 if r < 0.6 else c.rng.getrandbits(32))


def _gen(c):
    b1 = _small(c)
    b2 = _small(c)
    tmpval = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    word = c.rng.getrandbits(32)
    c14 = 1 if c.rng.random() < 0.5 else 0
    r34 = c.rng.getrandbits(32)

    # X and Y: slot +0x330 returns b1 / b2 (no args)
    x_vt = c.emu.logging_vtable('aim-x', 0x340, impl={0x330: lambda e, a: (b1, None)}, argwords={0x330: 0})
    X = _rnd(c, 0x40); c.emu.w32(X, x_vt)
    y_vt = c.emu.logging_vtable('aim-y', 0x340, impl={0x330: lambda e, a: (b2, None)}, argwords={0x330: 0})
    Y = _rnd(c, 0x40); c.emu.w32(Y, y_vt)
    # B and S: slot +0x350 returns X / Y
    b_vt = c.emu.logging_vtable('aim-b', 0x360, impl={0x350: lambda e, a: (X, None)}, argwords={0x350: 0})
    B = _rnd(c, 0x40); c.emu.w32(B, b_vt)
    s_vt = c.emu.logging_vtable('aim-s', 0x360, impl={0x350: lambda e, a: (Y, None)}, argwords={0x350: 0})
    S_obj = _rnd(c, 0x40); c.emu.w32(S_obj, s_vt)

    # Z: slot +0x88 writes tmpval through arg1 (the out pointer); R: slot +0x138 returns Z, slot +0x114 returns word
    def slot88(e, r_):
        ptr = e.arg32(1)
        e.calllog.append(('aim-z-88', e.reg('ecx'), (e.arg32(0),)))
        e.w32(ptr, tmpval)
        e.ret(eax=0, argbytes=8)
    z_vt = c.emu.fake_vtable('aim-z', 0x90, {0x88: slot88})
    Z = _rnd(c, 0x40); c.emu.w32(Z, z_vt)
    r_vt = c.emu.logging_vtable('aim-render', 0x140, impl={0x138: lambda e, a: (Z, None), 0x114: lambda e, a: (word, None)},
                                argwords={0x138: 0, 0x114: 4})
    R = _rnd(c, 0x40); c.emu.w32(R, r_vt)
    rr = _rnd(c, 0x200)
    c.emu.w32(rr + 0x9b, R)
    c.emu.w32(0x70039c, rr)

    # obj at this+0x61a: slot +0x14 (c), +0x34 (value), +0x20 (logs one argument)
    o_vt = c.emu.logging_vtable('aim-o2', 0x40, impl={0x14: lambda e, a: (c14, None), 0x34: lambda e, a: (r34, None)},
                                argwords={0x14: 0, 0x34: 1, 0x20: 1})
    o2 = _rnd(c, 0x40); c.emu.w32(o2, o_vt)

    # this (the player): slot +0x508 returns S (or 0), +0x50c returns B (or 0); +0x518, +0x51c, +0x12c log their arguments
    b_ret = 0 if c.rng.random() < 0.25 else B
    s_ret = 0 if c.rng.random() < 0.25 else S_obj
    self_vt = c.emu.logging_vtable('aim-player', 0x540,
                                   impl={0x50c: lambda e, a: (b_ret, None), 0x508: lambda e, a: (s_ret, None)},
                                   argwords={0x518: 1, 0x51c: 1, 0x12c: 3, 0x50c: 0, 0x508: 0})
    self_ = _rnd(c, 0x800)
    c.emu.w32(self_, self_vt)
    c.emu.w32(self_ + 0x61a, o2)
    return [self_]


S(0x4816e0, 'ZPlayer::CallBackAimInPosition (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-65 batch 8 (residue 18); call-recording vtable model; leftover push feeds the 0x12c call')
