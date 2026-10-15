"""specs_s31110.py - Sonnet h1 batch 31110."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g553dd0(c):
    clear_hooks(c)
    r = c.rng
    blks = [rnd(c, 0x20), rnd(c, 0x20), rnd(c, 0x20), rnd(c, 0x20)]
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: blks[k % 2 if k < 4 else 0] if False else blks[k % 4], pop=4, this=True, side=clob(c))
    hook_rec(c, 0x591e50, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x5002f0, 1, ret=r32(c), pop=4, this=True)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r32(c), this=True, side=clob(c))})
    c.emu.w32(0x7003b8, rnd(c, 0x2c60))
    return [rnd(c, 0x20), r32(c)][:1]


def g57b670(c):
    clear_hooks(c)
    hook_rec(c, 0x563510, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x57b6d0, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x563110, 2, ret=r32(c), pop=8, this=True)
    o = obj(c, 0x40, {0x34c: pystub(c, 5, ret=r32(c), this=True)}, nslots=0x100)
    me = obj(c, 0x80, {0x84: pystub(c, 0, ret=o, this=True)}, nslots=0x40)
    return [me, r32(c), r32(c)]


def g6364e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x50)
    j = r32(c)

    def vside(em, k):
        em.mu.reg_write(REGS['ecx'], j)
        em.calllog.append(('vt', em.r32(me)))
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=vside)
    hook_rec(c, 0x6363a0, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    fl = lambda: r.choice([0, 1, 0x80, r.getrandbits(8)]) | (r32(c) & ~0xff)
    c.emu.w32(me + 0x2d, r32(c))
    c.emu.w32(me + 0x31, fl())
    c.emu.w32(me + 0x36, r32(c))
    c.emu.w32(me + 0x3a, fl())
    return [me, r.choice([0, 1, 2, 3, r32(c)])]


S(0x553dd0, 'GUESS two 5003d0 lookups, 591e50, sys slot 0x4c then 5002f0', 'stdcall', None, ret='eax', gen=g553dd0, note='batch31110')
S(0x57b670, 'GUESS 563510, slot 0x84 object slot 0x34c(5 args), 57b6d0, 563110', 'thiscall', None, ret='al', gen=g57b670, note='batch31110')
S(0x6364e0, 'GUESS dtor: free two buffers, 6363a0, optional free this', 'thiscall', None, ret='eax', gen=g6364e0, note='batch31110')
