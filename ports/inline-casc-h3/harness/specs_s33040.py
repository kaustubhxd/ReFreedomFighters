"""specs_s33040.py - h3 (Sonnet) batch 33040."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _gctor(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, this=True)
    return [rnd(c, 0x200)]


def _g4c58b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda e, k: r.getrandbits(32))
    me = rnd(c, 0x100)
    mid = rnd(c, 0x20)
    c.emu.w32(mid + 8, rnd(c, 0x40))
    c.emu.w32(me + 0x44, mid)
    return [me, _w(c), rnd(c, 0x40)]


def _g52a070(c):
    clear_hooks(c)
    hook_rec(c, 0x517030, 2, this=True)
    return [rnd(c, 0x200), rnd(c, 0x80)]


def _g43e110(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        t = em.reg('ecx')
        em.w32(t + 0x14, r.choice([0, 1, 2, 8, 0xf, 0x10, 0x11, r.getrandbits(32)]))
    hook_rec(c, 0x45fa00, 1, this=True, side=side)
    return [rnd(c, 0x40), _w(c)]


def _g4683f0(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x6352f0, 1, this=True, side=side, nullflag=(0,))
    hook_rec(c, 0x4702b0, 1, this=True, deref={0: 1})
    return [rnd(c, 0x40), _w(c)]


def _g4edbd0(c):
    clear_hooks(c)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda e, k: rnd(c, 0x20))
    hook_rec(c, 0x4ede80, 1, this=True)
    return [rnd(c, 0x200), c.rng.choice([0, _w(c)])]


def _g5ecd40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ebca0, 0, this=True)
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 3, 5, 8])
    buf = rnd(c, 0x28 * 9 + 0x40)
    mid = rnd(c, 0x20)
    c.emu.w32(mid + 4, buf)
    c.emu.w32(me + 0x3a, mid)
    c.emu.w32(me + 0x3e, n)
    return [me]


S(0x5d6c70, 'GUESS ctor flag+vtable+2 fields', 'thiscall', None, ret='eax', gen=_gctor, note='batch33040')
S(0x5d8520, 'GUESS ctor flag+vtable+3 fields', 'thiscall', None, ret='eax', gen=_gctor, note='batch33040')
S(0x4c58b0, 'GUESS copy 3 floats from nested obj', 'thiscall', None, ret=None, gen=_g4c58b0, note='batch33040')
S(0x52a070, 'GUESS two 517030 calls', 'thiscall', None, ret=None, gen=_g52a070, note='batch33040')
S(0x43e110, 'GUESS call + flag clear', 'thiscall', None, ret=None, gen=_g43e110, note='batch33040')
S(0x4683f0, 'GUESS clear flag + 2 calls return 1', 'thiscall', None, ret='al', gen=_g4683f0, note='batch33040')
S(0x4edbd0, 'GUESS new + copy', 'thiscall', None, ret=None, gen=_g4edbd0, note='batch33040')
S(0x5ecd40, 'GUESS init floats loop', 'thiscall', None, ret=None, gen=_g5ecd40, note='batch33040')
