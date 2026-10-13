"""specs_s1005.py - area 81 (residue 0), batch 1005: ZKillBox::RemoveWeapons (0x5b1f80). The render manager's slot 0x58 returns an object o whose
slot 0x80 writes nothing (its two out-pointers are stack addresses, skipped). The helper 0x4db7c0 is a counting stub that ignores its argument.
The rm2 object's slot 0x38 (ten stack arguments) fills the caller's array with zero to three element pointers and returns their count. Each
element's +0x54 object returns one of three shared objects; those have slot 0x1e0 (returns a bool), 0x2f4 (returns a bool) and 0x320 (void).
The byte at +0x8c is set in most cases so the body runs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    ss.patch(c, 0x4db7c0, ss.rec(c, 1, log=False))
    o1s = [obj(c, 0x40, {0x1e0: _stub(c, 1, ret=c.rng.choice([0, 1])),
                         0x2f4: _stub(c, 0, ret=c.rng.choice([0, 1])),
                         0x320: _stub(c, 0)}) for _ in range(3)]
    n = c.rng.randint(0, 3)
    els = []
    for _ in range(n):
        cc = obj(c, 0x40, {0x20: _stub(c, 0, ret=c.rng.choice(o1s))})
        e = obj(c, 0x80)
        c.emu.w32(e + 0x54, cc)
        els.append(e)
    src = c.emu.alloc(4 * (n + 1), 4)
    for i, e in enumerate(els):
        c.emu.w32(src + 4 * i, e)
    ob = obj(c, 0x40, {0x38: _stub(c, 10, skip=(0, 1, 3, 4, 5), ret=n, ofills=((0, 0, src, n),))})
    rm2 = obj(c, 0x40)
    c.emu.w32(rm2 + 0x1c, ob)
    o = obj(c, 0x40, {0x80: _stub(c, 2, skip=(0, 1))})
    c.emu.w32(o + 8, obj(c, 0x40))
    rm1 = obj(c, 0x40, {0x58: _stub(c, 1, ret=o)})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm1)
    c.emu.w32(sysobj + 0x1aa3, rm2)
    self_ = obj(c, 0x100)
    c.emu.wbytes(self_ + 0x8c, bytes([1 if c.rng.random() < 0.85 else 0]))
    c.emu.w32(self_ + 0x4e, r32(c))
    return [self_]


S(0x5b1f80, 'ZKillBox::RemoveWeapons', 'thiscall', gen=g)
