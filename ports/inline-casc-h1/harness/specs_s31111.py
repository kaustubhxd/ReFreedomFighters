"""specs_s31111.py - Sonnet h1 batch 31111."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g428af0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True)
    b = obj(c, 0x40, {0x18: pystub(c, 3, ret=r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r32(c)]), this=True, deref={2: 6})}, nslots=0x40)
    return [rnd(c, 0x40), b]


def g463990(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: pystub(c, 4, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    ar = rnd(c, 0x200)
    me = obj(c, 0x40, {0x2cc: pystub(c, 0, ret=ar, this=True, side=clob(c))}, nslots=0x200)
    c.emu.w32(me + 0x20, r.choice([0, 1, 2, 3, 5]))
    return [me]


def g5fd120(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fd240, 1, ret=r.choice([0, 1, 0x100, r32(c)]), pop=4, this=True, side=clob(c))
    o = obj(c, 0x40, {0x24: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    hook_rec(c, 0x5fa630, 0, ret=o, pop=0)
    hook_rec(c, 0x5fd2a0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x5f3b00, 0, ret=r32(c), pop=0, this=True)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=clob(c))
    me = rnd(c, 0x40)
    return [me, r.choice([0, 0, r32(c) | 1])] if False else [me, r.choice([0, r32(c) | 1])]


S(0x428af0, '/GS: build descriptor, B slot 0x18(4,&desc), bool >=0', 'stdcall', None, ret='eax', gen=g428af0, note='batch31111')
S(0x463990, 'GUESS log loop over this[0x20] entries stride 0x30 from slot 0x2cc ptr', 'thiscall', None, ret='eax', gen=g463990, note='batch31111')
S(0x5fd120, 'GUESS release: 5fd240 gate, 5fa630 slot 0x24, 5fd2a0, 5f3b00, free', 'thiscall', None, ret='eax', gen=g5fd120, note='batch31111')
