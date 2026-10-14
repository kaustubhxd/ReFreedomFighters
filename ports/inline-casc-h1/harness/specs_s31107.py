"""specs_s31107.py - batch 31107."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g46ce40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f900, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x4e12e0, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    hook_rec(c, 0x4e11d0, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    hook_rec(c, 0x4e1b30, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    return [rnd(c, 0xa0), rnd(c, 0x20)]


def g4fa1d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f080, 1, ret=r32(c), pop=4, this=True)
    o = r.choice([0, obj(c, 0x40, {0x2f4: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x100)])
    me = obj(c, 0x80, {0x2c4: pystub(c, 0, ret=o, this=True, side=clob(c))}, nslots=0x100)
    c.emu.w32(me + 0x6c, r32(c))
    return [me, r.choice([0, 1, 0x100, 0xff, r32(c)])]


def g5a45c0(c):
    clear_hooks(c)
    r = c.rng
    a = obj(c, 0x700, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, r32(c)]), this=True)}, nslots=0x100)
    c.emu.w32(a + 0x684, r.choice([0, 1, 2, 3, 4, 5, 6, r32(c)]))
    return [rnd(c, 0x100), r.choice([a, a, a, 0])]


S(0x46ce40, 'GUESS init chain 43f900 then 4e12e0/4e1b30/4e11d0 on this+0x60,0x8e,0x92', 'thiscall', None, ret='eax', gen=g46ce40, note='batch31107')
S(0x4fa1d0, 'GUESS toggle: slot 0x2c4 / 45f080 and flag bit 0 at +0x6c', 'thiscall', None, ret='eax', gen=g4fa1d0, note='batch31107')
S(0x5a45c0, 'GUESS slot 0x1e0 check then address of entry (count<<4)+0x99', 'thiscall', None, ret='eax', gen=g5a45c0, note='batch31107')
