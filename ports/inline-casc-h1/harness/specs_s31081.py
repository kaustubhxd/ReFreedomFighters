"""specs_s31081.py - batch 31081."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False):
    """Slot stub (callee pops n args, records ECX); optionally clobbers ECX."""
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, this=True, side=side)


def g4d1e10(c):
    clear_hooks(c)
    P = rnd(c, 0x10)
    me = obj(c, 0x40, {0x3c: st(c, 1, ret=P)})
    return [me, r32(c)]


def g551080(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x18: st(c, 1)})
    return [a, r32(c)]


def g656760(c):
    clear_hooks(c)
    P = rnd(c, 0x10)
    me = obj(c, 0x40, {0xc: st(c, 1, ret=P)})
    return [me, r32(c)]


def g607910(c):
    clear_hooks(c)
    hook_rec(c, 0x504880, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k, j=r32(c): emu.mu.reg_write(REGS['ecx'], j))
    return [obj(c, 0x40, {0x9c: st(c, 1)})]


def g466d90(c):
    clear_hooks(c)
    so = sysobj(c, table_size=0xae8)
    tab = c.emu.r32(so + 0x9b)
    c.emu.w32(tab + 0xadc, obj(c, 0x20, {0x25c: st(c, 2)}))
    c.emu.w32(0x7003b8, rnd(c, 0x4c0))
    return [rnd(c, 0x10)]


def g472fd0(c):
    clear_hooks(c)
    hook_rec(c, 0x465fd0, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k, j=r32(c): emu.mu.reg_write(REGS['ecx'], j))
    me = obj(c, 0x300, {0x104: st(c, 1)})
    return [me]


def g4d1dd0(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0x10: st(c, 1)})
    c.emu.w32(me + 0xc, rnd(c, 0x10))
    return [me]


def g566ee0(c):
    clear_hooks(c)
    hook_rec(c, 0x5672c0, 1, ret=r32(c), pop=4, this=True, side=lambda emu, k, j=r32(c): emu.mu.reg_write(REGS['ecx'], j))
    return [obj(c, 0x1c0, {0xd0: st(c, 1)})]


def g425150(c):
    clear_hooks(c)
    hook_rec(c, 0x42ad20, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x28, 0 if c.rng.random() < 0.3 else obj(c, 0x10, {0: st(c, 1, clob=True)}))
    return [me]


def g467f60(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0x408: st(c, 0, clob=True), 0x404: st(c, 0, clob=True), 0x40c: st(c, 0)})
    return [me, r32(c)]


def g470bf0(c):
    clear_hooks(c)
    o2 = obj(c, 0x20, {0x358: st(c, 1)})
    me = obj(c, 0x100, {0x350: st(c, 0, ret=o2, clob=True)})
    return [me]


def g51d0d0(c):
    clear_hooks(c)
    me = obj(c, 0x500, {0x2e8: st(c, 1)})
    if c.rng.random() < 0.5:
        c.emu.w32(me + 0x499, 0)
    return [me]


def g5c2c80(c):
    clear_hooks(c)
    o2 = obj(c, 0x20, {0x5c: st(c, 3)})
    sysobj(c, table_slots={0x134: st(c, 0, ret=o2)})
    return [rnd(c, 0x10)]


S(0x4d1e10, 'GUESS vtable 0x3c call, deref result', 'thiscall', None, ret='eax', gen=g4d1e10, note='batch31081')
S(0x551080, 'GUESS call slot 0x18 of first arg with second', 'stdcall', None, ret='eax', gen=g551080, note='batch31081')
S(0x656760, 'GUESS vtable 0xc call, word at +2', 'thiscall', None, ret='eax', gen=g656760, note='batch31081')
S(0x607910, 'GUESS 504880 then vtable 0x9c(1)', 'thiscall', None, ret='eax', gen=g607910, note='batch31081')
S(0x466d90, 'GUESS table member slot 0x25c result into global', 'thiscall', None, ret='eax', gen=g466d90, note='batch31081')
S(0x472fd0, 'GUESS 465fd0 then vtable 0x104 result stored', 'thiscall', None, ret='eax', gen=g472fd0, note='batch31081')
S(0x4d1dd0, 'GUESS vtable 0x10(0), masked member field', 'thiscall', None, ret='eax', gen=g4d1dd0, note='batch31081')
S(0x566ee0, 'GUESS 5672c0(member), vtable 0xd0(0)', 'thiscall', None, ret='eax', gen=g566ee0, note='batch31081')
S(0x425150, 'GUESS release member then tail 42ad20', 'thiscall', None, ret='eax', gen=g425150, note='batch31081')
S(0x467f60, 'GUESS three vtable calls, last is a tail', 'thiscall', None, ret='eax', gen=g467f60, note='batch31081')
S(0x470bf0, 'GUESS chained vtable calls updating member', 'thiscall', None, ret='eax', gen=g470bf0, note='batch31081')
S(0x51d0d0, 'GUESS lazy member via vtable 0x2e8', 'thiscall', None, ret='eax', gen=g51d0d0, note='batch31081')
S(0x5c2c80, 'GUESS global table slot 0x134 then member slot 0x5c', 'thiscall', None, ret='eax', gen=g5c2c80, note='batch31081')
