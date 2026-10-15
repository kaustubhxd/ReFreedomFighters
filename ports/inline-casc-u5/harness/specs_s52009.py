"""specs_s52009.py - tier H. 0x43f730: box test against this+0x18/0x1c/0x20 (limits minus r) for V = this+0x24 - p (p near and far), this[0x44] null or an iterator object with scripted slots 0x4c / 0x5c (write L[0], return keys) / 0x44; engine table slot 0x58 returns an object (matrix block at [o+8], slot 0x180 returns al, high bytes random) or 0; the real 0x43e920 / 0x441a60 run; /GS check keeps eax."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _f(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _b(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g43f730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    rr = r.choice([0.0, 1.0, 0.5, -1.0, _f(r.uniform(-2, 2))])
    cc = [_f(r.uniform(-20, 20)) for _ in range(3)]
    lim = [r.choice([5.0, 3.0, 0.0, 1.0, _f(r.uniform(0, 8))]) for _ in range(3)]
    me = rnd(c, 0x60)
    for i in range(3):
        e.w32(me + 0x18 + 4 * i, _b(lim[i] + rr))
        e.w32(me + 0x24 + 4 * i, _b(cc[i]))
    p = rnd(c, 0x10)
    for i in range(3):
        d = r.choice([0.0, 0.5, -1.0, _f(r.uniform(-6, 6)), _f(r.uniform(-3, 3)), lim[i], -lim[i], _f(r.uniform(-1, 1))])
        e.w32(p + 4 * i, _b(cc[i] + d))
    m = r.choice([0, 1, 2, 3, 4])
    Lseq = [r.getrandbits(32) | 1 for _ in range(m)] + [0]
    keys = [r.getrandbits(32) for _ in range(8)]

    def w4c(em, k):
        em.w32(em.arg32(0), Lseq[0])

    def w5c(em, k):
        em.w32(em.arg32(0), Lseq[min(k + 1, len(Lseq) - 1)])
    objs = []
    for i in range(6):
        if r.random() < 0.35:
            objs.append(0)
        else:
            mat = rnd(c, 0x80)
            for j in range(9):
                e.w32(mat + 0x24 + 4 * j - 0x24 + 0x24, _b(r.choice([0.0, 1.0, _f(r.uniform(-5, 5))])) if j < 3 else e.r32(mat + 0x24 + 4 * j))
            hit = r.choice([0, 0, 1, r.getrandbits(8) | 1, r.getrandbits(24) << 8])
            o = obj(c, 0x20, {0x180: pystub(c, 2, this=True, deref={0: 3}, ret=hit | (r.getrandbits(24) << 8))}, nslots=0x184 // 4)
            e.w32(o + 8, mat)
            objs.append(o)
    it = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=w4c, stackmark=(0,)),
                        0x5c: pystub(c, 1, this=True, side=w5c, stackmark=(0,), ret=lambda em, k: keys[min(k, 7)]),
                        0x44: pystub(c, 1, this=True, stackmark=(0,))}, nslots=0x60 // 4)
    e.w32(me + 0x44, 0 if r.random() < 0.15 else it)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 5)])})
    return [me, p, F(rr)]


S(0x43f730, 'GUESS box and object hit test', 'thiscall', None, ret='al', gen=_g43f730, note='batch52009')
