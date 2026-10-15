"""specs_s200014.py - Sonnet-w2 batch 200014: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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


def _reg(c, o, slot, nargs, ret=None):
    r = c.rng
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {slot: pystub(c, nargs, ret=r.getrandbits(32) if ret is None else ret, this=True, side=_side(c, o))}, nslots=0x150 // 4)
    c.emu.w32(eng + 0x9b, t)


def _ctor_register(c):
    r, o = _setup(c, 0x80)
    hook_rec(c, 0x469870, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    _reg(c, o, 0x114, 4)
    return [o]


def g4b9160(c):
    r, o = _setup(c, 0xa0)
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    _reg(c, o, 0x34, 1)
    return [o]


def g47f6f0(c):
    r, o = _setup(c, 0x40)
    hook_rec(c, 0x43de70, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    peer = obj(c, 0x40, {0x210: pystub(c, 1, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))}, nslots=0x90)
    ret = peer if r.random() < 0.75 else 0
    t = obj(c, 0x40, {0x58: pystub(c, 1, ret=ret, this=True, side=seh_record(c, 2))}, nslots=0x20)
    c.emu.w32(eng + 0x9b, t)
    c.emu.w32(o + 0x18, r.choice([0, r.getrandbits(32), 1]))
    return [o]


def g604650(c):
    r, o = _setup(c, 0x40)
    hook_rec(c, 0x604ca0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x41e290, 1, ret=rnd(c, 0x10), pop=0, side=seh_record(c, 2))
    c.emu.w32(0x724768, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [o]


def g4f8630(c):
    r, o = _setup(c, 0x200)
    hook_rec(c, 0x4f97f0, 3, ret=r.getrandbits(32), pop=12, this=True, side=_side(c, o))
    hook_rec(c, 0x4cbeb0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x4ccba0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


for a, n, g in ((0x5bc270, 'ctor register 5bc270', _ctor_register), (0x5c37e0, 'ctor register 5c37e0', _ctor_register), (0x5dd750, 'ctor register 5dd750', _ctor_register),
                (0x4b9160, 'dtor free two register', g4b9160), (0x47f6f0, 'dtor release peer', g47f6f0), (0x604650, 'ctor with buffer', g604650),
                (0x4f8630, 'ctor three args c', g4f8630)):
    S(a, 'GUESS ' + n, 'thiscall', None, ret='eax', gen=g, note='batch200014')
S(0x577920, 'GUESS factory init 577920', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x573590), note='batch200014')
