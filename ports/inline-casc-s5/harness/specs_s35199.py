"""specs_s35199.py - 0x4b7240 (thiscall(a, unused) ret 8, ret=None, nan_heap). this: 0x1a0 random bytes with bytes +0x180 / +0x181 (0 / 1), dwords +0x50 (non-zero), +0x54 (0, 1 or 2), +0x58, +0x5c (float bits), +0x60; vtable slots 0x64 (1 arg), 0x9c (0 args) and 0x94 (2 args; first call returns R, later calls R2 or 0).
Engine: dword +0x40 random, unaligned +0x1a9f = O (null in 1/6; slot 0x70 1 arg, al true in 3/4), table slots 0x58 (1 arg; null in 1/8), 0x60 (1 arg; returns a 0x100-byte block or 0 in 1/6). R: [+0x54] = X (null in 1/5; slots 0x1e0 al true in 3/4 and 0x3f8 1 arg). R2: block with [+0x50] pointing to a getter object (0x4dc130 runs for real). Hooks: 0x467260 (3 args), 0x43ec00 (6 args), 0x441890 (float arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g4b7240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    X = 0 if r.random() < 1 / 5 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=((r.getrandbits(24) << 8) | 1) if r.random() < 0.75 else (r.getrandbits(24) << 8)),
                                                  0x3f8: pystub(c, 1, this=True)}, nslots=0x100)
    R = rnd(c, 0x80)
    e.w32(R + 0x54, X)
    R2 = 0 if r.random() < 1 / 5 else rnd(c, 0x80)
    if R2:
        g = rnd(c, 0x80)
        e.w32(g + 0x54, rnd(c, 0x20))
        e.w32(R2 + 0x50, g if r.random() < 0.7 else 0)
    seq = [R, R2]
    me = obj(c, 0x1a0, {0x64: pystub(c, 1, this=True), 0x9c: pystub(c, 0, this=True), 0x94: pystub(c, 2, this=True, ret=lambda em, k: seq[min(k, 1)])}, nslots=0x68)
    e.w8(me + 0x180, r.choice([0, 1, 1]))
    e.w8(me + 0x181, r.choice([0, 1, 1]))
    e.w32(me + 0x50, r.getrandbits(32) | 1)   # never zero: the original dereferences the null result of the skipped slot 0x94 call
    e.w32(me + 0x54, r.choice([0, 0, 1, 1, 2]))
    e.w32(me + 0x58, r.choice([0, 1, r.getrandbits(32)]))
    e.w32(me + 0x5c, r.choice([0x3f800000, 0x40000000, 0, r.getrandbits(32) & 0x7f7fffff]))
    e.w32(me + 0x60, r.getrandbits(32))
    ent = 0 if r.random() < 1 / 6 else rnd(c, 0x100)
    O = obj(c, 0x20, {0x70: pystub(c, 1, this=True, ret=((r.getrandbits(24) << 8) | 1) if r.random() < 0.75 else (r.getrandbits(24) << 8))}, nslots=0x20)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=0 if r.random() < 1 / 8 else rnd(c, 0x10)), 0x60: pystub(c, 1, this=True, ret=ent)}, table_size=0x70)
    e.w32(so + 0x40, r.getrandbits(32))
    e.wbytes(so + 0x1a9f, (0 if r.random() < 1 / 6 else O).to_bytes(4, 'little'))
    hook_rec(c, 0x467260, 3, this=True, pop=12, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x43ec00, 6, this=True, pop=24, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x441890, 1, this=True, pop=4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x4b7240, 'GUESS update HUD entry and show or hide its linked object', 'thiscall', None, ret=None, gen=_g4b7240, nan_heap=True, note='batch35199')
