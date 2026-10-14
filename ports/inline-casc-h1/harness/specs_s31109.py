"""specs_s31109.py - batch 31109."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4f3e80(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(1), r32(c))
    o = obj(c, 0x40, {0x88: pystub(c, 2, ret=r32(c), this=True, side=side, deref={1: 1})}, nslots=0x40)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r32(c), this=True),
                           0x138: pystub(c, 0, ret=o, this=True, side=clob(c))})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x64, r.choice([0, 0, r32(c) | 1]))
    return [me]


def g50ff80(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x20)
    hook_rec(c, 0x5003d0, 1, ret=blk, pop=4, this=True)
    tgt = r.choice([0, obj(c, 0x40, {0xc4: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x80)])
    o2 = obj(c, 0x40, {0x2c: pystub(c, 2, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=tgt, this=True, side=clob(c))})
    a = rnd(c, 0x20)
    return [a]


def g538040(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c, table_size=0xb00)
    tbl = c.emu.r32(so + 0x9b)
    sentinel = rnd(c, 0x20)
    c.emu.w32(tbl + 0xadc, sentinel)
    n = r.choice([0, 1, 2, 3, 4])
    nxt = sentinel
    chain = []
    for i in range(n):
        o = obj(c, 0x40, {0x20: pystub(c, 0, ret=nxt, this=True),
                          0x1e0: pystub(c, 1, ret=r.choice([0, 0, 1, 0x100, 0xff, r32(c)]), this=True, side=clob(c))}, nslots=0x100)
        nxt = o
    a = obj(c, 0x40, {0x20: pystub(c, 0, ret=nxt, this=True)}, nslots=0x40)
    return [a]


S(0x4f3e80, 'GUESS sys table slot 0x58 on this[0x64] or on value fetched via slot 0x138/0x88', 'thiscall', None, ret='eax', gen=g4f3e80, note='batch31109')
S(0x50ff80, 'GUESS lookup via 5003d0 and sys slot 0x58, tail slot 0xc4(0) or log', 'stdcall', None, ret='eax', gen=g50ff80, note='batch31109')
S(0x538040, 'GUESS walk slot 0x20 chain until flag 0x100021 or sentinel', 'stdcall', None, ret='eax', gen=g538040, note='batch31109')
