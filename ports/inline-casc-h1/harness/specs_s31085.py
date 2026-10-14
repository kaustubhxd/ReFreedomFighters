"""specs_s31085.py - batch 31085."""
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


def g597980(c):
    clear_hooks(c)
    hk(c, 0x593f40, 1, pop=4)
    hk(c, 0x594040, 2, pop=8)
    hk(c, 0x596ef0, 2, pop=8, clob=False)
    return [rnd(c, 0x1d20)]


def g5aa6e0(c):
    clear_hooks(c)
    me = rnd(c, 0x700)
    for i in range(24):
        c.emu.w32(me + 0x4cc + 4 * i, obj(c, 0x40, {8: st(c, 0, clob=True)}))
    return [me]


def g659b60(c):
    clear_hooks(c)
    hk(c, 0x63f4e0, 3, pop=0xc)
    me = obj(c, 0x100, {0xdc: st(c, 1)})
    return [me, r32(c), r32(c), r32(c)]


def g46e410(c):
    clear_hooks(c)
    sysobj(c, table_slots={0x58: st(c, 1)})
    me = rnd(c, 0xb0)
    c.emu.w32(me + 0xa0, obj(c, 0x40, {0x30: st(c, 1, clob=True)}))
    return [me, r32(c)]


def _two(first, slot, field):
    def g(c):
        clear_hooks(c)
        hk(c, first, 1, pop=4)
        me = rnd(c, 0xa0)
        a = obj(c, 0x100, {slot: st(c, 1)})
        return [me, a]
    return g


def _rec(slot, o1, o2):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = obj(c, 0x5310, {slot: st(c, 3)})
        if r.random() < 0.2:
            c.emu.w32(me + 0x5302, 0)
        else:
            P = rnd(c, 0x100)
            off = r.choice([8, 0x10, 0x20, 0x40])
            c.emu.w32(P, off)
            c.emu.w32(me + 0x5302, P)
        return [me, r32(c)]
    return g


S(0x597980, 'GUESS 593f40, 594040 result stored, 596ef0', 'thiscall', None, ret='eax', gen=g597980, note='batch31085')
S(0x5aa6e0, 'GUESS reset 24 member objects via slot 8', 'thiscall', None, ret='eax', gen=g5aa6e0, note='batch31085')
S(0x659b60, 'GUESS 63f4e0 then slot 0xdc(a), true', 'thiscall', None, ret='al', gen=g659b60, note='batch31085')
S(0x46e410, 'GUESS member slot 0x30 result into table slot 0x58', 'thiscall', None, ret='eax', gen=g46e410, note='batch31085')
S(0x46f5d0, 'GUESS 46f520(arg) then arg slot 0x70(this+0x94), true', 'thiscall', None, ret='al', gen=_two(0x46f520, 0x70, 0x94), note='batch31085')
S(0x4706a0, 'GUESS 441790(arg) then arg slot 0x6c(this+0x70), true', 'thiscall', None, ret='al', gen=_two(0x441790, 0x6c, 0x70), note='batch31085')
S(0x5366f0, 'GUESS indirect record fields into slot 0x1ac', 'thiscall', None, ret='eax', gen=_rec(0x1ac, 0x10, 0x28), note='batch31085')
S(0x536870, 'GUESS indirect record fields into slot 0x1b0', 'thiscall', None, ret='eax', gen=_rec(0x1b0, 4, 0x1c), note='batch31085')
