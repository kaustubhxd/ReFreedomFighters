"""specs_s33046.py - h3 () batch 33046."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g648520(c):
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

    def ret(em, kk):
        st['v'] = r.choice([0, 1, 0x100, 0x101])
        return st['v']

    def side(em, kk):
        em.w32(em.reg('ecx') + 8, newnode if (st['v'] & 0xff) else r.choice([0, newnode]))
    hook_rec(c, 0x63b240, 0, this=True, ret=ret, side=side)
    return [me]


def _g597a70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = _w(c)
    G = _zeroed(c, 0x2d00, 0x40)
    e.w32(0x7003b8, G)
    qv = r.getrandbits(32)
    me = _zeroed(c, 0x1e00, 0x40)
    # me+0x1d0b -> X ; [X+0x54] -> Y ; [Y+4] = qv
    X = rnd(c, 0x60)
    Y = rnd(c, 0x10)
    e.w32(Y + 4, qv)
    e.w32(X + 0x54, Y)
    e.w32(me + 0x1d0b, X)
    edis = []
    for i in range(4):
        o = rnd(c, 0x60)
        t = rnd(c, 0x60)
        e.w32(t + 0x3c, r.choice([0, 0x400, _w(c), 0xfffffbff]))
        e.w32(o + 8, t)
        u = rnd(c, 0x10)
        e.w32(u + 4, r.choice([qv, qv, _w(c)]))
        e.w32(o + 0x54, u)
        e.w32(G + 0x2c3d + 4 * i, o)
        d = _zeroed(c, 0x2000, 0x10)
        n = r.choice([-1, 0, 1, 2, 5])
        e.w32(d + 0x1fae, n & 0xffffffff)
        for k in range(6):
            e.w32(d + 0x1dae + 4 * k, r.choice([a, _w(c)]))
        edis.append(r.choice([d, d, 0]))
    hook_rec(c, 0x589c20, 1, this=True, ret=lambda em, k: edis[k] if k < 4 else 0)
    return [me, a]


def _gvc(off, nargs, retf=None):
    def g(c):
        clear_hooks(c)
        r = c.rng
        stub = pystub(c, nargs, this=True, ret=retf(c) if retf else (lambda em, k: _w(c)))
        return [obj(c, 0x40, {off: stub})]
    return g


def _g46e450(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: stub})
    return [rnd(c, 0x100)]


S(0x648520, 'GUESS take free record', 'thiscall', None, ret='eax', gen=_g648520, note='batch33046')
S(0x597a70, 'GUESS slot scan bool', 'thiscall', None, ret='al', gen=_g597a70, note='batch33046')
S(0x466d70, 'GUESS vcall 0x2b4(0x11)', 'thiscall', None, ret='eax', gen=_gvc(0x2b4, 1), note='batch33046')
S(0x466f50, 'GUESS vcall 0x2b4(2)', 'thiscall', None, ret='eax', gen=_gvc(0x2b4, 1), note='batch33046')
S(0x46eab0, 'GUESS vcall 0x350 deref', 'thiscall', None, ret='eax', gen=_gvc(0x350, 0, lambda c: (lambda em, k: rnd(c, 0x140))), note='batch33046')
S(0x54df90, 'GUESS vcall 0x24 return 1', 'thiscall', None, ret='al', gen=_gvc(0x24, 0), note='batch33046')
S(0x46e580, 'GUESS vcall 0x25c(str,0)', 'thiscall', None, ret='eax', gen=_gvc(0x25c, 2), note='batch33046')
S(0x46e450, 'GUESS sys table vcall 0x58', 'thiscall', None, ret='eax', gen=_g46e450, note='batch33046')
