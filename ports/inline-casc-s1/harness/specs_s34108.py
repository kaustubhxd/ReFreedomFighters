"""specs_s34108.py - seven items; callees are recorders. Register-argument callee 0x4de420 logs edx (source) and ecx (this); it is hooked with a stand-in copy (the copy itself is observable through the heap)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _edx(em, k):
    em.calllog.append(('edx', em.reg('edx')))


def _g525380(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4de420, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    return [rnd(c, 0x20), rnd(c, 0x40), rnd(c, 0x10)]


def _ctor(addr, nbytes):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, 0x469870, 0, this=True, pop=0, ret=r.getrandbits(32))
        return [rnd(c, nbytes)]
    return g


def _g475300(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x467710, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x466220, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x3f0)]


def _g4dcb50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4de420, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    return [rnd(c, 0x50), rnd(c, 0x40), rnd(c, 0x10)]


def _g5aee20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5af040, 1, this=True, ret=lambda em, k: r.choice([0, 1, 5, 7, 8, 8]))
    return [rnd(c, 0x50), r.getrandbits(32), r.getrandbits(32)]


def _g42abbd(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x10)
    hook_rec(c, 0x42acaf, 5, pop=0, ret=blk)
    hook_rec(c, 0x634d94, 2, pop=0, ret=lambda em, k: r.choice([0, 1, 0xffffffff, 0x80000000, 5, r.getrandbits(32)]))
    return [r.getrandbits(32) for _ in range(5)]


def _g468030(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4654b0, 3, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x1e0), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x525380, 'GUESS copy block and read vector', 'thiscall', None, ret='eax', gen=_g525380, note='batch34108')
S(0x5d48e0, 'GUESS constructor F2', 'thiscall', None, ret='eax', gen=_ctor(0x5d48e0, 0x70), note='batch34108')
S(0x475300, 'GUESS reset state', 'thiscall', None, ret='eax', gen=_g475300, note='batch34108')
S(0x4dcb50, 'GUESS set vector and copy block', 'thiscall', None, ret='eax', gen=_g4dcb50, note='batch34108')
S(0x5aee20, 'GUESS accumulate into slot', 'thiscall', None, ret=None, gen=_g5aee20, note='batch34108')
S(0x42abbd, 'GUESS call and clamp error', 'cdecl', None, ret='eax', gen=_g42abbd, note='batch34108')
S(0x468030, 'GUESS constructor with base args 2', 'thiscall', None, ret='eax', gen=_g468030, note='batch34108')
