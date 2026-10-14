"""specs_s35030.py - 0x5fd670 (thiscall(a, b, c, d) ret 0x10, returns this). Pointers inside a 0x200-byte region; [this+4] = end pointer of the string (>= b); memcpy 0x634d22 (cdecl, 3 args) and 0x430d10
(thiscall, 3 args) hooked; the memmove import (0x676278) is a Python stub logging (dst, src, length) and moving bytes. Ranges: b - a and d - c from 0..0x20 in all orderings (room >= n, room < n, equal)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5fd670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    R = rnd(c, 0x200)
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x430d10, 3, this=True)

    def mm(em, rr):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memmove', d, s, n))
        if 0 < n < 0x100:
            em.wbytes(d, bytes(em.rbytes(s, n)))
        em.ret(eax=d)
    e.stub_import('memmove', mm)
    a = R + 0x20 + r.randrange(0x20)
    b = a + r.choice([0, 1, 2, 5, 8, r.randint(0, 0x20)])
    end = b + r.randint(0, 0x30)
    src = R + 0x100 + r.randrange(0x20)
    n = r.choice([0, 1, 2, 5, 8, b - a, b - a + 1, max(b - a - 1, 0), r.randint(0, 0x20)])
    me = rnd(c, 0x20)
    e.w32(me + 4, end)
    return [me, a, b, src, src + n]


S(0x5fd670, 'GUESS string replace range', 'thiscall', None, ret='eax', gen=_g5fd670, note='batch35030')
