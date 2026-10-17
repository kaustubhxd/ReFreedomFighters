"""specs_s240010.py - Sonnet-w4a: CRT per-thread lock-token helpers."""
import pe_emu
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _tls(c):
    r = c.rng
    e = c.emu
    tls = rnd(c, 0x40)
    idx = r.randrange(8)
    for i in range(8):
        e.w32(tls + 4 * i, rnd(c, 0x20))
    e.w32(pe_emu.TEB + 0x2c, tls)
    e.w32(0x7257d4, idx)
    e.w32(0x6f5660, r.choice([0, 5, 0xfffffffe, _w(c)]))


def _g63452b(c):
    clear_hooks(c)
    r = c.rng
    _tls(c)
    hook_rec(c, 0x6345b0, 0, pop=0)
    hook_rec(c, 0x6345fd, 0, pop=0, ret=lambda em, k: _w(c))
    hook_rec(c, 0x6345bc, 0, pop=0, ret=lambda em, k: _w(c))
    return [rnd(c, 8)]


def _g63456a(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _tls(c)
    p = rnd(c, 8)
    e.w32(p, r.choice([0, 0, 0xffffffff, 0xffffffff, _w(c) | 1]))
    n_wait = [r.randrange(3)]

    def side(em, k):
        # after n_wait calls the owner lets go: 0 or a plain token
        if k >= n_wait[0]:
            em.w32(p, r.choice([0, _w(c) | 1]))
    hook_rec(c, 0x6345b0, 0, pop=0)
    hook_rec(c, 0x6345fd, 0, pop=0, ret=lambda em, k: _w(c))
    hook_rec(c, 0x634609, 1, pop=0, side=side, ret=lambda em, k: _w(c))
    return [p]


S(0x63452b, 'GUESS take lock token', 'cdecl', None, ret='eax', gen=_g63452b, note='batch240010')
S(0x63456a, 'GUESS wait lock token', 'cdecl', None, ret='eax', gen=_g63456a, note='batch240010')
