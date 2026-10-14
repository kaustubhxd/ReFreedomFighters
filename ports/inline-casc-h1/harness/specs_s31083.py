"""specs_s31083.py - batch 31083."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, this=True, side=side)


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g4760d0(c):
    clear_hooks(c)
    hk(c, 0x467f60, 0)
    hk(c, 0x467cd0, 1, pop=4)
    me = obj(c, 0x400, {0x4a8: st(c, 0, clob=True)})
    return [me]


def g519da0(c):
    clear_hooks(c)
    blk = rnd(c, 0x10)
    hk(c, 0x5003d0, 1, pop=4, ret=blk)
    hk(c, 0x5002f0, 1, pop=4, clob=False)
    inner = obj(c, 0x40, {0x330: st(c, 0)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x14, inner)
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 8, rnd(c, 0x10))
    return [me, arg]


def g55cc00(c):
    clear_hooks(c)
    inner = obj(c, 0x600, {0x354: st(c, 2), 0x5ac: st(c, 2)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, inner)
    return [me, r32(c)]


def g5d02d0(c):
    clear_hooks(c)
    hk(c, 0x5d0310, 0, clob=False)
    sysobj(c, table_slots={0x114: st(c, 4)})
    return [rnd(c, 0xb70)]


def g656f60(c):
    clear_hooks(c)
    O = rnd(c, 0x100)
    me = obj(c, 0x40, {0xc: st(c, 1, ret=O, clob=True)})
    return [me, r32(c)]


def g657940(c):
    clear_hooks(c)
    r = c.rng
    O = rnd(c, 0x60)
    c.emu.wbytes(O + 2, r.choice([0, 0, 1, 0x100]).to_bytes(2, 'little'))
    c.emu.w32(O + 0x50, r.choice([0, 1, 1, 2]))
    me = obj(c, 0x40, {0xc: st(c, 1, ret=O)})
    return [me, r32(c)]


def g4ef1c0(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, slots={0xfc: st(c, 1)})
    me = obj(c, 0x300, {0x230: st(c, 0)})
    c.emu.w32(me + 0x97, r.choice([0, r32(c)]))
    return [me]


def g51b0e0(c):
    clear_hooks(c)
    blk = rnd(c, 0x10)
    hk(c, 0x5003d0, 1, pop=4, ret=blk)
    inner = obj(c, 0x400, {0x388: st(c, 1)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, inner)
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 4, rnd(c, 0x10))
    return [me, arg]


S(0x4760d0, 'GUESS 467f60, slot 0x4a8, 467cd0 on two members', 'thiscall', None, ret='eax', gen=g4760d0, note='batch31083')
S(0x519da0, 'GUESS slot 0x330 result into 5003d0/5002f0', 'thiscall', None, ret='eax', gen=g519da0, note='batch31083')
S(0x55cc00, 'GUESS two member vtable calls (0x354, 0x5ac)', 'thiscall', None, ret='eax', gen=g55cc00, note='batch31083')
S(0x5d02d0, 'GUESS table slot 0x114 result stored, tail 5d0310', 'thiscall', None, ret='eax', gen=g5d02d0, note='batch31083')
S(0x656f60, 'GUESS vtable 0xc twice, second with result+0x8c', 'thiscall', None, ret='eax', gen=g656f60, note='batch31083')
S(0x657940, 'GUESS vtable 0xc result flag test', 'thiscall', None, ret='al', gen=g657940, note='batch31083')
S(0x4ef1c0, 'GUESS release sysobj handle then tail slot 0x230', 'thiscall', None, ret='eax', gen=g4ef1c0, note='batch31083')
S(0x51b0e0, 'GUESS 5003d0 lookup value to member slot 0x388', 'thiscall', None, ret='eax', gen=g51b0e0, note='batch31083')
