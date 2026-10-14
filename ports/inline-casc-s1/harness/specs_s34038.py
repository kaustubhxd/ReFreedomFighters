"""specs_s34038.py - cascade tier E, batch 34038.
0x4d6980 / 0x4d6a10: [this+8] (old block) is zero in a third; n includes values whose 4 / 42-byte size overflows 32 bits; hooked 0x41e290 returns a fresh block or 0 (a fifth); 0x41e2c0 is a cdecl recorder; the
logger object at 0x700390 is set; the old [this] / [this+4] are random.
0x4f4610: s slots 0x48 and 0x60 are recorders (0x60 writes a new string pointer into [this+0xac] through its heap pointer argument); hooked 0x4f04e0 returns 0/1; the string's first byte is zero in a half;
hooked 0x634273 is a cdecl recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _gen_arr(mult):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, 0x41e290, 1, ret=(0 if r.random() < 0.2 else rnd(c, 0x40)), pop=0)
        hook_rec(c, 0x41e2c0, 1, pop=0)
        lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
        lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
        c.emu.w32(0x700390, lg)
        me = rnd(c, 0x20)
        c.emu.w32(me + 8, 0 if r.random() < 0.33 else (r.getrandbits(32) | 1))
        lim = 0x100000000 // mult
        n = r.choice([0, 1, 5, 0x30, lim - 1, lim, lim + 1, 0x80000000, r.getrandbits(32), r.randint(0, 100)])
        return [me, n & 0xffffffff]
    return g


def _g4f4610(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f04e0, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)
    hook_rec(c, 0x634273, 2, pop=0)

    def w(em, k):
        buf = rnd(c, 0x10)
        em.wbytes(buf, bytes([0 if r.random() < 0.5 else r.randrange(1, 256)]))
        em.w32(em.arg32(0), buf)
    s = obj(c, 0x20, {0x48: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True, side=w)}, nslots=0x70 // 4)
    me = rnd(c, 0xc0)
    buf0 = rnd(c, 0x10)
    c.emu.wbytes(buf0, bytes([0 if r.random() < 0.5 else r.randrange(1, 256)]))
    c.emu.w32(me + 0xac, buf0)
    return [me, s]


S(0x4d6980, 'GUESS reset array and allocate n 4-byte elements', 'thiscall', None, ret=None, gen=_gen_arr(4), note='batch34038')
S(0x4d6a10, 'GUESS reset array and allocate n 42-byte elements', 'thiscall', None, ret=None, gen=_gen_arr(0x2a), note='batch34038')
S(0x4f4610, 'GUESS read two fields from stream, free empty string', 'thiscall', None, ret='al', gen=_g4f4610, note='batch34038')
