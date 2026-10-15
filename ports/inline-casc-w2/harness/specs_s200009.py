"""specs_s200009.py - Sonnet-w2 batch 200009: SEH-framed ctor / dtor / factory / allocator shapes. Hooked callees and vtable stubs record the SEH chain and the
object's vtable word at call time; fake outer SEH records 0-2; fs:[0] compared after return."""
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


def g5193c0(c):
    r, o = _setup(c)
    hook_rec(c, 0x500990, 1, ret=r.getrandbits(32), pop=4, this=True, side=_side(c, o))
    hook_rec(c, 0x51a700, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    c.emu.w32(0x701660, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [o, r.getrandbits(32)]


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


def g5bfc00(c):
    r, o = _setup(c, 0x80)
    hook_rec(c, 0x41e2c0, 1, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=0x14)
    c.emu.w32(eng + 0x9b, t)
    return [o]


def g5f30d0(c):
    r, o = _setup(c, 0x20)
    ptr = r.choice([0, o])
    hook_rec(c, 0x41e290, 1, ret=ptr, pop=0, side=seh_record(c, 2))
    hook_rec(c, 0x603500, 1, ret=r.getrandbits(32), pop=4, this=True, side=seh_record(c, 2))
    return [r.getrandbits(32), r.getrandbits(32)]


S(0x5193c0, 'GUESS ctor guarded b', 'thiscall', None, ret='eax', gen=g5193c0, note='batch200009')
S(0x56ca20, 'GUESS factory init 56ca20', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x56c810), note='batch200009')
S(0x5a3ee0, 'GUESS factory init 5a3ee0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5a3710), note='batch200009')
S(0x5b2b60, 'GUESS factory init 5b2b60', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5b2550), note='batch200009')
S(0x5b94f0, 'GUESS factory init 5b94f0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5b9380), note='batch200009')
S(0x5bcba0, 'GUESS factory init 5bcba0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5bcab0), note='batch200009')
S(0x5bfc00, 'GUESS dtor register c', 'thiscall', None, ret='eax', gen=g5bfc00, note='batch200009')
S(0x5f30d0, 'GUESS new and init', 'stdcall', None, ret='eax', gen=g5f30d0, note='batch200009')
