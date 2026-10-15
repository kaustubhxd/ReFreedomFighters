"""specs_s33075.py - h3 (Sonnet) batch 33075."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _logsetup(c, slot, nargs):
    e = c.emu
    slog = pystub(c, nargs, pop=0, ret=lambda em, k: _w(c), side=lambda em, k: em.calllog.append(('log', em.arg32(1))))
    robj = obj(c, 0x80, {slot: slog})
    s20 = pystub(c, 2, this=True, side=lambda em, k: em.calllog.append(('g', em.arg32(1))), ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _g428300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _logsetup(c, 0x2c, 3)
    e.w32(0x676068, pystub(c, 7, ret=lambda em, k: r.choice([0xffffffff, 0xffffffff, 1, _w(c)])))
    s1c = pystub(c, 1, this=True)
    me = obj(c, 0x80, {0x1c: s1c})
    return [me, _w(c)]


def _g46a990(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s0 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', em.r32(me), em.reg('ecx'))))
    c2 = obj(c, 0x40, {0: s0})
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: (em.calllog.append(('d', em.arg32(1), em.r32(me))), e.w32(me + 0x70, c2) if em.arg32(1) == 4 else None))
    hook_rec(c, 0x43ea20, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.r32(me))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    me = _zeroed(c, 0xa0, 0xa0)
    e.w32(me + 0x70, r.choice([obj(c, 0x40, {0: s0}), 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g4bbba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog3 = pystub(c, 3, pop=0, ret=lambda em, k: _w(c), side=lambda em, k: em.calllog.append(('log3', em.arg32(1), em.arg32(2))))
    slog2 = pystub(c, 2, pop=0, ret=lambda em, k: _w(c), side=lambda em, k: em.calllog.append(('log2', em.arg32(1))))
    r3 = obj(c, 0x80, {0x2c: slog3})
    r2 = obj(c, 0x80, {0x2c: slog2})
    s20 = pystub(c, 2, this=True, side=lambda em, k: em.calllog.append(('g', em.arg32(1))), ret=lambda em, k: r3 if k == 0 else r2)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: _w(c))
    so = sysobj(c)
    e.w32(so + 0x1a9f, r.choice([0, 1, _w(c)]))
    inner = rnd(c, 0x10)
    e.w32(inner + 4, r.choice([0, _w(c)]))
    me = rnd(c, 0x80)
    e.w32(me + 0x44, inner)
    return [me, _w(c), rnd(c, 0x20)]


def _g4ee070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa0 = pystub(c, 2, this=True)
    sb = pystub(c, 2, this=True)
    sb2 = pystub(c, 2, this=True)
    vt2 = e.alloc(0x200, 4)
    e.w32(vt2 + 0x60, sb2)
    p = obj(c, 0x200, {0xa0: sa0, 0x60: sb})
    s138 = pystub(c, 0, this=True, ret=lambda em, k: p)
    s4c = pystub(c, 2, this=True, side=lambda em, k: e.w32(p, vt2), ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x138: s138, 0x4c: s4c})
    return [rnd(c, 0x40), r.choice([0, 1, 0x100, 0x101, _w(c)])]


def _g564600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57f960, 0, this='mark', side=lambda em, k: em.calllog.append(('o', 1)))
    hook_rec(c, 0x57f9b0, 2, this=True, nullflag=(1,), side=lambda em, k: em.calllog.append(('o', 2)))
    hook_rec(c, 0x565360, 1, this=True, nullflag=(0,), side=lambda em, k: em.calllog.append(('o', 3)))
    me = _zeroed(c, 0xcb0, 0x100)
    e.w32(me + 0xc9a, r.choice([0xa, 0xa, 0xa, 0, 0xb, _w(c)]))
    e.w32(me + 0xc96, _w(c))
    e.wbytes(me + 0x189, bytes([r.choice([1, 0xff])]))
    return [me, r.randrange(0, 5)]


def _g5b2370(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4464e0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    sl = {off: pystub(c, 1, this=True, side=lambda em, k, off=off: em.calllog.append(('v', off, em.arg32(0)))) for off in (0x60, 0x64, 0x70, 0x68)}
    a = obj(c, 0x100, sl)
    me = _zeroed(c, 0x200, 0x200)
    return [me, a]


def _g456b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x400, 4)
    e.w32(vt2 + 0x214, sb)
    o = obj(c, 0x300, {0x214: sa})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([o, o, 0]))
    s4c = pystub(c, 1, this=True, side=lambda em, k: e.w32(o, vt2), ret=lambda em, k: _w(c))
    so = sysobj(c, table_slots={0x58: s58, 0x4c: s4c})
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0x18, _w(c))
    me = _zeroed(c, 0x100, 0x100)
    e.w32(me + 0xed, r.choice([0, 0, _w(c)]))
    return [me, rnd(c, 8), rnd(c, 8)]


def _g4ce550(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s4c = pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), _w(c)))
    s5ca = pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), r.choice([0, 0, 1, _w(c)])), ret=lambda em, k: _w(c))
    me = obj(c, 0x80, {0x4c: s4c, 0x5c: s5ca})
    return [r.choice([me, me, me, 0]), r.choice([0, 1, 2, 3, 5])]


S(0x428300, 'GUESS open file or log', 'thiscall', None, ret='al', gen=_g428300, note='batch33075')
S(0x46a990, 'GUESS dtor two vtables with child', 'thiscall', None, ret='eax', gen=_g46a990, note='batch33075')
S(0x4bbba0, 'GUESS log prints then query and conditional log', 'thiscall', None, ret=None, gen=_g4bbba0, note='batch33075')
S(0x4ee070, 'GUESS flag selects vcall form', 'thiscall', None, ret=None, gen=_g4ee070, note='batch33075')
S(0x564600, 'GUESS state 10 init temp and apply', 'thiscall', None, ret='al', gen=_g564600, note='batch33075')
S(0x5b2370, 'GUESS check then four arg vcalls', 'thiscall', None, ret='al', gen=_g5b2370, note='batch33075')
S(0x456b70, 'GUESS lazy lookup and two outputs', 'thiscall', None, ret=None, gen=_g456b70, note='batch33075')
S(0x4ce550, 'GUESS iterate with out local', 'thiscall', None, ret='eax', gen=_g4ce550, note='batch33075')
