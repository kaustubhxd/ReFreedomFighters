"""specs_s31104.py - batch 31104."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g46c910(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x470550, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x471680, 0, ret=r32(c), pop=0, this=True)
    me = obj(c, 0x80, {0x64: pystub(c, 1, ret=r32(c), this=True)})
    a = r.getrandbits(16)
    b = a if r.random() < 0.4 else r.getrandbits(16)
    c.emu.w32(me + 0x48, a | (b << 16))
    c.emu.w32(me + 0x50, r.choice([0, 0, 1, 0x100, r32(c)]))
    arg = r.choice([a, b, a, r.getrandbits(16)]) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    return [me, arg, r32(c)]


def g4fc0d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e40, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    return [rnd(c, 0x90), rnd(c, 0x20)]


def g51bd30(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        em.calllog.append(('a', k, em.arg32(0), em.arg32(1)) if k >= 1 else ('first',))
    hook_rec(c, 0x4690b0, 0, ret=r32(c), pop=0, this=True, side=side)
    hook_rec(c, 0x512070, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x45c510, 1, ret=r32(c), pop=0)
    return [rnd(c, 0x520), r.choice([0, 1, 4, 5, 2, 7, r32(c)])]


S(0x46c910, 'GUESS compare id with +0x48/+0x4a, release +0x5a and slot 0x64(0x10)', 'thiscall', None, ret='eax', gen=g46c910, note='batch31104')
S(0x4fc0d0, 'GUESS read fields from stream into this+0x78..0x83', 'thiscall', None, ret='eax', gen=g4fc0d0, note='batch31104')
S(0x51bd30, 'GUESS dtor 512070 + flag bits -> 45c510 or 4690b0(this,0x5d9)', 'thiscall', None, ret='eax', gen=g51bd30, note='batch31104')
