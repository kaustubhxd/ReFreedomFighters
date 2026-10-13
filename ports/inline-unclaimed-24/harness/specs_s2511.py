"""specs_s2511.py - decomp area 24, batch 2511.
0x4fca70 (GUESS CMAINCAMERACONTROL free-camera key movement): thiscall, no args, plain ret. System object (0x70039c) slot 0xd4 is a
key-down query (recorder, thiscall, 1 arg, deterministic per key from a random key map); +0x20 is the frame time. this+8 is a pose object
(matrix in +0..0x23, position in +0x24..0x2c; read by the exe's own 0x4db500 / 0x4db2a0 / 0x4419f0 / 0x441940 / 0x4e0be0 / 0x4e0d00).
this->vtable slot 0x74 (matrix, position) is a recorder that records the 9 + 3 dwords they point to. Ramp globals 0x700e38/3c are random."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _f(r, lo=-3.0, hi=3.0):
    k = r.random()
    if k < 0.05:
        return 0
    if k < 0.08:
        return 0x7fc00000
    if k < 0.10:
        return 0x80000000
    return struct.unpack('<I', struct.pack('<f', r.uniform(lo, hi)))[0]


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = r.choice([0.1, 0.3, 0.5, 0.8])
    keys = {k: (r.random() < p) for k in (0x10, 0x11, 0x12, 0x25, 0x26, 0x27, 0x28)}
    if r.random() < 0.15:
        keys = {k: False for k in keys}
    elif r.random() < 0.35:
        keys[0x12] = False
        keys[0x11] = False
        keys[0x10] = False
    key = pystub(c, 1, this=True, ret=lambda em, n: 1 if keys.get(em.arg32(0), False) else 0)
    so = sysobj(c, slots={0xd4: key})
    e.w32(so + 0x20, _f(r, -0.2, 0.7))
    e.w32(0x700e38, _f(r, -1.0, 3.0))
    e.w32(0x700e3c, _f(r, -1.0, 3.0))
    pose = rnd(c, 0x40)
    for i in range(12):
        e.w32(pose + 4 * i, _f(r, -2.0, 2.0))
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x74, pystub(c, 2, this=True, deref={0: 9, 1: 3}))
    me = rnd(c, 0x40)
    e.w32(me, vt)
    e.w32(me + 8, pose)
    return [me]


S(0x4fca70, 'GUESS free-camera key movement', 'thiscall', None, ret=None, gen=_gen, note='batch2511')
