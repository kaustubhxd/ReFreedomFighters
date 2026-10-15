"""specs_s42018.py - Sonnet t3 batch 42018. 0x5233a0: /GS float function, args (out ptr, float f). Hooked: 0x633654 (ECX = cookie), 0x460af0 (this + 3 args, fills the local vec3 with random floats),
helper slot 0x88 (1 arg, rewrites the out vec3 with random floats); 0x4e0d00 and 0x44c840 (vec3 scale / normalise) run for real. [this+0x4b] (unaligned) is zero in a fifth of the cases."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([r.uniform(-10, 10), r.uniform(-1, 1), r.uniform(-1e3, 1e3), 0.0, 1.0, -1.0])


def g5233a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(em, k):
        em.wbytes(em.arg32(0), b''.join(struct.pack('<f', _fv(r)) for _ in range(3)))
    hook_rec(c, 0x460af0, 3, this=True, nullflag=(0,), side=fill)

    def fill2(em, k):
        em.wbytes(em.arg32(0), b''.join(struct.pack('<f', _fv(r)) for _ in range(3)))
    helper = obj(c, 0x40, {0x88: pystub(c, 1, this=True, side=fill2)})
    me = rnd(c, 0x80)
    e.wbytes(me + 0x4b, struct.pack('<I', helper if r.random() < 0.8 else 0))
    e.wbytes(me + 4, struct.pack('<f', r.choice([0.0, 0.5, 1.0, r.uniform(-2, 2), r.uniform(0, 1)])))
    out = rnd(c, 0x20)
    return [me, out, F(r.choice([-1.0, 0.0, 0.25, 0.5, 1.0, 2.0, r.uniform(-3, 3), r.uniform(0, 1)]))]


S(0x5233a0, 'GUESS clamp factor, reset out axis, helper rewrites and rescales it (GS)', 'thiscall', None, ret=None, gen=g5233a0, note='batch42018')
