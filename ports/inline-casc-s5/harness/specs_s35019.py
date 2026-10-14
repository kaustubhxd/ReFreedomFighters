"""specs_s35019.py - 0x567200 (thiscall(a, b), ret='al'). Hooked 0x563110 (thiscall, 2 args), 0x567510 (thiscall). [this+0x54] -> object with slot 0x25c (2 args, returns h or 0 in 1/4); h has slot 0x284
(1 arg, buffer content recorded). Engine 0x70039c: slot 0x190 returns s (object with slot 0x198: 3 args, pops 8, writes random bytes into the 0x100-byte buffer), engine+0x9b table -> +0xae4 object with
slot 0 (3 args, pops nothing)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g567200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563110, 2, this=True)
    hook_rec(c, 0x567510, 0, this=True)
    h = 0 if r.random() < 0.25 else obj(c, 0x20, {0x284: pystub(c, 1, deref={0: -0x100}, this=True)}, nslots=0xa2)
    o54 = obj(c, 0x20, {0x25c: pystub(c, 2, ret=h, this=True)}, nslots=0x98)
    me = rnd(c, 0x200)
    e.w32(me + 0x54, o54)
    data = bytes(r.getrandbits(8) for _ in range(0x100))

    def fill(em, k):
        em.wbytes(em.arg32(1), data)
    s = obj(c, 0x20, {0x198: pystub(c, 3, nullflag=(1,), pop=8, side=fill)}, nslots=0x67)
    t = obj(c, 0x20, {0: pystub(c, 3, this=True, pop=0, ret=r.getrandbits(32))}, nslots=2)
    so = sysobj(c, slots={0x190: pystub(c, 0, ret=s, this=True)}, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.wbytes(tab + 0xae4, t.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x567200, 'GUESS base update then write label', 'thiscall', None, ret='al', gen=_g567200, note='batch35019')
