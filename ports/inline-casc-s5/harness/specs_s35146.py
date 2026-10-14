"""specs_s35146.py - 0x4f26d0 (thiscall(a, b) ret 8, ret='al'). this: object with slot 0x130 (3 args recorded; side effect sets a[0x10] = 1 on a random call index, in 1/4 of cases never). b: 0 in 1/6, else head of a chain of 1..5 objects, each with slot 0x20 (returns the next object) and
slot 0x1e0 (1 arg; returns 0 on the last, otherwise random incl. garbage upper bytes). Engine table slot 0x4c (1 arg) returns a random dword. a: 0x20 random bytes (byte 0x10 random before the call)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g4f26d0(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x20)
    stopk = r.randint(0, 5) if r.random() < 0.75 else 99

    def side(em, k):
        if k >= stopk:
            em.wbytes(a + 0x10, b'\x01')
    this = obj(c, 0x20, {0x130: pystub(c, 3, this=True, side=side)}, nslots=0x4d)
    n = r.randint(1, 5)
    succ = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=0)}, nslots=0x7a)
    for i in range(n):
        ret = r.choice([1, 1, 1, 2, 0x100, 0x1ff01, 0])
        succ = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=succ), 0x1e0: pystub(c, 1, this=True, ret=ret)}, nslots=0x7a)
    b = 0 if r.random() < 1 / 6 else succ
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))}, table_size=0x60)
    return [this, a, b]


S(0x4f26d0, 'GUESS dispatch object chain to this until done flag', 'thiscall', None, ret='al', gen=_g4f26d0, note='batch35146')
