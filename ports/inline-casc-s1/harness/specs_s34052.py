"""specs_s34052.py - cascade tier E, batch 34052.
0x56f220 / 0x576120: the real 0x610100 stub runs; hooked 0x4e5e60 returns the next of eleven (three) distinct random dwords and records the stream; for 0x576120 engine table slot 0x58 returns random values.
0x5b2300: hooked 0x446040 returns 0/1; s slots 0x68, 0x74 and 0x6c (heap pointers) and 0x40 (stack pointer writing a random id) are recorders; engine table slot 0x58 returns random values."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _stream_hook(c, n):
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(n)]
    hook_rec(c, 0x4e5e60, 0, ret=lambda em, k: vals[min(k, n - 1)], this=True, pop=0)


def _g56f220(c):
    clear_hooks(c)
    _stream_hook(c, 11)
    return [rnd(c, 0x1d0), rnd(c, 0x20)]


def _g576120(c):
    clear_hooks(c)
    r = c.rng
    _stream_hook(c, 3)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    return [rnd(c, 0x240), rnd(c, 0x20)]


def _g5b2300(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x446040, 1, ret=r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)

    def wid(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    s = obj(c, 0x20, {0x68: pystub(c, 1, this=True), 0x74: pystub(c, 1, this=True), 0x6c: pystub(c, 1, this=True),
                      0x40: pystub(c, 1, this=True, side=wid, stackmark=(0,))}, nslots=0x78 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    return [rnd(c, 0x1d0), s]


S(0x56f220, 'GUESS read eleven fields from a stream', 'thiscall', None, ret=None, gen=_g56f220, note='batch34052')
S(0x576120, 'GUESS read three ids and resolve them', 'thiscall', None, ret=None, gen=_g576120, note='batch34052')
S(0x5b2300, 'GUESS read a record when the base reader accepts', 'thiscall', None, ret='al', gen=_g5b2300, note='batch34052')
