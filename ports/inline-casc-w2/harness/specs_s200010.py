"""specs_s200010.py - Sonnet-w2 batch 200010: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
and the object's vtable word at call time; fake outer SEH records 0-2; fs:[0] compared after return."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _side(c, o):
    sr = seh_record(c, 2)

    def side(emu, k):
        emu.calllog.append(('vt', emu.r32(o)))
        sr(emu, k)
    return side


def _setup(c, size=0x80):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    return c.rng, rnd(c, size)


def g616be0(c):
    r, o = _setup(c)
    hook_rec(c, 0x659c00, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    inner = rnd(c, 0x40)
    c.emu.w32(inner + 0x30, r.choice([1, 1, 0, 2, 0xffffffff, r.getrandbits(32)]))
    c.emu.w32(o + 4, inner)
    return [o, r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])]


def _factory(c, init):
    r, o = _setup(c, 0x20)
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    p = o if r.random() < 0.75 else 0
    t = rnd(c, 0x40)
    mgr = obj(c, 0x40, {0x44: pystub(c, 1, ret=p, this=True, side=seh_record(c, 2))}, nslots=0x18)
    c.emu.w32(t + 8, mgr)
    c.emu.w32(eng + 0x9b, t)
    hook_rec(c, init, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [rnd(c, 0x10)]


S(0x616be0, 'GUESS deleting dtor refcounted', 'thiscall', None, ret='eax', gen=g616be0, note='batch200010')
S(0x46b200, 'GUESS factory init 46b200', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469c00), note='batch200010')
S(0x46b270, 'GUESS factory init 46b270', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469cc0), note='batch200010')
S(0x4a63d0, 'GUESS factory init 4a63d0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4a6270), note='batch200010')
S(0x4a8850, 'GUESS factory init 4a8850', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4a86c0), note='batch200010')
S(0x4b2950, 'GUESS factory init 4b2950', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4b1ca0), note='batch200010')
S(0x4be8e0, 'GUESS factory init 4be8e0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4bdaf0), note='batch200010')
S(0x4c3420, 'GUESS factory init 4c3420', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4c32a0), note='batch200010')
