"""specs_s200012.py - Sonnet-w2 batch 200012: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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
    r, o = _setup(c, 0x140)
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    m = obj(c, 0x20, {8: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=4) if r.random() < 0.75 else 0
    c.emu.w32(o + 0x110, m)
    return [o, r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])]


S(0x608180, 'GUESS deleting dtor owned 134', 'thiscall', None, ret='eax', gen=_owned, note='batch200012')
S(0x5702a0, 'GUESS factory init 5702a0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x56fea0), note='batch200012')
S(0x5b7fb0, 'GUESS factory init 5b7fb0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5b7f00), note='batch200012')
S(0x5be120, 'GUESS factory init 5be120', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5bde30), note='batch200012')
S(0x5bfd60, 'GUESS factory init 5bfd60', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5bfac0), note='batch200012')
S(0x5c4070, 'GUESS factory init 5c4070', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5c3e70), note='batch200012')
S(0x5c6300, 'GUESS factory init 5c6300', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5c5d20), note='batch200012')
S(0x5c85e0, 'GUESS factory init 5c85e0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5c7f50), note='batch200012')
S(0x5d5260, 'GUESS factory init 5d5260', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x5d51a0), note='batch200012')
