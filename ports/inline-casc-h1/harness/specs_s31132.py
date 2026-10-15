"""specs_s31132.py - Sonnet h1 batch 31132."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _g(c, target, nstack, nin):
    clear_hooks(c)
    r = c.rng

    def put(em, k):
        d = em.reg('ecx')
        em.calllog.append(('off', (em.arg32(1) - d) & 0xffffffff))
        for i in range(3):
            em.w32(d + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x42b390, 2, ret=r32(c), pop=8, this='mark', stackmark=(1,), side=put)
    hook_rec(c, target, nstack, ret=r32(c), pop=4 * nstack, this=True)
    B = rnd(c, 0x20)
    A = rnd(c, 0x20)
    c.emu.w32(A + 4, B)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, A)
    return [me] + [r32(c) for _ in range(nin)]


def g5f16c0(c):
    return _g(c, 0x602a60, 8, 6)


def g5f1680(c):
    return _g(c, 0x6028b0, 10, 8)


S(0x5f16c0, 'GUESS build 12-byte struct via 42b390(arg0, &last arg byte) then 602a60 with struct and five args', 'thiscall', None, ret='eax', gen=g5f16c0, note='batch31132')
S(0x5f1680, 'GUESS build 12-byte struct via 42b390(arg0, &last arg byte) then 6028b0 with struct and seven args', 'thiscall', None, ret='eax', gen=g5f1680, note='batch31132')
