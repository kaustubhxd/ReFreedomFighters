"""specs_s31123.py - Sonnet h1 batch 31123."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g493020(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc440, 1, ret=r32(c), pop=4, this=True)
    objs = [rnd(c, 0x20) for _ in range(4)]
    sysobj(c, table_slots={0x2c: pystub(c, 0, ret=r.choice([0, 0, 1, 0x100, r32(c)]), this=True),
                           0x54: pystub(c, 1, ret=lambda e, k: objs[k % 4], this=True, side=clob(c))})
    a = rnd(c, 0x40)
    n = r.choice([0, 1, 2, 3])
    c.emu.w32(a, n)
    for i in range(3):
        c.emu.w32(a + 4 + 8 * i, r32(c))
        c.emu.w32(a + 8 + 8 * i, r.choice([0x4000, 0, 0x4001, r32(c), r32(c) & ~0x4000]))
    return [a]


def g4c0940(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4db3b0, 0, ret=r.choice([0, r32(c) | 1]), pop=0, this=True)
    hook_rec(c, 0x445c50, 0, ret=r.choice([0, r32(c) | 1]), pop=0, this=True)
    ob = rnd(c, 0x20)
    h = obj(c, 0x40, {0xb4: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=ob, this=True),
                                0x4c: pystub(c, 1, ret=r32(c), this=True)}, table_size=0xb00)
    c.emu.w32(so + 0x190f, h)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xadc, r32(c))
    me = rnd(c, 0x1c0)
    c.emu.w32(me + 0x1ac, r.choice([0, 1, 0x100, r32(c)]))
    return [me][:1]


def g54dc40(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    L = r.choice([0, 1, 3, 7])
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0, 0, 0, 0]
    for i in range(L + 1):
        c.emu.w32(s + i, bs[i] | bs[i + 1] << 8 | bs[i + 2] << 16 | bs[i + 3] << 24)
    me = rnd(c, 0x8070)
    h = r.choice([0, obj(c, 0x40, {0x10: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x20)])
    c.emu.w32(me + 0x8061, h)
    return [me, r32(c), r.choice([0, s, s, s])]


def g579ca0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True,
             side=lambda e, k: e.calllog.append(('cookie', e.reg('ecx'))))
    c.emu.w32(0x6f5630, r32(c))
    c.emu.w32(0x6f5634, r32(c))

    def fill(em, k):
        a = em.arg32(1)
        for i in range(16):
            em.w32(a + 4 * i, r.getrandbits(32))
    o = obj(c, 0x40, {0x198: pystub(c, 4, ret=r32(c), pop=0, side=fill)}, nslots=0x100)
    t = obj(c, 0x40, {0x68: pystub(c, 3, ret=r32(c), this=True, deref={0: 16})}, nslots=0x40)
    sysobj(c, slots={0x190: pystub(c, 0, ret=o, this=True)}, table_slots={0x134: pystub(c, 0, ret=t, this=True)})
    me = rnd(c, 0x1a0)
    return [me, r32(c)]


S(0x493020, 'GUESS if sys slot 0x2c false, for each (id,flags) look up slot 0x54 and call 4dc440(1) when flag 0x4000', 'stdcall', None, ret='eax', gen=g493020, note='batch31123')
S(0x4c0940, 'GUESS resolve object through flag-dependent path then sys slot 0x4c(edx or default)', 'thiscall', None, ret='eax', gen=g4c0940, note='batch31123')
S(0x54dc40, 'GUESS duplicate string into allocated buffer at +0x802d and notify slot 0x10', 'thiscall', None, ret='eax', gen=g54dc40, note='batch31123')
S(0x579ca0, '/GS: global slot 0x190 obj slot 0x198 fills local, table slot 0x134 obj slot 0x68(local,arg,0)', 'thiscall', None, ret='eax', gen=g579ca0, note='batch31123')
