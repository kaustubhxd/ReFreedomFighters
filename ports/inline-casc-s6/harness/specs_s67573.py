"""specs_s67573.py - cascade s6 batch 67573 (0x460cb0, no arguments, no return value). Twenty hooks (ten constructors taking three zero arguments, ten second-stage functions): each constructor logs its
three arguments and the three globals 0x6ffa68 / 6c / 70 (random before the call, zero after the function's own stores) and writes a unique tag dword through its `this`; each second-stage function logs
the dword it finds there, so the pairing of objects (and the 0x6852c0 store before the last one) is visible in the call log."""
from pilot import S
from recruits_util import clear_hooks


def _g460cb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x6ffa68, 0x6ffa6c, 0x6ffa70):
        e.w32(a, r.getrandbits(32) | 1)
    ctors = (0x4764b0, 0x476f50, 0x47f6c0, 0x468030, 0x4654b0, 0x469da0, 0x47fce0, 0x460e40, 0x471b50, 0x43de40)
    dtors = (0x476500, 0x477480, 0x47f6f0, 0x468080, 0x465660, 0x46a5c0, 0x47fd30, 0x460f90, 0x471f60, 0x43de70)
    for i, (cc, dd) in enumerate(zip(ctors, dtors)):
        def mkc(addr, i=i):
            def h(em, res_):
                em.calllog.append(('ctor', addr, em.arg32(0), em.arg32(1), em.arg32(2), em.r32(0x6ffa68), em.r32(0x6ffa6c), em.r32(0x6ffa70)))
                em.w32(em.reg('ecx'), 0xA5000000 + i)
                em.ret(eax=0, argbytes=12)
            return h

        def mkd(addr):
            def h(em, res_):
                em.calllog.append(('dtor', addr, em.r32(em.reg('ecx'))))
                em.ret(eax=0, argbytes=0)
            return h
        e.hook(cc, mkc(cc))
        e.hook(dd, mkd(dd))
    return []


S(0x460cb0, 'GUESS construct_destroy_selftest', 'cdecl', None, ret=None, gen=_g460cb0, note='batch67573')
