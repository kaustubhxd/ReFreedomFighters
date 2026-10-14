"""specs_s35147.py - 0x4d5f20 (thiscall(a, b, c, d) ret 0x10, ret='eax'). 0x4d6520 hooked (3 args after ecx; arg 1 = the caller's stack buffer, recorded as a marker; side effect fills 0x1c random bytes there; returns 0 in 1/4, 0x100 (al == 0) in 1/8, else a nonzero al with garbage upper bytes);
0x4d62c0 hooked (4 args after ecx, arg 0 the buffer recorded as its 7 dwords; returns 0 in 1/4). c: 0 in 1/3."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4d5f20(c):
    clear_hooks(c)
    r = c.rng
    ra = r.choice([0, 0, 0x100, 0x1ff00, 1, 0x7701, 0x12345602])

    def fill(em, k):
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0x1c)))
    hook_rec(c, 0x4d6520, 3, this=True, ret=ra, stackmark=(1,), side=fill)
    hook_rec(c, 0x4d62c0, 4, this=True, ret=0 if r.random() < 1 / 4 else r.getrandbits(32) | 1, deref={0: 7})
    cc = 0 if r.random() < 1 / 3 else r.getrandbits(32)
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), cc, r.getrandbits(32)]


S(0x4d5f20, 'GUESS parse into local record then process with fallback id', 'thiscall', None, ret='eax', gen=_g4d5f20, note='batch35147')
