"""specs_s66078.py - cascade s4 batch 66078: 0x460cb0 (/GS-protected: construct and finish a chain of stack objects)."""
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _g460cb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    for ctor in (0x4764b0, 0x476f50, 0x47f6c0, 0x468030, 0x4654b0, 0x469da0, 0x47fce0, 0x460e40, 0x471b50, 0x43de40):
        hook_rec(c, ctor, 3, this=True)
    for fin in (0x476500, 0x477480, 0x47f6f0, 0x468080, 0x465660, 0x46a5c0, 0x47fd30, 0x460f90, 0x471f60):
        hook_rec(c, fin, 0, this=True)

    def h43de70(em, rr):
        ecx = em.reg('ecx')
        em.calllog.append(('h43de70', ecx, em.r32(ecx)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x43de70, h43de70)
    for a in (0x6ffa68, 0x6ffa6c, 0x6ffa70):
        e.w32(a, r.getrandbits(32))
    e._image_dirty = True
    return []


S(0x460cb0, 'GUESS /GS construct and finish a chain of stack objects', 'cdecl', None, ret=None, gen=_g460cb0, note='batch66078')
