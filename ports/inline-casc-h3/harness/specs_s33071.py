"""specs_s33071.py - h3 () batch 33071."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _assert(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g4d4590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x676424, pystub(c, 1, pop=0, ret=lambda em, k: r.choice([0, 1, 7])))
    me = _zeroed(c, 0x1100, 0x40)
    e.w32(me + 0x10cf, r.randrange(0, 6))
    ch = r.choice([0x41, 0x80, 0xff, 0x7f, 0, r.getrandbits(8) | (r.getrandbits(24) << 8)])
    return [me, ch, r.choice([0, 1, 2, 3, 0x10003, r.randrange(0, 5)])]


def _g4f6bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43ea20, 0, this=True, side=lambda em, k: em.calllog.append(('o', em.r32(me + 0x93))))
    hook_rec(c, 0x45c510, 1, pop=0, side=lambda em, k: em.calllog.append(('f', 1)))
    hook_rec(c, 0x4690b0, 2, pop=0, side=lambda em, k: em.calllog.append(('f', 2)))
    s210 = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', em.r32(me + 0x93), em.r32(me))))
    me = _zeroed(c, 0xa0, 0xa0)
    e.w32(me + 0x93, r.choice([obj(c, 0x300, {0x210: s210}), 0]))
    return [me, r.choice([0, 1, 4, 5, 2, 0xff, _w(c)])]


def _g54a040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for i, a in enumerate((0x4102f0, 0x401900, 0x401c90, 0x401020, 0x4010c0, 0x410490)):
        hook_rec(c, a, 1, pop=0, side=lambda em, k, i=i: em.calllog.append(('h', i)))
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.r32(me + 0xd))))
    me = _zeroed(c, 0x2320, 0x40)
    e.w32(me + 0xd, r.choice([0, _w(c)]))
    e.wbytes(me + 0x2315, bytes([r.choice([0, 1, 0x80])]))
    return [me]


def _g5eec70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.calllog.append(('d', em.r32(me))))
    me = rnd(c, 0x20)

    def mk(i):
        s = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('c', i, em.r32(me))))
        return r.choice([obj(c, 0x40, {0: s}), 0])
    for i, off in enumerate((4, 8, 0xc)):
        e.w32(me + off, mk(i))
    return [me, r.choice([0, 1, 2, 3, _w(c)])]


def _g5f0ff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sa = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    sb = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt2 = e.alloc(0x200, 4)
    e.w32(vt2 + 0x130, sb)
    rr = obj(c, 0x200, {0x130: sa})

    def side(em, k):
        if r.random() < 0.6:
            em.wbytes(em.arg32(4), bytes([r.getrandbits(8)]))
        e.w32(rr, vt2)
    s58 = pystub(c, 1, this=True, ret=lambda em, k: rr)
    s114 = pystub(c, 5, this=True, deref={4: -1}, side=side, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58, 0x114: s114})
    return [_w(c)]


def _g5f5620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    n = r.choice([0, 1, 2, 3])
    nodes = [_zeroed(c, 0xb0, 0xb0) for _ in range(n)]
    cands = []
    for i, nd in enumerate(nodes):
        base = r.randrange(0, 0x400)
        ln = r.choice([0, 0x10, 0x100, 0x200])
        P = _w(c)
        e.w32(nd + 0x48, base)
        e.w32(nd + 0x54, P)
        e.w32(nd + 0x58, (P + ln) & 0xffffffff)
        e.w32(nd + 0x9c, nodes[i + 1] if i + 1 < n else 0)
        cands += [base, base + ln, base + ln - 1, base - 1, base + 1]
    a = r.choice(cands + [r.randrange(0, 0x400)]) & 0xffffffff
    me = rnd(c, 0xa0)
    e.w32(me + 0x96, nodes[0] if n else 0)
    return [me, a]


def _g64dcb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = _zeroed(c, 0x10200, 0x40)
    n0 = r.choice([0, 1, 2, 3])
    ents = [_zeroed(c, 0x90, 0x90) for _ in range(4)]
    for i in range(n0):
        x = rnd(c, 0x20)
        inner = rnd(c, 0x20)
        e.w32(x + 0xc, _w(c))
        e.w32(inner + 0xc, x)
        e.w32(ents[i] + 0xc, inner)
    # slot 0xc removes the first entry
    def remove(em, k):
        n = em.r32(me + 0x10089)
        arr = me + 0x1008d
        for i in range(n - 1):
            em.w32(arr + 4 * i, em.r32(arr + 4 * i + 4))
        em.w32(me + 0x10089, n - 1)
    s0c = pystub(c, 1, this=True, side=remove)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0xc, s0c)
    e.w32(me, vt)
    for i in range(n0):
        e.w32(me + 0x1008d + 4 * i, ents[i])
    e.w32(me + 0x10089, n0)

    def add(em, k):
        m = r.choice([0, 1, 2, 3])
        for i in range(m):
            em.w32(me + 0x1008d + 4 * i, ents[i])
        em.w32(me + 0x10089, m)
    s60 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('s', 0x60)))
    s64 = pystub(c, 0, this=True, side=lambda em, k: (em.calllog.append(('s', 0x64)), add(em, k)))
    ch = obj(c, 0x100, {0x60: s60, 0x64: s64})
    e.w32(me + 0x1005d, ch)
    return [me]


def _g421500(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def qside(em, k):
        buf = em.arg32(1)
        for i in range(7):
            em.w32(buf + 4 * i, _w(c))
        em.w32(buf + 0x10, r.choice([0x1000, 0x1000, 0x1000, 0x2000, 0]))
        em.w32(buf + 4, r.choice([0, _w(c), _w(c)]))
    e.w32(0x6760e8, pystub(c, 3, nullflag=(1,), side=qside, ret=lambda em, k: _w(c)))
    e.w32(0x67607c, pystub(c, 3, ret=lambda em, k: _w(c)))
    e.w32(0x676258, pystub(c, 2, pop=0, ret=lambda em, k: r.choice([0, 0x6fd450, _w(c)])))
    return [_w(c)]


S(0x4d4590, 'GUESS append printable chars', 'thiscall', None, ret=None, gen=_g4d4590, note='batch33071')
S(0x4f6bb0, 'GUESS dtor flags dispatch a8 with child', 'thiscall', None, ret='eax', gen=_g4f6bb0, note='batch33071')
S(0x54a040, 'GUESS six cleanups and free', 'thiscall', None, ret=None, gen=_g54a040, note='batch33071')
S(0x5eec70, 'GUESS dtor three children', 'thiscall', None, ret='eax', gen=_g5eec70, note='batch33071')
S(0x5f0ff0, 'GUESS lookup vcall 130 return flag', 'thiscall', None, ret='al', gen=_g5f0ff0, note='batch33071')
S(0x5f5620, 'GUESS map address through ranges', 'thiscall', None, ret='eax', gen=_g5f5620, note='batch33071')
S(0x64dcb0, 'GUESS drain list then number entries', 'thiscall', None, ret=None, gen=_g64dcb0, note='batch33071')
S(0x421500, 'GUESS module file name of address', 'thiscall', None, ret='eax', gen=_g421500, note='batch33071')
