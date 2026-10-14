"""specs_s35037.py - 0x4b5620 (thiscall(n) ret 4, ret='eax'). [[this+0x44]+0x18] = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out param; the iterator's first dword is zeroed after 0..4 calls, non-zero
at the start in 4/5)); engine table slot 0x58 (1 arg) returns a random value; n in 0..5."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4b5620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3, 4, 5])
    seq = [r.getrandbits(32) for _ in range(6)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 5)], side=s5c)}, nslots=0x20)
    mid = rnd(c, 0x40)
    e.w32(mid + 0x18, L)
    me = rnd(c, 0x80)
    e.w32(me + 0x44, mid)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    return [me, r.choice([0, 1, 2, 3, 4, 5])]


S(0x4b5620, 'GUESS nth list entry through engine table', 'thiscall', None, ret='eax', gen=_g4b5620, note='batch35037')
