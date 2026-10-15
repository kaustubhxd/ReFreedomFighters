"""specs_s31101.py - Sonnet h1 batch 31101."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g46ca10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f8c0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    ob = obj(c, 0x80, {0x1e0: pystub(c, 1, ret=lambda e, k: r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, side=clob(c))})
    return [rnd(c, 0x80), ob]


def g475380(c):
    clear_hooks(c)
    hook_rec(c, 0x467850, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    ob = obj(c, 0x80, {0x10: pystub(c, 2, ret=r32(c), this=True, side=clob(c))})
    return [rnd(c, 0x80), ob, r32(c)]


def g4c5700(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e40, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: r.choice([0, 0, r.getrandbits(32)]), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e6330, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    return [rnd(c, 0x60), rnd(c, 0x20)]


S(0x46ca10, 'GUESS copy base, conditional copy +0x60/+0x64 on slot 0x1e0 flag', 'thiscall', None, ret='eax', gen=g46ca10, note='batch31101')
S(0x475380, 'GUESS serialize via 467850 and two slot 0x10 writes', 'thiscall', None, ret='al', gen=g475380, note='batch31101')
S(0x4c5700, 'GUESS read fields from stream into this+0x4c..0x52', 'thiscall', None, ret='al', gen=g4c5700, note='batch31101')
