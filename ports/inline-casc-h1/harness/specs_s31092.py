"""specs_s31092.py - Sonnet h1 batch 31092."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, pop=None):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g462ad0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, 0 if r.random() < 0.2 else obj(c, 0x40, {0x18: st(c, 1)}))
    c.emu.w32(me + 0x60, 0 if r.random() < 0.3 else obj(c, 0x40, {0x18: st(c, 1, ret=r.choice([0, 1, r32(c)]), clob=True)}))
    return [me, r32(c)]


def g46c970(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x43f8c0, 1, pop=4)
    a = obj(c, 0x80, {0x1e0: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101]))})
    return [rnd(c, 0x80), a]


def g54bda0(c):
    clear_hooks(c)
    r = c.rng
    scratch = c.emu.alloc(4, 4)
    hook_rec(c, 0x54f2b0, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k: emu.w32(scratch, emu.reg('edx')))   # records EDX
    inner = obj(c, 0x40, {0x2c: st(c, 8, ret=r.choice([0, r32(c), 0x1234]), pop=0x20)})
    me = rnd(c, 0x6400)
    c.emu.w32(me + 0x63ec, inner)
    return [me] + [r32(c) for _ in range(6)]


S(0x462ad0, 'GUESS member slot 0x18 gate, else tail slot 0x18 of other member', 'thiscall', None, ret='eax', gen=g462ad0, note='batch31092')
S(0x46c970, 'GUESS 43f8c0 then copy +0x60,+0x64 if arg slot 0x1e0 true', 'thiscall', None, ret='eax', gen=g46c970, note='batch31092')
S(0x54bda0, 'GUESS member slot 0x2c with 7 args, 54f2b0 on failure', 'thiscall', None, ret='al', gen=g54bda0, note='batch31092')
