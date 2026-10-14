"""specs_s35145.py - 0x534480 (thiscall(s) ret 4, ret='eax'). Pool object: 0x100 random bytes with the used count [0] random, free-list head [4] in 0..6 and eight 8-byte entries from +8 whose link dwords (+0xc + 8i) are small indices 0..7, in half of the cases with bit 31 set (the mask 0x7fffffff matters);
s: object with slot 0x48 (1 arg, out pointer flag-recorded: the first call writes n in 0..3, later calls write fresh random dwords)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g534480(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    vals = [r.getrandbits(32) for _ in range(4)]

    def w48(em, k):
        em.w32(em.arg32(0), n if k == 0 else vals[min(k - 1, 3)])
    s = obj(c, 0x20, {0x48: pystub(c, 1, nullflag=(0,), this=True, side=w48)}, nslots=0x13)
    me = rnd(c, 0x100)
    e.w32(me + 4, r.randint(0, 6))
    for i in range(8):
        lk = r.randint(0, 7) | (0x80000000 if r.random() < 0.5 else 0)
        e.w32(me + 8 + 8 * i + 4, lk)
    return [me, s]


S(0x534480, 'GUESS read values into indexed pool and link into ring', 'thiscall', None, ret='eax', gen=_g534480, note='batch35145')
