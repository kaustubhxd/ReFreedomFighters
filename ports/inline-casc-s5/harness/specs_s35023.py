"""specs_s35023.py - 0x468f20 (ret='al'). Stream object slot 0x10 (2 args: dest recorded, length recorded) writes a call-dependent random dword through dest; object random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g468f20(c):
    clear_hooks(c)
    r = c.rng

    def rd(em, k):
        em.w32(em.arg32(0), ((k + 1) * 0x9e3779b1 ^ r.getrandbits(32)) & 0xffffffff)
    s = obj(c, 0x20, {0x10: pystub(c, 2, this=True, side=rd)}, nslots=8)
    return [rnd(c, 0x40), s]


S(0x468f20, 'GUESS load eight dwords from stream', 'thiscall', None, ret='al', gen=_g468f20, note='batch35023')
