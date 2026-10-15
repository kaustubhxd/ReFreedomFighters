"""specs_s200003.py - Sonnet-w2 batch 200003: SEH-framed destructor-shaped functions. Every hooked callee records the SEH chain it
sees (seh_record: next, handler, state) AND the object's vtable word at call time ('vt' call-log row), so the order of vtable stores
and calls is compared. Fake outer SEH records 0-2; fs:[0] compared after return."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, seh_record, seh_chain


def _side(c, o):
    sr = seh_record(c, 2)

    def side(emu, k):
        emu.calllog.append(('vt', emu.r32(o)))
        sr(emu, k)
    return side


def _setup(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    return c.rng, rnd(c, 0x40)


def g4ee4e0(c):
    r, o = _setup(c)
    hook_rec(c, 0x4f0c10, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x43de70, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o]


def g6035a0(c):
    r, o = _setup(c)
    hook_rec(c, 0x603900, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x41e2c0, 1, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return [o]


def g4478d0(c):
    r, o = _setup(c)
    hook_rec(c, 0x4dbb00, 1, ret=r.getrandbits(32), pop=4, this=True, side=_side(c, o))
    hook_rec(c, 0x45c3e0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o]


def g5facc0(c):
    r, o = _setup(c)
    hook_rec(c, 0x5fb5b0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x54f870, 2, ret=r.getrandbits(32), pop=8, side=_side(c, o))
    return [o]


def g5ab460(c):
    r, o = _setup(c)
    hook_rec(c, 0x54f870, 2, ret=r.getrandbits(32), pop=8, side=seh_record(c, 2))
    begin = r.choice([0, rnd(c, 16), r.getrandbits(32)])
    k = r.random()
    if k < 0.25:
        end = begin
    elif k < 0.4:
        end = (begin - r.randrange(1, 64)) & 0xffffffff
    else:
        end = (begin + r.randrange(0, 300)) & 0xffffffff
    c.emu.w32(o, begin)
    c.emu.w32(o + 8, end)
    return [o]


S(0x4ee4e0, 'GUESS derived dtor a', 'thiscall', None, ret='eax', gen=g4ee4e0, note='batch200003')
S(0x6035a0, 'GUESS derived dtor b', 'thiscall', None, ret='eax', gen=g6035a0, note='batch200003')
S(0x4478d0, 'GUESS derived dtor c', 'thiscall', None, ret='eax', gen=g4478d0, note='batch200003')
S(0x5facc0, 'GUESS clear and free 19', 'thiscall', None, ret='eax', gen=g5facc0, note='batch200003')
S(0x5ab460, 'GUESS vector16b free', 'thiscall', None, ret='eax', gen=g5ab460, note='batch200003')
