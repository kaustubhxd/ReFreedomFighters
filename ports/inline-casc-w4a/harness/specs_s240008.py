"""specs_s240008.py - Sonnet-w4a: atexit-style registration."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g634609(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ck = _w(c)
    if r.random() < 0.15:
        ck &= ~0x1f
    e.w32(0x6f5630, ck)
    s = pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    n = ck & 0x1f
    rol = ((s << n) | (s >> (32 - n))) & 0xffffffff if n else s
    e.w32(0x7257f8, rol ^ ck)
    e.w32(0x7257f4, 0 if r.random() < 0.5 else _w(c) | 1)
    hook_rec(c, 0x634aae, 3, this=True, pop=12, ret=lambda em, k: _w(c))
    hook_rec(c, 0x6345fd, 0, pop=0)
    hook_rec(c, 0x6345b0, 0, pop=0)
    cell = e.r32(0x6760b8)

    def h(em, res):
        em.calllog.append(('imp', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=r.choice([0, 0, _w(c)]), argbytes=12)
    e.stubs[cell] = (e.stubs[cell][0], h)
    return [_w(c)]


S(0x634609, 'GUESS atexit register encoded', 'cdecl', None, ret='eax', gen=_g634609, note='batch240008')
