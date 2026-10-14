"""specs_s35081.py - 0x45e100 (thiscall(a, b) ret 8). 0x4da3a0 hooked (thiscall, AL true in 3/4); [[this+0x10]+8] = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out param, first dword zeroed after 0..4 calls,
non-zero at start in 4/5)); the object at 0x70038c has slot 0xcc (1 arg, returns a distinct object per call) whose slot 0x50 takes two args (null in a quarter)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g45e100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4da3a0, 0, this=True, ret=((r.getrandbits(24) << 8) | 1) if r.random() < 0.75 else (r.getrandbits(24) << 8))
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3, 4])
    seq = [r.getrandbits(32) for _ in range(6)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)], side=s5c)}, nslots=0x20)
    mid = rnd(c, 0x20)
    e.w32(mid + 8, L)
    me = rnd(c, 0x20)
    e.w32(me + 0x10, mid)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0x50: pystub(c, 2, this=True)}, nslots=0x15) for _ in range(5)]
    E = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 4)])}, nslots=0x34)
    e.w32(0x70038c, E)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x45e100, 'GUESS forward call to every listed entry object', 'thiscall', None, ret=None, gen=_g45e100, note='batch35081')
