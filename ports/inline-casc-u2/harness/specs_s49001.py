"""specs_s49001.py - cascade u2 batch 49001: 0x5ecd80. `this` is a random block with the float fields (+0xbf, +0xc3 (zero half of the time), +0xc7), the ints at +0x52/+0x56 (negatives too), the count at
+0x3e (0..4), the object pointer array at +0x62 and the record table behind [+0x3a]+4. The view object a has slots 0/1 (ints), 3 (float in st0); 0x4463b0 is hooked (records ctx and the two input floats,
writes two random floats to the output); 0x5ec8b0 is hooked (records this and its three arguments)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5ecd80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = c.fv
    me = rnd(c, 0x1a0)
    n = r.choice([0, 1, 1, 2, 3, 4])
    e.w32(me + 0x3e, n)

    def wf(o, v):
        e.wbytes(me + o, struct.pack('<f', v))
    wf(0xbf, fv(-10, 10, 0.1))
    wf(0xc3, 0.0 if r.random() < 0.5 else fv(-10, 10, 0.1))
    wf(0xc7, fv(-10, 10, 0.1))
    e.wbytes(me + 0x52, struct.pack('<i', r.choice([r.randrange(-3000, 3000), r.randrange(-2 ** 31, 2 ** 31), 0, 640])))
    e.wbytes(me + 0x56, struct.pack('<i', r.choice([r.randrange(-3000, 3000), r.randrange(-2 ** 31, 2 ** 31), 0, 480])))
    ptrs = e.alloc(4 * 6, 4)
    for i in range(6):
        o = rnd(c, 0x20)
        e.wbytes(o + 8, struct.pack('<ff', fv(-10, 10, 0.1), fv(-10, 10, 0.1)))
        e.w32(ptrs + 4 * i, o)
    e.wbytes(me + 0x62, struct.pack('<I', ptrs))
    tab = rnd(c, 0x28 * 6 + 0x20)
    st = rnd(c, 0x10)
    e.w32(st + 4, tab)
    e.wbytes(me + 0x3a, struct.pack('<I', st))

    def side(em, k):
        em.wbytes(em.arg32(0), struct.pack('<ff', fv(-10, 10, 0.1), fv(-10, 10, 0.1)))
    hook_rec(c, 0x4463b0, 2, this=True, nullflag=(0,), deref={1: 2}, side=side, pop=8)
    hook_rec(c, 0x5ec8b0, 3, this=True, pop=12, stackmark=(1, 2))
    a = obj(c, 0x20, {0: pystub(c, 0, this=True, ret=lambda em, k: r.randrange(-500, 500)),
                      4: pystub(c, 0, this=True, ret=lambda em, k: r.randrange(-500, 500)),
                      0xc: pystub(c, 0, this=True, st0=lambda em, k: fv(-10, 10, 0.1))})
    ctx = rnd(c, 0x20)
    return [me, a, ctx]


S(0x5ecd80, 'GUESS view scale setup and per-entry update', 'thiscall', None, ret=None, gen=_g5ecd80, note='batch49001')
