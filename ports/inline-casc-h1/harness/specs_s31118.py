"""specs_s31118.py - batch 31118."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4dcdf0(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c)
    so = c.emu.r32(0x70039c)
    h = obj(c, 0x40, {0x190: pystub(c, 2, ret=r32(c), pop=8, this=True)}, nslots=0x100)
    c.emu.w32(so + 0x190f, h)
    me = rnd(c, 0x80)
    old = r.choice([0, r32(c) | 1])
    c.emu.w32(me + 0x6c, old)
    c.emu.w32(me + 0x58, r32(c) & 0xffff | (r.choice([0, 0, r.getrandbits(16) | 1]) << 16))
    if r.random() < 0.6:
        P = rnd(c, 0x20)
        Q = rnd(c, 0x40)
        c.emu.w32(P + 0xc, Q)
        c.emu.w32(Q + 0x23, r.choice([0x800000, 0, r32(c), r32(c) & ~0x800000]))
        c.emu.w32(me + 0x54, P)
    else:
        c.emu.w32(me + 0x54, 0)
    arg = old if r.random() < 0.3 else r32(c)
    return [me, arg]


def g534090(c):
    clear_hooks(c)
    r = c.rng
    A = obj(c, 0x40, {0x10: pystub(c, 1, ret=r.choice([0, 1, 0x100, r32(c)]), this=True)}, nslots=0x20)
    mask = r.choice([0, 1, 3, 7, 0xf])
    c.emu.w32(A + 0x10, mask)
    T = rnd(c, 0x40)
    for i in range(16):
        c.emu.w32(T + 4 * i, r.randrange(0, 4))
    me = rnd(c, 0x1020)
    c.emu.w32(me, A)
    c.emu.w32(me + 4, T)
    c.emu.w32(me + 8, rnd(c, 0x400))
    return [me, r32(c)]


def g54a5e0(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: pystub(c, 2, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    c.emu.w32(0x676148, pystub(c, 4, ret=r32(c), pop=16))
    hook_rec(c, 0x54dc10, 0, ret=r.choice([0, 1, 0x100, r32(c)]), pop=0, this=True, side=clob(c))
    me = obj(c, 0x40, {0x90: pystub(c, 0, ret=r.choice([0, 1, 0x100, r32(c)]), this=True)}, nslots=0x40)
    return [me]


def g5ef1e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
    me = rnd(c, 0xc0)

    def side(em, k):
        em.calllog.append(('vt', em.r32(me)))

    def sub():
        return r.choice([0, obj(c, 0x40, {0: pystub(c, 1, ret=r32(c), this=True, side=side)}, nslots=0x10)])
    c.emu.w32(me + 0xa1, sub())
    c.emu.w32(me + 0xa5, sub())
    c.emu.w32(me + 0xa9, sub())
    return [me, r.choice([0, 1, 2, 3, r32(c)])]


S(0x4dcdf0, 'GUESS set this[0x6c], notify global+0x190f slot 0x190(this, old) if flags allow', 'thiscall', None, ret='eax', gen=g4dcdf0, note='batch31118')
S(0x534090, 'GUESS free table slot into free list when slot 0x10(arg) accepts', 'thiscall', None, ret='eax', gen=g534090, note='batch31118')
S(0x54a5e0, 'GUESS IAT call, 54dc10, slot 0x90, log on failure', 'thiscall', None, ret='al', gen=g54a5e0, note='batch31118')
S(0x5ef1e0, 'GUESS dtor vtable 6b81b8 deleting three subobjects then 6b01dc', 'thiscall', None, ret='eax', gen=g5ef1e0, note='batch31118')
