"""specs_s33047.py - h3 (Sonnet) batch 33047: tiny vtable wrappers."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g475ac0(c):
    clear_hooks(c)
    e = c.emu
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    vt = e.alloc(0x20, 4)
    e.w32(vt + 0xc, stub)
    me = rnd(c, 0x400)
    e.w32(me + 0x34f, vt)
    return [me]


def _g5646e0(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0xd00, {0xfc: stub})
    c.emu.w32(me + 0xc82, r.choice([0x20, 0x20, 0x21, 0, _w(c)]))
    return [me, _w(c)]


def _g5f9dc0(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x40, {4: stub})
    c.emu.w32(me + 4, r.choice([1, 1, 2, 0, 3, _w(c)]))
    return [me]


def _g46e6d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4db2c0, 2, this=True, ret=lambda em, k: _w(c))
    rr = rnd(c, 0x20)
    stub = pystub(c, 0, this=True, ret=lambda em, k: rr)
    me = obj(c, 0x40, {0x348: stub})
    return [me, _w(c), _w(c)]


def _g4d4f00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [_w(c), _w(c)]


def _g635490(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 1, this=True)
    o = obj(c, 0x20, {0: stub})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x14, r.choice([o, o, 0]))
    return [me]


def _g466f30(c):
    clear_hooks(c)
    stub7c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    rr = obj(c, 0x20, {0x7c: stub7c})
    stub20 = pystub(c, 0, this=True, ret=lambda em, k: rr)
    me = obj(c, 0x40, {0x20: stub20})
    return [me]


def _g51d100(c):
    clear_hooks(c)
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x4b0, {0x2ec: stub})
    return [me]


S(0x475ac0, 'GUESS subobject vcall 0xc(this)', 'thiscall', None, ret='eax', gen=_g475ac0, note='batch33047')
S(0x5646e0, 'GUESS vcall 0xfc if state 0x20', 'thiscall', None, ret=None, gen=_g5646e0, note='batch33047')
S(0x5f9dc0, 'GUESS release refcount vcall 4', 'thiscall', None, ret=None, gen=_g5f9dc0, note='batch33047')
S(0x46e6d0, 'GUESS vcall 0x348 then tail 4db2c0', 'thiscall', None, ret='eax', gen=_g46e6d0, note='batch33047')
S(0x4d4f00, 'GUESS assert hook stub', 'stdcall', None, ret='al', gen=_g4d4f00, note='batch33047')
S(0x635490, 'GUESS delete owned child vcall 0', 'thiscall', None, ret=None, gen=_g635490, note='batch33047')
S(0x466f30, 'GUESS double vcall 0x20 then 0x7c', 'thiscall', None, ret='eax', gen=_g466f30, note='batch33047')
S(0x51d100, 'GUESS vcall 0x2ec(field) clear', 'thiscall', None, ret=None, gen=_g51d100, note='batch33047')
