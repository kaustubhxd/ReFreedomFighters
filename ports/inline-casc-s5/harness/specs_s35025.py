"""specs_s35025.py - 0x44a340. 0x45eeb0 hooked (thiscall, 2 args). [this+0x18] = list L (null in 1/6; slots 0x4c, 0x5c (zeroes the iterator's first dword after 0..3 calls, the iterator is non-zero at start in 4/5)).
s: object with slot 0x28 (1 arg, returns zero in half); engine table slot 0x58 returns an object (null in 1/3) with slot 0x1e4 (2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g44a340(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45eeb0, 2, this=True)
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3])
    seq = [r.getrandbits(32) for _ in range(5)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 4)], side=s5c)}, nslots=0x20)
    me = rnd(c, 0x40)
    e.w32(me + 0x18, L)
    s = obj(c, 0x20, {0x28: pystub(c, 1, this=True, ret=lambda em, k: 0 if (k + r.getrandbits(1)) % 2 == 0 else 1)}, nslots=0x10)
    ents = [0 if r.random() < 1 / 3 else obj(c, 0x10, {0x1e4: pystub(c, 2, this=True)}, nslots=0x7c) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: ents[min(k, 3)])})
    return [me, s, r.getrandbits(32)]


S(0x44a340, 'GUESS register object with listed table objects', 'thiscall', None, ret=None, gen=_g44a340, note='batch35025')
