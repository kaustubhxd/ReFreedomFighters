"""specs_s33110.py - h3 () batch 33110: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g507370(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ps = [rnd(c, 8) for _ in range(3)]
    for p in ps:
        e.w32(p, _b(c.fv(-5, 5, 0.1)))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: ps[min(k, 2)])

    def side(em, k):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, _w(c))
    s624 = pystub(c, 1, this=True)
    s630 = pystub(c, 1, this=True, stackmark=(0,), side=side)
    s5e8 = pystub(c, 1, this=True)
    s5e0 = pystub(c, 2, this=True, deref={0: 3, 1: 3})
    q = obj(c, 0x640, {0x624: s624, 0x630: s630, 0x5e8: s5e8, 0x5e0: s5e0})
    me = rnd(c, 0x20)
    e.w32(me + 0x18, q)
    return [me, rnd(c, 0x10)]


def _g5cf300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = rnd(c, 0x10)
    vals = [0.0, -0.42, 0.42, -0.44, 0.44, 0.4400001, -0.4400001, 0.46, -0.46, 0.4600001, -0.4600001, 1.0, -1.0, 0.3]
    flag = r.random() < 0.85

    def side(em, k):
        for i in range(2):
            x = r.choice(vals + [c.fv(-1, 1, 0.05)])
            em.w32(em.arg32(0) + 4 * i, _b(x) if x == x else 0x7fc00000)
    hook_rec(c, 0x446320, 2, this=True, stackmark=(1,), side=side)
    # the hook above receives (a, l): write into `a`
    s8c = pystub(c, 1, this=True, deref={0: 3})
    ent = obj(c, 0x100, {0x8c: s8c})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: ent if flag else 0)
    sysobj(c, table_slots={0x58: s58})
    me = rnd(c, 0xc80)
    p = rnd(c, 0x10)
    return [me, a, p]


def _g44a160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([0, 1, 2, 3])
    results = [r.choice([0, 0, 1, 0x100, 0xff, _w(c)]) for _ in range(4)]
    sel = [r.random() < 0.7 for _ in range(4)]

    def s4c_side(em, k):
        em.w32(em.arg32(0), 1)

    def s5c_side(em, k):
        em.w32(em.arg32(0), 1 if k < m else 0)
    s4c = pystub(c, 1, this=True, stackmark=(0,), side=s4c_side)
    s5c = pystub(c, 1, this=True, stackmark=(0,), side=s5c_side, ret=lambda em, k: 0x1000 + k)
    o = obj(c, 0x80, {0x4c: s4c, 0x5c: s5c})
    s180 = pystub(c, 2, this=True, ret=lambda em, k: results[min(k, 3)])
    pobj = obj(c, 0x200, {0x180: s180})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: pobj if sel[min(k, 3)] else 0)
    sysobj(c, table_slots={0x58: s58})
    me = rnd(c, 0x30)
    e.w32(me + 0x18, o if r.random() < 0.9 else 0)
    return [me, _w(c), _w(c)]


S(0x507370, 'GUESS pass three floats through two temp structs', 'thiscall', None, ret=None, gen=_g507370, note='batch33110')
S(0x5cf300, 'GUESS fill vector and clamp pitch/yaw to limits', 'thiscall', None, ret=None, gen=_g5cf300, note='batch33110')
S(0x44a160, 'GUESS find first child accepting a call', 'thiscall', None, ret='al', gen=_g44a160, note='batch33110')
