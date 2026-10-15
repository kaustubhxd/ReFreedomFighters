"""specs_s31133.py - Sonnet h1 batch 31133: 0x5c82a0 (the worklist row was truncated at 8 instructions; the real function is ~110)."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5c82a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True,
             side=lambda e, k: e.calllog.append(('cookie', e.reg('ecx'))))
    c.emu.w32(0x6f5630, r32(c))
    c.emu.w32(0x6f5634, r32(c))

    def wr(em, addr, n):
        for i in range(n):
            em.w32(addr + 4 * i, r.getrandbits(32))

    def look(em, name, regname, n):
        a = em.reg(regname)
        em.calllog.append((name, tuple(em.r32(a + 4 * i) for i in range(n))))

    # 4db500(ecx=object[8], &out3): fills three dwords
    hook_rec(c, 0x4db500, 1, ret=r32(c), pop=4, this=True, side=lambda e, k: wr(e, e.arg32(0), 3))

    def s43e920(em, k):
        look(em, 'a', 'edx', 3)
        em.calllog.append(('b', tuple(em.r32(em.arg32(0) + 4 * i) for i in range(3))))
        wr(em, em.reg('ecx'), 3)
    hook_rec(c, 0x43e920, 1, ret=r32(c), pop=4, this=True, side=s43e920)
    hook_rec(c, 0x5c88c0, 2, ret=r.choice([0, 1, 0x100, r32(c)]), pop=8, this=True, deref={0: 3})

    def s4de040(em, k):
        look(em, 'c', 'edx', 3)
        wr(em, em.reg('ecx'), 6)
    hook_rec(c, 0x4de040, 1, ret=r32(c), pop=4, this=True, side=s4de040)
    hook_rec(c, 0x4419f0, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: (look(e, 'd', 'edx', 6), wr(e, e.reg('ecx'), 3)))
    hook_rec(c, 0x441940, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: (look(e, 'e', 'edx', 3), wr(e, e.reg('ecx'), 3)))
    hook_rec(c, 0x4de420, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: (look(e, 'f', 'edx', 6), wr(e, e.reg('ecx'), 8)))
    hook_rec(c, 0x4e09b0, 0, ret=r32(c), pop=0, this=True, side=lambda e, k: look(e, 'g', 'ecx', 3))
    o1 = obj(c, 0x40, {0x2d4: pystub(c, 2, ret=r32(c), this=True, deref={0: 8, 1: 3}),
                       0x6c: pystub(c, 1, ret=r32(c), this=True, deref={0: 6})}, nslots=0x100)
    # three table slot 0x58 objects: [8] fields are passed as ECX to 4db500
    t1 = rnd(c, 0x20)
    t2 = rnd(c, 0x20)
    ret58 = [t1, t2, o1, o1]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda e, k: ret58[k % 4], this=True)})
    me = obj(c, 0x100, {}, nslots=0x10)
    K = obj(c, 0x40, {0x8c: pystub(c, 1, ret=r32(c), this=True, deref={0: 3})}, nslots=0x100)
    c.emu.w32(me + 0x44, K)
    c.emu.w32(me + 0x6c, r.choice([0, 0, r32(c) | 1]))
    for off in (0x70, 0x74, 0x78):
        c.emu.w32(me + off, r32(c))
    src = rnd(c, 0x10)
    return [me, src]


S(0x5c82a0, 'GUESS build vectors from arg, slot 0x8c, two 4db500 fetches, vector helper calls, slot 0x2d4 (and 0x6c when this[0x6c])', 'thiscall', None, ret='al', gen=g5c82a0, note='batch31133')
