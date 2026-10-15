"""specs_s31074.py - Sonnet h1 batch 31074."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g656e20(c):
    clear_hooks(c)
    hook_rec(c, 0x655a70, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
    return [rnd(c, 0x40), c.rng.choice([0, 1, 2, 3, r32(c)])]


def g4a7960(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
    return [rnd(c, 0x90)]


def _lookup(c, word):
    blk = rnd(c, 0x10)
    c.emu.w32(blk, word)
    hook_rec(c, 0x5003d0, 1, ret=blk, pop=4, this=True)


def _arg_obj(c):
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 4, rnd(c, 0x20))
    return arg


def g51e840(c):
    clear_hooks(c)
    _lookup(c, c.rng.choice([0, 1, 0x100, r32(c)]))
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, obj(c, 0x40, {0x39c: pystub(c, 1, ret=r32(c), this=True)}))
    return [me, _arg_obj(c)]


def g522820(c):
    clear_hooks(c)
    _lookup(c, c.rng.choice([0, 1, 0x100, r32(c)]))
    hook_rec(c, 0x520f20, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, rnd(c, 0x20))
    return [me, _arg_obj(c)]


def g5d0080(c):
    clear_hooks(c)
    hook_rec(c, 0x5cc880, 1, ret=r32(c), pop=4, this=True, side=_clob(c))
    hook_rec(c, 0x5a7530, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0xe30)
    if c.rng.random() < 0.3:
        c.emu.w32(me + 0xe18, 0)
    return [me]


def g5f4600(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5f4630, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x80)
    cap = r.randrange(1, 20)
    size = r.choice([r.randrange(0, cap), cap, cap + 1])
    c.emu.w32(me + 0x4c, rnd(c, 0x100))
    c.emu.w32(me + 0x50, cap)
    c.emu.w32(me + 0x54, size)
    return [me, r32(c)]


def g5a5f00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ebd80, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0x4e0)
    for i in range(12):
        c.emu.w32(me + 0x440 + 4 * i, rnd(c, 0x40))
    for i in range(8):
        c.emu.w32(me + 0x4b8 + 4 * i, rnd(c, 0x10))
    c.emu.w32(me + 0x47c, r.choice([0, 1, 5, 11, 12, 12]))
    return [me, r.randrange(0, 8)]


def g5d8840(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, ret=r32(c), pop=0xc, this=True, side=_clob(c))
    return [rnd(c, 0x60), r32(c), r32(c), r32(c)]


S(0x656e20, 'GUESS vtable 6c3e28, call 655a70, optional delete 4', 'thiscall', None, ret='eax', gen=g656e20, note='batch31074')
S(0x4a7960, 'GUESS ctor base 469870, vtable 690114, clear +72/+76', 'thiscall', None, ret='eax', gen=g4a7960, note='batch31074')
S(0x51e840, 'GUESS flag from 5003d0 lookup to member slot 0x39c', 'thiscall', None, ret='eax', gen=g51e840, note='batch31074')
S(0x522820, 'GUESS flag from 5003d0 lookup into 520f20', 'thiscall', None, ret='eax', gen=g522820, note='batch31074')
S(0x5d0080, 'GUESS reset fields, 5cc880, optional 5a7530', 'thiscall', None, ret=None, gen=g5d0080, note='batch31074')
S(0x5f4600, 'GUESS vector push_back', 'thiscall', None, ret=None, gen=g5f4600, note='batch31074')
S(0x5a5f00, 'GUESS activate next slot with item', 'thiscall', None, ret=None, gen=g5a5f00, note='batch31074')
S(0x5d8840, 'GUESS ctor base 43de40 (3 args), vtable 6b5fc8', 'thiscall', None, ret='eax', gen=g5d8840, note='batch31074')
