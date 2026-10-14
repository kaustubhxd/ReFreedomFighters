"""specs_s35009.py - 0x46b650 (returns bool: ret='al'). Object with L at +0x7c; L slots 0x14 (zero in 1/5; when non-zero it may clear [this+0x7c] in 1/6), 0x4c (writes a first dword to the
iterator, zero in 1/5), 0x5c (returns a sequence that contains the target in half the cases; zeroes the iterator's first dword after 0..3 calls); o slot 0x2e8; engine table slot 0x4c returns the target."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g46b650(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x90)
    T = r.getrandbits(32)
    m = r.choice([0, 1, 2, 3])
    seq = [r.getrandbits(32) for _ in range(5)]
    if r.random() < 0.5:
        seq[r.randrange(4)] = T
    z = r.random()

    def s14(em, k):
        if r.random() < 1 / 6:
            em.w32(me + 0x7c, 0)

    def s4c(em, k):
        em.w32(em.arg32(0), 0 if r.random() < 0.2 else r.getrandbits(32) | 1)

    def s5c(em, k):
        if k >= m:
            em.w32(em.arg32(0), 0)
    L = obj(c, 0x10, {0x14: pystub(c, 0, ret=0 if z < 0.2 else r.getrandbits(32) | 1, this=True, side=s14),
                      0x4c: pystub(c, 1, nullflag=(0,), this=True, side=s4c),
                      0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 4)], side=s5c)}, nslots=0x20)
    e.w32(me + 0x7c, L)
    o = obj(c, 0x20, {0x2e8: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0xc0)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=T, this=True)})
    return [me, o]


S(0x46b650, 'GUESS iterable contains resolved entry', 'thiscall', None, ret='al', gen=_g46b650, note='batch35009')
