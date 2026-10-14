"""specs_s33050.py - h3 () batch 33050."""
import pe_emu
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4f10d0(c):
    clear_hooks(c)
    s274 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s23c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x40, {0x274: s274, 0x23c: s23c})]


def _g5373d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [rnd(c, 0x10)]


def _g6568b0(c):
    clear_hooks(c)
    e = c.emu
    so = sysobj(c)
    s80 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    e.w32(so + 0x1aa3, obj(c, 0x40, {0x80: s80}))
    s0c = pystub(c, 1, this=True, ret=lambda em, k: rnd(c, 0x10))
    return [obj(c, 0x40, {0xc: s0c}), _w(c)]


def _g462d10(c):
    clear_hooks(c)
    e = c.emu
    s14 = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    child = obj(c, 0x40, {0x14: s14})
    me = rnd(c, 0x100)
    e.w32(me + 0x6c, child)
    return [me, _w(c), _w(c), _w(c)]


def _g467390(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x463940, 0, this=True, ret=lambda em, k: _w(c))
    s360 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    s364 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x180, {0x360: s360, 0x364: s364})
    c.emu.w32(me + 0x159, r.choice([0, 0x20000, 0x20000, _w(c), 0x1ffff]))
    return [me]


def _g473b20(c):
    clear_hooks(c)
    s548 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    s54c = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x40, {0x548: s548, 0x54c: s54c})]


def _g4d8bf0(c):
    clear_hooks(c)
    r = c.rng
    s84 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, _w(c), _w(c)]))
    child = obj(c, 0x40, {0x84: s84})
    me = rnd(c, 0x40)
    c.emu.w32(me + 4, child)
    return [me, _w(c)]


def _g425c3b(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ebp = pe_emu.STACK_TOP - 0x80
    e.w32(ebp - 0x1c, r.choice([0, _w(c), _w(c)]))
    e.w32(0x676070, pystub(c, 1, ret=lambda em, k: _w(c)))
    e.w32(0x6760a8, pystub(c, 2, ret=lambda em, k: _w(c)))
    e.w32(0x6760a4, pystub(c, 1, ret=lambda em, k: _w(c)))
    return []


S(0x4f10d0, 'GUESS vcall chain 274 then 23c', 'thiscall', None, ret='eax', gen=_g4f10d0, note='batch33050')
S(0x5373d0, 'GUESS assert then clear out param', 'stdcall', None, ret='eax', gen=_g5373d0, note='batch33050')
S(0x6568b0, 'GUESS lookup then sys vcall 0x80', 'thiscall', None, ret='eax', gen=_g6568b0, note='batch33050')
S(0x462d10, 'GUESS child vcall 0x14 four args', 'thiscall', None, ret='eax', gen=_g462d10, note='batch33050')
S(0x467390, 'GUESS flag selects vcall then tail', 'thiscall', None, ret='eax', gen=_g467390, note='batch33050')
S(0x473b20, 'GUESS two vcalls 548/54c', 'thiscall', None, ret='eax', gen=_g473b20, note='batch33050')
S(0x4d8bf0, 'GUESS child vcall 0x84 plus 4', 'thiscall', None, ret='eax', gen=_g4d8bf0, note='batch33050')
S(0x425c3b, 'GUESS SEH funclet import releases', 'cdecl', None, ret=None, gen=_g425c3b, note='batch33050')
