"""specs_s31084.py - Sonnet h1 batch 31084."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, side2=None):
    j = r32(c)

    def side(emu, k):
        if side2:
            side2(emu, k)
        if clob:
            emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, this=True, side=side if (clob or side2) else None)


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def _arg_obj(c):
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 4, rnd(c, 0x10))
    c.emu.w32(arg + 8, rnd(c, 0x10))
    return arg


def g522910(c):
    clear_hooks(c)
    blk = rnd(c, 0x10)
    hk(c, 0x5003d0, 1, pop=4, ret=blk)
    inner = obj(c, 0x400, {0x374: st(c, 1)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, inner)
    return [me, _arg_obj(c)]


def g5595c0(c):
    clear_hooks(c)
    blk = rnd(c, 0x10)
    hk(c, 0x5003d0, 1, pop=4, ret=blk)
    hk(c, 0x5002f0, 1, pop=4, clob=False)
    inner = obj(c, 0x700, {0x6b0: st(c, 0, ret=c.rng.choice([0x7fff, 0x8000, 0x12345678, 0xffff8001, r32(c)]))})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, inner)
    return [me, _arg_obj(c)]


def g5d5970(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x400, {0x110: st(c, 2)})
    c.emu.w32(me + 0x25, 0 if r.random() < 0.3 else obj(c, 0x300, {0x25c: st(c, 1, clob=True)}))
    return [me]


def g463320(c):
    clear_hooks(c)
    me = obj(c, 0x300, {0x2ac: st(c, 2, clob=True), 0x98: st(c, 2)})
    return [me, r32(c), r32(c)]


def g4739e0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x280, {0x230: st(c, 2)})
    for i in range(4):
        c.emu.w32(me + 0x24e + 4 * i, r32(c))
    return [me, r.choice([-5, -1, 0, 1, 2, 3, 4, 100]) & 0xffffffff]


def g47fbe0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    mem = None
    # first slot call may null the member pointer (the thunk re-reads it)
    kill = r.random() < 0.3

    def side(emu, k):
        if kill:
            emu.w32(me + 4, 0)
    mem = obj(c, 0x40, {0x14: st(c, 0, side2=side, clob=True), 0: st(c, 1)})
    c.emu.w32(me + 4, 0 if r.random() < 0.2 else mem)
    return [me]


def g520d50(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x2620, {0x310: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101, r32(c)]))})
    return [me, r32(c)]


def g5968c0(c):
    clear_hooks(c)
    hk(c, 0x594040, 2, pop=8)
    hk(c, 0x593f40, 1, pop=4)
    hk(c, 0x596d70, 2, pop=8, clob=False)
    me = rnd(c, 0x1d20)
    return [me]


S(0x522910, 'GUESS 5003d0 lookup value to member slot 0x374', 'thiscall', None, ret='eax', gen=g522910, note='batch31084')
S(0x5595c0, 'GUESS slot 0x6b0 word into 5003d0/5002f0', 'thiscall', None, ret='eax', gen=g5595c0, note='batch31084')
S(0x5d5970, 'GUESS release member then slot 0x110(0x10, 0)', 'thiscall', None, ret='eax', gen=g5d5970, note='batch31084')
S(0x463320, 'GUESS two vtable calls with the same args', 'thiscall', None, ret='eax', gen=g463320, note='batch31084')
S(0x4739e0, 'GUESS clamp index, call slot 0x230 with member', 'thiscall', None, ret='eax', gen=g4739e0, note='batch31084')
S(0x47fbe0, 'GUESS shutdown and delete member', 'thiscall', None, ret='eax', gen=g47fbe0, note='batch31084')
S(0x520d50, 'GUESS set state, ask slot 0x310, reset on false', 'thiscall', None, ret='eax', gen=g520d50, note='batch31084')
S(0x5968c0, 'GUESS 594040, 593f40, 596d70 chain', 'thiscall', None, ret='eax', gen=g5968c0, note='batch31084')
