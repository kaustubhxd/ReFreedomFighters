"""specs_s33039.py - h3 (Sonnet) batch 33039."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _flags(c):
    return c.rng.getrandbits(32)


def _g4f9c60(c):
    clear_hooks(c)
    hook_rec(c, 0x4ef200, 1, this=True)
    return [rnd(c, 0x100), rnd(c, 0x100)]


def _gdel(base):
    def g(c):
        clear_hooks(c)
        def seen(em, k):
            em.calllog.append(('vt', 0, None, (em.r32(em.reg('ecx')),)))
        hook_rec(c, base, 0, this=True, side=seen)
        hook_rec(c, 0x634273, 2, pop=0)
        return [rnd(c, 0x100), _flags(c)]
    return g


def _gctor(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, this=True)
    return [rnd(c, 0x200)]


def _g47f6c0(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), _flags(c), _flags(c), _flags(c)]


def _gvc(off, fld):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu

        def ret_func(e2, k):
            ptr = e.alloc(4)
            e.w32(ptr, r.choice([0, 0, r.getrandbits(32)]))
            return ptr
        hook_rec(c, 0x5003d0, 1, this=True, ret=ret_func)
        stub = pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))
        tgt = obj(c, 0x40, {off: stub})
        me = rnd(c, 0x300)
        e.w32(me + fld, tgt)
        arg = obj(c, 0x8, {4: r.getrandbits(32)})
        return [me, arg]
    return g


S(0x4f9c60, 'GUESS copy ctor + 2 fields', 'thiscall', None, ret=None, gen=_g4f9c60, note='batch33039')
S(0x5493c0, 'GUESS scalar deleting dtor (0xa274)', 'thiscall', None, ret='eax', gen=_gdel(0x54cd00), note='batch33039')
S(0x607cb0, 'GUESS scalar deleting dtor (4)', 'thiscall', None, ret='eax', gen=_gdel(0x656e10), note='batch33039')
S(0x5c7ce0, 'GUESS ctor flag+vtable+field', 'thiscall', None, ret='eax', gen=_gctor, note='batch33039')
S(0x5c5260, 'GUESS ctor flag+vtable+2 fields', 'thiscall', None, ret='eax', gen=_gctor, note='batch33039')
S(0x47f6c0, 'GUESS ctor(a,b,c)', 'thiscall', None, ret='eax', gen=_g47f6c0, note='batch33039')
S(0x5080a0, 'GUESS vcall 0x694 with bool', 'thiscall', None, ret='eax', gen=_gvc(0x694, 0x18), note='batch33039')
S(0x5227f0, 'GUESS vcall 0x38c with bool', 'thiscall', None, ret='eax', gen=_gvc(0x38c, 0x1c), note='batch33039')
