"""specs_s1524.py - recruits thread batch 1524: ZFollowShape::FrameUpdate (0x4c5df0).
The shape object: target id at +0x54 (table slot 0x58 -> T or null), radius +0x48 (1..10), H float +0x50, offset dword
+0x4c, kind dword +0x62 (0..3), flags +0x58, +0x59, +0x66 (bytes), +0x67 (dword), counter +0x5a. The owner geom at
+0x44 (slots 0x7c, 0x210), T (slots 0x84, 0x210, first dword = a value written into the offset). The BasicShape at
T+0x1c runs as exe code (GetSplinePos; batch 1520 port) with a record array. this (slots 0x58, 0x68) is a recorder.
mreset runs as exe code. The engine clock is at [0x70039c]+0x40."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    now = r.randint(1000, 1 << 20)
    so = sysobj(c, table_size=0xae0)
    e.w32(so + 0x40, now)
    t = obj(c, 0x200, {0x84: pystub(c, 1, nullflag=(0,), side=lambda em, k: [em.wf32(em.arg32(0) + 4 * i, r.uniform(-200, 200)) for i in range(3)]),
                       0x210: pystub(c, 1, this=True),
                       0x1e0: pystub(c, 1, ret=0)})
    # BasicShape at T+0x1c: n at +0x10, records at +0xc
    n = r.randint(1, 4)
    recs = c.emu.alloc(56 * n + 16, 16)
    for i in range(56 * n // 4):
        e.wf32(recs + 4 * i, r.uniform(-50, 50))
    e.w32(t + 0x1c + 0xc, recs)
    e.w32(t + 0x1c + 0x10, n)
    owner = obj(c, 0x60, {0x7c: pystub(c, 2, deref={0: 12, 1: 3}), 0x210: pystub(c, 1, this=True)})
    this = obj(c, 0x100, {0x58: pystub(c, 0, this=True), 0x68: pystub(c, 2, this=True)})
    tgt_null = r.random() < 0.1
    e.w32(this + 0x44, owner)
    e.w32(this + 0x54, r.getrandbits(32))
    e.wf32(this + 0x48, r.uniform(1.0, 60.0))
    e.wf32(this + 0x50, r.uniform(0.0, 3.0))
    e.w32(this + 0x4c, r.randint(0, now))
    e.w32(this + 0x62, r.choice([0, 1, 2, 3]))
    e.w8(this + 0x58, r.randint(0, 1))
    e.w8(this + 0x59, r.randint(0, 1))
    e.w8(this + 0x66, r.randint(0, 1))
    e.w32(this + 0x67, r.choice([0, 1, 2]))
    e.w32(this + 0x5a, r.randint(0, 3))
    e.w32(this + 0x5e, r.randint(0, 2))
    # the target's first dword is its vtable pointer; the original copies it into the offset (kept as is)
    # table: id -> T (or null)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=0 if tgt_null else t)})
    e.w32(so + 0x9b, tbl)
    return [this]


S(0x4c5df0, 'ZFollowShape::FrameUpdate', 'thiscall', gen=_gen, note='batch1524', max_insns=400000)
