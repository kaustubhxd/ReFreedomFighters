"""specs_s31098.py - batch 31098."""
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


def g578bb0(c):
    clear_hooks(c)
    r = c.rng
    v = r32(c)
    hook_rec(c, 0x561cb0, 2, ret=r32(c), pop=8, this=True)
    sysobj(c, table_slots={0x114: st(c, 4, ret=v)})
    a = (v & 0xffff) | ((r32(c) & 0xffff) << 16) if r.random() < 0.5 else r32(c)
    return [rnd(c, 0x1a0), a, rnd(c, 0x10)]


def g4529e0(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x4478d0, 0)
    hk(c, 0x45c510, 1, pop=0, clob=False)
    hk(c, 0x4690b0, 2, pop=0, clob=False)
    return [rnd(c, 0x40), r.choice([0, 1, 2, 3, 4, 5, 7, r32(c)])]


def g46c7d0(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: st(c, 3, pop=0)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: st(c, 2, ret=o2)}))
    blk = rnd(c, 0x60)
    fl = c.emu.r32(blk + 0x3c)
    c.emu.w32(blk + 0x3c, (fl | 0x400) if r.random() < 0.4 else (fl & ~0x400))
    me = obj(c, 0x240, {0x210: st(c, 1)})
    c.emu.w32(me + 8, blk)
    c.emu.w32(me + 4, r.choice([0, r32(c)]))
    return [me]


S(0x578bb0, 'GUESS table slot 0x114 compare, copy field, then 561cb0', 'thiscall', None, ret='eax', gen=g578bb0, note='batch31098')
S(0x4529e0, 'GUESS vtable 681860, 4478d0, flag bits -> 45c510 or 4690b0', 'thiscall', None, ret='eax', gen=g4529e0, note='batch31098')
S(0x46c7d0, 'GUESS log message unless flag, then slot 0x210(1)', 'thiscall', None, ret='eax', gen=g46c7d0, note='batch31098')
