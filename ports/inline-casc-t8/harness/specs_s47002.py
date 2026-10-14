"""specs_s47002.py - cascade t8 batch 47002: 0x61fbc0 (loader through callbacks in a context struct). Callbacks a[0x78], a[0xc], e are recorder stubs; 0x626d70 / 0x626b00 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g61fbc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ecb = pystub(c, 1, pop=0)

    def side(em, k):
        buf = em.arg32(2)
        em.w32(buf + 0x400, r.getrandbits(32))
        em.w32(buf + 0x404, r.getrandbits(32))
        em.w32(buf + 0x408, ecb if r.random() < 0.6 else 0)
    f78 = pystub(c, 3, pop=0, deref={2: 0x103}, ret=lambda em, k: r.choice([0, 1, 7, 0x80000000]), side=side)
    fc = pystub(c, 1, pop=0, ret=lambda em, k: r.choice([0, 0x1234, r.getrandbits(32)]))
    a = rnd(c, 0x110)
    e.w32(a + 0x78, f78 if r.random() > 0.1 else 0)
    e.w32(a + 0xc, fc)
    e.w32(a + 0xe8, r.choice([0, 1, 0x100]))
    for addr in (0x626d70, 0x626b00):
        hook_rec(c, addr, 4, pop=0, deref={1: 0x103}, ret=lambda em, k: r.choice([0, 0x5555, r.getrandbits(32)]))
    return [a, r.getrandbits(32)]


S(0x61fbc0, 'GUESS load through callbacks', 'cdecl', None, ret='eax', gen=_g61fbc0, note='batch47002')
