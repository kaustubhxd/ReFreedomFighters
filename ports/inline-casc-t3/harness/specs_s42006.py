"""specs_s42006.py - Sonnet t3 batch 42006. 0x501da0: /GS float function. Hooked: 0x633654 (ECX = cookie), obj slots 0x80 (2 args, fills v34 (vec3 at +0..) with random floats) and 0x7c
(2 args, records the vec3 contents), 0x5003d0 (this + 1 arg, returns a pointer to a random heap float pair); 0x4deb20 and 0x4de4f0 (and their callees) run for real."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fl(r):
    return struct.pack('<f', r.choice([r.uniform(-10, 10), r.uniform(-1, 1), r.uniform(-1e3, 1e3), 0.0, 1.0, -1.0]))


def g501da0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(em, k):
        p = em.arg32(0)
        em.wbytes(p, b''.join(_fl(r) for _ in range(9)))
        q = em.arg32(1)
        em.wbytes(q, b''.join(_fl(r) for _ in range(3)))
    blk = rnd(c, 16)
    e.wbytes(blk, _fl(r))
    hook_rec(c, 0x5003d0, 1, this=True, ret=blk)
    ob = obj(c, 0x40, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=fill),
                       0x7c: pystub(c, 2, this=True, deref={0: 9, 1: 3})})
    me = rnd(c, 0x40)
    e.w32(me + 0xc, ob)
    src = rnd(c, 0x20)
    return [me, src]


S(0x501da0, 'GUESS rotate vector by a built local and hand to the object (GS)', 'thiscall', None, ret=None, gen=g501da0, note='batch42006')
