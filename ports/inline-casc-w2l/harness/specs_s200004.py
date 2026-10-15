"""specs_s200004.py - Sonnet-w2 batch 200004: SEH-framed constructor / deleting-destructor shapes. Hooked callees record the SEH chain
(seh_record) and the object's vtable word at call time; fake outer SEH records 0-2; fs:[0] compared after return."""
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


def g565870(c):
    r, o = _setup(c, 0x1c0)
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=0x14)
    c.emu.w32(eng + 0x9b, t)
    return [o]


def g499d50(c):
    r, o = _setup(c)
    hook_rec(c, 0x49a3e0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return [o, r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])]


def g4d8d50(c):
    r, o = _setup(c)
    hook_rec(c, 0x4d8e60, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x4e7e80, 0, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=seh_record(c, 2))
    c.emu.w32(o, r.choice([0, rnd(c, 0x20), rnd(c, 0x40)]))
    return [o]


def g4d8180(c):
    r, o = _setup(c, 0x100)
    hook_rec(c, 0x4cbe80, 1, ret=r.getrandbits(32), pop=4, this=True, side=_side(c, o))
    return [o, r.getrandbits(32), r.getrandbits(32)]


S(0x565870, 'GUESS init and register b', 'thiscall', None, ret='eax', gen=g565870, note='batch200004')
S(0x499d50, 'GUESS deleting dtor 13c', 'thiscall', None, ret='eax', gen=g499d50, note='batch200004')
S(0x4d8d50, 'GUESS release owned', 'thiscall', None, ret='eax', gen=g4d8d50, note='batch200004')
S(0x4d8180, 'GUESS ctor two members', 'thiscall', None, ret='eax', gen=g4d8180, note='batch200004')
