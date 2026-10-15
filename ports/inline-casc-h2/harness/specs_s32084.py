"""specs_s32084.py - h2 (Sonnet) batch 32084: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _chain(c):
    r = c.rng
    hook_rec(c, 0x51d0d0, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=r.getrandbits(32))
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, ret=r.getrandbits(32))


def g51ecd0(c):
    clear_hooks(c)
    _chain(c)
    me = rnd(c, 0x40)
    a = rnd(c, 0x20)
    return [me, a]


def g5228b0(c):
    clear_hooks(c)
    r = c.rng
    _chain(c)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, obj(c, 0x20, {0x394: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x394 // 4 + 1))
    return [me, rnd(c, 0x20)]


def g5c7f30(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x68: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x40), o]


def _g_global(cnt, objp, blk):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        hook_rec(c, 0x634d10, 3, pop=0)
        e.w32(cnt, r.getrandbits(32))
        e.w32(objp, obj(c, 0x20, {0: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0)
        return [r.getrandbits(32)]
    return g


def g5f9700(c):
    clear_hooks(c)
    r = c.rng
    a = obj(c, 0x80, {0x5c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x20), a, r.getrandbits(32)]


def g656f80(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x100)
    me = obj(c, 0x40, {0xc: pystub(c, 1, ret=buf, this=True)})
    return [me, r.getrandbits(32)]


def g464730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ent = rnd(c, 0x80)
    if r.random() < 0.3:
        e.wbytes(ent + 0x5a, bytes(2))
    dst = rnd(c, 0x30)
    o = obj(c, 0x20, {0x58: pystub(c, 1, ret=dst, this=True)})
    me = rnd(c, 0x80)
    e.w32(me + 8, ent)
    e.w32(me + 0x6c, o)
    return [me, rnd(c, 0x30)]


S(0x51ecd0, 'GUESS chain: lookup, 5003d0, 5002f0', 'thiscall', None, ret='eax', gen=g51ecd0, note='batch32084')
S(0x5228b0, 'GUESS chain: slot 0x394, 5003d0, 5002f0', 'thiscall', None, ret='eax', gen=g5228b0, note='batch32084')
S(0x5c7f30, 'GUESS slot 0x68(this+0x1d), true', 'thiscall', None, ret='al', gen=g5c7f30, note='batch32084')
S(0x50d770, 'GUESS reset global pool 7012c8', 'stdcall', None, ret=None, gen=_g_global(0x7012c8, 0x7012cc, 0x7012d0), note='batch32084')
S(0x560320, 'GUESS reset global pool 714198', 'stdcall', None, ret=None, gen=_g_global(0x714198, 0x71419c, 0x7141a0), note='batch32084')
S(0x5f9700, 'GUESS init vtable, slot 0x5c(this+4)', 'thiscall', None, ret='eax', gen=g5f9700, note='batch32084')
S(0x656f80, 'GUESS slot 0xc twice', 'thiscall', None, ret='eax', gen=g656f80, note='batch32084')
S(0x464730, 'GUESS conditional copy via slot 0x58', 'thiscall', None, ret='eax', gen=g464730, note='batch32084')
