"""specs_s42007.py - Sonnet t3 batch 42007. 0x5c4940: /GS float function. Hooked: 0x633654 (ECX = cookie), 0x591ae0 (this = [this+0x60], returns an object whose +0x44 holds a helper),
helper slot 0x80 (2 args: &vec3 out filled with random floats, a); 0x4e0be0 (euler -> basis, sin/cos imports) runs for real."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fl(r):
    return struct.pack('<f', r.choice([r.uniform(-10, 10), r.uniform(-1, 1), r.uniform(-1e3, 1e3), 0.0, 1.0, -1.0]))


def g5c4940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(em, k):
        em.wbytes(em.arg32(0), b''.join(_fl(r) for _ in range(3)))
    helper = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0,), side=fill)})
    mid = rnd(c, 0x60)
    e.w32(mid + 0x44, helper)
    hook_rec(c, 0x591ae0, 0, this=True, pop=0, ret=mid)
    me = rnd(c, 0x80)
    e.w32(me + 0x60, rnd(c, 0x20))
    out = rnd(c, 0x40)
    return [me, r.getrandbits(32), out]


S(0x5c4940, 'GUESS build two basis blocks from a vector (GS)', 'thiscall', None, ret=None, gen=g5c4940, note='batch42007')
