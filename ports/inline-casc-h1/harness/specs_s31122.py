"""specs_s31122.py - Sonnet h1 batch 31122."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4f45a0(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        pp = em.arg32(0)
        em.w32(pp, (em.r32(pp) + r.choice([1, 1, 2])) & 0xffffffff)
    L = r.choice([0, 1, 2, 3, 5])
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0, 0, 0, 0]
    for i in range(len(bs) - 3):
        c.emu.w32(s + i, bs[i] | bs[i + 1] << 8 | bs[i + 2] << 16 | bs[i + 3] << 24)
    me = obj(c, 0x40, {0x298: pystub(c, 1, ret=r.choice([0, 1, 2, 7, r32(c)]), this=True, side=side, deref={0: 1})}, nslots=0x100)
    return [me, s, r.choice([0, 1, 2, 3, 6])]


def g539be0(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.choice([0, r32(c) | 1]), this=True)})
    return [rnd(c, 0x5200), r32(c)]


def g614e50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x63d840, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4cd180, 0, ret=r32(c), pop=0, this=True)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=clob(c))
    me = rnd(c, 0xb9c0)
    c.emu.w32(me + 4, r.choice([0, 1, 0x100, r32(c)]) << 8 | (c.emu.r32(me + 4) & 0xff))
    for off in (0xb9b0, 0xb9ac, 0xb9a8):
        c.emu.w32(me + off, r.choice([0, 0, r32(c) | 1]))
    return [me]


def g46ee50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True)
    hook_rec(c, 0x4db500, 1, ret=r32(c), pop=4, this=True)

    def look(em, name, n):
        d = em.reg('edx')
        em.calllog.append((name, tuple(em.r32(d + 4 * i) for i in range(n))))

    def f2c4(em, k):
        a, b = em.arg32(0), em.arg32(1)
        for i in range(9):
            em.w32(a + 4 * i, r.getrandbits(32))
        for i in range(3):
            em.w32(b + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x4419f0, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: look(e, 'a', 9))
    hook_rec(c, 0x441940, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: look(e, 'b', 3))
    Rr = rnd(c, 0x20)
    Qb = rnd(c, 0x140)
    c.emu.w32(Qb + 0x11b, Rr)
    c.emu.w32(Rr + 8, rnd(c, 0x20))
    q = obj(c, 0x40, {}, nslots=0x10)
    me = obj(c, 0x200, {0x350: pystub(c, 0, ret=Qb, this=True, side=clob(c)),
                        0x2c4: pystub(c, 2, ret=r32(c), this=True, side=f2c4)}, nslots=0x100)
    return [me, r32(c)]


S(0x4f45a0, 'GUESS loop slot 0x298(&p) accumulating until NUL or count', 'thiscall', None, ret='eax', gen=g4f45a0, note='batch31122')
S(0x539be0, 'GUESS validate id via sys slot 0x58 then store and zero counters, else log', 'thiscall', None, ret='eax', gen=g539be0, note='batch31122')
S(0x614e50, 'GUESS release three owned buffers via 4cd180 and 634273 when enabled', 'thiscall', None, ret='eax', gen=g614e50, note='batch31122')
S(0x46ee50, '/GS: slot 0x350 obj chain to 4db500, slot 0x2c4 fills two locals, 4419f0/441940 via EDX', 'thiscall', None, ret='eax', gen=g46ee50, note='batch31122')
