"""specs_s240005.py - Sonnet-w4a: encoded-pointer call, startup lock."""
import pe_emu
from pilot import S
from recruits_util import clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _stubcell(c, cell, nargs, ret):
    e = c.emu
    a = e.r32(cell)
    n = [0]

    def h(em, res):
        em.calllog.append(('imp', cell, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(), argbytes=4 * nargs)
    e.stubs[a] = (e.stubs[a][0], h)


def _g6345bc(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ck = _w(c)
    e.w32(0x6f5630, ck)
    if r.random() < 0.15:
        ck_n = 0
        e.w32(0x6f5630, ck & ~0x1f)
        ck = ck & ~0x1f
    s = pystub(c, 0, ret=lambda em, k: _w(c))
    n = ck & 0x1f
    rol = ((s << n) | (s >> (32 - n))) & 0xffffffff if n else s
    e.w32(0x7257fc, rol ^ ck)
    e.w32(0x7257f4, 0 if r.random() < 0.5 else _w(c) | 1)
    hook_rec(c, 0x634aae, 1, this=True, pop=4, ret=lambda em, k: _w(c))
    _stubcell(c, 0x67613c, 1, lambda: _w(c))
    _stubcell(c, 0x676140, 1, lambda: _w(c))
    return []


def _g633d00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    teb = e.r32(pe_emu.TEB + 0x18)
    owner = e.r32(teb + 4)
    e.w32(0x725494, r.choice([0, 0, owner]))
    hook_rec(c, 0x634cb5, 0, pop=0, ret=lambda em, k: r.choice([0, 1, 1]))
    return []


S(0x6345bc, 'GUESS call encoded pointer or release', 'cdecl', None, ret='eax', gen=_g6345bc, note='batch240005')
S(0x633d00, 'GUESS thread-owner lock acquire', 'cdecl', None, ret='eax', gen=_g633d00, note='batch240005')
