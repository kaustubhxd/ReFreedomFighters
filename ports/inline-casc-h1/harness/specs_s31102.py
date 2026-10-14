"""specs_s31102.py - batch 31102."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4fcfd0(c):
    clear_hooks(c)
    hook_rec(c, 0x4fdac0, 0, ret=r32(c), pop=0, this=True)
    o = obj(c, 0x140, {0x128: pystub(c, 2, ret=r32(c), this=True, side=clob(c))})
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True, side=clob(c)),
                           0x4c: pystub(c, 2, ret=r32(c), this=True, side=clob(c))})
    return [rnd(c, 0x90)]


def g56c550(c):
    clear_hooks(c)
    hook_rec(c, 0x5630f0, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    subs = [obj(c, 0x280, {0x250: pystub(c, 1, ret=r32(c), this=True)}) for _ in range(2)]
    objs = [obj(c, 0x280, {0x25c: pystub(c, 2, ret=subs[i], this=True, side=clob(c))}) for i in range(2)]
    me = rnd(c, 0xce8)
    c.emu.w32(me + 0xcd2, objs[0])
    c.emu.w32(me + 0xcd6, objs[1])
    return [me]


def g596760(c):
    clear_hooks(c)
    r = c.rng
    flag = r.choice([0, 1, 0x100, r32(c) | 1])
    o = obj(c, 0x200, {0x1e0: pystub(c, 1, ret=flag, this=True)})
    ret = r.choice([0, o, o])
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=ret, this=True)})
    me = rnd(c, 0x600)
    c.emu.w32(me + 0x4ef, r.choice([0, 1, 5, r.randrange(0, 100)]))
    return [me, r32(c)]


S(0x4fcfd0, 'GUESS sys slots 0x58/0x4c then slot 0x128 and tail 4fdac0', 'thiscall', None, ret='eax', gen=g4fcfd0, note='batch31102')
S(0x56c550, 'GUESS 5630f0 then slot 0x25c/0x250 on two objects', 'thiscall', None, ret='eax', gen=g56c550, note='batch31102')
S(0x596760, 'GUESS append arg to list at +0x2ef if slot 0x1e0 ok', 'thiscall', None, ret='eax', gen=g596760, note='batch31102')
