"""specs_s34133.py - 0x63a770 cdecl(old, newsize): engine object 0x70038c slot 0x48 (1 arg) returns a fresh random value each call; hooked 0x41e290 (returns a block) and 0x634273; memmove import stubbed (logs the arguments and the source bytes)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x60), pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    eng = obj(c, 0x20, {0x48: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=0x4c // 4)
    e.w32(0x70038c, eng)
    blk = rnd(c, 0x60)
    n = r.choice([0, 1, 7, 0x10, 0x30]) | (r.getrandbits(4) << 28)
    e.w32(blk + 8 - 8 + 0, r.getrandbits(32))
    old = blk + 0x10
    e.w32(old - 8, n)
    e.w32(old - 4, r.getrandbits(32))

    def mm(em, res_):
        d, s, k = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memmove', d, s, k))
        em.ret(eax=d, argbytes=0)
    e.stub_import('memmove', mm)
    return [old, r.choice([0, 1, 0x20, 0x30])]


S(0x63a770, 'GUESS aligned realloc copy', 'cdecl', None, ret='eax', gen=_g, note='batch34133')
