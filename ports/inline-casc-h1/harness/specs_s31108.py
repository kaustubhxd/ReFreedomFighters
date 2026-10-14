"""specs_s31108.py - batch 31108."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def logobj(c, slot, nargs, pop=0, this=False):
    o2 = obj(c, 0x40, {slot: pystub(c, nargs, ret=r32(c), pop=pop, this=this)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))


def g659330(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4cd9b0, 2, ret=lambda e, k: r.choice([0xffffffff, 0xffffffff, 0, r.getrandbits(32)]), pop=8, this=True)
    logobj(c, 0x30, 2)
    return [rnd(c, 0x20), r32(c), r32(c) & ~3]


def g4b0ba0(c):
    clear_hooks(c)
    r = c.rng
    logobj(c, 0x2c, 2)
    B = rnd(c, 0x1c00)
    if r.random() < 0.2:
        g = B + 0x20
        me = B + 0x10
    else:
        g = B + 0x20
        me = rnd(c, 0x80)
    p = r.choice([0, obj(c, 0x40, {0xcc: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x80)])
    c.emu.w32(g + 0x1a9f, p)
    c.emu.w32(0x70039c, g)
    return [me, r32(c)]


def g4ce960(c):
    clear_hooks(c)
    r = c.rng
    logobj(c, 0x2c, 5)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x14, r.choice([0, 1, 4, 31, 32, 33, r32(c)]))
    return [me, r32(c)]


S(0x659330, 'GUESS init from (a,b), 4cd9b0 result, -1 logs and zeroes', 'thiscall', None, ret='eax', gen=g659330, note='batch31108')
S(0x4b0ba0, 'GUESS copy global +0x40 to this+0x50, forward this[0x64] to slot 0xcc or log', 'thiscall', None, ret='eax', gen=g4b0ba0, note='batch31108')
S(0x4ce960, 'GUESS log shifted/masked value', 'thiscall', None, ret='eax', gen=g4ce960, note='batch31108')
