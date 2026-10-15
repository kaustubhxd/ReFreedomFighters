"""specs_s31088.py - Sonnet h1 batch 31088."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, pop=None, side2=None):
    j = r32(c)

    def side(emu, k):
        if side2:
            side2(emu, k)
        if clob:
            emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side if (clob or side2) else None)


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g45fa70(c):
    clear_hooks(c)
    r = c.rng
    O = rnd(c, 0x20)
    sysobj(c, table_slots={0x58: st(c, 1, ret=r.choice([0, O, O]))})
    me = obj(c, 0x140, {0x130: st(c, 3)})
    return [me, r32(c), r32(c), r32(c)]


def g474470(c):
    clear_hooks(c)
    r = c.rng
    O = obj(c, 0x200, {0x1e0: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101]))})
    me = rnd(c, 0x300)
    sub = obj(c, 0x40, {0x10: st(c, 0, ret=r.choice([0, O, O]))})
    c.emu.w32(me + 0x2e7, c.emu.r32(sub))        # the sub-object embedded at +0x2e7 starts with its vtable pointer
    return [me]


def g47fa50(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x45fc70, 1, pop=4)
    O = obj(c, 0x80, {0x6c: st(c, 1)})
    sysobj(c, table_slots={0x58: st(c, 1, ret=r.choice([0, O, O]))})
    return [rnd(c, 0x40), r32(c)]


def g49cb80(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x4e6bf0, 1, pop=4)
    a = rnd(c, 0x80)
    c.emu.w32(a + 0x68, r.randrange(0, 6))

    def mod(emu, k):
        emu.w32(emu.arg32(0) + 0x68, r.randrange(0, 6))
    me = obj(c, 0x40, {0x10: st(c, 1, side2=mod if r.random() < 0.5 else None)})
    c.emu.w32(me + 0x1d, rnd(c, 0x40))
    c.emu.w32(me + 0x2d, rnd(c, 0x10))
    return [me, a]


def g4b07c0(c):
    clear_hooks(c)
    a = obj(c, 0x100, {0x44: st(c, 1, clob=True), 0x3c: st(c, 1)})
    return [rnd(c, 0x100), a]


def g4e8380(c):
    clear_hooks(c)
    blk = rnd(c, 0x40)
    mem = obj(c, 0x40, {4: st(c, 1, ret=blk + 8)})
    me = obj(c, 0x40, {0: st(c, 1)})
    c.emu.w32(me + 0x1d, mem)
    return [me, r32(c), r32(c)]


def g5f3fc0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    c.emu.w32(me, obj(c, 0x40, {0x28: st(c, 0)}))
    c.emu.wbytes(me + 4, bytes([r.choice([0, 4, 4, 1, 3])]))
    a = obj(c, 0x40, {0x24: st(c, 0)})
    return [me, a]


def g476a20(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x43f8c0, 1, pop=4)
    a = obj(c, 0x80, {0x1e0: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101]))})
    return [rnd(c, 0x80), a]


S(0x45fa70, 'GUESS table slot 0x58 lookup then slot 0x130', 'thiscall', None, ret='eax', gen=g45fa70, note='batch31088')
S(0x474470, 'GUESS member slot 0x10 then 0x1e0 check', 'thiscall', None, ret='eax', gen=g474470, note='batch31088')
S(0x47fa50, '45fc70, table slot 0x58 then tail slot 0x6c', 'thiscall', None, ret='eax', gen=g47fa50, note='batch31088')
S(0x49cb80, 'slot 0x10, 4e6bf0 on member, clear +0x68', 'thiscall', None, ret='eax', gen=g49cb80, note='batch31088')
S(0x4b07c0, 'clear flag, two slots on arg, true', 'thiscall', None, ret='al', gen=g4b07c0, note='batch31088')
S(0x4e8380, 'slot 4 result minus 4 filled and passed to slot 0', 'thiscall', None, ret='eax', gen=g4e8380, note='batch31088')
S(0x5f3fc0, 'state byte, release old then set from arg slot 0x24', 'thiscall', None, ret='eax', gen=g5f3fc0, note='batch31088')
S(0x476a20, '43f8c0 then copy +0x5c if slot 0x1e0 true', 'thiscall', None, ret='eax', gen=g476a20, note='batch31088')
