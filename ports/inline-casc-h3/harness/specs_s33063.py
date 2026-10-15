"""specs_s33063.py - h3 (Sonnet) batch 33063."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _gdisp(base):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 0, this=True, side=lambda em, k: em.calllog.append(('b', em.r32(em.reg('ecx')))))
        hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
        hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
        return [rnd(c, 0x40), r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]
    return g


def _g470250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x46b440, 2, this=True)
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rnd(c, 0x20), 0]))
    sysobj(c, table_slots={0x60: s60})
    s304 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0xb0, {0x304: s304})
    e.w32(me + 0x96, r.choice([0, _w(c), _w(c)]))
    e.w32(me + 0x9a, r.choice([0, _w(c), _w(c)]))
    return [me]


def _g4cdbd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s0 = pystub(c, 1, this=True)
    me = _w(c)
    sa = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('n', 1)))
    sb = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('n', 2)))
    vt2 = e.alloc(0x100, 4)
    e.w32(vt2 + 0x7c, sb)
    vt1 = e.alloc(0x100, 4)
    e.w32(vt1 + 0x7c, sa)
    me = rnd(c, 0x40)
    e.w32(me, vt1)
    # swap vtable from the first call on
    sa2 = pystub(c, 1, this=True, side=lambda em, k: (em.calllog.append(('n', 1)), e.w32(me, vt2)))
    e.w32(vt1 + 0x7c, sa2)
    n = r.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x10) for _ in range(n)]
    for i, nd in enumerate(nodes):
        e.w32(nd + 4, nodes[i + 1] if i + 1 < n else 0)
    e.w32(me + 4, nodes[0] if n else 0)
    e.w32(me + 0xc, _w(c) & 0x7fffffff)
    e.w32(me + 0x14, _w(c) | 1)
    e.w32(me + 0x1c, r.choice([obj(c, 0x40, {0: s0}), 0]))
    return [me]


def _g534510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.r32(me + 8), em.r32(me + 4), em.r32(me))))
    s0 = pystub(c, 1, this=True)
    me = rnd(c, 0x1020)
    e.w32(me, r.choice([obj(c, 0x40, {0: s0}), 0]))
    e.w32(me + 4, r.choice([_w(c), 0]))
    e.w32(me + 8, r.choice([_w(c), 0]))
    return [me]


def _g5ef000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s8 = pystub(c, 0, this=True)
    me = obj(c, 0x40, {8: s8})
    cur = [_w(c) for _ in range(4)]
    for i, off in enumerate((0x11, 0x15, 0x19, 0x1d)):
        e.w32(me + off, cur[i])
    args = list(cur)
    k = r.choice([-1, 0, 1, 2, 3])
    if k >= 0:
        args[k] = args[k] ^ r.choice([1, 0x80000000, _w(c) | 1])
    return [me] + args


def _g63ea00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x63ef00, 1, this=True)
    n = rnd(c, 0x60)
    s130 = pystub(c, 3, this=True)
    ch = obj(c, 0x200, {0x130: s130})
    e.w32(n + 0x54, r.choice([ch, ch, 0]))
    hook_rec(c, 0x4dd8d0, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    a = rnd(c, 0x60)
    e.w32(a + 0x38, r.choice([n, n, n, 0]))
    return [rnd(c, 0x40), a]


S(0x445340, 'GUESS dtor flags dispatch 445340', 'thiscall', None, ret='eax', gen=_gdisp(0x45c3e0), note='batch33063')
S(0x46a7c0, 'GUESS dtor flags dispatch 46a7c0', 'thiscall', None, ret='eax', gen=_gdisp(0x46a4f0), note='batch33063')
S(0x5b21b0, 'GUESS dtor flags dispatch 5b21b0', 'thiscall', None, ret='eax', gen=_gdisp(0x445330), note='batch33063')
S(0x470250, 'GUESS table lookup then update 304', 'thiscall', None, ret=None, gen=_g470250, note='batch33063')
S(0x4cdbd0, 'GUESS list teardown with vtable reread', 'thiscall', None, ret=None, gen=_g4cdbd0, note='batch33063')
S(0x534510, 'GUESS release members', 'thiscall', None, ret=None, gen=_g534510, note='batch33063')
S(0x5ef000, 'GUESS set quad and notify if changed', 'thiscall', None, ret=None, gen=_g5ef000, note='batch33063')
S(0x63ea00, 'GUESS call then clear flag and child vcall', 'thiscall', None, ret=None, gen=_g63ea00, note='batch33063')
