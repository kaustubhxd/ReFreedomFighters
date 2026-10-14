"""specs_s33056.py - h3 () batch 33056."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g4869a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4614d0, 3, this=True, ret=lambda em, k: _w(c))
    s230 = pystub(c, 2, this=True, ret=lambda em, k: rnd(c, 0x20))
    o = obj(c, 0x300, {0x230: s230})
    s0c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x80, {0xc: s0c})
    e.w32(me + 8, o)
    e.w32(me + 0x14, r.choice([0, _w(c), _w(c)]))
    return [me]


def _g52abc0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x43e0f0, 0, this=True)
    s110 = pystub(c, 2, this=True)
    s114 = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    return [obj(c, 0x140, {0x110: s110})]


def _g54df10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = _zeroed(c, 0x4200, 0x40)
    s = pystub(c, 0, this=True, ret=lambda em, k: r.randrange(0, 6))
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x4c, s)
    e.w32(me, vt)
    e.wbytes(me + 0x40a7, bytes(r.choice([0, 0, 1, 7]) for _ in range(6)))
    e.w32(me + 0x40ad, r.randrange(0, 6))
    return [me]


def _g584cc0(c):
    clear_hooks(c)
    r = c.rng
    s = pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    sysobj(c, table_slots={0x58: s})
    me = rnd(c, 0x200)
    return [me, _w(c)]


def _g5de3e0(c):
    clear_hooks(c)
    e = c.emu
    G = _zeroed(c, 0x2d00, 0x40)
    e.w32(0x7003b8, G)
    s100 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x100: s100})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: robj)
    sysobj(c, table_slots={0x58: s58})
    me = rnd(c, 0x140)
    e.w32(me + 0x114, rnd(c, 0x700))
    return [me]


def _g426790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 2, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))
    e.w32(0x67612c, pystub(c, 3, ret=lambda em, k: r.choice([0, 0, 1, _w(c)])))
    return [_w(c), _w(c)]


def _g4690c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s4c = pystub(c, 0, this=True)
    me = obj(c, 0x40, {0x4c: s4c})
    e.w32(me + 4, r.choice([0, 4, 5, 0x100, _w(c)]))
    s148 = pystub(c, 2, this=True)
    sysobj(c, table_slots={0x148: s148})
    return [r.choice([me, me, me, 0]), _w(c)]


def _g475280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s3c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    o2 = obj(c, 0x80, {0x3c: s3c})
    s28 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0x3b7, o2), ret=lambda em, k: r.choice([0, 1, 0x100, _w(c)]))
    s3d = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    o1 = obj(c, 0x80, {0x28: s28, 0x3c: s3d})
    me = rnd(c, 0x400)
    e.w32(me + 0x3b7, r.choice([o1, o1, o1, 0]))
    return [me, _w(c)]


S(0x4869a0, 'GUESS child vcall 230 then 4614d0 or tail', 'thiscall', None, ret='eax', gen=_g4869a0, note='batch33056')
S(0x52abc0, 'GUESS init vcall 110 and table 114 store word', 'thiscall', None, ret=None, gen=_g52abc0, note='batch33056')
S(0x54df10, 'GUESS claim flag byte slot', 'thiscall', None, ret='al', gen=_g54df10, note='batch33056')
S(0x584cc0, 'GUESS clear resolved five entries', 'thiscall', None, ret=None, gen=_g584cc0, note='batch33056')
S(0x5de3e0, 'GUESS register self and resolve children', 'thiscall', None, ret='eax', gen=_g5de3e0, note='batch33056')
S(0x426790, 'GUESS import call or log on failure', 'stdcall', None, ret='eax', gen=_g426790, note='batch33056')
S(0x4690c0, 'GUESS flag set and table vcall 148', 'thiscall', None, ret=None, gen=_g4690c0, note='batch33056')
S(0x475280, 'GUESS child query then tail vcall reread', 'thiscall', None, ret='eax', gen=_g475280, note='batch33056')
