"""specs_s200011.py - Sonnet-w2 batch 200011: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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


def _owned(c):
    r, o = _setup(c)
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    m = obj(c, 0x20, {8: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=4) if r.random() < 0.75 else 0
    c.emu.w32(o + 4, m)
    return [o, r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])]


S(0x54ea20, 'GUESS deleting dtor owned 8', 'thiscall', None, ret='eax', gen=_owned, note='batch200011')
S(0x54eb10, 'GUESS deleting dtor owned 50', 'thiscall', None, ret='eax', gen=_owned, note='batch200011')
S(0x4c4ba0, 'GUESS factory init 4c4ba0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4c4930), note='batch200011')
S(0x4c5460, 'GUESS factory init 4c5460', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4c52f0), note='batch200011')
S(0x4cad60, 'GUESS factory init 4cad60', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x4ca8f0), note='batch200011')
S(0x53d0f0, 'GUESS factory init 53d0f0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x53ccd0), note='batch200011')
S(0x548e20, 'GUESS factory init 548e20', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x548ca0), note='batch200011')
S(0x565eb0, 'GUESS factory init 565eb0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x565b90), note='batch200011')
