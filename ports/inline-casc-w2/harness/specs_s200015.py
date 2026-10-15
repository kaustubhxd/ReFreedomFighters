"""specs_s200015.py - Sonnet-w2 batch 200015: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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


def g5c3f10(c):
    r, o = _setup(c, 0x80)
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=0x14)
    c.emu.w32(eng + 0x9b, t)
    m = obj(c, 0x20, {0: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=2) if r.random() < 0.75 else 0
    c.emu.w32(o + 0x48, m)
    return [o]


S(0x5c3f10, 'GUESS dtor owned clear register', 'thiscall', None, ret='eax', gen=g5c3f10, note='batch200015')
S(0x46b3c0, 'GUESS factory init 46b3c0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4ae520, 'GUESS factory init 4ae520', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4b2bd0, 'GUESS factory init 4b2bd0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4b2f70, 'GUESS factory init 4b2f70', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4b3170, 'GUESS factory init 4b3170', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4b31f0, 'GUESS factory init 4b31f0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
S(0x4baee0, 'GUESS factory init 4baee0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200015')
