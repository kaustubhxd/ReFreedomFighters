"""specs_s31121.py - batch 31121."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g44d520(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([1, 2, 3, 5, 8])           # count before the decrement
    idx = r.randrange(0, n)
    ents = [rnd(c, 0x20) for _ in range(9)]
    A = rnd(c, 0x40)
    for i in range(9):
        c.emu.w32(A + 4 * i, ents[i])
    o = r.choice([0, obj(c, 0x40, {0x294: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x100)])
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)})
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x1c, n)
    c.emu.w32(me + 0x20, A)
    return [me, idx]


def g4762a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x476bd0, 0, ret=r32(c), pop=0, this=True)
    so = sysobj(c)
    v = r.choice([0, 5, -5 & 0xffffffff, r32(c)])
    c.emu.w32(so + 0x40, v)
    me = rnd(c, 0x80)
    sv = r.choice([v, (v + 1) & 0xffffffff, (v - 1) & 0xffffffff, r32(c), 0, 0xffffffff])
    c.emu.w32(me + 0x52, sv)
    k4e = r.choice([0, 0, 1, 1, 2, r32(c)])
    c.emu.w32(me + 0x4e, k4e)
    flag = r.choice([0, 1, 0x100, r32(c)])
    sub = obj(c, 0x40, {0x210: pystub(c, 1, ret=r32(c), this=True),
                        0x28: pystub(c, 0, ret=r32(c), this=True),
                        0x1e0: pystub(c, 1, ret=flag, this=True)}, nslots=0x100)
    c.emu.w32(me + 0x44, sub if k4e == 0 else r.choice([0, sub, sub]))
    vt = obj(c, 0x20, {0x68: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x40)
    c.emu.w32(me, c.emu.r32(vt))
    return [me]


def g4c0a90(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: r.choice([0, 0, r.getrandbits(32)]), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e5e40, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e6330, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    return [rnd(c, 0x1b8), rnd(c, 0x20)][:0] or [rnd(c, 0x1b8), rnd(c, 0x20)]


def g4d5de0(c):
    clear_hooks(c)
    r = c.rng
    val = r32(c)

    def put(emu, k):
        for i in range(8):
            emu.w32(emu.arg32(1) + 4 * i, (val + i * 0x01010101) & 0xffffffff)
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True)
    hook_rec(c, 0x4d6520, 3, ret=lambda e, k: r.choice([0, 1, 0x100, r.getrandbits(32)]), pop=0xc, deref={1: 8}, side=put)
    c.emu.w32(0x676138, pystub(c, 3, ret=r32(c), pop=12))
    return [r32(c), r32(c)]


S(0x44d520, 'GUESS remove entry idx from slot array, notify sys slot 0x58 obj slot 0x294, swap with last', 'thiscall', None, ret='eax', gen=g44d520, note='batch31121')
S(0x4762a0, 'GUESS timed state step vs global+0x40, slots 0x210/0x68/0x28/0x1e0, tail 476bd0', 'thiscall', None, ret='eax', gen=g4762a0, note='batch31121')
S(0x4c0a90, 'GUESS read fields from stream into this+0x48..0x1ac', 'thiscall', None, ret='al', gen=g4c0a90, note='batch31121')
S(0x4d5de0, '/GS: 4d6520(a,&local,0) then import 0x676138 with local fields', 'stdcall', None, ret='eax', gen=g4d5de0, note='batch31121')
