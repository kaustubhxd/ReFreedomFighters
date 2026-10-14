"""specs_s38036.py - cascade s8 batch 38036. The id argument is one of the four ids at this+0x142 / 0x148 / 0x146 / 0x14c (distinct random words, 90%) or unrelated; flags +0x1d5 / +0x1c3 / +0x1e6 / +0x1cc,
step +0x156 (small, around the list count) and the 12-byte record table (n 0..4 records from this+0x4c, first dwords random small ints, compared signed against *extra) are randomised; engine object: slots 0xc
(4 args), 0x1cc (1 arg), +0x190f object (slot 0xbc), table slots 0xac (count 0..3), 0xa4, 0xa0 (recorded, every call logged in order); the engine float at +0x1b40 is compared through the heap/data snapshot;
0x5d7bc0 / 0x5d7e00 / 0x5d7ef0 hooked (the last one records this = this+0x48)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5d73b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = r.sample(range(1, 0x10000), 4)
    cnt = r.randrange(0, 4)
    obj9 = obj(c, 0x20, {0xbc: pystub(c, 0, this=True)})
    slots = {0xc: pystub(c, 4, this=True), 0x1cc: pystub(c, 1, this=True)}

    def ctr(em, k):
        return cnt
    so = sysobj(c, slots, table_slots={0xac: pystub(c, 0, this=True, ret=ctr), 0xa4: pystub(c, 0, this=True), 0xa0: pystub(c, 1, this=True)})
    e.w32(so + 0x190f, obj9)
    e.w32(so + 0x1b40, r.getrandbits(32))
    me = rnd(c, 0x200)
    for off, v in zip((0x142, 0x148, 0x146, 0x14c), ids):
        e.wbytes(me + off, struct.pack('<H', v))
    lc = r.randrange(0, 5)
    lst = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lc)})
    e.w32(me + 0x14e, lst)
    e.w32(me + 0x44, obj(c, 0x20, {0x128: pystub(c, 3, this=True)}))
    e.w32(me + 0x156, r.choice([0, 1, lc - 1, lc, lc + 1, 0xffffffff, r.getrandbits(32)]) & 0xffffffff)
    for off in (0x1d5, 0x1c3, 0x1e6, 0x1cc):
        e.wbytes(me + off, bytes([r.choice([0, 1, 1, 0xff])]))
    n = r.choice([0, 1, 2, 3, 4])
    e.w32(me + 0x48, n)
    for i in range(n):
        e.w32(me + 0x4c + 12 * i, r.choice([0, 1, 5, 10, 20, 0xffffffff, r.getrandbits(32)]))
    extra = rnd(c, 8)
    e.w32(extra, r.choice([0, 3, 10, 15, 100, 0xfffffffe, r.getrandbits(32)]))
    hook_rec(c, 0x5d7bc0, 0, this=True)
    hook_rec(c, 0x5d7e00, 0, this=True)
    hook_rec(c, 0x5d7ef0, 2, this=True, pop=8)
    idv = r.choice(ids) if r.random() < 0.9 else r.randrange(0x10000)
    if r.random() < 0.3:
        idv |= r.getrandbits(16) << 16
    return [me, idv, extra]


S(0x5d73b0, 'GUESS event dispatch of two-list control', 'thiscall', None, ret='eax', gen=_g5d73b0, note='batch38036')
