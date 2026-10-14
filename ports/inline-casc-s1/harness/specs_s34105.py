"""specs_s34105.py - seven call wrappers; callees are recorders (this recorded; edx logged for the register-argument callees)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _edx(em, k):
    em.calllog.append(('edx', em.reg('edx')))


def _g4ea2b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x441970, 1, this=True, ret=r.getrandbits(32), side=_edx)
    hook_rec(c, 0x441940, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    return [rnd(c, 0x60), r.getrandbits(32), r.getrandbits(32)]


def _dtor(callee):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, callee, 0, this=True, pop=0, ret=r.getrandbits(32))
        hook_rec(c, 0x634273, 2, pop=0)
        return [rnd(c, 0x40), r.choice([0, 1, 2, 3, r.getrandbits(32)])]
    return g


def _g54c2a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x650dc0, 1, this=True, ret=r.getrandbits(32))
    tgt = 0 if r.random() < 0.3 else obj(c, 0x20, {0x20: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x24 // 4)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x50, tgt)
    return [me, r.getrandbits(32)]


def _g55c7d0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    me = rnd(c, 0x30)
    mid = rnd(c, 0x60)
    c.emu.w32(mid + 0x54, rnd(c, 0x20))
    c.emu.w32(me + 0x1c, mid)
    return [me, rnd(c, 0x20)]


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x469870, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x50)]


def _g5afed0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5afbb0, 2, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


S(0x4ea2b0, 'GUESS two register calls', 'thiscall', None, ret='eax', gen=_g4ea2b0, note='batch34105')
S(0x532a80, 'GUESS scalar deleting destructor G', 'thiscall', None, ret='eax', gen=_dtor(0x5329f0), note='batch34105')
S(0x54c2a0, 'GUESS store then forward to member slot 0x20', 'thiscall', None, ret='eax', gen=_g54c2a0, note='batch34105')
S(0x55c7d0, 'GUESS copy cell value into nested object', 'thiscall', None, ret='eax', gen=_g55c7d0, note='batch34105')
S(0x57a100, 'GUESS constructor with flag A', 'thiscall', None, ret='eax', gen=_ctor, note='batch34105')
S(0x5afed0, 'GUESS forward and store', 'thiscall', None, ret='eax', gen=_g5afed0, note='batch34105')
S(0x5b7960, 'GUESS constructor with flag B', 'thiscall', None, ret='eax', gen=_ctor, note='batch34105')
