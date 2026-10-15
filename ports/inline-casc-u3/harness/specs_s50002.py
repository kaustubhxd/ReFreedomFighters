"""specs_s50002.py - u3 (Sonnet) batch 50002, tier H. 0x487230: this[0xc] slot 0x10 gives the actor (sometimes null); actor slot 0x2d0 and this[8] slots 0x470 / 0x244 / 0x458 are recorders
(0x244 gets (obj, float, 1.0f, 0, 1): the float is compared as bits); 0x486e90 and 0x4873f0 hooked; engine object fields +0x40 (int ms) and +0x48 (float) set; time fields
this[0x30], [0x34], [0x38], [0x3c] built around the current time so every branch (step == 0, step > t, bool true / false, early outs) runs."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g487230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    so = e.r32(0x70039c)
    ms = r.choice([0, 1, 1024, 2048, r.randrange(0, 20000), r.randrange(0, 2 ** 31), 0x80000000, 0xffffffff])
    e.w32(so + 0x40, ms)
    e.wbytes(so + 0x48, _fb(r.uniform(0, 0.5)))
    t = (ms - (1 << 32) if ms >= 1 << 31 else ms) * (1.0 / 1024)
    t = struct.unpack('<f', _fb(t))[0]
    hook_rec(c, 0x486e90, 2, this=True, pop=8, ret=r.getrandbits(32))
    hook_rec(c, 0x4873f0, 1, this=True, pop=4, ret=lambda em, k: r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(8)]))
    actor = obj(c, 0x20, {0x2d0: pystub(c, 2, this=True)}, nslots=0x2d4 // 4)
    holder = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=actor if r.random() > 0.08 else 0)}, nslots=0x14 // 4)
    outer = obj(c, 0x20, {0x470: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(8)),
                          0x244: pystub(c, 5, this=True), 0x458: pystub(c, 1, this=True)}, nslots=0x474 // 4)
    me = rnd(c, 0x50)
    e.w32(me + 8, outer)
    e.w32(me + 0xc, holder)
    rec = rnd(c, 0x80)
    n = r.choice([0, 1, 5, 25, 50, 100, -7, r.randrange(1, 1000)])
    lo = r.randrange(0, 100000)
    e.w32(rec + 0x60, lo)
    e.w32(rec + 0x64, (lo + n) & 0xffffffff)
    e.w32(me + 0x2c, rec if r.random() > 0.12 else 0)
    k = r.random()
    if k < 0.15:
        x30 = t + r.uniform(0.0001, 5)
    else:
        x30 = t - r.uniform(0, 3)
    if k > 0.97:
        x30 = r.choice([x for x in EDGE_F if x == x])
    m = r.random()
    if m < 0.3:
        x38 = 0.0
    elif m < 0.5:
        x38 = t + r.uniform(0.001, 3)
    elif m < 0.95:
        x38 = r.uniform(0, max(t, 0.5))
    else:
        x38 = r.choice(EDGE_F)
    x34 = r.choice([0.0, r.uniform(0, 1.5), r.uniform(0, 0.7), r.uniform(0.55, 0.65)])
    x3c = r.choice([x38 + r.uniform(0, 2), r.uniform(0, 3), x38])
    if x38 == 0.0 and r.random() < 0.3:   # out lands exactly on 1.0
        x30 = struct.unpack('<f', _fb(t - 1.0))[0]
        e.w32(rec + 0x64, (lo + 25) & 0xffffffff)
    if 0 < x38 and r.random() < 0.15:     # step equal to the current time
        x38 = t
    for off, v in ((0x30, x30), (0x34, x34), (0x38, x38), (0x3c, x3c)):
        e.wbytes(me + off, struct.pack('<f', v) if abs(v) < 3e38 or v != v else struct.pack('<f', 0.0))
    return [me]


S(0x487230, 'GUESS advance timed animation on actor', 'thiscall', None, ret='al', gen=_g487230, nan_heap=True, note='batch50002')
