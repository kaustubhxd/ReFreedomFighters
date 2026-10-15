"""specs_s200016.py - Sonnet-w2 batch 200016: SEH-framed factory family and a refcounted deleting dtor. Hooked callees and vtable stubs record the SEH chain
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


S(0x4be7e0, 'GUESS factory init 4be7e0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4be860, 'GUESS factory init 4be860', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4bebb0, 'GUESS factory init 4bebb0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4bec30, 'GUESS factory init 4bec30', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4c6c70, 'GUESS factory init 4c6c70', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4caae0, 'GUESS factory init 4caae0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4cab60, 'GUESS factory init 4cab60', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4cabe0, 'GUESS factory init 4cabe0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x4f1c90, 'GUESS factory init 4f1c90', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x57a130, 'GUESS factory init 57a130', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x5b75b0, 'GUESS factory init 5b75b0', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
S(0x5b7990, 'GUESS factory init 5b7990', 'thiscall', None, ret='eax', gen=lambda c: _factory(c, 0x469870), note='batch200016')
