"""specs_s31099.py - Sonnet h1 batch 31099."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4a2ff0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: r.choice([0, 0, r.getrandbits(32)]), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e5e40, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def g4f0b70(c):
    clear_hooks(c)
    r = c.rng
    flag = r.choice([0, 1, 0x100, r32(c) | 1, r32(c) & ~0xff])
    hook_rec(c, 0x4dc630, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    hook_rec(c, 0x4dae40, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    sysobj(c, table_slots={0x2c: pystub(c, 0, ret=flag, this=True, side=clob(c)),
                           0x6c: pystub(c, 0, ret=r32(c), this=True, side=clob(c)),
                           0x68: pystub(c, 0, ret=r32(c), this=True)})
    return [rnd(c, 0x20)]


def g54dd00(c):
    clear_hooks(c)
    r = c.rng
    flag = r.choice([0, 1, 0x100, r32(c) | 1, r32(c) & ~0xff])
    buf = rnd(c, 0x40)
    me = obj(c, 0x8040, {0x28: pystub(c, 0, ret=r32(c), this=True, side=clob(c)),
                         0x20: pystub(c, 0, ret=flag, this=True, side=clob(c)),
                         0x18: pystub(c, 0, ret=r32(c), this=True, side=clob(c)),
                         0x2c: pystub(c, 0, ret=r32(c), this=True, side=clob(c)),
                         0x1c: pystub(c, 0, ret=r32(c), this=True)})
    c.emu.w32(me + 0x8021, buf)
    return [me]


S(0x4a2ff0, 'GUESS read fields from stream into this+0x48..0x4f', 'thiscall', None, ret=None, gen=g4a2ff0, note='batch31099')
S(0x4f0b70, 'GUESS sys slot 0x2c check then 4dc630, slots 0x6c, 0x68', 'thiscall', None, ret='eax', gen=g4f0b70, note='batch31099')
S(0x54dd00, 'GUESS vcalls then append 0x10000,8 record', 'thiscall', None, ret='eax', gen=g54dd00, note='batch31099')
