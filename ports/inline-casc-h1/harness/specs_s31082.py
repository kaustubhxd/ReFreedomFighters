"""specs_s31082.py - Sonnet h1 batch 31082."""
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


def g467710(c):
    clear_hooks(c)
    hk(c, 0x466220, 0)
    me = obj(c, 0x200, {0x3dc: st(c, 0, clob=True), 0x414: st(c, 0)})
    return [me]


def g471f60(c):
    clear_hooks(c)
    hk(c, 0x468080, 0, clob=False)
    me = rnd(c, 0x400)
    c.emu.w32(me + 0x3b7, 0 if c.rng.random() < 0.3 else obj(c, 0x10, {0: st(c, 1, clob=True)}))
    return [me]


def g4c59d0(c):
    clear_hooks(c)
    me = rnd(c, 0x80)
    a = obj(c, 0x40, {0x68: st(c, 1)})
    return [me, a]


def g4ecb00(c):
    clear_hooks(c)
    me = obj(c, 0x1b0, {0x14: st(c, 6)})
    return [me] + [r32(c) for _ in range(5)]


def g52cf10(c):
    clear_hooks(c)
    sysobj(c, slots={0x1c8: st(c, 2)})
    return [rnd(c, 0x20)]


def g659b10(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0xe4: st(c, 1)})
    return [me, rnd(c, 0x30)]


def g431760(c):
    clear_hooks(c)
    hk(c, 0x4cbec0, 0)
    hk(c, 0x61ba60, 0, clob=False)
    return [rnd(c, 0x200)]


def g466360(c):
    clear_hooks(c)
    hk(c, 0x4620d0, 1, pop=4)
    me = obj(c, 0x340, {0x32c: st(c, 1)})
    return [me, r32(c)]


def g46b700(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x4711f0, 2, pop=8, clob=False)
    me = obj(c, 0xd0, {0x35c: st(c, 0, ret=r.choice([0, 1, r32(c)]), clob=True)})
    return [me]


def g475980(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x300, {0x2d0: st(c, 2)})
    me = obj(c, 0x510, {0x500: st(c, 0, ret=r.choice([0, o2, o2]))})
    return [me, r32(c)]


def g4e0e60(c):
    clear_hooks(c)
    sysobj(c, slots={0x144: st(c, 2)})
    return [r32(c), r32(c)]


def g5c7f10(c):
    clear_hooks(c)
    a = obj(c, 0x80, {0x6c: st(c, 1)})
    return [rnd(c, 0x40), a]


S(0x467710, 'GUESS two vtable calls, reset member', 'thiscall', None, ret='eax', gen=g467710, note='batch31082')
S(0x471f60, 'GUESS vtable 6890a4, release member, tail 468080', 'thiscall', None, ret='eax', gen=g471f60, note='batch31082')
S(0x4c59d0, 'GUESS clear flag 0x40, call slot 0x68 of arg with this+0x4c', 'thiscall', None, ret='al', gen=g4c59d0, note='batch31082')
S(0x4ecb00, 'GUESS forward 5 args plus member to vtable slot 0x14', 'thiscall', None, ret='eax', gen=g4ecb00, note='batch31082')
S(0x52cf10, 'GUESS member from sysobj slot 0x1c8', 'thiscall', None, ret='eax', gen=g52cf10, note='batch31082')
S(0x659b10, 'GUESS store vtable 0xe4 result in arg+0x14, true', 'thiscall', None, ret='al', gen=g659b10, note='batch31082')
S(0x431760, 'GUESS 4cbec0 on four members, tail 61ba60', 'thiscall', None, ret='eax', gen=g431760, note='batch31082')
S(0x466360, 'GUESS 4620d0 then vtable 0x32c(1)', 'thiscall', None, ret='eax', gen=g466360, note='batch31082')
S(0x46b700, 'GUESS conditional 4711f0 and flag', 'thiscall', None, ret='eax', gen=g46b700, note='batch31082')
S(0x475980, 'GUESS call slot 0x2d0 of looked-up object', 'thiscall', None, ret='eax', gen=g475980, note='batch31082')
S(0x4e0e60, 'GUESS sysobj slot 0x144(a, b), return a', 'stdcall', None, ret='eax', gen=g4e0e60, note='batch31082')
S(0x5c7f10, 'GUESS call slot 0x6c of arg with this+0x1d, true', 'thiscall', None, ret='al', gen=g5c7f10, note='batch31082')
