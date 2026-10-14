"""specs_s33033.py - h3 batch 33033: four tier B call+field functions. Callees hooked: 0x436060, 0x5003d0, 0x655a60."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _me(c, n=0x80):
    return rnd(c, n)


def _g429200(c):
    clear_hooks(c)
    hook_rec(c, 0x436060, 1, this=True)
    return [_me(c, 0x200)]


def _g51e910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ret_func(e2, res_):
        # Return a pointer to a heap dword
        ptr = e.alloc(4)
        e.w32(ptr, r.getrandbits(32))
        e2.ret(eax=ptr)

    hook_rec(c, 0x5003d0, 1, this=True, side=ret_func)
    me = obj(c, 0x300, {0x18: e.alloc(0x280)})
    arg = obj(c, 0x8, {4: r.getrandbits(32)})
    return [me, arg]


def _g55c770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ret_func(e2, res_):
        # Return a pointer to a heap dword
        ptr = e.alloc(4)
        e.w32(ptr, r.getrandbits(32))
        e2.ret(eax=ptr)

    hook_rec(c, 0x5003d0, 1, this=True, side=ret_func)
    me = obj(c, 0x300, {0x1c: e.alloc(0xa00)})
    arg = obj(c, 0x8, {4: r.getrandbits(32)})
    return [me, arg]


def _g656de0(c):
    clear_hooks(c)
    hook_rec(c, 0x655a60, 1, this=True)
    return [_me(c, 0x200)]


S(0x429200, 'GUESS call + field init', 'thiscall', None, ret='al', gen=_g429200, note='batch33033')
S(0x51e910, 'GUESS call + deref + field store', 'thiscall', None, ret='eax', gen=_g51e910, note='batch33033')
S(0x55c770, 'GUESS call + deref + field store', 'thiscall', None, ret='eax', gen=_g55c770, note='batch33033')
S(0x656de0, 'GUESS call + vtable set', 'thiscall', None, ret='eax', gen=_g656de0, note='batch33033')
