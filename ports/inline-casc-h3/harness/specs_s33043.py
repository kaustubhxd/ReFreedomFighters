"""specs_s33043.py - h3 (Sonnet) batch 33043."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _seen(em, k):
    em.calllog.append(('vt', 0, None, (em.r32(em.reg('ecx')),)))


def _g49c770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lo, hi = r.choice([(0, 0), (1, 0), (0, 1), (2, 1), (3, 2), (5, 0), (0, 4)]), None
    lo, hi = lo
    hook_rec(c, 0x49c980, 2, this=True, ret=lambda em, k: (hi << 16) | lo | (0 if True else 0))
    me = rnd(c, 0x80)
    arr = e.alloc(0x40, 4)
    for i in range(10):
        e.w32(arr + 4 * i, rnd(c, 0x60))
    e.w32(me + 0x39, arr)
    return [me, rnd(c, 0x80)]


def _g58a320(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59d370, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x38, r.randrange(0, 7))
    return [me]


def _g4f9e10(c):
    clear_hooks(c)
    hook_rec(c, 0x43ff00, 5, this=True, ret=lambda em, k: rnd(c, 0x100))
    return [rnd(c, 0x100), _w(c), _w(c), _w(c), _w(c), _w(c)]


def _glist(h1, h2):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        k = r.choice([0, 1, 2, 3, 4])
        nodes = [rnd(c, 0x20) for _ in range(k)]
        for i, n in enumerate(nodes):
            nxt = nodes[i + 1] if i + 1 < k else r.choice([0, nodes[0]])
            e.w32(n + 8, nxt)
            e.wbytes(n + 2, (0xffff if r.random() < 0.65 else r.getrandbits(16)).to_bytes(2, 'little'))
        me = rnd(c, 0x40)
        e.w32(me + 8, nodes[0] if k else 0)
        newnode = rnd(c, 0x20)

        def side(em, kk):
            em.w32(em.reg('ecx') + 8, r.choice([0, newnode]))
        hook_rec(c, h1, 0, this=True, side=side, ret=lambda em, kk: r.choice([0, 1, 0x100, 0x101]))
        hook_rec(c, h2, 0, this=True, ret=lambda em, kk: _w(c))
        return [me]
    return g


def _g54cc50(c):
    clear_hooks(c)
    hook_rec(c, 0x634d10, 3, pop=0, side=lambda em, k: em.calllog.append(('vt', 0, None, (em.r32(em.arg32(0) - 0x7f),))))
    return [rnd(c, 0x4100), _w(c)]


def _g65f460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ret64(em, k):
        esi = rnd(c, 0x40)
        e.w32(esi + 0xc, r.choice([0, rnd(c, 0x40)]))
        return esi
    hook_rec(c, 0x64d030, 4, this=True, ret=ret64)

    def side(em, k):
        d = em.reg('edx')
        em.calllog.append(('edx', 0, None, tuple(em.r32(d + 4 * i) for i in range(9))))
    hook_rec(c, 0x4de420, 0, this=True, side=side)
    me = rnd(c, 0x40)
    return [me, _w(c), rnd(c, 0x30), rnd(c, 0x10), r.choice([0xff, 0xffffff00 | 0xff, _w(c), 0x55])]


def _g4f9860(c):
    clear_hooks(c)
    hook_rec(c, 0x4ee210, 3, this=True, side=_seen)
    return [rnd(c, 0x200), _w(c), _w(c), _w(c)]


S(0x49c770, 'GUESS flag array and arg', 'thiscall', None, ret=None, gen=_g49c770, note='batch33043')
S(0x58a320, 'GUESS compact array by predicate', 'thiscall', None, ret=None, gen=_g58a320, note='batch33043')
S(0x4f9e10, 'GUESS call and copy fields', 'thiscall', None, ret='eax', gen=_g4f9e10, note='batch33043')
S(0x63ae30, 'GUESS skip 0xffff nodes tail call', 'thiscall', None, ret='eax', gen=_glist(0x63b340, 0x63b0c0), note='batch33043')
S(0x648480, 'GUESS skip 0xffff nodes tail call B', 'thiscall', None, ret='eax', gen=_glist(0x63b3c0, 0x648750), note='batch33043')
S(0x54cc50, 'GUESS init with memset', 'thiscall', None, ret='eax', gen=_g54cc50, note='batch33043')
S(0x65f460, 'GUESS lookup and copy vec', 'thiscall', None, ret=None, gen=_g65f460, note='batch33043')
S(0x4f9860, 'GUESS ctor3 fields', 'thiscall', None, ret='eax', gen=_g4f9860, note='batch33043')
