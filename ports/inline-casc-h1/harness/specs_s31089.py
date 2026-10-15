"""specs_s31089.py - Sonnet h1 batch 31089."""
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


def g487440(c):
    clear_hooks(c)
    sysobj(c, table_slots={0x114: st(c, 4)})
    return [rnd(c, 0x20), r32(c)]


def g4c2240(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x2c: st(c, 0, ret=r.choice([0, 1, 0x100, 0x101, r32(c)]))})
    me = obj(c, 0x100, {0x68: st(c, 2), 0x84: st(c, 0)})
    return [me, r32(c)]


def g4cd950(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x100, {0x94: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101]), clob=True), 0x8c: st(c, 1)})
    return [me, r32(c)]


def g5095b0(c):
    clear_hooks(c)
    hk(c, 0x505de0, 1, pop=4)
    a = obj(c, 0x40, {0: st(c, 1)})
    me = obj(c, 0x100, {0x38: st(c, 0)})
    return [me, a]


def g5187d0(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    c.emu.w32(so + 0x1a9f, 0 if r.random() < 0.25 else obj(c, 0x80, {0x60: st(c, 2)}))
    me = obj(c, 0x140, {0x2e8: st(c, 1)})
    return [me]


def g521970(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x515cf0, 0)
    me = obj(c, 0x2710, {0x2ec: st(c, 1)})
    for off in (0x26fa, 0x26ea):
        c.emu.w32(me + off, r.choice([0, r32(c)]))
    return [me]


def g5d6240(c):
    clear_hooks(c)
    r = c.rng
    v = [r32(c), r32(c), r.choice([0, 0, 1, r32(c)])]
    j = r32(c)
    hook_rec(c, 0x4e5e60, 0, ret=lambda emu, k: v[min(k, 2)], pop=0, this=True, side=lambda emu, k: emu.mu.reg_write(REGS['ecx'], j))
    return [rnd(c, 0x90), rnd(c, 0x20)]


def g59a800(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x597930, 0)
    hk(c, 0x597980, 0)
    me = rnd(c, 0x2300)
    c.emu.w32(me + 0x44, obj(c, 0x140, {0x12c: st(c, 3)}))
    c.emu.w32(me + 0x22df, r.choice([0, r32(c)]))
    return [me, r.choice([0, 1, 0x100, 0x101])]


S(0x487440, 'GUESS ctor with table slot 0x114 result', 'thiscall', None, ret='eax', gen=g487440, note='batch31089')
S(0x4c2240, 'GUESS clear flag, table gate, slots 0x68 and 0x84, true', 'thiscall', None, ret='al', gen=g4c2240, note='batch31089')
S(0x4cd950, 'GUESS slot 0x94 gate, else slot 0x8c', 'thiscall', None, ret='eax', gen=g4cd950, note='batch31089')
S(0x5095b0, 'GUESS 505de0, slot 0x38 result into arg slot 0', 'thiscall', None, ret='eax', gen=g5095b0, note='batch31089')
S(0x5187d0, 'GUESS global member slot 0x60 result into slot 0x2e8', 'thiscall', None, ret='eax', gen=g5187d0, note='batch31089')
S(0x521970, 'GUESS 515cf0, release two members via slot 0x2ec', 'thiscall', None, ret='eax', gen=g521970, note='batch31089')
S(0x5d6240, 'GUESS three getters stored in members', 'thiscall', None, ret='eax', gen=g5d6240, note='batch31089')
S(0x59a800, 'GUESS 597930 or 597980, then member slot 0x12c', 'thiscall', None, ret='eax', gen=g59a800, note='batch31089')
