"""specs_s31070.py - batch 31070: tier B call-through thunks."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def g4d3a20(c):
    clear_hooks(c)
    hook_rec(c, 0x4d24e0, 4, ret=r32(c), pop=0x10, deref={1: 1})
    return [r32(c), r32(c)]


def _getter(off):
    def g(c):
        clear_hooks(c)
        hook_rec(c, 0x4e5e60, 0, ret=r32(c), pop=0, this=True)
        return [rnd(c, 0x200), r32(c)]
    return g


def g42ab49(c):
    clear_hooks(c)
    hook_rec(c, 0x42ab26, 4, ret=r32(c), pop=0, deref={3: 1})
    return [r32(c), r32(c), r32(c)]


def g497450(c):
    clear_hooks(c)
    blk = rnd(c, 0x80)
    hook_rec(c, 0x4973b0, 1, ret=c.rng.choice([0, blk]), pop=4)
    return [r32(c)]


def g4d3b10(c):
    clear_hooks(c)
    hook_rec(c, 0x4d2700, 5, ret=r32(c), pop=0x14, deref={3: 1})
    return [r32(c), r32(c), r32(c)]


def g533d20(c):
    clear_hooks(c)
    j = r32(c)
    hook_rec(c, 0x534190, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k: emu.mu.reg_write(REGS['ecx'], j))   # callee clobbers ECX
    return [rnd(c, 0x1020)]


def g480620(c):
    clear_hooks(c)
    j = r32(c)
    hook_rec(c, 0x45f3c0, 1, ret=r32(c), pop=4, this=True, side=lambda emu, k: emu.mu.reg_write(REGS['ecx'], j))
    hook_rec(c, 0x4805a0, 0, ret=r32(c), pop=0, this=True)
    return [rnd(c, 0x40), r32(c)]


def g4d3d90(c):
    clear_hooks(c)
    hook_rec(c, 0x4d2700, 5, ret=r32(c), pop=0x14)
    return [r32(c), r32(c), c.rng.choice([r32(c), 3, 0, 0x40000000]), r32(c)]


def g628eb0(c):
    clear_hooks(c)
    hook_rec(c, 0x628c80, 6, ret=r32(c), pop=0)
    return [r32(c), r32(c), r32(c), r32(c)]


def g536c40(c):
    clear_hooks(c)
    so = sysobj(c, table_size=0xae8)
    tab = c.emu.r32(so + 0x9b)
    c.emu.w32(tab + 0xadc, r32(c))
    hook_rec(c, 0x445c50, 0, ret=r32(c), pop=0, this=True)
    return [c.rng.choice([0, 0, r32(c), 0x20000200])]


S(0x4d3a20, 'GUESS call 4d24e0(a, 2, &b, 0)', 'stdcall', None, ret='eax', gen=g4d3a20, note='batch31070')
S(0x57c1d0, 'GUESS this+0x180 = 4e5e60(arg)', 'thiscall', None, ret='eax', gen=_getter(0x180), note='batch31070')
S(0x5d9180, 'GUESS this+0x54 = 4e5e60(arg)', 'thiscall', None, ret='eax', gen=_getter(0x54), note='batch31070')
S(0x42ab49, 'GUESS call 42ab26(a, b, 0, &c)', 'cdecl', None, ret='eax', gen=g42ab49, note='batch31070')
S(0x497450, 'GUESS field 0x54 of 4973b0 lookup', 'stdcall', None, ret='eax', gen=g497450, note='batch31070')
S(0x4d3b10, 'GUESS call 4d2700(a, 8, c, &b, 0)', 'stdcall', None, ret='eax', gen=g4d3b10, note='batch31070')
S(0x533d20, 'GUESS zero fields then call 534190', 'thiscall', None, ret='eax', gen=g533d20, note='batch31070')
S(0x480620, 'GUESS call 45f3c0(arg) then 4805a0, true', 'thiscall', None, ret='al', gen=g480620, note='batch31070')
S(0x4d3d90, 'GUESS call 4d2700(a, 8, d, b, c*4)', 'stdcall', None, ret='eax', gen=g4d3d90, note='batch31070')
S(0x628eb0, 'GUESS call 628c80(table, a, 0, b, c, d)', 'cdecl', None, ret='eax', gen=g628eb0, note='batch31070')
S(0x536c40, 'GUESS null arg -> global table field, else call 445c50', 'stdcall', None, ret='eax', gen=g536c40, note='batch31070')
