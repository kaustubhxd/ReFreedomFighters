"""specs_s38022.py - cascade s8 batch 38022: 0x620e70. Scratch buffer (S+0x23c, 0x400 bytes) with write pointer S+0x238 (0 or a few bytes in) and end S+0x234 a few bytes past it so the
grow helper 0x6206e0 runs (its hook moves the end up by 0x30 and fails about 10% of the time); strings of 'a' 'b' '=' 0x0c bytes ending in NUL (0..14 chars); 0x61fd60 returns a pool node
(or 0; node[0] equals the scratch buffer half of the time so the interning call runs), 0x6204f0 / 0x61c660 hooked (about 10% failures). All helper args are recorded."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g620e70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = e.alloc(0x400, 4)
    e.wbytes(buf, r.randbytes(0x400))
    me = rnd(c, 0x300)
    k = r.choice([0, 0, 1, 3])
    e.w32(me + 0x23c, buf)
    e.w32(me + 0x238, buf + k)
    e.w32(me + 0x234, buf + k + r.choice([0, 1, 2, 4, 8, 0x100]))
    pool = []
    for _ in range(6):
        n = rnd(c, 0x40)
        if r.random() < 0.5:
            e.w32(n, buf)
        pool.append(n)
    pf = r.choice([0.0, 0.1, 0.3])

    def fd(em, kk):
        return 0 if r.random() < pf else r.choice(pool)

    def grow_side(em, kk):
        s = em.arg32(0) - 0x22c
        em.w32(s + 0x234, em.r32(s + 0x234) + 0x30)
    hook_rec(c, 0x6206e0, 1, pop=0, ret=lambda em, kk: 0 if r.random() < pf else 1, side=grow_side)
    hook_rec(c, 0x61fd60, 3, pop=0, ret=fd)
    hook_rec(c, 0x6204f0, 2, pop=0, ret=lambda em, kk: 0 if r.random() < pf else r.getrandbits(32) | 1)
    hook_rec(c, 0x61c660, 5, pop=0, ret=lambda em, kk: 0 if r.random() < pf else 1)
    alphabet = [ord('a'), ord('b'), ord('a'), 0x3d, 0x3d, 0x0c, ord('c')]
    s = bytes(r.choice(alphabet) for _ in range(r.randrange(0, 15))) + b'\0'
    p = e.alloc(len(s) + 8, 1)
    e.wbytes(p, s + bytes(r.choice([ord('a'), 0x3d, 0x0c, 0]) for _ in range(7)))
    return [me, p]


S(0x620e70, 'GUESS parse name=value definition string', 'cdecl', None, ret='eax', gen=_g620e70, note='batch38022')
