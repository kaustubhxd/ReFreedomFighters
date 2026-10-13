"""specs_s2612.py - wider batch 2612: seven small unclaimed functions. Callees hooked (0x49a3e0, 0x6352f0 (writes a random dword through its argument and
records it), 0x4cd0e0, 0x4d1530, 0x634273 (cdecl, 2 args)); the assert hook 0x7003b0 is always set (returns a random EAX); engine slot 0x1907 is a heap object."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _me(c, n=0x80):
    return rnd(c, n)


def _g499980(c):
    clear_hooks(c)
    hook_rec(c, 0x49a3e0, 0, this=True)
    return [_me(c)]


def _g4b5940(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        if r.random() < 0.7:
            em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x6352f0, 1, this=True, nullflag=(0,), side=side)
    me = obj(c, 0x80, {0x88: pystub(c, 1, this=True, deref={0: 1})})
    return [me]


def _g4c7a60(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    if r.random() < 0.75:
        o = obj(c, 0x20, {0xc: pystub(c, 3, this=True)})
        c.emu.wbytes(so + 0x1907, o.to_bytes(4, 'little'))
    else:
        c.emu.wbytes(so + 0x1907, bytes(4))
    return [_me(c)]


def _dtor(base):
    def g(c):
        clear_hooks(c)
        hook_rec(c, base, 0, this=True)
        hook_rec(c, 0x634273, 2, pop=0)
        return [_me(c, 0x40), c.rng.choice([0, 1, 2, 3, 0x100, c.rng.getrandbits(32)])]
    return g


def _g4d53e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = _me(c, 0x20)
    return [me, (me + 4) if r.random() < 0.5 else r.choice([0, me, me + 8, r.getrandbits(32)])]


def _g4d5700(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, pop=0)
    return [_me(c, 0x20), c.rng.choice([0, 1, 2, 3, 0x100, c.rng.getrandbits(32)])]


S(0x499980, 'GUESS vtable set + base step (SEH frame)', 'thiscall', None, ret=None, gen=_g499980, note='batch2612')
S(0x4b5940, 'GUESS clear flag, out-param, slot 0x88', 'thiscall', None, ret=None, gen=_g4b5940, note='batch2612')
S(0x4c7a60, 'GUESS clear fields, engine slot 0xc', 'thiscall', None, ret=None, gen=_g4c7a60, note='batch2612')
S(0x4cd3c0, 'GUESS scalar deleting dtor (size 0x1c)', 'thiscall', None, ret='eax', gen=_dtor(0x4cd0e0), note='batch2612')
S(0x4d1600, 'GUESS scalar deleting dtor (size 0x38)', 'thiscall', None, ret='eax', gen=_dtor(0x4d1530), note='batch2612')
S(0x4d53e0, 'GUESS compare with this+4, assert hook', 'thiscall', None, ret='eax', gen=_g4d53e0, note='batch2612')
S(0x4d5700, 'GUESS vtable set + delete (size 4)', 'thiscall', None, ret='eax', gen=_g4d5700, note='batch2612')
