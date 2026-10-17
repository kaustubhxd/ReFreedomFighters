"""specs_s33044.py - h3 (Sonnet) batch 33044."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _g65e0b0(c):
    clear_hooks(c)
    hook_rec(c, 0x634123, 5, side=lambda em, k: em.calllog.append(('vt', 0, None, (em.r32(em.arg32(0) - 4),))))
    return [rnd(c, 0x3800)]


def _g4e6c80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: rnd(c, 0x60))
    b = r.choice([0, 1, 2, 5, 16, 0xffffffff, 0x80000000, 0xfffffffb])
    return [rnd(c, 0x40), _w(c), b, _w(c), _w(c)]


def _g65e350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: rnd(c, 0x40))
    so = sysobj(c)
    e.w32(so + 0x1aa3, rnd(c, 0x40))
    n = r.choice([0, 1, 2, 5, 9])
    return [rnd(c, 0x20), rnd(c, 0x40), n]


def _g62f390(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d10, 3, pop=0)
    p = rnd(c, 0x100)
    e = c.emu
    n = r.randrange(1, 12)
    e.w32(p + 0x44, n)
    e.w32(p + 0x3c, rnd(c, 0x40))
    e.w32(p + 0x7c, r.randrange(0, 6))
    return [p]


def _g4fc460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    k = r.choice([0, 1, 2, 3, 4])
    bogus = r.random() < 0.3

    def dside(em, kk):
        em.calllog.append(('own', 0, None, (em.r32(me + 0x48), em.r32(me + 0x4c), em.r32(me + 0x50), em.r32(spare + 0xc))))
        if bogus:
            em.w32(me + 0x48, em.r32(em.arg32(0) + 0xc))
    hook_rec(c, 0x634273, 2, pop=0, side=dside)
    nodes = [rnd(c, 0x30) for _ in range(k)]
    spare = rnd(c, 0x30)
    for i, n in enumerate(nodes):
        e.w32(n + 8, nodes[i - 1] if i > 0 else (spare if bogus else 0))
        e.w32(n + 0xc, nodes[i + 1] if i + 1 < k else 0)
        e.w32(n + 0x10, me)
    e.w32(me + 0x48, nodes[0] if k else 0)
    e.w32(me + 0x4c, nodes[-1] if k else _w(c))
    e.w32(me + 0x50, r.choice(nodes + [0, _w(c)]) if k else 0)
    return [me]


def _g606b10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6014a0, 1, ret=lambda em, k: r.choice([rnd(c, 0x60), rnd(c, 0x60), 0]))
    n = r.choice([0, 1, 2, 5, 9])
    v = rnd(c, 8)
    return [rnd(c, 0x20), n, v, _w(c)]


def _g63ac70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk(word):
        n = rnd(c, 0xb0)
        e.wbytes(n + 2, word.to_bytes(2, 'little'))
        return n
    k = r.choice([0, 1, 2, 3, 4])
    nodes = [mk(0xffff if r.random() < 0.6 else r.randrange(0, 4)) for _ in range(k)]
    for i, n in enumerate(nodes):
        e.w32(n + 8, nodes[i + 1] if i + 1 < k else r.choice([0, nodes[0]]))
    me = rnd(c, 0x40)
    e.w32(me + 8, nodes[0] if k else 0)
    newnode = mk(r.choice([0xffff, 0, 1, 3]))
    st = {'v': 0}

    def ret615(em, kk):
        st['v'] = r.choice([0, 1, 0x100, 0x101])
        return st['v']

    def side(em, kk):
        em.w32(em.reg('ecx') + 8, newnode if (st['v'] & 0xff) else r.choice([0, newnode]))
    hook_rec(c, 0x615650, 0, this=True, ret=ret615, side=side)
    return [me]


def _g6033c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: r.choice([0, rnd(c, 0x90), rnd(c, 0x90)]))
    n = r.choice([0, 1, 2, 5, 9, 16])
    return [rnd(c, 0x20), n]


S(0x65e0b0, 'GUESS ctor table init', 'thiscall', None, ret='eax', gen=_g65e0b0, note='batch33044')
S(0x4e6c80, 'GUESS index buffer init', 'thiscall', None, ret='eax', gen=_g4e6c80, note='batch33044')
S(0x65e350, 'GUESS alloc and offset copy', 'thiscall', None, ret=None, gen=_g65e350, note='batch33044')
S(0x62f390, 'GUESS table reset', 'cdecl', None, ret=None, gen=_g62f390, note='batch33044')
S(0x4fc460, 'GUESS destroy list', 'thiscall', None, ret=None, gen=_g4fc460, note='batch33044')
S(0x606b10, 'GUESS vector n copies', 'thiscall', None, ret='eax', gen=_g606b10, note='batch33044')
S(0x63ac70, 'GUESS next live node', 'thiscall', None, ret='eax', gen=_g63ac70, note='batch33044')
S(0x6033c0, 'GUESS array of 8-byte entries', 'thiscall', None, ret='eax', gen=_g6033c0, note='batch33044')
