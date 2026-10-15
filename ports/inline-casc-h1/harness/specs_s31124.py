"""specs_s31124.py - Sonnet h1 batch 31124."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5b5370(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c)
    so = c.emu.r32(0x70039c)
    h = obj(c, 0x40, {0x88: pystub(c, 1, ret=r32(c), this=True, side=clob(c))}, nslots=0x100)
    c.emu.w32(so + 0x1907, h)
    me = rnd(c, 0x270)
    c.emu.w32(me + 0x250, r.choice([3, 3, 0, 1, 2, r32(c)]))
    return [me, r.choice([3, 0, 1, r32(c)])]


def g5f2840(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c, table_slots={0x114: pystub(c, 4, ret=r32(c), this=True)}, table_size=0xc00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xbc4, r.choice([0, 0, 1, 0x100, r32(c)]))
    sub = lambda: r.choice([0, obj(c, 0x40, {0x14: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x20)])
    M = rnd(c, 0xb0)
    c.emu.w32(M + 0xa0, sub())
    c.emu.w32(M + 0xa4, sub())
    me = rnd(c, 0x1020)
    c.emu.w32(me + 0xc, M)
    return [me, r32(c)]


def g63fc20(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=clob(c))
    return [rnd(c, 0x240)][:1]


def g658ca0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True,
             side=lambda e, k: e.calllog.append(('cookie', e.reg('ecx'))))
    c.emu.w32(0x6f5630, r32(c))
    c.emu.w32(0x6f5634, r32(c))
    hook_rec(c, 0x610100, 1, ret=r32(c), pop=4, this=True, side=clob(c))

    def fill(em, k):
        a, b = em.arg32(0), em.arg32(1)
        for i in range(9):
            em.w32(a + 4 * i, r.getrandbits(32))
        for i in range(3):
            em.w32(b + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x4db2c0, 2, ret=r32(c), pop=8, this=True, side=fill)
    arg = rnd(c, 0x60)
    c.emu.w32(arg + 8, rnd(c, 0x20))
    me = obj(c, 0x200, {0x12c: pystub(c, 3, ret=r32(c), this=True, deref={0: 9, 1: 3})}, nslots=0x100)
    c.emu.w32(me + 0x137, r.choice([0, 0, 1, r32(c) | 1]))
    return [me, arg]


S(0x5b5370, 'GUESS leaving state 3 releases five handles via global+0x1907 slot 0x88, set state', 'thiscall', None, ret='eax', gen=g5b5370, note='batch31124')
S(0x5f2840, 'GUESS notify two children slot 0x14 unless flag, bump counter, table slot 0x114 word to global', 'thiscall', None, ret='eax', gen=g5f2840, note='batch31124')
S(0x63fc20, 'GUESS free eight owned buffers and zero them', 'thiscall', None, ret='eax', gen=g63fc20, note='batch31124')
S(0x658ca0, '/GS: 610100(arg), when flag 4db2c0 fills two locals then slot 0x12c(locals, arg+0x3c)', 'thiscall', None, ret='eax', gen=g658ca0, note='batch31124')
