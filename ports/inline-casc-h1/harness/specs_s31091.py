"""specs_s31091.py - batch 31091."""
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


def g489490(c):
    clear_hooks(c)
    me = obj(c, 0x80, {0x40: st(c, 5, clob=True), 0x48: st(c, 5)})
    return [me] + [r32(c) for _ in range(5)]


def g4c6310(c):
    clear_hooks(c)
    sysobj(c, table_slots={0x114: st(c, 4)})
    a = obj(c, 0x80, {0x40: st(c, 1, clob=True)})
    return [rnd(c, 0x60), a]


def g57a9f0(c):
    clear_hooks(c)
    hk(c, 0x5626c0, 0)
    sysobj(c, table_slots={0x4c: st(c, 1)})
    blk = rnd(c, 0x13300)
    glob = rnd(c, 0x80)
    c.emu.w32(0x7003a0, glob)
    me = rnd(c, 0x200)
    c.emu.w32(me + 0x94, blk)
    c.emu.w32(me + 0x54, obj(c, 0x40, {0x25c: st(c, 2)}))
    return [me]


def g597930(c):
    clear_hooks(c)
    hk(c, 0x593f40, 1, pop=4)
    hk(c, 0x594040, 2, pop=8)
    hk(c, 0x596d70, 2, pop=8, clob=False)
    me = rnd(c, 0x1d40)
    c.emu.w32(me + 0x1d0b, obj(c, 0x140, {0x128: st(c, 3)}))
    return [me]


def g61be30(c):
    clear_hooks(c)
    r = c.rng
    mem = rnd(c, 0x80)
    c.emu.w32(mem + 0x34, pystub(c, 4, ret=r32(c), pop=0, this=False))
    a = rnd(c, 0x230)
    c.emu.w32(a + 0x8c, mem)
    c.emu.w32(a + 0x118, r.choice([0, r32(c)]))
    return [a]


def g657820(c):
    clear_hooks(c)
    r = c.rng
    O = rnd(c, 0x60)
    c.emu.wbytes(O + 2, r.choice([0, 0, 1, 0x100]).to_bytes(2, 'little'))
    me = obj(c, 0x40, {0xc: st(c, 1, ret=O)})
    return [me, r32(c), rnd(c, 4), rnd(c, 4), rnd(c, 4)]


def g476350(c):
    clear_hooks(c)
    a = obj(c, 0x80, {0x54: st(c, 1, clob=True), 0x60: st(c, 1)})
    return [rnd(c, 0x60), a]


S(0x489490, 'GUESS clear +0x21 then slots 0x40 and 0x48 with 5 args', 'thiscall', None, ret='eax', gen=g489490, note='batch31091')
S(0x4c6310, 'GUESS clear flag, arg slot 0x40, table slot 0x114 word', 'thiscall', None, ret='al', gen=g4c6310, note='batch31091')
S(0x57a9f0, 'GUESS 5626c0 then table slot 0x4c and member slot 0x25c', 'thiscall', None, ret='eax', gen=g57a9f0, note='batch31091')
S(0x597930, 'GUESS 593f40, 594040 stored, slot 0x128, 596d70', 'thiscall', None, ret='eax', gen=g597930, note='batch31091')
S(0x61be30, 'GUESS member function pointer at +0x34 with 4 args', 'cdecl', None, ret='eax', gen=g61be30, note='batch31091')
S(0x657820, 'GUESS slot 0xc lookup copies three fields to outputs', 'thiscall', None, ret='al', gen=g657820, note='batch31091')
S(0x476350, 'GUESS clear flag, two arg slots, true', 'thiscall', None, ret='al', gen=g476350, note='batch31091')
