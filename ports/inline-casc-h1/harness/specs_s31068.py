"""specs_s31068.py - batch 31068."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec
from pe_emu import REGS


def r32(c):
    return c.rng.getrandbits(32)


def _args(c, me, extra=()):
    return [me] + list(extra)


def g5f28d0(c):
    clear_hooks(c)
    hook_rec(c, 0x604d30, 2, ret=r32(c), pop=0, this=True)
    hook_rec(c, 0x6038e0, 2, ret=r32(c), pop=0, this=True)
    return [rnd(c, 0x40), r32(c), r32(c)]


def _flag_call(callee):
    def g(c):
        clear_hooks(c)
        hook_rec(c, callee, 0, ret=r32(c), pop=0, this=True)
        return [rnd(c, 0x40), r32(c)]
    return g


def g4c1e20(c):
    clear_hooks(c)
    hook_rec(c, 0x4c0a90, 1, ret=r32(c), pop=4, this=True)
    return [rnd(c, 0x40), r32(c), r32(c)]


def g4ce850(c):
    clear_hooks(c)
    hook_rec(c, 0x41e290, 1, ret=r32(c), pop=0)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x10, c.rng.choice([0, 1, 7, r32(c)]))
    return [me]


def _two(first, second):
    def g(c):
        clear_hooks(c)
        junk = r32(c)
        hook_rec(c, first, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k, j=junk: emu.mu.reg_write(REGS['ecx'], j))  # the callee clobbers ECX
        hook_rec(c, second, 2, ret=r32(c), pop=0, this=True)
        return [rnd(c, 0x40), r32(c), r32(c)]
    return g


def g4625c0(c):
    clear_hooks(c)
    r = c.rng
    n = r.randrange(1, 6)
    me = rnd(c, 0x40)
    recs = rnd(c, 0x18 * 6)
    for i in range(n):
        fl = c.emu.r32(recs + 0x18 * i + 4)
        c.emu.w32(recs + 0x18 * i + 4, (fl & ~8) | (8 if r.random() < 0.35 else 0))
    c.emu.w32(me + 0x1c, recs)
    c.emu.w32(me + 0x20, n)
    return [me, r.randrange(0, n), r.choice([0, 1, 2, 0x100, 0x1ff, r32(c)])]


def g478640(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x700)
    c.emu.w32(me + 0x6ce, r.choice([0, r32(c)]))
    c.emu.w32(me + 0x64c, r.choice([10, 10, 0, r32(c)]))
    if r.random() < 0.1:
        c.emu.w32(me + 0x695, 0)
        return [me]
    lst = rnd(c, 0x40)
    c.emu.w32(me + 0x695, lst)
    c.emu.w32(lst + 0x10, r.choice([0, 1, 1, 1]))
    cnt = r.randrange(0, 8)
    c.emu.w32(lst + 8, cnt)
    c.emu.w32(lst + 0xc, rnd(c, 0x100))
    arr = c.emu.alloc(4 * 10, 4)
    for i in range(10):
        c.emu.w32(arr + 4 * i, 0 if r.random() < 0.5 else rnd(c, 0x40))
    c.emu.w32(lst + 0x14, arr)
    return [me]


S(0x5f28d0, 'GUESS call 604d30 then tail 6038e0', 'thiscall', None, ret='eax', gen=g5f28d0, note='batch31068')
S(0x4bb600, 'GUESS clear flag 0x40, call 4bb550, true', 'thiscall', None, ret='al', gen=_flag_call(0x4bb550), note='batch31068')
S(0x5dbc20, 'GUESS clear flag 0x40, call 5dbc30, true', 'thiscall', None, ret='al', gen=_flag_call(0x5dbc30), note='batch31068')
S(0x4c1e20, 'GUESS forward second arg to 4c0a90', 'thiscall', None, ret='eax', gen=g4c1e20, note='batch31068')
S(0x4ce850, 'GUESS alloc 16 + 4*count', 'thiscall', None, ret='eax', gen=g4ce850, note='batch31068')
S(0x56ba00, 'GUESS call 564b10 then tail 56bd90', 'thiscall', None, ret='eax', gen=_two(0x564b10, 0x56bd90), note='batch31068')
S(0x578d20, 'GUESS call 562260 then tail 578aa0', 'thiscall', None, ret='eax', gen=_two(0x562260, 0x578aa0), note='batch31068')
S(0x4625c0, 'GUESS record flag bit 3 maintain', 'thiscall', None, ret='al', gen=g4625c0, note='batch31068')
S(0x478640, 'GUESS dequeue entry into state', 'thiscall', None, ret=None, gen=g478640, note='batch31068')
