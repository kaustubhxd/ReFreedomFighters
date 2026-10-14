"""specs_s35161.py - 0x4fb360 (thiscall(s) ret 4, ret='al'). this: object with slot 0x84 (0 args recorded), 0x80 random bytes. s: stream with slot 0x68 (1 arg, writes a random byte there) and slot 0x40 (1 arg flag-recorded; writes id: zero in 1/3, else random).
Engine table slot 0x58 (1 arg) returns p with slot 0x100 (1 arg, returns a random dword)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4fb360(c):
    clear_hooks(c)
    r = c.rng
    p = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x50)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=p)}, table_size=0x60)

    def w1(em, k):
        em.w8(em.arg32(0), r.getrandbits(8))

    def w4(em, k):
        em.w32(em.arg32(0), 0 if r.random() < 1 / 3 else r.getrandbits(32))
    s = obj(c, 0x20, {0x68: pystub(c, 1, this=True, side=w1), 0x40: pystub(c, 1, this=True, nullflag=(0,), side=w4)}, nslots=0x1b)
    me = obj(c, 0x80, {0x84: pystub(c, 0, this=True)}, nslots=0x22)
    return [me, s]


S(0x4fb360, 'GUESS deserialize two bytes and a resolved reference', 'thiscall', None, ret='al', gen=_g4fb360, note='batch35161')
