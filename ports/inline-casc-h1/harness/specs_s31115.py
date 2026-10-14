"""specs_s31115.py - batch 31115."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g500450(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5003d0, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x5002f0, 1, ret=r32(c), pop=4, this=True)

    def side(em, k):
        if r.random() < 0.8:
            em.w32(em.arg32(1), r32(c))
    cobj = obj(c, 0x40, {0x88: pystub(c, 2, ret=r32(c), this=True, side=side)}, nslots=0x40)
    e = r.choice([0, obj(c, 0x40, {0x4c: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x40)])
    a = obj(c, 0x40, {0x18: pystub(c, 1, ret=e, this=True, side=clob(c))}, nslots=0x20)
    return [a, r32(c), cobj]


def g5afbb0(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: pystub(c, 2, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    a = r.choice([0, obj(c, 0x40, {0x464: pystub(c, 0, ret=r.choice([0, r32(c) | 1]), this=True)}, nslots=0x200)])
    return [rnd(c, 0x20), a, r.choice([0, r32(c) | 1])]


def g62f980(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6321a0, 2, ret=r32(c), pop=0)
    if r.random() < 0.1:
        return [0]
    e = rnd(c, 0x40)
    P = r.choice([0, rnd(c, 0x20)])
    c.emu.w32(e + 0x1c, P)
    fn = r.choice([0, pystub(c, 2, ret=r32(c), pop=0)])
    c.emu.w32(e + 0x24, fn)
    return [e]


def g45b910(c):
    clear_hooks(c)
    hook_rec(c, 0x43e0f0, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    g = obj(c, 0x40, {0x60: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x40)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=g, this=True, side=clob(c)),
                           0x4c: pystub(c, 2, ret=r32(c), this=True)})
    me = obj(c, 0x80, {0x110: pystub(c, 2, ret=r32(c), this=True, side=clob(c)),
                       0x214: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x100)
    return [me]


S(0x500450, 'GUESS lookup via slot 0x18, out via slot 0x88, 5003d0 then 5002f0, returns obj', 'stdcall', None, ret='eax', gen=g500450, note='batch31115')
S(0x5afbb0, 'GUESS store pair, slot 0x464 result, log if any field zero', 'thiscall', None, ret='eax', gen=g5afbb0, note='batch31115')
S(0x62f980, 'GUESS release resource via 6321a0 and callback, clear +0x1c', 'stdcall', None, ret='eax', gen=g62f980, note='batch31115')
S(0x45b910, 'GUESS slot 0x138 obj slot 0x60(msg, sys slot 0x4c), slot 0x110, 43e0f0, tail slot 0x214', 'thiscall', None, ret='eax', gen=g45b910, note='batch31115')
