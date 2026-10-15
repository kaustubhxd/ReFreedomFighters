"""specs_s31090.py - Sonnet h1 batch 31090."""
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


def g564fd0(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x562c20, 1, pop=4, clob=False)
    me = obj(c, 0x110, {0x100: st(c, 1)})
    c.emu.w32(me + 0xdc, r.choice([2, 2, 2, 0, 3, r32(c)]))
    return [me, r.choice([0x457, 0x8ae, 0xd05, 0x456, 0, r32(c)])]


def g654d00(c):
    clear_hooks(c)
    sysobj(c)
    me = obj(c, 0x240, {0x230: st(c, 3)})
    return [me, r32(c), r32(c), r32(c)]


def g465890(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x461760, 3, pop=0xc, clob=False)
    mem = obj(c, 0x80, {0x54: st(c, 4, ret=r.choice([0, 1, 0x100, 0x101]), clob=True)})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6c, mem)
    return [me, r32(c), r32(c), r32(c)]


def g4b1c20(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c, table_slots={0xa8: st(c, 0, clob=True), 0xa0: st(c, 1)})
    c.emu.w32(so + 0x1907, obj(c, 0x40, {0x2c: st(c, 2, ret=r.choice([0, 1, 0x100, 0x101]))}))
    return [rnd(c, 0x60)]


def g4f75a0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x380, {0x36c: st(c, 1, clob=True), 0x370: st(c, 0)})
    c.emu.w32(me + 0x93, r.choice([0, r32(c)]))
    a = rnd(c, 0x10)
    return [me, a]


def g571bf0(c):
    clear_hooks(c)
    O = obj(c, 0x100, {0x7c: st(c, 0, clob=True), 0x84: st(c, 0, clob=True), 0x8c: st(c, 0)})
    sysobj(c, slots={0xbc: st(c, 0, ret=O)})
    return [rnd(c, 0x1a0)]


def g5c3d90(c):
    clear_hooks(c)
    a = obj(c, 0x80, {0x68: st(c, 1, clob=True), 0x40: st(c, 1)})
    return [rnd(c, 0x60), a]


def g655b40(c):
    clear_hooks(c)
    r = c.rng
    O2 = obj(c, 0x40, {0x14: st(c, 1)})
    so = sysobj(c)
    c.emu.w32(so + 0x190f, obj(c, 0x40, {0x20: st(c, 0, ret=O2)}))
    return [r.choice([0, 1, 5, 0x40000000, 0x10, r32(c)])]


S(0x564fd0, 'GUESS state 2 and magic id -> slot 0x100, else tail 562c20', 'thiscall', None, ret='eax', gen=g564fd0, note='batch31090')
S(0x654d00, 'GUESS slot 0x230 then set/clear sysobj flag bits', 'thiscall', None, ret='eax', gen=g654d00, note='batch31090')
S(0x465890, 'GUESS member slot 0x54 gate, else 461760', 'thiscall', None, ret='eax', gen=g465890, note='batch31090')
S(0x4b1c20, 'GUESS gate on sysobj member slot 0x2c then two table slots', 'thiscall', None, ret='eax', gen=g4b1c20, note='batch31090')
S(0x4f75a0, 'GUESS copy two dwords then optional slot 0x36c and slot 0x370', 'thiscall', None, ret='eax', gen=g4f75a0, note='batch31090')
S(0x571bf0, 'GUESS three getters via sysobj slot 0xbc object', 'thiscall', None, ret='eax', gen=g571bf0, note='batch31090')
S(0x5c3d90, 'GUESS clear flag, two arg slots with member addresses, true', 'thiscall', None, ret='al', gen=g5c3d90, note='batch31090')
S(0x655b40, 'GUESS global member slot 0x20 then 0x14 with size n*4', 'stdcall', None, ret='eax', gen=g655b40, note='batch31090')
