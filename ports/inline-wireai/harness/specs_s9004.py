"""specs_s9004.py - wire-ai batch 9004: CRagdoll2::InitIndices 0x644660. The link (+0x36) is a fake whose slot 0x2b4 logs the bone id
and returns a random index; sometimes a different link object per call is not possible (the pointer is fixed), so the log order and the
23 stored words are what is compared."""
from pilot import S
from specs_s701 import _rnd


def _ii(c):
    e = c.emu

    def bone(em, r):
        em.calllog.append(('link.2b4', 0x2b4, None, (em.arg32(0),)))
        em.ret(eax=c.rng.choice([0, 1, 0x17, c.rng.getrandbits(32), c.rng.randrange(64)]), argbytes=4)
    lk = _rnd(c, 0x40)
    e.w32(lk, e.fake_vtable('link', 0x2b8 // 4, {0x2b4: bone}))
    self_ = _rnd(c, 0x200)
    e.w32(self_ + 0x36, lk)
    return [self_]


S(0x644660, 'CRagdoll2::InitIndices', 'thiscall', None, ret=None, gen=_ii, note='b9004')
