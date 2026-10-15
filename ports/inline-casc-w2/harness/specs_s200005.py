"""specs_s200005.py - Sonnet-w2 batch 200005: SEH-framed ctor / deleting-dtor shapes. Hooked callees record the SEH chain and the object's
vtable word at call time; fake outer SEH records 0-2; fs:[0] compared after return."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _side(c, o):
    sr = seh_record(c, 2)

    def side(emu, k):
        emu.calllog.append(('vt', emu.r32(o)))
        sr(emu, k)
    return side


def _setup(c, size=0x40):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    return c.rng, rnd(c, size)


def g4fb930(c):
    r, o = _setup(c, 0xb0)
    hook_rec(c, 0x469870, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x4ccba0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o]


def _flags(r):
    return r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])


def g6125f0(c):
    r, o = _setup(c)
    hook_rec(c, 0x6132a0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return [o, _flags(r)]


def g616b70(c):
    r, o = _setup(c)
    hook_rec(c, 0x659c00, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return [o, _flags(r)]


def g433f30(c):
    r, o = _setup(c, 0xb0)
    hook_rec(c, 0x434fb0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x4cbec0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    if r.random() < 0.7:
        m = obj(c, 0x20, {0: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=2)
    else:
        m = 0
    c.emu.w32(o + 8, m)
    return [o]


S(0x4fb930, 'GUESS ctor flagged', 'thiscall', None, ret='eax', gen=g4fb930, note='batch200005')
S(0x6125f0, 'GUESS deleting dtor 2216c', 'thiscall', None, ret='eax', gen=g6125f0, note='batch200005')
S(0x616b70, 'GUESS deleting dtor 14', 'thiscall', None, ret='eax', gen=g616b70, note='batch200005')
S(0x433f30, 'GUESS dtor with owned', 'thiscall', None, ret='eax', gen=g433f30, note='batch200005')
