"""specs_s33093.py - h3 () batch 33093: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g5273e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        em.w32(em.arg32(0), _b(c.fv(-10.0, 10.0, 0.25)))
    s8 = pystub(c, 1, this=True, stackmark=(0,), side=side, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff00, _w(c)]))

    def side2(em, k):
        em.calllog.append(('edx', em.reg('edx')))
    hook_rec(c, 0x4e0130, 2, this=True, side=side2)
    sub = obj(c, 0x20, {8: s8})
    me = rnd(c, 0x40)
    # the sub-object lives inside `me` at +0x28: copy its vtable pointer there
    e.w32(me + 0x28, e.r32(sub))
    return [me, rnd(c, 0x10)]


def _g4e0a10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s1c4 = pystub(c, 2, st0=lambda em, k: c.fv(-3.0, 3.0, 0.25))
    sysobj(c, slots={0x1c4: s1c4})

    def side(em, k):
        em.calllog.append(('in', tuple(em.r32(em.reg('edx') + 4 * i) for i in range(3))))
        t = em.reg('ecx')
        for i in range(3):
            em.w32(t + 4 * i, _b(c.fv(-3.0, 3.0, 0.25)))
    vals = [0.0, 0.0001, 0.0001220703125, 0.00012207032, 0.00012207031, 0.00012203, 0.000122, 1.0, float('nan'), -1.0, 5.0]
    t = r.choice(vals)
    hook_rec(c, 0x44e630, 0, this=True, side=side, st0=lambda em, k: t)
    return [rnd(c, 0x10)]


S(0x5273e0, 'GUESS query slot 8 then 0x4e0130 with edx', 'thiscall', None, ret='al', gen=_g5273e0, note='batch33093')
S(0x4e0a10, 'GUESS random direction or default', 'thiscall', None, ret=None, gen=_g4e0a10, note='batch33093')
