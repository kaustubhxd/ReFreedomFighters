"""specs_s300.py - unclaimed-43 batch 300: ZLNKOBJ::GetDefaultBones(ZBone *out) const (0x4630e0), thiscall, ret 4.
The object is a logging vtable (slots 0x2b4, 0x2c8, 0x2cc) with a skeleton block at +0x1c and a bone count at +0x20.
Counts cover the early return (1) and the loop (2..12); the parent table and the offset table are random blocks with
valid parent indices, so the matrix products run on real data. The bone index n (slot 0x2b4) is random in range."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E

COUNTS = [1, 1, 2, 2, 3, 4, 5, 8, 12]
NSLOTS = 0x2d0 // 4          # slots up to 0x2cc


def _gen(c):
    r = c.rng
    count = r.choice(COUNTS)
    skel = c.bytes_(0x18 * count + 0x40)
    n = r.randrange(count)
    r1 = c.bytes_(0x30 * count + 0x40)
    for i in range(1, count):
        c.emu.w32(r1 + 0xc + 0x30 * i, r.randrange(count))
    r2 = c.fbuf(12 * count + 12)
    out = c.bytes_(0x30 * count + 0x40)
    impl = {
        0x2b4: lambda e, a: (n, None),
        0x2cc: lambda e, a: (r1, None),
        0x2c8: lambda e, a: (r2, None),
    }
    o = E.logged_obj(c, 'ZLNKOBJ', NSLOTS, impl=impl, argwords={0x2b4: 1})
    c.emu.w32(o + 0x1c, skel)
    c.emu.w32(o + 0x20, count)
    c.emu.mu.ctl_flush_tb()
    return [o, out]


S(0x4630e0, 'ZLNKOBJ::GetDefaultBones(ZBone*) const', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 300; mreset, quattomat, matrix product, vmmul, PSVECAdd are original exe code')
