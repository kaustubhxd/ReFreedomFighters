"""specs_s31131.py - Sonnet h1 batch 31131."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g54e900(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54e570, 0, ret=r32(c), pop=0, this=True)
    c.emu.w32(0x676144, pystub(c, 2, ret=r.choice([0, 1, r32(c)]), pop=8))
    return [rnd(c, 0x2e0)]


def g54bbc0(c):
    clear_hooks(c)
    r = c.rng

    def put(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))
        em.w32(em.arg32(2), r.getrandbits(32))
    hook_rec(c, 0x54f2b0, 0, ret=r32(c), pop=0, this=True,
             side=lambda e, k: e.calllog.append(('edx', e.reg('edx'))))
    o = obj(c, 0x40, {0x10: pystub(c, 3, ret=r.choice([0, r32(c) | 1]), this=True, side=put)}, nslots=0x40)
    me = rnd(c, 0x6400)
    c.emu.w32(me + 0x63ec, o)
    return [me]


def g5aa020(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5acac0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x5edb00, 1, ret=r32(c), pop=4, this=True)
    t = obj(c, 0x40, {8: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x10)
    me = rnd(c, 0x670)
    c.emu.w32(me + 0x640, r32(c))
    c.emu.w32(me + 0x470, t)
    c.emu.w32(me + 0x658, r.choice([0, 1, 0x100, r32(c)]))
    return [me, r.choice([0, 0, 1, 0x100, r32(c)])]


def g60fd70(c):
    clear_hooks(c)
    r = c.rng
    v = r32(c)
    c.emu.w32(0x72496c, v if r.random() < 0.4 else r32(c))
    g = obj(c, 0x40, {0xc8: pystub(c, 3, ret=r32(c), this=True)}, nslots=0x100)
    c.emu.w32(0x724a00, g)
    return [v, r32(c)]


def g4f4ba0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f9c00, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4f9680, 1, ret=r32(c), pop=4, this=True)
    me = obj(c, 0xa0, {0x360: pystub(c, 0, ret=r.choice([0, 1, 0x100, r32(c)]), this=True, side=clob(c)),
                       0x358: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100)
    c.emu.w32(me + 0x70, r.choice([0x20, 0x20, 0, 1, r32(c)]))
    c.emu.w32(me + 0x8f, r.choice([1, 1, 0, 2, r32(c)]))
    return [me]


def g5e05a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4614d0, 3, ret=r32(c), pop=12, this=True)
    K = obj(c, 0x40, {0x228: pystub(c, 5, ret=r32(c), pop=20, this=True)}, nslots=0x100)
    P = rnd(c, 0x10)
    c.emu.w32(P, r.choice([0, r32(c) | 1]))
    me = obj(c, 0x40, {0xc: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x20)
    c.emu.w32(me + 8, K)
    c.emu.w32(me + 0xc, P)
    return [me]


S(0x54e900, 'GUESS IAT 0x676144(this[0x2ce],0) then tail 54e570 when nonzero', 'thiscall', None, ret='eax', gen=g54e900, note='batch31131')
S(0x54bbc0, 'GUESS slot 0x10 of this[0x63ec] fills two locals, 54f2b0(edx=0x6a3bb8), return first', 'thiscall', None, ret='eax', gen=g54bbc0, note='batch31131')
S(0x5aa020, 'GUESS 5acac0(arg), notify this[0x470] when enabled and arg clear', 'thiscall', None, ret='eax', gen=g5aa020, note='batch31131')
S(0x60fd70, 'GUESS fastcall (ecx,edx): update cached value and notify slot 0xc8', 'fastcall', None, ret='eax', gen=g60fd70, note='batch31131')
S(0x4f4ba0, 'GUESS state 0x20 check, slot 0x360/0x358 toggle, 4f9c00, 4f9680(1)', 'thiscall', None, ret='eax', gen=g4f4ba0, note='batch31131')
S(0x5e05a0, 'GUESS slot 0x228 five args then 4614d0(7.0f,0x465710,0), else tail slot 0xc', 'thiscall', None, ret='eax', gen=g5e05a0, note='batch31131')
