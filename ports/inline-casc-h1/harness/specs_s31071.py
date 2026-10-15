"""specs_s31071.py - Sonnet h1 batch 31071: tier B call-through thunks."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5c7c80(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5ea0, 0, ret=r32(c), pop=0, this=True)
    hook_rec(c, 0x4e5e40, 0, ret=r32(c), pop=0, this=True)
    return [rnd(c, 0x60), rnd(c, 0x20), r32(c)]


def g62f120(c):
    clear_hooks(c)
    hook_rec(c, 0x62ef10, 8, ret=r32(c), pop=0x20)
    return [r32(c), r32(c), r32(c), r32(c)]


def g42ac71(c):
    clear_hooks(c)
    pair = rnd(c, 8)
    hook_rec(c, 0x42acb5, 5, ret=pair, pop=0)
    hook_rec(c, 0x634d82, 2, ret=r32(c), pop=0)
    return [r32(c), r32(c), r32(c), r32(c)]


def g51ec40(c):
    clear_hooks(c)
    blk = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, ret=blk, pop=4, this=True)
    me = rnd(c, 0x40)
    tgt = rnd(c, 0x360)
    c.emu.w32(me + 0x18, tgt)
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 4, rnd(c, 0x20))
    return [me, arg]


def g5cfae0(c):
    clear_hooks(c)
    hook_rec(c, 0x5cfd90, 1, ret=c.rng.choice([0, 1, 0x100, 0x101, r32(c)]), pop=4, this=True, side=_clob(c))
    hook_rec(c, 0x5cfb10, 1, ret=r32(c), pop=4, this=True)
    return [rnd(c, 0x40), r32(c)]


def _dtor(callee, size):
    def g(c):
        clear_hooks(c)
        if callee:
            hook_rec(c, callee, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
        hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
        return [rnd(c, 0x40), c.rng.choice([0, 1, 2, 3, r32(c)])]
    return g


S(0x5c7c80, 'GUESS member getters from arg', 'thiscall', None, ret='eax', gen=g5c7c80, note='batch31071')
S(0x62f120, 'GUESS call 62ef10 with constants', 'stdcall', None, ret='eax', gen=g62f120, note='batch31071')
S(0x42ac71, 'GUESS call 42acb5 then 634d82 with its pair', 'cdecl', None, ret='eax', gen=g42ac71, note='batch31071')
S(0x51ec40, 'GUESS store 5003d0 lookup into member', 'thiscall', None, ret='eax', gen=g51ec40, note='batch31071')
S(0x5cfae0, 'GUESS call 5cfd90, else 5cfb10', 'thiscall', None, ret='eax', gen=g5cfae0, note='batch31071')
S(0x485f00, 'GUESS set vtable 685294, optional delete 0x1c', 'thiscall', None, ret='eax', gen=_dtor(None, 0x1c), note='batch31071')
S(0x4cd2d0, 'GUESS call 4ccf60, optional delete 0xac', 'thiscall', None, ret='eax', gen=_dtor(0x4ccf60, 0xac), note='batch31071')
S(0x52d190, 'GUESS call 52d080, optional delete 0xd1e', 'thiscall', None, ret='eax', gen=_dtor(0x52d080, 0xd1e), note='batch31071')
