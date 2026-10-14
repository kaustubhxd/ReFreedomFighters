"""specs_s33061.py - h3 () batch 33061."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g46cea0(c):
    clear_hooks(c)

    def lg(i):
        return lambda em, k: em.calllog.append(('c', i))
    hook_rec(c, 0x43f900, 1, this=True, side=lg(0))
    hook_rec(c, 0x4e12e0, 2, this=True, side=lg(1))
    hook_rec(c, 0x4e1b30, 0, this=True, side=lg(2))
    hook_rec(c, 0x4e0fd0, 1, this=True, side=lg(3))
    return [rnd(c, 0x100), rnd(c, 0x40)]


def _g4c5820(c):
    clear_hooks(c)
    e = c.emu
    sa = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x100, 4)
    e.w32(vt2 + 0x60, sb)
    p = obj(c, 0x80, {0x60: sa})
    s4c = pystub(c, 2, this=True, side=lambda em, k: e.w32(p, vt2), ret=lambda em, k: _w(c))
    s138 = pystub(c, 0, this=True, ret=lambda em, k: p)
    sysobj(c, table_slots={0x138: s138, 0x4c: s4c})
    return [rnd(c, 0x80), _w(c), _w(c)]


def _g533d60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    s0 = pystub(c, 1, this=True)
    me = rnd(c, 0x40)
    e.w32(me, r.choice([obj(c, 0x40, {0: s0}), 0]))
    e.w32(me + 4, r.choice([_w(c), 0]))
    e.w32(me + 8, r.choice([_w(c), 0]))
    return [me]


def _g561c60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    P = _zeroed(c, 0x120, 0x40)
    s300 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('r', k)))
    s14 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 2, 3, 4]))
    vtp = e.alloc(0x400, 4)
    e.w32(vtp + 0x300, s300)
    vtq = e.alloc(0x40, 4)
    e.w32(vtq + 0x14, s14)
    e.w32(P, vtp)
    e.w32(P + 0xcb, vtq)
    s84 = pystub(c, 0, this=True, ret=lambda em, k: P)
    me = obj(c, 0xa0, {0x84: s84})
    e.w32(me + 0x94, r.choice([0, 1, _w(c)]))
    return [me]


def _g5c7c30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b8, _w(c))
    s0 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xae4, obj(c, 0x40, {0: s0}))
    hook_rec(c, 0x589c20, 1, this=True, ret=lambda em, k: rnd(c, 0x20))
    hook_rec(c, 0x59a580, 3, this=True)
    me = rnd(c, 0x80)
    v = r.getrandbits(16)
    e.wbytes(me + 0x4c, v.to_bytes(2, 'little'))
    a = r.choice([v, v, v | (r.getrandbits(16) << 16), r.getrandbits(32)])
    return [me, a, _w(c)]


def _g5e9dc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x59a2d0, 0, this=True)
    s100a = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    s100b = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    edi = _zeroed(c, 0x900, 0x40)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0x100, s100a)
    e.w32(edi, vt)
    e.w32(edi + 0x85a, r.choice([0, 0, _w(c)]))
    me = _zeroed(c, 0x1d20, 0x40)
    e.w32(me + 0x1d0b, edi)
    e.w32(me + 0x4f3, r.choice([obj(c, 0x200, {0x100: s100b}), 0]))
    return [me]


def _g6565e0(c):
    clear_hooks(c)
    s = pystub(c, 2, this=True)
    return [obj(c, 0x200, {0x14c: s}), rnd(c, 0x60), rnd(c, 0x60)]


def _g43e250(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de70, 0, this=True)
    hook_rec(c, 0x45c510, 1, pop=0)
    hook_rec(c, 0x4690b0, 2, pop=0)
    return [rnd(c, 0x40), r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


S(0x46cea0, 'GUESS call sequence on arg', 'thiscall', None, ret=None, gen=_g46cea0, note='batch33061')
S(0x4c5820, 'GUESS table lookup 138 then vcall 60 vtable first', 'thiscall', None, ret='eax', gen=_g4c5820, note='batch33061')
S(0x533d60, 'GUESS dtor-like release three', 'thiscall', None, ret=None, gen=_g533d60, note='batch33061')
S(0x561c60, 'GUESS repeat vcall by count', 'thiscall', None, ret=None, gen=_g561c60, note='batch33061')
S(0x5c7c30, 'GUESS match id then lookups', 'thiscall', None, ret='eax', gen=_g5c7c30, note='batch33061')
S(0x5e9dc0, 'GUESS cache lookups then tail', 'thiscall', None, ret=None, gen=_g5e9dc0, note='batch33061')
S(0x6565e0, 'GUESS vcall 14c then copy five dwords', 'thiscall', None, ret=None, gen=_g6565e0, note='batch33061')
S(0x43e250, 'GUESS scalar-ish dtor flags', 'thiscall', None, ret='eax', gen=_g43e250, note='batch33061')
