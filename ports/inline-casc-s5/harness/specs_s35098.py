"""specs_s35098.py - 0x49a650 (thiscall(w) ret 4). this: object with slots 0x14 (1 arg, out pointer flag-recorded: first call writes count 0..3, second writes size 0..5) and 0x10 (2 args: out pointer flag-recorded, length recorded; writes a heap pointer
(distinct per call) through the pointer); w: object with slots 0xc (0 args) and 4 (1 arg, returns a heap pointer + 4); 0x634d22 hooked (cdecl, 3 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g49a650(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d22, 3, pop=0)
    count = r.choice([0, 1, 2, 3])
    size = r.choice([0, 1, 2, 5])
    srcs = [rnd(c, 0x40) for _ in range(4)]

    def w14(em, k):
        em.w32(em.arg32(0), count if k == 0 else size)

    def w10(em, k):
        em.w32(em.arg32(0), srcs[min(k, 3)])
    me = obj(c, 0x20, {0x14: pystub(c, 1, nullflag=(0,), this=True, side=w14), 0x10: pystub(c, 2, nullflag=(0,), this=True, side=w10)}, nslots=8)
    bufs = [rnd(c, 0x40) + 4 for _ in range(4)]
    w = obj(c, 0x20, {0xc: pystub(c, 0, this=True), 4: pystub(c, 1, this=True, ret=lambda em, k: bufs[min(k, 3)])}, nslots=4)
    return [me, w]


S(0x49a650, 'GUESS copy count records into buffer of w', 'thiscall', None, ret=None, gen=_g49a650, note='batch35098')
