"""specs_s31073.py - batch 31073."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def _ctor(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
    return [rnd(c, 0x60)]


def _dtor(base):
    def g(c):
        clear_hooks(c)
        if base:
            hook_rec(c, base, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
        hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
        return [rnd(c, 0x40), c.rng.choice([0, 1, 2, 3, r32(c)])]
    return g


def g5f9570(c):
    clear_hooks(c)
    vals = [r32(c), r32(c)]
    hook_rec(c, 0x605b90, 0, ret=lambda emu, k: vals[min(k, 1)], pop=0, this=True, side=_clob(c))
    me = rnd(c, 0x60)
    return [me]


def g47fd30(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=_clob(c))      # callee clobbers ECX, the tail jump must restore this
    hook_rec(c, 0x43de70, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0xa0)
    if c.rng.random() < 0.7:
        inner = rnd(c, 0x10)
        c.emu.w32(me + 0x8c, inner)
    else:
        c.emu.w32(me + 0x8c, 0)
    return [me]


def g5aefc0(c):
    clear_hooks(c)
    hook_rec(c, 0x5af040, 1, ret=c.rng.choice([0, 1, 3, 7, 8, 8]), pop=4, this=True)
    return [rnd(c, 0x60), r32(c)]


def g5e9b40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ab130, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x5e9b70, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x1d20)
    if r.random() < 0.85:
        inner = rnd(c, 0x400)
        c.emu.wbytes(inner + 0x3c6, bytes([r.choice([0, 1, 7])]))
        c.emu.w32(me + 0x1d0f, inner)
    else:
        c.emu.w32(me + 0x1d0f, 0)
    return [me, r32(c)]


S(0x5d5c90, 'GUESS ctor base 469870, vtable 6b58c8', 'thiscall', None, ret='eax', gen=_ctor, note='batch31073')
S(0x5dd5e0, 'GUESS ctor base 469870, vtable 6b6e38', 'thiscall', None, ret='eax', gen=_ctor, note='batch31073')
S(0x5df850, 'GUESS vtable 685294, optional delete 0x14', 'thiscall', None, ret='eax', gen=_dtor(None), note='batch31073')
S(0x5f9570, 'GUESS sum of span and two sizes', 'thiscall', None, ret='eax', gen=g5f9570, note='batch31073')
S(0x6580e0, 'GUESS call 658020, optional delete 0x11e7', 'thiscall', None, ret='eax', gen=_dtor(0x658020), note='batch31073')
S(0x47fd30, 'GUESS free member buffers then tail 43de70', 'thiscall', None, ret='eax', gen=g47fd30, note='batch31073')
S(0x534d30, 'GUESS vtable 6a1a60, call 4e66a0, optional delete 0xd', 'thiscall', None, ret='eax', gen=_dtor(0x4e66a0), note='batch31073')
S(0x5aefc0, 'GUESS indexed member by 5af040 lookup', 'thiscall', None, ret='eax', gen=g5aefc0, note='batch31073')
S(0x5e9b40, 'GUESS conditional 5ab130 then 5e9b70', 'thiscall', None, ret='eax', gen=g5e9b40, note='batch31073')
