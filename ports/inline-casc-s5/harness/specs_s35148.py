"""specs_s35148.py - 0x4c2100 (thiscall(s) ret 4, ret='al'). s: object whose slots 0x48, 0x40, 0x68, 0x50 take one out pointer (recorded) and write a random dword (a random byte for slot 0x68) there. this: 0x80 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4c2100(c):
    clear_hooks(c)
    r = c.rng

    def w4(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))

    def w1(em, k):
        em.w8(em.arg32(0), r.getrandbits(8))
    s = obj(c, 0x20, {0x48: pystub(c, 1, this=True, side=w4), 0x40: pystub(c, 1, this=True, side=w4),
                      0x68: pystub(c, 1, this=True, side=w1), 0x50: pystub(c, 1, this=True, side=w4)}, nslots=0x1b)
    return [rnd(c, 0x80), s]


S(0x4c2100, 'GUESS deserialize field block from stream', 'thiscall', None, ret='al', gen=_g4c2100, note='batch35148')
