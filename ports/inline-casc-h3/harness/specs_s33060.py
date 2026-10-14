"""specs_s33060.py - h3 () batch 33060."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g462000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s1e0 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0)), ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    a1 = obj(c, 0x200, {0x1e0: s1e0})
    s2e4 = pystub(c, 1, this=True)
    me = obj(c, 0x300, {0x2e4: s2e4})
    s2 = pystub(c, 1, this=True)

    def sideh(em, k):
        em.calllog.append(('t', 0))
    hook_rec(c, 0x45d5b0, 1, this=True, side=sideh)
    return [me, a1]


def _g46baa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s14a = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    s14b = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    c1 = obj(c, 0x40, {0x14: s14a})
    c2 = obj(c, 0x40, {0x14: s14b})
    s114 = pystub(c, 1, this=True)
    s31c = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('a', 1)), ret=lambda em, k: _w(c))
    s318 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('a', 2)), ret=lambda em, k: _w(c))
    me = obj(c, 0x340, {0x114: s114, 0x31c: s31c, 0x318: s318})
    e.w32(me + 0x74, c1)
    e.w32(me + 0x78, c2)
    return [me]


def _g470610(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4705a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, _w(c)]))
    s = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    a = obj(c, 0x80, {0x44: s})
    return [rnd(c, 0x100), a]


def _g4b5970(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6352f0, 1, this=True, nullflag=(0,), side=lambda em, k: (em.w32(em.arg32(0), _w(c)) if r.random() < 0.7 else None))
    s98 = pystub(c, 1, this=True, deref={0: 1})
    s68 = pystub(c, 2, this=True)
    return [obj(c, 0x100, {0x98: s98, 0x68: s68})]


def _g558a50(c):
    clear_hooks(c)
    r = c.rng
    ptrs = []

    def ret(em, k):
        p = rnd(c, 0x10)
        ptrs.append(p)
        return p

    def side(em, k):
        if k == 1 and ptrs and r.random() < 0.5:
            em.w32(ptrs[0], _w(c))
    hook_rec(c, 0x5003d0, 1, this=True, ret=ret, side=side)
    hook_rec(c, 0x59e730, 2, this=True, ret=lambda em, k: _w(c))
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x1c, rnd(c, 0x20))
    a = rnd(c, 0x20)
    c.emu.w32(a + 4, rnd(c, 0x20))
    return [me, a]


def _g595210(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s330 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([7, 7, 7, 0, 6, 8, _w(c)]))
    o = obj(c, 0x400, {0x330: s330})
    s350 = pystub(c, 0, this=True, ret=lambda em, k: o)
    a = obj(c, 0x400, {0x350: s350})
    me = _zeroed(c, 0x900, 0x40)
    blk = _zeroed(c, 0xb60, 0x40)
    e.wbytes(blk + 0xb45, bytes([r.choice([0, 1, 0x80])]))
    e.w32(me + 0x85a, blk)
    return [me, a]


def _g5e0200(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x4614d0, 3, this=True, ret=lambda em, k: _w(c))
    s10 = pystub(c, 0, this=True)
    ch = obj(c, 0x40, {0x10: s10})
    s228 = pystub(c, 5, this=True, ret=lambda em, k: rnd(c, 0x20))
    o = obj(c, 0x300, {0x228: s228})
    me = rnd(c, 0x40)
    e.w32(me + 0xc, ch)
    e.w32(me + 8, o)
    return [me]


def _g6566a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    o = rnd(c, 0x40)
    e.w32(o + 0x20, r.choice([0, 0, _w(c)]))
    e.w32(so + 0x1aa3, o)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [_w(c)]


S(0x462000, 'GUESS call then conditional vcall', 'thiscall', None, ret=None, gen=_g462000, note='batch33060')
S(0x46baa0, 'GUESS child checks then vcalls', 'thiscall', None, ret='eax', gen=_g46baa0, note='batch33060')
S(0x470610, 'GUESS check call then arg vcall 44', 'thiscall', None, ret='al', gen=_g470610, note='batch33060')
S(0x4b5970, 'GUESS out local then vcalls', 'thiscall', None, ret=None, gen=_g4b5970, note='batch33060')
S(0x558a50, 'GUESS two lookups then 59e730', 'thiscall', None, ret='eax', gen=_g558a50, note='batch33060')
S(0x595210, 'GUESS nested vcall kind check', 'thiscall', None, ret='al', gen=_g595210, note='batch33060')
S(0x5e0200, 'GUESS child vcall then vcall 228 and 4614d0', 'thiscall', None, ret='eax', gen=_g5e0200, note='batch33060')
S(0x6566a0, 'GUESS add sysobj offset with assert', 'stdcall', None, ret='eax', gen=_g6566a0, note='batch33060')
