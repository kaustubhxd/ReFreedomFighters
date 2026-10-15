"""specs_s31119.py - Sonnet h1 batch 31119."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g45bee0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f3c0, 1, ret=r.choice([0, 1, 0x100, r32(c)]), pop=4, this=True)
    g = obj(c, 0x40, {0x60: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x40)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=g, this=True, side=clob(c)),
                           0x4c: pystub(c, 2, ret=r32(c), this=True)})
    me = obj(c, 0x80, {0x214: pystub(c, 0, ret=r32(c), this=True, side=clob(c))}, nslots=0x100)
    return [me, r32(c)]


def g4863c0(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x358: pystub(c, 1, ret=r32(c), this=True), 0x2d0: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x200)
    o = obj(c, 0x40, {0x128: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x80)
    sysobj(c, table_slots={0x114: pystub(c, 6, ret=r32(c), this=True)})
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, o)
    return [me, a]


def g4f03c0(c):
    clear_hooks(c)
    r = c.rng
    fl = lambda: r.choice([0, 1, 0x100, r32(c)])
    P = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=fl(), this=True), 0x2c4: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x100)
    me = obj(c, 0x80, {0x1e0: pystub(c, 1, ret=fl(), this=True), 0x20: pystub(c, 0, ret=P, this=True, side=clob(c))}, nslots=0x100)
    c.emu.w32(me + 0x5c, r.choice([0, 0, 0, r32(c) | 1]))
    return [me]


S(0x45bee0, 'GUESS slot 0x138 obj slot 0x60 msg, slot 0x214, 45f3c0(arg) != 0', 'thiscall', None, ret='al', gen=g45bee0, note='batch31119')
S(0x4863c0, 'GUESS arg slots 0x358/0x2d0, sys slot 0x114 result to this[8] slot 0x128', 'thiscall', None, ret='eax', gen=g4863c0, note='batch31119')
S(0x4f03c0, 'GUESS cached owner at +0x5c: flag 0x100030 self else slot 0x20 chain slot 0x2c4', 'thiscall', None, ret='eax', gen=g4f03c0, note='batch31119')
