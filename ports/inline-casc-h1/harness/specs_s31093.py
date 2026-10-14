"""specs_s31093.py - batch 31093."""
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


def g57bcb0(c):
    clear_hooks(c)
    val = r32(c)

    skip = c.rng.random() < 0.4      # sometimes the callee leaves the local alone, exposing its initial value

    def put(emu, k):
        if not skip:
            emu.w32(emu.arg32(1), val)
    hk(c, 0x563510, 1, pop=4)
    o2 = obj(c, 0x100, {0x88: st(c, 2, side2=put)})
    sysobj(c, table_slots={0x138: st(c, 0, ret=o2)})
    return [rnd(c, 0xcc0)]


def g6057a0(c):
    clear_hooks(c)
    hk(c, 0x5fa590, 2, pop=8)
    b = obj(c, 0x40, {0: st(c, 1, clob=True)})
    a = obj(c, 0x40, {0x2c: st(c, 1)})
    return [rnd(c, 0x20), a, b]


def g6566e0(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    blk = rnd(c, 0x40)
    c.emu.w32(blk + 0x20, r.choice([0, 0, r32(c), 1]))
    c.emu.w32(so + 0x1aa3, blk)
    o2 = obj(c, 0x40, {0x2c: st(c, 2, pop=0)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: st(c, 2, ret=o2)}))
    return [r32(c)]


S(0x57bcb0, 'GUESS 563510, table slot 0x138 object slot 0x88 fills field', 'thiscall', None, ret='eax', gen=g57bcb0, note='batch31093')
S(0x6057a0, 'GUESS 5fa590 then arg slots chained', 'thiscall', None, ret='eax', gen=g6057a0, note='batch31093')
S(0x6566e0, 'GUESS global offset or log error', 'stdcall', None, ret='eax', gen=g6566e0, note='batch31093')
