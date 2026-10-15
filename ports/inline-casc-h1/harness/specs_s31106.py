"""specs_s31106.py - Sonnet h1 batch 31106."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g44bca0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45d5b0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x44bcf0, 1, ret=r32(c), pop=4, this=True)
    g = rnd(c, 0x1b00)
    c.emu.w32(g + 0x1a9f, r.choice([0, 0, r32(c) | 1]))
    c.emu.w32(0x70039c, g)
    other = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, r32(c)]), this=True, side=clob(c))}, nslots=0x100)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, r.choice([0, r32(c) | 1]))
    return [me, other]


def g473910(c):
    clear_hooks(c)
    e = obj(c, 0x40, {0x2d0: pystub(c, 2, ret=r32(c), this=True),
                      0x2f0: pystub(c, 3, ret=r32(c), this=True),
                      0x210: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x200)
    me = obj(c, 0x40, {0x500: pystub(c, 0, ret=e, this=True, side=clob(c)),
                       0x548: pystub(c, 2, ret=r32(c), this=True, side=clob(c))}, nslots=0x200)
    return [me]


def g4b8b50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dcbb0, 1, ret=r32(c), pop=4, this=True)
    o = rnd(c, 0x20)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True, side=clob(c))})
    p = r.choice([0, obj(c, 0x40, {0x290: pystub(c, 4, ret=r32(c), this=True)}, nslots=0x100)])
    me = rnd(c, 0x80)
    b = [p & 0xff, (p >> 8) & 0xff, (p >> 16) & 0xff, p >> 24]
    flag = r.choice([0, 0, 1, 0x80, r.getrandbits(8)])
    c.emu.w32(me + 0x58, flag | b[0] << 8 | b[1] << 16 | b[2] << 24)
    c.emu.w32(me + 0x5c, b[3] | (r32(c) & ~0xff))
    c.emu.w32(me + 0x54, r.choice([1, 1, 0, r32(c)]))
    return [me]


S(0x44bca0, 'GUESS base copy 45d5b0, flag-gated byte copy and 44bcf0', 'thiscall', None, ret='eax', gen=g44bca0, note='batch31106')
S(0x473910, 'GUESS slot 0x500 object then slots 0x548, 0x2d0, 0x2f0, 0x210', 'thiscall', None, ret='eax', gen=g473910, note='batch31106')
S(0x4b8b50, 'GUESS one-shot activate: sys slot 0x58, 4dcbb0, slot 0x290', 'thiscall', None, ret='eax', gen=g4b8b50, note='batch31106')
