"""specs_s35076.py - 0x498e60 (stdcall(s) ret 4). s: object with slot 8 (1 arg) and slot 0x10 (2 args; the dword behind the first pointer is compared by content, the length recorded). Engine table [+0xc] = list L (null in 1/6;
slots 0x4c, 0x5c (flag-recorded out param; first dword zeroed after 0..4 calls, non-zero at the start in 4/5))."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g498e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = obj(c, 0x20, {8: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True, deref={0: 1})}, nslots=5)
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3, 4])
    seq = [r.getrandbits(32) for _ in range(6)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)], side=s5c)}, nslots=0x20)
    so = sysobj(c)
    e.w32(e.r32(so + 0x9b) + 0xc, L)
    return [s]


S(0x498e60, 'GUESS serialise list into stream', 'stdcall', None, ret=None, gen=_g498e60, note='batch35076')
