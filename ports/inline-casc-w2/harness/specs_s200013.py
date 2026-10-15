"""specs_s200013.py - Sonnet-w2 batch 200013: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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


def g5dc060(c):
    r, o = _setup(c, 0x80)
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=0x14)
    c.emu.w32(eng + 0x9b, t)
    m = obj(c, 0x20, {0: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=2) if r.random() < 0.75 else 0
    c.emu.w32(o + 0x48, m)
    return [o]


def g4d8ce0(c):
    r, o = _setup(c, 0x20)
    ptr = r.choice([0, rnd(c, 0x30)])
    hook_rec(c, 0x41e290, 1, ret=ptr, pop=0, side=seh_record(c, 2))
    hook_rec(c, 0x4e7dd0, 1, ret=r.getrandbits(32), pop=4, this=True, side=seh_record(c, 2))
    return [o, r.getrandbits(32)]


def g5b2100(c):
    r, o = _setup(c, 0x1e0)
    hook_rec(c, 0x4451d0, 3, ret=r.getrandbits(32), pop=12, this=True, side=_side(c, o))
    hook_rec(c, 0x4de7a0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g45cae0(c):
    r, o0 = _setup(c, 0x40)
    a = rnd(c, 0x20)
    o = obj(c, 0x40, {0x1d4: pystub(c, 2, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))}, nslots=0x78)
    hook_rec(c, 0x4cbeb0, 0, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))
    return [o, a, r.getrandbits(32)]


def g4bddb0(c):
    r, o = _setup(c, 0x1e0)
    hook_rec(c, 0x469870, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x4ccba0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o]


for a, n, g in ((0x5dc060, 'dtor owned register', g5dc060), (0x4d8ce0, 'make and store', g4d8ce0), (0x5b2100, 'ctor with member', g5b2100),
                (0x45cae0, 'forward with member', g45cae0), (0x4bddb0, 'ctor two members b', g4bddb0)):
    S(a, 'GUESS ' + n, 'thiscall', None, ret='eax', gen=g, note='batch200013')
S(0x5693a0, 'GUESS factory init 5693a0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x561020), note='batch200013')
S(0x56dc50, 'GUESS factory init 56dc50', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x561020), note='batch200013')
S(0x57be70, 'GUESS factory init 57be70', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x561020), note='batch200013')
S(0x46b2e0, 'GUESS factory init 46b2e0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469cc0), note='batch200013')
S(0x46b350, 'GUESS factory init 46b350', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469cc0), note='batch200013')
